// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistUtils.h"

#include "Framework/Application/SlateApplication.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraph.h"
#include "Runtime/Core/Public/Containers/Queue.h"
#include "Editor/AIGraph/Classes/AIGraphNode.h"
#include "Editor/BlueprintGraph/Classes/EdGraphSchema_K2_Actions.h"
#include "Editor/BlueprintGraph/Classes/EdGraphSchema_K2.h"
#include "Editor/BlueprintGraph/Classes/K2Node.h"
#include "Editor/GraphEditor/Public/SGraphNode.h"
#include "Editor/GraphEditor/Public/SGraphPanel.h"
#include "Editor/GraphEditor/Public/SNodePanel.h"
#include "Editor/UnrealEd/Public/EdGraphNode_Comment.h"
#include "Editor/UnrealEd/Public/Kismet2/KismetEditorUtilities.h"
#include "Editor/UnrealEd/Public/Kismet2/BlueprintEditorUtils.h"
#include "Layout/SlateRect.h"

#include "EdGraph/EdGraphSchema.h"

#include "K2Node_Knot.h"
#include "K2Node_InputAction.h"
#include "K2Node_InputTouch.h"
#include "K2Node_InputAxisEvent.h"
#include "K2Node_InputKeyEvent.h"
#include "K2Node_InputVectorAxisEvent.h"
#include "K2Node_InputKey.h"
#include "K2Node_InputActionEvent.h"
#include "K2Node_InputTouchEvent.h"
#include "K2Node_InputAxisKeyEvent.h"
#include "K2Node_Variable.h"
#include "K2Node_BaseAsyncTask.h"

#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistModule.h"
#include "../GraphFormatters/GraphFormatterTypes.h"

#include "MaterialGraphNode_Knot.h"
#include "MaterialEditor/Public/MaterialEditorUtilities.h"
#include "Materials/MaterialExpressionReroute.h"

#include "BlueprintAssistSettings.h"
#include "EdGraphSchema_BehaviorTree.h"
#include "SoundCueGraph/SoundCueGraphSchema.h"
#include "MaterialGraph/MaterialGraphSchema.h"
#include "SoundCueGraph/SoundCueGraphNode.h"
#include "SoundCueEditorUtilities.h"
#include "Sound/SoundCue.h"
#include "SoundCueGraph/SoundCueGraph.h"

#include "AnimGraph/Classes/AnimationGraphSchema.h"
#include "BlueprintAssistInputProcessor.h"
#include "BlueprintAssistTabHandler.h"

// @TODO Niagara graph formatting
// #include "EdGraphSchema_Niagara.h"
// #include "NiagaraEditor/Public/NiagaraNode.h"

void FBAUtils::DeleteNode(UEdGraphNode* Node)
{
	if (!Node)
		return;

	UEdGraph* EdGraph = Node->GetGraph();

	if (EdGraph->GetClass()->GetFName() == "MaterialGraph")
	{
		TArray<UEdGraphNode*> NodesToDelete;
		NodesToDelete.Add(Node);
		FMaterialEditorUtilities::DeleteNodes(Node->GetGraph(), NodesToDelete);
	}
	else
	{
		UBlueprint* OwnerBlueprint = FBlueprintEditorUtils::FindBlueprintForNodeChecked(Node);
		FBlueprintEditorUtils::RemoveNode(OwnerBlueprint, Node, /*bDontRecompile=*/ true);
	}
}

bool FBAUtils::IsNodeDeleted(UEdGraphNode* Node)
{
	if (!Node)
		return true;

	UEdGraph* EdGraph = Node->GetGraph();
	if (!EdGraph)
		return false;
	
	return !EdGraph->Nodes.Contains(Node);
}

TArray<UEdGraphNode*> FBAUtils::GetLinkedNodes(
	UEdGraphNode* Node,
	const EEdGraphPinDirection Direction)
{
	TSet<UEdGraphNode*> Nodes;
	for (UEdGraphPin* LinkedPin : GetLinkedPins(Node, Direction))
		if (LinkedPin->LinkedTo.Num() > 0)
			for (UEdGraphPin* Linked2LinkedPin : LinkedPin->LinkedTo)
				Nodes.Add(Linked2LinkedPin->GetOwningNode());

	return Nodes.Array();
}

TArray<UEdGraphNode*> FBAUtils::GetLinkedNodesFromPins(TArray<UEdGraphPin*> Pins)
{
	TSet<UEdGraphNode*> Nodes;
	for (UEdGraphPin* Pin : Pins)
	{
		for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
		{
			Nodes.Add(LinkedPin->GetOwningNode());
		}
	}

	return Nodes.Array();
}

TArray<UEdGraphPin*> FBAUtils::GetLinkedPins(
	UEdGraphNode* Node,
	const EEdGraphPinDirection Direction)
{
	const auto Pred = [](UEdGraphPin* Pin)
	{
		return Pin->LinkedTo.Num() > 0;
	};
	return GetPinsByDirection(Node, Direction).FilterByPredicate(Pred);
}

TArray<UEdGraphPin*> FBAUtils::GetLinkedToPins(
	UEdGraphNode* Node,
	const EEdGraphPinDirection Direction)
{
	TSet<UEdGraphPin*> LinkedToPins;
	
	for (UEdGraphPin* Pin : GetLinkedPins(Node, Direction))
	{
		LinkedToPins.Append(Pin->LinkedTo);
	}

	return LinkedToPins.Array();
}

TArray<UEdGraphPin*> FBAUtils::GetPinsByDirection(
	UEdGraphNode* Node,
	const EEdGraphPinDirection Direction)
{
	const auto Pred = [Direction](UEdGraphPin* Pin)
	{
		return !Pin->bHidden && (Pin->Direction == Direction || Direction ==
			EGPD_MAX);
	};

	return Node->Pins.FilterByPredicate(Pred);
}

TArray<UEdGraphPin*> FBAUtils::GetExecPins(UEdGraphNode* Node, const EEdGraphPinDirection Direction)
{
	const auto Pred = [Direction](UEdGraphPin* Pin)
	{
		return !Pin->bHidden && IsExecPin(Pin) && (Pin->Direction == Direction || Direction == EGPD_MAX);
	};

	return Node->Pins.FilterByPredicate(Pred);
}

TArray<UEdGraphPin*> FBAUtils::GetParameterPins(
	UEdGraphNode* Node,
	const EEdGraphPinDirection Direction)
{
	const auto Pred = [&Direction](UEdGraphPin* Pin)
	{
		return !Pin->bHidden && IsParameterPin(Pin) && (Pin->Direction == Direction || Direction == EGPD_MAX);
	};

	return Node->Pins.FilterByPredicate(Pred);
}

TArray<UEdGraphPin*> FBAUtils::GetPinsByCategory(
	UEdGraphNode* Node,
	const FName Category,
	const EEdGraphPinDirection Direction)
{
	const auto Pred = [&Category, &Direction](UEdGraphPin* Pin)
	{
		return Pin->PinType.PinCategory == Category && (Pin->Direction == Direction
			|| Direction == EGPD_MAX);
	};

	return Node->Pins.FilterByPredicate(Pred);
}

FSlateRect FBAUtils::GetGroupedBounds(const TArray<FSlateRect>& Rects)
{
	bool bBoundsInit = false;
	FSlateRect GroupedBounds;
	for (const FSlateRect& Rect : Rects)
	{
		// initialize bounds from first valid node
		if (!bBoundsInit)
		{
			GroupedBounds = Rect;
			bBoundsInit = true;
		}
		else
		{
			GroupedBounds = GroupedBounds.Expand(Rect);
		}
	}

	return GroupedBounds;
}

FSlateRect FBAUtils::GetNodeBounds(UEdGraphNode* Node)
{
	if (Node == nullptr)
		return FSlateRect();

	const TWeakPtr<SGraphNode> GraphNode = Node->DEPRECATED_NodeWidget;

	const FVector2D Pos(Node->NodePosX, Node->NodePosY);
	const FVector2D Size
		= GraphNode.IsValid()
		? GraphNode.Pin()->GetDesiredSize()
		: FVector2D(300.f, 150.f);

	return FSlateRect::FromPointAndExtent(Pos, Size);
}

FSlateRect FBAUtils::GetNodeArrayBounds(TArray<UEdGraphNode*> Nodes)
{
	bool bBoundsInit = false;
	FSlateRect Bounds;
	for (int i = 0; i < Nodes.Num(); i++)
	{
		UEdGraphNode* Node = Nodes[i];

		if (!Node)
			continue;

		// initialize bounds from first valid node
		if (!bBoundsInit)
		{
			Bounds = GetNodeBounds(Node);
			bBoundsInit = true;
		}
		else
		{
			Bounds = Bounds.Expand(GetNodeBounds(Node));
		}
	}

	return Bounds;
}

FSlateRect FBAUtils::GetCachedNodeBounds(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	UEdGraphNode* Node,
	bool bWithCommentBubble)
{
	return GraphHandler->GetCachedNodeBounds(Node, bWithCommentBubble);
}

FSlateRect FBAUtils::GetCachedNodeArrayBounds(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	TArray<UEdGraphNode*> Nodes)
{
	bool bBoundsInit = false;
	FSlateRect Bounds;
	for (int i = 0; i < Nodes.Num(); i++)
	{
		UEdGraphNode* Node = Nodes[i];
		if (!Node)
			continue;

		// initialize bounds from first valid node
		if (!bBoundsInit)
		{
			Bounds = GetCachedNodeBounds(GraphHandler, Node);
			bBoundsInit = true;
		}
		else
		{
			Bounds = Bounds.Expand(GetCachedNodeBounds(GraphHandler, Node));
		}
	}

	return Bounds;
}

FVector2D FBAUtils::GetPinPos(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphPin* Pin)
{
	UEdGraphNode* OwningNode = Pin->GetOwningNode();

	FSlateRect NodeBounds = GetCachedNodeBounds(GraphHandler, OwningNode, false);

	// use node left and right for the pin pos x
	return FVector2D(
		Pin->Direction == EGPD_Input ? NodeBounds.Left : NodeBounds.Right,
		GraphHandler->GetPinY(Pin));
}

void FBAUtils::SortNodesOnGraphByDistance(
	UEdGraphNode* RelativeNode,
	const UEdGraph* Graph,
	TSet<UEdGraphNode*>& LHSNodes,
	TSet<UEdGraphNode*>& RHSNodes,
	TSet<UEdGraphPin*>& LHSPins,
	TSet<UEdGraphPin*>& RHSPins)
{
	if (Graph == nullptr || RelativeNode == nullptr)
		return;

	// Add nodes to LHS or RHS depending on X position
	for (UEdGraphNode* Other : Graph->Nodes)
	{
		// ignore the same node
		if (Other == RelativeNode)
			continue;

		// ignore nodes too far away
		// TODO: make this an option parameter
		const float DeltaX = FMath::Abs(Other->NodePosX - RelativeNode->NodePosX);
		const float DeltaY = FMath::Abs(Other->NodePosY - RelativeNode->NodePosY);
		if (DeltaX > 600 || DeltaY > 400)
			continue;

		(RelativeNode->NodePosX >= Other->NodePosX ? LHSNodes : RHSNodes).Add(Other);
	}

	// sort nodes by distance to Node
	UEdGraphNode* NodeLValue = RelativeNode;
	const auto& Sorter = [NodeLValue](UEdGraphNode& A, UEdGraphNode& B)-> bool
	{
		float DeltaX = A.NodePosX - NodeLValue->NodePosX;
		float DeltaY = A.NodePosY - NodeLValue->NodePosY;
		const float DistA = DeltaX * DeltaX + 4.f * DeltaY * DeltaY;

		DeltaX = B.NodePosX - NodeLValue->NodePosX;
		DeltaY = B.NodePosY - NodeLValue->NodePosY;
		const float DistB = DeltaX * DeltaX + 4.f * DeltaY * DeltaY;

		return DistA < DistB;
	};

	LHSNodes.Sort(Sorter);
	RHSNodes.Sort(Sorter);

	for (UEdGraphNode* Node : LHSNodes)
		for (UEdGraphPin* OtherPin : Node->Pins)
			if (OtherPin->Direction == EGPD_Output)
				LHSPins.Add(OtherPin);

	for (UEdGraphNode* Node : RHSNodes)
		for (UEdGraphPin* OtherPin : Node->Pins)
			if (OtherPin->Direction == EGPD_Input)
				RHSPins.Add(OtherPin);
}

UK2Node_Knot* FBAUtils::CreateKnotNode(
	const FVector2D& Position,
	UEdGraphPin* PinA,
	UEdGraphPin* PinB)
{
	// logic is mostly copied from UEdGraphSchema_K2::OnPinConnectionDoubleCicked
	const FVector2D NodeSpacerSize(42.f, 16.0f);
	// This constant is duplicated from inside of SGraphNodeKnot
	const FVector2D KnotTopLeft = Position - NodeSpacerSize * 0.5f;

	// Create a new knot
	UEdGraph* ParentGraph = nullptr;
	if (UEdGraphNode* NodeA = PinA->GetOwningNodeUnchecked())
	{
		ParentGraph = NodeA->GetGraph();
	}
	else if (UEdGraphNode* NodeB = PinB->GetOwningNodeUnchecked())
	{
		ParentGraph = NodeB->GetGraph();
	}

	check(ParentGraph != nullptr);

	if (!FBlueprintEditorUtils::IsGraphReadOnly(ParentGraph))
	{
		UK2Node_Knot* NewKnot = FEdGraphSchemaAction_K2NewNode::SpawnNode<UK2Node_Knot>(ParentGraph, KnotTopLeft, EK2NewNodeFlags::None);
		LinkKnotNodeBetween(NewKnot, Position, PinA, PinB);
		return NewKnot;
	}

	return nullptr;
}

UEdGraphNode* FBAUtils::CreateKnotNode_MaterialGraph(
	const FVector2D& Position,
	UEdGraphPin* PinA,
	UEdGraphPin* PinB,
	bool bCreateLink /*= true*/)
{
	// This constant is duplicated from inside of SGraphNodeKnot
	const FVector2D NodeSpacerSize(42.0f, 24.0f);
	const FVector2D KnotTopLeft = Position - (NodeSpacerSize * 0.5f);

	// Create a new knot
	UEdGraph* ParentGraph = PinA->GetOwningNode()->GetGraph();

	UMaterialExpression* Expression = FMaterialEditorUtilities::CreateNewMaterialExpression(
		ParentGraph,
		UMaterialExpressionReroute::StaticClass(),
		KnotTopLeft,
		true,
		true);

	UMaterialGraphNode_Knot* KnotNode = CastChecked<UMaterialGraphNode_Knot>(Expression->GraphNode);

	if (KnotNode != nullptr)
	{
		// Move the connections across (only notifying the knot, as the other two didn't really change)
		PinA->BreakLinkTo(PinB);
		PinA->MakeLinkTo(
			(PinA->Direction == EGPD_Output) ? KnotNode->GetInputPin() : KnotNode->GetOutputPin());
		PinB->MakeLinkTo(
			(PinB->Direction == EGPD_Output) ? KnotNode->GetInputPin() : KnotNode->GetOutputPin());
		FMaterialEditorUtilities::UpdateMaterialAfterGraphChange(ParentGraph);
	}

	return KnotNode;
}

void FBAUtils::RemoveLinkedKnotNodes(UEdGraphNode* InitialNode, TSet<UEdGraphNode*>& RemovedNodes)
{
	struct FLocal
	{
		static void Delete(UEdGraphNode* InNode, TSet<UEdGraphNode*>& VisitedNodes)
		{
			if (VisitedNodes.Contains(InNode))
				return;

			/** Iterate across all linked node */
			for (UEdGraphNode* Node : GetLinkedNodes(InNode))
			{
				if (IsKnotNode(Node) && !VisitedNodes.Contains(Node))
				{
					if (VisitedNodes.Contains(Node))
						continue;

					VisitedNodes.Emplace(Node);
					Delete(Node, VisitedNodes);
				}
			}

			/** Delete all connections for each knot node */
			if (IsKnotNode(InNode))
			{
				DisconnectKnotNode(InNode);
				DeleteNode(InNode);
			}
		}
	};

	FLocal::Delete(InitialNode, RemovedNodes);
}

TArray<UEdGraphPin*> FBAUtils::GetLinkedToPinsIgnoringKnots(UEdGraphNode* InNode, EEdGraphPinDirection Direction)
{
	TArray<UEdGraphNode*> PendingNodes = { InNode };
	TArray<UEdGraphPin*> OutPins;
	
	while (PendingNodes.Num() > 0)
	{
		UEdGraphNode* Node = PendingNodes.Pop();
	
		for (UEdGraphPin* Pin : GetLinkedToPins(Node, Direction))
		{
			if (UK2Node_Knot* KnotNode = Cast<UK2Node_Knot>(Pin->GetOwningNode()))
			{
				PendingNodes.Push(KnotNode);
			}
			else
			{
				OutPins.Add(Pin);
			}
		}
	}

	return OutPins;
}

void FBAUtils::LinkKnotNodeBetween(UK2Node_Knot* KnotNode, const FVector2D& Position, UEdGraphPin* PinA, UEdGraphPin* PinB)
{
	const FVector2D NodeSpacerSize(42.f, 16.0f);

	// This constant is duplicated from inside of SGraphNodeKnot
	const FVector2D KnotTopLeft = Position - NodeSpacerSize * 0.5f;

	// Create a new knot
	UEdGraph* ParentGraph = nullptr;
	if (UEdGraphNode* NodeA = PinA->GetOwningNodeUnchecked())
	{
		ParentGraph = NodeA->GetGraph();
	}
	else if (UEdGraphNode* NodeB = PinB->GetOwningNodeUnchecked())
	{
		ParentGraph = NodeB->GetGraph();
	}

	check(ParentGraph != nullptr);
	
	if (!FBlueprintEditorUtils::IsGraphReadOnly(ParentGraph))
	{
		KnotNode->NodePosX = KnotTopLeft.X;
		KnotNode->NodePosY = KnotTopLeft.Y;

		// Move the connections across (only notifying the knot, 
		// as the other two didn't really change)
		if (PinB != nullptr)
		{
			PinA->BreakLinkTo(PinB);
		}
		PinA->MakeLinkTo(PinA->Direction == EGPD_Output ? KnotNode->GetInputPin() : KnotNode->GetOutputPin());

		if (PinB != nullptr)
		{
			PinB->MakeLinkTo(PinB->Direction == EGPD_Output ? KnotNode->GetInputPin() : KnotNode->GetOutputPin());
		}

		// Blueprint stuff
		KnotNode->PostReconstructNode();

		// Dirty the blueprint
		UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraphChecked(CastChecked<UEdGraph>(ParentGraph));
		FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
	}
}

void FBAUtils::DisconnectKnotNode(UEdGraphNode* Node)
{
	if (!Node)
		return;

	UEdGraphPin* InputPin = GetPinsByDirection(Node, EGPD_Input)[0];
	UEdGraphPin* OutputPin = GetPinsByDirection(Node, EGPD_Output)[0];

	// link connections of the knot node
	if (InputPin->LinkedTo.Num() > 0 && OutputPin->LinkedTo.Num() > 0)
	{
		TArray<UEdGraphPin*> InputPinsLinked = InputPin->LinkedTo;
		TArray<UEdGraphPin*> OutputPinsLinked = OutputPin->LinkedTo;

		for (UEdGraphPin* PinA : InputPinsLinked)
		{
			InputPin->BreakLinkTo(PinA);

			for (UEdGraphPin* PinB : OutputPinsLinked)
			{
				OutputPin->BreakLinkTo(PinB);
				PinA->MakeLinkTo(PinB);
			}
		}
	}

	Node->BreakAllNodeLinks();
}

bool FBAUtils::IsNodePure(UEdGraphNode* Node)
{
	return !IsNodeImpure(Node);
}

bool FBAUtils::IsNodeImpure(UEdGraphNode* Node)
{
	return Node->Pins.ContainsByPredicate(IsExecPin);
}

bool FBAUtils::IsPinLinked(const UEdGraphPin* Pin)
{
	return Pin->LinkedTo.Num() > 0;
}

bool FBAUtils::IsPinUnlinked(const UEdGraphPin* Pin)
{
	return !IsPinLinked(Pin);
}

bool FBAUtils::IsExecPin(const UEdGraphPin* Pin)
{
	auto Graph = Pin->GetOwningNodeUnchecked()->GetGraph();
	if (IsMaterialGraph(Graph))
	{
		return true;
	// 	return
	// 		Pin->PinType.PinSubCategory != UMaterialGraphSchema::PSC_Red &&
	// 		Pin->PinType.PinSubCategory != UMaterialGraphSchema::PSC_Green &&
	// 		Pin->PinType.PinSubCategory != UMaterialGraphSchema::PSC_Blue &&
	// 		Pin->PinType.PinSubCategory != UMaterialGraphSchema::PSC_Alpha &&
	// 		Pin->PinType.PinSubCategory != UMaterialGraphSchema::PSC_RGBA;
	}

	if (IsSoundCueGraph(Graph))
	{
		return true;
	}

	if (IsBehaviorTreeGraph(Graph))
	{
		return true;
	}

	if (IsNiagaraGraph(Graph))
	{
		return true;
		// return Pin->PinType.PinSubCategory == UEdGraphSchema_Niagara::PinCategoryType;
	}

	if (IsAnimationGraph(Graph))
	{
		return true;
		// return Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Struct;
	}
	
	return Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec;
}

bool FBAUtils::IsDelegatePin(const UEdGraphPin* Pin)
{
	return Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Delegate;
}

int FBAUtils::GetPinIndex(UEdGraphPin* Pin)
{
	int PinIndex = -1;
	GetPinsByDirection(Pin->GetOwningNode(), Pin->Direction).Find(Pin, PinIndex);
	return PinIndex;
}

int FBAUtils::GetLinkedPinIndex(UEdGraphPin* Pin)
{
	int PinIndex;
	GetLinkedPins(Pin->GetOwningNode(), Pin->Direction).Find(Pin, PinIndex);
	return PinIndex;
}

TSet<UEdGraphNode*> FBAUtils::GetNodeTreeWithFilter(UEdGraphNode* InitialNode, TFunctionRef<bool(UEdGraphPin*)> Pred, EEdGraphPinDirection Direction, bool bOnlyInitialDirection)
{
	TSet<UEdGraphNode*> NodeTree;
	TSet<UEdGraphNode*> VisitedNodes;
	VisitedNodes.Add(InitialNode);
	TQueue<UEdGraphNode*> NodeQueue;

	NodeQueue.Enqueue(InitialNode);

	while (!NodeQueue.IsEmpty())
	{
		UEdGraphNode* NextNode;
		NodeQueue.Dequeue(NextNode);
		NodeTree.Add(NextNode);

		EEdGraphPinDirection PinsDirection = Direction;

		if (bOnlyInitialDirection && NextNode != InitialNode)
			PinsDirection = EGPD_MAX;

		for (UEdGraphPin* LinkedPin : GetLinkedToPins(NextNode, PinsDirection).FilterByPredicate(Pred))
		{
			UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();

			if (VisitedNodes.Contains(LinkedNode))
				continue;

			NodeQueue.Enqueue(LinkedNode);
			VisitedNodes.Add(LinkedNode);
		}
	}

	return NodeTree;
}

TSet<UEdGraphNode*> FBAUtils::GetNodeTreeWithFilter(UEdGraphNode* InitialNode, TFunctionRef<bool(const FPinLink&)> Pred,
	EEdGraphPinDirection Direction, bool bOnlyInitialDirection)
{
	TSet<UEdGraphNode*> NodeTree;
	TSet<UEdGraphNode*> VisitedNodes;
	VisitedNodes.Add(InitialNode);
	TQueue<UEdGraphNode*> NodeQueue;

	NodeQueue.Enqueue(InitialNode);

	while (!NodeQueue.IsEmpty())
	{
		UEdGraphNode* NextNode;
		NodeQueue.Dequeue(NextNode);
		NodeTree.Add(NextNode);

		EEdGraphPinDirection PinsDirection = Direction;

		if (bOnlyInitialDirection && NextNode != InitialNode)
			PinsDirection = EGPD_MAX;

		auto PinLinks = GetPinLinks(NextNode, PinsDirection).FilterByPredicate(Pred);
		
		for (const FPinLink& PinLink : PinLinks)
		{
			UEdGraphPin* LinkedPin = PinLink.To;
			
			UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();
			if (VisitedNodes.Contains(LinkedNode))
				continue;

			NodeQueue.Enqueue(LinkedNode);
			VisitedNodes.Add(LinkedNode);
		}
	}

	return NodeTree;
}

TSet<UEdGraphNode*> FBAUtils::GetNodeTree(UEdGraphNode* InitialNode, const EEdGraphPinDirection Direction, bool bOnlyInitialDirection)
{
	return GetNodeTreeWithFilter(InitialNode, [](UEdGraphPin*) { return true; }, Direction, bOnlyInitialDirection);
}

TSet<UEdGraphNode*> FBAUtils::GetExecTree(UEdGraphNode* Node, EEdGraphPinDirection Direction, bool bOnlyInitialDirection)
{
	return GetExecutionTreeWithFilter(Node, [](UEdGraphNode* Node) { return true; }, Direction, bOnlyInitialDirection);
}

TSet<UEdGraphNode*> FBAUtils::GetExecutionTreeWithFilter(UEdGraphNode* InitialNode, TFunctionRef<bool(UEdGraphNode*)> Pred, EEdGraphPinDirection Direction, bool bOnlyInitialDirection)
{
	TSet<UEdGraphNode*> NodeTree;
	TSet<UEdGraphNode*> VisitedNodes;
	VisitedNodes.Add(InitialNode);
	TQueue<UEdGraphNode*> NodeQueue;

	NodeQueue.Enqueue(InitialNode);

	while (!NodeQueue.IsEmpty())
	{
		UEdGraphNode* NextNode;
		NodeQueue.Dequeue(NextNode);
		NodeTree.Add(NextNode);

		const EEdGraphPinDirection PinsDirection = Direction;

		if (bOnlyInitialDirection && NextNode != InitialNode)
			Direction = EGPD_MAX;

		TArray<UEdGraphNode*> LinkedNodes = GetLinkedNodesFromPins(GetExecPins(NextNode, PinsDirection));

		for (UEdGraphNode* LinkedNode : LinkedNodes)
		{
			if (VisitedNodes.Contains(LinkedNode))
				continue;

			if (!Pred(LinkedNode))
				continue;

			NodeQueue.Enqueue(LinkedNode);
			VisitedNodes.Add(LinkedNode);
		}
	}

	return NodeTree;
}

TSet<UEdGraphNode*> FBAUtils::GetEdGraphNodeTree(
	UEdGraphNode* InitialNode,
	const EEdGraphPinDirection Direction)
{
	// if the initial node is pure, find the first impure node in the tree
	if (IsNodePure(InitialNode))
	{
		TQueue<UEdGraphNode*> NodeQueue;
		TSet<UEdGraphNode*> VisitedNodes;

		VisitedNodes.Add(InitialNode);
		NodeQueue.Enqueue(InitialNode);

		while (!NodeQueue.IsEmpty())
		{
			UEdGraphNode* NextNode;
			NodeQueue.Dequeue(NextNode);

			TArray<UEdGraphNode*> LinkedOutputNodes = GetLinkedNodes(NextNode);
			bool bFoundExecNode = false;
			for (UEdGraphNode* LinkedNode : LinkedOutputNodes)
			{
				if (VisitedNodes.Contains(LinkedNode))
					continue;

				VisitedNodes.Add(LinkedNode);

				if (IsNodeImpure(LinkedNode))
				{
					InitialNode = LinkedNode;
					bFoundExecNode = true;
					break;
				}

				NodeQueue.Enqueue(LinkedNode);
			}

			if (bFoundExecNode)
				break;
		}
	}

	TSet<UEdGraphNode*> NodeTree;
	TSet<UEdGraphNode*> VisitedNodes;
	TQueue<UEdGraphNode*> NodeQueue;

	NodeQueue.Enqueue(InitialNode);

	// find all connected impure nodes
	while (!NodeQueue.IsEmpty())
	{
		UEdGraphNode* NextNode;
		NodeQueue.Dequeue(NextNode);

		NodeTree.Add(NextNode);

		// add the input parameter tree
		TQueue<UEdGraphNode*> ParameterQueue;
		TSet<UEdGraphNode*> VisitedParameters;
		ParameterQueue.Enqueue(NextNode);
		while (!ParameterQueue.IsEmpty())
		{
			UEdGraphNode* ParameterNode;
			ParameterQueue.Dequeue(ParameterNode);

			TArray<UEdGraphNode*> LinkedPureNodes =
				GetLinkedNodes(ParameterNode).FilterByPredicate(IsNodePure);
			for (UEdGraphNode* LinkedNode : LinkedPureNodes)
			{
				if (VisitedParameters.Contains(LinkedNode))
					continue;

				VisitedParameters.Add(LinkedNode);

				ParameterQueue.Enqueue(LinkedNode);
				NodeTree.Add(LinkedNode);
			}
		}

		// iterate over linked impure nodes
		TArray<UEdGraphPin*> LinkedExecPins =
			GetLinkedPins(NextNode, Direction).FilterByPredicate(IsExecPin);
		for (UEdGraphPin* LinkedPin : LinkedExecPins)
		{
			for (UEdGraphPin* LinkedTo : LinkedPin->LinkedTo)
			{
				UEdGraphNode* LinkedNode = LinkedTo->GetOwningNode();
				if (VisitedNodes.Contains(LinkedNode))
					continue;

				NodeQueue.Enqueue(LinkedNode);
				VisitedNodes.Add(LinkedNode);
			}
		}
	}

	return NodeTree;
}

bool FBAUtils::TryLinkImpureNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB)
{
	TArray<UEdGraphPin*> OutExecPinsA = GetExecPins(NodeA, EGPD_Output);
	TArray<UEdGraphPin*> InExecPinsB = GetExecPins(NodeB, EGPD_Input);

	if (OutExecPinsA.Num() == 0 || InExecPinsB.Num() == 0)
		return false;

	UEdGraphPin* PinA = OutExecPinsA[0];
	UEdGraphPin* PinB = InExecPinsB[0];

	return TryCreateConnection(PinA, PinB);
}

UEdGraphPin* FBAUtils::GetFirstExecPin(UEdGraphNode* Node, EEdGraphPinDirection Direction)
{
	TArray<UEdGraphPin*> Pins = GetExecPins(Node, Direction);
	return Pins.Num() == 0 ? nullptr : Pins[0];
}

UEdGraphNode* FBAUtils::GetFirstLinkedNode(UEdGraphNode* Node, EEdGraphPinDirection Direction)
{
	if (UEdGraphPin* ExecPin = GetFirstExecPin(Node, Direction))
	{
		if (ExecPin->LinkedTo.Num() > 0)
		{
			return ExecPin->LinkedTo[0]->GetOwningNode();
		}
	}

	return nullptr;
}

void FBAUtils::PrintNodeInfo(UEdGraphNode* Node)
{
	const UEdGraphNode* EdGraphNode = Cast<UEdGraphNode>(Node);
	if (EdGraphNode == nullptr)
		return;

	UE_LOG(LogBlueprintAssist, Warning, TEXT("### BEGIN print node <%s (%s)> info"), *EdGraphNode->GetName(), *EdGraphNode->GetClass()->GetFName().ToString());
	for (UEdGraphPin* Pin : EdGraphNode->Pins)
	{
		UE_LOG(LogBlueprintAssist, Warning, TEXT("\tPin <%s> | <%s> | <%s> | <%s>"),
		       *Pin->GetDisplayName().ToString(),
		       *FString(Pin->Direction == EGPD_Input ? "In" : "Out"),
		       *Pin->PinType.PinCategory.ToString(),
		       *Pin->PinType.PinSubCategory.ToString());
	}
	UE_LOG(LogBlueprintAssist, Warning, TEXT("### END print node <%s> info"), *EdGraphNode->GetName());
}

bool FBAUtils::IsKnotNode(UEdGraphNode* Node)
{
	if (Cast<UK2Node_Knot>(Node))
		return true;

	if (Cast<UMaterialGraphNode_Knot>(Node))
		return true;

	return false;
}

bool FBAUtils::IsCommentNode(UEdGraphNode* Node)
{
	const UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(Node);
	return CommentNode != nullptr;
}

bool FBAUtils::IsVarNode(UEdGraphNode* Node)
{
	const UK2Node_Variable* VarNode = Cast<UK2Node_Variable>(Node);
	return VarNode != nullptr;
}

bool FBAUtils::IsK2Node(UEdGraphNode* Node)
{
	if (Node == nullptr)
		return false;

	const UK2Node* K2Node = Cast<UK2Node>(Node);
	return K2Node != nullptr;
}

bool FBAUtils::IsK2Node_BaseAsyncTask(UEdGraphNode* Node)
{
	const UK2Node_BaseAsyncTask* VarNode = Cast<UK2Node_BaseAsyncTask>(Node);
	return VarNode != nullptr;
}

TEnumAsByte<EBAGraphType> FBAUtils::GetBAGraphType(UEdGraph* Graph)
{
	if (IsBehaviorTreeGraph(Graph))
		return BAGraphType_BehaviorTree;

	if (IsSoundCueGraph(Graph))
		return BAGraphType_SoundCue;

	if (IsMaterialGraph(Graph))
		return BAGraphType_MaterialGraph;

	if (IsNiagaraGraph(Graph))
		return BAGraphType_NiagaraGraph;

	if (IsAnimationGraph(Graph))
		return BAGraphType_AnimGraph;

	if (IsBlueprintGraph(Graph))
		return BAGraphType_Blueprint;

	return BAGraphType_Unknown;
}

FString FBAUtils::GetBAGraphTypeAsString(UEdGraph* Graph)
{
	switch (GetBAGraphType(Graph).GetValue())
	{
	case BAGraphType_Blueprint: return FString("Blueprint");
	case BAGraphType_SoundCue: return FString("Sound Cue");
	case BAGraphType_BehaviorTree: return FString("Behavior Tree");
	case BAGraphType_MaterialGraph: return FString("Material Graph");
	case BAGraphType_NiagaraGraph: return FString("Niagara Graph");
	case BAGraphType_AnimGraph: return FString("Anim Graph");
	default: return FString("Unknown");
	}
}

bool FBAUtils::IsValidGraph(UEdGraph* Graph)
{
	const EBAGraphType GraphType = GetBAGraphType(Graph);
	UBASettings* Settings = GetMutableDefault<UBASettings>();
	return  !Settings->DisabledGraphs.Contains(GraphType);
}

bool FBAUtils::IsBlueprintGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Cast<UEdGraphSchema_K2>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsBehaviorTreeGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Cast<UEdGraphSchema_BehaviorTree>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsSoundCueGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Cast<USoundCueGraphSchema>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsMaterialGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Cast<UMaterialGraphSchema>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsNiagaraGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Graph->GetClass()->GetFName() == "NiagaraGraph";
	// return Cast<UEdGraphSchema_Niagara>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsAnimationGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
		return false;

	return Cast<UAnimationGraphSchema>(Graph->GetSchema()) != nullptr;
}

bool FBAUtils::IsGraphNode(UEdGraphNode* Node)
{
	if (Node == nullptr)
		return false;

	return IsBlueprintNode(Node) || IsBehaviorTreeNode(Node) || IsMaterialNode(Node) || IsSoundCueNode(Node) || IsNiagaraNode(Node);

	// TODO: support these graphs
	bool bValidEnvironmentQueryNode = false;
}

bool FBAUtils::IsBlueprintNode(UEdGraphNode* Node)
{
	return IsK2Node(Node) && !IsCommentNode(Node) && !IsKnotNode(Node) && !IsK2Node_BaseAsyncTask(Node);
}

bool FBAUtils::IsBehaviorTreeNode(UEdGraphNode* Node)
{
	if (Node == nullptr)
		return false;

	// TODO: UBehaviorTreeGraphNode is private, so instead I'm casting to the base class
	// The only other class that inherits from AIGraphNode is UEnvironmentQueryGraphNode
	// look at that class later
	const UAIGraphNode* BTNode = Cast<UAIGraphNode>(Node);
	return BTNode != nullptr;
}

bool FBAUtils::IsSoundCueNode(UEdGraphNode* Node)
{
	if (Cast<USoundCueGraphNode>(Node) != nullptr)
		return true;

	// TODO: Once this deprecated thing is gone, pass graphpanel to this function so we can call GetGraphNode
	if (Node->DEPRECATED_NodeWidget.IsValid())
	{
		FString NodeType = Node->DEPRECATED_NodeWidget.Pin()->GetTypeAsString();

		return NodeType == "SGraphNodeSoundResult";
	}

	return false;
}

bool FBAUtils::IsMaterialNode(UEdGraphNode* Node)
{
	if (!Node)
	{
		return false;
	}
	
	const bool bValidMaterialNode = Cast<UMaterialGraphNode>(Node) != nullptr;
	if (bValidMaterialNode)
		return true;

	// TODO: Once this deprecated thing is gone, pass graphpanel to this function so we can call GetGraphNode
	if (Node->DEPRECATED_NodeWidget.IsValid())
	{
		FString NodeType = Node->DEPRECATED_NodeWidget.Pin()->GetTypeAsString();

		return NodeType == "SGraphNodeMaterialResult";
	}

	return false;
}

bool FBAUtils::IsNiagaraNode(UEdGraphNode* Node)
{
	if (!Node)
	{
		return false;
	}

	if (Node->DEPRECATED_NodeWidget.IsValid())
	{
		FString NodeType = Node->DEPRECATED_NodeWidget.Pin()->GetTypeAsString();
		return NodeType.Contains("Niagara");
	}
	
	return false;
	// return Cast<UNiagaraNode>(Node) != nullptr;
}

bool FBAUtils::IsEventNode(UEdGraphNode* Node)
{
	// only has output exec pins
	if (IsBlueprintNode(Node))
	{
		return GetExecPins(Node, EGPD_Input).Num() == 0 && GetExecPins(Node, EGPD_Output).Num() > 0;
	}

	return false;
}

bool FBAUtils::TryCreateConnection(
	UEdGraphPin* PinA,
	UEdGraphPin* PinB,
	const bool bBreakLinks /*= false*/,
	const bool bConversionAllowed /*= false*/,
	const bool bTryHidden /*= false*/)
{
	if (!bTryHidden && PinB->bHidden)
		return false;

	if (!PinA || !PinB)
		return false;

	auto NodeA = PinA->GetOwningNodeUnchecked();
	auto Schema = NodeA->GetGraph()->GetSchema();
	const FPinConnectionResponse Response = Schema->CanCreateConnection(PinA, PinB);
	bool bModified = false;

	TArray<UEdGraphPin*> PreviouslyLinked = PinA->LinkedTo;

	ECanCreateConnectionResponse NewResponse = Response.Response;

	if (bBreakLinks && (
		Response.Response == CONNECT_RESPONSE_MAKE ||
		Response.Response == CONNECT_RESPONSE_BREAK_OTHERS_A ||
		Response.Response == CONNECT_RESPONSE_BREAK_OTHERS_B))
	{
		NewResponse = CONNECT_RESPONSE_BREAK_OTHERS_AB;
	}

	switch (NewResponse)
	{
	case CONNECT_RESPONSE_MAKE:
		PinA->Modify();
		PinB->Modify();
		PinA->MakeLinkTo(PinB);
		bModified = true;
		break;

	case CONNECT_RESPONSE_BREAK_OTHERS_A:
		PinA->Modify();
		PinB->Modify();
		PinA->BreakAllPinLinks();
		PinA->MakeLinkTo(PinB);
		bModified = true;
		break;

	case CONNECT_RESPONSE_BREAK_OTHERS_B:
		PinA->Modify();
		PinB->Modify();
		PinB->BreakAllPinLinks();
		PinA->MakeLinkTo(PinB);
		bModified = true;
		break;

	case CONNECT_RESPONSE_BREAK_OTHERS_AB:
		{
			PinA->Modify();
			PinB->Modify();
			PinA->BreakAllPinLinks();
			PinB->BreakAllPinLinks();

			PinA->MakeLinkTo(PinB);

			bModified = true;
			break;
		}
	case CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE:
		if (bConversionAllowed)
			bModified = Schema->CreateAutomaticConversionNodeAndConnections(PinA, PinB);
		break;
	case CONNECT_RESPONSE_DISALLOW:
		break;
	default:
		break;
	}

#if WITH_EDITOR
	if (bModified)
	{
		PinA->GetOwningNode()->PinConnectionListChanged(PinA);
		PinB->GetOwningNode()->PinConnectionListChanged(PinB);

		PinA->GetOwningNode()->NodeConnectionListChanged();
		PinB->GetOwningNode()->NodeConnectionListChanged();
	}
#endif

	return bModified;
}

FString FBAUtils::GetNodeName(UEdGraphNode* Node)
{
	if (Node == nullptr)
		return FString("nullptr");

	return Node->GetNodeTitle(ENodeTitleType::ListView).ToString();
}

FSlateRect FBAUtils::FSlateRectFromVectors(const FVector2D& A, const FVector2D& B)
{
	return FSlateRect(
		FMath::Min(A.X, B.X),
		FMath::Min(A.Y, B.Y),
		FMath::Max(A.X, B.X),
		FMath::Max(A.Y, B.Y));
}

int FBAUtils::DistanceSquaredBetweenNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB)
{
	const int DeltaX = NodeA->NodePosX - NodeB->NodePosX;
	const int DeltaY = NodeA->NodePosY - NodeB->NodePosY;
	return DeltaX * DeltaX + DeltaY * DeltaY;
}

bool FBAUtils::LineRectIntersection(
	const FSlateRect& Rect,
	const FVector2D& Start,
	const FVector2D& End)
{
	const FVector Min3D(Rect.GetTopLeft(), -1.f);
	const FVector Max3D(Rect.GetBottomRight(), 1.f);
	const FBox Box(Min3D, Max3D);

	const FVector Start3D(Start, 0.f);
	const FVector End3D(End, 0.f);
	const FVector StartToEnd3D = End3D - Start3D;

	return FMath::LineBoxIntersection(Box, Start3D, End3D, StartToEnd3D);
}

void FBAUtils::SetNodePosY(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	UEdGraphNode* Node,
	const int NewY)
{
	const FSlateRect NodeBounds = GetCachedNodeBounds(GraphHandler, Node);
	const float DeltaY = NewY - NodeBounds.Top;
	Node->NodePosY += DeltaY;
}

void FBAUtils::SetNodePos(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	UEdGraphNode* Node,
	const int NewX,
	const int NewY)
{
	Node->NodePosX = NewX;
	SetNodePosY(GraphHandler, Node, NewY);
}

void FBAUtils::SetNodePos(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	UEdGraphNode* Node,
	const FVector2D& NewPos)
{
	SetNodePos(GraphHandler, Node, NewPos.X, NewPos.Y);
}

FString FBAUtils::GraphTypeToString(const EGraphType GraphType)
{
	switch (GraphType)
	{
	case GT_Function:
		return FString("Function");
	case GT_Ubergraph:
		return FString("Graph");
	case GT_Macro:
		return FString("Macro");
	case GT_Animation:
		return FString("Animation");
	case GT_StateMachine:
		return FString("StateMachine");
	case GT_MAX:
		return FString("MAX");
	default:
		return FString("BlueprintAssistUtils::GraphTypeToString: ERROR");
	}
}

EGraphType FBAUtils::GetGraphType(UEdGraph* Graph)
{
	return Graph->GetSchema()->GetGraphType(Graph);
}

bool FBAUtils::IsInputNode(UEdGraphNode* Node)
{
	return
		Cast<UK2Node_InputAction>(Node) || Cast<UK2Node_InputActionEvent>(Node) ||
		Cast<UK2Node_InputTouch>(Node) || Cast<UK2Node_InputTouchEvent>(Node) ||
		Cast<UK2Node_InputAxisEvent>(Node) ||
		Cast<UK2Node_InputAxisKeyEvent>(Node) ||
		Cast<UK2Node_InputKey>(Node) || Cast<UK2Node_InputKeyEvent>(Node) ||
		Cast<UK2Node_InputVectorAxisEvent>(Node);
}

void FBAUtils::StraightenPin(
	TSharedPtr<FBAGraphHandler> GraphHandler,
	UEdGraphPin* SourcePin,
	UEdGraphPin* PinToAlign)
{
	UEdGraphNode* NodeToAlign = PinToAlign->GetOwningNode();
	const float DeltaY = GraphHandler->GetPinY(SourcePin) - GraphHandler->GetPinY(PinToAlign);
	NodeToAlign->NodePosY += FMath::RoundToInt(DeltaY);
}

bool FBAUtils::IsNodeVisible(TSharedPtr<SGraphPanel> GraphPanel, UEdGraphNode* Node)
{
	if (!GraphPanel.IsValid())
		return false;

	const FSlateRect NodeBounds = GetNodeBounds(Node);
	return GraphPanel->IsRectVisible(NodeBounds.GetTopLeft(), NodeBounds.GetBottomRight());
}

FString FBAUtils::GetPinName(UEdGraphPin* Pin)
{
	if (Pin == nullptr)
		return FString("nullptr");

	if (Pin->PinFriendlyName.IsEmpty())
	{
		return Pin->GetName().Replace(TEXT(" "), TEXT(""));
	}
	else
	{
		return Pin->PinFriendlyName.ToString();
	}
}

TSharedPtr<SWidget> FBAUtils::GetChildWidget(
	TSharedPtr<SWidget> Widget,
	const FString& WidgetClassName,
	bool bCheckContains)
{
	if (Widget.IsValid())
	{
		const bool bFoundWidget
			= bCheckContains
			? Widget->GetTypeAsString().Contains(WidgetClassName)
			: Widget->GetTypeAsString() == WidgetClassName;

		if (bFoundWidget)
		{
			return Widget;
		}

		// iterate through children
		FChildren* Children = Widget->GetChildren();
		for (int i = 0; i < Children->Num(); i++)
		{
			TSharedPtr<SWidget> ReturnWidget = GetChildWidget(
				Children->GetChildAt(i),
				WidgetClassName);
			if (ReturnWidget.IsValid())
			{
				return ReturnWidget;
			}
		}
	}

	return nullptr;
}

void FBAUtils::GetChildWidgets(
	TSharedPtr<SWidget> Widget,
	const FString& WidgetClassName,
	TArray<TSharedPtr<SWidget>>& OutWidgets,
	bool bCheckContains)
{
	if (Widget.IsValid())
	{
		const bool bFoundWidget
			= bCheckContains
			? Widget->GetTypeAsString().Contains(WidgetClassName)
			: Widget->GetTypeAsString() == WidgetClassName;

		if (bFoundWidget)
		{
			OutWidgets.Add(Widget);
		}

		// iterate through children
		FChildren* Children = Widget->GetChildren();
		for (int i = 0; i < Children->Num(); i++)
		{
			GetChildWidgets(Children->GetChildAt(i), WidgetClassName, OutWidgets);
		}
	}
}

TSharedPtr<SWidget> FBAUtils::GetParentWidgetOfType(
	TSharedPtr<SWidget> Widget,
	const FString& ParentType)
{
	if (!Widget.IsValid())
		return nullptr;

	if (Widget->GetTypeAsString().Contains(ParentType))
		return Widget;

	if (!Widget->IsParentValid())
		return nullptr;

	check(Widget->GetParentWidget() != Widget)

	TSharedPtr<SWidget> ReturnWidget = GetParentWidgetOfType(Widget->GetParentWidget(), ParentType);
	if (ReturnWidget.IsValid())
		return ReturnWidget;

	return nullptr;
}

TSharedPtr<SGraphNode> FBAUtils::GetGraphNode(
	TSharedPtr<SGraphPanel> GraphPanel,
	UEdGraphNode* Node)
{
	if (Node == nullptr || !GraphPanel.IsValid())
		return nullptr;

	TSharedPtr<SGraphNode> GraphNode_GUID = GraphPanel->GetNodeWidgetFromGuid(Node->NodeGuid);
	if (GraphNode_GUID.IsValid())
		return GraphNode_GUID;

	FChildren* Children = GraphPanel->GetChildren();
	for (int i = 0; i < Children->Num(); i++)
	{
		TSharedPtr<SGraphNode> GraphNode = StaticCastSharedRef<SGraphNode>(Children->GetChildAt(i));

		if (GraphNode.IsValid())
		{
			if (GraphNode->GetNodeObj() == Node)
			{
				return GraphNode;
			}
		}
	}

	return nullptr;
}

TSharedPtr<SGraphPin> FBAUtils::GetGraphPin(TSharedPtr<SGraphPanel> GraphPanel, UEdGraphPin* Pin)
{
	if (Pin == nullptr || !GraphPanel.IsValid())
		return nullptr;

	TSharedPtr<SGraphNode> GraphNode = GetGraphNode(GraphPanel, Pin->GetOwningNode());
	return GraphNode.IsValid() ? GraphNode->FindWidgetForPin(Pin) : nullptr;
}

TSharedPtr<SGraphPin> FBAUtils::GetHoveredGraphPin(TSharedPtr<SGraphPanel> GraphPanel)
{
	if (!GraphPanel.IsValid())
		return nullptr;

	UEdGraph* Graph = GraphPanel->GetGraphObj();
	if (Graph == nullptr)
		return nullptr;

	const bool bIsMaterialGraph = FBAUtils::IsMaterialGraph(Graph);
	
	// check if graph pin "IsHovered" function
	for (UEdGraphNode* Node : Graph->Nodes)
	{
		for (UEdGraphPin* Pin : Node->Pins)
		{
			if (!Pin->bHidden)
			{
				TSharedPtr<SGraphPin> GraphPin = GetGraphPin(GraphPanel, Pin);
				if (GraphPin.IsValid())
				{
					// TODO: annoying bug where hover state can get locked if the panel is frozen and you move the cursor too fast
					const bool bIsHovered =  bIsMaterialGraph ? GraphPin->IsDirectlyHovered() : GraphPin->IsHovered(); 
					if (bIsHovered)
					{
						return GraphPin;
					}
				}
			}
		}
	}

	return nullptr;
}

TSharedPtr<SGraphNode> FBAUtils::GetHoveredGraphNode(TSharedPtr<SGraphPanel> GraphPanel)
{
	if (!GraphPanel.IsValid())
		return nullptr;

	UEdGraph* Graph = GraphPanel->GetGraphObj();
	if (Graph == nullptr)
		return nullptr;

	for (UEdGraphNode* Node : Graph->Nodes)
	{
		TSharedPtr<SGraphNode> GraphNode = FBAUtils::GetGraphNode(GraphPanel, Node);
		if (GraphNode.IsValid())
		{
			if (GraphNode->GetCachedGeometry().IsUnderLocation(
				FSlateApplication::Get().GetCursorPos()))
			{
				return GraphNode;
			}
		}
	}

	return nullptr;
}

void FBAUtils::PrintChildWidgets(TSharedPtr<SWidget> Widget)
{
	if (Widget.IsValid())
	{
		UE_LOG(
			LogBlueprintAssist,
			Warning,
			TEXT("ChildWidget: %s | %s"),
			*Widget->GetTypeAsString(),
			*Widget->ToString());
		FChildren* Children = Widget->GetChildren();
		for (int i = 0; i < Children->Num(); i++)
		{
			PrintChildWidgets(Children->GetChildAt(i));
		}
	}
}

int32 FBAUtils::SnapToGrid(const float& InFloat)
{
	if (InFloat != 0)
	{
		const float SnapSize = SNodePanel::GetSnapGridSize();
		return FMath::RoundToInt(SnapSize * FMath::RoundToFloat(InFloat / SnapSize));
	}

	return 0;
}

bool FBAUtils::IsUserInputWidget(TSharedPtr<SWidget> Widget)
{
	const FString Type = Widget->GetTypeAsString();
	if (Type == "SEditableText" ||
		Type == "SMultiLineEditableTextBox" ||
		Type == "SMultiLineEditableText" ||
		Type == "SSearchBox")
		return true;

	const bool Contains = Type.Contains("SSpinBox");
	return Contains;
}

bool FBAUtils::IsClickableWidget(TSharedPtr<SWidget> Widget)
{
	const FString Type = Widget->GetTypeAsString();
	if (Type == "SComboBox" ||
		Type == "SComponentClassCombo" ||
		Type == "SCheckBox" ||
		Type == "SColorBlock")
		return true;

	const bool Contains = Type.Contains("Button");
	return Contains;
}

FVector2D FBAUtils::GraphCoordToPanelCoord(
	TSharedPtr<SGraphPanel> GraphPanel,
	const FVector2D& PanelSpaceCoordinate)
{
	return (GraphPanel->GetCachedGeometry().LocalToAbsolute(PanelSpaceCoordinate) - GraphPanel->
		GetViewOffset()) * GraphPanel->GetZoomAmount();
}

bool FBAUtils::TryLinkPins(UEdGraphPin* Source, UEdGraphPin* Target, bool bInsertNode)
{
	UEdGraphNode* SourceNode = Source->GetOwningNode();
	const UEdGraphSchema* Schema = SourceNode->GetGraph()->GetSchema();

	if (bInsertNode && Target->LinkedTo.Num() == 1)
	{
		UEdGraphPin* PinAlreadyLinked = PinAlreadyLinked = Target->LinkedTo[0];

		for (UEdGraphPin* Pin : GetPinsByDirection(SourceNode, Target->Direction))
		{
			if (Schema->CanCreateConnection(Pin, PinAlreadyLinked).Response != CONNECT_RESPONSE_DISALLOW)
			{
				Target->BreakLinkTo(PinAlreadyLinked);
				Schema->TryCreateConnection(Pin, PinAlreadyLinked);
			}
		}
	}

	const bool bSuccess = Schema->TryCreateConnection(Source, Target);

	return bSuccess;
}

bool FBAUtils::CanConnectPins(
	UEdGraphPin* PinA,
	UEdGraphPin* PinB,
	bool bOverrideLinks,
	bool bAcceptConversions,
	bool bAcceptHiddenPins)
{
	if (PinA == nullptr || PinB == nullptr)
	{
		return false;
	}
	
	const UEdGraphSchema* Schema = PinA->GetOwningNodeUnchecked()->GetGraph()->GetSchema();
	ECanCreateConnectionResponse Response = Schema->CanCreateConnection(PinA, PinB).Response;

	if (!bAcceptHiddenPins && (PinA->bHidden || PinB->bHidden))
		return false;

	switch (Response)
	{
	case CONNECT_RESPONSE_MAKE:
		return true;
	case CONNECT_RESPONSE_DISALLOW:
		return false;
	case CONNECT_RESPONSE_BREAK_OTHERS_A:
		return bOverrideLinks;
	case CONNECT_RESPONSE_BREAK_OTHERS_B:
		return bOverrideLinks;
	case CONNECT_RESPONSE_BREAK_OTHERS_AB:
		return bOverrideLinks;
	case CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE:
		return bAcceptConversions;
	case CONNECT_RESPONSE_MAX:
		return false;
	default:
		return false;
	}
}

void FBAUtils::InteractWithWidget(TSharedPtr<SWidget> Widget)
{
	if (!Widget.IsValid())
		return;

	if (FBAUtils::IsClickableWidget(Widget))
	{
		if (Widget->GetTypeAsString() == "SComboButton" || Widget->GetTypeAsString() == "SComponentClassCombo")
		{
			TSharedPtr<SWidget> ChildButton = GetChildWidget(Widget, "SButton");
			if (ChildButton.IsValid())
				Widget = ChildButton;
		}

		// Not sure why check box is not working, but send a key event instead	
		if (Widget->GetTypeAsString() == "SCheckBox")
			//|| Widget->GetTypeAsString().Contains("Button"))
		{
			FKeyEvent KeyEvent(
				EKeys::Virtual_Accept,
				FModifierKeysState(),
				FSlateApplication::Get().GetUserIndexForKeyboard(),
				false,
				-1,
				-1);

			Widget->OnKeyDown(Widget->GetCachedGeometry(), KeyEvent);
			Widget->OnKeyUp(Widget->GetCachedGeometry(), KeyEvent);
			return;
		}

		TSet<FKey> PressedKeys;
		const FGeometry CachedGeometry = Widget->GetCachedGeometry();
		const FVector2D GeometryCenter = CachedGeometry.GetAbsolutePosition() + CachedGeometry.
			GetAbsoluteSize() * 0.5f;

		FPointerEvent PointerEvent(
			FSlateApplication::Get().CursorPointerIndex,
			GeometryCenter,
			GeometryCenter,
			PressedKeys,
			EKeys::LeftMouseButton,
			0.f,
			FModifierKeysState());

		FReply TheReply = Widget->OnMouseButtonDown(Widget->GetCachedGeometry(), PointerEvent);

		// Maybe we should use FSlateApplication::ProcessReply, but for now this works
		if (TheReply.ShouldSetUserFocus() || TheReply.GetUserFocusRecepient().IsValid())
		{
			FSlateApplication::Get().SetKeyboardFocus(TheReply.GetUserFocusRecepient());
		}

		Widget->OnMouseButtonUp(Widget->GetCachedGeometry(), PointerEvent);
	}
	else if (FBAUtils::IsUserInputWidget(Widget))
	{
		FSlateApplication::Get().SetKeyboardFocus(Widget, EFocusCause::Navigation);
	}
}

TSharedPtr<SWidget> FBAUtils::GetInteractableChildWidget(TSharedPtr<SWidget> Widget)
{
	struct FLocal
	{
		static TSharedPtr<SWidget> GetInteractableWidget(TSharedPtr<SWidget> CurrentWidget)
		{
			if (FBAUtils::IsUserInputWidget(CurrentWidget) || FBAUtils::IsClickableWidget(
				CurrentWidget))
			{
				return CurrentWidget;
			}

			FChildren* Children = CurrentWidget->GetChildren();
			for (int i = 0; i < Children->Num(); i++)
			{
				TSharedPtr<SWidget> OutWidget = GetInteractableWidget(Children->GetChildAt(i));
				if (OutWidget.IsValid())
				{
					return OutWidget;
				}
			}

			return nullptr;
		}
	};

	return FLocal::GetInteractableWidget(Widget);
}

void FBAUtils::GetInteractableChildWidgets(
	TSharedPtr<SWidget> Widget,
	TArray<TSharedPtr<SWidget>>& OutWidgets,
	bool bCheckEditable,
	bool bCheckClickable)
{
	struct FLocal
	{
		static void GetInteractableWidget(
			TSharedPtr<SWidget> CurrentWidget,
			TArray<TSharedPtr<SWidget>>& OutWidgets,
			bool bCheckEditable,
			bool bCheckClickable)
		{
			if ((bCheckEditable && FBAUtils::IsUserInputWidget(CurrentWidget)) ||
				(bCheckClickable && FBAUtils::IsClickableWidget(CurrentWidget)))
			{
				OutWidgets.Add(CurrentWidget);
			}

			FChildren* Children = CurrentWidget->GetChildren();
			for (int i = 0; i < Children->Num(); i++)
			{
				GetInteractableWidget(
					Children->GetChildAt(i),
					OutWidgets,
					bCheckEditable,
					bCheckClickable);
			}
		}
	};

	FLocal::GetInteractableWidget(Widget, OutWidgets, bCheckEditable, bCheckClickable);
}

UEdGraphNode* FBAUtils::GetTopMost(UEdGraphNode* Node, EEdGraphPinDirection Direction)
{
	const auto Pred = [](UEdGraphNode*) { return true; };
	return GetTopMostWithFilter(Node, Direction, Pred);
}

UEdGraphNode* FBAUtils::GetTopMostWithFilter(
	UEdGraphNode* Node,
	EEdGraphPinDirection Direction,
	TFunctionRef<bool (UEdGraphNode*)> Pred)
{
	struct FLocalInfo
	{
		UEdGraphNode* Node;
		int Top;
		int Right;

		FLocalInfo(UEdGraphNode* InNode, const int InTop, const int InRight)
			: Node(InNode)
			, Top(InTop)
			, Right(InRight)
		{
		}
	};

	struct FLocal
	{
		TArray<UEdGraphNode*> VisitedNodes;

		FLocalInfo Recursive_TopMost(
			FLocalInfo& Info,
			UEdGraphPin* InPin,
			const EEdGraphPinDirection InDirection,
			TFunctionRef<bool (UEdGraphNode*)> Pred)
		{
			TArray<EEdGraphPinDirection> InputOutput
				= InDirection == EGPD_Output
				? TArray<EEdGraphPinDirection>{EGPD_Input, EGPD_Output}
				: TArray<EEdGraphPinDirection>{EGPD_Output, EGPD_Input};

			const int32 PinIndex = InPin == nullptr
				? 0
				: FBAUtils::GetLinkedPins(Info.Node, InPin->Direction).IndexOfByKey(InPin);

			Info.Top -= PinIndex;

			TArray<FLocalInfo> Children;
			for (EEdGraphPinDirection Direction : InputOutput)
			{
				const int NewRight = Info.Right + (Direction == InDirection ? 1 : -1);
				int ChildIndexOffset = 0;
				for (UEdGraphPin* ParentPin : FBAUtils::GetLinkedPins(Info.Node, Direction))
				{
					for (UEdGraphPin* LinkedPin : ParentPin->LinkedTo)
					{
						UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();
						if (!Pred(LinkedNode))
							continue;

						const int NewTop = Info.Top + ChildIndexOffset;

						ChildIndexOffset += 1;

						if (VisitedNodes.Contains(LinkedNode))
							continue;

						VisitedNodes.Add(LinkedNode);

						FLocalInfo LinkedInfo(LinkedNode, NewTop, NewRight);
						Children.Add(
							Recursive_TopMost(LinkedInfo, LinkedPin, InDirection, Pred));
					}
				}
			}
			Children.Add(Info);

			const auto& TopRightMost = [](const FLocalInfo& A, const FLocalInfo& B)
			{
				if (A.Top != B.Top)
					return A.Top < B.Top;

				return A.Right > B.Right;
			};
			Children.Sort(TopRightMost);

			return Children[0];
		}
	};

	FLocal Local;
	FLocalInfo RootInfo(Node, 0, 0);
	return Local.Recursive_TopMost(RootInfo, nullptr, Direction, Pred).Node;
}

void FBAUtils::SafeDelete(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphNode* Node)
{
	TSharedPtr<SGraphEditor> FocusedGraphEd = GraphHandler->GetGraphEditor();
	if (!FocusedGraphEd.IsValid())
	{
		return;
	}

	FocusedGraphEd->GetCurrentGraph()->Modify();

	bool bNeedToModifyStructurally = false;

	//TODO: Make the rest of this code work to safely delete other kind of nodes

	//// this closes all the document that is outered by this node
	//// this is used by AnimBP statemachines/states that can create subgraph
	//auto CloseAllDocumentsTab = [](const UEdGraphNode* InNode)
	//{
	//	TArray<UObject*> NodesToClose;
	//	GetObjectsWithOuter(InNode, NodesToClose);
	//	for (UObject* Node : NodesToClose)
	//	{
	//		UEdGraph* NodeGraph = Cast<UEdGraph>(Node);
	//		if (NodeGraph)
	//		{
	//			TSharedRef<FTabPayload_UObject> Payload = FTabPayload_UObject::Make(DocumentID);
	//			DocumentManager->CloseTab(Payload);
	//		}
	//	}
	//};

	UEdGraph* Graph = Node->GetGraph();
	
	if (Node != nullptr)
	{
		if (Node->CanUserDeleteNode())
		{
			// // if it's state based anim node, make sure we close the sub graph first
			// / otherwise, we leave the orphan graph around
			// UAnimStateNodeBase* StateNode = Cast<UAnimStateNodeBase>(Node);
			// if (StateNode)
			// {
			// 	CloseAllDocumentsTab(StateNode);
			// }
			// else
			// {
			// 	const class UAnimGraphNode_StateMachineBase* SMNode = Cast<UAnimGraphNode_StateMachineBase>(Node);
			// 	if (SMNode)
			// 	{
			// 		CloseAllDocumentsTab(SMNode);
			// 	}
			// }
			//
			if (IsMaterialGraph(Graph))
			{
				TArray<UEdGraphNode*> NodesToDelete = { Node };
				FMaterialEditorUtilities::DeleteNodes(Graph, NodesToDelete);
				return;
			}

			if (IsSoundCueGraph(Graph)) // From FSoundCueEditor::DeleteSelectedNodes
			{
				FBlueprintEditorUtils::RemoveNode(nullptr, Node, true);

				if (USoundCueGraphNode* SoundGraphNode = Cast<USoundCueGraphNode>(Node))
				{
					USoundNode* DelNode = SoundGraphNode->SoundNode;

					USoundCue* SoundCue = Cast<USoundCueGraph>(Graph)->GetSoundCue();
					
					// Make sure SoundCue is updated to match graph
					SoundCue->CompileSoundNodesFromGraphNodes();
					
					// Remove this node from the SoundCue's list of all SoundNodes
					SoundCue->AllNodes.Remove(DelNode);
					SoundCue->MarkPackageDirty();
				}
				
				return;
			}

			if (IsBehaviorTreeGraph(Graph)) // From FAIGraphEditor::DeleteSelectedNodes
			{
				Graph->Modify();
				Node->Modify();
				Node->DestroyNode();
				return;
			}

			if (IsNiagaraGraph(Graph))
			{
				Graph->Modify();
				Node->Modify();
				Node->DestroyNode();
				return;
			}
			
			UK2Node* K2Node = Cast<UK2Node>(Node);
			if (K2Node != nullptr && K2Node->NodeCausesStructuralBlueprintChange())
			{
				bNeedToModifyStructurally = true;
			}
			
			//if (UK2Node_Composite* SelectedNode = Cast<UK2Node_Composite>(*NodeIt))
			//{
			//	//Close the tab for the composite if it was open
			//	if (SelectedNode->BoundGraph)
			//	{
			//		DocumentManager->CleanInvalidTabs();
			//	}
			//}
			//else if (UK2Node_Timeline* TimelineNode = Cast<UK2Node_Timeline>(*NodeIt))
			//{
			//	DocumentManager->CleanInvalidTabs();
			//}
			//AnalyticsTrackNodeEvent( GetBlueprintObj(), Node, true );
			
			UBlueprint* Blueprint = GraphHandler->GetBlueprint();
			if (Blueprint != nullptr)
			{
				FBlueprintEditorUtils::RemoveNode(Blueprint, Node, true);
			
				if (bNeedToModifyStructurally)
				{
					FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
				}
				else
				{
					FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
				}
			}
			else
			{
				UE_LOG(LogBlueprintAssist, Error, TEXT("Failed to delete node: Blueprint is null"));
			}
		}
	}
}

bool FBAUtils::IsPinLinkedToNode(UEdGraphPin* SourcePin, UEdGraphNode* NodeToCheck, const TSet<UEdGraphNode*>& IgnoredNodes)
{
	TSet<UEdGraphNode*> VisitedNodes;
	TArray<UEdGraphNode*> PendingNodes;

	VisitedNodes.Add(SourcePin->GetOwningNode());

	for (UEdGraphPin* Pin : SourcePin->LinkedTo)
	{
		if (FBAUtils::IsExecPin(Pin))
		{
			PendingNodes.Add(Pin->GetOwningNode());
			VisitedNodes.Add(Pin->GetOwningNode());
		}
	}

	while (PendingNodes.Num() > 0)
	{
		UEdGraphNode* NextNode = PendingNodes.Pop();

		if (NextNode == NodeToCheck)
			return true;

		if (IgnoredNodes.Contains(NextNode))
			continue;

		TArray<UEdGraphPin*> LinkedExecPins = FBAUtils::GetLinkedToPins(NextNode).FilterByPredicate(FBAUtils::IsExecPin);
		for (UEdGraphPin* Pin : LinkedExecPins)
		{
			if (VisitedNodes.Contains(Pin->GetOwningNode()))
				continue;

			VisitedNodes.Add(Pin->GetOwningNode());
			PendingNodes.Add(Pin->GetOwningNode());
		}
	}

	return false;
}

TArray<FPinLink> FBAUtils::GetPinLinks(UEdGraphNode* Node, EEdGraphPinDirection Direction)
{
	TArray<FPinLink> OutLinks;
	for (UEdGraphPin* Pin : GetLinkedPins(Node, Direction))
	{
		for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
		{
			OutLinks.Add(FPinLink(Pin, LinkedPin));
		}
	}

	return OutLinks;
}

UEdGraphPin* FBAUtils::GetPinFromGraph(const FGraphPinHandle& Handle, UEdGraph* Graph)
{
	for (auto Node : Graph->Nodes)
	{
		if (Node->NodeGuid == Handle.NodeGuid)
		{
			for (UEdGraphPin* Pin : Node->Pins)
			{
				if (Pin->PinId == Handle.PinId)
				{
					return Pin;
				}
			}
		}
	}

	return nullptr;
}

bool FBAUtils::IsExtraRootNode(UEdGraphNode* Node)
{
	return GetDefault<UBASettings>()->ExtraRootNodeTypes.Contains(Node->GetClass()->GetFName());
}

void FBAUtils::SwapNodes(UEdGraphNode* NodeA, UEdGraphNode* NodeB)
{
	if (NodeA == nullptr || NodeB == nullptr)
		return;
	
	TArray<UEdGraphPin*> NodeAPins = NodeA->Pins;
	TArray<UEdGraphPin*> NodeBPins = NodeB->Pins;

	TArray<FPinLink> PinsToLink;
	TSet<UEdGraphPin*> PinsConnected;

	// loop through our pins and check which pins can be connected to the new node
	for (int i = 0; i < 2; ++i)
	{
		for (UEdGraphPin* PinA : NodeAPins)
		{
			if (PinA->LinkedTo.Num() == 0)
				continue;

			if (PinsConnected.Contains(PinA))
				continue;

			for (UEdGraphPin* PinB : NodeBPins)
			{
				if (PinsConnected.Contains(PinB))
					continue;

				// on the first run (i = 0), we only use pins which have the same name
				if (FBAUtils::GetPinName(PinA) == FBAUtils::GetPinName(PinB) || i > 0)
				{
					TArray<UEdGraphPin*> LinkedToA = PinA->LinkedTo;
					TArray<UEdGraphPin*> LinkedToB = PinB->LinkedTo;

					auto LinkedToBoth = { LinkedToA, LinkedToB };
					
					bool bConnected = false;

					const auto AddLinks = [](const TArray<UEdGraphPin*>& First, const TArray<UEdGraphPin*> Second)
					{
						
					};
					
					for (UEdGraphPin* LinkedPin : LinkedToA)
					{
						if (FBAUtils::CanConnectPins(LinkedPin, PinB, true, false))
						{
							PinsToLink.Add(FPinLink(LinkedPin, PinB));
							PinsConnected.Add(PinA);
							PinsConnected.Add(PinB);
							bConnected = true;
						}
					}

					if (bConnected)
					{
						break;
					}
				}
			}
		}

		// link the pins marked in the last two loops
		for (auto& PinToLink : PinsToLink)
		{
			for (UEdGraphPin* Pin : NodeB->Pins)
			{
				if (Pin->PinId == PinToLink.To->PinId)
				{
					FBAUtils::TryCreateConnection(PinToLink.From, Pin);
					break;
					//UE_LOG(LogTemp, Warning, TEXT("\tConnected"));
				}
			}
		}
	}
}

TArray<UEdGraphNode*> FBAUtils::GetNodesUnderComment(UEdGraphNode_Comment* CommentNode)
{
	TArray<UEdGraphNode*> OutNodes;
	for (UObject* Obj : CommentNode->GetNodesUnderComment())
	{
		if (UEdGraphNode* Node = Cast<UEdGraphNode>(Obj))
		{
			OutNodes.Add(Node);
		}
	}

	return OutNodes;
}

TArray<UEdGraphNode_Comment*> FBAUtils::GetCommentNodesFromGraph(UEdGraph* Graph)
{
	TArray<UEdGraphNode_Comment*> Comments;
	for (auto Node : Graph->Nodes)
	{
		if (auto Comment = Cast<UEdGraphNode_Comment>(Node))
		{
			Comments.Add(Comment);
		}
	}

	return Comments;
}

TArray<UEdGraphNode_Comment*> FBAUtils::GetContainingCommentNodes(const TArray<UEdGraphNode_Comment*>& Comments,
	UEdGraphNode* Node)
{
	TArray<UEdGraphNode_Comment*> ContainingComments;
	for (auto Comment : Comments)
	{
		auto NodesUnderComments = FBAUtils::GetNodesUnderComment(Comment);
		if (NodesUnderComments.Contains(Node))
		{
			ContainingComments.Add(Comment);
		}
	}

	return ContainingComments;
}

UEdGraphNode* FBAUtils::GetFirstLinkedNodePreferringInput(UEdGraphNode* Node)
{
	const auto LinkedInput = GetLinkedNodes(Node, EGPD_Input);
	if (LinkedInput.Num() > 0)
	{
		return LinkedInput[0];
	}
	
	const auto LinkedOutput = GetLinkedNodes(Node, EGPD_Output);
	if (LinkedOutput.Num() > 0)
	{
		return LinkedOutput[0];
	}
	
	return nullptr;
}

void FBAUtils::RemoveNodeFromComment(UEdGraphNode_Comment* Comment, UEdGraphNode* NodeToRemove)
{
	const FCommentNodeSet NodesUnderComment = Comment->GetNodesUnderComment();

	// Clear all nodes under comment
	Comment->ClearNodesUnderComment();

	// Add back the nodes under comment while filtering out any which are to be removed
	for (UObject* NodeUnderComment : NodesUnderComment)
	{
		if (NodeUnderComment != NodeToRemove)
		{
			Comment->AddNodeUnderComment(NodeUnderComment);
		}
	}
}

FBAFormatterSettings& FBAUtils::GetFormatterSettings(UEdGraph* Graph)
{
	EBAGraphType GraphType = GetBAGraphType(Graph).GetValue();
	auto BASettings = GetMutableDefault<UBASettings>();
	
	switch (GraphType)
	{
		case BAGraphType_Blueprint:
			return BASettings->BlueprintFormatterSettings;
		case BAGraphType_SoundCue:
			return BASettings->SoundCueGraphFormatterSettings;
		case BAGraphType_BehaviorTree:
			return BASettings->BehaviorTreeFormatterSettings;
		case BAGraphType_MaterialGraph:
			return BASettings->MaterialGraphFormatterSettings;
		case BAGraphType_NiagaraGraph:
			return BASettings->NiagaraGraphFormatterSettings;
		case BAGraphType_AnimGraph:
			return BASettings->AnimationGraphFormatterSettings;
		default:
			UE_LOG(LogBlueprintAssist, Warning, TEXT("Not a recognized graph type: using blueprint formatter settings"));
			return BASettings->BlueprintFormatterSettings;
	}
}

TSharedPtr<FBAGraphHandler> FBAUtils::GetCurrentGraphHandler()
{
	IBlueprintAssistModule& BAModule = IBlueprintAssistModule::Get();
	TSharedPtr<FBAInputProcessor> InputProcessor = BAModule.GetInputProcessor();
	return InputProcessor->TabHandler->GetGraphHandler();
}

float FBAUtils::GetCenterYOfPins(TSharedPtr<FBAGraphHandler> GraphHandler, TArray<UEdGraphPin*>& Pins)
{
	float PinMin = MAX_flt;
    float PinMax = -MAX_flt;
    for (auto Pin : Pins)
    {
        PinMin = FMath::Min(PinMin, FBAUtils::GetPinPos(GraphHandler, Pin).Y);
        PinMax = FMath::Max(PinMax, FBAUtils::GetPinPos(GraphHandler, Pin).Y);
    }
                
    return (PinMin + PinMax) / 2;
}

TSharedPtr<IMenu> FBAUtils::PushMenuAtCenterOfWindow(TSharedPtr<SWidget> Widget, const FVector2D& WidgetSize, TSharedPtr<SWidget> WidgetToFocus)
{
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().GetActiveTopLevelWindow();

	FVector2D WindowPosition = FSlateApplication::Get().GetCursorPos();
	if (ParentWindow.IsValid())
	{
		FSlateRect ParentMonitorRect = ParentWindow->GetFullScreenInfo();
		const FVector2D MonitorCenter((ParentMonitorRect.Right + ParentMonitorRect.Left) * 0.5f, (ParentMonitorRect.Top + ParentMonitorRect.Bottom) * 0.5f);
		WindowPosition = MonitorCenter - WidgetSize * 0.5f;
	}

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
        ParentWindow.ToSharedRef(),
        FWidgetPath(),
        Widget.ToSharedRef(),
        WindowPosition,
        FPopupTransitionEffect(FPopupTransitionEffect::None)
    );

	if (WidgetToFocus.IsValid())
	{
		FSlateApplication::Get().SetKeyboardFocus(WidgetToFocus);
	}

	return Menu;
}
