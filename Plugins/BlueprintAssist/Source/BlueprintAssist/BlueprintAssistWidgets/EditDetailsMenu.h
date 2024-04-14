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

struct FEditDetailsStruct
{
	TSharedPtr<SWidget> Widget;
	FString DetailName;
	bool bClickInsteadOfFocusing = false;

	FEditDetailsStruct(TSharedPtr<SWidget> InWidget, FString InDetailName)
		: Widget(InWidget)
		, DetailName(InDetailName)
	{
	}
};

class BLUEPRINTASSIST_API SEditDetailsMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SEditDetailsMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

protected:
	int32 SuggestionIndex = INDEX_NONE;

	TArray<TSharedPtr<FEditDetailsStruct>> AllItems;
	TArray<TSharedPtr<FEditDetailsStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FEditDetailsStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(
		TSharedPtr<FEditDetailsStruct> Item,
		const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FEditDetailsStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FEditDetailsStruct> Item);
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
