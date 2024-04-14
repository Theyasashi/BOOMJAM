// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "Graph/Nodes/SMGraphNode_Base.h"
#include "Helpers/SMGraphK2Node_FunctionNodes.h"

#include "SMTransitionInstance.h"

#include "SMGraphNode_TransitionEdge.generated.h"

struct FSMTransition;
class USMGraphNode_StateNodeBase;
class USMTransitionGraph;

UCLASS()
class SMSYSTEMEDITOR_API USMGraphNode_TransitionEdge : public USMGraphNode_Base
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(meta = (BlueprintBaseOnly))
	TSubclassOf<USMTransitionInstance> TransitionClass;
	
	/**
	 * The instance which owns the delegate the transition should bind to.
	 */
	UPROPERTY(EditAnywhere, Category = "Event Trigger")
	TEnumAsByte<ESMDelegateOwner> DelegateOwnerInstance;

	/**
	 * The class of the instance containing the delegate.
	 */
	UPROPERTY(EditAnywhere, Category = "Event Trigger")
	TSubclassOf<UObject> DelegateOwnerClass;
	
	/**
	 * The guid assigned to this property if one exists.
	 */
	UPROPERTY()
	FGuid DelegatePropertyGuid;
	
	/**
	 * Available delegates.
	 */
	UPROPERTY(EditAnywhere, Category = "Event Trigger")
	FName DelegatePropertyName;

	/**
	 * If the event should trigger a targeted update of the state machine limited to this
	 * transition and destination state.
	 * 
	 * This can efficiently allow state machines with tick disabled to update. This
	 * won't evaluate parallel or super state transitions.
	 *
	 * This setting can also be changed on each Event Trigger Result Node.
	 */
	UPROPERTY(EditAnywhere, Category = "Event Trigger", meta = (DisplayName = "Targeted Update"))
	uint8 bEventTriggersTargetedUpdate: 1;

	/**
	 * If the event should trigger a full update of the state machine. Setting this will be applied
	 * after 'Targeted Update'. A full update consists of evaluating transitions top down from the
	 * root state machine, as well as running OnStateUpdate if necessary.
	 *
	 * This is a legacy setting. To maintain old legacy behavior enable this setting and
	 * disable 'Targeted Update'.
	 *
	 * This setting can also be changed on each Event Trigger Result Node.
	 */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Event Trigger", meta = (DisplayName = "Full Update"))
	uint8 bEventTriggersFullUpdate: 1;

	/**
	 * @deprecated Set on the node template instead.
	 */
	UPROPERTY()
	uint8 bCanEvaluate_DEPRECATED: 1;

	/**
	 * @deprecated Set on the node template instead.
	 */
	UPROPERTY()
	uint8 bCanEvaluateFromEvent_DEPRECATED: 1;
	
	/**
	 * @deprecated Set on the node template instead.
	 */
	UPROPERTY()
	uint8 bCanEvalWithStartState_DEPRECATED: 1;
	
	/**
	 * @deprecated Set on the node template instead.
	 */
	UPROPERTY()
	int32 PriorityOrder_DEPRECATED;
	
	/** Copy configuration settings to the runtime node. */
	void SetRuntimeDefaults(FSMTransition& Transition) const;

	/** Copy configurable settings from another transition node. */
	void CopyFrom(const USMGraphNode_TransitionEdge& Transition);

	/** Find the FSMTransition used to set defaults. */
	FSMTransition* GetRuntimeNode() const;
	
	// UEdGraphNode
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void PostPlacedNewNode() override;
	virtual void PrepareForCopying() override;
	virtual void PostPasteNode() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
	virtual void DestroyNode() override;
	virtual bool CanDuplicateNode() const override { return true; }
	virtual void ReconstructNode() override;
	virtual UObject* GetJumpTargetForDoubleClick() const override;
	// ~UEdGraphNode

	// USMGraphNode_Base
	virtual void ResetDebugState() override;
	virtual void UpdateTime(float DeltaTime) override;
	virtual void ImportDeprecatedProperties() override;
	virtual void PlaceDefaultInstanceNodes() override;
	virtual FName GetFriendlyNodeName() const override { return "Transition"; }
	virtual FLinearColor GetBackgroundColor() const override;
	virtual FLinearColor GetActiveBackgroundColor() const override;
	virtual UClass* GetNodeClass() const override { return TransitionClass; }
	virtual void SetNodeClass(UClass* Class) override;
	virtual bool SupportsPropertyGraphs() const override { return false; }
	virtual float GetMaxDebugTime() const override;
	virtual void PreCompile(FSMKismetCompilerContext& CompilerContext) override;
	virtual void OnCompile(FSMKismetCompilerContext& CompilerContext) override;
	// ~USMGraphNode_Base

protected:
	void CreateBoundGraph();
	void SetBoundGraph(UEdGraph* Graph);

public:
	/** Return the color to use for the transition. */
	FLinearColor GetTransitionColor(bool bIsHovered) const;

	/**
	 * Return the correct icon for the transition or transition stack.
	 * @param InIndex The icon to retrieve. < 0 for base transition, 0+ for the transition stack.
	 */
	const FSlateBrush* GetTransitionIcon(int32 InIndex);
	
	UClass* GetSelectedDelegateOwnerClass() const;
	
	void GoToTransitionEventNode();

	void InitTransitionDelegate();
	
protected:
	void SetupDelegateDefaults();
	void RefreshTransitionDelegate();
	
	/** Record the guid. */
	void UpdateTransitionDelegateGuid();

	/** Update all applicable transition result nodes with the event settings of this node. */
	void UpdateResultNodeEventSettings();
	
public:
	FString GetTransitionName() const;
	void CreateConnections(USMGraphNode_StateNodeBase* Start, USMGraphNode_StateNodeBase* End);

	/** Checks if there is any possibility of transitioning. */
	bool PossibleToTransition() const;

	USMTransitionGraph* GetTransitionGraph() const;
	
	USMGraphNode_StateNodeBase* GetFromState() const;
	USMGraphNode_StateNodeBase* GetToState() const;

	bool ShouldRunParallel() const;
	bool WasEvaluating() const { return bWasEvaluating; }

	bool IsHovered() const { return bIsHoveredByUser; }
	bool IsFromAnyState() const;
	
	/** Return the best pin to use for linear expression display. */
	UEdGraphPin* GetLinearExpressionPin() const;

protected:
	virtual FLinearColor Internal_GetBackgroundColor() const override;
	void SetDefaultsWhenPlaced();

protected:
	bool bWasEvaluating;
	
private:
	friend class FSMKismetCompilerContext;
	friend class FSMGraphConnectionDrawingPolicy;
	/* Connection drawing class manages these properties, but they're
	 * stored here because connection drawing is repeatedly reinstantiated. */

	// UTC time stamp user last hovered this node.
	FDateTime LastHoverTimeStamp;
	
	// Time in seconds since last hover.
	double TimeSinceHover;
	
	// If the user is considered hovering this node.
	bool bIsHoveredByUser;

	// Determined by kismet compiler. 
	bool bFromAnyState;
};
