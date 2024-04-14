// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h" // needed for EGraphType and EEdGraphPinDirection
#include "BlueprintAssistSettings.h" // needed for EBAGraphType

class IMenu;
class UEdGraphNode_Comment;
struct FGraphPinHandle;
class UEdGraphNode;
class UEdGraphPin;
class UK2Node_Knot;
class UMaterialExpressionReroute;
class UMaterialGraphNode_Knot;
class SGraphPanel;
class SGraphEditor;
class SGraphPin;
class SGraphNode;
class FEdGraphFormatter;
class FBAGraphHandler;
class FBlueprintEditor;
struct FFormatterInterface;
struct FPinLink;

struct BLUEPRINTASSIST_API FBAUtils
{
	static void DeleteNode(UEdGraphNode* Node);

	static bool IsNodeDeleted(UEdGraphNode* Node);

	/** For a node, return all connected nodes */
	static TArray<UEdGraphNode*> GetLinkedNodes(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	static TArray<UEdGraphNode*> GetLinkedNodesFromPins(TArray<UEdGraphPin*> Pins);

	/** For a node, return all of the node's pins which have a connection */
	static TArray<UEdGraphPin*> GetLinkedPins(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	static TArray<UEdGraphPin*> GetLinkedToPins(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	/** For a node, return all of the pins in a certain direction */
	static TArray<UEdGraphPin*> GetPinsByDirection(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	/** For a node, return all of the pins which are exec pins (and an optional direction) */
	static TArray<UEdGraphPin*> GetExecPins(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	/** For a node, return all of the pins which are not exec pins (and an optional direction) */
	static TArray<UEdGraphPin*> GetParameterPins(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	/** For a node, return all of the pins in a certain direction */
	static TArray<UEdGraphPin*> GetPinsByCategory(
		UEdGraphNode* Node,
		FName Category,
		EEdGraphPinDirection Direction = EGPD_MAX);

	/** Calculate bounds for multiple FSlateRects */
	static FSlateRect GetGroupedBounds(const TArray<FSlateRect>& Rects);
	
	/** Calculate the bounds of a node */
	static FSlateRect GetNodeBounds(UEdGraphNode* Node);

	/** Calculate the bounds of multiple nodes */
	static FSlateRect GetNodeArrayBounds(TArray<UEdGraphNode*> Nodes);

	/** Calculate the bounds of a node using the cached size in the graph handler */
	static FSlateRect GetCachedNodeBounds(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphNode* Node, bool bWithCommentBubble = true);

	/** Calculate the bounds of an array of nodes using the cached size in the graph handler */
	static FSlateRect GetCachedNodeArrayBounds(
		TSharedPtr<FBAGraphHandler> GraphHandler,
		TArray<UEdGraphNode*> Nodes);

	/** Get the pin position, using the cached offset in the graph handler */
	static FVector2D GetPinPos(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphPin* Pin);

	/** Checks all nodes on the graph and sorts them depending on whether they are on the LHS or RHS of a given node */
	static void SortNodesOnGraphByDistance(
		UEdGraphNode* RelativeNode,
		const UEdGraph* Graph,
		TSet<UEdGraphNode*>& LHSNodes,
		TSet<UEdGraphNode*>& RHSNodes,
		TSet<UEdGraphPin*>& LHSPins,
		TSet<UEdGraphPin*>& RHSPins);

	/** Adds a knot node connecting two pins */
	static UK2Node_Knot* CreateKnotNode(
		const FVector2D& Position,
		UEdGraphPin* PinA,
		UEdGraphPin* PinB);

	/** Adds a knot node connecting two pins */
	static UEdGraphNode* CreateKnotNode_MaterialGraph(
		const FVector2D& Position,
		UEdGraphPin* PinA,
		UEdGraphPin* PinB,
		bool bCreateLink = true);

	static void LinkKnotNodeBetween(UK2Node_Knot* Node, const FVector2D& Position, UEdGraphPin* PinA, UEdGraphPin* PinB);

	static void DisconnectKnotNode(UEdGraphNode* Node);

	static void RemoveLinkedKnotNodes(UEdGraphNode* Node, TSet<UEdGraphNode*>& RemovedNodes);

	static TArray<UEdGraphPin*> GetLinkedToPinsIgnoringKnots(UEdGraphNode* Node, EEdGraphPinDirection Direction = EGPD_MAX);

	static bool IsNodePure(UEdGraphNode* Node);

	static bool IsNodeImpure(UEdGraphNode* Node);

	static bool IsKnotNode(UEdGraphNode* Node);

	static bool IsCommentNode(UEdGraphNode* Node);

	static bool IsVarNode(UEdGraphNode* Node);

	static bool IsK2Node(UEdGraphNode* Node);

	static bool IsK2Node_BaseAsyncTask(UEdGraphNode* Node);

	static TEnumAsByte<EBAGraphType> GetBAGraphType(UEdGraph* Graph);
	
	static FString GetBAGraphTypeAsString(UEdGraph* Graph);

	static bool IsValidGraph(UEdGraph* Graph);

	static bool IsBlueprintGraph(UEdGraph* Graph);

	static bool IsBehaviorTreeGraph(UEdGraph* Graph);

	static bool IsSoundCueGraph(UEdGraph* Graph);

	static bool IsMaterialGraph(UEdGraph* Graph);
	
	static bool IsNiagaraGraph(UEdGraph* Graph);
	
	static bool IsAnimationGraph(UEdGraph* Graph);

	static bool IsGraphNode(UEdGraphNode* Node);

	static bool IsBlueprintNode(UEdGraphNode* Node);

	static bool IsBehaviorTreeNode(UEdGraphNode* Node);

	static bool IsSoundCueNode(UEdGraphNode* Node);

	static bool IsMaterialNode(UEdGraphNode* Node);
	
	static bool IsNiagaraNode(UEdGraphNode* Node);

	static bool IsEventNode(UEdGraphNode* Node);

	static bool IsInputNode(UEdGraphNode* Node);

	static FString GetNodeName(UEdGraphNode* Node);

	static void PrintNodeInfo(UEdGraphNode* Node);

	static bool IsPinLinked(const UEdGraphPin* Pin);

	static bool IsPinUnlinked(const UEdGraphPin* Pin);

	static bool IsExecPin(const UEdGraphPin* Pin);

	static bool IsDelegatePin(const UEdGraphPin* Pin);

	static bool IsParameterPin(const UEdGraphPin* Pin) { return !IsExecPin(Pin) && !IsDelegatePin(Pin); }

	static int GetPinIndex(UEdGraphPin* Pin);

	static int GetLinkedPinIndex(UEdGraphPin* Pin);

	static TSet<UEdGraphNode*> GetNodeTreeWithFilter(
		UEdGraphNode* Node,
		TFunctionRef<bool(UEdGraphPin*)> Pred,
		EEdGraphPinDirection Direction = EGPD_MAX,
		bool bOnlyInitialDirection = false);

	static TSet<UEdGraphNode*> GetNodeTreeWithFilter(
		UEdGraphNode* Node,
		TFunctionRef<bool(const FPinLink&)> Pred,
		EEdGraphPinDirection Direction = EGPD_MAX,
		bool bOnlyInitialDirection = false);

	static TSet<UEdGraphNode*> GetNodeTree(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX,
		bool bOnlyInitialDirection = false);

	static TSet<UEdGraphNode*> GetExecTree(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX,
		bool bOnlyInitialDirection = false);

	static TSet<UEdGraphNode*> GetExecutionTreeWithFilter(
		UEdGraphNode* Node,
		TFunctionRef<bool(UEdGraphNode*)> Pred,
		EEdGraphPinDirection Direction = EGPD_MAX,
		bool bOnlyInitialDirection = false);

	static TSet<UEdGraphNode*> GetEdGraphNodeTree(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction = EGPD_MAX);

	static bool TryLinkImpureNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB);

	static UEdGraphPin* GetFirstExecPin(UEdGraphNode* Node, EEdGraphPinDirection Direction);

	static UEdGraphNode* GetFirstLinkedNode(UEdGraphNode* Node, EEdGraphPinDirection Direction);

	static bool TryCreateConnection(
		UEdGraphPin* PinA,
		UEdGraphPin* PinB,
		bool bBreakLinks = false,
		bool bConversionAllowed = false,
		bool bTryHidden = false);

	static FSlateRect FSlateRectFromVectors(const FVector2D& A, const FVector2D& B);

	static int DistanceSquaredBetweenNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB);

	static bool LineRectIntersection(
		const FSlateRect& Rect,
		const FVector2D& Start,
		const FVector2D& End);

	static void SetNodePosY(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphNode* Node, int NewY);

	static void SetNodePos(
		TSharedPtr<FBAGraphHandler> GraphHandler,
		UEdGraphNode* Node,
		int NewX,
		int NewY);

	static void SetNodePos(
		TSharedPtr<FBAGraphHandler> GraphHandler,
		UEdGraphNode* Node,
		const FVector2D& NewPos);

	static FString GraphTypeToString(EGraphType GraphType);

	static EGraphType GetGraphType(UEdGraph* Graph);

	static void StraightenPin(
		TSharedPtr<FBAGraphHandler> GraphHandler,
		UEdGraphPin* SourcePin,
		UEdGraphPin* PinToAlign);

	static bool IsNodeVisible(TSharedPtr<SGraphPanel> GraphPanel, UEdGraphNode* Node);

	static FString GetPinName(UEdGraphPin* Pin);

	static void PrintChildWidgets(TSharedPtr<SWidget> Widget);

	static TSharedPtr<SWidget> GetChildWidget(
		TSharedPtr<SWidget> Widget,
		const FString& WidgetClassName,
		bool bCheckContains = false);

	static void GetChildWidgets(
		TSharedPtr<SWidget> Widget,
		const FString& WidgetClassName,
		TArray<TSharedPtr<SWidget>>& OutWidgets,
		bool bCheckContains = false);

	static TSharedPtr<SWidget> GetParentWidgetOfType(
		TSharedPtr<SWidget> Widget,
		const FString& ParentType);

	static TSharedPtr<SGraphNode> GetGraphNode(
		TSharedPtr<SGraphPanel> GraphPanel,
		UEdGraphNode* Node);

	static TSharedPtr<SGraphPin> GetGraphPin(TSharedPtr<SGraphPanel> GraphPanel, UEdGraphPin* Pin);

	static TSharedPtr<SGraphPin> GetHoveredGraphPin(TSharedPtr<SGraphPanel> GraphPanel);

	static TSharedPtr<SGraphNode> GetHoveredGraphNode(TSharedPtr<SGraphPanel> GraphPanel);

	static int32 SnapToGrid(const float& InFloat);

	static bool IsUserInputWidget(TSharedPtr<SWidget> Widget);

	static bool IsClickableWidget(TSharedPtr<SWidget> Widget);

	static FVector2D GraphCoordToPanelCoord(
		TSharedPtr<SGraphPanel> GraphPanel,
		const FVector2D& PanelSpaceCoordinate);

	static bool TryLinkPins(UEdGraphPin* Source, UEdGraphPin* Target, bool bInsertNode = false);

	static bool CanConnectPins(
		UEdGraphPin* PinA,
		UEdGraphPin* PinB,
		bool bOverrideLinks = false,
		bool bAcceptConversions = false,
		bool bAcceptHiddenPins = false);

	static void InteractWithWidget(TSharedPtr<SWidget> Widget);

	static TSharedPtr<SWidget> GetInteractableChildWidget(TSharedPtr<SWidget> Widget);

	static void GetInteractableChildWidgets(
		TSharedPtr<SWidget> Widget,
		TArray<TSharedPtr<SWidget>>& OutWidgets,
		bool bCheckEditable = true,
		bool bCheckClickable = true);

	static UEdGraphNode* GetTopMost(UEdGraphNode* Node, EEdGraphPinDirection Direction);

	static UEdGraphNode* GetTopMostWithFilter(
		UEdGraphNode* Node,
		EEdGraphPinDirection Direction,
		TFunctionRef<bool (UEdGraphNode*)> Pred);

	static void SafeDelete(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphNode* Node);

	static bool IsPinLinkedToNode(UEdGraphPin* Pin, UEdGraphNode* Node, const TSet<UEdGraphNode*>& IgnoredNodes);

	static TArray<FPinLink> GetPinLinks(UEdGraphNode* Node, EEdGraphPinDirection Direction = EGPD_MAX);

	static UEdGraphPin* GetPinFromGraph(const FGraphPinHandle& Handle, UEdGraph* Graph);

	static bool IsExtraRootNode(UEdGraphNode* Node);

	static void SwapNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB);

	static TArray<UEdGraphNode*> GetNodesUnderComment(UEdGraphNode_Comment* CommentNode);

	static TArray<UEdGraphNode_Comment*> GetCommentNodesFromGraph(UEdGraph* Graph);
	
	static TArray<UEdGraphNode_Comment*> GetContainingCommentNodes(const TArray<UEdGraphNode_Comment*>& Comments, UEdGraphNode* Node);

	static UEdGraphNode* GetFirstLinkedNodePreferringInput(UEdGraphNode* Node);

	template <class T>
	static bool DoesArrayContainsAllItems(const TArray<T>& Array, const TArray<T>& Items)
	{
		for (T Item : Items)
		{
			if (!Array.Contains(Item))
				return false;
		}

		return true;
	}

	static void RemoveNodeFromComment(UEdGraphNode_Comment* Comment, UEdGraphNode* NodeToRemove);

	static FBAFormatterSettings& GetFormatterSettings(UEdGraph* Graph);
	
	static TSharedPtr<FBAGraphHandler> GetCurrentGraphHandler();

	static float GetCenterYOfPins(TSharedPtr<FBAGraphHandler> GraphHandler, TArray<UEdGraphPin*>& Pins);

	static TSharedPtr<IMenu> PushMenuAtCenterOfWindow(TSharedPtr<SWidget> Widget, const FVector2D& WidgetSize, TSharedPtr<SWidget> WidgetToFocus);
};
