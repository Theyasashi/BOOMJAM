// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "EdGraph/EdGraphNode.h"
#include "Widgets/Views/SListView.h"

class ISettingsContainer;
class ISettingsCategory;
class ISettingsSection;
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

struct FGoToSettingsStruct
{
	TSharedPtr<ISettingsContainer> Container;
	TSharedPtr<ISettingsCategory> Category;
	TSharedPtr<ISettingsSection> Section;
	
	FGoToSettingsStruct(TSharedPtr<ISettingsContainer> InContainer, TSharedPtr<ISettingsCategory> InCategory, TSharedPtr<ISettingsSection> InSection)
		: Container(InContainer)
		, Category(InCategory)
		, Section(InSection)
	{
	}

	FString ToString() const;

	const FSlateBrush* GetIcon();
};

class BLUEPRINTASSIST_API SGoToSettingsMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SGoToSettingsMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor);

public:
	FVector2D WidgetSize;
	
protected:
	int32 SuggestionIndex = INDEX_NONE;
	TArray<TSharedPtr<FGoToSettingsStruct>> AllItems;
	TArray<TSharedPtr<FGoToSettingsStruct>> FilteredItems;
	TSharedPtr<SSearchBox> FilterTextBox;
	TSharedPtr<SListView<TSharedPtr<FGoToSettingsStruct>>> FilteredItemsListView;

	TSharedRef<ITableRow> CreateItemWidget(TSharedPtr<FGoToSettingsStruct> Item, const TSharedRef<STableViewBase>& OwnerTable) const;

	void OnListItemClicked(TSharedPtr<FGoToSettingsStruct> Item);

	/** Called when filter text changes */
	void OnFilterTextChanged(const FText& InFilterText);

	/** Called when enter is hit in search box */
	void OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	void SelectItem(TSharedPtr<FGoToSettingsStruct> Item);
	bool SelectFirstItem();

	void MarkActiveSuggestion();

	// SWidget interface
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent) override;
	// End of SWidget interface

public:
	TSharedRef<SEditableTextBox> GetFilterTextBox();
};
