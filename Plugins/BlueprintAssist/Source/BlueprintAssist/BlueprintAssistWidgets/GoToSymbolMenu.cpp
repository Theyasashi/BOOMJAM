// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "GoToSymbolMenu.h"
#include "EditorStyleSet.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Layout/SBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Views/STreeView.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Input/SSearchBox.h"

#include "EdGraph/EdGraphNode.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "BlueprintAssistUtils.h"

#include "EdGraph/EdGraph.h"
#include "K2Node_Event.h"
#include "Engine/Blueprint.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "EdGraph/EdGraphSchema.h"
#include "BlueprintEditor.h"
#include "BlueprintAssistGraphHandler.h"
#include "K2Node_Composite.h"

void SGoToSymbolMenu::Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor)
{
	GraphHandler = InArgs._GraphHandler;
	NodeLocation = InArgs._NodeLocation;
	MenuLocation = InArgs._MenuLocation;

	UBlueprint* Blueprint = GraphHandler->GetBlueprint();
	check(Blueprint)

	SuggestionIndex = INDEX_NONE;

	TArray<UEdGraph*> BlueprintGraphs;
	Blueprint->GetAllGraphs(BlueprintGraphs);

	AllItems.Empty();

	for (UEdGraph* Graph : BlueprintGraphs)
	{
		const EGraphType GraphType = FBAUtils::GetGraphType(Graph);

		if (Blueprint->DelegateSignatureGraphs.Contains(Graph))
			continue;

		// add all event nodes on the graph for ubergraphs
		if (GraphType == GT_Ubergraph)
		{
			TArray<UEdGraphNode*> EventNodes;
			Graph->GetNodesOfClass(EventNodes);

			EventNodes = EventNodes.FilterByPredicate(
				[](UEdGraphNode* Node)
				{
					return Cast<UK2Node_Event>(Node) || FBAUtils::IsInputNode(Node) || Cast<UK2Node_Composite>(Node);
				});

			for (UEdGraphNode* Node : EventNodes)
			{
				AllItems.Add(MakeShareable(new FGoToSymbolStruct(Node, Graph)));
			}
		}

		// add the graph as a symbol
		AllItems.Add(MakeShareable(new FGoToSymbolStruct(nullptr, Graph)));
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
					.Text(FText::FromString(FString("Go to symbol")))
					.Font(FEditorStyle::GetFontStyle(FName("BlueprintEditor.ActionMenu.ContextDescriptionFont")))
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox)
					.OnTextChanged(this, &SGoToSymbolMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SGoToSymbolMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot()
				.FillHeight(1.f)
				[
					SAssignNew(FilteredItemsListView, SListView<TSharedPtr<FGoToSymbolStruct>>)
					.ItemHeight(24)
					.SelectionMode(ESelectionMode::Single)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SGoToSymbolMenu::CreateItemWidget)
					.OnMouseButtonClick(this, &SGoToSymbolMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(FOnKeyDown::CreateSP(this, &SGoToSymbolMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());
}

TSharedRef<ITableRow> SGoToSymbolMenu::CreateItemWidget(
	TSharedPtr<FGoToSymbolStruct> Item,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	FLinearColor IconColor = FLinearColor::White;

	const FSlateBrush* ContextIcon
		= Item->EventNode != nullptr
		? Item->EventNode->GetIconAndTint(IconColor).GetIcon() // get icon from node
		: FBlueprintEditor::GetGlyphForGraph(Item->Graph); // get icon from graph

	const FString OptionalGraphName
		= Item->EventNode != nullptr
		? Item->Graph->GetName()
		: "";

	return
		SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, ContextIcon != nullptr ? 5 : 0, 0)
			[
				SNew(SImage).ColorAndOpacity(IconColor).Image(ContextIcon)
			]
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Left).FillWidth(1).Padding(0, 2)
			[
				SNew(STextBlock).Text(FText::FromString(Item->ToString()))
			]
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Right)
			[
				SNew(SBox).WidthOverride(100)
				[
					SNew(STextBlock).Text(FText::FromString(Item->GetTypeDescription()))
				]
			]
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Right)
			[
				SNew(SBox).WidthOverride(100)
				[
					SNew(STextBlock).Text(FText::FromString(OptionalGraphName))
				]
			]
		];
}

void SGoToSymbolMenu::OnListItemClicked(TSharedPtr<FGoToSymbolStruct> Item)
{
	SelectItem(Item);
}

void SGoToSymbolMenu::OnFilterTextChanged(const FText& InFilterText)
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
		TSharedPtr<FGoToSymbolStruct> Pin = AllItems[PinIndex];

		// If we're filtering, search check to see if we need to show this action
		bool bShowAction = true;
		if (bRequiresFiltering)
		{
			const FString& SearchText = Pin->ToString() + " " + Pin->GetTypeDescription();

			FString EachTermSanitized;
			for (int32 FilterIndex = 0; FilterIndex < FilterTerms.Num() && bShowAction; ++FilterIndex)
			{
				const bool bMatchesTerm = SearchText.Contains(FilterTerms[FilterIndex]);
				bShowAction = bShowAction && bMatchesTerm;
			}
		}

		if (bShowAction)
		{
			FilteredItems.Add(MakeShareable(new FGoToSymbolStruct(Pin->EventNode, Pin->Graph)));
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

void SGoToSymbolMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
	}
}

void SGoToSymbolMenu::SelectItem(TSharedPtr<FGoToSymbolStruct> Item)
{
	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));

	const EGraphType GraphType = FBAUtils::GetGraphType(Item->Graph);

	if (Item->Graph == nullptr)
		return;

	if (GraphType == GT_Ubergraph)
	{
		UEdGraph* CurrentGraph = GraphHandler->GetFocusedEdGraph();

		// if we selected an event node
		if (Item->EventNode != nullptr)
		{
			if (CurrentGraph == Item->Graph) // if we are already on the same graph
			{
				const FSlateRect NodeBounds = FBAUtils::GetCachedNodeBounds(
					GraphHandler,
					Item->EventNode);

				// lerp the graph
				GraphHandler->BeginLerpViewport(NodeBounds.GetCenter(), true);

				// select the node
				TSet<const UEdGraphNode*> NodeSet;
				NodeSet.Add(Item->EventNode);
				CurrentGraph->SelectNodeSet(NodeSet);
			}
			else // move to the other graph and select the node
			{
				FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Item->EventNode, false);
			}

			return; // we should have focused the node, exit here
		}
	}

	// open the graph
	FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Item->Graph, false);
}

bool SGoToSymbolMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		SelectItem(FilteredItems[0]);
		return true;
	}

	return false;
}

void SGoToSymbolMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FGoToSymbolStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SGoToSymbolMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
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
		TArray<TSharedPtr<FGoToSymbolStruct>> SelectedItems;
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

TSharedRef<SEditableTextBox> SGoToSymbolMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}

/*****************/
/* FSymbolStruct */
/*****************/
FString FGoToSymbolStruct::ToString() const
{
	return EventNode != nullptr
		? FBAUtils::GetNodeName(EventNode)
		: Graph->GetName();
}

FString FGoToSymbolStruct::GetTypeDescription() const
{
	return EventNode != nullptr
		? FString("Event")
		: FBAUtils::GraphTypeToString(FBAUtils::GetGraphType(Graph));
}
