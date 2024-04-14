// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/IInputProcessor.h"
#include "EdGraph/EdGraphNode.h"
#include "BlueprintAssistSettings.h"

class SDockTab;
class FBAGraphHandler;
class FBATabHandler;
class FUICommandList;

class BLUEPRINTASSIST_API FBAInputProcessor
	: public TSharedFromThis<FBAInputProcessor>
	, public IInputProcessor
{
public:
	TSharedPtr<FBATabHandler> TabHandler;

	UEdGraphNode* SavedNodeToReplace = nullptr;

	FDelegateHandle OnReplaceMenuClosedDelegate;

	FBAInputProcessor();

	~FBAInputProcessor();

	void Cleanup();

	//~ Begin IInputProcessor Interface

	void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override;

	bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

	bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;

	//~ End IInputProcessor Interface

private:
	TSharedPtr<FBAGraphHandler> GraphHandler;
	
	TSharedPtr<FUICommandList> GlobalCommands;
	TSharedPtr<FUICommandList> TabCommands;
	TSharedPtr<FUICommandList> GraphCommands;
	TSharedPtr<FUICommandList> GraphReadOnlyCommands;
	TSharedPtr<FUICommandList> SingleNodeCommands;
	TSharedPtr<FUICommandList> MultipleNodeCommands;
	TSharedPtr<FUICommandList> MultipleNodeCommandsIncludingComments;
	TSharedPtr<FUICommandList> PinCommands;
	TSharedPtr<FUICommandList> ActionMenuCommands;
	TSharedPtr<FUICommandList> PinEditCommands;

	void CreateGraphEditorCommands();

	// command list
	void OnOpenContextMenu();

	void FormatNodes() const;

	void FormatNodesSelectively();

	void FormatNodesWithHelixing() const;

	void FormatNodesWithLHS() const;

	void OnSmartWireSelectedNode() const;

	void OnFormatAllEvents() const;

	void SelectNodeInDirection(
		const TArray<UEdGraphNode*>& Nodes,
		int X,
		int Y,
		float DistLimit) const;

	void SelectAnyNodeInDirection(int X, int Y) const;

	void SelectCustomEventNodeInDirection(int X, int Y) const;

	void SelectPinInDirection(int X, int Y) const;

	bool CanSelectPinInDirection();

	void ShiftCameraInDirection(int X, int Y) const;

	void SwapNodeInDirection(EEdGraphPinDirection Direction) const;

	void OpenContextMenu(const FVector2D& MenuLocation, const FVector2D& NodeSpawnPosition) const;

	void SmartWireNode(UEdGraphNode* Node) const;

	void LinkPinToNearest(UEdGraphPin* Pin, bool bOverrideLink, bool bFilterByDirection, float DistLimit = 0.f) const;

	void LinkToHoveredPin();

	void LinkNodesBetweenWires();

	void CreateContextMenuFromPin(UEdGraphPin* Pin, const FVector2D& MenuLocation, const FVector2D& NodeLocation) const;

	void OpenPinLinkMenu();

	void OpenGoToSymbolMenu();
	
	void OpenGoToSettingsMenu();

	void OpenFocusSearchBoxMenu();

	void OpenVariableSelectorMenu();

	void OpenCreateSymbolMenu();

	void OpenEditDetailsMenu();

	void OpenAddVariableMenu();

	void DuplicateNodeForEachLink() const;

	void RefreshNodeSizes() const;

	void OnEditSelectedPinValue() const;

	void DeleteAndLink();

	void ZoomToNodeTree() const;

	void OnGetContextMenuActions(bool bUsePin = true) const;

	void PrintSelectedNodeInfo() const;

	void OnToggleActionMenuContextSensitive() const;

	void DisconnectPinOrWire();

	void DisconnectExecutionOfSelectedNode();

	void DisconnectExecutionOfNodes(TArray<UEdGraphNode*> Nodes);

	void DisconnectAllNodeLinks();

	void ReplaceNodeWith();

	void OnReplaceNodeMenuClosed(const TSharedRef<class SWindow>& Window);

	void DebugPrintGraphUnderCursor() const;

	void ToggleNodes();

	void SplitPin();
	void RecombinePin();

	void CreateRerouteNode();

	void OpenBlueprintAssistHotkeyMenu();
};
