// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"

#include "SMEditorSettings.generated.h"

UENUM()
enum class ESMJumpToGraphBehavior : uint8
{
	/** The local or intermediate graph within the same blueprint. */
	PreferLocalGraph,
	/** An external blueprint's graph. */
	PreferExternalGraph
};

UCLASS(config = EditorPerProjectUserSettings)
class USMEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	USMEditorSettings();

	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor StateDefaultColor;

	/** When a state has internal logic. */
	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor StateWithLogicColor;

	/** When a node is an end state. */
	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor EndStateColor;

	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor StateMachineDefaultColor;

	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor StateMachineParentDefaultColor;
	
	/** When a state machine has states. */
	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor StateMachineWithLogicColor;

	/** The default color for Any States. */
	UPROPERTY(config, EditAnywhere, Category = "States")
	FLinearColor AnyStateDefaultColor;

	/** The maximum amount of Any State icons to display per state. */
	UPROPERTY(config, EditAnywhere, Category = "States", meta = (ClampMin = "0", ClampMax = "10"))
	int32 MaxAnyStateIcons;
	
	/** The buffer size which accepts pins to create transitions. Open editors will need to be refreshed. */
	UPROPERTY(config, EditAnywhere, Category = "States", meta = (ClampMin = "4.0", ClampMax = "15.0"))
	float StateConnectionSize;
	
	/** The padding around the main content box for state machines. */
	UPROPERTY(config, EditAnywhere, AdvancedDisplay, Category = "States")
	FMargin StateMachineContentPadding;
	
	/** The padding around the main content box. */
	UPROPERTY(config, EditAnywhere, AdvancedDisplay, Category = "States")
	FMargin StateContentPadding;

	/** Prevent nodes from displaying overlay widgets indicating a special status, such as for intermediate graphs or waiting for an end state. */
	UPROPERTY(config, EditAnywhere, AdvancedDisplay, Category = "States")
	bool bDisableVisualCues;
	
	/** When a transition evaluator has no input. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions")
	FLinearColor TransitionEmptyColor;

	/** When the transition evaluator has input. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions")
	FLinearColor TransitionValidColor;

	/** When a transition is hovered. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions")
	FLinearColor TransitionHoverColor;

	/** Allow transitions with On Transition Entered logic to have a special color. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions")
	bool bEnableTransitionWithEntryLogicColor;
	
	/** When a transition has On Transition Entered logic. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions", meta = (EditCondition = "bEnableTransitionWithEntryLogicColor"))
	FLinearColor TransitionWithEntryLogicColor;

	/** Display the transition priority next to transition icons. */
	UPROPERTY(config, EditAnywhere, Category = "Transitions")
	bool bDisplayTransitionPriority;
	
	/** When a state is active during debug. */
	UPROPERTY(config, EditAnywhere, Category = "Debug")
	FLinearColor ActiveStateColor;

	/** When a transition is active during debug. */
	UPROPERTY(config, EditAnywhere, Category = "Debug")
	FLinearColor ActiveTransitionColor;
	
	/** Time in seconds before the last state starts to fade. */
	UPROPERTY(config, EditAnywhere, Category = "Debug", meta = (ClampMin = "0.0"))
	float TimeToDisplayLastActiveState;

	/** The fade time in seconds to hide the last active state. */
	UPROPERTY(config, EditAnywhere, Category = "Debug", meta = (ClampMin = "0.0"))
	float TimeToFadeLastActiveState;

	/** The fade time in seconds to hide the last active transition. */
	UPROPERTY(config, EditAnywhere, Category = "Debug", meta = (ClampMin = "0.0"))
	float TimeToFadeLastActiveTransition;

	/** Transitions that are evaluating will be highlighted in the editor during debug. */
	UPROPERTY(config, EditAnywhere, Category = "Debug")
	bool bDisplayTransitionEvaluation;
	
	/** When a transition is evaluating during debug. */
	UPROPERTY(config, EditAnywhere, Category = "Debug", meta = (EditCondition = "bDisplayTransitionEvaluation"))
	FLinearColor EvaluatingTransitionColor;
	
	/**
	 * The behavior when double clicking on state machine references.
	 * The local graph is available when the intermediate graph is enabled.
	 *
	 * If a node class is assigned it will still have to be accessed through the context menu.
	 */
	UPROPERTY(config, EditAnywhere, Category = "Node Double Click")
	ESMJumpToGraphBehavior ReferenceDoubleClickBehavior;
	
	/** Show fast path icons on all applicable nodes. */
	UPROPERTY(config, EditAnywhere, Category = "Visual")
	bool bDisplayFastPath;
	
	/**
	 * Add all Kismet toolbar extenders to the state machine editor. This allows items from third party plugins to be visible in Logic Driver.
	 */
	UPROPERTY(config, EditAnywhere, Category = "Plugin Compatibility")
	bool bEnableBlueprintToolbarExtenders;

	/**
	 * Add all Kismet menu extenders to the state machine editor. This allows items from third party plugins to be visible in Logic Driver.
	 */
	UPROPERTY(config, EditAnywhere, Category = "Plugin Compatibility")
	bool bEnableBlueprintMenuExtenders;
};
