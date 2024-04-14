// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "SMStateInstance.h"

#include "SMConduitInstance.generated.h"

/**
 * The base class for conduit nodes.
 */
UCLASS(NotBlueprintable, BlueprintType, classGroup = LogicDriver, hideCategories = (SMConduitInstance), meta = (DisplayName = "Conduit Class"))
class SMSYSTEM_API USMConduitInstance : public USMStateInstance_Base
{
	GENERATED_BODY()

public:
	USMConduitInstance();

	/** Sets whether this node is allowed to evaluate or not. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	void SetCanEvaluate(const bool bValue);
	/** Check whether this node is allowed to evaluate. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool GetCanEvaluate() const;
	
	/** Public getter for #bEvalWithTransitions. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	bool GetEvalWithTransitions() const;
	/** Public setter for #bEvalWithTransitions. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Defaults")
	void SetEvalWithTransitions(const bool bValue);

private:
	friend class USMGraphNode_ConduitNode;
	
	/**
	 * This conduit will be evaluated with inbound and outbound transitions.
	 * If any transition fails the entire transition fails. In that case the
	 * state leading to this conduit will not take this transition.
	 *
	 * This makes the behavior similar to AnimGraph conduits.
	 */
	UPROPERTY(EditDefaultsOnly, Category = Conduit)
	bool bEvalWithTransitions;

	/**
	 * If this conduit is allowed to evaluate.
	 */
	UPROPERTY(EditDefaultsOnly, Category = Conduit, meta=(DisplayName = "Can Evaluate"))
	bool bCanEvaluate;
};

