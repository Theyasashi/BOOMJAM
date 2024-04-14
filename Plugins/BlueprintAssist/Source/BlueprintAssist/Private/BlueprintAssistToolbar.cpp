// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistToolbar.h"

#include "Modules/ModuleManager.h"
#include "GraphEditorModule.h"
#include "PropertyEditorModule.h"

#include "BlueprintEditorModule.h"
#include "Widgets/Input/SCheckBox.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "BlueprintAssistSettings.h"
#include "BlueprintAssistSizeCache.h"
#include "LevelEditorActions.h"
#include "BlueprintAssistModule.h"
#include "BlueprintAssistInputProcessor.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistTabHandler.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "BlueprintAssist"

void FBAToolbarCommandsImpl::RegisterCommands()
{
	UI_COMMAND(
		AutoFormatting_Never,
		"Never auto format",
		"Never auto format when you create a new node",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		AutoFormatting_FormatAll,
		"Always format all connected nodes",
		"Always format all connected nodes when you create a new node",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		AutoFormatting_FormatNewlyCreated,
		"Only format the newly created node",
		"Only format the newly created node when you create a new node",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		FormattingStyle_Compact,
		"Formatting Style Compact",
		"Sets the formatting style to Compact",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		FormattingStyle_Expanded,
		"Formatting Style Expanded",
		"Sets the formatting style to Expanded",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		ParameterStyle_LeftHandSide,
		"Parameter Style Left Hand Side",
		"Parameters will be positioned out on the LHS when formatting",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		ParameterStyle_Helixing,
		"Parameter Style Helixing",
		"Parameter nodes will be positioned below when formatting",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		CommentInsertStyle_Never,
		"Auto Comment Insert: Never",
		"New nodes will never be inserted into connected comment nodes",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		CommentInsertStyle_Always,
		"Auto Comment Insert: Always",
		"New nodes will always be inserted into the comment node when connected",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		CommentInsertStyle_Surrounded,
		"Auto Comment Insert: Surrounded",
		"New nodes will only be inserted into the comment node when both connected nodes are also inside the comment",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		FormatAllStyle_Simple,
		"Format All Style: Simple",
		"Position root nodes into a single column",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		FormatAllStyle_Smart,
		"Format All Style: Smart",
		"Position root nodes into multiple columns based on node position",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		FormatAllStyle_NodeType,
		"Format All Style: Node Type",
		"Position nodes into columns based on root node type",
		EUserInterfaceActionType::RadioButton,
		FInputChord());

	UI_COMMAND(
		BlueprintAssistSettings,
		"Blueprint Assist Settings",
		"Open the blueprint assist settings",
		EUserInterfaceActionType::Button,
		FInputChord());
}

void FBAToolbarCommands::Register()
{
	FBAToolbarCommandsImpl::Register();
}

const FBAToolbarCommandsImpl& FBAToolbarCommands::Get()
{
	return FBAToolbarCommandsImpl::Get();
}

void FBAToolbarCommands::Unregister()
{
	return FBAToolbarCommandsImpl::Unregister();
}

void FBAToolbar::SetAutoFormattingStyle(EBAAutoFormatting FormattingStyle)
{
	if (FBAFormatterSettings* FormatterSettings = GetCurrentFormatterSettings())
	{
		UBASettings* BASettings = GetMutableDefault<UBASettings>();
		FormatterSettings->AutoFormatting = FormattingStyle;
		BASettings->PostEditChange();
		BASettings->SaveConfig();
	}
}

bool FBAToolbar::IsAutoFormattingStyleChecked(EBAAutoFormatting FormattingStyle)
{
	if (FBAFormatterSettings* FormatterSettings = GetCurrentFormatterSettings())
	{
		return FormatterSettings->AutoFormatting == FormattingStyle;
	}

	return false;
}

void FBAToolbar::SetParameterStyle(EBAParameterFormattingStyle Style)
{
	UBASettings* BASettings = GetMutableDefault<UBASettings>();
	BASettings->ParameterStyle = Style;
	BASettings->PostEditChange();
	BASettings->SaveConfig();
}

bool FBAToolbar::IsParameterStyleChecked(EBAParameterFormattingStyle Style)
{
	return GetDefault<UBASettings>()->ParameterStyle == Style;
}

void FBAToolbar::SetNodeFormattingStyle(EBANodeFormattingStyle Style)
{
	UBASettings* BASettings = GetMutableDefault<UBASettings>();
	BASettings->FormattingStyle = Style;
	BASettings->PostEditChange();
	BASettings->SaveConfig();
}

bool FBAToolbar::IsNodeFormattingStyleChecked(EBANodeFormattingStyle Style)
{
	return GetDefault<UBASettings>()->FormattingStyle == Style;
}

void FBAToolbar::SetCommentInsertStyle(EBAAutoInsertComment Style)
{
	UBASettings* BASettings = GetMutableDefault<UBASettings>();
	BASettings->AutoInsertComment = Style;
	BASettings->PostEditChange();
	BASettings->SaveConfig();
}

bool FBAToolbar::IsCommentInsertStyleChecked(EBAAutoInsertComment Style)
{
	return GetDefault<UBASettings>()->AutoInsertComment == Style;
}

void FBAToolbar::SetFormatAllStyle(EBAFormatAllStyle Style)
{
	UBASettings* BASettings = GetMutableDefault<UBASettings>();
	BASettings->FormatAllStyle = Style;
	BASettings->PostEditChange();
	BASettings->SaveConfig();
}

bool FBAToolbar::IsFormatAllStyleChecked(EBAFormatAllStyle Style)
{
	return GetDefault<UBASettings>()->FormatAllStyle == Style;
}

void FBAToolbar::SetUseCommentBoxPadding(ECheckBoxState NewCheckedState)
{
	UBASettings* BASettings = GetMutableDefault<UBASettings>();
	BASettings->bAccountForCommentsWhenFormatting = (NewCheckedState == ECheckBoxState::Checked) ? true : false;
	BASettings->PostEditChange();
	BASettings->SaveConfig();
}

void FBAToolbar::SetGraphReadOnly(ECheckBoxState NewCheckedState)
{
	TSharedPtr<FBAGraphHandler> GraphHandler = FBAUtils::GetCurrentGraphHandler();
	if (GraphHandler.IsValid())
	{
		GraphHandler->GetFocusedEdGraph()->bEditable = (NewCheckedState == ECheckBoxState::Checked) ? false : true;
	}
}

void FBAToolbar::OpenBlueprintAssistSettings()
{
	FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").ShowViewer("Editor", "Plugins", "BlueprintAssist");
}

void FBAToolbar::BindToolbarCommands()
{
	const FBAToolbarCommandsImpl& Commands = FBAToolbarCommands::Get();
	BlueprintAssistToolbarActions = MakeShareable(new FUICommandList);
	FUICommandList& ActionList = *BlueprintAssistToolbarActions;

	ActionList.MapAction(
		Commands.AutoFormatting_Never,
		FExecuteAction::CreateStatic(&FBAToolbar::SetAutoFormattingStyle, BAAutoFormat_Never),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsAutoFormattingStyleChecked, BAAutoFormat_Never)
	);

	ActionList.MapAction(
		Commands.AutoFormatting_FormatNewlyCreated,
		FExecuteAction::CreateStatic(&FBAToolbar::SetAutoFormattingStyle, BAAutoFormat_FormatSingleConnected),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsAutoFormattingStyleChecked, BAAutoFormat_FormatSingleConnected)
	);

	ActionList.MapAction(
		Commands.AutoFormatting_FormatAll,
		FExecuteAction::CreateStatic(&FBAToolbar::SetAutoFormattingStyle, BAAutoFormat_FormatAllConnected),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsAutoFormattingStyleChecked, BAAutoFormat_FormatAllConnected)
	);

	ActionList.MapAction(
		Commands.FormattingStyle_Compact,
		FExecuteAction::CreateStatic(&FBAToolbar::SetNodeFormattingStyle, BANodeFormatting_Compact),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsNodeFormattingStyleChecked, BANodeFormatting_Compact)
	);

	ActionList.MapAction(
		Commands.FormattingStyle_Expanded,
		FExecuteAction::CreateStatic(&FBAToolbar::SetNodeFormattingStyle, BANodeFormatting_Expanded),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsNodeFormattingStyleChecked, BANodeFormatting_Expanded)
	);

	ActionList.MapAction(
		Commands.ParameterStyle_LeftHandSide,
		FExecuteAction::CreateStatic(&FBAToolbar::SetParameterStyle, BAParameterFormatting_LeftSide),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsParameterStyleChecked, BAParameterFormatting_LeftSide)
	);

	ActionList.MapAction(
		Commands.ParameterStyle_Helixing,
		FExecuteAction::CreateStatic(&FBAToolbar::SetParameterStyle, BAParameterFormatting_Helixing),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsParameterStyleChecked, BAParameterFormatting_Helixing)
	);

	ActionList.MapAction(
		Commands.CommentInsertStyle_Never,
		FExecuteAction::CreateStatic(&FBAToolbar::SetCommentInsertStyle, BAAutoInsertComment_Never),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsCommentInsertStyleChecked, BAAutoInsertComment_Never)
	);

	ActionList.MapAction(
		Commands.CommentInsertStyle_Always,
		FExecuteAction::CreateStatic(&FBAToolbar::SetCommentInsertStyle, BAAutoInsertComment_Always),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsCommentInsertStyleChecked, BAAutoInsertComment_Always)
	);

	ActionList.MapAction(
		Commands.CommentInsertStyle_Surrounded,
		FExecuteAction::CreateStatic(&FBAToolbar::SetCommentInsertStyle, BAAutoInsertComment_Surrounded),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsCommentInsertStyleChecked, BAAutoInsertComment_Surrounded)
	);

	ActionList.MapAction(
		Commands.FormatAllStyle_Simple,
		FExecuteAction::CreateStatic(&FBAToolbar::SetFormatAllStyle, BAFormatAll_Simple),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsFormatAllStyleChecked, BAFormatAll_Simple)
	);

	ActionList.MapAction(
		Commands.FormatAllStyle_Smart,
		FExecuteAction::CreateStatic(&FBAToolbar::SetFormatAllStyle, BAFormatAll_Smart),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsFormatAllStyleChecked, BAFormatAll_Smart)
	);

	ActionList.MapAction(
		Commands.FormatAllStyle_NodeType,
		FExecuteAction::CreateStatic(&FBAToolbar::SetFormatAllStyle, BAFormatAll_NodeType),
		FCanExecuteAction(),
		FIsActionChecked::CreateStatic(&FBAToolbar::IsFormatAllStyleChecked, BAFormatAll_NodeType)
	);

	ActionList.MapAction(
		Commands.BlueprintAssistSettings,
		FExecuteAction::CreateStatic(&FBAToolbar::OpenBlueprintAssistSettings)
	);
}

TSharedRef<SWidget> FBAToolbar::CreateToolbarWidget()
{
	const bool bShouldCloseWindowAfterMenuSelection = true;

	FMenuBuilder MenuBuilder(bShouldCloseWindowAfterMenuSelection, BlueprintAssistToolbarActions, ToolbarExtender);

	TSharedPtr<FBAGraphHandler> GraphHandler = FBAUtils::GetCurrentGraphHandler();
	if (GraphHandler.IsValid())
	{
		MenuBuilder.BeginSection("FormattingSettings");
		{
			MenuBuilder.AddSubMenu(
				LOCTEXT("AutoFormattingSubMenu", "Auto Formatting Behaviour"),
				LOCTEXT("AutoFormattingSubMenu_Tooltip", "Allows you to set the auto formatting behavior when a new node is added to the graph"),
				FNewMenuDelegate::CreateRaw(this, &FBAToolbar::MakeAutoFormattingSubMenu));

			MenuBuilder.AddSubMenu(
				LOCTEXT("FormattingStyleSubMenu", "Formatting Style"),
				LOCTEXT("FormattingStyleSubMenu_Tooltip", "Set the formatting style"),
				FNewMenuDelegate::CreateRaw(this, &FBAToolbar::MakeFormattingStyleSubMenu));

			MenuBuilder.AddSubMenu(
				LOCTEXT("ParameterStyleSubMenu", "Parameter Style"),
				LOCTEXT("ParameterStyleSubMenu_Tooltip", "Set the style for parameters when formatting"),
				FNewMenuDelegate::CreateRaw(this, &FBAToolbar::MakeParameterStyleSubMenu));

			MenuBuilder.AddSubMenu(
				LOCTEXT("AutoCommentInsertStyleSubMenu", "Auto Comment Insert Style"),
				LOCTEXT("AutoCommentInsertStyle_Tooltip", "Set the auto comment insert style"),
				FNewMenuDelegate::CreateRaw(this, &FBAToolbar::MakeCommentInsertStyleSubMenu));

			MenuBuilder.AddSubMenu(
				LOCTEXT("FormatAllInsertStyleSubMenu", "Format All Insert Style"),
				LOCTEXT("FormatAllInsertStyle_Tooltip", "Set the format all style"),
				FNewMenuDelegate::CreateRaw(this, &FBAToolbar::MakeFormatAllStyleSubMenu));

			TSharedRef<SWidget> AccountForCommentsCheckbox = SNew(SBox)
			[
				SNew(SCheckBox)
				.IsChecked(GetDefault<UBASettings>()->bAccountForCommentsWhenFormatting ? ECheckBoxState::Checked : ECheckBoxState::Unchecked)
				.OnCheckStateChanged(FOnCheckStateChanged::CreateRaw(this, &FBAToolbar::SetUseCommentBoxPadding))
				.Style(FEditorStyle::Get(), "Menu.CheckBox")
				.ToolTipText(LOCTEXT("AccountCommentNodesFormattingToolTip", "Toggle whether to account for comment nodes when formatting"))
				.Content()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(2.0f, 0.0f, 0.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("AccountCommentNodesFormatting", "Account for comment nodes when formatting (Experimental)"))
					]
				]
			];

			MenuBuilder.AddMenuEntry(FUIAction(), AccountForCommentsCheckbox);
		}
		MenuBuilder.EndSection();

		MenuBuilder.BeginSection("MiscSettings");
		{
			TSharedRef<SWidget> GraphReadOnlyCheckbox = SNew(SBox)
			[
				SNew(SCheckBox)
	            .IsChecked(GraphHandler->IsGraphReadOnly() ? ECheckBoxState::Checked : ECheckBoxState::Unchecked)
	            .OnCheckStateChanged(FOnCheckStateChanged::CreateRaw(this, &FBAToolbar::SetGraphReadOnly))
	            .Style(FEditorStyle::Get(), "Menu.CheckBox")
	            .ToolTipText(LOCTEXT("GraphReadOnlyToolTip", "Set the graph read only state (cannot be undone without the BA plugin!)"))
				.Content()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(2.0f, 0.0f, 0.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("GraphReadOnly", "Graph Read Only"))
					]
				]
			];

			MenuBuilder.AddMenuEntry(FUIAction(), GraphReadOnlyCheckbox);
		}
		MenuBuilder.EndSection();

		// open blueprint settings
		MenuBuilder.BeginSection("BlueprintAssistSettings");
		{
			MenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().BlueprintAssistSettings);
		}
		MenuBuilder.EndSection();
	}

	TSharedRef<SWidget> MenuBuilderWidget = MenuBuilder.MakeWidget();

	return MenuBuilderWidget;
}

void FBAToolbar::MakeAutoFormattingSubMenu(FMenuBuilder& InMenuBuilder)
{
	InMenuBuilder.BeginSection("AutoFormattingStyle", LOCTEXT("AutoFormattingStyle", "Auto Formatting Style"));
	{
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().AutoFormatting_Never);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().AutoFormatting_FormatNewlyCreated);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().AutoFormatting_FormatAll);
	}
	InMenuBuilder.EndSection();
}

void FBAToolbar::MakeParameterStyleSubMenu(FMenuBuilder& InMenuBuilder)
{
	InMenuBuilder.BeginSection("ParameterStyle", LOCTEXT("ParameterStyle", "Parameter Style"));
	{
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().ParameterStyle_Helixing);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().ParameterStyle_LeftHandSide);
	}
	InMenuBuilder.EndSection();
}

void FBAToolbar::MakeFormattingStyleSubMenu(FMenuBuilder& InMenuBuilder)
{
	InMenuBuilder.BeginSection("FormattingStyle", LOCTEXT("FormattingStyle", "Formatting Style"));
	{
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().FormattingStyle_Compact);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().FormattingStyle_Expanded);
	}
	InMenuBuilder.EndSection();
}

void FBAToolbar::MakeCommentInsertStyleSubMenu(FMenuBuilder& InMenuBuilder)
{
	InMenuBuilder.BeginSection("CommentInsertStyle", LOCTEXT("CommentInsertStyle", "Comment Insert Style"));
	{
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().CommentInsertStyle_Never);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().CommentInsertStyle_Always);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().CommentInsertStyle_Surrounded);
	}
	InMenuBuilder.EndSection();
}

void FBAToolbar::MakeFormatAllStyleSubMenu(FMenuBuilder& InMenuBuilder)
{
	InMenuBuilder.BeginSection("FormatAllStyle", LOCTEXT("FormatAllStyle", "Format All Style"));
	{
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().FormatAllStyle_Simple);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().FormatAllStyle_Smart);
		InMenuBuilder.AddMenuEntry(FBAToolbarCommands::Get().FormatAllStyle_NodeType);
	}
	InMenuBuilder.EndSection();
}

void FBAToolbar::ExtendToolbar(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateRaw(this, &FBAToolbar::CreateToolbarWidget),
		LOCTEXT("BlueprintAssist", "BP Assist"),
		LOCTEXT("BlueprintAssistSettingsMenu", "Blueprint Assist Settings Menu"),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.GameSettings"),
		false
	);
}

FBAFormatterSettings* FBAToolbar::GetCurrentFormatterSettings()
{
	auto GraphHandler = FBAUtils::GetCurrentGraphHandler();
	if (!GraphHandler.IsValid())
		return nullptr;

	return &FBAUtils::GetFormatterSettings(GraphHandler->GetFocusedEdGraph());
}
