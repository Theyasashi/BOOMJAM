// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "AddSymbolMenu.h"
#include "EditorStyleSet.h"
#include "Widgets/Layout/SBox.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Input/SSearchBox.h"
#include "EdGraph/EdGraphNode.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintEditor.h"
#include "BlueprintAssistGraphHandler.h"

#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Editor/Kismet/Public/SSCSEditor.h"

void SAddSymbolMenu::Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor, TSharedPtr<SWidget> WidgetToSearchThrough)
{
	SuggestionIndex = INDEX_NONE;

	AllItems.Empty();

	TArray<TSharedPtr<SWidget>> ActionButtons;
	FChildren* ListPanelChildren = WidgetToSearchThrough->GetChildren();
	int NumChildren = ListPanelChildren->Num();
	for (int i = 0; i < NumChildren; i++)
	{
		TSharedPtr<SWidget> Child = ListPanelChildren->GetChildAt(i);
		if (Child->GetTypeAsString() == "SCategoryHeaderTableRow< TSharedPtr<FGraphActionNode> >")
		{
			ActionButtons.Add(Child);
		}
	}

	for (TSharedPtr<SWidget> Widget : ActionButtons)
	{
		// add the graph as a symbol
		TSharedPtr<FAddSymbolStruct> AddSymbolStruct = MakeShareable(new FAddSymbolStruct(Widget));
		AllItems.Add(AddSymbolStruct);
	}

	// also search for the "Add Components" button
	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (Window.IsValid())
	{
		TSharedPtr<SWidget> AddComponentsButton = FBAUtils::GetChildWidget(Window, "SComponentClassCombo");
		if (AddComponentsButton.IsValid())
		{
			TSharedPtr<FAddSymbolStruct> AddSymbolStruct = MakeShareable(new FAddSymbolStruct(AddComponentsButton));
			AllItems.Add(AddSymbolStruct);
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
					.Text(FText::FromString(FString("Add Symbol")))
					.Font(FontInfo)
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox)
					.OnTextChanged(this, &SAddSymbolMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SAddSymbolMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SAssignNew(FilteredItemsListView, SListView<TSharedPtr<FAddSymbolStruct>>)
					.ItemHeight(24)
					.SelectionMode(ESelectionMode::Single)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SAddSymbolMenu::CreateItemWidget)
					.OnMouseButtonClick(this, &SAddSymbolMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(FOnKeyDown::CreateSP(this, &SAddSymbolMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());
}

TSharedRef<ITableRow> SAddSymbolMenu::CreateItemWidget(
	TSharedPtr<FAddSymbolStruct> Item,
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

void SAddSymbolMenu::OnListItemClicked(TSharedPtr<FAddSymbolStruct> Item)
{
	SelectItem(Item);
}

void SAddSymbolMenu::OnFilterTextChanged(const FText& InFilterText)
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
		TSharedPtr<FAddSymbolStruct> Item = AllItems[PinIndex];

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
			FilteredItems.Add(MakeShareable(new FAddSymbolStruct(Item->Widget)));
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

void SAddSymbolMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
	}
}

void SAddSymbolMenu::SelectItem(TSharedPtr<FAddSymbolStruct> Item)
{
	FBAUtils::InteractWithWidget(Item->GetWidgetToFocus());

	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
}

bool SAddSymbolMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		SelectItem(FilteredItems[0]);
		return true;
	}

	return false;
}

void SAddSymbolMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FAddSymbolStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SAddSymbolMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
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
		TArray<TSharedPtr<FAddSymbolStruct>> SelectedItems;
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

TSharedRef<SEditableTextBox> SAddSymbolMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}

/********************/
/* FAddSymbolStruct */
/********************/

FString FAddSymbolStruct::ToString() const
{
	return Title;
}

void FAddSymbolStruct::GetTitle()
{
	TArray<TSharedPtr<SWidget>> Widgets;
	FBAUtils::GetChildWidgets(GetWidgetToFocus(), "STextBlock", Widgets);
	for (auto FoundWidget : Widgets)
	{
		TSharedPtr<STextBlock> TextBlock = StaticCastSharedPtr<STextBlock>(FoundWidget);
		if (TextBlock.IsValid())
		{
			FString WidgetText = TextBlock->GetText().ToString();
			if (WidgetText.Len() > 1)
			{
				Title = WidgetText;
				return;
			}
		}
	}

	Title = Widget->ToString();
}

TSharedPtr<SWidget> FAddSymbolStruct::GetWidgetToFocus()
{
	TArray<TSharedPtr<SWidget>> PendingWidgets;
	PendingWidgets.Add(Widget);

	// grab the button from the category header (SCategoryHeaderTableRow)
	while (PendingWidgets.Num() > 0)
	{
		TSharedPtr<SWidget> Current = PendingWidgets.Pop();
		FChildren* Children = Current->GetChildren();
		for (int i = 0; i < Children->Num(); i++)
		{
			TSharedPtr<SWidget> Child = Children->GetChildAt(i);
			if (Child->GetTypeAsString() == "SButton" && Child->GetParentWidget()->GetTypeAsString()
				== "SHorizontalBox")
				return Child;

			PendingWidgets.Add(Child);
		}
	}

	return Widget;

	//return FBlueprintAssistUtils::FindChildWidget(Widget, "SButton", true);
	//ActionButtons.Add(ButtonWidget);
	//return Widget;
}
