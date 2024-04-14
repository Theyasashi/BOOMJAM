// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "BlueprintAssistSettings.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "Editor/EditorStyle/Public/EditorStyleSet.h"
#include "Framework/Commands/Commands.h"

enum class ECheckBoxState : unsigned char;
class SWidget;

class FBAToolbarCommandsImpl : public TCommands<FBAToolbarCommandsImpl>
{
public:
	FBAToolbarCommandsImpl()
		: TCommands<FBAToolbarCommandsImpl>(
			TEXT("BlueprintAssistToolbarCommands"),
			NSLOCTEXT("Contexts", "BlueprintAssistToolbarCommands", "Blueprint Assist Toolbar Commands"),
			NAME_None,
			FEditorStyle::GetStyleSetName())
	{
	}

	virtual ~FBAToolbarCommandsImpl()
	{
	}

	void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> AutoFormatting_Never;
	TSharedPtr<FUICommandInfo> AutoFormatting_FormatNewlyCreated;
	TSharedPtr<FUICommandInfo> AutoFormatting_FormatAll;

	TSharedPtr<FUICommandInfo> FormattingStyle_Compact;
	TSharedPtr<FUICommandInfo> FormattingStyle_Expanded;

	TSharedPtr<FUICommandInfo> ParameterStyle_LeftHandSide;
	TSharedPtr<FUICommandInfo> ParameterStyle_Helixing;

	TSharedPtr<FUICommandInfo> CommentInsertStyle_Never;
	TSharedPtr<FUICommandInfo> CommentInsertStyle_Always;
	TSharedPtr<FUICommandInfo> CommentInsertStyle_Surrounded;

	TSharedPtr<FUICommandInfo> FormatAllStyle_Simple;
	TSharedPtr<FUICommandInfo> FormatAllStyle_Smart;
	TSharedPtr<FUICommandInfo> FormatAllStyle_NodeType;

	TSharedPtr<FUICommandInfo> BlueprintAssistSettings;
};

class BLUEPRINTASSIST_API FBAToolbarCommands
{
public:
	static void Register();

	static const FBAToolbarCommandsImpl& Get();

	static void Unregister();
};

class FBAToolbar
{
public:
	TSharedPtr<FUICommandList> BlueprintAssistToolbarActions;

	TSharedPtr<FExtender> ToolbarExtender;

	static void SetAutoFormattingStyle(EBAAutoFormatting FormattingStyle);
	static bool IsAutoFormattingStyleChecked(EBAAutoFormatting FormattingStyle);

	static void SetParameterStyle(EBAParameterFormattingStyle Style);
	static bool IsParameterStyleChecked(EBAParameterFormattingStyle Style);

	static void SetNodeFormattingStyle(EBANodeFormattingStyle Style);
	static bool IsNodeFormattingStyleChecked(EBANodeFormattingStyle Style);

	static void SetCommentInsertStyle(EBAAutoInsertComment Style);
	static bool IsCommentInsertStyleChecked(EBAAutoInsertComment Style);

	static void SetFormatAllStyle(EBAFormatAllStyle Style);
	static bool IsFormatAllStyleChecked(EBAFormatAllStyle Style);

	void SetUseCommentBoxPadding(ECheckBoxState NewCheckedState);
	void SetGraphReadOnly(ECheckBoxState NewCheckedState);

	static void OpenBlueprintAssistSettings();

	void BindToolbarCommands();

	TSharedRef<SWidget> CreateToolbarWidget();

	void MakeAutoFormattingSubMenu(FMenuBuilder& InMenuBuilder);
	void MakeParameterStyleSubMenu(FMenuBuilder& InMenuBuilder);
	void MakeFormattingStyleSubMenu(FMenuBuilder& InMenuBuilder);
	void MakeCommentInsertStyleSubMenu(FMenuBuilder& InMenuBuilder);
	void MakeFormatAllStyleSubMenu(FMenuBuilder& InMenuBuilder);

	void ExtendToolbar(FToolBarBuilder& ToolbarBuilder);

	static FBAFormatterSettings* GetCurrentFormatterSettings();
};
