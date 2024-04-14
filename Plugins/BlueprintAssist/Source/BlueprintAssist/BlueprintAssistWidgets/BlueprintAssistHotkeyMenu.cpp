// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistHotkeyMenu.h"
#include "EditorStyleSet.h"
#include "Widgets/Layout/SBox.h"

#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
// #include "Widgets/Input/SSearchBox.h"
#include "BlueprintAssistGraphHandler.h"

#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/Slate/Public/Widgets/Text/SRichTextBlock.h"
#include "Editor/Kismet/Public/SSCSEditor.h"
#include "Widgets/Layout/SScrollBox.h"

void SBAHotkeyMenu::Construct(
	const FArguments& InArgs)
{
	WidgetSize = FVector2D(600, 600);
	
	const FInputBindingManager& InputBindingManager = FInputBindingManager::Get();

	BlueprintAssistHotkeys.Empty();

	TArray<TSharedPtr<FUICommandInfo>> CommandInfos;
	InputBindingManager.GetCommandInfosFromContext("BlueprintAssistCommands", CommandInfos);
	for (TSharedPtr<FUICommandInfo> Command : CommandInfos)
	{
		BlueprintAssistHotkeys.Add(MakeShareable(new FBAHotkeyStruct(Command)));
	}

	
	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(5)
		[
			SNew(SBox)
			.WidthOverride(WidgetSize.X)
			.HeightOverride(WidgetSize.Y)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(2, 2, 2, 5)
				[
					SNew(STextBlock)
					.Text(FText::FromString(FString("Blueprint Assist Hotkeys")))
					.Font(FEditorStyle::GetFontStyle(FName("BlueprintEditor.ActionMenu.ContextDescriptionFont")))
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SNew(SBorder)
	                .BorderImage(FEditorStyle::GetBrush("DetailsView.CategoryMiddle"))
	                .Padding(2)
	                [
						SNew(SListView<TSharedPtr<FBAHotkeyStruct>>)
						.ItemHeight(24)
						.SelectionMode(ESelectionMode::Single)
						.ListItemsSource(&BlueprintAssistHotkeys)
						.OnGenerateRow(this, &SBAHotkeyMenu::CreateItemWidget)
						.IsFocusable(false)
					]
				]
			]
		]
	);
}

TSharedRef<ITableRow> SBAHotkeyMenu::CreateItemWidget(TSharedPtr<FBAHotkeyStruct> Item, const TSharedRef<STableViewBase>& OwnerTable) const
{
	return SNew(STableRow<TSharedPtr<FString>>, OwnerTable).Padding(FMargin(8.0, 4.0))
    [
        SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth()
        [
        	SNew(SVerticalBox)
        	+ SVerticalBox::Slot().AutoHeight()
        	[
        		SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(STextBlock).Text(FText::FromName(Item->CommandName))
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
       				SNew(SSpacer).Size(FVector2D(12.0f, 8.0f))
				]
                + SHorizontalBox::Slot().AutoWidth()
                [
					SNew(STextBlock).Text(Item->CommandChord)
					.Font(FEditorStyle::GetFontStyle(TEXT("PropertyWindow.BoldFont")))
                ]
            ]
            + SVerticalBox::Slot().AutoHeight()
            [
            	SNew(SScrollBox)
            	.Orientation(Orient_Horizontal)
            	+SScrollBox::Slot()
            	[
					SNew(STextBlock).Text(Item->CommandDesc)
					.Font(FEditorStyle::GetFontStyle(TEXT("PropertyWindow.NormalFont")))
                ]
            ]
        ]
    ];
}
