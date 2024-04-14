// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "EdGraphFormatter.h"

#include "BlueprintAssistSettings.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintAssistGraphHandler.h"

#include "EdGraphParameterFormatter.h"
#include "GraphFormatterTypes.h"

#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraphNode_Comment.h"
#include "Editor/BlueprintGraph/Classes/K2Node_Knot.h"
#include "Containers/Queue.h"
#include "SGraphPanel.h"
#include "SGraphNodeComment.h"

#include "BlueprintAssistModule.h"

FNodeChangeInfo::FNodeChangeInfo(UEdGraphNode* InNode, UEdGraphNode* InNodeToKeepStill)
	: Node(InNode)
{
	bIsNodeToKeepStill = Node == InNodeToKeepStill;
	UpdateValues(InNodeToKeepStill);
}

void FNodeChangeInfo::UpdateValues(UEdGraphNode* NodeToKeepStill)
{
	NodeX = Node->NodePosX;
	NodeY = Node->NodePosY;

	NodeOffsetX = Node->NodePosX - NodeToKeepStill->NodePosX;
	NodeOffsetY = Node->NodePosY - NodeToKeepStill->NodePosY;

	Links.Empty();
	for (UEdGraphPin* Pin : Node->Pins)
	{
		for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
		{
			Links.Add(FPinLink(Pin, LinkedPin));
		}
	}
}

bool FNodeChangeInfo::HasChanged(UEdGraphNode* NodeToKeepStill)
{
	// check pin links
	TSet<FPinLink> NewLinks;
	for (UEdGraphPin* Pin : Node->Pins)
	{
		for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
		{
			NewLinks.Add(FPinLink(Pin, LinkedPin));
		}
	}

	if (NewLinks.Num() != Links.Num())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Num links changed"));
		return true;
	}

	for (const FPinLink& Link : Links)
	{
		if (!NewLinks.Contains(Link))
		{
			//UE_LOG(LogTemp, Warning, TEXT("New links does not contain %s"), *Link.ToString());
			return true;
		}
	}

	return false;
}

FEdGraphFormatter::FEdGraphFormatter(
	TSharedPtr<FBAGraphHandler> InGraphHandler,
	FEdGraphFormatterParameters InFormatterParameters)
	: GraphHandler(InGraphHandler)
	, RootNode(nullptr)
	, FormatterParameters(InFormatterParameters)
{
	const UBASettings* BASettings = GetDefault<UBASettings>();
	
	NodePadding = BASettings->BlueprintFormatterSettings.Padding;
	PinPadding = BASettings->BlueprintParameterPadding;
	TrackSpacing = BASettings->BlueprintKnotTrackSpacing;
	VerticalPinSpacing = BASettings->VerticalPinSpacing;
	bCenterBranches = BASettings->bCenterBranches;
	NumRequiredBranches = BASettings->NumRequiredBranches;

	LastFormattedX = 0;
	LastFormattedY = 0;
}

void FEdGraphFormatter::FormatNode(UEdGraphNode* InitialNode)
{
	if (!IsInitialNodeValid(InitialNode))
	{
		return;
	}

	RootNode = InitialNode;

	TArray<UEdGraphNode*> NewNodeTree = GetNodeTree(InitialNode);
	
	NodeTree = NewNodeTree;

	const auto& SelectedNodes = GraphHandler->GetSelectedNodes();
	const bool bAreAllNodesSelected = !NewNodeTree.ContainsByPredicate([&SelectedNodes](UEdGraphNode* Node)
	{
		return !SelectedNodes.Contains(Node);
	});

	// check if we can do simple relative formatting
	if (GetMutableDefault<UBASettings>()->bEnableFasterFormatting && !IsFormattingRequired(NewNodeTree))
	{
		SimpleRelativeFormatting();
		return;
	}

	NodeChangeInfos.Reset();
	NodePool.Reset();
	MainParameterFormatter.Reset();
	ParameterFormatterMap.Reset();
	KnotNodesSet.Reset();
	KnotTracks.Reset();
	FormatXInfoMap.Reset();
	Path.Reset();
	SameRowMapping.Reset();
	KnotNodeOwners.Reset();
	ParentComments.Reset();
	SubGraphFormatters.Reset();
	NodesToExpand.Reset();
	ParameterParentMap.Reset();
	NodeHeightLevels.Reset();

	if (FBAUtils::GetLinkedPins(RootNode).Num() == 0)
	{
		NodePool = { RootNode };
		return;
	}

	RemoveKnotNodes();

	if (FBAUtils::IsNodePure(RootNode))
	{
		MainParameterFormatter = MakeShared<FEdGraphParameterFormatter>(GraphHandler, RootNode, SharedThis(this));
		MainParameterFormatter->FormatNode(RootNode);
		return;
	}

	NodeToKeepStill = RootNode;

	if (GraphHandler->NewNodeForFormatting != nullptr && GraphHandler->NewNodeForFormatting == RootNode)
	{
		const TArray<UEdGraphNode*> LinkedNodes = FBAUtils::GetLinkedNodes(GraphHandler->NewNodeForFormatting, EGPD_Output).
			FilterByPredicate(FBAUtils::IsNodeImpure);

		if (LinkedNodes.Num() > 0)
		{
			NodeToKeepStill = LinkedNodes[0];
			GraphHandler->NewNodeForFormatting = nullptr;
		}
	}

	const FVector2D SavedLocation = FVector2D(NodeToKeepStill->NodePosX, NodeToKeepStill->NodePosY);
	
	// initialize the node pool from the root node
	InitNodePool();

	InitCommentNodeInfo();

	// UE_LOG(LogTemp, Warning, TEXT("Selected Root Node as %s | NodeToKeepStill as %s"), *FBAUtils::GetNodeName(RootNode), *FBAUtils::GetNodeName(NodeToKeepStill));
	//for (UEdGraphNode* Node : FormatterParameters.NodesToFormat)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("\tSelective Formatting %s"), *FBAUtils::GetNodeName(Node));
	//}

	// for (UEdGraphNode* Node : NodePool)
	// {
	// 	// UE_LOG(LogTemp, Warning, TEXT("\t\tNodePool %s"), *FBAUtils::GetNodeName(Node));
	// }

	GetPinsOfSameHeight();
	
	bAccountForComments = false;
	FormatX(false);

	//UE_LOG(LogTemp, Warning, TEXT("Path: "));
	//for (FPinLink& PinLink : Path)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("\t%s"), *PinLink.ToString());
	//}

	//UE_LOG(LogTemp, Warning, TEXT("NodeInfos: "));
	//for (UEdGraphNode* Node : NodePool)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("\t%s"), *FBAUtils::GetNodeName(Node));
	//	if (!FormatXInfoMap.Contains(Node))
	//	{
	//		UE_LOG(LogTemp, Error, TEXT("ERROR FormatXInfo does not contain %s"), *FBAUtils::GetNodeName(Node));
	//	}
	//	else
	//	{
	//		for (TSharedPtr<FFormatXInfo> Info : FormatXInfoMap[Node]->Children)
	//		{
	//			UE_LOG(LogTemp, Warning, TEXT("\t\t%s"), *FBAUtils::GetNodeName(Info->GetNode()));
	//		}
	//	}
	//}

	if (GetMutableDefault<UBASettings>()->bCustomDebug == 0)
		return;

	/** Format the input nodes before we format the X position so we can get the column bounds */
	bAccountForComments = GetDefault<UBASettings>()->bAccountForCommentsWhenFormatting;
	FormatParameterNodes();

	FormatComments();

	if (GetMutableDefault<UBASettings>()->bCustomDebug == 3)
		return;

	Path.Empty();
	FormatXInfoMap.Empty();
	FormatX(true);

	if (GetMutableDefault<UBASettings>()->bCustomDebug == 1)
		return;

	/** Format Y (Rows) */
	FormatY();
	
	if (GetMutableDefault<UBASettings>()->bCustomDebug == 2)
		return;

	if (GetMutableDefault<UBASettings>()->bExpandNodesByHeight)
	{
		ExpandByHeight();
	}

	// TODO: Finish logic for wrapping nodes
	// WrapNodes();

	/** Format knot nodes */
	if (GetMutableDefault<UBASettings>()->bCreateKnotNodes)
	{
		FormatKnotNodes();
	}

	// Cleanup knot node pool
	for (auto KnotNode : KnotNodePool)
	{
		if (FBAUtils::GetLinkedNodes(KnotNode).Num() == 0)
		{
			FBAUtils::DeleteNode(KnotNode);
		}
	}
	KnotNodePool.Empty();

	/** Formatting may move nodes, move all nodes back using the root as a baseline */
	ResetRelativeToNodeToKeepStill(SavedLocation);

	/** Snap all nodes to the grid (only on the x-axis) */
	TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();
	for (UEdGraphNode* Node : FormattedNodes)
	{
		Node->NodePosX = FBAUtils::SnapToGrid(Node->NodePosX);
	}

	SaveFormattingEndInfo();

	ModifyCommentNodes();

	// Check if formatting is required checks the difference between the node trees, so we must set it here
	NodeTree = GetNodeTree(InitialNode);

	//for (UEdGraphNode* Nodes : GetFormattedGraphNodes())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Formatted node %s"), *FBAUtils::GetNodeName(Nodes));
	//}
	//

	if (bAreAllNodesSelected)
	{
		auto& SelectionManager = GraphHandler->GetGraphPanel()->SelectionManager;
		for (auto Node : KnotNodesSet)
		{
			SelectionManager.SetNodeSelection(Node, true);
		}
	}
}

void FEdGraphFormatter::InitNodePool()
{
	NodePool.Empty();
	TArray<UEdGraphNode*> InputNodeStack;
	TArray<UEdGraphNode*> OutputNodeStack;
	OutputNodeStack.Push(RootNode);
	RootNode->Modify();

	while (InputNodeStack.Num() > 0 || OutputNodeStack.Num() > 0)
	{
		UEdGraphNode* CurrentNode
			= OutputNodeStack.Num() > 0
			? OutputNodeStack.Pop()
			: InputNodeStack.Pop();

		if (!GraphHandler->FilterSelectiveFormatting(CurrentNode, FormatterParameters.NodesToFormat))
			continue;

		if (NodePool.Contains(CurrentNode) || FBAUtils::IsNodePure(CurrentNode))
			continue;

		NodePool.Add(CurrentNode);

		TArray<EEdGraphPinDirection> Directions = {EGPD_Input, EGPD_Output};

		for (EEdGraphPinDirection& Dir : Directions)
		{
			TArray<UEdGraphPin*> ExecPins = FBAUtils::GetLinkedPins(CurrentNode, Dir).FilterByPredicate(IsExecOrDelegatePin);

			for (int32 MyPinIndex = ExecPins.Num() - 1; MyPinIndex >= 0; MyPinIndex--)
			{
				UEdGraphPin* Pin = ExecPins[MyPinIndex];

				for (int32 i = Pin->LinkedTo.Num() - 1; i >= 0; i--)
				{
					UEdGraphPin* LinkedPin = Pin->LinkedTo[i];
					UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();

					if (NodePool.Contains(LinkedNode) || FBAUtils::IsNodePure(LinkedNode))
						continue;

					LinkedNode->Modify();
					
					FBAUtils::StraightenPin(GraphHandler, Pin, LinkedPin);

					if (Dir == EGPD_Output)
						OutputNodeStack.Push(LinkedNode);
					else
						InputNodeStack.Push(LinkedNode);
				}
			}
		}
	}
}

void FEdGraphFormatter::ExpandPendingNodes(bool bUseParameter)
{
	for (TSharedPtr<FFormatXInfo> Info : NodesToExpand)
	{
		if (!Info->Parent.IsValid())
		{
			// UE_LOG(LogTemp, Warning, TEXT("Expand X Invalid %s"), *FBAUtils::GetNodeName(Info->GetNode()));
			return;
		}


		UEdGraphNode* Node = Info->GetNode();
		UEdGraphNode* Parent = Info->Parent->GetNode();
		TArray<UEdGraphNode*> InputChildren = Info->GetChildren(EGPD_Input);


		// UE_LOG(LogTemp, Warning, TEXT("Expand X %s | %s"), *FBAUtils::GetNodeName(Info->GetNode()), *FBAUtils::GetNodeName(Parent));

		
		if (InputChildren.Num() > 0)
		{
			FSlateRect InputBounds = bUseParameter
				? GetClusterBoundsForNodes(InputChildren)
				: FBAUtils::GetCachedNodeArrayBounds(GraphHandler, InputChildren);

			FSlateRect ParentBounds = bUseParameter
				? GetClusterBounds(Parent)
				: FBAUtils::GetCachedNodeBounds(GraphHandler, Parent);

			if (bAccountForComments)
			{
				InputBounds = GetRelativeBoundsForNodes(InputChildren, Parent, bUseParameter);
				ParentBounds = GetRelativeNodeBounds(Parent, Node, bUseParameter);
			}

			if (ParentBounds.Right > InputBounds.Left)
			{
				const float Delta = ParentBounds.Right - InputBounds.Left + NodePadding.X;

				// UE_LOG(LogTemp, Warning, TEXT("Expanding node %s by %f"), *FBAUtils::GetNodeName(Node), Delta);

				Node->NodePosX += Delta;

				if (bUseParameter)
				{
					RefreshParameters(Node);
				}

				TArray<UEdGraphNode*> AllChildren = Info->GetChildren();
				for (UEdGraphNode* Child : AllChildren)
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tChild %s"), *FBAUtils::GetNodeName(Child));

					Child->NodePosX += Delta;

					if (bUseParameter)
					{
						RefreshParameters(Child);
					}
				}
			}
		}
	}
}

void FEdGraphFormatter::SimpleRelativeFormatting()
{
	for (UEdGraphNode* Node : GetFormattedNodes())
	{
		// check(NodeChangeInfos.Contains(Node))
		if (NodeChangeInfos.Contains(Node))
		{
			Node->NodePosX = NodeToKeepStill->NodePosX + NodeChangeInfos[Node].NodeOffsetX;
			Node->NodePosY = NodeToKeepStill->NodePosY + NodeChangeInfos[Node].NodeOffsetY;
		}
		else
		{
			UE_LOG(LogBlueprintAssist, Error, TEXT("No ChangeInfo for %s"), *FBAUtils::GetNodeName(Node));
		}
	}

	SaveFormattingEndInfo();

	ModifyCommentNodes();
}

void FEdGraphFormatter::FormatX(const bool bUseParameter)
{
	// UE_LOG(LogTemp, Warning, TEXT("----- Format X -----"));
	
	TSet<UEdGraphNode*> VisitedNodes;
	TSet<UEdGraphNode*> PendingNodes;
	PendingNodes.Add(RootNode);
	TSet<FPinLink> VisitedLinks;
	const FPinLink RootNodeLink(nullptr, nullptr, RootNode);
	TSharedPtr<FFormatXInfo> RootInfo = MakeShared<FFormatXInfo>(RootNodeLink, nullptr);

	TArray<TSharedPtr<FFormatXInfo>> OutputStack;
	TArray<TSharedPtr<FFormatXInfo>> InputStack;
	OutputStack.Push(RootInfo);
	FormatXInfoMap.Add(RootNode, RootInfo);

	EEdGraphPinDirection LastDirection = EGPD_Output;

	NodesToExpand.Reset();

	while (OutputStack.Num() > 0 || InputStack.Num() > 0)
	{
		// try to get the current info from the pending input
		TSharedPtr<FFormatXInfo> CurrentInfo = nullptr;
		
		TArray<TSharedPtr<FFormatXInfo>>& FirstStack = LastDirection == EGPD_Output ? OutputStack : InputStack;
		TArray<TSharedPtr<FFormatXInfo>>& SecondStack = LastDirection == EGPD_Output ? InputStack : OutputStack;
		
		if (FirstStack.Num() > 0)
		{
			CurrentInfo = FirstStack.Pop();
		}
		else
		{
			CurrentInfo = SecondStack.Pop();
		}

		LastDirection = CurrentInfo->Link.GetDirection();

		UEdGraphNode* CurrentNode = CurrentInfo->GetNode();
		VisitedNodes.Add(CurrentNode);

		// UE_LOG(LogTemp, Warning, TEXT("Processing %s | %s"), *FBAUtils::GetNodeName(CurrentNode), *CurrentInfo->Link.ToString());
		const int32 NewX = GetChildX(CurrentInfo->Link, bUseParameter);

		if (!FormatXInfoMap.Contains(CurrentNode))
		{
			if (CurrentNode != RootNode)
			{
				CurrentInfo->SetParent(CurrentInfo->Parent);
				CurrentNode->NodePosX = NewX;
				
				if (bUseParameter)
				{
					if (SubGraphFormatters.Contains(CurrentNode))
					{
						TSharedPtr<FCommentSubGraphFormatter> SubGraphFormatter = SubGraphFormatters[CurrentNode];
						if (!SubGraphFormatter->bHasBeenFormatted)
						{
							SubGraphFormatters[CurrentNode]->FormatNode(CurrentNode);
							// UE_LOG(LogTemp, Warning, TEXT("Formatted sub graph for %s"), *FBAUtils::GetNodeName(CurrentNode));
						}
					}
					
					RefreshParameters(CurrentNode);
				}

				// UE_LOG(LogTemp, Warning, TEXT("\tInitial Set node pos x %d %s"), NewX, *FBAUtils::GetNodeName(CurrentNode));
			
				Path.Add(CurrentInfo->Link);
			}
			FormatXInfoMap.Add(CurrentNode, CurrentInfo);
		}
		else
		{
			TSharedPtr<FFormatXInfo> OldInfo = FormatXInfoMap[CurrentNode];

			// UE_LOG(LogTemp, Warning, TEXT("\tInfo map contains %s | %s (%s) | Parent %s (%s) | %d"),
			//        *FBAUtils::GetNodeName(CurrentInfo->Link.To->GetOwningNode()),
			//        *FBAUtils::GetNodeName(CurrentInfo->GetNode()),
			//        *FBAUtils::GetPinName(CurrentInfo->Link.To),
			//        *FBAUtils::GetNodeName(CurrentInfo->Link.From->GetOwningNode()),
			//        *FBAUtils::GetPinName(CurrentInfo->Link.From),
			//        NewX);

			const bool bHasNoParent = CurrentInfo->Link.From == nullptr;

			bool bHasCycle = false;
			if (!bHasNoParent) // if we have a parent, check if there is a cycle
			{
				// bHasCycle = OldInfo->GetChildren(EGPD_Output).Contains(CurrentInfo->Parent->GetNode());
				bHasCycle = OldInfo->GetChildren().Contains(CurrentInfo->Parent->GetNode());

				// if (bHasCycle)
				// {
				// 	UE_LOG(LogTemp, Warning, TEXT("\t\tHas cycle! Skipping"));
				// 	for (UEdGraphNode* Child : OldInfo->GetChildren(EGPD_Output))
				// 	{
				// 		UE_LOG(LogTemp, Warning, TEXT("\t\t\tChild: %s"), *FBAUtils::GetNodeName(Child));
				// 	}
				// }

				// for (UEdGraphNode* Child : OldInfo->GetChildren(EGPD_Output))
				// // for (UEdGraphNode* Child : OldInfo->GetChildren())
				// {
				// 	UE_LOG(LogTemp, Warning, TEXT("\t\t\tParent %s | Child: %s"), *FBAUtils::GetNodeName(CurrentInfo->Parent->GetNode()), *FBAUtils::GetNodeName(Child));
				// }
				
			}

			if (bHasNoParent || !bHasCycle)
			{
				if (OldInfo->Parent.IsValid())
				{
					bool bTakeNewParent = bHasNoParent;

					if (!bTakeNewParent)
					{
						const int32 OldX = CurrentInfo->GetNode()->NodePosX;

						const bool bPositionIsBetter
							= CurrentInfo->Link.From->Direction == EGPD_Output
							? NewX > OldX
							: NewX < OldX;

						// UE_LOG(LogTemp, Warning, TEXT("\t Comparing parents Old: %s (%d) New: %s (%d)"),
						//        *FBAUtils::GetNodeName(OldInfo->Link.From->GetOwningNode()), OldX,
						//        *FBAUtils::GetNodeName(CurrentInfo->Link.From->GetOwningNode()), NewX);

						const bool bSameDirection = OldInfo->Link.To->Direction == CurrentInfo->Link.To->Direction;
						// if (!bSameDirection) UE_LOG(LogTemp, Warning, TEXT("\t\tNot same direction"));
						//
						// if (!bPositionIsBetter) UE_LOG(LogTemp, Warning, TEXT("\t\tPosition is worse?"));

						bTakeNewParent = bPositionIsBetter && bSameDirection;
					}

					// take the new parent by updating the old info
					if (bTakeNewParent)
					{
						// UE_LOG(LogTemp, Warning, TEXT("\t\tTOOK PARENT"));

						OldInfo->Link = CurrentInfo->Link;
						OldInfo->SetParent(CurrentInfo->Parent);

						CurrentInfo = OldInfo;

						CurrentNode->NodePosX = NewX;
						if (bUseParameter)
							RefreshParameters(CurrentNode);

						for (TSharedPtr<FFormatXInfo> ChildInfo : CurrentInfo->Children)
						{
							if (ChildInfo->Link.GetDirection() == EGPD_Output)
							{
								OutputStack.Push(ChildInfo);
							}
							else
							{
								InputStack.Push(ChildInfo);
							}
						}

						Path.Add(CurrentInfo->Link);
					}
				}
			}
		}

		TArray<UEdGraphPin*> LinkedPins = FBAUtils::GetLinkedPins(CurrentInfo->GetNode()).FilterByPredicate(IsExecOrDelegatePin);

		for (int i = LinkedPins.Num() - 1; i >= 0; --i)
		{
			UEdGraphPin* ParentPin = LinkedPins[i];

			for (UEdGraphPin* LinkedPin : ParentPin->LinkedTo)
			{
				UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();

				const FPinLink PinLink(ParentPin, LinkedPin, LinkedNode);

				// UE_LOG(LogTemp, Warning, TEXT("\t\tTrying to iterate link %s"), *PinLink.ToString());
				
				if (VisitedLinks.Contains(PinLink))
					continue;
				
				VisitedLinks.Add(PinLink);
				if (!NodePool.Contains(LinkedNode))
					continue;

				if (FBAUtils::IsNodePure(LinkedNode))
					continue;

				// UE_LOG(LogTemp, Warning, TEXT("\t\t\tIterating pin link %s"), *PinLink.ToString());

				TSharedPtr<FFormatXInfo> LinkedInfo = MakeShared<FFormatXInfo>(PinLink, CurrentInfo);

				if (ParentPin->Direction == EGPD_Output)
				{
					OutputStack.Push(LinkedInfo);
					// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tAdded to output stack"));
				}
				else
				{	
					if (GetMutableDefault<UBASettings>()->FormattingStyle == BANodeFormatting_Expanded)
					{						
						const bool bHasCycle = PendingNodes.Contains(LinkedNode) || FBAUtils::GetExecTree(LinkedNode, EGPD_Input).Contains(CurrentInfo->GetNode());
						//FBAUtils::GetExecTree(LinkedNode, EGPD_Input).Array().FilterByPredicate(OnlySelected).Contains(CurrentInfo->GetNode());
						// const bool bHasCycle = FBAUtils::GetExecTree(LinkedNode, EGPD_Input).Array().FilterByPredicate(OnlySelected).Contains(CurrentInfo->GetNode());
						if (!bHasCycle)
						{
							if (CurrentInfo->Link.GetDirection() == EGPD_Output)
							{
								if (!CurrentInfo->Parent.IsValid() || LinkedNode != CurrentInfo->Parent->GetNode())
								{
									NodesToExpand.Add(CurrentInfo);
									// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tExpanding node %s"), *FBAUtils::GetNodeName(LinkedNode));
								}
							}
						}

					}
					
					InputStack.Push(LinkedInfo);
					// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tAdded to input stack"));
				}

				PendingNodes.Add(LinkedNode);
			}
		}
	}

	if (GetMutableDefault<UBASettings>()->FormattingStyle == BANodeFormatting_Expanded)
	{
		ExpandPendingNodes(bUseParameter);
	}
}

void FEdGraphFormatter::ExpandByHeight()
{
	// expand nodes in the output direction for centered branches
	for (UEdGraphNode* Node : NodePool)
	{
		TSharedPtr<FFormatXInfo> Info = FormatXInfoMap[Node];
				
		const TArray<FPinLink> PinLinks = Info->GetChildrenAsLinks(EGPD_Output);

		if (bCenterBranches && PinLinks.Num() < NumRequiredBranches)
		{
			continue;
		}

		float LargestExpandX = 0;
		for (const FPinLink& Link : PinLinks)
		{
			const FVector2D ToPos = FBAUtils::GetPinPos(GraphHandler, Link.To);
			const FVector2D FromPos = FBAUtils::GetPinPos(GraphHandler, Link.From);
			
			const float PinDeltaY = FMath::Abs(ToPos.Y - FromPos.Y);
			const float PinDeltaX = FMath::Abs(ToPos.X - FromPos.X);

			// expand to move the node to form a 45 degree angle for the wire (delta x == delta y)
			const float ExpandX = PinDeltaY * 0.75f - PinDeltaX;

			LargestExpandX = FMath::Max(ExpandX, LargestExpandX);
			// UE_LOG(LogTemp, Warning, TEXT("Delta X %f | DeltaY %f | ExpandX %f"), PinDeltaX, PinDeltaY, ExpandX);
		}

		if (LargestExpandX <= 0)
			continue;

		// UE_LOG(LogTemp, Warning, TEXT("Expanding %s"), *FBAUtils::GetNodeName(Node));
		TArray<UEdGraphNode*> Children = Info->GetChildren(EGPD_Output);
		for (UEdGraphNode* Child : Children)
		{
			// UE_LOG(LogTemp, Warning, TEXT("\tChild %s"), *FBAUtils::GetNodeName(Child));
			Child->NodePosX += LargestExpandX;
			RefreshParameters(Child);
		}
	}
}

void FEdGraphFormatter::InitCommentNodeInfo()
{
	ParentComments.Empty();
	CommentNodesContains.Reset();

	TArray<UEdGraphNode_Comment*> CommentNodes = FBAUtils::GetCommentNodesFromGraph(GraphHandler->GetFocusedEdGraph());

	CommentNodes.Sort([](UEdGraphNode_Comment& NodeA, UEdGraphNode_Comment& NodeB)
	{
		return NodeA.CommentDepth > NodeB.CommentDepth;
	});

	auto FormattedNodes = GetFormattedGraphNodes();

	bool bModifiedComment = false;
	for (UEdGraphNode_Comment* Comment : CommentNodes)
	{
		TArray<UEdGraphNode*> NodesUnderComment = FBAUtils::GetNodesUnderComment(Comment);
		
		for (UEdGraphNode* EdGraphNode : NodesUnderComment)
		{
			if (NodeTree.Contains(EdGraphNode))
			{
				CommentNodesContains.FindOrAdd(Comment).Add(EdGraphNode);

				ParentComments.FindOrAdd(EdGraphNode).Add(Comment);

				if (!bModifiedComment)
				{
					Comment->Modify();
					bModifiedComment = true;
				}
			}
		}
	}
}

void FEdGraphFormatter::FormatY_Recursive(
	UEdGraphNode* CurrentNode,
	UEdGraphPin* CurrentPin,
	UEdGraphPin* ParentPin,
	TSet<UEdGraphNode*>& NodesToCollisionCheck,
	TSet<FPinLink>& VisitedLinks,
	const bool bSameRow,
	TSet<UEdGraphNode*>& Children)
{
	// const FString NodeNameA = CurrentNode == nullptr
	// 	? FString("nullptr")
	// 	: FBAUtils::GetNodeName(CurrentNode);
	// const FString PinNameA = CurrentPin == nullptr ? FString("nullptr") : FBAUtils::GetPinName(CurrentPin);
	// const FString NodeNameB = ParentPin == nullptr
	// 	? FString("nullptr")
	// 	: FBAUtils::GetNodeName(ParentPin->GetOwningNode());
	// const FString PinNameB = ParentPin == nullptr ? FString("nullptr") : FBAUtils::GetPinName(ParentPin);
	//
	// UE_LOG(LogTemp, Warning, TEXT("FormatY Next : %s | %s || %s | %s"),
	//        *NodeNameA, *PinNameA,
	//        *NodeNameB, *PinNameB);

	uint16 CollisionLimit = 30;
	while (true)
	{
		if (CollisionLimit <= 0)
		{
			// UE_LOG(LogTemp, Warning, TEXT("BlueprintAssist: FormatY failed to resolve collision!"));
			break;
		}

		CollisionLimit -= 1;

		bool bNoCollision = true;
		for (UEdGraphNode* NodeToCollisionCheck : NodesToCollisionCheck)
		{
			if (NodeToCollisionCheck == CurrentNode)
				continue;

			if (ParentPin != nullptr && ParentPin->GetOwningNode() == NodeToCollisionCheck)
				continue;
			
			TSet<UEdGraphNode*> NodesToMove;

			FSlateRect MyBounds = bAccountForComments ? GetRelativeNodeBounds(CurrentNode, NodeToCollisionCheck, NodesToMove, true) : GetClusterBounds(CurrentNode);
			const FMargin CollisionPadding(0, 0, NodePadding.X * 0.75f, NodePadding.Y);

			if (ParentPin != nullptr)
			{	
				float ParentX = FBAUtils::GetPinPos(GraphHandler, ParentPin).X;
				if (MyBounds.Left > ParentX)
				{
					MyBounds = MyBounds.ExtendBy(FMargin(MyBounds.Left - ParentX, 0, 0, 0));
				}
				else if (ParentX > MyBounds.Right)
				{
					MyBounds = MyBounds.ExtendBy(FMargin(0, 0, ParentX - MyBounds.Right, 0));
				}
			}

			FSlateRect OtherBounds = bAccountForComments ? GetRelativeNodeBounds(NodeToCollisionCheck, CurrentNode, true) : GetClusterBounds(NodeToCollisionCheck);

			OtherBounds = OtherBounds.ExtendBy(CollisionPadding);

			if (FSlateRect::DoRectanglesIntersect(MyBounds.ExtendBy(CollisionPadding), OtherBounds))
			{
				bNoCollision = false;
				const int32 Delta = OtherBounds.Bottom - MyBounds.Top;

				// UE_LOG(LogTemp, Warning, TEXT("Collision between %d | %s (%s) and %s (%s)"),
				// 	Delta + 1,
				// 	*FBAUtils::GetNodeName(CurrentNode), *MyBounds.ToString(),
				// 	*FBAUtils::GetNodeName(NodeToCollisionCheck), *OtherBounds.ToString());

				if (NodesToMove.Num() > 0)
				{
					for (UEdGraphNode* Node : NodesToMove)
					{
						// UE_LOG(LogTemp, Warning, TEXT("\tMoved node relative %s %d"), *FBAUtils::GetNodeName(Node), Delta + 1);
						Node->NodePosY += Delta + 1;
					}
				}
				else
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tMoved node single %s"), *FBAUtils::GetNodeName(CurrentNode));
					CurrentNode->NodePosY += Delta + 1;
					RefreshParameters(CurrentNode);
				}
			}
		}

		if (bNoCollision)
		{
			break;
		}
	}

	NodesToCollisionCheck.Emplace(CurrentNode);

	const EEdGraphPinDirection ParentDirection = ParentPin == nullptr ? EGPD_Output : ParentPin->Direction.GetValue();

	bool bFirstPin = true;

	UEdGraphPin* MainPin = CurrentPin;

	bool bCenteredParent = false;
	
	TArray<EEdGraphPinDirection> Directions = { ParentDirection, UEdGraphPin::GetComplementaryDirection(ParentDirection) };
	for (EEdGraphPinDirection CurrentDirection : Directions)
	{
		TArray<UEdGraphPin*> Pins = FBAUtils::GetLinkedPins(CurrentNode, CurrentDirection)
		                                                 .FilterByPredicate(IsExecOrDelegatePin)
		                                                 .FilterByPredicate(FBAUtils::IsPinLinked);
		
		UEdGraphPin* LastLinked = CurrentPin;
		UEdGraphPin* LastProcessed = nullptr;

		TArray<ChildBranch> ChildBranches;
		
		int DeltaY = 0;
		for (UEdGraphPin* MyPin : Pins)
		{
			TArray<UEdGraphPin*> LinkedPins = MyPin->LinkedTo;

			for (int i = 0; i < LinkedPins.Num(); ++i)
			{				
				UEdGraphPin* OtherPin = LinkedPins[i];
				UEdGraphNode* OtherNode = OtherPin->GetOwningNode();
				FPinLink Link(MyPin, OtherPin);

				bool bIsSameLink = Path.Contains(Link);

				// UE_LOG(LogTemp, Warning, TEXT("\tIter Child %s"), *FBAUtils::GetNodeName(OtherNode));
				//
				// if (!bIsSameLink)
				// {
				// 	UE_LOG(LogTemp, Warning, TEXT("\t\tNot same link!"));
				// }

				if (VisitedLinks.Contains(Link)
					|| !NodePool.Contains(OtherNode)
					|| FBAUtils::IsNodePure(OtherNode)
					|| NodesToCollisionCheck.Contains(OtherNode)
					|| !bIsSameLink)
				{
					// UE_LOG(LogTemp, Warning, TEXT("\t\t\tSkipping child"));
					continue;
				}
				VisitedLinks.Add(Link);

				// UE_LOG(LogTemp, Warning, TEXT("\t\tTaking Child %s"), *FBAUtils::GetNodeName(OtherNode));

				FBAUtils::StraightenPin(GraphHandler, MyPin, OtherPin);

				bool bChildIsSameRow = false;

				if (bFirstPin && (ParentPin == nullptr || MyPin->Direction == ParentPin->Direction))
				{
					bChildIsSameRow = true;
					bFirstPin = false;
					// UE_LOG(LogTemp, Error, TEXT("\t\tNode %s is same row as %s"),
					//        *FBAUtils::GetNodeName(OtherNode),
					//        *FBAUtils::GetNodeName(CurrentNode));
				}
				else
				{
					if (LastProcessed != nullptr)
					{
						//UE_LOG(LogTemp, Warning, TEXT("Moved node %s to %s"), *FBAUtils::GetNodeName(OtherNode), *FBAUtils::GetNodeName(LastPinOther->GetOwningNode()));
						const int32 NewNodePosY = FMath::Max(OtherNode->NodePosY, LastProcessed->GetOwningNode()->NodePosY);
						FBAUtils::SetNodePosY(GraphHandler, OtherNode, NewNodePosY);
					}
				}

				if (!NodeHeightLevels.Contains(OtherNode))
				{
					int NewHeight = NodeHeightLevels[CurrentNode] + (bChildIsSameRow ? 0 : DeltaY);
					
					NodeHeightLevels.Add(OtherNode, NewHeight);

					// UE_LOG(LogTemp, Warning, TEXT("Set height for node %s to %d"), *FBAUtils::GetNodeName(OtherNode), NewHeight);
				}

				RefreshParameters(OtherNode);
				
				TSet<UEdGraphNode*> LocalChildren;
				FormatY_Recursive(OtherNode, OtherPin, MyPin, NodesToCollisionCheck, VisitedLinks, bChildIsSameRow, LocalChildren);
				Children.Append(LocalChildren);

				if (FormatXInfoMap[CurrentNode]->GetImmediateChildren().Contains(OtherNode))
				{
					ChildBranches.Add(ChildBranch(OtherPin, MyPin, LocalChildren));
				}

				//UE_LOG(LogTemp, Warning, TEXT("Local children for %s"), *FBAUtils::GetNodeName(CurrentNode));
				//for (UEdGraphNode* Node : LocalChildren)
				//{
				//	UE_LOG(LogTemp, Warning, TEXT("\tChild %s"), *FBAUtils::GetNodeName(Node));
				//}

				if (!bChildIsSameRow && LocalChildren.Num() > 0)
				{
					UEdGraphPin* PinToAvoid = LastLinked;
					if (MainPin != nullptr)
					{
						PinToAvoid = MainPin;
						MainPin = nullptr;
					}

					if (PinToAvoid != nullptr && GetDefault<UBASettings>()->bCustomDebug != 27)
					{
						TSet<UEdGraphNode*> NodesToMove;
						FSlateRect Bounds = bAccountForComments ? GetRelativeBoundsForNodes(LocalChildren.Array(), CurrentNode, NodesToMove, true) : FBAUtils::GetCachedNodeArrayBounds(GraphHandler, LocalChildren.Array());
						
						// UE_LOG(LogTemp, Warning, TEXT("\t\t\tPin to avoid %s (%s)"), *FBAUtils::GetPinName(PinToAvoid), *FBAUtils::GetPinName(OtherPin));
						const float PinPos = GraphHandler->GetPinY(PinToAvoid) + VerticalPinSpacing;
						const float Delta = PinPos - Bounds.Top;
						
						if (Delta > 0)
						{
							if (NodesToMove.Num() > 0)
							{
								for (auto Node : NodesToMove)
								{
									Node->NodePosY += Delta;
								}
							}
							else
							{
								for (UEdGraphNode* Child : LocalChildren)
								{
									Child->NodePosY += Delta;
									RefreshParameters(Child);
								}
							}
						}
					}
				}

				LastProcessed = OtherPin;
			}

			LastLinked = MyPin;

			DeltaY += 1;
		}

		if (bCenterBranches && ChildBranches.Num() >= NumRequiredBranches && ParentDirection == EGPD_Output)
		{
			if (CurrentDirection != ParentDirection)
			{
				bCenteredParent = true;
			}
			
			CenterBranches(CurrentNode, ChildBranches, NodesToCollisionCheck);
		}
	}

	Children.Add(CurrentNode);

	if (bSameRow && ParentPin != nullptr && !bCenteredParent)
	{
		// UE_LOG(LogTemp, Warning, TEXT("\t\t\tStraightening pin from %s to %s"),
		//        *FBAUtils::GetPinName(CurrentPin),
		//        *FBAUtils::GetPinName(ParentPin));

		FBAUtils::StraightenPin(GraphHandler, CurrentPin, ParentPin);
		RefreshParameters(ParentPin->GetOwningNode());
	}
}

void FEdGraphFormatter::GetPinsOfSameHeight_Recursive(
	UEdGraphNode* CurrentNode,
	UEdGraphPin* CurrentPin,
	UEdGraphPin* ParentPin,
	TSet<UEdGraphNode*>& NodesToCollisionCheck,
	TSet<FPinLink>& VisitedLinks)
{
	NodesToCollisionCheck.Emplace(CurrentNode);

	TArray<TArray<UEdGraphPin*>> OutputInput;

	const EEdGraphPinDirection Direction = CurrentPin == nullptr ? EGPD_Output : CurrentPin->Direction.GetValue();

	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, Direction).FilterByPredicate(IsExecOrDelegatePin));
	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, UEdGraphPin::GetComplementaryDirection(Direction)).FilterByPredicate(IsExecOrDelegatePin));

	bool bFirstPin = true;

	auto& GraphHandlerCapture = GraphHandler;

	auto LinkedToSorter = [&GraphHandlerCapture, &NodesToCollisionCheck](UEdGraphPin& PinA, UEdGraphPin& PinB)
	{
		struct FLocal
		{
			static void GetPins(UEdGraphPin* NextPin, TSet<UEdGraphNode*>& VisitedNodes, TArray<UEdGraphPin*>& OutPins, bool& bHasEventNode, int32& DepthToEventNode, int32 TempDepth)
			{
				if (FBAUtils::IsEventNode(NextPin->GetOwningNode()))
				{
					DepthToEventNode = TempDepth;
					bHasEventNode = true;
				}

				if (VisitedNodes.Contains(NextPin->GetOwningNode()))
				{
					OutPins.Add(NextPin);
					return;
				}

				VisitedNodes.Add(NextPin->GetOwningNode());

				auto NextPins = FBAUtils::GetLinkedToPins(NextPin->GetOwningNode(), EGPD_Input);

				for (UEdGraphPin* Pin : NextPins)
				{
					GetPins(Pin, VisitedNodes, OutPins, bHasEventNode, DepthToEventNode, TempDepth + 1);
				}
			}

			static UEdGraphPin* HighestPin(TSharedPtr<FBAGraphHandler> GraphHandler, UEdGraphPin* Pin, TSet<UEdGraphNode*>& VisitedNodes, bool& bHasEventNode, int32& DepthToEventNode)
			{
				TArray<UEdGraphPin*> OutPins;
				GetPins(Pin, VisitedNodes, OutPins, bHasEventNode, DepthToEventNode, 0);

				if (OutPins.Num() == 0)
					return nullptr;

				OutPins.StableSort([GraphHandler](UEdGraphPin& PinA, UEdGraphPin& PinB)
				{
					const FVector2D PinPosA = FBAUtils::GetPinPos(GraphHandler, &PinA);
					const FVector2D PinPosB = FBAUtils::GetPinPos(GraphHandler, &PinB);

					if (PinPosA.X != PinPosB.X)
						return PinPosA.X < PinPosB.X;

					return PinPosA.Y < PinPosB.Y;
				});

				return OutPins[0];
			}
		};

		bool bHasEventNodeA = false;
		int32 DepthToEventNodeA = 0;

		auto VisitedNodesCopyA = NodesToCollisionCheck;
		UEdGraphPin* HighestPinA = FLocal::HighestPin(GraphHandlerCapture, &PinA, VisitedNodesCopyA, bHasEventNodeA, DepthToEventNodeA);
		bool bHasEventNodeB = false;
		int32 DepthToEventNodeB = 0;
		auto VisitedNodesCopyB = NodesToCollisionCheck;
		UEdGraphPin* HighestPinB = FLocal::HighestPin(GraphHandlerCapture, &PinB, VisitedNodesCopyB, bHasEventNodeB, DepthToEventNodeB);

		if (HighestPinA == nullptr || HighestPinB == nullptr)
		{
			if (bHasEventNodeA != bHasEventNodeB)
				return bHasEventNodeA > bHasEventNodeB;

			return DepthToEventNodeA > DepthToEventNodeB;
		}

		const FVector2D PinPosA = FBAUtils::GetPinPos(GraphHandlerCapture, HighestPinA);
		const FVector2D PinPosB = FBAUtils::GetPinPos(GraphHandlerCapture, HighestPinB);

		if (PinPosA.X != PinPosB.X)
			return PinPosA.X < PinPosB.X;

		return PinPosA.Y < PinPosB.Y;
	};

	for (TArray<UEdGraphPin*>& Pins : OutputInput)
	{
		for (UEdGraphPin* MyPin : Pins)
		{
			TArray<UEdGraphPin*> LinkedPins = MyPin->LinkedTo;

			if (MyPin->Direction == EGPD_Input && GetMutableDefault<UBASettings>()->FormattingStyle == BANodeFormatting_Expanded)
			{
				LinkedPins.StableSort(LinkedToSorter);
			}

			for (int i = 0; i < LinkedPins.Num(); ++i)
			{
				UEdGraphPin* OtherPin = LinkedPins[i];
				UEdGraphNode* OtherNode = OtherPin->GetOwningNode();
				FPinLink Link(MyPin, OtherPin);

				// UE_LOG(LogTemp, Warning, TEXT("Iterating %s"), *Link.ToString());

				if (VisitedLinks.Contains(Link)
					|| !NodePool.Contains(OtherNode)
					|| FBAUtils::IsNodePure(OtherNode)
					|| NodesToCollisionCheck.Contains(OtherNode))
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tSkipping"));
					continue;
				}
				VisitedLinks.Add(Link);


				if (bFirstPin && (ParentPin == nullptr || MyPin->Direction == ParentPin->Direction))
				{
					// UE_LOG(LogTemp, Warning, TEXT("Same row?"));
					SameRowMapping.Add(Link, true);
					SameRowMapping.Add(FPinLink(OtherPin, MyPin), true);
					bFirstPin = false;
				}

				GetPinsOfSameHeight_Recursive(OtherNode, OtherPin, MyPin, NodesToCollisionCheck, VisitedLinks);
			}
		}
	}
}

void FEdGraphFormatter::AddKnotNodesToComments()
{
	if (CommentNodesContains.Num() == 0)
	{
		return;
	}
	
	for (TSharedPtr<FKnotNodeTrack> Track : KnotTracks)
	{		
		TArray<UEdGraphNode*> TrackNodes = Track->GetNodes(GraphHandler->GetFocusedEdGraph()).Array();

		int NumKnots = 0;
		UK2Node_Knot* SingleKnot = nullptr;
		for (auto Creation : Track->KnotCreations)
		{
			if (Creation->CreatedKnot != nullptr)
			{
				NumKnots += 1;
				SingleKnot = Creation->CreatedKnot;
			}
		}
		
		for (const auto& Elem : CommentNodesContains)
		{
			UEdGraphNode_Comment* Comment = Elem.Key;
			TArray<UEdGraphNode*> Containing = Elem.Value;
			FSlateRect CommentBounds = GetCommentBounds(Comment, nullptr);// .ExtendBy(30);

			const auto IsNotInsideComment = [&CommentBounds](TSharedPtr<FKnotNodeCreation> Creation)
			{
				UK2Node_Knot* Knot = Creation->CreatedKnot;

				if (Knot != nullptr)
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tComment bounds %s | %s"), *CommentBounds.ToString(), *FVector2D(Knot->NodePosX, Knot->NodePosY).ToString());
					return !CommentBounds.ContainsPoint(FVector2D(Knot->NodePosX, Knot->NodePosY));
				}
				
				return false;
			};

			bool bContainsSingleKnot = NumKnots == 1 && CommentBounds.ContainsPoint(FVector2D(SingleKnot->NodePosX, SingleKnot->NodePosY));
			const bool bContainsAllNodes = FBAUtils::DoesArrayContainsAllItems(Containing, TrackNodes);

			// UE_LOG(LogTemp, Warning, TEXT("\t\tAllKnots %d | AllNodes %d"), bContainsAllKnots, bContainsAllNodes);
			
			if (bContainsAllNodes)
			{
				if (!(NumKnots == 1 && bContainsSingleKnot))
				{
					auto NodesUnderComment = Comment->GetNodesUnderComment();
					for (auto Creation : Track->KnotCreations)
					{
						if (!NodesUnderComment.Contains(Creation->CreatedKnot))
						{
							Comment->AddNodeUnderComment(Creation->CreatedKnot);
						}
					}
				}
			}
		}
	}
}

UEdGraphNode* FEdGraphFormatter::GetHighestLevelParentNode(UEdGraphNode* Node)
{
	while (FormatXInfoMap.Contains(Node))
	{
		auto Info = FormatXInfoMap[Node];
		if (NodeHeightLevels[Node] == 0)
		{
			return Node;
		}

		return GetHighestLevelParentNode(Info->Parent->GetNode());
	}

	return nullptr;
}

void FEdGraphFormatter::WrapNodes()
{
	TArray<UEdGraphNode*> PendingNodes;
	PendingNodes.Push(RootNode);

	TSet<UEdGraphNode*> VisitedNodes;

	const float RootPos = RootNode->NodePosX;
	
	while (PendingNodes.Num() > 0)
	{
		UEdGraphNode* NextNode = PendingNodes.Pop();
		if (NextNode->NodePosX - RootPos > 1000)
		{
			TSharedPtr<FFormatXInfo> Info = FormatXInfoMap[NextNode];
			TArray<UEdGraphNode*> Children = Info->GetChildren(EGPD_Output);

			float Offset = RootPos - NextNode->NodePosX;
			NextNode->NodePosX += Offset;
			NextNode->NodePosY += 500;

			for (UEdGraphNode* Child : Children)
			{
				Child->NodePosX += Offset;
				Child->NodePosY += 500;
			}
		}

		TArray<UEdGraphNode*> OutputNodes = FBAUtils::GetLinkedNodes(NextNode, EGPD_Output); 
		
		for (UEdGraphNode* Node : OutputNodes)
		{
			if (VisitedNodes.Contains(Node))
			{
				continue;
			}

			VisitedNodes.Add(Node);
			PendingNodes.Add(Node);			
		}
	}
}

void FEdGraphFormatter::ExpandKnotTracks()
{
	// UE_LOG(LogTemp, Error, TEXT("### Expanding Knot Tracks"));
	// for (auto Elem : KnotTracks)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("KnotTrack %s"), *FBAUtils::GetPinName(Elem->GetParentPin()));
	// }

	// sort tracks by:
	// 1. exec over parameter
	// 2. Highest track Y
	// 3. Smallest track width
	// 4. Parent pin height
	TSharedPtr<FBAGraphHandler> GraphHandlerCapture = GraphHandler;
	const auto& ExpandTrackSorter = [GraphHandlerCapture](const TSharedPtr<FKnotNodeTrack>& TrackA, const TSharedPtr<FKnotNodeTrack>& TrackB)
	{
		if (TrackA->bIsLoopingTrack != TrackB->bIsLoopingTrack)
			return TrackA->bIsLoopingTrack < TrackB->bIsLoopingTrack;

		// TODO: Improve ordering of the tracks to favor non-aligned
		//const bool bTrackAWantsToAlign = TrackA->PinToAlignTo != nullptr;
		//const bool bTrackBWantsToAlign = TrackB->PinToAlignTo != nullptr;
		//if (bTrackAWantsToAlign != bTrackBWantsToAlign)
		//	return bTrackAWantsToAlign < bTrackBWantsToAlign;

		const bool bIsExecPinA = FBAUtils::IsExecPin(TrackA->GetLastPin());
		const bool bIsExecPinB = FBAUtils::IsExecPin(TrackB->GetLastPin());
		if (bIsExecPinA != bIsExecPinB)
			return bIsExecPinA > bIsExecPinB;

		if (TrackA->GetTrackHeight() != TrackB->GetTrackHeight())
		{
			return TrackA->bIsLoopingTrack
                ? TrackA->GetTrackHeight() > TrackB->GetTrackHeight()
                : TrackA->GetTrackHeight() < TrackB->GetTrackHeight();
		}

		const float WidthA = TrackA->GetTrackBounds().GetSize().X;
		const float WidthB = TrackB->GetTrackBounds().GetSize().X;
		if (WidthA != WidthB)
		{
			return TrackA->bIsLoopingTrack
                ? WidthA > WidthB
                : WidthA < WidthB;
		}

		return GraphHandlerCapture->GetPinY(TrackA->GetLastPin()) < GraphHandlerCapture->GetPinY(TrackB->GetLastPin());
	};

	// const auto RemoveAlignedTracks = [](TSharedPtr<FKnotNodeTrack> KnotTrack)
	// {
	// 	return FBAUtils::IsParameterPin(KnotTrack->ParentPin) || !KnotTrack->PinToAlignTo.IsValid();
	// };
	//
	// TArray<TSharedPtr<FKnotNodeTrack>> SortedTracks = KnotTracks.FilterByPredicate(RemoveAlignedTracks);

	TArray<TSharedPtr<FKnotNodeTrack>> SortedTracks = KnotTracks;
	SortedTracks.StableSort(ExpandTrackSorter);
	
	TArray<TSharedPtr<FKnotNodeTrack>> PendingTracks = SortedTracks;

	// for (auto Track : SortedTracks)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Expanding tracks %s"), *Track->ToString());
	// }

	int COUNT_ERROR_PENDING = 0;
	
	TSet<TSharedPtr<FKnotNodeTrack>> PlacedTracks;
	while (PendingTracks.Num() > 0)
	{
		COUNT_ERROR_PENDING += 1;
		if (COUNT_ERROR_PENDING > 100)
		{
			UE_LOG(LogBlueprintAssist, Error, TEXT("Failed to expand pending tracks"));
			break;
		}
		
		TSharedPtr<FKnotNodeTrack> CurrentTrack = PendingTracks[0];
		PlacedTracks.Add(CurrentTrack);

		const float TrackY = CurrentTrack->GetTrackHeight();
		
		float LastTrackY = MAX_FLT;

		FSlateRect ExpandedBounds = CurrentTrack->GetTrackBounds();
		ExpandedBounds.Top = TrackY;

		// UE_LOG(LogTemp, Warning, TEXT("Process pending Track %s (%s)"), *FBAUtils::GetPinName(CurrentTrack->ParentPin), *FBAUtils::GetNodeName(CurrentTrack->ParentPin->GetOwningNode()));
		
		// check against all other tracks, and find ones which overlap with the current track
		TArray<TSharedPtr<FKnotNodeTrack>> OverlappingTracks;
		OverlappingTracks.Add(CurrentTrack);
		for (TSharedPtr<FKnotNodeTrack> Track : SortedTracks)
		{
			if (Track == CurrentTrack)
				continue;

			if (FSlateRect::DoRectanglesIntersect(Track->GetTrackBounds(), CurrentTrack->GetTrackBounds()))
			{
				OverlappingTracks.Add(Track);
				// UE_LOG(LogTemp, Warning, TEXT("\tTrack %s colliding %s"), *FBAUtils::GetPinName(Track->ParentPin), *FBAUtils::GetPinName(CurrentTrack->ParentPin));
			}
		}

		if (OverlappingTracks.Num() == 1)
		{
			// UE_LOG(LogTemp, Warning, TEXT("\tRemoved pin to align to: continueing"));
			PendingTracks.Remove(CurrentTrack);
			continue;
		}

		int COUNT_ERROR_OVERLAPPING = 0;
		int i = 0;

		const auto& PinAlignedFirst = [](const TSharedPtr<FKnotNodeTrack>& TrackA, const TSharedPtr<FKnotNodeTrack>& TrackB)
		{
			if (TrackA->HasPinToAlignTo() != TrackB->HasPinToAlignTo())
			{
				return TrackA->HasPinToAlignTo() > TrackB->HasPinToAlignTo();
			}

			return TrackA->GetTrackHeight() < TrackB->GetTrackHeight();
		};
		
		OverlappingTracks.StableSort(PinAlignedFirst);
		
		while (OverlappingTracks.Num() > 0)
		{
			COUNT_ERROR_OVERLAPPING += 1;
			if (COUNT_ERROR_OVERLAPPING > 100)
			{
				UE_LOG(LogBlueprintAssist, Error, TEXT("Failed to resolve overlapping tracks"));
				break;
			}
			
			TSharedPtr<FKnotNodeTrack> Track = OverlappingTracks[0];

			if (LastTrackY != MAX_FLT)
			{
				const float NewTrackY = LastTrackY + TrackSpacing;
				Track->UpdateTrackHeight(NewTrackY);
				// UE_LOG(LogTemp, Warning, TEXT("\tSet Track %s to %f"), *FBAUtils::GetPinName(Track->ParentPin), NewTrackY);
			}

			const auto OverlappingTrackBounds = Track->GetTrackBounds();
			ExpandedBounds.Left = FMath::Min(OverlappingTrackBounds.Left, ExpandedBounds.Left);
			ExpandedBounds.Right = FMath::Max(OverlappingTrackBounds.Right, ExpandedBounds.Right);

			LastTrackY = Track->GetTrackHeight();

			if (!Track->PinToAlignTo.IsValid()) // don't add aligned tracks
			{
				PlacedTracks.Add(Track);
			}

			// check against all other tracks, and find ones which overlap with the current track
			const auto NewTracks = [&PlacedTracks, &OverlappingTracks](TSharedPtr<FKnotNodeTrack> KnotTrack)
			{
				return !PlacedTracks.Contains(KnotTrack) && !OverlappingTracks.Contains(KnotTrack);// && !KnotTrack->PinToAlignTo.IsValid();
				// return !OverlappingTracks.Contains(Track) && !Track->PinToAlignTo.IsValid();
			};

			for (TSharedPtr<FKnotNodeTrack> KnotTrack : SortedTracks.FilterByPredicate(NewTracks))
			{
				// UE_LOG(LogTemp, Warning, TEXT("Checking %s against %s"), *Track->ToString(), *KnotTrack->ToString());
				
				if (FSlateRect::DoRectanglesIntersect(KnotTrack->GetTrackBounds(), Track->GetTrackBounds()))
				{
					// UE_LOG(LogTemp, Warning, TEXT("Added overlapping Track %s"), *FBAUtils::GetPinName(KnotTrack->ParentPin));
					OverlappingTracks.Add(KnotTrack);
				}
			}

			// UE_LOG(LogTemp, Warning, TEXT("OverlappingTracks"));
			// for (TSharedPtr<FKnotNodeTrack> MyTrack : OverlappingTracks)
			// {
			// 	UE_LOG(LogTemp, Warning, TEXT("\tOverlapping Track %s"), *FBAUtils::GetPinName(MyTrack->ParentPin));
			// }
			//
			// UE_LOG(LogTemp, Warning, TEXT("PlacedTracks"));
			// for (TSharedPtr<FKnotNodeTrack> PlacedTrack : PlacedTracks)
			// {
			// 	UE_LOG(LogTemp, Warning, TEXT("\tPlaced Track %s"), *FBAUtils::GetPinName(PlacedTrack->ParentPin));
			// }
			//
			// UE_LOG(LogTemp, Warning, TEXT("\tSet track %s at %f"), *FBAUtils::GetPinName(Track->ParentPin), NewTrackY);

			OverlappingTracks.RemoveAt(0);

			i += 1;
		}

		for (TSharedPtr<FKnotNodeTrack> Track : PlacedTracks)
		{
			// UE_LOG(LogTemp, Warning, TEXT("\tPlaced track %s"), *Track->ToString());
			PendingTracks.Remove(Track);
		}

		// UE_LOG(LogTemp, Warning, TEXT("%d"), i);
		
		if (i == 1)
			continue;

		TSet<UEdGraphNode*> TrackNodes = CurrentTrack->GetNodes(GraphHandler->GetFocusedEdGraph());
		float Bottom = LastTrackY;

		ExpandedBounds.Bottom = Bottom + TrackSpacing * 0.5f;

		// find the top of the tallest node the track block is colliding with
		bool bAnyCollision = false;
		float CollisionTop = MAX_flt;

		// collide against nodes
		for (UEdGraphNode* Node : GetFormattedGraphNodes())
		{
			// if (Node == CurrentTrack->LinkedTo[0]->GetOwningNode() || Node == CurrentTrack->GetLastPin()->GetOwningNode())
			// 	continue;

			bool bSkipNode = false;
			for (TSharedPtr<FKnotNodeTrack> Track : PlacedTracks)
			{
				if (Node == Track->LinkedTo[0]->GetOwningNode() || Node == Track->GetLastPin()->GetOwningNode())
				{
					// UE_LOG(LogTemp, Warning, TEXT("Skipping node %s"), *FBAUtils::GetNodeName(Node));
					bSkipNode = true;
					break;
				}
				
				if (auto AlignedPin = Track->GetPinToAlignTo())
				{
					if (Node == AlignedPin->GetOwningNode())
					{
						// UE_LOG(LogTemp, Warning, TEXT("Skipping node aligned %s"), *FBAUtils::GetNodeName(Node));
						bSkipNode = true;
						break;
					}
				}
			}

			if (bSkipNode)
			{
				continue;
			}
			

			const FSlateRect NodeBounds = GraphHandler->GetCachedNodeBounds(Node);
			// UE_LOG(LogTemp, Warning, TEXT("Checking collision for %s | %s | %s"), *FBAUtils::GetNodeName(Node), *NodeBounds.ToString(), *ExpandedBounds.ToString());

			if (FSlateRect::DoRectanglesIntersect(NodeBounds, ExpandedBounds))
			{
				// UE_LOG(LogTemp, Warning, TEXT("Collision with %s"), *FBAUtils::GetNodeName(Node));
				bAnyCollision = true;
				CollisionTop = FMath::Min(NodeBounds.Top, CollisionTop);
			}
		}

		if (!bAnyCollision)
			continue;

		float Delta = ExpandedBounds.Bottom - CollisionTop;
		// UE_LOG(LogTemp, Warning, TEXT("### Moving nodes down | Block of tracks of size %d | Delta %f"), i, Delta);

		// move all nodes below the track block
		TSet<UEdGraphNode*> MovedNodes;
		for (UEdGraphNode* Node : GetFormattedGraphNodes())
		{
			// UE_LOG(LogTemp, Warning, TEXT("\tChecking Node for collision %s | My %d | Track %f"), *FBAUtils::GetNodeName(Node), Node->NodePosY, TrackY);

			if (Node->NodePosY > TrackY)
			{
				Node->NodePosY += Delta;
				MovedNodes.Add(Node);
				// UE_LOG(LogTemp, Warning, TEXT("\t Moved node %s by delta %f"), *FBAUtils::GetNodeName(Node), Delta);
			}
		}

		for (TSharedPtr<FKnotNodeTrack> Track : SortedTracks)
		{
			//UE_LOG(LogTemp, Warning, TEXT("CHECKING track %s"), *BlueprintAssistUtils::GetNodeName(Track->ParentPin->GetOwningNode()));

			if (PlacedTracks.Contains(Track))
				continue;

			if (Track->GetPinToAlignTo() != nullptr) // if we are aligned to a pin, update our track y when a node moves
			{
				//UE_LOG(LogTemp, Warning, TEXT("\tTrack is easy solution"));

				if (MovedNodes.Contains(Track->GetLastPin()->GetOwningNode()) || MovedNodes.Contains(
					Track->ParentPin->GetOwningNode()))
				{
					//UE_LOG(LogTemp, Warning, TEXT("\tMoved EAST SOLUTION Track for node delta %s"), *BlueprintAssistUtils::GetNodeName(Track->GetLastPin()->GetOwningNode()));
					Track->UpdateTrackHeight(Track->GetTrackHeight() + Delta);
				}
			}
			else if (Track->GetTrackHeight() > TrackY)
			{
				//UE_LOG(LogTemp, Warning, TEXT("\tMoved BELOW Track for node delta %s"), *BlueprintAssistUtils::GetNodeName(Track->GetLastPin()->GetOwningNode()));
				Track->UpdateTrackHeight(Track->GetTrackHeight() + Delta);
			}
		}
	}
}

void FEdGraphFormatter::FormatKnotNodes()
{
	//UE_LOG(LogTemp, Warning, TEXT("### Format Knot Nodes"));

	MakeKnotTrack();

	// UE_LOG(LogTemp, Warning, TEXT("### All Knot Tracks"));
	// for (TSharedPtr<FKnotNodeTrack> Track : KnotTracks)
	// {
	// 	FString EasySolution = Track->GetPinToAlignTo() != nullptr ? FString("True") : FString("False");
	// 	FString Looping = Track->bIsLoopingTrack ? FString("True") : FString("False");
	// 	UE_LOG(LogTemp, Warning, TEXT("\tKnot Tracks %s | %s | %s | EasySol %s | Looping %s"),
	// 	       *FBAUtils::GetPinName(Track->ParentPin),
	// 	       *FBAUtils::GetNodeName(Track->ParentPin->GetOwningNodeUnchecked()),
	// 		   *FBAUtils::GetPinName(Track->GetLastPin()),
	// 		   *FBAUtils::GetNodeName(Track->GetLastPin()->GetOwningNodeUnchecked()),
	// 	       *EasySolution,
	// 	       *Looping);
	// 	
	// 	for (TSharedPtr<FKnotNodeCreation> Elem : Track->KnotCreations)
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("\t\t%s"), *Elem->KnotPos.ToString());
	// 	}
	// }

	MergeNearbyKnotTracks();

	if (GetDefault<UBASettings>()->bCustomDebug != 280)
	{
		ExpandKnotTracks();
	}

	CreateKnotTracks();

	if (GetDefault<UBASettings>()->bAddKnotNodesToComments)
	{
		AddKnotNodesToComments();
	}
}

void FEdGraphFormatter::CreateKnotTracks()
{
	// we sort tracks by
	// 1. exec pin track over parameter track 
	// 2. top-most-track-height 
	// 3. top-most parent pin 
	// 4. left-most
	const auto& TrackSorter = [](const TSharedPtr<FKnotNodeTrack> TrackA, const TSharedPtr<FKnotNodeTrack> TrackB)
	{
		const bool bIsExecPinA = FBAUtils::IsExecPin(TrackA->GetLastPin());
		const bool bIsExecPinB = FBAUtils::IsExecPin(TrackB->GetLastPin());

		if (bIsExecPinA != bIsExecPinB)
			return bIsExecPinA > bIsExecPinB;

		if (TrackA->GetTrackHeight() != TrackB->GetTrackHeight())
			return TrackA->GetTrackHeight() < TrackB->GetTrackHeight();

		if (TrackA->ParentPinPos.Y != TrackB->ParentPinPos.Y)
			return TrackA->ParentPinPos.Y < TrackB->ParentPinPos.Y;

		return TrackA->GetTrackBounds().GetSize().X < TrackB->GetTrackBounds().GetSize().X;
	};
	KnotTracks.Sort(TrackSorter);

	for (TSharedPtr<FKnotNodeTrack> KnotTrack : KnotTracks)
	{
		// sort knot creations
		auto GraphCapture = GraphHandler->GetFocusedEdGraph();
		const auto CreationSorter = [GraphCapture](TSharedPtr<FKnotNodeCreation> CreationA, TSharedPtr<FKnotNodeCreation> CreationB)
		{
			UEdGraphPin* Pin = FBAUtils::GetPinFromGraph(CreationA->PinToConnectToHandle, GraphCapture);
			
			if (FBAUtils::IsExecPin(Pin))
			{
				return CreationA->KnotPos.X > CreationB->KnotPos.X;
			}

			return CreationA->KnotPos.X < CreationB->KnotPos.X;
		};

		if (!KnotTrack->bIsLoopingTrack)
		{
			KnotTrack->KnotCreations.StableSort(CreationSorter);
		}

		// UE_LOG(LogTemp, Warning, TEXT("Creating knot track"));
		// if (KnotTrack->PinToAlignTo.IsValid())
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("\tShould make aligned track!"));
		// }
		
		TSharedPtr<FKnotNodeCreation> LastCreation = nullptr;
		const int NumCreations = KnotTrack->KnotCreations.Num();
		for (int i = 0; i < NumCreations; i++)
		{
			TSharedPtr<FKnotNodeCreation> Creation = KnotTrack->KnotCreations[i];
			Creation->CreationIndex = i;
			Creation->OwningKnotTrack = KnotTrack;

			FVector2D KnotPos = Creation->KnotPos;

			// UE_LOG(LogTemp, Warning, TEXT("Making knot creation at %s %d"), *KnotPos.ToString(), i);
			for (auto Pin : Creation->PinHandlesToConnectTo)
			{
				// UE_LOG(LogTemp, Warning, TEXT("\tPin %s"), *FBAUtils::GetPinName(FBAUtils::GetPinFromGraph(Pin, GraphHandler->GetFocusedEdGraph())));
			}

			UEdGraphPin* PinToAlignTo = KnotTrack->GetPinToAlignTo();
			
			if (PinToAlignTo != nullptr)
			{
				Creation->PinToConnectToHandle = KnotTrack->PinToAlignTo;
				KnotPos.Y = GraphHandler->GetPinY(PinToAlignTo);

				// UE_LOG(LogTemp, Warning, TEXT("Created knot aligned to %s"), *FBAUtils::GetNodeName(PinToAlignTo->GetOwningNode()));
			}

			if (!LastCreation.IsValid()) // create a knot linked to the first pin (the fallback pin)
			{
				UEdGraphPin* ParentPin = FBAUtils::GetPinFromGraph(FGraphPinHandle(KnotTrack->ParentPin), GraphHandler->GetFocusedEdGraph());
				UK2Node_Knot* KnotNode = CreateKnotNode(Creation.Get(), KnotPos, ParentPin);
				// UE_LOG(LogTemp, Warning, TEXT("Create initial %s"), *FBAUtils::GetPinName(ParentPin));
				
				KnotNodesSet.Add(KnotNode);
				LastCreation = Creation;
			}
			else // create a knot that connects to the last knot
			{
				UK2Node_Knot* ParentKnot = LastCreation->CreatedKnot;

				const bool bCreatePinAlignedKnot = LastCreation->PinHandlesToConnectTo.Num() == 1 && PinToAlignTo != nullptr;
				if (bCreatePinAlignedKnot && NumCreations == 1) // move the parent knot to the aligned x position
				{
					// UE_LOG(LogTemp, Warning, TEXT("Create pin aligned!"));
					for (const FGraphPinHandle& PinHandle : Creation->PinHandlesToConnectTo)
					{
						UEdGraphPin* Pin = FBAUtils::GetPinFromGraph(PinHandle, GraphHandler->GetFocusedEdGraph());
						
						UEdGraphPin* ParentPin = Pin->Direction == EGPD_Input
							? ParentKnot->GetOutputPin()
							: ParentKnot->GetInputPin();
						FBAUtils::TryCreateConnection(ParentPin, Pin);
					}
				}
				else
				{
					// UE_LOG(LogTemp, Warning, TEXT("Create normal"));
					
					UEdGraphPin* LastPin = KnotTrack->GetLastPin();

					UEdGraphPin* PinOnLastKnot = LastPin->Direction == EGPD_Output
						? ParentKnot->GetInputPin()
						: ParentKnot->GetOutputPin();

					UK2Node_Knot* NewKnot = CreateKnotNode(Creation.Get(), KnotPos, PinOnLastKnot);
					KnotNodesSet.Add(NewKnot);

					LastCreation = Creation;
				}
			}
		}
	}
}

void FEdGraphFormatter::ResetRelativeToNodeToKeepStill(const FVector2D& SavedLocation)
{
	const float DeltaX = SavedLocation.X - NodeToKeepStill->NodePosX;
	const float DeltaY = SavedLocation.Y - NodeToKeepStill->NodePosY;

	if (DeltaX != 0 || DeltaY != 0)
	{
		TSet<UEdGraphNode*> AllNodes = GetFormattedGraphNodes();
		for (UEdGraphNode* Node : AllNodes)
		{
			Node->NodePosX += DeltaX;
			Node->NodePosY += DeltaY;
		}

		for (UEdGraphNode* Node : KnotNodesSet)
		{
			Node->NodePosX += DeltaX;
			Node->NodePosY += DeltaY;
		}
	}
}

void FEdGraphFormatter::FormatComments()
{
	TSet<UEdGraphNode_Comment*> FormattedComments;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> VisitedNodes;
	TArray<FPinLink> OutputStack;
	TArray<FPinLink> InputStack;
	const FPinLink RootNodeLink(nullptr, nullptr, RootNode);
	OutputStack.Push(RootNodeLink);

	EEdGraphPinDirection LastDirection = EGPD_Output;

	NodesToExpand.Reset();

	while (OutputStack.Num() > 0 || InputStack.Num() > 0)
	{
		// try to get the current info from the pending input
		FPinLink CurrentLink;

		TArray<FPinLink>& FirstStack = LastDirection == EGPD_Output ? OutputStack : InputStack;
		TArray<FPinLink>& SecondStack = LastDirection == EGPD_Output ? InputStack : OutputStack;

		if (FirstStack.Num() > 0)
		{
			CurrentLink = FirstStack.Pop();
		}
		else
		{
			CurrentLink = SecondStack.Pop();
		}

		LastDirection = CurrentLink.GetDirection();

		UEdGraphNode* CurrentNode = CurrentLink.GetNode();
		VisitedNodes.Add(CurrentNode);

		// Format the comment sub graph
		if (ParentComments.Contains(CurrentNode))
		{			
			TArray<UEdGraphNode_Comment*>& Comments = ParentComments[CurrentNode];
			for (auto Comment : Comments)
			{
				if (FormattedComments.Contains(Comment))
					continue;
				
				FormattedComments.Add(Comment);

				FCommentSubGraphFormatterParameters SubGraphParameters;
				SubGraphParameters.bIsCommentFormatter = true;
				SubGraphParameters.NodesToFormat = CommentNodesContains[Comment];

				if (FBAUtils::DoesArrayContainsAllItems(SubGraphParameters.NodesToFormat, NodeTree))
				{
					continue;
				}

				TSharedPtr<FCommentSubGraphFormatter> SubGraphFormatter = MakeShared<FCommentSubGraphFormatter>(GraphHandler, SubGraphParameters, SharedThis(this));

				SubGraphFormatter->FormatNode(CurrentNode);

				SubGraphFormatters.Add(CurrentNode, SubGraphFormatter);
			}
		}

		TArray<UEdGraphPin*> LinkedPins = FBAUtils::GetLinkedPins(CurrentNode).FilterByPredicate(IsExecOrDelegatePin);

		for (int i = LinkedPins.Num() - 1; i >= 0; --i)
		{
			UEdGraphPin* ParentPin = LinkedPins[i];

			for (UEdGraphPin* LinkedPin : ParentPin->LinkedTo)
			{
				UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();

				const FPinLink PinLink(ParentPin, LinkedPin, LinkedNode);
				if (VisitedLinks.Contains(PinLink))
					continue;

				VisitedLinks.Add(PinLink);
				if (!NodePool.Contains(LinkedNode))
					continue;

				if (FBAUtils::IsNodePure(LinkedNode))
					continue;

				// UE_LOG(LogTemp, Warning, TEXT("\t\t\tIterating pin link %s"), *PinLink.ToString());

				if (ParentPin->Direction == EGPD_Output)
				{
					OutputStack.Push(PinLink);
				}
				else
				{
					InputStack.Push(PinLink);
				}
			}
		}
	}
}

int32 FEdGraphFormatter::GetChildX(const FPinLink& Link, const bool bUseClusterNodes)
{	
	if (Link.From == nullptr)
	{
		return GetRelativeNodeBounds(Link.GetNode(), nullptr, bUseClusterNodes).Left;
	}

	float NewNodePos;
	UEdGraphNode* Parent = Link.From->GetOwningNode();
	UEdGraphNode* Child = Link.To->GetOwningNode();
	FSlateRect ParentBounds = bUseClusterNodes
		? GetClusterBounds(Parent)
		: FBAUtils::GetCachedNodeBounds(GraphHandler, Parent);
	
	// if (auto SameRowPtr = SameRowMapping.Find(Link))
	{
		// if (*SameRowPtr)
		{
			TSet<UEdGraphNode*> RelativeNodes;
			auto RelativeBounds = GetRelativeNodeBounds(Parent, Child, RelativeNodes, bUseClusterNodes);

			auto SameRowPtr = SameRowMapping.Find(Link);
			if (SameRowPtr != nullptr && *SameRowPtr)
			{
				// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tTaking Relative bounds %s | OLD %s"), *RelativeBounds.ToString(), *ParentBounds.ToString());
				ParentBounds = RelativeBounds;
			}
			else
			{
				const auto NodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, RelativeNodes.Array());

				bool bIsSame = Link.GetDirection() == EGPD_Output ? NodesBounds.Right == ParentBounds.Right : NodesBounds.Left == ParentBounds.Left;

				if (bIsSame)
				{
					// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tTaking Relative bounds %s | OLD %s"), *RelativeBounds.ToString(), *ParentBounds.ToString());

					
					ParentBounds = RelativeBounds;
				}

			}
			
			//ParentBounds = GetRelativeNodeBounds(Parent, Child, bUseClusterNodes);
		}
	}

	FSlateRect ChildBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, Child);

	FSlateRect LargerBounds = GetRelativeNodeBounds(Child, Parent, bUseClusterNodes);

	if (Link.From->Direction == EGPD_Input)
	{
		const float Delta = LargerBounds.Right - ChildBounds.Left;
		NewNodePos = ParentBounds.Left - Delta - NodePadding.X;// -1;
	}
	else
	{
		const float Delta = ChildBounds.Left - LargerBounds.Left;
		NewNodePos = ParentBounds.Right + Delta + NodePadding.X;// +1;
	}

	// UE_LOG(LogTemp, Warning, TEXT("Node %s New Node Pos %d | %s | %s | %s"), *Link.ToString(), FMath::RoundToInt(NewNodePos), *ParentBounds.ToString(), *ChildBounds.ToString(), *LargerBounds.ToString());

	return FMath::RoundToInt(NewNodePos);
}

void FEdGraphFormatter::RemoveKnotNodes()
{
	TSet<UEdGraphNode*> RemovedNodes;

	auto& GraphHandlerCapture = GraphHandler;
	auto& FormatterParamsCapture = FormatterParameters;
	const auto OnlySelected = [&GraphHandlerCapture, &FormatterParamsCapture](UEdGraphPin* Pin)
	{
		return GraphHandlerCapture->FilterSelectiveFormatting(Pin->GetOwningNode(), FormatterParamsCapture.NodesToFormat)
		&& (FBAUtils::IsParameterPin(Pin) || IsExecOrDelegatePin(Pin));
	};

	TArray<UEdGraphNode_Comment*> CommentNodes = FBAUtils::GetCommentNodesFromGraph(GraphHandler->GetFocusedEdGraph());
	
	for (UEdGraphNode* Node : FBAUtils::GetNodeTreeWithFilter(RootNode, OnlySelected))
	{
		/** Delete all connections for each knot node */
		if (UK2Node_Knot* KnotNode = Cast<UK2Node_Knot>(Node))
		{
			FBAUtils::DisconnectKnotNode(KnotNode);

			for (auto Comment : CommentNodes)
			{
				if (Comment->GetNodesUnderComment().Contains(KnotNode))
				{
					FBAUtils::RemoveNodeFromComment(Comment, KnotNode);
				}
			}
			
			if (GetMutableDefault<UBASettings>()->bUseKnotNodePool)
			{
				KnotNodePool.Add(KnotNode);
			}
			else
			{
				FBAUtils::DeleteNode(KnotNode);
			}
		}
	}
}

bool FEdGraphFormatter::IsExecOrDelegatePin(UEdGraphPin* Pin)
{
	const bool bUseDelegatePins = GetMutableDefault<UBASettings>()->bTreatDelegatesAsExecutionPins && FBAUtils::IsDelegatePin(Pin) && FBAUtils::IsNodeImpure(Pin->GetOwningNode());
	return FBAUtils::IsExecPin(Pin) || bUseDelegatePins;
}

void FEdGraphFormatter::ModifyCommentNodes()
{
	if (!GetMutableDefault<UBASettings>()->bTryToHandleCommentNodes)
		return;
	
	/** Modify all comment nodes which our formatted nodes (needed for the AutoSizeComment plugin) */
	TArray<UEdGraphNode_Comment*> AllCommentNodes;
	GraphHandler->GetFocusedEdGraph()->GetNodesOfClass(AllCommentNodes);

	for (UEdGraphNode_Comment* CommentNode : AllCommentNodes)
	{
		TArray<UEdGraphNode*> EdGraphNodesUnderComment;

		bool bShouldUpdateNode = false;
		for (UObject* NodeUnderComment : CommentNode->GetNodesUnderComment())
		{
			if (UEdGraphNode* Node = Cast<UEdGraphNode>(NodeUnderComment))
			{
				if (!FBAUtils::IsCommentNode(Node) && !FBAUtils::IsKnotNode(Node))
				{
					if (GetFormattedGraphNodes().Contains(Node))
					{
						bShouldUpdateNode = true;
					}

					EdGraphNodesUnderComment.Add(Node);
				}
			}
		}

		if (bShouldUpdateNode)
		{
			TSharedPtr<SGraphNodeComment> GraphNodeComment = StaticCastSharedPtr<SGraphNodeComment>(FBAUtils::GetGraphNode(GraphHandler->GetGraphPanel(), CommentNode));
			if (GraphNodeComment.IsValid())
			{
				const float TitlebarHeight = GraphNodeComment->GetDesiredSizeForMarquee().Y;
				const FVector2D CommentPadding = GetDefault<UBASettings>()->CommentNodePadding;
				const FMargin Padding = FMargin(CommentPadding.X, CommentPadding.Y + TitlebarHeight, CommentPadding.X, CommentPadding.Y);
				const FSlateRect NewBounds = FBAUtils::GetNodeArrayBounds(EdGraphNodesUnderComment).ExtendBy(Padding);
				CommentNode->SetBounds(NewBounds);
			}
		}
	}
}

UK2Node_Knot* FEdGraphFormatter::CreateKnotNode(FKnotNodeCreation* Creation, const FVector2D& Position, UEdGraphPin* ParentPin)
{
	if (!Creation)
		return nullptr;

	UK2Node_Knot* OptionalNodeToReuse = nullptr;
	if (GetMutableDefault<UBASettings>()->bUseKnotNodePool && KnotNodePool.Num() > 0)
	{
		OptionalNodeToReuse = KnotNodePool.Pop();
	} 
	else
	{
		// UE_LOG(LogTemp, Warning, TEXT("Failed to find?"));
	}

	auto Graph = GraphHandler->GetFocusedEdGraph();
	UK2Node_Knot* CreatedNode = Creation->CreateKnotNode(Position, ParentPin, OptionalNodeToReuse, Graph);

	UEdGraphPin* MainPinToConnectTo = FBAUtils::GetPinFromGraph(Creation->PinToConnectToHandle, Graph);
	
	KnotNodeOwners.Add(CreatedNode, MainPinToConnectTo->GetOwningNode());
	// UE_LOG(LogTemp, Warning, TEXT("Created node %d for %s"), CreatedNode, *FBAUtils::GetNodeName(ParentPin->GetOwningNode()));
	
	return CreatedNode;//Creation->CreateKnotNode(Position, ParentPin, OptionalNodeToReuse, GraphHandler->GetFocusedEdGraph());
}

void FEdGraphFormatter::GetPinsOfSameHeight()
{
	TSet<UEdGraphNode*> NodesToCollisionCheck;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> TempChildren;
	GetPinsOfSameHeight_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks);
}

FSlateRect FEdGraphFormatter::GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, bool bUseClusterBounds)
{
	TSet<UEdGraphNode*> Unused;
	return GetRelativeNodeBounds(Node, NodeAsking, Unused, bUseClusterBounds);
}

FSlateRect FEdGraphFormatter::GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes, bool bUseClusterBounds)
{
	if (!GetDefault<UBASettings>()->bAccountForCommentsWhenFormatting || !bAccountForComments)
	{
		return bUseClusterBounds ? GetClusterBounds(Node) : FBAUtils::GetCachedNodeBounds(GraphHandler, Node);
	}

	TArray<UEdGraphNode_Comment*> NodeComments;
	if (ParentComments.Contains(Node))
	{
		NodeComments = ParentComments[Node];
	}

	TArray<UEdGraphNode_Comment*> NodeAskingCommentNodes;
	if (ParentComments.Contains(NodeAsking))
	{
		NodeAskingCommentNodes = ParentComments[NodeAsking];
	}
	
	// FSlateRect OutBounds = bUseClusterBounds ? GetRelativeClusterBounds(Node, NodeAsking) : FBAUtils::GetCachedNodeBounds(GraphHandler, Node);
	FSlateRect OutBounds = bUseClusterBounds ? GetClusterBounds(Node) : FBAUtils::GetCachedNodeBounds(GraphHandler, Node);

	// apply the comment node padding
	for (UEdGraphNode_Comment* CommentNode : NodeComments)
	{
		if (NodeAskingCommentNodes.Contains(CommentNode))
		{
			continue;
		}

		auto NodesUnderComment = FBAUtils::GetNodesUnderComment(CommentNode);

		if (NodesUnderComment.Num() == 0)
			continue;
		
		const auto IsUnderComment = [&NodesUnderComment](const FPinLink& PinLink)
		{
			return NodesUnderComment.Contains(PinLink.GetNode());
		};

		const auto CommentNodeTree = FBAUtils::GetNodeTreeWithFilter(NodesUnderComment[0], IsUnderComment);
		const auto& NodeTreeCapture = NodeTree;
		
		// skip if 1. nodes are not linked 2. any nodes are not in our node tree 3. if pure node: then the parent must be in the comment box
		auto ThisCapture = this;
		auto& ParameterParentMapCapture = ParameterParentMap;
		const auto ShouldSkip = [&CommentNodeTree, &NodeTreeCapture, &ThisCapture, &NodesUnderComment, &ParameterParentMapCapture](UEdGraphNode* Node)
		{
			if (FBAUtils::IsCommentNode(Node) || FBAUtils::IsKnotNode(Node))
				return false;

			// if (FBAUtils::IsNodePure(Node))
			// {
			// 	if (ParameterParentMapCapture.Contains(Node))
			// 	{
			// 		auto ParamFormatter = ParameterParentMapCapture[Node];
			// 		if (ParamFormatter.IsValid())
			// 		{
			// 			UE_LOG(LogTemp, Warning, TEXT("Checking param formatter for %s | %s"), *FBAUtils::GetNodeName(Node), *FBAUtils::GetNodeName(ParamFormatter->GetRootNode()));
			// 			if (!NodesUnderComment.Contains(ParamFormatter->GetRootNode()))
			// 			{
			// 				UE_LOG(LogTemp, Warning, TEXT("Skipping root node"));
			// 				return true;
			// 			}
			// 		}
			// 	}
			// }
			
			return !CommentNodeTree.Contains(Node) || !NodeTreeCapture.Contains(Node);
		};
		
		if (NodesUnderComment.ContainsByPredicate(ShouldSkip))
		{
			// UE_LOG(LogTemp, Warning, TEXT("Skipping node!"));
			continue;
		}

		// skip if the other node is contained in our comment node
		if (ParentComments.Contains(NodeAsking))
		{
			bool bSkipCommentNode = false;

			for (UEdGraphNode_Comment* OtherComment : ParentComments[NodeAsking])
			{
				auto OtherNodesUnderComment = FBAUtils::GetNodesUnderComment(OtherComment);
				if (CommentNode == OtherComment || NodesUnderComment.Contains(OtherComment) || OtherNodesUnderComment.Contains(CommentNode))
					continue;
				
				for (UEdGraphNode* OtherNode : OtherNodesUnderComment)
				{
					if (NodesUnderComment.Contains(OtherNode))
					{
						bSkipCommentNode = true;
						break;
					}
				}
				if (bSkipCommentNode)
					break;
			}
			if (bSkipCommentNode)
				continue;
		}

		auto CommentNodeBounds = GetCommentBounds(CommentNode, NodeAsking);

		// UE_LOG(LogTemp, Warning, TEXT("\t\tExpanding bounds for %s | OLD %s | NEW %s"), *FBAUtils::GetNodeName(Node), *OutBounds.ToString(), *OutBounds.Expand(CommentNodeBounds).ToString());

		OutBounds = OutBounds.Expand(CommentNodeBounds);

		for (auto NodeUnderComment : NodesUnderComment)
		{
			if (!FBAUtils::IsCommentNode(NodeUnderComment))
			{
				RelativeNodes.Add(NodeUnderComment);
			}
		}
	}

	return OutBounds;
}

FSlateRect FEdGraphFormatter::GetCommentNodeBounds(UEdGraphNode_Comment* CommentNode, const FSlateRect& InBounds, FMargin& PostPadding)
{
	auto ObjUnderComment = CommentNode->GetNodesUnderComment();
	TArray<UEdGraphNode*> NodesUnderComment;
	for (auto Obj : ObjUnderComment)
	{
		if (UEdGraphNode* EdNode = Cast<UEdGraphNode>(Obj))
		{
			if (FBAUtils::IsCommentNode(EdNode))
				continue;

			NodesUnderComment.Add(EdNode);
		}
	}

	const auto ContainedNodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, NodesUnderComment);
	auto OutBounds = InBounds;

	const auto BASettings = GetDefault<UBASettings>();
	const FVector2D Padding = BASettings->CommentNodePadding;
	float TitlebarHeight = 0.f;
	
	TSharedPtr<SGraphNodeComment> GraphNodeComment = StaticCastSharedPtr<SGraphNodeComment>(FBAUtils::GetGraphNode(GraphHandler->GetGraphPanel(), CommentNode));
	if (GraphNodeComment.IsValid())
	{
		TitlebarHeight = GraphNodeComment->GetDesiredSizeForMarquee().Y;
	}

	if (ContainedNodesBounds.Left == InBounds.Left)
	{
		PostPadding.Left += Padding.X;
	}
	else if (ContainedNodesBounds.Left < InBounds.Left)
	{
		OutBounds.Left = ContainedNodesBounds.Left;
		PostPadding.Left = Padding.X;
	}
	
	if (ContainedNodesBounds.Right == InBounds.Right)
	{
		PostPadding.Right += Padding.X;
	}
	else if (ContainedNodesBounds.Right > InBounds.Right)
	{
		OutBounds.Right = ContainedNodesBounds.Right;
		PostPadding.Right = Padding.X;
	}
	
	if (ContainedNodesBounds.Top == InBounds.Top)
	{
		PostPadding.Top += Padding.Y + TitlebarHeight;
	}
	else if (ContainedNodesBounds.Top > InBounds.Top)
	{
		OutBounds.Top = ContainedNodesBounds.Top;
		PostPadding.Top = Padding.Y + TitlebarHeight;
	}
	
	if (ContainedNodesBounds.Bottom == InBounds.Bottom)
	{
		PostPadding.Bottom += Padding.Y;
	}
	else if (ContainedNodesBounds.Bottom < InBounds.Bottom)
	{
		OutBounds.Bottom = ContainedNodesBounds.Bottom;
		PostPadding.Left = Padding.Y;
	}

	return OutBounds;
}

FSlateRect FEdGraphFormatter::GetCommentBounds(UEdGraphNode_Comment* CommentNode, UEdGraphNode* NodeAsking)
{
	auto ObjUnderComment = CommentNode->GetNodesUnderComment();
	TArray<UEdGraphNode*> NodesUnderComment;
	TArray<UEdGraphNode_Comment*> CommentNodesUnderComment;
	
	for (auto Obj : ObjUnderComment)
	{
		if (UEdGraphNode* EdNode = Cast<UEdGraphNode>(Obj))
		{
			if (auto Comment = Cast<UEdGraphNode_Comment>(EdNode))
			{
				CommentNodesUnderComment.Add(Comment);
			}
			else
			{
				NodesUnderComment.Add(EdNode);
			}
		}
	}

	for (auto Node : NodesUnderComment)
	{
		// UE_LOG(LogTemp, Warning, TEXT("\t\t\tNodeUnderComment %s | %s"), *FBAUtils::GetNodeName(Node), *FBAUtils::GetCachedNodeBounds(GraphHandler, Node).ToString());
	}
	

	auto ContainedNodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, NodesUnderComment);
	// UE_LOG(LogTemp, Warning, TEXT("\t\t ContainedNodesBounds %s"), *ContainedNodesBounds.ToString());
	for (UEdGraphNode_Comment* CommentUnderComment : CommentNodesUnderComment)
	{
		if (ParentComments.Contains(NodeAsking))
		{
			if (ParentComments[NodeAsking].Contains(CommentUnderComment))
			{
				continue;
			}
		}

		
		ContainedNodesBounds = ContainedNodesBounds.Expand(GetCommentBounds(CommentUnderComment, NodeAsking));
		// UE_LOG(LogTemp, Warning, TEXT("\t\t ContainedNodesBounds %s"), *ContainedNodesBounds.ToString());
	}
	
	const FVector2D Padding = GetDefault<UBASettings>()->CommentNodePadding;

	const float TitlebarHeight = FBAUtils::GetCachedNodeBounds(GraphHandler, CommentNode, false).GetSize().Y;

	const FMargin CommentPadding(
		Padding.X, 
		Padding.Y + TitlebarHeight,
		Padding.X, 
		Padding.Y);

	// UE_LOG(LogTemp, Warning, TEXT("\t\tContainedNodeBounds %s | Padding %s"), *ContainedNodesBounds.ToString(), *CommentPadding.GetDesiredSize().ToString());
	
	ContainedNodesBounds = ContainedNodesBounds.ExtendBy(CommentPadding);

	return ContainedNodesBounds;
}

void FEdGraphFormatter::ApplyCommentPadding(FSlateRect& Bounds, UEdGraphNode* Node, EEdGraphPinDirection Direction)
{
	if (!ParentComments.Contains(Node))
		return;
	
	FSlateRect NodeBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, Node);
	
	if (Direction == EGPD_Input)
	{
		float Offset = 0;
		for (auto Comment : ParentComments[Node])
		{
			auto ObjUnderComment = Comment->GetNodesUnderComment();
			TArray<UEdGraphNode*> NodesUnderComment;
			for (auto Obj : ObjUnderComment)
			{
				if (UEdGraphNode* EdNode = Cast<UEdGraphNode>(Obj))
				{
					if (FBAUtils::IsCommentNode(EdNode))
						continue;

					NodesUnderComment.Add(EdNode);
				}
			}

			const auto ContainedNodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, NodesUnderComment);
			if (ContainedNodesBounds.Left == NodeBounds.Left)
			{
				Offset += 30;
			}
		}
		Bounds.Left -= Offset;
	}
	else
	{
		float Offset = 0;
		for (auto Comment : ParentComments[Node])
		{
			auto ObjUnderComment = Comment->GetNodesUnderComment();
			TArray<UEdGraphNode*> NodesUnderComment;
			for (auto Obj : ObjUnderComment)
			{
				if (UEdGraphNode* EdNode = Cast<UEdGraphNode>(Obj))
				{
					if (FBAUtils::IsCommentNode(EdNode))
						continue;

					NodesUnderComment.Add(EdNode);
				}
			}

			const auto ContainedNodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, NodesUnderComment);
			if (ContainedNodesBounds.Right == NodeBounds.Right)
			{
				Offset += 30;
			}
		}
		Bounds.Right += Offset;
	}
}

void FEdGraphFormatter::FormatParameterNodes()
{
	TArray<UEdGraphNode*> IgnoredNodes;

	TArray<UEdGraphNode*> NodePoolCopy = NodePool;

	const auto& LeftTopMostSort = [](const UEdGraphNode& NodeA, const UEdGraphNode& NodeB)
	{
		if (NodeA.NodePosX != NodeB.NodePosX)
			return NodeA.NodePosX < NodeB.NodePosX;

		return NodeA.NodePosY < NodeB.NodePosY;
	};
	NodePoolCopy.StableSort(LeftTopMostSort);

	ParameterParentMap.Reset();

	for (UEdGraphNode* MainNode : NodePoolCopy)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Format parameters for node %s"), *FBAUtils::GetNodeName(MainNode));

		TSharedPtr<FEdGraphParameterFormatter> ParameterFormatter = GetParameterFormatter(MainNode);
		ParameterFormatter->SetIgnoredNodes(IgnoredNodes);
		ParameterFormatter->FormatNode(MainNode);

		// update node -> parameter formatter map
		for (UEdGraphNode* NodeToCheck : ParameterFormatter->GetFormattedNodes())
		{
			if (ParameterParentMap.Contains(NodeToCheck))
			{
				// if the node already has a parent, update the old parent by removing 
				TSharedPtr<FEdGraphParameterFormatter> ParentFormatter = ParameterParentMap[NodeToCheck];
				ParentFormatter->FormattedOutputNodes.Remove(NodeToCheck);
				ParentFormatter->AllFormattedNodes.Remove(NodeToCheck);

				// UE_LOG(LogTemp, Warning, TEXT("Removed node %s from %s"), *FBAUtils::GetNodeName(NodeToCheck), *FBAUtils::GetNodeName(ParentFormatter->GetRootNode()));
			}

			// UE_LOG(LogTemp, Warning, TEXT("Added node %s to %s"), *FBAUtils::GetNodeName(NodeToCheck), *FBAUtils::GetNodeName(ParameterFormatter->GetRootNode()));
			ParameterParentMap.Add(NodeToCheck, ParameterFormatter);
		}

		// the next main nodes will ignore the input nodes from the parameter formatter
		IgnoredNodes.Append(ParameterFormatter->FormattedInputNodes.Array());
	}

	if (GetMutableDefault<UBASettings>()->bExpandParametersByHeight)
	{
		for (UEdGraphNode* MainNode : NodePoolCopy)
		{
			TSharedPtr<FEdGraphParameterFormatter> ParameterFormatter = GetParameterFormatter(MainNode);
			ParameterFormatter->ExpandByHeight();
		}
	}

	for (auto& Elem  : ParameterFormatterMap)
	{
		// UE_LOG(LogTemp, Warning, TEXT("MainParamForm: %s"), *FBAUtils::GetNodeName(Elem.Key));

		TSharedPtr<FEdGraphParameterFormatter> ParamFormatter = Elem.Value;
		ParamFormatter->SaveRelativePositions();
		ParamFormatter->bInitialized = true;

		// for (auto Child : ParamFormatter->GetFormattedNodes())
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("\tNode %s"), *FBAUtils::GetNodeName(Child));
		// }
	}
}

TSet<UEdGraphNode*> FEdGraphFormatter::GetFormattedGraphNodes()
{
	TSet<UEdGraphNode*> OutNodes;
	for (UEdGraphNode* Node : NodePool)
		OutNodes.Append(GetParameterFormatter(Node)->GetFormattedNodes());

	return OutNodes;
}

void FEdGraphFormatter::RefreshParameters(UEdGraphNode* Node)
{
	if (FBAUtils::IsNodePure(Node))
		return;
	
	TSharedPtr<FEdGraphParameterFormatter> Formatter = GetParameterFormatter(Node);
	Formatter->FormatNode(Node);
}

bool FEdGraphFormatter::IsFormattingRequired(const TArray<UEdGraphNode*>& NewNodeTree)
{
	if (!NewNodeTree.Contains(NodeToKeepStill))
		return true;

	// Check if a node has been deleted
	if (NodeTree.ContainsByPredicate(FBAUtils::IsNodeDeleted))
	{
		//UE_LOG(LogTemp, Warning, TEXT("One of the nodes has been deleted"));
		return true;
	}

	// Check if the number of nodes has changed
	if (NodeTree.Num() != NewNodeTree.Num())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Num nodes changed %d to %d"), NewNodeTree.Num(), NodeTree.Num());
		return true;
	}

	// Check if the node tree has changed
	for (UEdGraphNode* Node : NewNodeTree)
	{
		if (!NodeTree.Contains(Node))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Node tree changed for node %s"), *FBAUtils::GetNodeName(Node));
			return true;
		}
	}

	// Check if any formatted nodes from last time have changed position or links
	for (UEdGraphNode* Node : GetFormattedNodes())
	{
		// Check if node has changed
		if (NodeChangeInfos.Contains(Node))
		{
			FNodeChangeInfo ChangeInfo = NodeChangeInfos[Node];
			if (ChangeInfo.HasChanged(NodeToKeepStill))
			{
				//UE_LOG(LogTemp, Warning, TEXT("Node links or position has changed"));
				return true;
			}
		}
	}

	TArray<UEdGraphNode_Comment*> CachedComments;
	CommentNodesContains.GetKeys(CachedComments);

	// Check if any comment nodes have been deleted
	const auto& NodeTreeCapture = NodeTree;
	TArray<UEdGraphNode_Comment*> CommentNodes = FBAUtils::GetCommentNodesFromGraph(GraphHandler->GetFocusedEdGraph());
	for (auto Comment : CommentNodes)
	{
		TArray<UEdGraphNode*> Contained = FBAUtils::GetNodesUnderComment(Comment);
		UEdGraphNode** RelativeNodePtr = Contained.FindByPredicate([&NodeTreeCapture](UEdGraphNode* Node)
		{
			return NodeTreeCapture.Contains(Node);
		});

		if (RelativeNodePtr != nullptr)
		{
			if (!CachedComments.Contains(Comment))
			{
				return true;
			}
		}
	}


	// Check contained comment nodes
	for (UEdGraphNode_Comment* Comment : CachedComments)
	{
		if (!CommentNodes.Contains(Comment))
		{
			return true;
		}

		TArray<UEdGraphNode*>& CachedContained = CommentNodesContains[Comment];
		TArray<UEdGraphNode*> CurrentContained = FBAUtils::GetNodesUnderComment(Comment);
		if (CachedContained.Num() != CurrentContained.Num())
		{
			return true;
		}

		for (auto Contained : CachedContained)
		{
			if (!CurrentContained.Contains(Contained))
			{
				return true;
			}
		}
	}

	return false;
}

void FEdGraphFormatter::SaveFormattingEndInfo()
{
	// Save the position so we can move relative to this the next time we format
	LastFormattedX = NodeToKeepStill->NodePosX;
	LastFormattedY = NodeToKeepStill->NodePosY;

	// Save node information
	for (UEdGraphNode* Node : GetFormattedNodes())
	{
		if (NodeChangeInfos.Contains(Node))
		{
			NodeChangeInfos[Node].UpdateValues(NodeToKeepStill);
		}
		else
		{
			NodeChangeInfos.Add(Node, FNodeChangeInfo(Node, NodeToKeepStill));
		}
	}
}

TArray<UEdGraphNode*> FEdGraphFormatter::GetNodeTree(UEdGraphNode* InitialNode) const
{
	const auto& GraphHandlerCapture = GraphHandler;
	const auto& FormatterParametersCapture = FormatterParameters;
	const auto Filter = [&GraphHandlerCapture, &FormatterParametersCapture](const FPinLink& Link)
	{
		return GraphHandlerCapture->FilterDelegatePin(Link, FormatterParametersCapture.NodesToFormat);
	};
	return FBAUtils::GetNodeTreeWithFilter(InitialNode, Filter).Array();
}

bool FEdGraphFormatter::IsInitialNodeValid(UEdGraphNode* Node) const
{
	if (!Node)
		return false;
	if (Cast<UEdGraphNode_Comment>(Node))
		return false;
	if (Cast<UK2Node_Knot>(Node))
		return false;

	return true;
}

FSlateRect FEdGraphFormatter::GetClusterBounds(UEdGraphNode* Node)
{
	const TArray<UEdGraphNode*> Nodes = GetParameterFormatter(Node)->GetFormattedNodes().Array();
	return FBAUtils::GetCachedNodeArrayBounds(GraphHandler, Nodes);
}

FSlateRect FEdGraphFormatter::GetRelativeClusterBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking)
{
	const TArray<UEdGraphNode*> ParameterNodes = GetParameterFormatter(Node)->GetFormattedNodes().Array();

	if (ParameterNodes.Num() == 0)
		return FBAUtils::GetCachedNodeBounds(GraphHandler, Node);

	bool bBoundsInit = false;
	FSlateRect Bounds;
	for (int i = 0; i < ParameterNodes.Num(); i++)
	{
		UEdGraphNode* ParameterNode = ParameterNodes[i];
		if (!ParameterNode)
			continue;

		// initialize bounds from first valid node
		if (!bBoundsInit)
		{
			Bounds = GetRelativeNodeBounds(ParameterNode, NodeAsking, true);
			bBoundsInit = true;
		}
		else
		{
			Bounds = Bounds.Expand(GetRelativeNodeBounds(ParameterNode, NodeAsking, true));
		}
	}

	return Bounds;
}

FSlateRect FEdGraphFormatter::GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, bool bUseClusterBounds)
{
	TArray<FSlateRect> AllBounds;

	for (UEdGraphNode* Node : Nodes)
	{
		AllBounds.Add(GetRelativeNodeBounds(Node, NodeAsking, bUseClusterBounds));
	}

	return FBAUtils::GetGroupedBounds(AllBounds);
}

FSlateRect FEdGraphFormatter::GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes, bool bUseClusterBounds)
{
	TArray<FSlateRect> AllBounds;

	for (UEdGraphNode* Node : Nodes)
	{
		AllBounds.Add(GetRelativeNodeBounds(Node, NodeAsking, RelativeNodes, bUseClusterBounds));
	}

	return FBAUtils::GetGroupedBounds(AllBounds);
}

FSlateRect FEdGraphFormatter::GetClusterBoundsForNodes(const TArray<UEdGraphNode*>& Nodes)
{
	TArray<UEdGraphNode*> NodesInColumn;

	for (UEdGraphNode* Node : Nodes)
		if (Node)
			NodesInColumn.Append(GetParameterFormatter(Node)->GetFormattedNodes().Array());

	return FBAUtils::GetCachedNodeArrayBounds(GraphHandler, NodesInColumn);
}

TSharedPtr<FEdGraphParameterFormatter> FEdGraphFormatter::GetParameterFormatter(UEdGraphNode* Node)
{
	if (!ParameterFormatterMap.Contains(Node))
		ParameterFormatterMap.Add(Node, MakeShared<FEdGraphParameterFormatter>(GraphHandler, Node, SharedThis(this)));

	return ParameterFormatterMap[Node];
}

TSet<UEdGraphNode*> FEdGraphFormatter::GetFormattedNodes()
{
	if (MainParameterFormatter.IsValid())
	{
		return MainParameterFormatter->GetFormattedNodes();
	}
	
	TSet<UEdGraphNode*> OutNodes;
	for (UEdGraphNode* Node : NodePool)
		OutNodes.Append(GetParameterFormatter(Node)->GetFormattedNodes());

	OutNodes.Append(KnotNodesSet);

	return OutNodes;
}

void FEdGraphFormatter::FormatY()
{
	NodeHeightLevels.Add(RootNode, 0);
	
	bAccountForComments = false;
	TSet<UEdGraphNode*> NodesToCollisionCheck;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> TempChildren;
	FormatY_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks, true, TempChildren);

	bAccountForComments = GetDefault<UBASettings>()->bAccountForCommentsWhenFormatting;
	NodesToCollisionCheck.Reset();
	VisitedLinks.Reset();
	TempChildren.Reset();
	FormatY_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks, true, TempChildren);
}

void FEdGraphFormatter::CenterBranches(UEdGraphNode* CurrentNode, TArray<ChildBranch>& ChildBranches, TSet<UEdGraphNode*>& NodesToCollisionCheck)
{
	// Center branches
	TArray<UEdGraphPin*> ChildPins;
	TArray<UEdGraphPin*> ParentPins;
	for (ChildBranch& Branch : ChildBranches)
	{
		ChildPins.Add(Branch.Pin);
		ParentPins.Add(Branch.ParentPin);
	}
	
	const float ChildrenCenter = FBAUtils::GetCenterYOfPins(GraphHandler, ChildPins);
	const float ParentCenter = FBAUtils::GetCenterYOfPins(GraphHandler, ParentPins);
	const float Offset = ParentCenter - ChildrenCenter;

	TArray<UEdGraphNode*> AllNodes;
	
	for (ChildBranch& Branch : ChildBranches)
	{
		for (UEdGraphNode* Child : Branch.BranchNodes)
		{
			AllNodes.Add(Child);
			Child->NodePosY += Offset;
			RefreshParameters(Child);
		}
	}

	// Resolve collisions
	AllNodes.Add(CurrentNode);
	FSlateRect AllNodesBounds = bAccountForComments ? GetRelativeBoundsForNodes(AllNodes, CurrentNode, true) : GetClusterBoundsForNodes(AllNodes);
	const float InitialTop = AllNodesBounds.Top;
	for (auto Node : NodesToCollisionCheck)
    {
		if (AllNodes.Contains(Node))
		{
			continue;
		}
		
    	FSlateRect Bounds = bAccountForComments ? GetRelativeNodeBounds(Node, CurrentNode, true) : GetClusterBounds(Node);
		Bounds = Bounds.ExtendBy(FMargin(0, 0, 0, NodePadding.Y));
    	if (FSlateRect::DoRectanglesIntersect(Bounds, AllNodesBounds))
    	{
			const float OffsetY = Bounds.Bottom - AllNodesBounds.Top;
    		AllNodesBounds = AllNodesBounds.OffsetBy(FVector2D(0, OffsetY));
    	}
    }

	const float DeltaY = AllNodesBounds.Top - InitialTop;
	if (DeltaY != 0)
	{
		for (auto Node : AllNodes)
		{
			Node->NodePosY += DeltaY;
			RefreshParameters(Node);
		}
	}
}

bool FEdGraphFormatter::TryAlignTrackToEndPins(TSharedPtr<FKnotNodeTrack> Track, const TArray<UEdGraphNode*>& AllNodes)
{
	const float ParentPinY = GraphHandler->GetPinY(Track->ParentPin);
	const float LastPinY = GraphHandler->GetPinY(Track->GetLastPin());
	bool bPreferParentPin = ParentPinY > LastPinY;

	if (FBAUtils::IsExecPin(Track->ParentPin))
	{
		bPreferParentPin = true;
	}

	for (int i = 0; i < 2; ++i)
	{
		//FString PreferPinStr = bPreferParentPin ? "true" : "false";
		//UE_LOG(LogTemp, Warning, TEXT("AlignTrack ParentY %f (%s) | LastPinY %f (%s) | PreferParent %s"), ParentPinY, *FBAUtils::GetPinName(Track->ParentPin), LastPinY,
		//       *FBAUtils::GetPinName(Track->GetLastPin()), *PreferPinStr);

		if (i == 1)
			bPreferParentPin = !bPreferParentPin;

		UEdGraphPin* SourcePin = bPreferParentPin ? Track->ParentPin : Track->GetLastPin();
		UEdGraphPin* OtherPin = bPreferParentPin ? Track->GetLastPin() : Track->ParentPin;

		const FVector2D SourcePinPos = FBAUtils::GetPinPos(GraphHandler, SourcePin);
		const FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);

		const FVector2D Padding = FBAUtils::IsParameterPin(OtherPin)
			? PinPadding
			: NodePadding;

		const FVector2D Point
			= SourcePin->Direction == EGPD_Output
			? FVector2D(OtherPinPos.X - Padding.X, SourcePinPos.Y)
			: FVector2D(OtherPinPos.X + Padding.X, SourcePinPos.Y);

		//UE_LOG(LogTemp, Error, TEXT("Checking Point %s | %s"), *Point.ToString(), *FBAUtils::GetNodeName(SourcePin->GetOwningNode()));

		bool bAnyCollision = false;

		for (UEdGraphNode* NodeToCollisionCheck : AllNodes)
		{
			FSlateRect CollisionBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, NodeToCollisionCheck).
				ExtendBy(FMargin(0, TrackSpacing * 0.25, 0, TrackSpacing * 0.25));

			// UE_LOG(LogTemp, Warning, TEXT("Collision check against %s | %s | %s"), *FBAUtils::GetNodeName(NodeToCollisionCheck), *CollisionBounds.ToString(), *Point.ToString());

			if (NodeToCollisionCheck == SourcePin->GetOwningNode() || NodeToCollisionCheck == OtherPin->GetOwningNode())
			{
				// UE_LOG(LogTemp, Warning, TEXT("\tSkipping node"));
				continue;
			}

			if (FBAUtils::LineRectIntersection(CollisionBounds, SourcePinPos, Point))
			{
				// UE_LOG(LogTemp, Warning, TEXT("\tFound collision"));
				bAnyCollision = true;
				break;
			}
		}

		for (TSharedPtr<FKnotNodeTrack> OtherTrack : KnotTracks)
        {
        	if (OtherTrack == Track)
        		continue;

			if (FBAUtils::LineRectIntersection(Track->GetTrackBounds().ExtendBy(FMargin(0, TrackSpacing * 0.25f)), SourcePinPos, Point))
        	// if (FSlateRect::DoRectanglesIntersect(Track->GetTrackBounds(), OtherTrack->GetTrackBounds()))
        	{
	            // UE_LOG(LogTemp, Warning, TEXT("Track %s colliding with %s"), *Track->ToString(), *OtherTrack->ToString());
        		bAnyCollision = true;
        		break;
        	}
        }

		if (!bAnyCollision)
		{
			// UE_LOG(LogTemp, Warning, TEXT("sucessfully found easy solution!"));
			Track->PinAlignedX = Point.X;
			Track->UpdateTrackHeight(SourcePinPos.Y);
			Track->PinToAlignTo = SourcePin;
			return true;
		}
	}

	return false;
}

bool FEdGraphFormatter::DoesPinNeedTrack(UEdGraphPin* Pin, const TArray<UEdGraphPin*>& LinkedTo)
{
	if (LinkedTo.Num() == 0)
		return false;

	// if the pin is linked to multiple linked nodes, we need a knot track
	if (LinkedTo.Num() > 1)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Multiple linked to?"));
		return true;
	}

	// otherwise the pin is linked to exactly 1 node, run a collision check
	UEdGraphPin* OtherPin = LinkedTo[0];
	bool Collsion = AnyCollisionBetweenPins(Pin, OtherPin);
	// UE_LOG(LogTemp, Warning, TEXT("Collision: %d"), Collsion);
	return AnyCollisionBetweenPins(Pin, OtherPin);
}

bool FEdGraphFormatter::AnyCollisionBetweenPins(UEdGraphPin* Pin, UEdGraphPin* OtherPin)
{
	TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();

	const FVector2D PinPos = FBAUtils::GetPinPos(GraphHandler, Pin);
	const FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);

	return NodeCollisionBetweenLocation(PinPos, OtherPinPos, {Pin->GetOwningNode(), OtherPin->GetOwningNode()});
}

bool FEdGraphFormatter::NodeCollisionBetweenLocation(FVector2D Start, FVector2D End, TSet<UEdGraphNode*> IgnoredNodes)
{
	TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();

	for (UEdGraphNode* NodeToCollisionCheck : FormattedNodes)
	{
		if (IgnoredNodes.Contains(NodeToCollisionCheck))
			continue;

		FSlateRect NodeBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, NodeToCollisionCheck);//.ExtendBy(FMargin(0, TrackSpacing * 0.5f));
		if (FBAUtils::LineRectIntersection(NodeBounds, Start, End))
		{
			// UE_LOG(LogTemp, Warning, TEXT("\tNode collision!"));
			return true;
		}
	}

	return false;
}

void FEdGraphFormatter::MakeKnotTrack()
{
	const TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();

	auto& GraphHandlerCapture = GraphHandler;
	auto FormatterParametersCapture = FormatterParameters;
	const auto& NotFormatted = [FormattedNodes, GraphHandlerCapture, FormatterParametersCapture](UEdGraphPin* Pin)
	{
		return !FormattedNodes.Contains(Pin->GetOwningNode()) || !GraphHandlerCapture->FilterSelectiveFormatting(Pin->GetOwningNode(), FormatterParametersCapture.NodesToFormat);
	};

	// iterate across the pins of all nodes and determine if they require a knot track
	for (UEdGraphNode* MyNode : FormattedNodes)
	{
		// make tracks for input exec pins
		bool bPreviousHasTrack = false;
		for (UEdGraphPin* MyPin : FBAUtils::GetExecPins(MyNode, EGPD_Input))
		{
			TArray<UEdGraphPin*> LinkedTo = MyPin->LinkedTo;
			LinkedTo.RemoveAll(NotFormatted);
			if (LinkedTo.Num() == 0)
				continue;

			if (GetMutableDefault<UBASettings>()->ExecutionWiringStyle == BAWiringStyle_AlwaysMerge)
			{
				MakeKnotTracksForLinkedExecPins(MyPin, LinkedTo, bPreviousHasTrack);
			}
			else
			{
				for (UEdGraphPin* Pin : LinkedTo)
				{
					MakeKnotTracksForLinkedExecPins(MyPin, {Pin}, bPreviousHasTrack);
				}
			}
		}

		// make tracks for output parameter pins
		bPreviousHasTrack = false;
		for (UEdGraphPin* MyPin : FBAUtils::GetParameterPins(MyNode, EGPD_Output))
		{
			TArray<UEdGraphPin*> LinkedTo = MyPin->LinkedTo;
			LinkedTo.RemoveAll(NotFormatted);
			if (LinkedTo.Num() == 0)
				continue;

			if (GetMutableDefault<UBASettings>()->ParameterWiringStyle == BAWiringStyle_AlwaysMerge)
			{
				MakeKnotTracksForParameterPins(MyPin, LinkedTo, bPreviousHasTrack);
			}
			else
			{
				for (UEdGraphPin* Pin : LinkedTo)
				{
					MakeKnotTracksForParameterPins(MyPin, {Pin}, bPreviousHasTrack);
				}
			}
		}
	}
}

void FEdGraphFormatter::MakeKnotTracksForLinkedExecPins(UEdGraphPin* ParentPin, TArray<UEdGraphPin*> LinkedPins, bool& bPreviousHasTrack)
{
	FVector2D ParentPinPos = FBAUtils::GetPinPos(GraphHandler, ParentPin);
	UEdGraphNode* ParentNode = ParentPin->GetOwningNode();

	// check for looping pins, these are pins where 
	// the x position of the pin is less than the x value of the parent pin
	TArray<UEdGraphPin*> LoopingPins;
	for (UEdGraphPin* LinkedPin : LinkedPins)
	{
		const FVector2D LinkedPinPos = FBAUtils::GetPinPos(GraphHandler, LinkedPin);
		if (LinkedPinPos.X > ParentPinPos.X)
		{
			LoopingPins.Add(LinkedPin);
		}
	}

	// create looping tracks
	for (UEdGraphPin* OtherPin : LoopingPins)
	{
		const float OtherNodeTop = FBAUtils::GetNodeBounds(OtherPin->GetOwningNode()).Top;
		const float MyNodeTop = FBAUtils::GetNodeBounds(ParentNode).Top;
		const float AboveNodeWithPadding = FMath::Min(OtherNodeTop, MyNodeTop) - TrackSpacing * 2;

		TArray<UEdGraphPin*> TrackPins = { OtherPin };
		TSharedPtr<FKnotNodeTrack> KnotTrack = MakeShared<FKnotNodeTrack>(SharedThis(this), GraphHandler, ParentPin, TrackPins, AboveNodeWithPadding, true);
		KnotTracks.Add(KnotTrack);

		const FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);

		const FVector2D FirstKnotPos(ParentPinPos.X + 20, KnotTrack->GetTrackHeight());
		TSharedPtr<FKnotNodeCreation> FirstLoopingKnot = MakeShared<FKnotNodeCreation>(FirstKnotPos, nullptr, OtherPin);
		KnotTrack->KnotCreations.Add(FirstLoopingKnot);

		const FVector2D SecondKnotPos(OtherPinPos.X - 20, KnotTrack->GetTrackHeight());
		TSharedPtr<FKnotNodeCreation> SecondLoopingKnot = MakeShared<FKnotNodeCreation>(SecondKnotPos, FirstLoopingKnot, OtherPin);
		KnotTrack->KnotCreations.Add(SecondLoopingKnot);

		KnotTrack->bIsLoopingTrack = true;
	}

	LinkedPins.RemoveAll([&LoopingPins](UEdGraphPin* Pin) { return LoopingPins.Contains(Pin); });

	// remove pins which are left or too close to my pin
	const float Threshold = ParentPinPos.X - NodePadding.X * 1.5f;
	TSharedPtr<FBAGraphHandler> GraphHandlerRef = GraphHandler;
	const auto& IsTooCloseToParent = [GraphHandlerRef, Threshold](UEdGraphPin* Pin)
	{
		const FVector2D PinPos = FBAUtils::GetPinPos(GraphHandlerRef, Pin);
		return PinPos.X > Threshold;
	};
	LinkedPins.RemoveAll(IsTooCloseToParent);

	auto LinkedToCopy = LinkedPins;

	// remove any linked pins which has the same height and no collision
	UEdGraphPin* PinRemoved = nullptr;
	for (UEdGraphPin* LinkedPin : LinkedPins)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Checking %s"), *FBAUtils::GetPinName(LinkedPin));
		const FVector2D LinkedPinPos = FBAUtils::GetPinPos(GraphHandler, LinkedPin);
		const bool bSameHeight = FMath::Abs(LinkedPinPos.Y - ParentPinPos.Y) < 5.f;
		if (bSameHeight && !AnyCollisionBetweenPins(ParentPin, LinkedPin))
		{
			PinRemoved = LinkedPin;
			break;
		}
	}
	LinkedToCopy.Remove(PinRemoved);

	if (LinkedToCopy.Num() == 0)
		return;

	// sort pins by node's highest x position first then highest y position
	const auto RightTop = [](const UEdGraphPin& PinA, const UEdGraphPin& PinB)
	{
		if (PinA.GetOwningNode()->NodePosX == PinB.GetOwningNode()->NodePosX)
			return PinA.GetOwningNode()->NodePosY > PinB.GetOwningNode()->NodePosY;

		return PinA.GetOwningNode()->NodePosX > PinB.GetOwningNode()->NodePosX;
	};

	LinkedPins.Sort(RightTop);

	const float Dist = FMath::Abs(ParentPinPos.X - FBAUtils::GetPinPos(GraphHandler, LinkedPins.Last()).X);

	// skip the pin distance check if we are expanding by height
	const bool bPinReallyFar = Dist > GetDefault<UBASettings>()->KnotNodeDistanceThreshold && !GetDefault<UBASettings>()->bExpandNodesByHeight;

	const bool bPinNeedsTrack = DoesPinNeedTrack(ParentPin, LinkedPins);
	
	// UE_LOG(LogTemp, Warning, TEXT("Need reroute: %d %d %d"), bPinReallyFar, bPreviousHasTrack, bPinNeedsTrack);
	
	const bool bNeedsReroute = bPinReallyFar || bPreviousHasTrack || bPinNeedsTrack;
	if (!bNeedsReroute)
		return;

	bPreviousHasTrack = true;

	TSharedPtr<FKnotNodeTrack> KnotTrack = MakeShared<FKnotNodeTrack>(SharedThis(this), GraphHandler, ParentPin, LinkedPins, ParentPinPos.Y, false);
	KnotTracks.Add(KnotTrack);

	TryAlignTrackToEndPins(KnotTrack, GetFormattedGraphNodes().Array());

	// if the track height is not the same as the parent pin height, 
	// remove any linked pins which has the same height and no collision
	if (KnotTrack->GetTrackHeight() != ParentPinPos.Y)
	{
		UEdGraphPin* PinRemoved2 = nullptr;
		for (UEdGraphPin* LinkedPin : KnotTrack->LinkedTo)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Checking %s"), *FBAUtils::GetPinName(LinkedPin));
			const FVector2D LinkedPinPos = FBAUtils::GetPinPos(GraphHandler, LinkedPin);
			const bool bSameHeight = FMath::Abs(LinkedPinPos.Y - ParentPinPos.Y) < 5.f;
			if (bSameHeight && !AnyCollisionBetweenPins(ParentPin, LinkedPin))
			{
				PinRemoved2 = LinkedPin;
				break;
			}
		}
		if (PinRemoved2)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Removed pin %s"), *FBAUtils::GetPinName(PinRemoved));
			LinkedPins.Remove(PinRemoved2);
			KnotTrack->LinkedTo.Remove(PinRemoved2);
		}
	}

	TSharedPtr<FKnotNodeCreation> PreviousKnot = nullptr;

	// if the track is not at the same height as the pin, then we need an
	// initial knot right of the inital pin, at the track height
	if (KnotTrack->GetTrackHeight() != ParentPinPos.Y)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Made initial?"));
		const FVector2D MyKnotPos = FVector2D(ParentPinPos.X - NodePadding.X, KnotTrack->GetTrackHeight());
		PreviousKnot = MakeShared<FKnotNodeCreation>(MyKnotPos, PreviousKnot, KnotTrack->ParentPin);
		KnotTrack->KnotCreations.Add(PreviousKnot);
	}

	// create a knot node for each of the pins remaining in linked to
	for (UEdGraphPin* OtherPin : KnotTrack->LinkedTo)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Break link %s"), *FBAUtils::GetPinName(OtherPin));

		ParentPin->BreakLinkTo(OtherPin);

		FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);
		FVector2D LastPinPos = FBAUtils::GetPinPos(GraphHandler, KnotTrack->GetLastPin());

		float KnotX = FMath::Min(OtherPinPos.X + NodePadding.X, ParentPinPos.X - NodePadding.X);

		// UE_LOG(LogTemp, Warning, TEXT("KnotX: %f"), KnotX);

		// if the pin is the same height as the track and the initial pin, just merge with the last one
		if (PreviousKnot.IsValid() && OtherPinPos.Y == KnotTrack->GetTrackHeight() && ParentPinPos.Y == OtherPinPos.Y)
		{
			// UE_LOG(LogTemp, Warning, TEXT("Connected to previous node?"));
			KnotTrack->PinAlignedX = PreviousKnot->KnotPos.X = FMath::Max(PreviousKnot->KnotPos.X, KnotX);
			PreviousKnot->PinHandlesToConnectTo.Add(OtherPin);
		}
		// if the x position is very close to the previous knot's x position, 
		// we should not need to create a new knot instead we merge the locations
		else if (PreviousKnot.IsValid() && FMath::Abs(KnotX - PreviousKnot->KnotPos.X) < 50)
		{
			// UE_LOG(LogTemp, Warning, TEXT("Merging coz too close"));
			PreviousKnot->KnotPos.X = KnotX;
			PreviousKnot->PinHandlesToConnectTo.Add(OtherPin);
		}
		else // create a new knot
		{
			// UE_LOG(LogTemp, Warning, TEXT("New knot %s"), *FBAUtils::GetPinName(OtherPin));
			const FVector2D KnotPos(KnotX, KnotTrack->GetTrackHeight());
			PreviousKnot = MakeShared<FKnotNodeCreation>(KnotPos, PreviousKnot, OtherPin);
			KnotTrack->KnotCreations.Add(PreviousKnot);
		}
	}
}

void FEdGraphFormatter::MakeKnotTracksForParameterPins(UEdGraphPin* ParentPin, TArray<UEdGraphPin*> LinkedPins, bool& bPreviousHasTrack)
{
	// UE_LOG(LogTemp, Warning, TEXT("Make knot tracks for parameter pin %s"), *FBAUtils::GetPinName(ParentPin));
	
	FVector2D ParentPinPos = FBAUtils::GetPinPos(GraphHandler, ParentPin);

	// remove pins which are left or too close to my pin
	const float Threshold = ParentPinPos.X + PinPadding.X * 1.5f;
	TSharedPtr<FBAGraphHandler> GraphHandlerRef = GraphHandler;
	const auto& IsTooCloseToParent = [GraphHandlerRef, Threshold](UEdGraphPin* Pin)
	{
		const FVector2D PinPos = FBAUtils::GetPinPos(GraphHandlerRef, Pin);
		return PinPos.X < Threshold;
	};
	LinkedPins.RemoveAll(IsTooCloseToParent);

	if (LinkedPins.Num() == 0)
		return;

	const auto LeftTop = [](const UEdGraphPin& PinA, const UEdGraphPin& PinB)
	{
		if (PinA.GetOwningNode()->NodePosX == PinB.GetOwningNode()->NodePosX)
			return PinA.GetOwningNode()->NodePosY > PinB.GetOwningNode()->NodePosY;

		return PinA.GetOwningNode()->NodePosX < PinB.GetOwningNode()->NodePosX;
	};
	LinkedPins.Sort(LeftTop);

	FVector2D LastPinPos = FBAUtils::GetPinPos(GraphHandler, LinkedPins.Last());

	float Dist = FMath::Abs(ParentPinPos.X - LastPinPos.X);
	
	const bool bLastPinFarAway = Dist > GetMutableDefault<UBASettings>()->KnotNodeDistanceThreshold && !GetDefault<UBASettings>()->bExpandNodesByHeight;

	const bool bPinNeedsTrack = DoesPinNeedTrack(ParentPin, LinkedPins);
	
	// UE_LOG(LogTemp, Warning, TEXT("Need reroute: %d %d %d"), bLastPinFarAway, bPreviousHasTrack, bPinNeedsTrack);
	
	const bool bNeedsReroute = bPinNeedsTrack || bPreviousHasTrack || bLastPinFarAway;
	if (!bNeedsReroute)
		return;

	// init the knot track
	TSharedPtr<FKnotNodeTrack> KnotTrack = MakeShared<FKnotNodeTrack>(SharedThis(this), GraphHandler, ParentPin, LinkedPins, ParentPinPos.Y, false);
	KnotTracks.Add(KnotTrack);

	// check if the track height can simply be set to one of it's pin's height
	if (LinkedPins.Num() == 1)// && !bPreviousHasTrack)
	{
		if (TryAlignTrackToEndPins(KnotTrack, GetFormattedGraphNodes().Array()))
		{
			// UE_LOG(LogTemp, Warning, TEXT("Found a pin to align to for %s"), *FBAUtils::GetPinName(KnotTrack->ParentPin));
		}
	}

	TSharedPtr<FKnotNodeCreation> PreviousKnot = nullptr;
	
	FVector2D FirstPinPos(FBAUtils::GetPinPos(GraphHandler, LinkedPins[0]).X - PinPadding.X, KnotTrack->GetTrackHeight());

	const bool bNodeCollision = NodeCollisionBetweenLocation(ParentPinPos, FirstPinPos, {ParentPin->GetOwningNode(), LinkedPins[0]->GetOwningNode()});
	
	const bool bAlignNormalTrack = !KnotTrack->HasPinToAlignTo() && (bPreviousHasTrack || bNodeCollision);

	const bool bMakeInitialKnot = !KnotTrack->HasPinToAlignTo() || bAlignNormalTrack;
	
	bool bMadeInitialKnot = false;
	
	// if (bPreviousHasTrack
	// 	|| ParentPinPos.Y != KnotTrack->GetTrackHeight()
	// 	|| NodeCollisionBetweenLocation(ParentPinPos, FirstPinPos, {ParentPin->GetOwningNode(), LinkedPins[0]->GetOwningNode()}))
	if (bMakeInitialKnot)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Made initial knot?"));
		
		const FVector2D InitialKnotPos = FVector2D(ParentPinPos.X + PinPadding.X, KnotTrack->GetTrackHeight());
		PreviousKnot = MakeShared<FKnotNodeCreation>(InitialKnotPos, nullptr, KnotTrack->ParentPin);
		// PreviousKnot = MakeShared<FKnotNodeCreation>(InitialKnotPos, nullptr, KnotTrack->GetLastPin());
		ParentPin->BreakLinkTo(KnotTrack->GetLastPin());
		KnotTrack->KnotCreations.Add(PreviousKnot);
		bMadeInitialKnot = true;
	}

	bPreviousHasTrack = true;

	// bool bSingleKnot = bMadeInitialKnot && KnotTrack->PinToAlignTo.IsValid() && KnotTrack->LinkedTo.Num() == 1;
	// if (bSingleKnot)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Single knot!"));
	// 	return;
	// }
	
	for (UEdGraphPin* OtherPin : KnotTrack->LinkedTo)
	{
		ParentPin->BreakLinkTo(OtherPin);
		FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);
		float KnotX = FMath::Max(OtherPinPos.X - PinPadding.X, ParentPinPos.X + PinPadding.X);

		if (KnotTrack->HasPinToAlignTo() && KnotTrack->LinkedTo.Num() == 1)
		{
			KnotX = KnotTrack->PinAlignedX;
		}

		// UE_LOG(LogTemp, Warning, TEXT("%s | %f"), *OtherPinPos.ToString(), KnotTrack->GetTrackHeight());

		// if the pin is the same height as the track and the initial pin, just merge with the last one
		if (PreviousKnot.IsValid() && OtherPinPos.Y == KnotTrack->GetTrackHeight() && ParentPinPos.Y == OtherPinPos.Y)
		{
			// UE_LOG(LogTemp, Warning, TEXT("Connected to previous node?"));
			KnotTrack->PinAlignedX = PreviousKnot->KnotPos.X = FMath::Min(PreviousKnot->KnotPos.X, KnotX);
			PreviousKnot->PinHandlesToConnectTo.Add(OtherPin);
		}
		// if the x position is close to the previous knot's x position, we should merge the knots
		else
			if (PreviousKnot.IsValid() && FMath::Abs(KnotX - PreviousKnot->KnotPos.X) < 50)
		{
			PreviousKnot->KnotPos.X = KnotX;
			PreviousKnot->PinHandlesToConnectTo.Add(OtherPin);
			// UE_LOG(LogTemp, Warning, TEXT("Merging knot nodes"));
		}
		else
		{
			// UE_LOG(LogTemp, Warning, TEXT("Making normal node"));
			const FVector2D KnotPos = FVector2D(KnotX, KnotTrack->GetTrackHeight());
			PreviousKnot = MakeShared<FKnotNodeCreation>(KnotPos, PreviousKnot, OtherPin);
			KnotTrack->KnotCreations.Add(PreviousKnot);

			if (OtherPin == LinkedPins.Last())
				PreviousKnot->PinHandlesToConnectTo.Add(KnotTrack->GetLastPin());
		}
	}
}

void FEdGraphFormatter::MergeNearbyKnotTracks()
{
	// UE_LOG(LogTemp, Warning, TEXT("Merging knot track"));
	
	TArray<TSharedPtr<FKnotNodeTrack>> PendingTracks = KnotTracks;

	if (GetMutableDefault<UBASettings>()->ExecutionWiringStyle != BAWiringStyle_MergeWhenNear)
	{
		PendingTracks.RemoveAll([](TSharedPtr<FKnotNodeTrack> Track)
		{
			return FBAUtils::IsExecPin(Track->ParentPin);
		});
	}

	if (GetMutableDefault<UBASettings>()->ParameterWiringStyle != BAWiringStyle_MergeWhenNear)
	{
		PendingTracks.RemoveAll([](TSharedPtr<FKnotNodeTrack> Track)
		{
			return FBAUtils::IsParameterPin(Track->ParentPin);
		});
	}

	// TODO: Handle merging of looping tracks
	PendingTracks.RemoveAll([](TSharedPtr<FKnotNodeTrack> Track)
	{
		return Track->bIsLoopingTrack;
	});

	while (PendingTracks.Num() > 0)
	{
		auto CurrentTrack = PendingTracks.Pop();
		auto Tracks = PendingTracks;

		for (TSharedPtr<FKnotNodeTrack> Track : Tracks)
		{
			// UE_LOG(LogTemp, Warning, TEXT("Merging track %s"), *FBAUtils::GetPinName(Track->ParentPin));
			
			// merge if they have the same parent and same height
			if (Track->ParentPin == CurrentTrack->ParentPin &&
				Track->GetTrackHeight() == CurrentTrack->GetTrackHeight())
			{
				for (TSharedPtr<FKnotNodeCreation> Creation : Track->KnotCreations)
				{
					bool bShouldAddCreation = true;
					for (TSharedPtr<FKnotNodeCreation> CurrentCreation : CurrentTrack->KnotCreations)
					{
						if (FMath::Abs(CurrentCreation->KnotPos.X - Creation->KnotPos.X) < 50)
						{
							bShouldAddCreation = false;
							CurrentCreation->PinHandlesToConnectTo.Append(Creation->PinHandlesToConnectTo);
						}
					}

					if (bShouldAddCreation)
					{
						CurrentTrack->KnotCreations.Add(Creation);
						CurrentTrack->PinToAlignTo = nullptr;

						// UE_LOG(LogTemp, Warning, TEXT("Cancelled pin to align to for track %s"), *FBAUtils::GetPinName(CurrentTrack->ParentPin));
					}
				}

				KnotTracks.Remove(Track);
				PendingTracks.Remove(Track);
			}
		}
	}
}
