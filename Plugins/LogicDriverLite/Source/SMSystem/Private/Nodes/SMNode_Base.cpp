// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMNode_Base.h"
#include "SMUtils.h"
#include "SMLogging.h"
#include "SMNodeInstance.h"
#include "SMRuntimeSettings.h"


FSMNode_Base::FSMNode_Base() : TimeInState(0), bIsInEndState(false), bHasUpdated(false), DuplicateId(0),
                               OwnerNode(nullptr),
                               OwningInstance(nullptr), NodeInstance(nullptr), NodeInstanceClass(nullptr),
                               ServerTimeInState(SM_ACTIVE_TIME_NOT_SET), bHaveGraphFunctionsInitialized(false), bIsInitializedForRun(0),
                               bIsActive(false)
{
	/*
	 * Originally the Guid was initialized here. This caused warnings to show up during packaging because
	 * Unreal does safety checks on struct native constructors by comparing multiple initializations with different
	 * addresses and verifying each property matches. That doesn't work with a Guid because it is guaranteed to
	 * be unique each time.
	 */
}

void FSMNode_Base::Initialize(UObject* Instance)
{
	OwningInstance = Cast<USMInstance>(Instance);
	CreateNodeInstance();
}

void FSMNode_Base::InitializeGraphFunctions()
{
	check(IsInGameThread());

	USMUtils::InitializeGraphFunctions(OnRootStateMachineStartedGraphEvaluator, OwningInstance, GetNodeInstance());
	USMUtils::InitializeGraphFunctions(OnRootStateMachineStoppedGraphEvaluator, OwningInstance, GetNodeInstance());
	
	USMUtils::InitializeGraphFunctions(TransitionInitializedGraphEvaluators, OwningInstance, GetNodeInstance());
	USMUtils::InitializeGraphFunctions(TransitionShutdownGraphEvaluators, OwningInstance, GetNodeInstance());
	
	bHaveGraphFunctionsInitialized = true;
}

void FSMNode_Base::Reset()
{
	USMUtils::ResetGraphFunctions(OnRootStateMachineStartedGraphEvaluator);
	USMUtils::ResetGraphFunctions(OnRootStateMachineStoppedGraphEvaluator);

	USMUtils::ResetGraphFunctions(TransitionInitializedGraphEvaluators);
	USMUtils::ResetGraphFunctions(TransitionShutdownGraphEvaluators);
}

void FSMNode_Base::OnStartedByInstance(USMInstance* Instance)
{
	USMUtils::ExecuteGraphFunctions(OnRootStateMachineStartedGraphEvaluator);
}

void FSMNode_Base::OnStoppedByInstance(USMInstance* Instance)
{
	USMUtils::ExecuteGraphFunctions(OnRootStateMachineStoppedGraphEvaluator);
}

const FGuid& FSMNode_Base::GetNodeGuid() const
{
	return Guid;
}

void FSMNode_Base::GenerateNewNodeGuid()
{
	SetNodeGuid(FGuid::NewGuid());
}

const FGuid& FSMNode_Base::GetGuid() const
{
	return PathGuid;
}

void FSMNode_Base::CalculatePathGuid(TMap<FString, int32>& InOutMappedPaths)
{
	USMUtils::PathToGuid(GetGuidPath(InOutMappedPaths), &PathGuid);
}

FString FSMNode_Base::GetGuidPath(TMap<FString, int32>& InOutMappedPaths) const
{
	TArray<const FSMNode_Base*> Owners;
	USMUtils::TryGetAllOwners(this, Owners);
	return USMUtils::BuildGuidPathFromNodes(Owners, &InOutMappedPaths);
}

FGuid FSMNode_Base::CalculatePathGuidConst() const
{
	TMap<FString, int32> PathToStateMachine;
	const FString Path = GetGuidPath(PathToStateMachine);
	return USMUtils::PathToGuid(Path);
}

void FSMNode_Base::GenerateNewNodeGuidIfNotSet()
{
	if (Guid.IsValid())
	{
		return;
	}

	GenerateNewNodeGuid();
}

void FSMNode_Base::SetNodeGuid(const FGuid& NewGuid)
{
	Guid = NewGuid;
}

void FSMNode_Base::SetOwnerNodeGuid(const FGuid& NewGuid)
{
	OwnerGuid = NewGuid;
}

void FSMNode_Base::SetOwnerNode(FSMNode_Base* Owner)
{
	OwnerNode = Owner;
}

void FSMNode_Base::CreateNodeInstance()
{
	if (!NodeInstanceClass)
	{
		SetNodeInstanceClass(GetDefaultNodeInstanceClass());

		check(NodeInstanceClass);
	}

	UObject* TemplateInstance = nullptr;
	if (TemplateName != NAME_None && OwningInstance)
	{
		TemplateInstance = USMUtils::FindTemplateFromInstance(OwningInstance, TemplateName);
		if (TemplateInstance == nullptr)
		{
			LD_LOG_ERROR(TEXT("Could not find node template %s for use on node %s from package %s. Loading defaults."), *TemplateName.ToString(), *GetNodeName(), *OwningInstance->GetName());
		}
	}

	if (TemplateInstance && TemplateInstance->GetClass() != NodeInstanceClass && TemplateInstance->GetClass()->GetName().StartsWith("REINST_"))
	{
		LD_LOG_ERROR(TEXT("Node class mismatch. Node %s has template class %s but is expecting %s. Try recompiling the blueprint %s."),
			*GetNodeName(), *TemplateInstance->GetClass()->GetName(), *NodeInstanceClass->GetName(), *OwningInstance->GetName());
		return;
	}
	if (!CanEverCreateNodeInstance() ||
		(IsUsingDefaultNodeClass() && !GetDefault<USMRuntimeSettings>()->bPreloadDefaultNodes))
	{
		// Default node instances are created on demand.
		return;
	}
	
	NodeInstance = NewObject<USMNodeInstance>(OwningInstance, NodeInstanceClass, NAME_None, RF_NoFlags, TemplateInstance);
	NodeInstance->SetOwningNode(this);
}

void FSMNode_Base::SetNodeInstanceClass(UClass* NewNodeInstanceClass)
{
	if (NewNodeInstanceClass && !IsNodeInstanceClassCompatible(NewNodeInstanceClass))
	{
		LD_LOG_ERROR(TEXT("Could not set node instance class %s on node %s. The types are not compatible."), *NewNodeInstanceClass->GetName(), *GetNodeName());
		return;
	}

	NodeInstanceClass = NewNodeInstanceClass;
}

bool FSMNode_Base::IsNodeInstanceClassCompatible(UClass* NewNodeInstanceClass) const
{
	ensureMsgf(false, TEXT("FSMNode_Base IsNodeInstanceClassCompatible hit for node %s and instance class %s. This should always be overidden in child classes."),
		*GetNodeName(), NewNodeInstanceClass ? *NewNodeInstanceClass->GetName() : TEXT("None"));
	return false;
}

USMNodeInstance* FSMNode_Base::GetOrCreateNodeInstance()
{
	if (!NodeInstance && CanEverCreateNodeInstance())
	{
		if (!HaveGraphFunctionsInitialized())
		{
			LD_LOG_ERROR(TEXT("GetOrCreateNodeInstance called on node %s before it has initialized."), *GetNodeName());
			return nullptr;
		}

		if (!NodeInstanceClass)
		{
			LD_LOG_ERROR(TEXT("GetOrCreateNodeInstance called on node %s with null NodeInstanceClass."), *GetNodeName());
			return nullptr;
		}
	
		NodeInstance = NewObject<USMNodeInstance>(OwningInstance, NodeInstanceClass, NAME_None, RF_NoFlags);
		NodeInstance->SetOwningNode(this);
	}
	
	return NodeInstance;
}

void FSMNode_Base::SetNodeName(const FString& Name)
{
	NodeName = Name;
}

void FSMNode_Base::SetTemplateName(const FName& Name)
{
	TemplateName = Name;
}

void FSMNode_Base::ExecuteInitializeNodes()
{
	if (IsInitializedForRun())
	{
		return;
	}
	
	USMUtils::ExecuteGraphFunctions(TransitionInitializedGraphEvaluators);
	bIsInitializedForRun = true;
}

void FSMNode_Base::ExecuteShutdownNodes()
{
	USMUtils::ExecuteGraphFunctions(TransitionShutdownGraphEvaluators);
	bIsInitializedForRun = false;
}

void FSMNode_Base::SetServerTimeInState(float InTime)
{
	ServerTimeInState = InTime;
}

void FSMNode_Base::PrepareGraphExecution()
{
	if (!HaveGraphFunctionsInitialized())
	{
		return;
	}

	UpdateReadStates();
}

void FSMNode_Base::SetActive(bool bValue)
{
#if WITH_EDITORONLY_DATA
	bWasActive = bIsActive;
#endif
	bIsActive = bValue;
}

