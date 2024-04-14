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

struct FVariableSelectorStruct
{
	TSharedPtr<SWidget> Widget;
	FString Title;
	bool bSSCS = false;

	FVariableSelectorStruct(TSharedPtr<SWidget> InWidget, bool bIsSSCS)
		: Widget(InWidget)
		, bSSCS(bIsSSCS)
	{
		GetTitle();
	}

	FVariableSelectorStruct()
		: Widget(nullptr)
	{
	}

	void GetTitle();

	FString ToString() const;

	TSharedPtr<SWidget> GetWidgetToFocus();

	bool operator==(const FVariableSelectorStruct& Other) const
	{
		return Title != Other.Title;
	}
};

class BLUEPRINTASSIST_API SVariableSelectorMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SVariableSelectorMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

protected:
	TSharedPtr<SWidget> TreeView;
	TSharedPtr<class SGraphActionMenu> ActionMenu;
	TSharedPtr<class SSCSEditor> SCSEditor;

	int32 SuggestionIndex = INDEX_NONE;

	TArray<TSharedPtr<FVariableSelectorStruct>> AllItems;
	TArray<TSharedPtr<FVariableSelectorStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FVariableSelectorStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(
		TSharedPtr<FVariableSelectorStruct> Item,
		const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FVariableSelectorStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FVariableSelectorStruct> Item, bool bCloseMenu);
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
