// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "SMNodeInstance.h"
#include "SMNode_Info.h"

#include "SMTransitionInstance.generated.h"

class USMStateInstance_Base;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTransitionEnteredSignature, class USMTransitionInstance*, TransitionInstance);

/**
 * The base class for transition connections.
 */
UCLASS(NotBlueprintable, BlueprintType, classGroup = LogicDriver, hideCategories = (SMTransitionInstance), meta = (DisplayName = "Transition Class"))
class SMSYSTEM_API USMTransitionInstance : public USMNodeInstance
{
	GENERATED_BODY()

public:
	USMTransitionInstance();

	/** The state this transition leaves from. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetPreviousStateInstance() const;

	/** The state this transition leads to. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetNextStateInstance() const;

	/**
	* Return the state that last triggered this transition.
	* This may be a state prior to a transition conduit.
	* This will be valid during OnTransitionEntered().
	*
	* @return The first state to trigger this transition chain or null.
	*/
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetSourceStateForActiveTransition() const;

	/**
	* Return the destination state we are transitioning to or last transitioned to.
	* This may be a state after a transition conduit.
	* This will be valid during OnTransitionEntered().
	*
	* @return The final state after the transition chain or null.
	*/
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetDestinationStateForActiveTransition() const;
	
	/** Return read only information about the owning transition. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void GetTransitionInfo(FSMTransitionInfo& Transition) const;

	/** Return the last server timestamp of this transition. If not networked this won't be set. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	const FDateTime& GetServerTimestamp() const;
	
	/**
	 * Evaluates the transition's local graph which usually calls #CanEnterTransition of this instance.
	 * This is equivalent to the state machine determining if a transition succeeds.
	 *
	 * This is best used from an external caller when checking a transition result.
	 *
	 * Do NOT call this from within CanEnterTransition of the instance or the local graph
	 * or you may trigger an infinite loop.
	 *
	 * @return The transition result.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool DoesTransitionPass() const;

	/**
	 * If the transition was created by an Any State.
	 * @return True if the transition was copied from an Any State.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool IsTransitionFromAnyState() const;

	/**
	 * Efficiently evaluate and take the transition immediately.
	 * If the transition's CanEnterTransition method returns true the entire transition
	 * chain this transition is part of will be evaluated and taken. Super state and parallel transitions
	 * will not evaluate when this method is called.
	 *
	 * Steps this method performs:
	 * 1. Enables SetCanEvaluate for this transition.
	 * 2. Calls EvaluateAndTakeTransitionChain from the owning state machine instance.
	 * 3. Sets SetCanEvaluate back to the original value.
	 * 
	 * Use at the end of execution from manually bound events.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void EvaluateFromManuallyBoundEvent();

	/** Sets whether this node is allowed to evaluate or not. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void SetCanEvaluate(const bool bValue);
	/** Check whether this transition is allowed to evaluate. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool GetCanEvaluate() const;
	
	/** Public getter for #PriorityOrder. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	int32 GetPriorityOrder() const;
	/**
	 * Public setter for #PriorityOrder.
	 * Only valid from the editor construction script.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetPriorityOrder(const int32 Value);

	/** Public getter for #bCanEvaluateFromEvent. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetCanEvaluateFromEvent() const;
	/** Public setter for #bCanEvaluateFromEvent. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetCanEvaluateFromEvent(const bool bValue);

	/** Public getter for #bCanEvalWithStartState. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetCanEvalWithStartState() const;
	/** Public setter for #bCanEvalWithStartState. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetCanEvalWithStartState(const bool bValue);
private:
	friend class USMGraphNode_TransitionEdge;
	
	/**
	 * Lower number transitions will be evaluated first.
	 */
	UPROPERTY(EditDefaultsOnly, Category = Transition, meta = (NodeBaseOnly))
	int32 PriorityOrder;

	/**
	 * If this transition is allowed to evaluate conditionally.
	 */
	UPROPERTY(EditDefaultsOnly, Category = Transition, meta=(DisplayName = "Can Evaluate Conditionally", NodeBaseOnly))
	bool bCanEvaluate;
	
	/** If this transition can evaluate from auto-bound events. */
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = Transition, meta = (NodeBaseOnly))
	bool bCanEvaluateFromEvent;
	
	/**
	 * Setting to false forces this transition to never evaluate on the same tick as Start State.
	 * Only checked if this transition's from state has bEvalTransitionsOnStart set to true.
	 */
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = Transition, meta = (NoResetToDefault, NodeBaseOnly))
	bool bCanEvalWithStartState;
	
public:
	/** Called when this transition has been entered from the previous state. */
	UPROPERTY(BlueprintAssignable, Category = "Logic Driver|Node Instance")
	FOnTransitionEnteredSignature OnTransitionEnteredEvent;
};