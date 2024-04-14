// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/Views/SListView.h"

class FBAInputProcessor;
class FBAGraphHandler;
class SBlueprintContextTargetMenu;
class SEditableTextBox;
class UEdGraph;
class UEdGraphNode;
class SWidget;

struct FBlueprintActionContext;
struct FCustomExpanderData;

class ITableRow;
class SGraphPanel;
class SSearchBox;
class UK2Node_Event;
class UBlueprint;

struct FAddSymbolStruct
{
	TSharedPtr<SWidget> Widget;
	FString Title;

	FAddSymbolStruct(TSharedPtr<SWidget> InWidget) : Widget(InWidget)
	{
		GetTitle();
	}

	FAddSymbolStruct()
		: Widget(nullptr)
	{
	}

	void GetTitle();

	FString ToString() const;

	TSharedPtr<SWidget> GetWidgetToFocus();

	bool operator==(const FAddSymbolStruct& Other) const
	{
		return Title != Other.Title;
	}
};

class BLUEPRINTASSIST_API SAddSymbolMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SAddSymbolMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor, TSharedPtr<SWidget> WidgetToSearchThrough);

protected:
	int32 SuggestionIndex = INDEX_NONE;

	TArray<TSharedPtr<FAddSymbolStruct>> AllItems;
	TArray<TSharedPtr<FAddSymbolStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FAddSymbolStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(
		TSharedPtr<FAddSymbolStruct> Item,
		const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FAddSymbolStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FAddSymbolStruct> Item);

	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;

	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
