// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "IDetailCustomization.h"

#include "BlueprintAssistSettings.generated.h"


UENUM()
enum EBANodeFormattingStyle
{
	BANodeFormatting_Expanded UMETA(DisplayName = "Expanded"),
	BANodeFormatting_Compact UMETA(DisplayName = "Compact"),
};

UENUM()
enum EBAParameterFormattingStyle
{
	BAParameterFormatting_Helixing UMETA(DisplayName = "Helixing"),
	BAParameterFormatting_LeftSide UMETA(DisplayName = "Left-side"),
};

UENUM()
enum EBAGraphType
{
	BAGraphType_Unknown UMETA(DisplayName = "Unknown"),
	BAGraphType_Blueprint UMETA(DisplayName = "Blueprint"),
	BAGraphType_SoundCue UMETA(DisplayName = "Sound Cue"),
	BAGraphType_BehaviorTree UMETA(DisplayName = "Behavior Tree"),
	BAGraphType_MaterialGraph UMETA(DisplayName = "Material Graph"),
	BAGraphType_NiagaraGraph UMETA(DisplayName = "Niagara Graph"),
	BAGraphType_AnimGraph UMETA(DisplayName = "Anim Graph"),
};

UENUM()
enum EBAWiringStyle
{
	BAWiringStyle_AlwaysMerge UMETA(DisplayName = "Always Merge"),
	BAWiringStyle_MergeWhenNear UMETA(DisplayName = "Merge When Near"),
	BAWiringStyle_SingleWire UMETA(DisplayName = "Single Wire"),
};

UENUM()
enum EBAAutoInsertComment
{
	BAAutoInsertComment_Never UMETA(DisplayName = "Never"),
	BAAutoInsertComment_Always UMETA(DisplayName = "Always"),
	BAAutoInsertComment_Surrounded UMETA(DisplayName = "Surrounded"),
};

UENUM()
enum EBAAutoFormatting
{
	BAAutoFormat_Never UMETA(DisplayName = "Never"),
	BAAutoFormat_FormatAllConnected UMETA(DisplayName = "Format all connected nodes"),
	BAAutoFormat_FormatSingleConnected UMETA(DisplayName = "Format relative to a connected node"),
};

UENUM()
enum EBAFormatAllStyle
{
	BAFormatAll_Simple UMETA(DisplayName = "Simple (single column)"),
    BAFormatAll_Smart UMETA(DisplayName = "Smart (create columns from node position)"),
    BAFormatAll_NodeType UMETA(DisplayName = "Node Type (columns by node type)"),
};

USTRUCT()
struct FBAFormatterSettings
{
	GENERATED_BODY()

	/* Padding used when formatting nodes */
	UPROPERTY(EditAnywhere, config, Category = FormatterSettings)
	FVector2D Padding = FVector2D(100, 100);

	/* Auto formatting method */
	UPROPERTY(EditAnywhere, config, Category = FormatterSettings)
	TEnumAsByte<EBAAutoFormatting> AutoFormatting = BAAutoFormat_Never;
};

UCLASS(config = EditorSettings)
class BLUEPRINTASSIST_API UBASettings : public UObject
{
	GENERATED_BODY()

public:
	UBASettings(const FObjectInitializer& ObjectInitializer);

	////////////////////////////////////////////////////////////
	// General
	////////////////////////////////////////////////////////////

	/* Add the BlueprintAssist widget to the toolbar */
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bAddToolbarWidget;

	/* Highlight the currently selected pin with this color */
	UPROPERTY(EditAnywhere, config, Category = General)
	FLinearColor PinHighlightColor;

	/* Highlight the text for the currently selected pin with this color */
	UPROPERTY(EditAnywhere, config, Category = General)
	FLinearColor PinTextHighlightColor;

	/* Sets the 'Comment Bubble Pinned' bool for all nodes on the graph */
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bSetAllCommentBubblePinned;

	/* Improves the default wiring behavior for new nodes */
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bBetterWiringForNewNodes;

	/* Distance the viewport moves when running the Shift Camera command. Scaled by zoom distance. */
	UPROPERTY(EditAnywhere, config, Category = General)
	float ShiftCameraDistance;
	
	/* Enable more slower but more accurate node size caching */
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bSlowButAccurateSizeCaching;

	/* Save the node size cache to a file (located in the the plugin folder) */
	UPROPERTY(EditAnywhere, config, Category = General)
	bool bSaveBlueprintAssistCacheToFile;

	/* List of disabled graph types */
	UPROPERTY(EditAnywhere, config, Category = General)
	TArray<TEnumAsByte<EBAGraphType>> DisabledGraphs;

	////////////////////////////////////////////////////////////
	// Formatting options
	////////////////////////////////////////////////////////////

	/* Blueprint formatting will be used for these types of graphs (you can see the type of a graph with the PrintGraphInfo command, default: unbound) */
	UPROPERTY(EditAnywhere, config, AdvancedDisplay, Category = FormattingOptions)
	TArray<FName> UseBlueprintFormattingForTheseGraphs;

	/* Add custom node types (besides blueprint event nodes) that you want to format when using the FormatAll command */
	UPROPERTY(EditAnywhere, config, AdvancedDisplay, Category = FormattingOptions)
	TArray<FName> ExtraRootNodeTypes;

	/* Determines how execution nodes are positioned */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	TEnumAsByte<EBANodeFormattingStyle> FormattingStyle;

	/* Determines how parameters are positioned */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	TEnumAsByte<EBAParameterFormattingStyle> ParameterStyle;

	/* Determines how execution wires are created */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	TEnumAsByte<EBAWiringStyle> ExecutionWiringStyle;

	/* Determines how parameter wires are created */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	TEnumAsByte<EBAWiringStyle> ParameterWiringStyle;

	/* Faster formatting will only format chains of nodes have been moved or had connections changed. Greatly increases speed of the format all command. */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bEnableFasterFormatting;

	/* Reuse knot nodes instead of creating new ones every time */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bUseKnotNodePool;

	/* Whether to use HelixingHeightMax and SingleNodeMaxHeight */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bLimitHelixingHeight;

	/* Helixing is disabled if the total height of the parameter nodes is larger than this value */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions, meta = (EditCondition = "bLimitHelixingHeight"))
	float HelixingHeightMax;

	/* Helixing is disabled if a single node is taller than this value */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions, meta = (EditCondition = "bLimitHelixingHeight"))
	float SingleNodeMaxHeight;

	/* Cache nodes only when you require their size. Use this if you have extremely large graphs. */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bCacheSizeWhenRequired;

	/* Create knot nodes */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bCreateKnotNodes;

	/* Add spacing to nodes which have many connections, fixing hard to read wires */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bExpandNodesByHeight;

	/* Add spacing to parameter nodes which have many connections, fixing hard to read wires */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bExpandParametersByHeight;

	////////////////////////////////////////////////////////////
	/// Format All
	////////////////////////////////////////////////////////////

	/* Determines how nodes are positioned into columns when running formatting all nodes */
    UPROPERTY(EditAnywhere, config, Category = FormatAll)
    TEnumAsByte<EBAFormatAllStyle> FormatAllStyle;
    
    /* x values defines padding between columns, y value defines horizontal padding between node trees */
    UPROPERTY(EditAnywhere, config, Category = FormatAll)
    FVector2D FormatAllPadding;

    /* Call the format all function when a new event node is added to the graph */
    UPROPERTY(EditAnywhere, config, Category = FormatAll)
    bool bAutoPositionEventNodes;

    /* Call the format all function when ANY new node is added to the graph. Useful for when the 'UseColumnsForFormatAll' setting is on. */
    UPROPERTY(EditAnywhere, config, Category = FormatAll)
    bool bAlwaysFormatAll;
    
	////////////////////////////////////////////////////////////
	// Blueprint formatting
	////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	FBAFormatterSettings BlueprintFormatterSettings;
	
	/* Padding used between parameter nodes */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	FVector2D BlueprintParameterPadding;

	/* When formatting treat delegate pins as execution pins, recommended to turn this option off and use the 'CreateEvent' node */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	bool bTreatDelegatesAsExecutionPins;

	/* Center node execution branches (Default: center nodes with 3 or more branches) */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
    bool bCenterBranches;

	/* Only center branches if we have this (or more) number of branches */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting, meta = (EditCondition = "bCenterBranches"))
	int NumRequiredBranches;

	/* Vertical spacing from the last linked pin */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	float VerticalPinSpacing;

	/* Vertical spacing from the last linked pin for parameters */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	float ParameterVerticalPinSpacing;
	
	/* Spacing used between wire tracks */
	UPROPERTY(EditAnywhere, config, Category = BlueprintFormatting)
	float BlueprintKnotTrackSpacing;

	/* The width between pins required for a knot node to be created */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	float KnotNodeDistanceThreshold;

	////////////////////////////////////////////////////////////
	// Behavior tree formatting
	////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, config, Category = BehaviorTreeFormatter)
	FBAFormatterSettings BehaviorTreeFormatterSettings;

	////////////////////////////////////////////////////////////
	// Sound cue graph formatting
	////////////////////////////////////////////////////////////
	
	UPROPERTY(EditAnywhere, config, Category = SoundCueGraphFormatter)
	FBAFormatterSettings SoundCueGraphFormatterSettings;

	////////////////////////////////////////////////////////////
	// Material graph formatting
	////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, config, Category = MaterialGraphFormatter)
	FBAFormatterSettings MaterialGraphFormatterSettings;
	
	////////////////////////////////////////////////////////////
	// Niagara Graph formatting
	////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, config, Category = NiagaraGraphFormatter)
	FBAFormatterSettings NiagaraGraphFormatterSettings;

	////////////////////////////////////////////////////////////
	// Animation Graph formatting
	////////////////////////////////////////////////////////////

	UPROPERTY(EditAnywhere, config, Category = AnimationGraphFormatter)
	FBAFormatterSettings AnimationGraphFormatterSettings;
	
	////////////////////////////////////////////////////////////
	// Comment Settings
	////////////////////////////////////////////////////////////

	/* Account for containing comments when formatting */
	UPROPERTY(EditAnywhere, config, Category = FormattingOptions)
	bool bAccountForCommentsWhenFormatting;
	
	/* Automatically insert new nodes into comment boxes */
	UPROPERTY(EditAnywhere, config, Category = General)
	TEnumAsByte<EBAAutoInsertComment> AutoInsertComment;
	
	/* Updates comment nodes when formatting, recommended to use this along with the AutoSizeComments plugin */
	UPROPERTY(EditAnywhere, config, Category = CommentSettings)
	bool bTryToHandleCommentNodes;

	/* Add knot nodes to comments after formatting */
	UPROPERTY(EditAnywhere, config, Category = CommentSettings)
	bool bAddKnotNodesToComments;

	/* Padding around the comment box. Make sure this is the same as in the AutoSizeComments setting */
	UPROPERTY(EditAnywhere, config, Category = CommentSettings)
	FVector2D CommentNodePadding;

	////////////////////////////////////////////////////////////
	// Notifications
	////////////////////////////////////////////////////////////

	/* Whether to show a notification while the graph is caching node sizes */
	UPROPERTY(EditAnywhere, config, Category = Notifications)
	bool bEnableCachingNodeSizeNotification;

	/* Number of pending caching nodes required to show notification */
	UPROPERTY(EditAnywhere, config, Category = Notifications, meta = (EditCondition = "bEnableCachingNodeSizeNotification"))
	int RequiredNumPendingSizeForNotification;
	
	////////////////////////////////////////////////////////////
	// Create variable defaults
	////////////////////////////////////////////////////////////
	
	/* Variable default Instance Editable */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    bool bDefaultInstanceEditable;

	/* Variable default Blueprint Read Only */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    bool bDefaultBlueprintReadOnly;
    
	/* Variable default Expose on Spawn */
    UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    bool bDefaultExposeOnSpawn;

	/* Variable default Private */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
	bool bDefaultPrivate;

	/* Variable default Expose to Cinematics */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    bool bDefaultExposeToCinematics;

	/* Variable default name */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    FString DefaultVariableName;
	
	/* Variable default Tooltip */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    FText DefaultTooltip;

	/* Variable default Category */
	UPROPERTY(EditAnywhere, config, Category = "Create Variable Defaults")
    FText DefaultCategory;
	
	////////////////////////////////////////////////////////////
	// Debug
	////////////////////////////////////////////////////////////

	/* Ignore this (setting for custom debugging) */
	UPROPERTY(EditAnywhere, config, Category = Debug)
	int bCustomDebug;
	
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};

class FBASettingsDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};