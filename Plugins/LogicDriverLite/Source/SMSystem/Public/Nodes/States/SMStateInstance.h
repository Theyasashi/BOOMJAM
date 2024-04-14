// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "SMNodeInstance.h"
#include "SMNode_Info.h"

#include "SMStateInstance.generated.h"

class USMTransitionInstance;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateBeginSignature, class USMStateInstance_Base*, StateInstance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStateUpdateSignature, class USMStateInstance_Base*, StateInstance, float, DeltaSeconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateEndSignature, class USMStateInstance_Base*, StateInstance);

/**
 * The abstract base class for all state type nodes including state machine nodes and conduits.
 */
UCLASS(Abstract, NotBlueprintable, BlueprintType, classGroup = LogicDriver, hideCategories = (SMStateInstance_Base), meta = (DisplayName = "State Class Base"))
class SMSYSTEM_API USMStateInstance_Base : public USMNodeInstance
{
	GENERATED_BODY()

public:
	USMStateInstance_Base();
	
	// USMNodeInstance
	/** If this state is an end state. */
	virtual bool IsInEndState() const override;
	// ~USMNodeInstance
	
	/** Return read only information about the owning state. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void GetStateInfo(FSMStateInfo& State) const;
	
	/** Checks if this state is a state machine. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool IsStateMachine() const;

	/** If this state is an entry state within a state machine. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool IsEntryState() const;
	
	/**
	 * Force set the active flag of this state. This call is replicated and can be called from the server or from a client.
	 * The caller must have state change authority.
	 *
	 * When calling from a state, it should be done either OnStateBegin or OnStateUpdate. When calling from a transition
	 * it should be done from OnTransitionEntered and limited to the previous state. If this is called from other
	 * state or transition methods it may cause issues with the normal update cycle of a state machine.
	 * 
	 * @param bValue True activates the state, false deactivates the state.
	 * @param bSetAllParents Sets the active state of all super state machines. A parent state machine won't be deactivated unless there are no other states active.
	 * @param bActivateNow If the state is becoming active it will fully activate and run OnStateBegin this tick. If this is false it will do so on the next update cycle.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void SetActive(bool bValue, bool bSetAllParents = false, bool bActivateNow = true);
	
	/**
	 * Signals to the owning state machine to process transition evaluation.
	 * This is similar to calling Update on the owner root state machine, however state update logic (Tick) won't execute.
	 * All transitions are evaluated as normal starting from the root state machine down.
	 * Depending on super state transitions it's possible the state machine this state is part of may exit.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void EvaluateTransitions();
	
	/**
	 * Return all outgoing transition instances.
	 * @param Transitions The outgoing transitions.
	 * @param bExcludeAlwaysFalse Skip over transitions that can't ever be true.
	 * @return True if any transitions exist.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool GetOutgoingTransitions(TArray<USMTransitionInstance*>& Transitions, bool bExcludeAlwaysFalse = true) const;

	/**
	 * Return all incoming transition instances.
	 * @param Transitions The incoming transitions.
	 * @param bExcludeAlwaysFalse Skip over transitions that can't ever be true.
	 * @return True if any transitions exist.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool GetIncomingTransitions(TArray<USMTransitionInstance*>& Transitions, bool bExcludeAlwaysFalse = true) const;
	
	/** The transition this state will be taking. Generally only valid on EndState and if this state isn't an end state. May be null. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMTransitionInstance* GetTransitionToTake() const;

	/**
	 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.
	 *
	 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause
	 * issues with the normal update cycle of a state machine.
	 * 
	 * @param NextStateInstance The state node instance to switch to.
	 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.
	 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.
	 *
	 * @return True if the active state was switched.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool SwitchToLinkedState(USMStateInstance_Base* NextStateInstance, bool bRequireTransitionToPass = true, bool bActivateNow = true);

	/**
	 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.
	 *
	 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause
	 * issues with the normal update cycle of a state machine.
	 * 
	 * @param NextStateName The name of the state to switch to.
	 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.
	 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.
	 *
	 * @return True if the active state was switched.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool SwitchToLinkedStateByName(const FString& NextStateName, bool bRequireTransitionToPass = true, bool bActivateNow = true);

	/**
	 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.
	 *
	 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause
	 * issues with the normal update cycle of a state machine.
	 * 
	 * @param TransitionInstance The transition which should be taken to the next state.
	 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.
	 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.
	 *
	 * @return True if the active state was switched.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool SwitchToLinkedStateByTransition(USMTransitionInstance* TransitionInstance, bool bRequireTransitionToPass = true, bool bActivateNow = true);

private:
	bool SwitchToLinkedStateByTransition_Internal(FSMTransition* Transition, bool bRequireTransitionToPass = true, bool bActivateNow = true);
	
public:
	/**
	 * Return a transition given the transition index.
	 * @param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.
	 *
	 * @return The transition or nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMTransitionInstance* GetTransitionByIndex(int32 Index) const;
	
	/**
	 * Return the next connected state given a transition index.
	 * @param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.
	 *
	 * @return The connected state or nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetNextStateByTransitionIndex(int32 Index) const;

	/**
	 * Return the next state connected by an outgoing transition.
	 * O(n) by number of transitions.
	 * @param StateName Name of the state to search for.
	 *
	 * @return The connected state or nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetNextStateByName(const FString& StateName) const;

	/**
	 * Return a previous state connected through an incoming transition.
	 * O(n) by number of transitions.
	 * @param StateName Name of the state to search for.
	 *
	 * @return The connected state or nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetPreviousStateByName(const FString& StateName) const;
	
	/**
	 * Retrieve the last active state that transitioned to this state.
	 * This will not count transition conduits.
	 *
	 * @return The state instance last active before this state became active. May be nullptr.
	 * 
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMStateInstance_Base* GetPreviousActiveState() const;

	/**
	 * Retrieve the last transition taken to this state.
	 *
	 * @return The transition instance last active before this state became active. May be nullptr.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	USMTransitionInstance* GetPreviousActiveTransition() const;

	/** Checks if every outgoing transition was created by an Any State. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool AreAllOutgoingTransitionsFromAnAnyState() const;

	/** Checks if every incoming transition was created by an Any State. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool AreAllIncomingTransitionsFromAnAnyState() const;
	
	/**
	 * Retrieve the UTC time when the state last started. If this is called before the state has started once,
	 * or before initialization (such as during an editor construction script) the datetime will be initialized to 0.
	 *
	 * @return DateTime in UTC. This is when the state started locally and won't be in sync with the server.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	const FDateTime& GetStartTime() const;

	/**
	 * Retrieve the time the server spent in the state. This is retrieved from network transactions
	 * and can match the TimeInState from the server.
	 *
	 * This will only match the server after OnStateEnd() is called and provided the client received the replicated
	 * transition. When using client state change authority, `bWaitForTransactionsFromServer` must be set to true
	 * for the client to receive the updated server time.
	 *
	 * When the server time can't be calculated the local time will be returned instead, using GetTimeInState().
	 *
	 * The return value is impacted by bCalculateServerTimeForClients of the state machine component's network settings,
	 * and whether the state machine is networked, a client or server, or is ticking.
	 *
	 * @param bOutUsedLocalTime [Out] Indicates that local time from GetTimeInState() was used.
	 * @return The total time spent in the state, either matching the server or the current local time spent.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	float GetServerTimeInState(UPARAM(DisplayName="UsedLocalTime") bool& bOutUsedLocalTime) const;

	/**
	 * Recursively search connected nodes for nodes matching the given type.
	 * @param OutNodes All found nodes.
	 * @param NodeClass The class type to search for.
	 * @param bIncludeChildren Include children of type NodeClass or require an exact match.
	 * @param StopIfTypeIsNot The search is broken when a node's type is not found in this list. Leave empty to never break the search.
	 */
	void GetAllNodesOfType(TArray<USMNodeInstance*>& OutNodes, TSubclassOf<USMNodeInstance> NodeClass, bool bIncludeChildren = true, const TArray<UClass*>& StopIfTypeIsNot = TArray<UClass*>()) const;

protected:
#if WITH_EDITORONLY_DATA
public:
	const FLinearColor& GetEndStateColor() const { return NodeEndStateColor; }
	
protected:
	/** The color this node should be when it is an end state. */
	UPROPERTY()
	FLinearColor NodeEndStateColor;

#endif

public:
	/** Public getter for #bAlwaysUpdate. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetAlwaysUpdate() const;
	/** Public setter for #bAlwaysUpdate. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetAlwaysUpdate(const bool bValue);

	/** Public getter for #bDisableTickTransitionEvaluation. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetDisableTickTransitionEvaluation() const;
	/** Public setter for #bDisableTickTransitionEvaluation. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetDisableTickTransitionEvaluation(const bool bValue);

	/** Public setter for #bEvalTransitionsOnStart. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetEvalTransitionsOnStart() const;
	/** Public setter for #bEvalTransitionsOnStart. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetEvalTransitionsOnStart(const bool bValue);

	/** Public getter for #bExcludeFromAnyState. Only valid for the editor. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetExcludeFromAnyState() const { return bExcludeFromAnyState; }
	/**
	 * Public setter for #bExcludeFromAnyState.
	 * Only valid from the editor construction script.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetExcludeFromAnyState(const bool bValue);
private:
	friend class USMGraphNode_StateNodeBase;
	
	/**
	 * Always update the state at least once before ending.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "State", meta = (NodeBaseOnly))
	bool bAlwaysUpdate;

	/**
	 * Prevents conditional transitions for this state from being evaluated on Tick.
	 * This is good to use if the transitions leading out of the state are event based
	 * or if you are manually calling EvaluateTransitions from a state instance.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "State", meta = (NodeBaseOnly))
	bool bDisableTickTransitionEvaluation;

	/**
	 * Allows transitions to be evaluated in the same tick as Start State.
	 * Normally transitions are evaluated on the second tick.
	 * This can be chained with other nodes that have this checked making it
	   possible to evaluate multiple nodes and transitions in a single tick.
	 
	 * When using this consider performance implications and any potential
	   infinite loops such as if you are using a self transition on this state.

	 * Individual transitions can modify this behavior with bCanEvalWithStartState.
	 */
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category = "State", meta = (NodeBaseOnly))
	bool bEvalTransitionsOnStart;

	/**
	 * Prevents the `Any State` node from adding transitions to this node.
	 * This can be useful for maintaining end states.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Any State", meta = (NodeBaseOnly))
	uint16 bExcludeFromAnyState: 1;

public:
	/**
	 * Called right before the state has started. This is meant for an observer to be aware of when a state is about
	 * to start. This will only be called for state stack instances if the state is allowed to execute logic.
	 * Do not change states from within this event, the state change process will still be in progress.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Logic Driver|Node Instance")
	FOnStateBeginSignature OnStateBeginEvent;

	/**
	 * Called right after the state has started. This is meant for an observer to be aware of when a state has started.
	 * If you need to change states this event is safer to use, but ideally state changes should be managed by transitions
	 * or from within the state.
	 *
	 * This will only be called for state stack instances if the state is allowed to execute logic, and will be called before
	 * the primary instance's OnPostStateBeginEvent. It is not safe to change states from this event when broadcast from
	 * a state stack instance.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Logic Driver|Node Instance")
	FOnStateBeginSignature OnPostStateBeginEvent;

	/**
	 * Called before the state has updated. This is meant for an observer to be aware of when a state is updating
	 * and it is not advised to switch states from this event.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Logic Driver|Node Instance")
	FOnStateUpdateSignature OnStateUpdateEvent;

	/**
	 * Called before the state has ended. It is not advised to switch states during this event.
	 * The state machine will already be in the process of switching states.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Logic Driver|Node Instance")
	FOnStateEndSignature OnStateEndEvent;
};

/**
 * The base class for state nodes. This is where most execution logic should be defined.
 */
UCLASS(NotBlueprintable, BlueprintType, classGroup = LogicDriver, hideCategories = (SMStateInstance), meta = (DisplayName = "State Class"))
class SMSYSTEM_API USMStateInstance : public USMStateInstance_Base
{
	GENERATED_BODY()

public:
	USMStateInstance();

};
