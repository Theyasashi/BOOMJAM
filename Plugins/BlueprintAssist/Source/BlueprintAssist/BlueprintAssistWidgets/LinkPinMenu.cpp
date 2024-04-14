// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "LinkPinMenu.h"
#include "EditorStyleSet.h"
#include "ScopedTransaction.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Views/STreeView.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Input/SSearchBox.h"

#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"
#include "SGraphPanel.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintAssistSettings.h"
#include "BlueprintAssistGraphHandler.h"

void SLinkPinMenu::Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor)
{
	// read slate args
	GraphHandler = InArgs._GraphHandler;
	SourcePin = InArgs._SourcePin;

	SuggestionIndex = INDEX_NONE;

	// sort pins by output then input
	AllItems.Empty();

	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();

	UEdGraphNode* SourceNode = SourcePin->GetOwningNode();

	TArray<UEdGraphNode*> AllNodes = Graph->Nodes;

	// sort nodes by distance to pin
	const auto Sorter = [SourceNode](UEdGraphNode& NodeA, UEdGraphNode& NodeB)
	{
		const int DistA = FBAUtils::DistanceSquaredBetweenNodes(SourceNode, &NodeA);
		const int DistB = FBAUtils::DistanceSquaredBetweenNodes(SourceNode, &NodeB);
		return DistA < DistB;
	};

	AllNodes.Sort(Sorter);

	// grab pins from the graph for the user to select
	for (UEdGraphNode* Node : AllNodes)
	{
		for (UEdGraphPin* Pin : Node->Pins)
		{
			// skip hidden | pins which we are already linked to | pins we can't connect to
			if (!Pin->bHidden && !SourcePin->LinkedTo.Contains(Pin) && CanConnectSourceToPin(Pin))
			{
				AllItems.Add(Pin);
			}
		}
	}

	FilteredItems.Empty();
	for (UEdGraphPin* Pin : AllItems)
		FilteredItems.Add(MakeShareable(new FPinLinkerStruct(Pin)));

	const FString MenuTitle = FString::Printf(
		TEXT("Select the pin to link to %s"),
		*SourcePin->GetName());

	const FSlateFontInfo FontStyle =
		FEditorStyle::GetFontStyle("BlueprintEditor.ActionMenu.ContextDescriptionFont");

	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(5)
		[
			// Achieving fixed width by nesting items within a fixed width box.
			SNew(SBox)
			.WidthOverride(400)
			.HeightOverride(400)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(2, 2, 2, 5)
				[
					SNew(STextBlock) // menu title
					.Text(FText::FromString(MenuTitle))
					.Font(FontStyle)
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox) // filter box
					.OnTextChanged(this, &SLinkPinMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SLinkPinMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SAssignNew(
						FilteredItemsListView,
						SListView<TSharedPtr<FPinLinkerStruct>>) // list of pins
					.ItemHeight(24)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SLinkPinMenu::CreateItemWidget)
					.SelectionMode(ESelectionMode::Single)
					.OnMouseButtonClick(this, &SLinkPinMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(FOnKeyDown::CreateSP(this, &SLinkPinMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());

	float OutZoom;
	GraphHandler->GetGraphEditor()->GetViewLocation(SavedLocation, OutZoom);
}

TSharedRef<ITableRow> SLinkPinMenu::CreateItemWidget(
	TSharedPtr<FPinLinkerStruct> Item,
	const TSharedRef<STableViewBase>& OwnerTable)
{
	UEdGraphPin* Pin = Item->Pin;

	const UEdGraphSchema* Schema = Pin->GetSchema();

	// Get the type color and icon
	const FSlateColor TypeColor = Schema->GetPinTypeColor(Pin->PinType);

	const FSlateBrush* ContextIcon = FBlueprintEditorUtils::GetIconFromPin(Item->Pin->PinType);

	const FString PinName = Pin->GetName();

	const FString OwningNodeName = FBAUtils::GetNodeName(Pin->GetOwningNode());

	const FString ItemName = FString::Printf(TEXT("%s (%s)"), *PinName, *OwningNodeName);

	return
		SNew(STableRow< TSharedPtr<FString>>, OwnerTable)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			  .AutoWidth()
			  .VAlign(VAlign_Center)
			  .Padding(0, 0, (ContextIcon != nullptr) ? 5 : 0, 0)
			[
				SNew(SImage)
				.ColorAndOpacity(TypeColor)
				.Image(ContextIcon)
			]
			+ SHorizontalBox::Slot().FillWidth(1).Padding(0, 2)
			[
				SNew(STextBlock)
				.Text(FText::FromString(ItemName))
			]
		];
}

void SLinkPinMenu::OnListItemClicked(TSharedPtr<FPinLinkerStruct> Item)
{
	LinkSourceToTarget(Item->Pin);
	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
}

void SLinkPinMenu::OnFilterTextChanged(const FText& InFilterText)
{
	// Trim and sanitized the filter text (so that it more likely matches the action descriptions)
	const FString TrimmedFilterString = FText::TrimPrecedingAndTrailing(InFilterText).ToString();

	// Tokenize the search box text into a set of terms; all of them must be present to pass the filter
	TArray<FString> FilterTerms;
	TrimmedFilterString.ParseIntoArray(FilterTerms, TEXT(" "), true);

	FilteredItems.Empty();

	// Filter all pins based on the filter terms and add them to filtered items
	const bool bRequiresFiltering = FilterTerms.Num() > 0;
	for (int32 PinIndex = 0; PinIndex < AllItems.Num(); ++PinIndex)
	{
		UEdGraphPin* CurrentPin = AllItems[PinIndex];

		if (CurrentPin->bHidden)
			continue;

		// If we're filtering, search check to see if we need to show this action
		bool bShowAction = true;
		if (bRequiresFiltering)
		{
			const FString OwningNodeName = FBAUtils::GetNodeName(CurrentPin->GetOwningNode());
			const FString SearchText = CurrentPin->GetName() + " " + OwningNodeName;

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
			FilteredItems.Add(MakeShareable(new FPinLinkerStruct(CurrentPin)));
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

void SLinkPinMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
		FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
	}
}

void SLinkPinMenu::LinkSourceToTarget(UEdGraphPin* TargetPin) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "LinkPinMenu", "Link Pin (Menu)"));

	FBAUtils::TryLinkPins(SourcePin, TargetPin);

	GraphHandler->BeginLerpViewport(SavedLocation, false);
}

bool SLinkPinMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		LinkSourceToTarget(FilteredItems[0]->Pin);
		return true;
	}

	return false;
}

void SLinkPinMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FPinLinkerStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);

		UEdGraphNode* ActiveNode = ItemToSelect->Pin->GetOwningNode();

		if (!FBAUtils::IsNodeVisible(GraphHandler->GetGraphPanel(), ActiveNode))
		{
			GraphHandler->BeginLerpViewport(FVector2D(ActiveNode->NodePosX, ActiveNode->NodePosY));
		}
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SLinkPinMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
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
		TArray<TSharedPtr<FPinLinkerStruct>> SelectedItems;
		FilteredItemsListView->GetSelectedItems(SelectedItems);

		FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));

		if (SelectedItems.Num() > 0)
		{
			LinkSourceToTarget(SelectedItems[0]->Pin);
			return FReply::Handled();
		}

		return SelectFirstItem() ? FReply::Handled() : FReply::Unhandled();
	}

	if (NumItems > 0)
	{
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

			// Move up or down one, wrapping around
			SuggestionIndex = (SuggestionIndex + SelectionDelta + NumItems) % NumItems;
			MarkActiveSuggestion();

			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

bool SLinkPinMenu::CanConnectSourceToPin(UEdGraphPin* Pin)
{
	const UEdGraphSchema* Schema = Pin->GetSchema();
	const FPinConnectionResponse Response = Schema->CanCreateConnection(SourcePin, Pin);
	return Response.Response != CONNECT_RESPONSE_DISALLOW;
	// && Response.Response != CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE;
}

TSharedPtr<SEditableTextBox> SLinkPinMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}

void SLinkPinMenu::Tick(
	const FGeometry& AllottedGeometry,
	const double InCurrentTime,
	const float InDeltaTime)
{
	if (FilteredItems.IsValidIndex(SuggestionIndex))
	{
		TSharedPtr<FPinLinkerStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		if (ItemToSelect.IsValid())
		{
			TSharedPtr<SGraphPin> GraphPin = GraphHandler->GetGraphPin(ItemToSelect->Pin);
			if (GraphPin.IsValid())
			{
				GraphPin->SetPinColorModifier(GetMutableDefault<UBASettings>()->PinHighlightColor);
			}
		}
	}
}
