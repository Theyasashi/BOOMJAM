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
class SDockTab;

struct FSearchBoxStruct
{
	TSharedPtr<SWidget> Widget;
	TSharedPtr<SDockTab> DockTab;

	FSearchBoxStruct(TSharedPtr<SWidget> InWidget, TSharedPtr<SDockTab> InDockTab)
		: Widget(InWidget)
		, DockTab(InDockTab)
	{
	}

	FString ToString() const;

	FString GetTabLabel() const;
};

class BLUEPRINTASSIST_API SFocusSearchBoxMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SFocusSearchBoxMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

protected:
	int32 SuggestionIndex = INDEX_NONE;

	TArray<TSharedPtr<FSearchBoxStruct>> AllItems;
	TArray<TSharedPtr<FSearchBoxStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FSearchBoxStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(
		TSharedPtr<FSearchBoxStruct> Item,
		const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FSearchBoxStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FSearchBoxStruct> Item);
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
