// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"
#include "ScopedTransaction.h"
#include "BlueprintAssistSettings.h"
#include "../GraphFormatters/EdGraphFormatter.h"

#if ENGINE_MINOR_VERSION >= 22
class FAsyncTaskNotification;
#endif
class SMyBlueprint;
struct FFormatterInterface;
struct FBACacheData;

class BLUEPRINTASSIST_API FBAGraphHandler
	: public TSharedFromThis<FBAGraphHandler>
{
public:
	UEdGraphNode* NewNodeForFormatting = nullptr;

	FBAGraphHandler(TWeakPtr<SDockTab> InTab, TWeakPtr<SGraphEditor> InGraphEditor);

	~FBAGraphHandler();

	void InitGraphHandler();

	void Cleanup();

	void Tick(float DeltaTime);

	void UpdateSelectedNode();

	void HighlightSelectedPin();

	TSharedPtr<SWindow> GetOrFindWindow();

	bool IsWindowActive();

	bool IsGraphReadOnly();

	void AddPendingFormatNodes(
		UEdGraphNode* Node,
		TSharedPtr<FScopedTransaction> PendingTransaction = TSharedPtr<FScopedTransaction>(),
		FEdGraphFormatterParameters FormatterParameters = FEdGraphFormatterParameters());

	void SetReplaceNewNodeTransaction(TSharedPtr<FScopedTransaction> Transaction)
	{
		ReplaceNewNodeTransaction = Transaction;
	}

	void ResetSingleNewNodeTransaction();

	float GetPinY(UEdGraphPin* Pin);

	void UpdateCachedNodeSize(float DeltaTime);

	void UpdateNodesRequiringFormatting();

	void SimpleFormatAll();
	
	void SmartFormatAll();

	void SetSelectedPin(UEdGraphPin* Pin);

	void UpdateLerpViewport(float DeltaTime);

	void BeginLerpViewport(FVector2D TargetView, bool bCenter = true);

	TSharedPtr<FFormatterInterface> FormatNodes(UEdGraphNode* Node, bool bUsingFormatAll = false);

	void CancelProcessingNodeSizes();

	TSharedPtr<SDockTab> GetTab() const { return TSharedPtr<SDockTab>(CachedTab.Pin()); }

	UEdGraph* GetFocusedEdGraph();

	TSharedPtr<SGraphEditor> GetGraphEditor();

	TSharedPtr<SGraphPanel> GetGraphPanel();

	UBlueprint* GetBlueprint();

	// class FBlueprintEditor* GetBlueprintEditor();

	// TWeakPtr<SMyBlueprint> GetMyBlueprintWidget();

	UEdGraphNode* GetSelectedNode(bool bAllowCommentNodes = false);

	TSet<UEdGraphNode*> GetSelectedNodes(bool bAllowCommentNodes = false);

	FSlateRect GetCachedNodeBounds(UEdGraphNode* Node, bool bWithCommentBubble = true);

	UEdGraphPin* GetSelectedPin();

	TSharedPtr<SGraphNode> GetGraphNode(UEdGraphNode* Node);

	TSharedPtr<SGraphPin> GetGraphPin(UEdGraphPin* Pin);

	bool IsCalculatingNodeSize() const { return PendingSize.Num() > 0; }

	void RefreshNodeSize(UEdGraphNode* Node);

	void RefreshAllNodeSizes();

	void ResetTransactions();

	void FormatAllEvents();

	void ApplyCommentBubbleSetting();

	int32 GetNumberOfPendingNodesToCache() const;

	void ClearCache();

	void ClearFormatters();

	bool FilterSelectiveFormatting(UEdGraphNode* Node, const TArray<UEdGraphNode*>& NodesToFormat);

	bool FilterDelegatePin(const FPinLink& PinLink, const TArray<UEdGraphNode*>& NodesToFormat);

	UEdGraphNode* GetRootNode(UEdGraphNode* InitialNode, const TArray<UEdGraphNode*>& NodesToFormat, bool bCheckSelectedNode = true);

private:
	TWeakPtr<SGraphPanel> CachedGraphPanel;
	TWeakPtr<SGraphEditor> CachedGraphEditor;
	TWeakPtr<SDockTab> CachedTab;
	TWeakPtr<SWindow> CachedWindow;

	FEdGraphFormatterParameters FormatterParameters;

	TArray<UEdGraphNode*> NodesCreatedThisFrame;
	TArray<UEdGraphNode*> NodesCreatedLastFrame;

	TOptional<FGraphPinHandle> SelectedPinHandle;

	FBACacheData& GetGraphCache();

	int Delay_ResetReplaceNode;

	int Delay_InitialCache;
	bool bInitialZoomFinished;
	FVector2D LastGraphView;
	float LastZoom;

	// update node size
	float NodeSizeTimeout;
	int TicksOnFocusedNode;
	int Delay_ViewportZoomIn;
	TSet<UEdGraphNode*> PendingFormatting;
	UEdGraphNode* FocusedNode;
	bool bFullyZoomed;
	FVector2D ViewCache;
	float ZoomCache;

	TSet<UEdGraphNode*> SeenNodes;
	TMap<UEdGraphNode*, FVector2D> CommentBubbleSizeCache;

	UEdGraphNode* LastSelectedNode;

	// lerp viewport position
	bool bLerpViewport;
	bool bCenterWhileLerping;
	FVector2D TargetLerpLocation;

	TArray<UEdGraphNode*> PendingSize;
#if ENGINE_MINOR_VERSION >= 22
	TUniquePtr<FAsyncTaskNotification> CachingSizeNotification;
	TUniquePtr<FAsyncTaskNotification> SizeTimeoutNotification;
#endif

	TArray<TArray<UEdGraphNode*>> FormatAllColumns;
	TMap<UEdGraphNode*, TSharedPtr<FFormatterInterface>> FormatterMap;

	TSharedPtr<FScopedTransaction> PendingTransaction;
	TSharedPtr<FScopedTransaction> ReplaceNewNodeTransaction;
	TSharedPtr<FScopedTransaction> FormatAllTransaction;

	void OnSelectionChanged(UEdGraphNode* PreviousNode, UEdGraphNode* NewNode);

	void ProcessNodesCreatedLastFrame();

	void ProcessNewImpureNode(UEdGraphNode* NodeCreated);

	void ProcessNewPureNode(UEdGraphNode* NodeCreated);

	void ProcessNewNode(UEdGraphNode* NewNode);

	void UpdateNewNodes();

	void ResetGraphEditor(TWeakPtr<SGraphEditor> NewGraphEditor);

	void ReplaceSavedSelectedNode(UEdGraphNode* NewNode);
};
