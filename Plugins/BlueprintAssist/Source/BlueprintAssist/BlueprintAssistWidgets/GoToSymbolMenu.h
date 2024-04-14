// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "EdGraph/EdGraphNode.h"
#include "Widgets/Views/SListView.h"

class FBAInputProcessor;
class FBAGraphHandler;
class SBlueprintContextTargetMenu;
class SEditableTextBox;
class UEdGraph;
class UEdGraphNode;

struct FBlueprintActionContext;
struct FCustomExpanderData;

class ITableRow;
class SGraphPanel;
class SSearchBox;
class UK2Node_Event;
class UBlueprint;

struct FGoToSymbolStruct
{
	UEdGraphNode* EventNode;
	UEdGraph* Graph;

	FGoToSymbolStruct(UEdGraphNode* InEventNode, UEdGraph* InGraph)
		: EventNode(InEventNode)
		, Graph(InGraph)
	{
	}

	FGoToSymbolStruct()
		: EventNode(nullptr)
		, Graph(nullptr)
	{
	}

	FString ToString() const;

	FString GetTypeDescription() const;
};

class BLUEPRINTASSIST_API SGoToSymbolMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SGoToSymbolMenu)
		: _GraphHandler(TSharedPtr<FBAGraphHandler>())
		, _NodeLocation(FVector2D::ZeroVector)
		, _MenuLocation(FVector2D::ZeroVector)
	{
	}

	SLATE_ARGUMENT(TSharedPtr<FBAGraphHandler>, GraphHandler)
	SLATE_ARGUMENT(FVector2D, NodeLocation)
	SLATE_ARGUMENT(FVector2D, MenuLocation)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

protected:
	int32 SuggestionIndex = INDEX_NONE;
	TSharedPtr<FBAGraphHandler> GraphHandler;
	FVector2D NodeLocation;
	FVector2D MenuLocation;

	TArray<TSharedPtr<FGoToSymbolStruct>> AllItems;
	TArray<TSharedPtr<FGoToSymbolStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FGoToSymbolStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(TSharedPtr<FGoToSymbolStruct> Item, const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FGoToSymbolStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FGoToSymbolStruct> Item);
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
