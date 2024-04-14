// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "EditDetailsMenu.h"
#include "EditorStyleSet.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Docking/SDockTab.h"

#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "EdGraph/EdGraphNode.h"
#include "Widgets/Input/SSearchBox.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "BlueprintAssistUtils.h"

#include "BlueprintEditor.h"
#include "BlueprintAssistGraphHandler.h"

void SEditDetailsMenu::Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor)
{
	SuggestionIndex = INDEX_NONE;

	AllItems.Empty();

	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();

	TArray<TSharedPtr<SWidget>> ItemRows;
	FBAUtils::GetChildWidgets(Window, "SDetailSingleItemRow", ItemRows);

	for (TSharedPtr<SWidget> Row : ItemRows)
	{
		TSharedPtr<SWidget> FoundWidget = FBAUtils::GetChildWidget(Row, "STextBlock");
		TSharedPtr<STextBlock> TextBlock = StaticCastSharedPtr<STextBlock>(FoundWidget);
		FString WidgetText = TextBlock->GetText().ToString();

		TSharedPtr<SWidget> FoundSplitter = FBAUtils::GetChildWidget(Row, "SSplitter");
		TSharedPtr<SSplitter> Splitter = StaticCastSharedPtr<SSplitter>(FoundSplitter);

		if (Splitter.IsValid())
		{
			FChildren* SplitterChildren = Splitter->GetChildren();
			if (SplitterChildren->Num() >= 2)
			{
				TSharedPtr<SWidget> WidgetToSearch = SplitterChildren->GetChildAt(1);
				TSharedPtr<SWidget> Interactable = FBAUtils::GetInteractableChildWidget(
					WidgetToSearch);

				if (Interactable.IsValid() && Interactable->GetParentWidget()->GetTypeAsString() !=
					"SResetToDefaultPropertyEditor")
				{
					AllItems.Add(MakeShareable(new FEditDetailsStruct(Interactable, WidgetText)));
				}
			}
		}
	}

	FilteredItems = AllItems;

	const FSlateFontInfo FontInfo =
		FEditorStyle::GetFontStyle(FName("BlueprintEditor.ActionMenu.ContextDescriptionFont"));

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
					.Text(FText::FromString(FString("Edit Details")))
					.Font(FontInfo)
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox)
					.OnTextChanged(this, &SEditDetailsMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SEditDetailsMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SAssignNew(FilteredItemsListView, SListView<TSharedPtr<FEditDetailsStruct>>)
					.ItemHeight(24)
					.SelectionMode(ESelectionMode::Single)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SEditDetailsMenu::CreateItemWidget)
					.OnMouseButtonClick(this, &SEditDetailsMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(FOnKeyDown::CreateSP(this, &SEditDetailsMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());
}

TSharedRef<ITableRow> SEditDetailsMenu::CreateItemWidget(
	TSharedPtr<FEditDetailsStruct> Item,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	return
		SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Left).FillWidth(1)
			[
				SNew(STextBlock).Text(FText::FromString(Item->DetailName))
			]
		];
}

void SEditDetailsMenu::OnListItemClicked(TSharedPtr<FEditDetailsStruct> Item)
{
	SelectItem(Item);
}

void SEditDetailsMenu::OnFilterTextChanged(const FText& InFilterText)
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
		TSharedPtr<FEditDetailsStruct> Item = AllItems[PinIndex];

		// If we're filtering, search check to see if we need to show this action
		bool bShowAction = true;
		if (bRequiresFiltering)
		{
			const FString& SearchText = Item->DetailName;

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
				MakeShareable(new FEditDetailsStruct(Item->Widget, Item->DetailName)));
		}
	}

	FilteredItemsListView->RequestListRefresh();

	// Make sure the selected suggestion stays within the filtered list
	if (SuggestionIndex >= 0 && FilteredItems.Num() > 0)
	{
		SuggestionIndex = FMath::Clamp<int32>(SuggestionIndex, 0, FilteredItems.Num() - 1);
		MarkActiveSuggestion();
	}
	else
	{
		SuggestionIndex = INDEX_NONE;
	}
}

void SEditDetailsMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
	}
}

void SEditDetailsMenu::SelectItem(TSharedPtr<FEditDetailsStruct> Item)
{
	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));

	if (Item->Widget.IsValid())
	{
		FBAUtils::InteractWithWidget(Item->Widget);
	}
}

bool SEditDetailsMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		SelectItem(FilteredItems[0]);
		return true;
	}

	return false;
}

void SEditDetailsMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FEditDetailsStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SEditDetailsMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
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
		TArray<TSharedPtr<FEditDetailsStruct>> SelectedItems;
		FilteredItemsListView->GetSelectedItems(SelectedItems);

		if (SelectedItems.Num() > 0)
		{
			SelectItem(SelectedItems[0]);
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

TSharedRef<SEditableTextBox> SEditDetailsMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}
