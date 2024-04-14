// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintAssistInputProcessor.h"

struct FSlateDebuggingFocusEventArgs;
class FBAGraphHandler;
class SDockTab;
class SWindow;
class SGraphEditor;
class SWidget;

/**
 * Manages tabs and their associated GraphHandlers
 */
class BLUEPRINTASSIST_API FBATabHandler
	: public TSharedFromThis<FBATabHandler>
{
public:
	FBATabHandler();

	~FBATabHandler();

	void Tick(float DeltaTime);

	void Cleanup();

	TSharedPtr<FBAGraphHandler> GetGraphHandler();

private:
	TWeakPtr<FBAGraphHandler> ActiveGraphHandler;
	TMap<TWeakPtr<SDockTab>, TSharedRef<FBAGraphHandler>> GraphHandlerMap;

	FDelegateHandle OnTabForegroundedDelegateHandle;
	FDelegateHandle OnActiveTabChangedDelegateHandle;

	int ProcessTabsDelay = 0;
	TSet<TWeakPtr<SDockTab>> TabsToProcess;

	void SetGraphHandler(TSharedPtr<SDockTab> Tab, TSharedPtr<SGraphEditor> GraphEditor);

	void OnTabForegrounded(TSharedPtr<SDockTab> NewTab, TSharedPtr<SDockTab> PreviousTab);

	void OnActiveTabChanged(TSharedPtr<SDockTab> PreviousTab, TSharedPtr<SDockTab> NewTab);

	void RemoveInvalidTabs();

	TSharedPtr<SDockTab> GetChildTabWithGraphEditor(TSharedPtr<SWidget> Widget) const;

	void ProcessTabs();

	bool ProcessTab(TSharedPtr<SDockTab> Tab);
};
