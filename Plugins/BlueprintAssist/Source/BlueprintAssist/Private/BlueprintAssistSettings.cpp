// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistSettings.h"
#include "BlueprintAssistModule.h"
#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistTabHandler.h"
#include "BlueprintAssistInputProcessor.h"
#include "BlueprintAssistSizeCache.h"

#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Input/SButton.h"

UBASettings::UBASettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisabledGraphs = { BAGraphType_Unknown };

	UseBlueprintFormattingForTheseGraphs =
	{
		"EdGraph",
		"GameplayAbilityGraph",
		"AnimationTransitionGraph",
	};

	ExtraRootNodeTypes =
	{
		"AnimGraphNode_Root",
		"AnimGraphNode_TransitionResult",
		"K2Node_Tunnel",
		"SoundCueGraphNode_Root",
		"BehaviorTreeGraphNode_Root",
		"MaterialGraphNode_Root",
		"NiagaraNodeInput",
	};

	ShiftCameraDistance = 400.0f;
	
	bSaveBlueprintAssistCacheToFile = true;

	bAddToolbarWidget = true;

	PinHighlightColor = FLinearColor(0.2f, 0.2f, 0.2f);
	PinTextHighlightColor = FLinearColor(0.728f, 0.364f, 0.003f);

	// ------------------- //
	// Format all settings //
	// ------------------- //
	
	FormatAllStyle = BAFormatAll_Simple; 
	bAutoPositionEventNodes = false;
	bAlwaysFormatAll = false;
	FormatAllPadding = FVector2D(800, 250);

	ExecutionWiringStyle = BAWiringStyle_AlwaysMerge;
	ParameterWiringStyle = BAWiringStyle_AlwaysMerge;

	FormattingStyle = BANodeFormatting_Expanded;
	ParameterStyle = BAParameterFormatting_Helixing;

	BlueprintParameterPadding = FVector2D(40, 25);
	BlueprintKnotTrackSpacing = 26.f;
	VerticalPinSpacing = 26.f;
	ParameterVerticalPinSpacing = 8.f;

	bLimitHelixingHeight = true;
	HelixingHeightMax = 500;
	SingleNodeMaxHeight = 300;

	// ------------------ //
	// Formatter Settings //
	// ------------------ //
	
	BlueprintFormatterSettings.Padding = FVector2D(80, 150);
	BlueprintFormatterSettings.AutoFormatting = BAAutoFormat_Never;
	
	BehaviorTreeFormatterSettings.Padding = FVector2D(100, 100);
	BehaviorTreeFormatterSettings.AutoFormatting = BAAutoFormat_Never;
	
	MaterialGraphFormatterSettings.Padding = FVector2D(200, 100);
	MaterialGraphFormatterSettings.AutoFormatting = BAAutoFormat_Never;
	
	NiagaraGraphFormatterSettings.Padding = FVector2D(80, 150);
	NiagaraGraphFormatterSettings.AutoFormatting = BAAutoFormat_Never;
	
	AnimationGraphFormatterSettings.Padding = FVector2D(80, 150);
	AnimationGraphFormatterSettings.AutoFormatting = BAAutoFormat_Never;

	SoundCueGraphFormatterSettings.Padding = FVector2D(80, 150);
	SoundCueGraphFormatterSettings.AutoFormatting = BAAutoFormat_Never;
	
	bCreateKnotNodes = true;

	bBetterWiringForNewNodes = false;

	bSetAllCommentBubblePinned = false;
	bCacheSizeWhenRequired = true;

	bTreatDelegatesAsExecutionPins = false;
	bCenterBranches = false;
	NumRequiredBranches = 3;

	AutoInsertComment = BAAutoInsertComment_Always;
	bTryToHandleCommentNodes = true;
	bAddKnotNodesToComments = true;
	CommentNodePadding = FVector2D(30, 30);

	bEnableFasterFormatting = false;

	bUseKnotNodePool = false;

	bSlowButAccurateSizeCaching = false;

	bAccountForCommentsWhenFormatting = false;

	KnotNodeDistanceThreshold = 800.f;

	bExpandNodesByHeight = true;
	bExpandParametersByHeight = false;

	bEnableCachingNodeSizeNotification = true;
	RequiredNumPendingSizeForNotification = 50;

	bCustomDebug = -1;

	// ------------------------ //
	// Create variable defaults //
	// ------------------------ //
	bDefaultInstanceEditable = false;
	bDefaultBlueprintReadOnly = false;
	bDefaultExposeOnSpawn = false;
	bDefaultPrivate = false;
	bDefaultExposeToCinematics = false;
	DefaultVariableName = TEXT("VarName");
	DefaultTooltip = FText::FromString(TEXT(""));
	DefaultCategory = FText::FromString(TEXT(""));
}

void UBASettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	check(IBlueprintAssistModule::IsAvailable())

	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	TSharedPtr<FBAInputProcessor> InputProcessor = IBlueprintAssistModule::Get().GetInputProcessor();

	if (InputProcessor.IsValid())
	{
		if (InputProcessor->TabHandler.IsValid())
		{
			TSharedPtr<FBAGraphHandler> GraphHandler = InputProcessor->TabHandler->GetGraphHandler();
			if (GraphHandler.IsValid())
			{
				if (PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bSetAllCommentBubblePinned))
				{
					GraphHandler->ApplyCommentBubbleSetting();
				}
				else if (PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bCacheSizeWhenRequired))
				{
					GraphHandler->ClearCache();
				}
				else if (PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, ParameterStyle)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, FormattingStyle)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, ParameterWiringStyle)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, ExecutionWiringStyle)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bLimitHelixingHeight)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, HelixingHeightMax)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, SingleNodeMaxHeight)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, BlueprintKnotTrackSpacing)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, BlueprintParameterPadding)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, FormatAllPadding)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bTreatDelegatesAsExecutionPins)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bExpandNodesByHeight)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bExpandParametersByHeight)
					|| PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bCreateKnotNodes)
					|| PropertyName == NAME_None) // if the name is none, this probably means we changed a property through the toolbar
					// TODO: maybe there's a way to change property externally while passing in correct info name
				{
					GraphHandler->ClearFormatters();
				}
			}
		}
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UBASettings, bAddToolbarWidget))
	{
		if (bAddToolbarWidget)
		{
			IBlueprintAssistModule::Get().BindAssetOpenedDelegate();
		}
		else
		{
			IBlueprintAssistModule::Get().UnbindAssetOpenedDelegate();
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

TSharedRef<IDetailCustomization> FBASettingsDetails::MakeInstance()
{
	return MakeShareable(new FBASettingsDetails);
}

void FBASettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	check(ObjectsBeingCustomized.Num() == 1);
	TWeakObjectPtr<UBASettings> Settings = Cast<UBASettings>(ObjectsBeingCustomized[0].Get());

	IDetailCategoryBuilder& EncryptionCategory = DetailBuilder.EditCategory("General");
	auto& SizeCache = IBlueprintAssistModule::Get().GetSizeCache();

	const FString CachePath = SizeCache.GetCachePath();

	const auto DeleteSizeCache = [&SizeCache]()
	{
		SizeCache.DeleteCache();
		return (FReply::Handled());
	};

	EncryptionCategory.AddCustomRow(FText::FromString("SizeCache")).ValueContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot().Padding(5).AutoWidth()
		[
			SNew(SButton)
				.Text(FText::FromString("Delete size cache file"))
				.ToolTipText(FText::FromString(FString::Printf(TEXT("Delete size cache file located at: %s"), *CachePath)))
				.OnClicked_Lambda(DeleteSizeCache)
		]
	];
}
