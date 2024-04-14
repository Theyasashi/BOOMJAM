// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "VariableSelectorMenu.h"
#include "EditorStyleSet.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Docking/SDockTab.h"

#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Input/SSearchBox.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "BlueprintAssistUtils.h"

#include "K2Node_Event.h"
#include "BlueprintEditor.h"
#include "BlueprintAssistGraphHandler.h"

#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/Slate/Public/Widgets/Text/SRichTextBlock.h"
#include "Editor/GraphEditor/Public/SGraphActionMenu.h"
#include "Editor/Kismet/Public/SSCSEditor.h"
#include "Editor/PropertyEditor/Public/PropertyPath.h"

void SVariableSelectorMenu::Construct(
	const FArguments& InArgs,
	TSharedPtr<FBAInputProcessor> InEditor)
{
	SuggestionIndex = INDEX_NONE;

	AllItems.Empty();

	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();

	TSet<FString> IgnoredTitles;

	// process SCSEditor
	TArray<TSharedPtr<SWidget>> SCSWidgets;
	TSharedPtr<SWidget> SCSEditorWidget = FBAUtils::GetChildWidget(Window, "SSCSEditor");
	SCSEditor = StaticCastSharedPtr<SSCSEditor>(SCSEditorWidget);

	FBAUtils::GetChildWidgets(Window, "SSCS_RowWidget", SCSWidgets, true);
	for (TSharedPtr<SWidget> Widget : SCSWidgets)
	{
		// add the graph as a symbol
		TSharedPtr<FVariableSelectorStruct> VarSelector = MakeShareable(
			new FVariableSelectorStruct(Widget, true));
		if (IgnoredTitles.Contains(VarSelector->ToString()))
			continue;

		AllItems.Add(VarSelector);
		IgnoredTitles.Add(VarSelector->ToString());
	}

	// process GraphActionMenu
	TSharedPtr<SWidget> ActionMenuWidget = FBAUtils::GetChildWidget(Window, "SGraphActionMenu");
	if (!ActionMenuWidget.IsValid())
		return;
	ActionMenu = StaticCastSharedPtr<SGraphActionMenu>(ActionMenuWidget);

	TSharedPtr<SWidget> WidgetToSearchThrough = FBAUtils::GetChildWidget(
		ActionMenuWidget,
		"SListPanel");

	TArray<TSharedPtr<SWidget>> GraphActionRows;
	FChildren* ListPanelChildren = WidgetToSearchThrough->GetChildren();
	bool bProcessNextRows = false;
	const int NumChildren = ListPanelChildren->Num();
	for (int i = 0; i < NumChildren; i++)
	{
		TSharedPtr<SWidget> Child = ListPanelChildren->GetChildAt(i);
		if (Child->GetTypeAsString() == "SCategoryHeaderTableRow< TSharedPtr<FGraphActionNode> >")
		{
			TSharedPtr<SWidget> HeaderText = FBAUtils::GetChildWidget(
				Child,
				"SRichTextBlock",
				true);

			TSharedPtr<SRichTextBlock> TextBlock = StaticCastSharedPtr<SRichTextBlock>(HeaderText);
			if (TextBlock->GetText().ToString() == "Variables")
			{
				bProcessNextRows = true;
			}
			else if (bProcessNextRows)
			{
				break;
			}
		}

		if (bProcessNextRows &&
			Child->GetTypeAsString() == "STableRow< TSharedPtr<FGraphActionNode> >")
		{
			GraphActionRows.Add(Child);
		}
	}

	for (TSharedPtr<SWidget> Widget : GraphActionRows)
	{
		// add the graph as a symbol
		TSharedPtr<FVariableSelectorStruct> VarSelector = MakeShareable(
			new FVariableSelectorStruct(Widget, false));
		if (IgnoredTitles.Contains(VarSelector->ToString()))
			continue;

		AllItems.Add(VarSelector);
		IgnoredTitles.Add(VarSelector->ToString());
	}

	FilteredItems = AllItems;

	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(5)
		[
			SNew(SBox)
			.WidthOverride(400)
			.HeightOverride(400)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(2, 2, 2, 5)
				[
					SNew(STextBlock)
					.Text(FText::FromString(FString("Select variable")))
					.Font(
						                FEditorStyle::GetFontStyle(
							                FName(
								                "BlueprintEditor.ActionMenu.ContextDescriptionFont")))
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox)
					.OnTextChanged(this, &SVariableSelectorMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SVariableSelectorMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SAssignNew(
						FilteredItemsListView,
						SListView<TSharedPtr<FVariableSelectorStruct>>)
					.ItemHeight(24)
					.SelectionMode(ESelectionMode::Single)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SVariableSelectorMenu::CreateItemWidget)
					.OnMouseButtonClick(this, &SVariableSelectorMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(
		FOnKeyDown::CreateSP(this, &SVariableSelectorMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());
}

TSharedRef<ITableRow> SVariableSelectorMenu::CreateItemWidget(
	TSharedPtr<FVariableSelectorStruct> Item,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	return
		SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Left).FillWidth(1)
			[
				SNew(STextBlock).Text(FText::FromString(Item->ToString()))
			]
		];
}

void SVariableSelectorMenu::OnListItemClicked(TSharedPtr<FVariableSelectorStruct> Item)
{
	SelectItem(Item, true);
}

void SVariableSelectorMenu::OnFilterTextChanged(const FText& InFilterText)
{
	// Trim and sanitized the filter text (so that it more likely matches the action descriptions)
	const FString TrimmedFilterString = FText::TrimPrecedingAndTrailing(InFilterText).ToString();

	// Tokenize the search box text into a set of terms; all of them must be present to pass the filter
	TArray<FString> FilterTerms;
	TrimmedFilterString.ParseIntoArray(FilterTerms, TEXT(" "), true);

	FilteredItems.Empty();

	const bool bRequiresFiltering = FilterTerms.Num() > 0;
	for (int32 PinIndex = 0; PinIndex < AllItems.Num(); ++PinIndex)
	{
		TSharedPtr<FVariableSelectorStruct> Item = AllItems[PinIndex];

		// If we're filtering, search check to see if we need to show this action
		bool bShowAction = true;
		if (bRequiresFiltering)
		{
			const FString& SearchText = Item->ToString();

			FString EachTermSanitized;
			for (int32 FilterIndex = 0; FilterIndex < FilterTerms.Num() && bShowAction; ++
			     FilterIndex)
			{
				const bool bMatchesTerm = SearchText.Contains(FilterTerms[FilterIndex]);
				bShowAction = bShowAction && bMatchesTerm;
			}
		}

		if (bShowAction)
		{
			FilteredItems.Add(
				MakeShareable(new FVariableSelectorStruct(Item->Widget, Item->bSSCS)));
		}
	}

	FilteredItemsListView->RequestListRefresh();

	// Make sure the selected suggestion stays within the filtered list
	if (SuggestionIndex >= 0 && FilteredItems.Num() > 0)
	{
		//@TODO: Should try to actually maintain the highlight on the same item if it survived the filtering
		SuggestionIndex = FMath::Clamp<int32>(SuggestionIndex, 0, FilteredItems.Num() - 1);
		MarkActiveSuggestion();
	}
	else
	{
		SuggestionIndex = INDEX_NONE;
	}
}

void SVariableSelectorMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
	}
}

void SVariableSelectorMenu::SelectItem(TSharedPtr<FVariableSelectorStruct> Item, bool bCloseMenu)
{
	if (bCloseMenu)
	{
		FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
	}

	if (Item->bSSCS)
	{
		if (SCSEditor.IsValid())
		{
			SCSEditor->HighlightTreeNode(FName(*Item->ToString()), FPropertyPath());
		}
	}
	else
	{
		if (ActionMenu.IsValid())
		{
			ActionMenu->SelectItemByName(FName(*Item->ToString()), ESelectInfo::OnKeyPress);
		}
	}
}

bool SVariableSelectorMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		SelectItem(FilteredItems[0], true);
		return true;
	}

	return false;
}

void SVariableSelectorMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FVariableSelectorStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);

		SelectItem(ItemToSelect, false);
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SVariableSelectorMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
{
	int32 SelectionDelta = 0;

	const int NumItems = FilteredItems.Num();

	if (KeyEvent.GetKey() == EKeys::Escape)
	{
		FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
		return FReply::Handled();
	}

	if (KeyEvent.GetKey() == EKeys::Enter)
	{
		TArray<TSharedPtr<FVariableSelectorStruct>> SelectedItems;
		FilteredItemsListView->GetSelectedItems(SelectedItems);

		if (SelectedItems.Num() > 0)
		{
			SelectItem(SelectedItems[0], true);
			return FReply::Handled();
		}

		return SelectFirstItem() ? FReply::Handled() : FReply::Unhandled();
	}

	if (NumItems > 0)
	{
		// move up and down through the filtered node list
		if (KeyEvent.GetKey() == EKeys::Up)
		{
			SelectionDelta = -1;
		}
		else if (KeyEvent.GetKey() == EKeys::Down)
		{
			SelectionDelta = +1;
		}

		if (SelectionDelta != 0)
		{
			// If we have no selected suggestion then we need to use the items in the root to set the selection and set the focus
			if (SuggestionIndex == INDEX_NONE)
			{
				SuggestionIndex = (SuggestionIndex + SelectionDelta + NumItems) % NumItems;
				MarkActiveSuggestion();
				return FReply::Handled();
			}

			//Move up or down one, wrapping around
			SuggestionIndex = (SuggestionIndex + SelectionDelta + NumItems) % NumItems;
			MarkActiveSuggestion();

			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

TSharedRef<SEditableTextBox> SVariableSelectorMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}

/***************************/
/* FVariableSelectorStruct */
/***************************/

FString FVariableSelectorStruct::ToString() const
{
	return Title;
}

void FVariableSelectorStruct::GetTitle()
{
	TSharedPtr<SWidget> FoundWidget = FBAUtils::GetChildWidget(Widget, "STextBlock");
	TSharedPtr<STextBlock> TextBlock = StaticCastSharedPtr<STextBlock>(FoundWidget);
	if (TextBlock.IsValid())
	{
		Title = TextBlock->GetText().ToString();
		Title.RemoveFromEnd(" (Inherited)");
	}
	else
	{
		Title = Widget->ToString();
	}
}

TSharedPtr<SWidget> FVariableSelectorStruct::GetWidgetToFocus()
{
	return Widget;
}
