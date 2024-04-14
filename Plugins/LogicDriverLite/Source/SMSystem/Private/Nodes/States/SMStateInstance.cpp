// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMStateInstance.h"
#include "SMInstance.h"
#include "SMState.h"
#include "SMLogging.h"
#include "SMStateMachine.h"
#include "SMTransitionInstance.h"
#include "SMUtils.h"
#if WITH_EDITORONLY_DATA
#include "Engine/BlueprintGeneratedClass.h"
#endif

USMStateInstance_Base::USMStateInstance_Base() : Super()
{
#if WITH_EDITORONLY_DATA
	// TODO: Read editor settings.
	NodeEndStateColor = FLinearColor(1.f, 1.f, 1.f, 0.7f);
#endif
}

bool USMStateInstance_Base::IsInEndState() const
{
	if (FSMState_Base* State = (FSMState_Base*)GetOwningNode())
	{
		return State->IsInEndState();
	}

	return false;
}

void USMStateInstance_Base::GetStateInfo(FSMStateInfo& State) const
{
	if (FSMState_Base* StateNode = (FSMState_Base*)GetOwningNode())
	{
		State = FSMStateInfo(*StateNode);
	}
	else
	{
		State = FSMStateInfo();
	}
}

bool USMStateInstance_Base::IsStateMachine() const
{
	if (FSMState_Base* State = (FSMState_Base*)GetOwningNode())
	{
		return State->IsStateMachine();
	}

	return false;
}

bool USMStateInstance_Base::IsEntryState() const
{
	if (FSMState_Base* State = (FSMState_Base*)GetOwningNode())
	{
		return State->bIsRootNode;
	}

	return false;
}

void USMStateInstance_Base::SetActive(bool bValue, bool bSetAllParents, bool bActivateNow)
{
	USMUtils::ActivateStateNetOrLocal(GetOwningNodeAs<FSMState_Base>(), bValue, bSetAllParents, bActivateNow);
}

void USMStateInstance_Base::EvaluateTransitions()
{
	if (USMInstance* StateMachineInstance = GetStateMachineInstance(true))
	{
		StateMachineInstance->EvaluateTransitions();
	}
}

bool USMStateInstance_Base::GetOutgoingTransitions(TArray<USMTransitionInstance*>& Transitions, bool bExcludeAlwaysFalse) const
{
	Transitions.Reset();

	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNodeContainer())
	{
		for (FSMTransition* Transition : Node->GetOutgoingTransitions())
		{
			if (Transition->bAlwaysFalse && bExcludeAlwaysFalse)
			{
				continue;
			}
			if (USMTransitionInstance* TransitionInstance = Cast<USMTransitionInstance>(Transition->GetOrCreateNodeInstance()))
			{
				Transitions.Add(TransitionInstance);
			}
		}
	}

	return Transitions.Num() > 0;
}

bool USMStateInstance_Base::GetIncomingTransitions(TArray<USMTransitionInstance*>& Transitions,
	bool bExcludeAlwaysFalse) const
{
	Transitions.Reset();

	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNodeContainer())
	{
		for (FSMTransition* Transition : Node->GetIncomingTransitions())
		{
			if (Transition->bAlwaysFalse && bExcludeAlwaysFalse)
			{
				continue;
			}
			if (USMTransitionInstance* TransitionInstance = Cast<USMTransitionInstance>(Transition->GetOrCreateNodeInstance()))
			{
				Transitions.Add(TransitionInstance);
			}
		}
	}

	return Transitions.Num() > 0;
}

USMTransitionInstance* USMStateInstance_Base::GetTransitionToTake() const
{
	if (FSMState_Base* State = (FSMState_Base*)GetOwningNodeContainer())
	{
		if (const FSMTransition* Transition = State->GetTransitionToTake())
		{
			return Cast<USMTransitionInstance>(const_cast<FSMTransition*>(Transition)->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

bool USMStateInstance_Base::SwitchToLinkedState(USMStateInstance_Base* NextStateInstance, bool bRequireTransitionToPass, bool bActivateNow)
{
	if (const FSMState_Base* Node = GetOwningNodeAs<FSMState_Base>())
	{
		if (!Node->IsActive())
		{
			LD_LOG_WARNING(TEXT("Attempted to switch to linked state %s but this node %s is not currently active."), *NextStateInstance->GetName(), *Node->GetNodeName());
			return false;
		}

		// Find the state in the available transitions.
		for (FSMTransition* Transition : Node->GetOutgoingTransitions())
		{
			if (NextStateInstance == Transition->GetToState()->GetNodeInstance())
			{
				return SwitchToLinkedStateByTransition_Internal(Transition, bRequireTransitionToPass, bActivateNow);
			}
		}

		LD_LOG_WARNING(TEXT("Attempted to switch to linked state %s from %s but the node could not be found."), *NextStateInstance->GetName(), *Node->GetNodeName());
	}

	return false;
}

bool USMStateInstance_Base::SwitchToLinkedStateByName(const FString& NextStateName, bool bRequireTransitionToPass, bool bActivateNow)
{
	if (USMStateInstance_Base* NextState = GetNextStateByName(NextStateName))
	{
		return SwitchToLinkedState(NextState, bRequireTransitionToPass, bActivateNow);
	}

	return false;
}

bool USMStateInstance_Base::SwitchToLinkedStateByTransition(USMTransitionInstance* TransitionInstance,
	bool bRequireTransitionToPass, bool bActivateNow)
{
	if (TransitionInstance != nullptr)
	{
		if (TransitionInstance->GetPreviousStateInstance() != this)
		{
			LD_LOG_WARNING(TEXT("Attempted to switch to linked state by transition %s from state %s but this transition is from state %s."),
				*TransitionInstance->GetNodeName(), *GetNodeName(), *TransitionInstance->GetPreviousStateInstance()->GetNodeName());
			return false;
		}
		return SwitchToLinkedStateByTransition_Internal(TransitionInstance->GetOwningNodeAs<FSMTransition>(), bRequireTransitionToPass, bActivateNow);
	}

	return false;
}

bool USMStateInstance_Base::SwitchToLinkedStateByTransition_Internal(FSMTransition* Transition,
	bool bRequireTransitionToPass, bool bActivateNow)
{
	check(Transition);
	if (FSMState_Base* Node = GetOwningNodeAs<FSMState_Base>())
	{
		if (!Node->IsActive())
		{
			LD_LOG_WARNING(TEXT("Attempted to switch to linked state by transition %s but this state %s is not currently active."),
				*Transition->GetNodeName(), *Node->GetNodeName());
			return false;
		}
		
		if (bRequireTransitionToPass && !Transition->DoesTransitionPass())
		{
			return false;
		}

		// Notify the owning state machine to take this transition.
		FSMStateMachine* StateMachineNode = static_cast<FSMStateMachine*>(Node->GetOwnerNode());
		if (StateMachineNode->CanProcessExternalTransition())
		{
			FSMState_Base* DestinationState = Transition->GetToState();
			
			if (StateMachineNode->ProcessTransition(Transition, Node,
				DestinationState, nullptr, 0.f))
			{
				if (bActivateNow)
				{
					// This branch can't be true if owner doesn't have state change authority.
					StateMachineNode->TryStartState(DestinationState);
				}
			}
			return true;
		}
	}

	return false;
}

USMTransitionInstance* USMStateInstance_Base::GetTransitionByIndex(int32 Index) const
{
	TArray<USMTransitionInstance*> Transitions;
	if (GetOutgoingTransitions(Transitions, false))
	{
		if (Index >= 0 && Index < Transitions.Num())
		{
			return Transitions[Index];
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMStateInstance_Base::GetNextStateByTransitionIndex(int32 Index) const
{
	USMTransitionInstance* FoundTransition = GetTransitionByIndex(Index);
	return FoundTransition ? FoundTransition->GetNextStateInstance() : nullptr;
}

USMStateInstance_Base* USMStateInstance_Base::GetNextStateByName(const FString& StateName) const
{
	if (USMStateMachineInstance* OwningStateMachineInstance = GetOwningStateMachineNodeInstance())
	{
		// Search for a state in the same FSM scope.
		if (USMStateInstance_Base* NeighborState = OwningStateMachineInstance->GetContainedStateByName(StateName))
		{
			TArray<USMTransitionInstance*> OutgoingTransitions;
			GetOutgoingTransitions(OutgoingTransitions, false);

			// Check if any of this state's outgoing transitions connects to the state in question.
			if (OutgoingTransitions.ContainsByPredicate([NeighborState](USMTransitionInstance* Transition)
			{
				return Transition->GetNextStateInstance() == NeighborState;
			}))
			{
				return NeighborState;
			}
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMStateInstance_Base::GetPreviousStateByName(const FString& StateName) const
{
	if (USMStateMachineInstance* OwningStateMachineInstance = GetOwningStateMachineNodeInstance())
	{
		// Search for a state in the same FSM scope.
		if (USMStateInstance_Base* NeighborState = OwningStateMachineInstance->GetContainedStateByName(StateName))
		{
			TArray<USMTransitionInstance*> IncomingTransitions;
			GetIncomingTransitions(IncomingTransitions, false);

			// Check if any of this state's incoming transitions connects to the state in question.
			if (IncomingTransitions.ContainsByPredicate([NeighborState](USMTransitionInstance* Transition)
			{
				return Transition->GetPreviousStateInstance() == NeighborState;
			}))
			{
				return NeighborState;
			}
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMStateInstance_Base::GetPreviousActiveState() const
{
	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNode())
	{
		if (FSMState_Base* PreviousEnteredState = Node->GetPreviousActiveState())
		{
			return Cast<USMStateInstance_Base>(PreviousEnteredState->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

USMTransitionInstance* USMStateInstance_Base::GetPreviousActiveTransition() const
{
	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNode())
	{
		if (FSMTransition* PreviousEnteredTransition = Node->GetPreviousActiveTransition())
		{
			return Cast<USMTransitionInstance>(PreviousEnteredTransition->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

// Checks every transition for IsTransitionFromAnyState().
static bool AreAllTransitionsFromAnAnyState(const TArray<USMTransitionInstance*>& InTransitions)
{
	if (InTransitions.Num() == 0)
	{
		return false;
	}
	
	for (const USMTransitionInstance* Transition : InTransitions)
	{
		if (!Transition->IsTransitionFromAnyState())
		{
			return false;
		}
	}

	return true;
}

bool USMStateInstance_Base::AreAllOutgoingTransitionsFromAnAnyState() const
{
	TArray<USMTransitionInstance*> Transitions;
	GetOutgoingTransitions(Transitions);

	return AreAllTransitionsFromAnAnyState(MoveTemp(Transitions));
}

bool USMStateInstance_Base::AreAllIncomingTransitionsFromAnAnyState() const
{
	TArray<USMTransitionInstance*> Transitions;
	GetIncomingTransitions(Transitions);

	return AreAllTransitionsFromAnAnyState(MoveTemp(Transitions));
}

const FDateTime& USMStateInstance_Base::GetStartTime() const
{
	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNode())
	{
		return Node->GetStartTime();
	}

	static FDateTime EmptyDateTime(0);
	return EmptyDateTime;
}

float USMStateInstance_Base::GetServerTimeInState(bool& bOutUsedLocalTime) const
{
	if (const FSMState_Base* Node = (FSMState_Base*)GetOwningNode())
	{
		const float ServerTimeInState = Node->GetServerTimeInState();
		if (ServerTimeInState >= 0.f)
		{
			bOutUsedLocalTime = false;
			return ServerTimeInState;
		}
		
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
		const TScriptInterface<ISMStateMachineNetworkedInterface> NetworkedInterface = GetNetworkInterface();
		if (NetworkedInterface.GetObject())
		{
			if (NetworkedInterface->IsConfiguredForNetworking())
			{
				// TODO: Consider a logging option for this state class, and perhaps as a config setting.
				LD_LOG_INFO(TEXT("[%s::GetServerTimeInState] Could not establish an accurate server time, using local time."), *GetNodeName());
			}
		}
#endif
	}
	
	bOutUsedLocalTime = true;
	return GetTimeInState();
}

void USMStateInstance_Base::GetAllNodesOfType(TArray<USMNodeInstance*>& OutNodes, TSubclassOf<USMNodeInstance> NodeClass, bool bIncludeChildren,
                                              const TArray<UClass*>& StopIfTypeIsNot) const
{
	// If true then the node cycles back to itself at some point.
	if (OutNodes.Contains(this))
	{
		return;
	}

	// Only count if this node is of the right type.
	if ((bIncludeChildren && GetClass()->IsChildOf(NodeClass)) || GetClass() == NodeClass)
	{
		OutNodes.Add(const_cast<USMStateInstance_Base*>(this));
	}

	// Look for all connected nodes.
	if (FSMState_Base* Node = (FSMState_Base*)GetOwningNode())
	{
		for (FSMTransition* Transition : Node->GetOutgoingTransitions())
		{
			FSMState_Base* NextState = Transition->GetToState();
			if (USMStateInstance_Base* Instance = Cast<USMStateInstance_Base>(NextState->GetOrCreateNodeInstance()))
			{
				// We break the search when a forbidden type is hit.
				if (StopIfTypeIsNot.Num() > 0)
				{
					bool bAllowed = false;
					for (UClass* Class : StopIfTypeIsNot)
					{
						if (Instance->GetClass()->IsChildOf(Class))
						{
							bAllowed = true;
							break;
						}
					}

					if (!bAllowed)
					{
						continue;
					}
				}

				Instance->GetAllNodesOfType(OutNodes, NodeClass, bIncludeChildren, StopIfTypeIsNot);
			}
		}
	}
}

bool USMStateInstance_Base::GetAlwaysUpdate() const
{
	GET_NODE_DEFAULT_VALUE(FSMState_Base, bAlwaysUpdate);
}

void USMStateInstance_Base::SetAlwaysUpdate(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMState_Base, bAlwaysUpdate, bValue);
}

bool USMStateInstance_Base::GetDisableTickTransitionEvaluation() const
{
	GET_NODE_DEFAULT_VALUE(FSMState_Base, bDisableTickTransitionEvaluation);
}

void USMStateInstance_Base::SetDisableTickTransitionEvaluation(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMState_Base, bDisableTickTransitionEvaluation, bValue);
}

bool USMStateInstance_Base::GetEvalTransitionsOnStart() const
{
	GET_NODE_DEFAULT_VALUE(FSMState_Base, bEvalTransitionsOnStart);
}

void USMStateInstance_Base::SetEvalTransitionsOnStart(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMState_Base, bEvalTransitionsOnStart, bValue);
}

void USMStateInstance_Base::SetExcludeFromAnyState(const bool bValue)
{
	bExcludeFromAnyState = bValue;
}

USMStateInstance::USMStateInstance() : Super()
{
}
