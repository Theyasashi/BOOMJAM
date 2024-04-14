// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMState.h"
#include "SMTransition.h"
#include "SMStateInstance.h"
#include "SMUtils.h"
#include "SMLogging.h"

void FSMState_Base::UpdateReadStates()
{
	Super::UpdateReadStates();
	bIsInEndState = IsEndState();
	bHasUpdated = HasUpdated();
	TimeInState = GetActiveTime();
}

void FSMState_Base::ResetReadStates()
{
	bHasUpdated = false;
	bIsInEndState = false;
	TimeInState = 0.f;
	SetServerTimeInState(SM_ACTIVE_TIME_NOT_SET);
}

FSMState_Base::FSMState_Base() : Super(), bIsRootNode(false), bAlwaysUpdate(false), bEvalTransitionsOnStart(false),
                                 bDisableTickTransitionEvaluation(false), bStayActiveOnStateChange(false), bAllowParallelReentry(false),
                                 bReenteredByParallelState(false), bCanExecuteLogic(true), bIsStateEnding(false), PreviousActiveState(nullptr),
                                 PreviousActiveTransition(nullptr), StartTime(0), EndTime(0), NextTransition(nullptr)
{
	ResetReadStates();
}

void FSMState_Base::Initialize(UObject* Instance)
{
	Super::Initialize(Instance);

	ResetReadStates();
	SortTransitions();
}

void FSMState_Base::InitializeGraphFunctions()
{
	FSMNode_Base::InitializeGraphFunctions();
}

void FSMState_Base::Reset()
{
	Super::Reset();
	ResetReadStates();
}

bool FSMState_Base::IsNodeInstanceClassCompatible(UClass* NewNodeInstanceClass) const
{
	return NewNodeInstanceClass && NewNodeInstanceClass->IsChildOf<USMStateInstance>();
}

UClass* FSMState_Base::GetDefaultNodeInstanceClass() const
{
	return USMStateInstance::StaticClass();
}

void FSMState_Base::ExecuteInitializeNodes()
{
	Super::ExecuteInitializeNodes();
}

void FSMState_Base::GetAllTransitionChains(TArray<FSMTransition*>& OutTransitions) const
{
	for (FSMTransition* Transition : OutgoingTransitions)
	{
		Transition->GetConnectedTransitions(OutTransitions);
	}
}

bool FSMState_Base::StartState()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMState_Base::StartState"), STAT_SMState_Start, STATGROUP_LogicDriver);
	
	NextTransition = nullptr;
	
	if (IsActive() && (!HasBeenReenteredFromParallelState() || !bAllowParallelReentry))
	{
		return false;
	}
	
	SetStartTime(FDateTime::UtcNow());

	ResetReadStates();
	
#if WITH_EDITORONLY_DATA
	StartCycle = FPlatformTime::Cycles64();
#endif

	SetActive(true);

	FirePreStartEvents();

	NotifyInstanceStateHasStarted();

	InitializeTransitions();
	
	return true;
}

bool FSMState_Base::UpdateState(float DeltaSeconds)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMState_Base::UpdateState"), STAT_SMState_Update, STATGROUP_LogicDriver);
	
	if (!IsActive())
	{
		return false;
	}

	TimeInState += DeltaSeconds;
	UpdateReadStates();

	if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(NodeInstance))
	{
		StateInstance->OnStateUpdateEvent.Broadcast(StateInstance, DeltaSeconds);
	}
	
	return bHasUpdated = true;
}

bool FSMState_Base::EndState(float DeltaSeconds, const FSMTransition* TransitionToTake)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMState_Base::EndState"), STAT_SMState_End, STATGROUP_LogicDriver);
	
	if (!IsActive())
	{
		return false;
	}

	SetEndTime(FDateTime::UtcNow());
	
	SetTransitionToTake(TransitionToTake);

	if (bAlwaysUpdate && !HasUpdated())
	{
		UpdateState(DeltaSeconds);
	}
	else
	{
		// Record the extra time for accuracy.
		TimeInState += DeltaSeconds;
	}

	UpdateReadStates();

	if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(NodeInstance))
	{
		StateInstance->OnStateEndEvent.Broadcast(StateInstance);
	}
	
	SetActive(false);

	return true;
}

void FSMState_Base::OnStartedByInstance(USMInstance* Instance)
{
	// Only execute if allowed and if it's this owning instance starting it.
	// This means reference nodes won't initialize until their owning blueprint is started.
	if (CanExecuteLogic() && Instance == GetOwningInstance())
	{
		UpdateReadStates();
		USMUtils::ExecuteGraphFunctions(OnRootStateMachineStartedGraphEvaluator);
	}
}

void FSMState_Base::OnStoppedByInstance(USMInstance* Instance)
{
	// Only execute if allowed and if it's this owning instance.
	if (CanExecuteLogic() && Instance == GetOwningInstance())
	{
		UpdateReadStates();
		USMUtils::ExecuteGraphFunctions(OnRootStateMachineStoppedGraphEvaluator);
	}
}

bool FSMState_Base::GetValidTransition(TArray<TArray<FSMTransition*>>& Transitions)
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("SMState_Base::GetValidTransition"), STAT_SMState_GetValidTransition, STATGROUP_LogicDriver);
	
	for (FSMTransition* Transition : OutgoingTransitions)
	{
		TArray<FSMTransition*> Chain;
		if (Transition->CanTransition(Chain))
		{
			Transitions.Add(MoveTemp(Chain));

			// Check if blocking or not.
			if (IsConduit() || !Transition->bRunParallel)
			{
				return true;
			}
		}
	}

	return Transitions.Num() > 0;
}

bool FSMState_Base::IsEndState() const
{
	for (FSMTransition* Transition : OutgoingTransitions)
	{
		// Look for at least one valid transition.
		if (!Transition->bAlwaysFalse)
		{
			return false;
		}
	}

	return true;
}

bool FSMState_Base::IsInEndState() const
{
	return IsEndState();
}

bool FSMState_Base::HasUpdated() const
{
	return bHasUpdated;
}

void FSMState_Base::SetCanExecuteLogic(bool bValue)
{
	bCanExecuteLogic = bValue;
}

bool FSMState_Base::CanEvaluateTransitionsOnTick() const
{
	if (bDisableTickTransitionEvaluation)
	{
		/* Check if any immediate outgoing transition has just completed from an event before returning false. */
		for (FSMTransition* Transition : OutgoingTransitions)
		{
			if (Transition->CanTransitionFromEvent())
			{
				return true;
			}
		}
	}

	return !bDisableTickTransitionEvaluation;
}

void FSMState_Base::SortTransitions()
{
	OutgoingTransitions.Sort([](const FSMTransition& lhs, const FSMTransition& rhs)
	{
		return lhs.Priority < rhs.Priority;
	});

	IncomingTransitions.Sort([](const FSMTransition& lhs, const FSMTransition& rhs)
	{
		return lhs.Priority < rhs.Priority;
	});
}

void FSMState_Base::SetTransitionToTake(const FSMTransition* Transition)
{
	NextTransition = Transition;

	if (NextTransition)
	{
		SetServerTimeInState(NextTransition->GetServerTimeInState());
	}
}

void FSMState_Base::SetPreviousActiveState(FSMState_Base* InPreviousState)
{
	PreviousActiveState = InPreviousState;
}

void FSMState_Base::SetPreviousActiveTransition(FSMTransition* InPreviousTransition)
{
	PreviousActiveTransition = InPreviousTransition;
}

void FSMState_Base::NotifyOfParallelReentry(bool bValue)
{
	bReenteredByParallelState = bValue;
}

void FSMState_Base::SetStartTime(const FDateTime& InStartTime)
{
	StartTime = InStartTime;
}

void FSMState_Base::SetEndTime(const FDateTime& InEndTime)
{
	EndTime = InEndTime;
}

void FSMState_Base::AddOutgoingTransition(FSMTransition* Transition)
{
	OutgoingTransitions.AddUnique(Transition);
}

void FSMState_Base::AddIncomingTransition(FSMTransition* Transition)
{
	IncomingTransitions.AddUnique(Transition);
}

void FSMState_Base::InitializeTransitions()
{
	ExecuteInitializeNodes();
	
	TArray<FSMTransition*> AllTransitions;
	GetAllTransitionChains(AllTransitions);
	
	for (FSMTransition* Transition : AllTransitions)
	{
		Transition->ExecuteInitializeNodes();
	}
}

void FSMState_Base::ShutdownTransitions()
{
	TArray<FSMTransition*> AllTransitions;
	GetAllTransitionChains(AllTransitions);

	for (FSMTransition* Transition : AllTransitions)
	{
		Transition->ExecuteShutdownNodes();
	}

	ExecuteShutdownNodes();
}

void FSMState_Base::NotifyInstanceStateHasStarted()
{
	if (USMInstance* Instance = GetOwningInstance())
	{
		Instance->NotifyStateStarted(*this);
	}
}

void FSMState_Base::FirePreStartEvents()
{
	if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(NodeInstance))
	{
		StateInstance->OnStateBeginEvent.Broadcast(StateInstance);
	}
}

void FSMState_Base::FirePostStartEvents()
{
	if (USMStateInstance_Base* StateInstance = Cast<USMStateInstance_Base>(NodeInstance))
	{
		StateInstance->OnPostStateBeginEvent.Broadcast(StateInstance);
	}
}


FSMState::FSMState() : Super()
{
}

void FSMState::Initialize(UObject* Instance)
{
	Super::Initialize(Instance);
}

void FSMState::InitializeGraphFunctions()
{
	FSMState_Base::InitializeGraphFunctions();
	USMUtils::InitializeGraphFunctions(BeginStateGraphEvaluator, OwningInstance, GetNodeInstance());
	USMUtils::InitializeGraphFunctions(UpdateStateGraphEvaluator, OwningInstance, GetNodeInstance());
	USMUtils::InitializeGraphFunctions(EndStateGraphEvaluator, OwningInstance, GetNodeInstance());
}

void FSMState::Reset()
{
	Super::Reset();
	USMUtils::ResetGraphFunctions(BeginStateGraphEvaluator);
	USMUtils::ResetGraphFunctions(UpdateStateGraphEvaluator);
	USMUtils::ResetGraphFunctions(EndStateGraphEvaluator);
}

void FSMState::ExecuteInitializeNodes()
{
	if (IsInitializedForRun())
	{
		return;
	}
	
	Super::ExecuteInitializeNodes();
}

void FSMState::ExecuteShutdownNodes()
{
	Super::ExecuteShutdownNodes();
}

bool FSMState::StartState()
{
	if (!Super::StartState())
	{
		return false;
	}

	if (CanExecuteLogic())
	{
		PrepareGraphExecution();
		USMUtils::ExecuteGraphFunctions(BeginStateGraphEvaluator);
	}

	FirePostStartEvents();

	return true;
}

bool FSMState::UpdateState(float DeltaSeconds)
{
	if (!Super::UpdateState(DeltaSeconds))
	{
		return false;
	}

	if (CanExecuteLogic())
	{
		USMUtils::ExecuteGraphFunctions(UpdateStateGraphEvaluator, (void*)&DeltaSeconds);
	}

	return true;
}

bool FSMState::EndState(float DeltaSeconds, const FSMTransition* TransitionToTake)
{
	if (!Super::EndState(DeltaSeconds, TransitionToTake))
	{
		return false;
	}

	if (CanExecuteLogic())
	{
		bIsStateEnding = true;
		USMUtils::ExecuteGraphFunctions(EndStateGraphEvaluator);
		bIsStateEnding = false;
	}

	ShutdownTransitions();

	return true;
}

void FSMState::OnStartedByInstance(USMInstance* Instance)
{
	Super::OnStartedByInstance(Instance);
}

void FSMState::OnStoppedByInstance(USMInstance* Instance)
{
	Super::OnStoppedByInstance(Instance);
}
