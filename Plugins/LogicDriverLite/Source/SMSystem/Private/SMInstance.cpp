// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMInstance.h"
#include "Engine/NetDriver.h"
#include "Net/UnrealNetwork.h"
#include "SMLogging.h"
#include "SMUtils.h"
#include "SMStateMachineComponent.h"

#include "Engine/NetDriver.h"
#include "Engine/GameEngine.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

#define LOCTEXT_NAMESPACE "SMInstance"

// Execute the function on the top most reference owner.
#define EXECUTE_ON_PRIMARY_CONST(function) \
		if (const USMInstance* Primary = GetPrimaryReferenceOwnerConst()) \
		{ \
			if (Primary != this) \
			{ \
				return Primary->function; \
			} \
		} \

#define EXECUTE_ON_PRIMARY(function) \
		if (USMInstance* Primary = GetPrimaryReferenceOwner()) \
		{ \
			if (Primary != this) \
			{ \
				return Primary->function; \
			} \
		} \


USMInstance::USMInstance() : Super()
{
	bAutoManageTime = true;
	bStopOnEndState = false;
	
	bCanEverTick = true;
#if WITH_EDITORONLY_DATA
	bCanTickInEditor = false;
#endif
	
	bCanTickWhenPaused = false;
	bTickRegistered = true;
	bTickBeforeInitialize = false;
	bTickBeforeBeginPlay = false;
	
	bEnableLogging = false;
	bLogStateChange = true;
	bLogTransitionTaken = true;

	bCanReplicateAsReference = false;
	
	bCallTickOnManualUpdate = false;
	bIsTicking = false;
	bIsUpdating = false;
	bCanEvaluateTransitionsLocally = true;
	bCanTakeTransitionsLocally = true;
	bCanExecuteStateLogic = true;
	bHasStarted = false;
	bLoadFromStatesCalled = false;
	bInitialized = false;
	bWaitingForStop = false;
}

bool USMInstance::IsTickable() const
{
	// Don't check CDO.
	// On IsPendingKillOrUnreachable can cause tick lookup function to crash debug / package builds.
	// Intermittently IsTemplate may fail in this scenario so it should be checked last.
	if (IsPendingKillOrUnreachable() || (!IsInitialized() && !bTickBeforeInitialize) || !CanEverTick() || IsTemplate())
	{
		return false;
	}

	UWorld* ThisWorld = GetWorld();

	// Well, we tried.
	if (!ThisWorld)
	{
		return true;
	}

	return bTickBeforeBeginPlay || ThisWorld->HasBegunPlay();
}

bool USMInstance::IsTickableInEditor() const
{
#if WITH_EDITORONLY_DATA
	return bCanTickInEditor;
#else
	return false;
#endif
}

ETickableTickType USMInstance::GetTickableTickType() const
{
	if (!bTickRegistered || IsTemplate())
	{
		return ETickableTickType::Never;
	}

	return ETickableTickType::Conditional;
}

UWorld* USMInstance::GetTickableGameObjectWorld() const
{
	return GetWorld();
}

TStatId USMInstance::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(SMInstance, STATGROUP_Tickables);
}

void USMInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	if (const UBlueprintGeneratedClass* BPClass = Cast<UBlueprintGeneratedClass>(GetClass()))
	{
		BPClass->GetLifetimeBlueprintReplicationList(OutLifetimeProps);
	}
	
	DOREPLIFETIME(USMInstance, R_StateMachineContext);
	DOREPLIFETIME(USMInstance, ComponentOwner);
	DOREPLIFETIME(USMInstance, ReplicatedReferences);

	DOREPLIFETIME(USMInstance, bAutoManageTime);
	DOREPLIFETIME(USMInstance, bStopOnEndState);
	DOREPLIFETIME(USMInstance, bCanEverTick);
	DOREPLIFETIME(USMInstance, bCanTickWhenPaused);
	DOREPLIFETIME(USMInstance, TickInterval);
}

void USMInstance::BeginDestroy()
{
	Shutdown();
	Super::BeginDestroy();
}

UWorld* USMInstance::GetWorld() const
{
	// Check if the context has its own world to use.
	UObject* Context = GetContext();
	return Context ? Context->GetWorld() : nullptr;
}

int32 USMInstance::GetFunctionCallspace(UFunction* Function, FFrame* Stack)
{
	if (UObject* Context = GetContext())
	{
		return Context->GetFunctionCallspace(Function, Stack);
	}

	return Super::GetFunctionCallspace(Function, Stack);
}

bool USMInstance::CallRemoteFunction(UFunction* Function, void* Parms, FOutParmRec* OutParms, FFrame* Stack)
{
	check(!HasAnyFlags(RF_ClassDefaultObject));
	if (AActor* Context = Cast<AActor>(GetContext()))
	{
		UNetDriver* NetDriver = Context->GetNetDriver();
		if (NetDriver)
		{
			NetDriver->ProcessRemoteFunction(Context, Function, Parms, OutParms, Stack, this);
			return true;
		}
	}
	return false;
}

UObject* USMInstance::GetContext() const
{
	return R_StateMachineContext;
}

void USMInstance::Initialize(UObject* Context)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Initialize"), STAT_SMInstance_Initialize, STATGROUP_LogicDriver);

	if (IsInitialized())
	{
		LD_LOG_WARNING(TEXT("State machine %s is currently initialized. Call Shutdown() before initializing."), *GetName());
		return;
	}

	if (!IsValid(Context))
	{
		LD_LOG_ERROR(TEXT("Context provided to state machine %s is invalid."), *GetName());
		return;
	}

	// New objects can't be instantiated while garbage collection is active.
	check(!IsGarbageCollecting());

	// Context is what the instance will run under. This also sets the World the state machine operates in.
	SetContext(Context);

	// Let child classes perform any needed setup.
	OnPreStateMachineInitialized();
	if (IsInGameThread())
	{
		OnPreStateMachineInitializedEvent.Broadcast(this);
	}
	
	// Locate the properties for this state machine. This could be either from a blueprint or native class.
	TSet<FStructProperty*> Properties;
	if (!USMUtils::TryGetStateMachinePropertiesForClass(GetClass(), Properties, RootStateMachineGuid))
	{
		LD_LOG_ERROR(TEXT("Could not locate properties for state machine %s."), *GetName());
		return;
	}

	// The RootGuid will have either been set by the compiler or when locating the parent class.
	if (!ensureAlways(RootStateMachineGuid.IsValid()))
	{
		LD_LOG_ERROR(TEXT("State machine %s has an invalid guid."), *GetName());
		return;
	}
	RootStateMachine.SetNodeGuid(RootStateMachineGuid);
	RootStateMachine.SetNodeName(GetRootNodeNameDefault());
	RootStateMachine.SetNodeInstanceClass(StateMachineClass);
	
	// Build the run-time state machine.
	if (!USMUtils::GenerateStateMachine(this, RootStateMachine, Properties))
	{
		LD_LOG_ERROR(TEXT("Error generating state machine %s. Please try recompiling the blueprint."), *GetName());
		return;
	}

	// Initialize the compiled state machine.
	RootStateMachine.Initialize(this);

	// Calculate path guids now that the instance is initialized and all node owners set.
	TMap<FString, int32> Paths;
	RootStateMachine.CalculatePathGuid(Paths);

	/* Build out a map of the state machine to use with node retrieval. */
	TSet<USMInstance*> InstancesMapped;
	BuildStateMachineMap(&RootStateMachine, InstancesMapped);
	
	// Final initialization is performed by top most owner.
	if (IsPrimaryReferenceOwner())
	{
		if (IsInGameThread())
		{
			FinishInitialize();
		}
	}
}

void USMInstance::Start()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Start"), STAT_SMInstance_Start, STATGROUP_LogicDriver);
	
	if (!CheckIsInitialized())
	{
		return;
	}

	if (bHasStarted || (RootStateMachine.IsActive() && RootStateMachine.GetSingleActiveState() != nullptr))
	{
		// Don't log any more. This can happen frequently and by default, such as through transition replication.
		LD_LOG_VERBOSE(TEXT("Attempted to start State Machine Instance %s when it was already running."), *GetName());
		return;
	}

	StatesPendingActivation.Empty();
	bHasStarted = true;
	
	DoStart();
}

void USMInstance::Update(float DeltaSeconds)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Update"), STAT_SMInstance_Update, STATGROUP_LogicDriver);
	
	if (IsUpdating() || !HasStarted() || !CheckIsInitialized())
	{
		return;
	}

	if (HandleStopOnEndState())
	{
		return;
	}
	
	if (!RootStateMachine.IsActive())
	{
		return;
	}
	
	// Begin update. This way if tick updates again we will cancel out.
	bIsUpdating = true;

	UpdateTime();

	if (bAutoManageTime && DeltaSeconds == 0.f)
	{
		DeltaSeconds = WorldTimeDelta;
	}
	
	if (!bIsTicking && bCallTickOnManualUpdate)
	{
		Tick(DeltaSeconds);
	}

	Internal_Update(DeltaSeconds);

	// End update.
	bIsUpdating = false;
}

void USMInstance::Stop()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Stop"), STAT_SMInstance_Stop, STATGROUP_LogicDriver);
	
	bWaitingForStop = false;

	if (!CheckIsInitialized())
	{
		return;
	}

	if (!bHasStarted)
	{
		LD_LOG_VERBOSE(TEXT("Attempted to stop State Machine Instance when it was not already running."));
		return;
	}

	if (RootStateMachine.IsActive())
	{
		RootStateMachine.EndState(0.f);
	}
	
	StatesPendingActivation.Empty();
	bLoadFromStatesCalled = false;
	bHasStarted = false;

	// Let states run any shutdown logic.
	for (const auto& KeyVal : GetNodeMap())
	{
		KeyVal.Value->OnStoppedByInstance(this);
	}
	
	OnStateMachineStop();
	OnStateMachineStoppedEvent.Broadcast(this);
}

void USMInstance::Restart()
{
	Stop();
	Start();
}

void USMInstance::Shutdown()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Shutdown"), STAT_SMInstance_Shutdown, STATGROUP_LogicDriver);
	
	if (!IsInitialized())
	{
		return;
	}
	
	UObject* Context = GetContext();
	const bool bContextDestroyed = Context == nullptr || Context->IsPendingKillOrUnreachable();
	if (IsActive() && !bContextDestroyed)
	{
		// Don't stop if context is being destroyed, this can cause blueprint runtime errors
		// if unbinding autobound transitions from the context.
		Stop();
	}
	
	for (FSMNode_Base* Node : RootStateMachine.GetAllNodes())
	{
		Node->Reset();
	}

	ReplicatedReferences.Empty();

	StateMachineGuids.Empty();
	GuidNodeMap.Empty();
	GuidStateMap.Empty();
	GuidTransitionMap.Empty();

	bInitialized = false;
}

void USMInstance::ReplicatedStart()
{
	if (USMStateMachineComponent* Component = GetComponentOwner())
	{
		Component->Start();
	}
	else
	{
		Start();
	}
}

void USMInstance::ReplicatedStop()
{
	if (USMStateMachineComponent* Component = GetComponentOwner())
	{
		Component->Stop();
	}
	else
	{
		Stop();
	}
}

void USMInstance::ReplicatedRestart()
{
	if (USMStateMachineComponent* Component = GetComponentOwner())
	{
		Component->Restart();
	}
	else
	{
		Restart();
	}
}

void USMInstance::StartWithNewContext(UObject* Context)
{
	SetContext(Context);
	Start();
}

void USMInstance::EvaluateTransitions()
{
	EXECUTE_ON_PRIMARY(EvaluateTransitions());
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::EvaluateTransitions"), STAT_SMInstance_EvaluateTransitions, STATGROUP_LogicDriver);
	
	GetRootStateMachine().ProcessStates(0.f, true);
}

bool USMInstance::EvaluateAndTakeTransitionChain(USMTransitionInstance* FirstTransitionInstance)
{
	EXECUTE_ON_PRIMARY(EvaluateAndTakeTransitionChain(FirstTransitionInstance));
	
	if (FirstTransitionInstance)
	{
		if (FSMTransition* Transition = FirstTransitionInstance->GetOwningNodeAs<FSMTransition>())
		{
			return EvaluateAndTakeTransitionChain(*Transition);
		}
	}
	
	return false;
}

bool USMInstance::EvaluateAndTakeTransitionChain(FSMTransition& InFirstTransition)
{
	EXECUTE_ON_PRIMARY(EvaluateAndTakeTransitionChain(InFirstTransition));
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::EvaluateAndTakeTransitionChain"), STAT_SMInstance_EvaluateAndTakeTransitionChain, STATGROUP_LogicDriver);
	
	if (FSMStateMachine* StateMachineOwner = static_cast<FSMStateMachine*>(InFirstTransition.GetOwnerNode()))
	{
		return StateMachineOwner->EvaluateAndTakeTransitionChain(&InFirstTransition);
	}
	
	return false;
}

bool USMInstance::EvaluateAndFindTransitionChain(USMTransitionInstance* InFirstTransitionInstance,
	TArray<USMTransitionInstance*>& OutTransitionChain, USMStateInstance_Base*& OutDestinationState,
	bool bRequirePreviousStateActive)
{
	EXECUTE_ON_PRIMARY(EvaluateAndFindTransitionChain(InFirstTransitionInstance, OutTransitionChain, OutDestinationState));

	OutTransitionChain.Reset();
	OutDestinationState = nullptr;
	
	if (InFirstTransitionInstance == nullptr)
	{
		return false;
	}

	if (FSMTransition* FirstTransition = InFirstTransitionInstance->GetOwningNodeAs<FSMTransition>())
	{
		if (bRequirePreviousStateActive && !FirstTransition->GetFromState()->IsActive())
		{
			return false;
		}
		
		TArray<FSMTransition*> Chain;
		if (FirstTransition->CanTransition(Chain))
		{
			FSMState_Base* DestinationState = FSMTransition::GetFinalStateFromChain(Chain);
			OutDestinationState = CastChecked<USMStateInstance_Base>(DestinationState->GetOrCreateNodeInstance());

			OutTransitionChain.Reserve(Chain.Num());
			for (FSMTransition* Transition : Chain)
			{
				OutTransitionChain.Add(CastChecked<USMTransitionInstance>(Transition->GetOrCreateNodeInstance()));
			}

			return true;
		}
	}
	
	return false;
}

bool USMInstance::TakeTransitionChain(const TArray<USMTransitionInstance*>& InTransitionChain)
{
	EXECUTE_ON_PRIMARY(TakeTransitionChain(InTransitionChain));

	if (InTransitionChain.Num() == 0)
	{
		return false;
	}

	if (const FSMTransition* FirstTransition = InTransitionChain[0]->GetOwningNodeAs<FSMTransition>())
	{
		if (FSMStateMachine* StateMachineOwner = static_cast<FSMStateMachine*>(FirstTransition->GetOwnerNode()))
		{
			TArray<FSMTransition*> Chain;
			Chain.Reserve(InTransitionChain.Num());
			for (const USMTransitionInstance* TransitionInstance : InTransitionChain)
			{
				Chain.Add(TransitionInstance->GetOwningNodeAs<FSMTransition>());
			}
			return StateMachineOwner->TakeTransitionChain(Chain);
		}
	}

	return false;
}

void USMInstance::PreloadAllNodeInstances()
{
	for (const auto& NodeKeyVal : GetNodeMap())
	{
		ensureMsgf(NodeKeyVal.Value->GetOrCreateNodeInstance(), TEXT("Preload node instance failed for node %s."), *NodeKeyVal.Value->GetNodeName());
	}
}

void USMInstance::ActivateStateLocally(const FGuid& StateGuid, bool bActive, bool bSetAllParents, bool bActivateNow)
{
	EXECUTE_ON_PRIMARY(ActivateStateLocally(StateGuid, bActive, bSetAllParents, bActivateNow));
	
	if (FSMState_Base* State = GetStateByGuid(StateGuid))
	{
		if (FSMStateMachine* StateMachineOwner = static_cast<FSMStateMachine*>(State->GetOwnerNode()))
		{
			if (!bActivateNow)
			{
				StatesPendingActivation.Add(State);
			}
			if (bActive)
			{
				if (!StateMachineOwner->ContainsActiveState(State))
				{
					StateMachineOwner->AddActiveState(State);

					if (bActivateNow)
					{
						StateMachineOwner->TryStartState(State);
					}
					
					if (bSetAllParents)
					{
						return ActivateStateLocally(StateMachineOwner->GetGuid(), bActive, bSetAllParents, bActivateNow);
					}
				}
			}
			else
			{
				StateMachineOwner->RemoveActiveState(State);
				if (bSetAllParents && !StateMachineOwner->HasActiveStates())
				{
					return ActivateStateLocally(StateMachineOwner->GetGuid(), bActive, bSetAllParents, bActivateNow);
				}
			}
		}
	}
}

void USMInstance::SwitchActiveState(USMStateInstance_Base* NewStateInstance, bool bDeactivateOtherStates)
{
	if (bDeactivateOtherStates)
	{
		TSet<FSMStateMachine*> OwningStateMachines;
		if (NewStateInstance)
		{
			if (const FSMNode_Base* OwningState = NewStateInstance->GetOwningNodeAs<FSMState_Base>())
			{
				// Find all super state machines to the new state.
				while (FSMStateMachine* OwningStateMachine = static_cast<FSMStateMachine*>(OwningState->GetOwnerNode()))
				{
					OwningStateMachines.Add(OwningStateMachine);
					OwningState = OwningState->GetOwnerNode();
				}
			}
		}
		
		// Always deactivate other states if they share the same scope or are below the new state.
		// Do not deactivate if they are one of the super state machines to the new state.
		TArray<FSMState_Base*> ActiveStates = GetAllActiveStates();
		for (FSMState_Base* State : ActiveStates)
		{
			if (State->IsStateMachine() && OwningStateMachines.Contains(static_cast<FSMStateMachine*>(State)))
			{
				continue;
			}
			
			USMUtils::ActivateStateNetOrLocal(State, false);
		}
	}

	if (NewStateInstance)
	{
		USMUtils::ActivateStateNetOrLocal(NewStateInstance->GetOwningNodeAs<FSMState_Base>(), true, true);
	}
}

void USMInstance::SwitchActiveStateByQualifiedName(const FString& InFullPath, bool bDeactivateOtherStates)
{
	if (USMStateInstance_Base* NewState = GetStateInstanceByQualifiedName(InFullPath))
	{
		SwitchActiveState(NewState, bDeactivateOtherStates);
	}
}

void USMInstance::LoadFromState(const FGuid& FromGuid, bool bAllParents, bool bNotify)
{
	if (!FromGuid.IsValid())
	{
		return;
	}

	if (FSMState_Base* State = GetStateByGuid(FromGuid))
	{
		if (FSMStateMachine* ParentSM = static_cast<FSMStateMachine*>(State->GetOwnerNode()))
		{
			ensureAlways(State != ParentSM);

			// Don't set when parent is a reference as it will just be forwarded back to this state.
			if (ParentSM->GetInstanceReference() == nullptr)
			{
				ParentSM->AddTemporaryInitialState(State);
			}

			if (bNotify)
			{
				bLoadFromStatesCalled = true;
				OnStateMachineInitialStateLoaded(FromGuid);
			}
			
			if (bAllParents && ParentSM->GetNodeGuid() != RootStateMachineGuid)
			{
				LoadFromState(ParentSM->GetGuid(), bAllParents);
			}
		}
	}
}

void USMInstance::LoadFromMultipleStates(const TArray<FGuid>& FromGuids, bool bNotify)
{
	for (const FGuid& Guid : FromGuids)
	{
		LoadFromState(Guid, false, bNotify);
	}
}

void USMInstance::ClearLoadedStates()
{
	for (const TTuple<FGuid, FSMState_Base*>& State : GetStateMap())
	{
		if (State.Value->IsStateMachine())
		{
			static_cast<FSMStateMachine*>(State.Value)->ClearTemporaryInitialStates(true);
		}
	}
}

void USMInstance::OnStateMachineInitialStateLoaded_Implementation(const FGuid& StateGuid)
{
}

void USMInstance::FinishInitialize()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::FinishInitialize"), STAT_SMInstance_FinishInitialize, STATGROUP_LogicDriver);

	check(IsInGameThread());

	if (IsInitialized())
	{
		LD_LOG_VERBOSE(TEXT("SMInstance::FinishInitialize called after the state machine %s was initialized. This could happen if FinishInitialize was called manually."), *GetName());
		return;
	}

	if (IsPrimaryReferenceOwner())
	{
		TArray<USMInstance*> References = GetAllReferencedInstances(true);
		for (USMInstance* Reference : References)
		{
			Reference->FinishInitialize();
		}
	}
	
	// Graph functions require game thread.
	{
		DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::RootStateMachine.InitializeGraphFunctions"), STAT_SMInstance_RootStateMachine_InitializeGraphFunctions, STATGROUP_LogicDriver);
		RootStateMachine.InitializeGraphFunctions();
	}
	
#if WITH_EDITORONLY_DATA
	// Load debug object for this instance.
	DebugStateMachine = FSMDebugStateMachine();
	for (const auto& KeyVal : GuidNodeMap)
	{
		DebugStateMachine.UpdateRuntimeNode(KeyVal.Value);
	}
#endif

	bInitialized = true;
	
	OnStateMachineInitialized();
	OnStateMachineInitializedEvent.Broadcast(this);
}

bool USMInstance::HandleStopOnEndState()
{
	if (bWaitingForStop)
	{
		return true;
	}
	bool bStopped = false;
	if (bStopOnEndState && IsInEndState() && !HasPendingActiveStates())
	{
		// If internal states need to update they still will.
		if (ISMStateMachineNetworkedInterface* NetworkObject = TryGetNetworkInterface())
		{
			bWaitingForStop = true;
			if (NetworkObject->HasAuthorityToChangeStates())
			{
				// Only signal to stop if we're allowed to. If the client is authoritative but is only following
				// server transactions then the client should request the stop.
				NetworkObject->ServerStop();
			}
			bStopped = true;
		}
		else
		{
			Stop();
			bStopped = true;
		}
	}

	return bStopped;
}

FString USMInstance::GetActiveStateName() const
{
	if (FSMState_Base* CurrentState = GetSingleActiveState())
	{
		return CurrentState->GetNodeName();
	}

	return FString();
}

FString USMInstance::GetNestedActiveStateName() const
{
	FSMState_Base* CurrentState = GetSingleNestedActiveState();
	if (CurrentState)
	{
		return CurrentState->GetNodeName();
	}

	return FString();
}

FGuid USMInstance::GetActiveStateGuid() const
{
	if (FSMState_Base* CurrentState = GetSingleActiveState())
	{
		return CurrentState->GetGuid();
	}

	return FGuid();
}

FGuid USMInstance::GetNestedActiveStateGuid() const
{
	FSMState_Base* CurrentState = GetSingleNestedActiveState();
	if (CurrentState)
	{
		return CurrentState->GetGuid();
	}

	return FGuid();
}

void USMInstance::TryGetNestedActiveState(FSMStateInfo& FoundState, bool& bSuccess) const
{
	if (FSMState_Base* State = GetSingleNestedActiveState())
	{
		FoundState = *State;
		bSuccess = true;
		return;
	}

	bSuccess = false;
}

FSMState_Base* USMInstance::GetSingleActiveState() const
{
	return RootStateMachine.GetSingleActiveState();
}

FSMState_Base* USMInstance::GetSingleNestedActiveState() const
{
	FSMState_Base* CurrentState = RootStateMachine.GetSingleActiveState();

	if (CurrentState != nullptr)
	{
		while (CurrentState->IsStateMachine())
		{
			FSMState_Base* SubCurrentState = ((FSMStateMachine*)CurrentState)->GetSingleActiveState();
			if (SubCurrentState == nullptr || SubCurrentState == CurrentState)
			{
				// This could be an empty state machine in which case return itself.
				// The state equal to itself isn't possible, but maybe a user did something weird.
				break;
			}

			CurrentState = SubCurrentState;
		}
	}

	return CurrentState;
}

TArray<FSMState_Base*> USMInstance::GetAllActiveStates() const
{
	return RootStateMachine.GetAllNestedActiveStates();
}

TArray<FGuid> USMInstance::GetAllCurrentStateGuids() const
{
	TArray<FGuid> CurrentGuids;
	GetAllActiveStateGuids(CurrentGuids);

	return CurrentGuids;
}

FGuid USMInstance::GetSingleActiveStateGuid(bool bCheckNested) const
{
	if (FSMState_Base* CurrentState = bCheckNested ? GetSingleNestedActiveState() : GetSingleActiveState())
	{
		return CurrentState->GetGuid();
	}

	return FGuid();
}

void USMInstance::GetAllActiveStateGuids(TArray<FGuid>& ActiveGuids) const
{
	ActiveGuids.Reset();
	
	TArray<FSMState_Base*> CurrentStates = GetAllActiveStates();
	for (FSMState_Base* State : CurrentStates)
	{
		ActiveGuids.AddUnique(State->GetGuid());
	}
}

TArray<FGuid> USMInstance::GetAllActiveStateGuidsCopy() const
{
	TArray<FGuid> OutGuids;
	GetAllActiveStateGuids(OutGuids);

	return OutGuids;
}

USMStateInstance_Base* USMInstance::GetActiveStateInstance(bool bCheckNested) const
{
	return GetSingleActiveStateInstance(bCheckNested);
}

USMStateInstance_Base* USMInstance::GetSingleActiveStateInstance(bool bCheckNested) const
{
	if (FSMState_Base* CurrentState = bCheckNested ? GetSingleNestedActiveState() : GetSingleActiveState())
	{
		return Cast<USMStateInstance_Base>(CurrentState->GetOrCreateNodeInstance());
	}

	return nullptr;
}

void USMInstance::GetAllActiveStateInstances(TArray<USMStateInstance_Base*>& ActiveStateInstances) const
{
	ActiveStateInstances.Reset();

	for (FSMState_Base* State : GetAllActiveStates())
	{
		if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(State->GetOrCreateNodeInstance()))
		{
			ActiveStateInstances.Add(StateInstance);
		}
	}
}

TArray<USMInstance*> USMInstance::GetAllReferencedInstances(bool bIncludeChildren) const
{
	TArray<USMInstance*> ReturnValue;

	for (const FGuid& StateMachineGuid : StateMachineGuids)
	{
		if (const FSMStateMachine* StateMachine = static_cast<FSMStateMachine*>(GetStateByGuid(StateMachineGuid)))
		{
			USMInstance* InstanceReference = StateMachine->GetInstanceReference();
			if (!InstanceReference)
			{
				continue;
			}

			// Verify we directly own this instance and it isn't a grand child.
			if (!bIncludeChildren && InstanceReference->GetRootStateMachine().GetReferencedByInstance() != this)
			{
				continue;
			}

			ReturnValue.Add(InstanceReference);
		}
	}

	return ReturnValue;
}

TArray<FSMStateMachine*> USMInstance::GetStateMachinesWithReferences(bool bIncludeChildren) const
{
	TArray<FSMStateMachine*> ReturnValue;

	for (const FGuid& StateMachineGuid : StateMachineGuids)
	{
		if (FSMStateMachine* StateMachine = static_cast<FSMStateMachine*>(GetStateByGuid(StateMachineGuid)))
		{
			USMInstance* InstanceReference = StateMachine->GetInstanceReference();
			if (!InstanceReference)
			{
				continue;
			}

			// Verify we directly own this instance and it isn't a grand child.
			if (!bIncludeChildren && InstanceReference->GetRootStateMachine().GetReferencedByInstance() != this)
			{
				continue;
			}

			ReturnValue.AddUnique(StateMachine);
		}
	}

	return ReturnValue;
}

void USMInstance::TryGetStateInfo(const FGuid& Guid, FSMStateInfo& StateInfo, bool& bSuccess) const
{
	EXECUTE_ON_PRIMARY_CONST(TryGetStateInfo(Guid, StateInfo, bSuccess));
	
	if (const FSMState_Base* FoundState = GetStateByGuid(Guid))
	{
		StateInfo = FSMStateInfo(*FoundState);
		bSuccess = true;
		return;
	}

	bSuccess = false;
}

void USMInstance::TryGetTransitionInfo(const FGuid& Guid, FSMTransitionInfo& TransitionInfo, bool& bSuccess) const
{
	EXECUTE_ON_PRIMARY_CONST(TryGetTransitionInfo(Guid, TransitionInfo, bSuccess));

	if (const FSMTransition* FoundTransition = GetTransitionByGuid(Guid))
	{
		TransitionInfo = FSMTransitionInfo(*FoundTransition);
		bSuccess = true;
		return;
	}

	bSuccess = false;
}

USMInstance* USMInstance::GetReferencedInstanceByGuid(const FGuid& Guid) const
{
	EXECUTE_ON_PRIMARY_CONST(GetReferencedInstanceByGuid(Guid));
	
	if (FSMState_Base* State = GetStateByGuid(Guid))
	{
		if (State->IsStateMachine())
		{
			return static_cast<FSMStateMachine*>(State)->GetInstanceReference();
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMInstance::GetStateInstanceByGuid(const FGuid& Guid) const
{
	EXECUTE_ON_PRIMARY_CONST(GetStateInstanceByGuid(Guid));

	if (FSMState_Base* State = GetStateByGuid(Guid))
	{
		return Cast<USMStateInstance_Base>(State->GetOrCreateNodeInstance());
	}

	return nullptr;
}

USMTransitionInstance* USMInstance::GetTransitionInstanceByGuid(const FGuid& Guid) const
{
	EXECUTE_ON_PRIMARY_CONST(GetTransitionInstanceByGuid(Guid));

	if (FSMTransition* Transition = GetTransitionByGuid(Guid))
	{
		return Cast<USMTransitionInstance>(Transition->GetOrCreateNodeInstance());
	}

	return nullptr;
}

USMNodeInstance* USMInstance::GetNodeInstanceByGuid(const FGuid& Guid) const
{
	EXECUTE_ON_PRIMARY_CONST(GetNodeInstanceByGuid(Guid));

	if (FSMNode_Base* Node = GetNodeByGuid(Guid))
	{
		return Node->GetOrCreateNodeInstance();
	}

	return nullptr;
}

USMStateInstance_Base* USMInstance::GetStateInstanceByQualifiedName(const FString& InFullPath) const
{
	EXECUTE_ON_PRIMARY_CONST(GetStateInstanceByQualifiedName(InFullPath));

	TArray<FString> OutNames;
	const int32 NodePathSize = InFullPath.ParseIntoArray(OutNames, TEXT("."));

	if (NodePathSize == 0)
	{
		if (!InFullPath.IsEmpty())
		{
			OutNames.Add(InFullPath);
		}
		else
		{
			LD_LOG_ERROR(TEXT("SMInstance::GetStateInstanceByQualifiedName: No input provided."),
				*InFullPath);
			return nullptr;
		}
	}

	USMStateInstance_Base* CurrentNode = GetRootStateMachineNodeInstance();
	if (CurrentNode)
	{
		while (OutNames.Num() > 0)
		{
			FString& NodeName = OutNames[0];

			if (CurrentNode->IsStateMachine())
			{
				USMStateMachineInstance* StateMachineNode = CastChecked<USMStateMachineInstance>(CurrentNode);
				if (const USMInstance* ReferenceInstance = StateMachineNode->GetStateMachineReference())
				{
					CurrentNode = ReferenceInstance->GetRootStateMachineNodeInstance()->GetContainedStateByName(NodeName);
				}
				else
				{
					CurrentNode = StateMachineNode->GetContainedStateByName(NodeName);
					if (!CurrentNode)
					{
						const FString RootNodeName = GetRootNodeNameDefault();
						if (!CurrentNode && NodeName == RootNodeName && StateMachineNode->GetNodeName() == RootNodeName)
						{
							CurrentNode = StateMachineNode;
						}
					}
				}
			}

			if (!CurrentNode)
			{
				LD_LOG_ERROR(TEXT("SMInstance::GetStateInstanceByQualifiedName: Could not find node %s in state machine blueprint %s."),
					*NodeName, *GetName());
				return nullptr;
			}
		
			if (CurrentNode->GetNodeName() != NodeName)
			{
				LD_LOG_ERROR(TEXT("SMInstance::GetStateInstanceByQualifiedName: Found node %s but expected node %s in state machine blueprint %s."),
					*CurrentNode->GetNodeName(), *NodeName, *GetName());
				return nullptr;
			}
		
			OutNames.RemoveAt(0);
		}
	}
	
	return CurrentNode;
}

FSMState_Base* USMInstance::GetStateByGuid(const FGuid& Guid) const
{
	if (FSMState_Base* const* State = GuidStateMap.Find(GetRedirectedGuid(Guid)))
	{
		return *State;
	}

	return nullptr;
}

FSMTransition* USMInstance::GetTransitionByGuid(const FGuid& Guid) const
{
	if (FSMTransition* const* Transition = GuidTransitionMap.Find(GetRedirectedGuid(Guid)))
	{
		return *Transition;
	}

	return nullptr;
}

FSMNode_Base* USMInstance::GetNodeByGuid(const FGuid& Guid) const
{
	if (FSMNode_Base* const* Value = GetNodeMap().Find(GetRedirectedGuid(Guid)))
	{
		return *Value;
	}

	return nullptr;
}

FSMState_Base* USMInstance::FindStateByGuid(const FGuid& Guid) const
{
	const FGuid GuidToUse = GetRedirectedGuid(Guid);
	if (RootStateMachineGuid == GuidToUse)
	{
		return const_cast<FSMStateMachine*>(&RootStateMachine);
	}
	return RootStateMachine.FindState(GuidToUse);
}

FGuid USMInstance::GetRedirectedGuid(const FGuid& InPathGuid) const
{
	if (const FGuid* RedirectedGuid = PathGuidRedirectMap.Find(InPathGuid))
	{
		return *RedirectedGuid;
	}

	return InPathGuid;
}

USMStateMachineInstance* USMInstance::GetRootStateMachineNodeInstance() const
{
	return Cast<USMStateMachineInstance>(const_cast<FSMStateMachine&>(RootStateMachine).GetOrCreateNodeInstance());
}

bool USMInstance::IsActive() const
{
	return bInitialized ? RootStateMachine.IsActive() : false;
}

void USMInstance::SetCanEverTick(bool Value)
{
	bCanEverTick = Value;
}

void USMInstance::SetRegisterTick(bool Value)
{
	bTickRegistered = Value;
}

void USMInstance::SetTickOnManualUpdate(bool Value)
{
	bCallTickOnManualUpdate = Value;
}

void USMInstance::SetCanTickWhenPaused(bool Value)
{
	bCanTickWhenPaused = Value;
}

#if WITH_EDITORONLY_DATA
void USMInstance::SetCanTickInEditor(bool Value)
{
	bCanTickInEditor = Value;
}
#endif

void USMInstance::SetTickBeforeBeginPlay(bool Value)
{
	bTickBeforeBeginPlay = Value;
}

void USMInstance::SetTickInterval(float Value)
{
	TickInterval = Value;
}

void USMInstance::SetAutoManageTime(bool Value)
{
	bAutoManageTime = Value;
}

void USMInstance::SetStopOnEndState(bool Value)
{
	bStopOnEndState = Value;
}

bool USMInstance::IsInEndState() const
{
	return RootStateMachine.IsInEndState();
}

void USMInstance::SetContext(UObject* Context)
{
	R_StateMachineContext = Context;
	if (IsPrimaryReferenceOwner() && R_StateMachineContext && GetOuter() != R_StateMachineContext)
	{
		Rename(nullptr, R_StateMachineContext, REN_DoNotDirty | REN_DontCreateRedirectors | REN_ForceNoResetLoaders);
	}
}

const TArray<FSMStateHistory>& USMInstance::GetStateHistory() const
{
	EXECUTE_ON_PRIMARY_CONST(GetStateHistory());
	return StateHistory;
}

void USMInstance::SetStateHistoryMaxCount(int32 NewSize)
{
	EXECUTE_ON_PRIMARY(SetStateHistoryMaxCount(NewSize));
	StateHistoryMaxCount = NewSize;
	TrimStateHistory();
}

int32 USMInstance::GetStateHistoryMaxCount() const
{
	EXECUTE_ON_PRIMARY_CONST(GetStateHistoryMaxCount());
	return StateHistoryMaxCount;
}

void USMInstance::ClearStateHistory()
{
	EXECUTE_ON_PRIMARY(ClearStateHistory());
	StateHistory.Empty();
}

void USMInstance::GetAllStateInstances(TArray<USMStateInstance_Base*>& StateInstances) const
{
	StateInstances.Reset();
	
	const TMap<FGuid, FSMState_Base*>& StateMap = GetStateMap();
	for (const auto& KeyVal : StateMap)
	{
		if (!KeyVal.Value->CanEverCreateNodeInstance())
		{
			// Prevents references from being counted twice.
			continue;
		}
		if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(KeyVal.Value->GetOrCreateNodeInstance()))
		{
			StateInstances.Add(StateInstance);
		}
	}
}

void USMInstance::GetAllTransitionInstances(TArray<USMTransitionInstance*>& TransitionInstances) const
{
	TransitionInstances.Reset();
	
	const TMap<FGuid, FSMTransition*>& TransitionMap = GetTransitionMap();
	for (const auto& KeyVal : TransitionMap)
	{
		if (USMTransitionInstance* TransitionInstance = Cast<USMTransitionInstance>(KeyVal.Value->GetOrCreateNodeInstance()))
		{
			TransitionInstances.Add(TransitionInstance);
		}
	}
}

void USMInstance::SetNetworkInterface(TScriptInterface<ISMStateMachineNetworkedInterface> InNetworkInterface)
{
	NetworkInterface = InNetworkInterface;
}

TScriptInterface<ISMStateMachineNetworkedInterface> USMInstance::GetNetworkInterface() const
{
	EXECUTE_ON_PRIMARY_CONST(GetNetworkInterface());
	return NetworkInterface;
}

void USMInstance::K2_TryGetNetworkInterface(TScriptInterface<ISMStateMachineNetworkedInterface>& Interface,
	bool& bIsValid)
{
	EXECUTE_ON_PRIMARY(K2_TryGetNetworkInterface(Interface, bIsValid));
	if (NetworkInterface.GetObject())
	{
		Interface = NetworkInterface;
		bIsValid = true;
		return;
	}

	bIsValid = false;
}

ISMStateMachineNetworkedInterface* USMInstance::TryGetNetworkInterface() const
{
	EXECUTE_ON_PRIMARY_CONST(TryGetNetworkInterface());
	if (NetworkInterface.GetObject() && NetworkInterface->IsConfiguredForNetworking())
	{
		return Cast<ISMStateMachineNetworkedInterface>(NetworkInterface.GetObject());
	}

	return nullptr;
}

void USMInstance::UpdateNetworkConditions()
{
	for (const auto& StateMachineGuid : StateMachineGuids)
	{
		FSMStateMachine* Node = static_cast<FSMStateMachine*>(GuidNodeMap.FindRef(StateMachineGuid));

		if (USMInstance* ReferencedStateMachine = Node->GetInstanceReference())
		{
			// The referenced instance will inherit the owning instance's network settings.
			ReferencedStateMachine->CopyNetworkConditionsFrom(this, true);
		}
		else
		{
			Node->SetNetworkedConditions(GetNetworkInterface(), bCanEvaluateTransitionsLocally, bCanTakeTransitionsLocally, bCanExecuteStateLogic);
		}
	}
}

void USMInstance::CopyNetworkConditionsFrom(USMInstance* OtherInstance, bool bUpdateNodes)
{
	check(OtherInstance);
	
	SetNetworkInterface(OtherInstance->NetworkInterface);
	SetAllowTransitionsLocally(OtherInstance->bCanEvaluateTransitionsLocally, OtherInstance->bCanTakeTransitionsLocally);
	SetAllowStateLogic(OtherInstance->bCanExecuteStateLogic);

	if (bUpdateNodes)
	{
		UpdateNetworkConditions();
	}
}

void USMInstance::SetAllowTransitionsLocally(bool bCanEvaluateTransitions, bool bCanTakeTransitions)
{
	bCanEvaluateTransitionsLocally = bCanEvaluateTransitions;
	bCanTakeTransitionsLocally = bCanTakeTransitions;
}

void USMInstance::SetAllowStateLogic(bool bAllow)
{
	bCanExecuteStateLogic = bAllow;
}

bool USMInstance::IsReferenceTemplate() const
{
	return HasAnyFlags(RF_ArchetypeObject) && !HasAnyFlags(RF_ClassDefaultObject) && GetName().StartsWith("TEMPLATE");
}

void USMInstance::SetReferenceOwner(USMInstance* Owner)
{
	ReferenceOwner = Owner;
	if (ReferenceOwner && ReferenceOwner != GetOuter())
	{
		Rename(nullptr, ReferenceOwner, REN_DoNotDirty | REN_DontCreateRedirectors | REN_ForceNoResetLoaders);
	}
}

void USMInstance::AddReplicatedReference(const FGuid& PathGuid, USMInstance* NewReference)
{
	EXECUTE_ON_PRIMARY(AddReplicatedReference(PathGuid, NewReference));
	FSMReferenceContainer ReferenceContainer;
	ReferenceContainer.PathGuid = PathGuid;
	ReferenceContainer.Reference = NewReference;
	ReplicatedReferences.Add(MoveTemp(ReferenceContainer));
}

USMInstance* USMInstance::FindReplicatedReference(const FGuid& PathGuid) const
{
	EXECUTE_ON_PRIMARY_CONST(FindReplicatedReference(PathGuid));
	if (const FSMReferenceContainer* Container = ReplicatedReferences.FindByPredicate([PathGuid](const FSMReferenceContainer& ReferenceContainer)
	{
		return ReferenceContainer.PathGuid == PathGuid;
	}))
	{
		return Container->Reference;
	}

	return nullptr;
}

bool USMInstance::HaveAllReferencesReplicated() const
{
	for (const FSMReferenceContainer& ReferenceContainer : ReplicatedReferences)
	{
		if (ReferenceContainer.Reference == nullptr)
		{
			return false;
		}
	}

	return true;
}

void USMInstance::REP_OnReplicatedReferencesLoaded()
{
	if (HaveAllReferencesReplicated())
	{
		OnReferencesReplicatedEvent.ExecuteIfBound();
	}
}

const USMInstance* USMInstance::GetPrimaryReferenceOwnerConst() const
{
	const USMInstance* Parent = ReferenceOwner;
	while (Parent)
	{
		const USMInstance* Next = Parent->GetReferenceOwnerConst();
		if (!Next)
		{
			return Parent;
		}
		Parent = Next;
	}

	return this;
}

USMInstance* USMInstance::GetPrimaryReferenceOwner()
{
	USMInstance* Parent = ReferenceOwner;
	while (Parent)
	{
		USMInstance* Next = Parent->GetReferenceOwner();
		if (!Next)
		{
			return Parent;
		}
		Parent = Next;
	}

	return this;
}

void USMInstance::NotifyTransitionTaken(const FSMTransition& Transition)
{
	const FSMTransitionInfo TransitionInfo(Transition);

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	if (IsLoggingEnabled() && bLogTransitionTaken)
	{
		LD_LOG_INFO(TEXT("[%s] Transition taken: %s"), *GetName(), *TransitionInfo.ToString());
	}
#endif
	
	OnStateMachineTransitionTaken(TransitionInfo);
	OnStateMachineTransitionTakenEvent.Broadcast(this, TransitionInfo);

	if (!IsPrimaryReferenceOwner())
	{
		EXECUTE_ON_PRIMARY(NotifyTransitionTaken(Transition));
	}
}

void USMInstance::NotifyStateChange(FSMState_Base* ToState, FSMState_Base* FromState)
{
	const FSMStateInfo ToStateInfo(ToState ? *ToState : FSMState_Base());
	const FSMStateInfo FromStateInfo(FromState ? *FromState : FSMState_Base());

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	if (IsLoggingEnabled() && bLogStateChange)
	{
		LD_LOG_INFO(TEXT("[%s] State change: from %s to %s"), *GetName(), *FromStateInfo.ToString(), *ToStateInfo.ToString());
	}
#endif

	RecordPreviousStateHistory(FromState);
	
	OnStateMachineStateChanged(ToStateInfo, FromStateInfo);
	OnStateMachineStateChangedEvent.Broadcast(this, ToStateInfo, FromStateInfo);

	if (!IsPrimaryReferenceOwner())
	{
		EXECUTE_ON_PRIMARY(NotifyStateChange(ToState, FromState));
	}
}

void USMInstance::NotifyStateStarted(const FSMState_Base& State)
{
	const FSMStateInfo StateInfo(State);
	OnStateMachineStateStarted(StateInfo);
	OnStateMachineStateStartedEvent.Broadcast(this, StateInfo);

	if (!IsPrimaryReferenceOwner())
	{
		EXECUTE_ON_PRIMARY(NotifyStateStarted(State));
	}
}

void USMInstance::Tick_Implementation(float DeltaTime)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMInstance::Tick"), STAT_SMInstance_Tick, STATGROUP_LogicDriver);
	
	if (!CanEverTick() || bIsTicking)
	{
		return;
	}

	// Check if we are allowed to tick depending on the interval.
	TimeSinceAllowedTick += DeltaTime;
	if (TimeSinceAllowedTick < TickInterval)
	{
		return;
	}

	// Signal we are ticking in case an update tries to call tick manually.
	bIsTicking = true;

	// It's possible we're not initialized but still ticking. This saves us a call and a warning.
	if (IsInitialized())
	{
		Update(TimeSinceAllowedTick);
	}

	TimeSinceAllowedTick = 0.f;

	bIsTicking = false;
}

void USMInstance::RunUpdateAsReference(float DeltaSeconds)
{
	Internal_Update(DeltaSeconds);
}

void USMInstance::Internal_Update(float DeltaSeconds)
{
	// It's okay to do a full update if this wasn't called by Update.
	if (!IsUpdating())
	{
		return Update(DeltaSeconds);
	}
	
	// Perform after end state check and before update routine.
	StatesPendingActivation.Empty();
	
	OnStateMachineUpdate(DeltaSeconds);
	OnStateMachineUpdatedEvent.Broadcast(this, DeltaSeconds);

	RootStateMachine.UpdateState(DeltaSeconds);
	
	// Run again after updating as the state machine could have moved into an end state.
	if (HandleStopOnEndState())
	{
		return;
	}
}

bool USMInstance::Internal_EvaluateAndTakeTransitionChainByGuid(const FGuid& PathGuid)
{
	EXECUTE_ON_PRIMARY(Internal_EvaluateAndTakeTransitionChainByGuid(PathGuid))
	
	if (FSMTransition* Transition = GetTransitionByGuid(PathGuid))
	{
		return EvaluateAndTakeTransitionChain(*Transition);
	}

	return false;
}

void USMInstance::Internal_EventUpdate()
{
	EXECUTE_ON_PRIMARY(Internal_EventUpdate());
	Internal_Update(0.f);
}

void USMInstance::Internal_EventCleanup(const FGuid& PathGuid)
{
	EXECUTE_ON_PRIMARY(Internal_EventCleanup(PathGuid))
	
	if (FSMTransition* Transition = GetTransitionByGuid(PathGuid))
	{
		// Auto-bound events will set bIsEvaluating to true primarily for debugging. However if two events fire at the exact same time
		// it won't be set to false unless this cleanup method is run.
		Transition->bIsEvaluating = false;
	}
}

void USMInstance::BuildStateMachineMap(FSMStateMachine* StateMachine, TSet<USMInstance*>& InstancesMapped)
{
	InstancesMapped.Add(this);
	
	const FGuid& StateMachineGuid = StateMachine->GetGuid();
	
	// Reference self.
	ensureMsgf(!StateMachineGuids.Contains(StateMachineGuid), TEXT("State machine %s already contains state machine guid %s"), *GetName(), *StateMachineGuid.ToString());
	StateMachineGuids.Add(StateMachineGuid);
	
	// This check prevents the state machine referenced from overriding the parent duplicate that points to the reference.
	if (!GuidNodeMap.Contains(StateMachineGuid))
	{
		GuidNodeMap.Add(StateMachineGuid, StateMachine);
		GuidStateMap.Add(StateMachineGuid, StateMachine);
	}

	// Build out guids of all contained nodes in references.
	if (USMInstance* ReferencedStateMachine = StateMachine->GetInstanceReference())
	{
		if (!InstancesMapped.Contains(ReferencedStateMachine))
		{
			InstancesMapped.Add(ReferencedStateMachine);
			BuildStateMachineMap(&ReferencedStateMachine->GetRootStateMachine(), InstancesMapped);
		}
		return;
	}

	for (FSMTransition* Transition : StateMachine->GetTransitions())
	{
		const FGuid& Guid = Transition->GetGuid();
		/*
		 * Unique GUID check 2:
		 * The PathGuid at this stage should always be unique and the ensure should never be tripped.
		 * The Guid here is calculated based on the path of the node in the state machine which allows multiple same reference calls to exist in the same blueprint.
		 *
		 * If this is triggered please check to make sure the state machine blueprint in question doesn't do anything abnormal such as use circular referencing.
		 */
		ensureAlwaysMsgf(!GuidNodeMap.Contains(Guid), TEXT("State machine %s already contains transition guid %s"), *GetName(), *Guid.ToString());
		
		GuidNodeMap.Add(Guid, Transition);
		GuidTransitionMap.Add(Guid, Transition);
	}

	for (FSMState_Base* State : StateMachine->GetStates())
	{
		const FGuid& Guid = State->GetGuid();
		/*
		 * Unique GUID check 2:
		 * The PathGuid at this stage should always be unique and the ensure should never be tripped.
		 * The Guid here is calculated based on the path of the node in the state machine which allows multiple same reference calls to exist in the same blueprint.
		 *
		 * If this is triggered please check to make sure the state machine blueprint in question doesn't do anything abnormal such as use circular referencing.
		 */
		ensureAlwaysMsgf(!GuidNodeMap.Contains(Guid), TEXT("State machine %s already contains state guid %s"), *GetName(), *Guid.ToString());
		
		GuidNodeMap.Add(Guid, State);
		GuidStateMap.Add(Guid, State);
		
		if (State->IsStateMachine())
		{
			BuildStateMachineMap((FSMStateMachine*)State, InstancesMapped);
		}
	}
}

bool USMInstance::CheckIsInitialized() const
{
	if (!IsInitialized())
	{
		LD_LOG_WARNING(TEXT("Attempted to use State Machine Instance when it wasn't initialized"));
		return false;
	}

	if (IsPendingKillOrUnreachable())
	{
		// This happens quite a bit in normal practice.
		//LD_LOG_INFO(TEXT("Attempted to use State Machine Instance when it was pending kill or unreachable"));
		return false;
	}

	return true;
}

void USMInstance::UpdateTime()
{
	if (const UWorld* World = GetWorld())
	{
		const float NewTime = bCanTickWhenPaused ? World->GetUnpausedTimeSeconds() : World->GetTimeSeconds();
		WorldTimeDelta = NewTime - WorldSeconds;
		WorldSeconds = NewTime;
	}
	else
	{
		WorldTimeDelta = WorldSeconds = 0.f;
	}
}

void USMInstance::RecordPreviousStateHistory(FSMState_Base* PreviousState)
{
	EXECUTE_ON_PRIMARY(RecordPreviousStateHistory(PreviousState));
	
	if (!PreviousState || StateHistoryMaxCount == 0)
	{
		return;
	}

	const FSMStateHistory StateHistoryInfo
	{
		PreviousState->GetGuid(),
		PreviousState->GetStartTime(),
		PreviousState->GetActiveTime(),
		PreviousState->GetServerTimeInState()
	};
	
	StateHistory.Add(StateHistoryInfo);
	TrimStateHistory();
}

void USMInstance::TrimStateHistory()
{
	EXECUTE_ON_PRIMARY(TrimStateHistory());
	
	const int32 CountToRemove = StateHistory.Num() - StateHistoryMaxCount;
	if (CountToRemove > 0)
	{
		StateHistory.RemoveAt(0, CountToRemove);
	}
}

void USMInstance::DoStart()
{
	TimeSinceAllowedTick = 0.f;
	OnStateMachineStart();
	OnStateMachineStartedEvent.Broadcast(this);

	// Let states run any initialization logic.
	for (const auto& KeyVal : GetNodeMap())
	{
		KeyVal.Value->OnStartedByInstance(this);
	}
	
	RootStateMachine.StartState();

	// Checks for case where the state machine starts and finishes and destroys itself in 1 frame.
	if (!IsValid(this) || IsUnreachable() || HasAnyFlags(RF_BeginDestroyed | RF_FinishDestroyed))
	{
		return;
	}

	UpdateTime();
}

#undef LOCTEXT_NAMESPACE