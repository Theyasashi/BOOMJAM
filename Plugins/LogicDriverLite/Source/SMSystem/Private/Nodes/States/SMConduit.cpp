// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMConduit.h"
#include "SMConduitInstance.h"
#include "SMUtils.h"

FSMConduit::FSMConduit() : Super(), bCanEnterTransition(false), bCanEvaluate(true), bEvalWithTransitions(false),
                           ConditionalEvaluationType(),
                           bIsEvaluating(false), bCheckedForTransitions(false)
{
}

void FSMConduit::Initialize(UObject* Instance)
{
	Super::Initialize(Instance);
}

void FSMConduit::InitializeGraphFunctions()
{
	FSMState_Base::InitializeGraphFunctions();

	USMUtils::InitializeGraphFunctions(CanEnterConduitGraphEvaluator, OwningInstance, GetNodeInstance());
	USMUtils::InitializeGraphFunctions(ConduitEnteredGraphEvaluator, OwningInstance, GetNodeInstance());
}

void FSMConduit::Reset()
{
	Super::Reset();
	USMUtils::ResetGraphFunctions(CanEnterConduitGraphEvaluator);
	USMUtils::ResetGraphFunctions(ConduitEnteredGraphEvaluator);
}

void FSMConduit::ExecuteInitializeNodes()
{
	if (IsInitializedForRun())
	{
		return;
	}
	
	Super::ExecuteInitializeNodes();
}

void FSMConduit::ExecuteShutdownNodes()
{
	Super::ExecuteShutdownNodes();
}

bool FSMConduit::IsNodeInstanceClassCompatible(UClass* NewNodeInstanceClass) const
{
	return NewNodeInstanceClass && NewNodeInstanceClass->IsChildOf<USMConduitInstance>();
}

UClass* FSMConduit::GetDefaultNodeInstanceClass() const
{
	return USMConduitInstance::StaticClass();
}

bool FSMConduit::StartState()
{
	const bool bResult = Super::StartState();

	USMUtils::ExecuteGraphFunctions(ConduitEnteredGraphEvaluator);

	FirePostStartEvents();

	return bResult;
}

bool FSMConduit::UpdateState(float DeltaSeconds)
{
	const bool bResult = Super::UpdateState(DeltaSeconds);

	return bResult;
}

bool FSMConduit::EndState(float DeltaSeconds, const FSMTransition* TransitionToTake)
{
	const bool bResult = Super::EndState(DeltaSeconds, TransitionToTake);
	ShutdownTransitions();
	return bResult;
}

bool FSMConduit::GetValidTransition(TArray<TArray<FSMTransition*>>& Transitions)
{
	if (bCheckedForTransitions || !bCanEvaluate)
	{
		return false;
	}

	bIsEvaluating = true;
#if WITH_EDITORONLY_DATA
	bWasEvaluating = true; // Will be set to false from the editor.
#endif
	
	// First check that the conduit passes.
	PrepareGraphExecution();
	
	if (ConditionalEvaluationType == ESMConditionalEvaluationType::SM_AlwaysTrue)
	{
		// Skip BP graph eval if not needed.
		bCanEnterTransition = true;
	}
	else
	{
		PrepareGraphExecution();
		USMUtils::ExecuteGraphFunctions(CanEnterConduitGraphEvaluator);
	}

	bIsEvaluating = false;
	
	if (!bCanEnterTransition)
	{
		return false;
	}

	bCheckedForTransitions = true;
	
	// Passes, find the best transition.
	const bool bResult = Super::GetValidTransition(Transitions);
	
	bCheckedForTransitions = false;
	return bResult;
}

void FSMConduit::EnterConduitWithTransition()
{
	if (IsConfiguredAsTransition())
	{
		SetActive(true);
		USMUtils::ExecuteGraphFunctions(ConduitEnteredGraphEvaluator);
		SetActive(false);
	}
}
