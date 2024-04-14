// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "GoToSettingsMenu.h"
#include "EditorStyleSet.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Layout/SBox.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Views/STreeView.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Input/SSearchBox.h"

#include "BlueprintEditor.h"
#include "ISettingsModule.h"
#include "ISettingsContainer.h"
#include "ISettingsCategory.h"
#include "ISettingsSection.h"

// @TODO: Make this menu use a tree structure

void SGoToSettingsMenu::Construct(const FArguments& InArgs, TSharedPtr<FBAInputProcessor> InEditor)
{
	SuggestionIndex = INDEX_NONE;

	WidgetSize = FVector2D(400.0f, 400.0f);
	
	AllItems.Empty();

	if (FModuleManager::Get().IsModuleLoaded(TEXT("Settings")))
	{
		ISettingsModule& SettingsModule = FModuleManager::LoadModuleChecked<ISettingsModule>("Settings");
		TArray<FName> AllContainers;
		SettingsModule.GetContainerNames(AllContainers);
		for (auto ContainerName : AllContainers)
		{
			TSharedPtr<ISettingsContainer> Container = SettingsModule.GetContainer(ContainerName);
			if (Container.IsValid())
			{
				TArray<TSharedPtr<ISettingsCategory>> AllCategories;
				Container->GetCategories(AllCategories);

				for (auto Category : AllCategories)
				{
					if (Category.IsValid())
					{
						TArray<TSharedPtr<ISettingsSection>> AllSections;
						Category->GetSections(AllSections);

						for (auto Section : AllSections)
						{
							AllItems.Add(MakeShareable(new FGoToSettingsStruct(Container, Category, Section)));
						}
					}
				}
			}
		}
	}
	
	FilteredItems = AllItems;

	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(5)
		[
			SNew(SBox)
			.WidthOverride(WidgetSize.X)
			.HeightOverride(WidgetSize.Y)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(2, 2, 2, 5)
				[
					SNew(STextBlock)
					.Text(FText::FromString(FString("Go to settings")))
					.Font(FEditorStyle::GetFontStyle(FName("BlueprintEditor.ActionMenu.ContextDescriptionFont")))
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SAssignNew(FilterTextBox, SSearchBox)
					.OnTextChanged(this, &SGoToSettingsMenu::OnFilterTextChanged)
					.OnTextCommitted(this, &SGoToSettingsMenu::OnFilterTextCommitted)
				]
				+ SVerticalBox::Slot()
				.FillHeight(1.f)
				[
					SAssignNew(FilteredItemsListView, SListView<TSharedPtr<FGoToSettingsStruct>>)
					.ItemHeight(24)
					.SelectionMode(ESelectionMode::Single)
					.ListItemsSource(&FilteredItems)
					.OnGenerateRow(this, &SGoToSettingsMenu::CreateItemWidget)
					.OnMouseButtonClick(this, &SGoToSettingsMenu::OnListItemClicked)
					.IsFocusable(false)
				]
			]
		]
	);

	FilterTextBox->SetOnKeyDownHandler(FOnKeyDown::CreateSP(this, &SGoToSettingsMenu::OnKeyDown));

	FSlateApplication::Get().SetKeyboardFocus(FilterTextBox.ToSharedRef());
}

TSharedRef<ITableRow> SGoToSettingsMenu::CreateItemWidget(
	TSharedPtr<FGoToSettingsStruct> Item,
	const TSharedRef<STableViewBase>& OwnerTable) const
{
	const FSlateBrush* ContextIcon = Item->GetIcon();

	return
		SNew(STableRow<TSharedPtr<FString>>, OwnerTable)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, ContextIcon != nullptr ? 5 : 0, 0)
			[
				SNew(SImage).Image(ContextIcon)
			]
			+ SHorizontalBox::Slot().AutoWidth().HAlign(HAlign_Left).FillWidth(1).Padding(0, 2)
			[
				SNew(STextBlock).Text(FText::FromString(Item->ToString()))
			]
		];
}

void SGoToSettingsMenu::OnListItemClicked(TSharedPtr<FGoToSettingsStruct> Item)
{
	SelectItem(Item);
}

void SGoToSettingsMenu::OnFilterTextChanged(const FText& InFilterText)
{
	// Trim and sanitized the filter text (so that it more likely matches the action descriptions)
	const FString TrimmedFilterString = FText::TrimPrecedingAndTrailing(InFilterText).ToString();

	// Tokenize the search box text into a set of terms; all of them must be present to pass the filter
	TArray<FString> FilterTerms;
	TrimmedFilterString.ParseIntoArray(FilterTerms, TEXT(" "), true);

	FilteredItems.Empty();

	const bool bRequiresFiltering = FilterTerms.Num() > 0;
	for (int32 ItemIndex = 0; ItemIndex < AllItems.Num(); ++ItemIndex)
	{
		TSharedPtr<FGoToSettingsStruct> Item = AllItems[ItemIndex];

		// If we're filtering, search check to see if we need to show this action
		bool bShowAction = true;
		if (bRequiresFiltering)
		{
			const FString& SearchText = Item->ToString();

			FString EachTermSanitized;
			for (int32 FilterIndex = 0; FilterIndex < FilterTerms.Num() && bShowAction; ++FilterIndex)
			{
				const bool bMatchesTerm = SearchText.Contains(FilterTerms[FilterIndex]);
				bShowAction = bShowAction && bMatchesTerm;
			}
		}

		if (bShowAction)
		{
			FilteredItems.Add(Item);
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

void SGoToSettingsMenu::OnFilterTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
	if (CommitInfo == ETextCommit::OnEnter)
	{
		SelectFirstItem();
	}
}

void SGoToSettingsMenu::SelectItem(TSharedPtr<FGoToSettingsStruct> Item)
{
	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));

	if (FModuleManager::Get().IsModuleLoaded(TEXT("Settings")))
	{
		FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").ShowViewer(
			Item->Container->GetName(), 
			Item->Category->GetName(),
			Item->Section->GetName());
	}
}

bool SGoToSettingsMenu::SelectFirstItem()
{
	if (FilteredItems.Num() > 0)
	{
		SelectItem(FilteredItems[0]);
		return true;
	}

	return false;
}

void SGoToSettingsMenu::MarkActiveSuggestion()
{
	if (SuggestionIndex >= 0)
	{
		TSharedPtr<FGoToSettingsStruct>& ItemToSelect = FilteredItems[SuggestionIndex];
		FilteredItemsListView->SetSelection(ItemToSelect);
		FilteredItemsListView->RequestScrollIntoView(ItemToSelect);
	}
	else
	{
		FilteredItemsListView->ClearSelection();
	}
}

FReply SGoToSettingsMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& KeyEvent)
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
		TArray<TSharedPtr<FGoToSettingsStruct>> SelectedItems;
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

TSharedRef<SEditableTextBox> SGoToSettingsMenu::GetFilterTextBox()
{
	return FilterTextBox.ToSharedRef();
}

/***********************/
/* FGoToSettingsStruct */
/***********************/
FString FGoToSettingsStruct::ToString() const
{
	return FString::Printf(TEXT("%s | %s | %s"), 
		*Container->GetDisplayName().ToString(), 
		*Category->GetDisplayName().ToString(),
		*Section->GetDisplayName().ToString());
}

const FSlateBrush* FGoToSettingsStruct::GetIcon()
{
	const FName& ContainerName = Container->GetName();
	
	if (ContainerName == "Project")
	{
		return FEditorStyle::GetBrush("ProjectSettings.TabIcon");
	}
		
	if (ContainerName == "Editor")
	{
		return FEditorStyle::GetBrush("EditorPreferences.TabIcon");
	}

	return nullptr;
}
