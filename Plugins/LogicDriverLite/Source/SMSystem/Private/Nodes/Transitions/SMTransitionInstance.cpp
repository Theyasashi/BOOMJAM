// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTransitionInstance.h"
#include "SMInstance.h"
#include "SMStateInstance.h"
#include "SMTransition.h"

USMTransitionInstance::USMTransitionInstance() : Super(), PriorityOrder(0),
bCanEvaluate(true), bCanEvaluateFromEvent(true),
bCanEvalWithStartState(true)
{
}

USMStateInstance_Base* USMTransitionInstance::GetPreviousStateInstance() const
{
	if (FSMTransition* Transition = (FSMTransition*)GetOwningNode())
	{
		if (FSMState_Base* PrevState = Transition->GetFromState())
		{
			return Cast<USMStateInstance_Base>(PrevState->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMTransitionInstance::GetNextStateInstance() const
{
	if (FSMTransition* Transition = (FSMTransition*)GetOwningNode())
	{
		if (FSMState_Base* NextState = Transition->GetToState())
		{
			return Cast<USMStateInstance_Base>(NextState->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMTransitionInstance::GetSourceStateForActiveTransition() const
{
	if (FSMTransition* Transition = (FSMTransition*)GetOwningNode())
	{
		if (Transition->SourceState)
		{
			return Cast<USMStateInstance_Base>(Transition->SourceState->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

USMStateInstance_Base* USMTransitionInstance::GetDestinationStateForActiveTransition() const
{
	if (FSMTransition* Transition = (FSMTransition*)GetOwningNode())
	{
		if (Transition->DestinationState)
		{
			return Cast<USMStateInstance_Base>(Transition->DestinationState->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

void USMTransitionInstance::GetTransitionInfo(FSMTransitionInfo& Transition) const
{
	if (FSMTransition* TransitionNode = (FSMTransition*)GetOwningNode())
	{
		Transition = FSMTransitionInfo(*TransitionNode);
	}
	else
	{
		Transition = FSMTransitionInfo();
	}
}

const FDateTime& USMTransitionInstance::GetServerTimestamp() const
{
	if (FSMTransition* TransitionNode = (FSMTransition*)GetOwningNode())
	{
		return TransitionNode->LastNetworkTimestamp;
	}

	static FDateTime EmptyTimestamp(0);
	return EmptyTimestamp;
}

bool USMTransitionInstance::DoesTransitionPass() const
{
	if (FSMTransition* TransitionNode = (FSMTransition*)GetOwningNode())
	{
		return TransitionNode->DoesTransitionPass();
	}

	return false;
}

bool USMTransitionInstance::IsTransitionFromAnyState() const
{
	GET_NODE_STRUCT_VALUE(FSMTransition, bFromAnyState);
	return false;
}

void USMTransitionInstance::EvaluateFromManuallyBoundEvent()
{
	const bool bOriginalEvalValue = GetCanEvaluate();
	SetCanEvaluate(true);
	USMInstance* OwningStateMachine = GetStateMachineInstance(true);
	if (OwningStateMachine)
	{
		OwningStateMachine->EvaluateAndTakeTransitionChain(this);
	}
	SetCanEvaluate(bOriginalEvalValue);
}

void USMTransitionInstance::SetCanEvaluate(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvaluate, bValue);
}

bool USMTransitionInstance::GetCanEvaluate() const
{
	GET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvaluate);
}

int32 USMTransitionInstance::GetPriorityOrder() const
{
	GET_NODE_DEFAULT_VALUE_DIF_VAR(FSMTransition, PriorityOrder, Priority);
}

void USMTransitionInstance::SetPriorityOrder(const int32 Value)
{
	SET_NODE_DEFAULT_VALUE_DIF_VAR(FSMTransition, PriorityOrder, Priority, Value);
}

bool USMTransitionInstance::GetCanEvaluateFromEvent() const
{
	GET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvaluateFromEvent);
}

void USMTransitionInstance::SetCanEvaluateFromEvent(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvaluateFromEvent, bValue);
}

bool USMTransitionInstance::GetCanEvalWithStartState() const
{
	GET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvalWithStartState);
}

void USMTransitionInstance::SetCanEvalWithStartState(const bool bValue)
{
	SET_NODE_DEFAULT_VALUE(FSMTransition, bCanEvalWithStartState, bValue);
}
