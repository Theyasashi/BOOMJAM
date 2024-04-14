// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistTabHandler.h"

#include "Framework/Application/SlateApplication.h"
#include "Widgets/Docking/SDockTab.h"
#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistUtils.h"

// #include "NiagaraEditor/Private/Widgets/SNiagaraScriptGraph.h"

#include "BlueprintAssistModule.h"

FBATabHandler::FBATabHandler()
{
	if (FSlateApplication::IsInitialized())
	{
		TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();

		// Add delegate for active tab changed
		const auto& ActiveTabChangedDelegate = FOnActiveTabChanged::FDelegate::CreateRaw(this, &FBATabHandler::OnActiveTabChanged);
		OnActiveTabChangedDelegateHandle = TabManager->OnActiveTabChanged_Subscribe(ActiveTabChangedDelegate);

		// Add delegate for tab foregrounded
		const auto& TabForegroundedDelegate = FOnActiveTabChanged::FDelegate::CreateRaw(this, &FBATabHandler::OnTabForegrounded);
		OnTabForegroundedDelegateHandle = TabManager->OnTabForegrounded_Subscribe(TabForegroundedDelegate);
	}
	else
	{
		UE_LOG(LogBlueprintAssist, Error, TEXT("FBlueprintAssistTabHandler::Constructor: SlateApp is not initialized"));
	}
}

void FBATabHandler::Tick(const float DeltaTime)
{
	if (ProcessTabsDelay > 0)
	{
		ProcessTabsDelay -= 1;
		return;
	}

	RemoveInvalidTabs();

	ProcessTabs();

	if (ActiveGraphHandler.IsValid())
	{
		ActiveGraphHandler.Pin()->Tick(DeltaTime);
	}
}

FBATabHandler::~FBATabHandler()
{
	ActiveGraphHandler.Reset();
	GraphHandlerMap.Empty();
	TabsToProcess.Empty();
}

void FBATabHandler::OnTabForegrounded(TSharedPtr<SDockTab> NewTab, TSharedPtr<SDockTab> PreviousTab)
{
	if (!NewTab.IsValid())
		return;

	// UE_LOG(LogTemp, Warning, TEXT("Tab foregrounded: %s %d"), *NewTab->GetTabLabel().ToString(), NewTab->GetTabRole());

	TWeakPtr<SDockTab> NewTabObserver(NewTab);
	TabsToProcess.Emplace(NewTabObserver);
	ProcessTabsDelay = 1;
}

void FBATabHandler::OnActiveTabChanged(TSharedPtr<SDockTab> PreviousTab, TSharedPtr<SDockTab> NewTab)
{
	if (!NewTab.IsValid())
		return;

	// UE_LOG(LogTemp, Warning, TEXT("Active tab changed: %s %d"), *NewTab->GetTabLabel().ToString(), NewTab->GetTabRole());

	TWeakPtr<SDockTab> NewTabObserver(NewTab);
	TabsToProcess.Emplace(NewTabObserver);
	ProcessTabsDelay = 1;
}

TSharedPtr<FBAGraphHandler> FBATabHandler::GetGraphHandler()
{
	if (!ActiveGraphHandler.IsValid())
	{
		// check if a graph handler can be generated for the active tab
		TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
		TSharedPtr<SDockTab> ActiveTab = TabManager->GetActiveTab();

		if (GraphHandlerMap.Contains(ActiveTab))
		{
			ActiveGraphHandler = GraphHandlerMap[ActiveTab];
		}
		// this helps when we reload the module as the active tab callback was not called
		// since the tab was never changed, so we need to check it again
		else
		{
			ProcessTab(ActiveTab);
		}
	}

	return ActiveGraphHandler.Pin();
}

void FBATabHandler::SetGraphHandler(TSharedPtr<SDockTab> Tab, TSharedPtr<SGraphEditor> GraphEditor)
{
	TWeakPtr<SGraphEditor> GraphEditorObserver(GraphEditor);
	TWeakPtr<SDockTab> TabObserver(Tab);

	if (ActiveGraphHandler.IsValid())
	{
		ActiveGraphHandler.Pin()->ResetTransactions();
	}

	if (GraphHandlerMap.Contains(Tab))
	{
		ActiveGraphHandler = GraphHandlerMap[Tab];
	}
	else
	{
		TSharedRef<FBAGraphHandler> NewGraphHandler(MakeShared<FBAGraphHandler>(TabObserver, GraphEditorObserver));
		GraphHandlerMap.Add(Tab, NewGraphHandler);
		ActiveGraphHandler = NewGraphHandler;
	}
}

void FBATabHandler::Cleanup()
{
	TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->OnTabForegrounded_Unsubscribe(OnTabForegroundedDelegateHandle);
	TabManager->OnActiveTabChanged_Unsubscribe(OnActiveTabChangedDelegateHandle);

	for (auto& Elem : GraphHandlerMap)
	{
		Elem.Value->Cleanup();
	}

	GraphHandlerMap.Reset();
	ActiveGraphHandler.Reset();
	TabsToProcess.Reset();
}

void FBATabHandler::RemoveInvalidTabs()
{
	TArray<TWeakPtr<SDockTab>> InvalidTabs;
	for (auto& Elem : GraphHandlerMap)
	{
		TWeakPtr<SDockTab> Tab = Elem.Key;
		TSharedRef<FBAGraphHandler> GraphHandler = Elem.Value;

		if (!Tab.IsValid() || !FBAUtils::IsValidGraph(GraphHandler->GetFocusedEdGraph()))
		{
			InvalidTabs.Add(Tab);
			GraphHandler->Cleanup();

			if (ActiveGraphHandler == GraphHandler)
			{
				ActiveGraphHandler.Reset();
				ActiveGraphHandler = nullptr;
			}
		}
	}

	for (auto& Tab : InvalidTabs)
		if (GraphHandlerMap.Contains(Tab))
			GraphHandlerMap.Remove(Tab);
}

TSharedPtr<SDockTab> FBATabHandler::GetChildTabWithGraphEditor(TSharedPtr<SWidget> Widget) const
{
	if (!Widget.IsValid())
		return nullptr;

	if (Widget->GetVisibility() == EVisibility::Hidden || Widget->GetVisibility() == EVisibility::Collapsed)
		return nullptr;

	// check if widget is dock tab
	if (Widget->GetTypeAsString() == "SDockTab")
	{
		TSharedPtr<SDockTab> ChildDockTab = StaticCastSharedPtr<SDockTab>(Widget);
		if (ChildDockTab->IsForeground())
		{
			TSharedRef<SWidget> TabContent = ChildDockTab->GetContent();
			if (TabContent->GetTypeAsString() == "SGraphEditor")
			{
				return ChildDockTab;
			}
		}
	}
	else // recursively check children
	{
		FChildren* const Children = Widget->GetChildren();
		for (int i = 0; i < Children->Num(); i++)
		{
			TSharedPtr<SDockTab> ReturnWidget = GetChildTabWithGraphEditor(Children->GetChildAt(i));
			if (ReturnWidget.IsValid())
			{
				return ReturnWidget;
			}
		}
	}

	return nullptr;
}

void FBATabHandler::ProcessTabs()
{
	if (TabsToProcess.Num() == 0)
		return;

	for (const TWeakPtr<SDockTab>& Tab : TabsToProcess)
	{
		if (Tab.Pin())
		{
			if (ProcessTab(Tab.Pin()))
			{
				break;
			}
		}
	}

	TabsToProcess.Empty();
}

bool FBATabHandler::ProcessTab(TSharedPtr<SDockTab> Tab)
{
	if (!Tab.IsValid() || !Tab->IsForeground())
		return false;

	const bool bIsMajorTab = Tab->GetTabRole() == MajorTab;

	TSharedPtr<SDockTab> TabWithGraphEditor
		= bIsMajorTab
		? GetChildTabWithGraphEditor(Tab->GetContent())
		: Tab;
	
	if (TabWithGraphEditor.IsValid())
	{
		TSharedRef<SWidget> TabContent = TabWithGraphEditor->GetContent();
		const FString TabContentType = TabContent->GetTypeAsString();

		// use the tab if it contains a graph editor, 
		if (TabContentType == "SGraphEditor")
		{
			TSharedRef<SGraphEditor> ContentGraphEditor = StaticCastSharedRef<SGraphEditor>(TabContent);
			if (FBAUtils::IsValidGraph(ContentGraphEditor->GetCurrentGraph()))
			{
				SetGraphHandler(TabWithGraphEditor, ContentGraphEditor);
				return true;
			}
		}

		// otherwise it may be a niagara graph, check child widgets to find the graph editor
		if (TabContentType == "SNiagaraScriptGraph")
		{
			TSharedPtr<SGraphEditor> ChildGraphEditor = StaticCastSharedPtr<SGraphEditor>(FBAUtils::GetChildWidget(TabContent, "SGraphEditor"));
			if (ChildGraphEditor.IsValid())
			{
				if (FBAUtils::IsValidGraph(ChildGraphEditor->GetCurrentGraph()))
				{
					SetGraphHandler(TabWithGraphEditor, ChildGraphEditor);
					return true;
				}
			}
		}
	}

	// if we have reached this point, then the processed tab is not suitable for a graph handler
	// set our active graph handler to null
	if (ActiveGraphHandler.Pin())
	{
		const bool bDifferentWindow = FBAUtils::GetParentWidgetOfType(Tab, "SWindow") != ActiveGraphHandler.Pin()->GetOrFindWindow();

		if (bDifferentWindow || Tab->GetTabRole() != PanelTab)
		{
			ActiveGraphHandler.Pin()->ResetTransactions();
			ActiveGraphHandler = nullptr;
		}
	}

	return false;
}
