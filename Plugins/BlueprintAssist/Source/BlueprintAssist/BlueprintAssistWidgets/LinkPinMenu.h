// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "EdGraph/EdGraphNode.h"
#include "Widgets/Views/SListView.h"

class FBAGraphHandler;
class FBAInputProcessor;
class SBlueprintContextTargetMenu;
class SEditableTextBox;
class UEdGraph;
class UEdGraphNode;
class UEdGraphPin;

struct FBlueprintActionContext;
struct FCustomExpanderData;

class ITableRow;
class SGraphPanel;
class SSearchBox;

struct FPinLinkerStruct
{
	UEdGraphPin* Pin;

	FPinLinkerStruct(UEdGraphPin* InPin)
		: Pin(InPin)
	{
	}
};

class BLUEPRINTASSIST_API SLinkPinMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SLinkPinMenu)
			: _GraphHandler(TSharedPtr<FBAGraphHandler>())
			, _SourcePin(nullptr)
	{
	}

	SLATE_ARGUMENT(TSharedPtr<FBAGraphHandler>, GraphHandler)
	SLATE_ARGUMENT(UEdGraphPin*, SourcePin)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

protected:
	int32 SuggestionIndex = INDEX_NONE;
	TSharedPtr<FBAGraphHandler> GraphHandler;
	UEdGraphPin* SourcePin = nullptr;

	FVector2D SavedLocation;

	TArray<UEdGraphPin*> AllItems;
	TArray<TSharedPtr<FPinLinkerStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FPinLinkerStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(
		TSharedPtr<FPinLinkerStruct> Item,
		const TSharedRef<STableViewBase>& OwnerTable);

	void OnListItemClicked(TSharedPtr<FPinLinkerStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void LinkSourceToTarget(UEdGraphPin* Pin) const;
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

	bool CanConnectSourceToPin(UEdGraphPin* Pin);

public:
	TSharedPtr<SEditableTextBox> GetFilterTextBox();

	void Tick(
		const FGeometry& AllottedGeometry,
		const double InCurrentTime,
		const float InDeltaTime) override;
};
