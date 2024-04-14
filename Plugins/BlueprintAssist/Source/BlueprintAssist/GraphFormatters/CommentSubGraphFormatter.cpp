// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "CommentSubGraphFormatter.h"

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

FCommentSubGraphFormatter::FCommentSubGraphFormatter(
	TSharedPtr<FBAGraphHandler> InGraphHandler,
	FCommentSubGraphFormatterParameters InFormatterParameters,
	TSharedPtr<FEdGraphFormatter> InParentFormatter)
	: GraphHandler(InGraphHandler)
	, RootNode(nullptr)
	, FormatterParameters(InFormatterParameters)
	, ParentFormatter(InParentFormatter)
{
	NodePadding = GetMutableDefault<UBASettings>()->BlueprintFormatterSettings.Padding;
	PinPadding = GetMutableDefault<UBASettings>()->BlueprintParameterPadding;
	TrackSpacing = GetMutableDefault<UBASettings>()->BlueprintKnotTrackSpacing;
	bHasBeenFormatted = false;
	bAccountForComments = false;
}

void FCommentSubGraphFormatter::FormatNode(UEdGraphNode* InitialNode)
{
	if (!IsInitialNodeValid(InitialNode))
	{
		return;
	}

	bHasBeenFormatted = true;

	RootNode = InitialNode;

	const FSlateRect SavedBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, RootNode);

	TArray<UEdGraphNode*> NewNodeTree = GetNodeTree(InitialNode);
	
	NodeTree = NewNodeTree;

	NodePool.Reset();
	MainParameterFormatter.Reset();
	ParameterFormatterMap.Reset();
	FormatXInfoMap.Reset();
	Path.Reset();
	SameRowMapping.Reset();

	// initialize the node pool from the root node
	InitNodePool();

	InitCommentNodeInfo();

	if (FBAUtils::IsNodePure(RootNode))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Root node is impure: Using format pure nodes"));
		MainParameterFormatter = MakeShareable(new FEdGraphParameterFormatter(GraphHandler, RootNode, ParentFormatter));
		MainParameterFormatter->FormatNode(RootNode);
		return;
	}

	/** Init the node info map */
	for (UEdGraphNode* Node : NodePool)
	{
		Node->Modify();
	}

	GetPinsOfSameHeight();

	FormatComments();
	
	bAccountForComments = false;
	FormatX(false);

	/** Format the input nodes before we format the X position so we can get the column bounds */
	bAccountForComments = GetDefault<UBASettings>()->bAccountForCommentsWhenFormatting;

	Path.Empty();
	FormatXInfoMap.Empty();
	FormatX(true);

	/** Format Y (Rows) */
	FormatY();

	if (GetMutableDefault<UBASettings>()->bExpandNodesByHeight)
	{
		ExpandBasedOnHeight();
	}

	/** Formatting may move nodes, move all nodes back using the root as a baseline */
	ResetRelativeToNodeToKeepStill(SavedBounds);

	// Check if formatting is required checks the difference between the node trees, so we must set it here
	NodeTree = GetNodeTree(InitialNode);
}

void FCommentSubGraphFormatter::InitNodePool()
{
	NodePool.Empty();
	TArray<UEdGraphNode*> InputNodeStack;
	TArray<UEdGraphNode*> OutputNodeStack;
	OutputNodeStack.Push(RootNode);

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

					if (Dir == EGPD_Output)
						OutputNodeStack.Push(LinkedNode);
					else
						InputNodeStack.Push(LinkedNode);
				}
			}
		}
	}
}

void FCommentSubGraphFormatter::ExpandPendingNodes(bool bUseParameter)
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
				? ParentFormatter->GetClusterBounds(Parent)
				: FBAUtils::GetCachedNodeBounds(GraphHandler, Parent);

			if (bAccountForComments)
			{
				InputBounds = ParentFormatter->GetRelativeBoundsForNodes(InputChildren, Parent, bUseParameter);
				// TODO Probably need this but who are we relative to?
				ParentBounds = ParentFormatter->GetRelativeNodeBounds(Parent, Node, bUseParameter);
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

void FCommentSubGraphFormatter::FormatX(const bool bUseParameter)
{
	TSet<UEdGraphNode*> VisitedNodes;
	TSet<UEdGraphNode*> PendingNodes;
	PendingNodes.Add(RootNode);
	TSet<FPinLink> VisitedLinks;
	const FPinLink RootNodeLink(nullptr, nullptr, RootNode);
	TSharedPtr<FFormatXInfo> RootInfo = MakeShareable(new FFormatXInfo(RootNodeLink, nullptr));

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
		const int32 NewX = ParentFormatter->GetChildX(CurrentInfo->Link, bUseParameter);

		if (!FormatXInfoMap.Contains(CurrentNode))
		{
			if (CurrentNode != RootNode)
			{
				CurrentInfo->SetParent(CurrentInfo->Parent);
				CurrentNode->NodePosX = NewX;

				if (SubGraphFormatters.Contains(CurrentNode))
				{
					SubGraphFormatters[CurrentNode]->FormatNode(CurrentNode);
				}
				
				if (bUseParameter)
				{
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
				if (VisitedLinks.Contains(PinLink))
					continue;
				
				VisitedLinks.Add(PinLink);
				if (!NodePool.Contains(LinkedNode))
					continue;

				if (FBAUtils::IsNodePure(LinkedNode))
					continue;

				// UE_LOG(LogTemp, Warning, TEXT("\t\t\tIterating pin link %s"), *PinLink.ToString());

				TSharedPtr<FFormatXInfo> LinkedInfo = MakeShareable(new FFormatXInfo(PinLink, CurrentInfo));

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

void FCommentSubGraphFormatter::ExpandBasedOnHeight()
{
	for (UEdGraphNode* Node : NodePool)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Expanding node %s"), *FBAUtils::GetNodeName(Node));

		FSlateRect NodeBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, Node);

		TSet<UEdGraphNode*> InputTree = FBAUtils::GetExecTree(Node, EGPD_Input);

		for (EEdGraphPinDirection Direction : {EGPD_Input, EGPD_Output})
		{
			const TArray<FPinLink> PinLinks = FBAUtils::GetPinLinks(Node, Direction);

			float LargestPinDelta = 0;
			for (const FPinLink& Link : PinLinks)
			{
				const float PinDelta = FBAUtils::GetPinPos(GraphHandler, Link.To).Y - FBAUtils::GetPinPos(GraphHandler, Link.From).Y;
				LargestPinDelta = FMath::Max(PinDelta, LargestPinDelta);
			}

			if (LargestPinDelta < 150)
				continue;

			auto& GraphHandlerCapture = GraphHandler;
			auto& FormatterParamCapture = FormatterParameters;
			const auto GreaterX = [GraphHandlerCapture, NodeBounds, FormatterParamCapture](UEdGraphNode* NodeToFilter)
			{
				if (!FormatterParamCapture.NodesToFormat.Contains(NodeToFilter))
					return false;
				
				const FSlateRect NodeToFilterBounds = FBAUtils::GetCachedNodeBounds(GraphHandlerCapture, NodeToFilter);
				return NodeToFilterBounds.Left > NodeBounds.Right;
			};

			TArray<UEdGraphNode*> NodesToMove = FBAUtils::GetExecutionTreeWithFilter(Node, GreaterX, EGPD_Output, true).Array();
			const float ExpandX = FMath::Min(LargestPinDelta * 0.15f, 350.f);

			for (UEdGraphNode* Child : NodesToMove)
			{
				// if we are expanding the output children, we don't want to move ourselves
				if (Direction == EGPD_Output && Node == Child)
					continue;

				//UE_LOG(LogTemp, Warning, TEXT("\tExpanded node %s (%s) %d"), *FBAUtils::GetNodeName(Child), *FBAUtils::GetNodeName(Node), Direction);

				Child->NodePosX += ExpandX;
				RefreshParameters(Child);
			}
		}
	}
}

void FCommentSubGraphFormatter::InitCommentNodeInfo()
{
	ParentComments.Empty();
	CommentNodesContains.Reset();

	TArray<UEdGraphNode_Comment*> CommentNodes = FBAUtils::GetCommentNodesFromGraph(GraphHandler->GetFocusedEdGraph());

	CommentNodes.Sort([](UEdGraphNode_Comment& NodeA, UEdGraphNode_Comment& NodeB)
	{
		return NodeA.CommentDepth > NodeB.CommentDepth;
	});

	auto FormattedNodes = GetFormattedGraphNodes();
	for (UEdGraphNode_Comment* Comment : CommentNodes)
	{
		TArray<UEdGraphNode*> NodesUnderComment = FBAUtils::GetNodesUnderComment(Comment);
		
		for (UEdGraphNode* EdGraphNode : NodesUnderComment)
		{
			if (NodeTree.Contains(EdGraphNode))
			{
				CommentNodesContains.FindOrAdd(Comment).Add(EdGraphNode);

				// TODO: Do node tree check to see if all nodes inside the comment box are connected
				ParentComments.FindOrAdd(EdGraphNode).Add(Comment);

				//UE_LOG(LogTemp, Warning, TEXT("Comments: Added Node %s to comment %d"), *FBAUtils::GetNodeName(EdGraphNode), Comment);
			}
		}
	}
}

void FCommentSubGraphFormatter::FormatY_Recursive(
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

			TSet<UEdGraphNode*> NodesToMove;

			FSlateRect MyBounds = bAccountForComments ? ParentFormatter->GetRelativeNodeBounds(CurrentNode, NodeToCollisionCheck, NodesToMove, true) : ParentFormatter->GetClusterBounds(CurrentNode);
			const FMargin CollisionPadding(0, 0, NodePadding.X * 0.33f, NodePadding.Y);

			FSlateRect OtherBounds = bAccountForComments ? ParentFormatter->GetRelativeNodeBounds(NodeToCollisionCheck, CurrentNode, true) : ParentFormatter->GetClusterBounds(NodeToCollisionCheck);

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

	TArray<TArray<UEdGraphPin*>> OutputInput;

	const EEdGraphPinDirection Direction = ParentPin == nullptr ? EGPD_Output : ParentPin->Direction.GetValue();

	// UE_LOG(LogTemp, Warning, TEXT("Pin Direction: %d"), Direction);

	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, Direction).FilterByPredicate(IsExecOrDelegatePin));
	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, UEdGraphPin::GetComplementaryDirection(Direction)).FilterByPredicate(IsExecOrDelegatePin));

	bool bFirstPin = true;

	UEdGraphPin* MainPin = CurrentPin;

	auto& GraphHandlerCapture = GraphHandler;

	for (TArray<UEdGraphPin*>& Pins : OutputInput)
	{
		UEdGraphPin* LastLinked = CurrentPin;
		UEdGraphPin* LastProcessed = nullptr;

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

				RefreshParameters(OtherNode);

				TSet<UEdGraphNode*> LocalChildren;
				FormatY_Recursive(OtherNode, OtherPin, MyPin, NodesToCollisionCheck, VisitedLinks, bChildIsSameRow, LocalChildren);
				Children.Append(LocalChildren);

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
						FSlateRect Bounds = bAccountForComments ? ParentFormatter->GetRelativeBoundsForNodes(LocalChildren.Array(), CurrentNode, NodesToMove, true) : FBAUtils::GetCachedNodeArrayBounds(GraphHandler, LocalChildren.Array());

						//UE_LOG(LogTemp, Warning, TEXT("\t\t\tPin to avoid %s (%s)"), *FBAUtils::GetPinName(PinToAvoid), *FBAUtils::GetPinName(OtherPin));
						const float PinPos = GraphHandler->GetPinY(PinToAvoid) + TrackSpacing;
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
		}
	}

	Children.Add(CurrentNode);

	if (bSameRow && ParentPin != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("\t\t\tStraightening pin from %s to %s"),
		//       *FBAUtils::GetPinName(CurrentPin),
		//       *FBAUtils::GetPinName(ParentPin));

		FBAUtils::StraightenPin(GraphHandler, CurrentPin, ParentPin);
		RefreshParameters(ParentPin->GetOwningNode());
	}
}

void FCommentSubGraphFormatter::GetPinsOfSameHeight_Recursive(
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

void FCommentSubGraphFormatter::ResetRelativeToNodeToKeepStill(const FSlateRect& SavedBounds)
{
	const FSlateRect NodeToKeepStillBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, RootNode);
	const float DeltaX = SavedBounds.Left - NodeToKeepStillBounds.Left;
	const float DeltaY = SavedBounds.Top - NodeToKeepStillBounds.Top;

	if (DeltaX != 0 || DeltaY != 0)
	{
		TSet<UEdGraphNode*> AllNodes = GetFormattedGraphNodes();
		for (UEdGraphNode* Node : AllNodes)
		{
			Node->NodePosX += DeltaX;
			Node->NodePosY += DeltaY;
		}
	}
}

void FCommentSubGraphFormatter::FormatComments()
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
				
				FCommentSubGraphFormatterParameters CommentFormatterParameters = FormatterParameters;
				CommentFormatterParameters.bIsCommentFormatter = true;
				CommentFormatterParameters.NodesToFormat = CommentNodesContains[Comment];

				if (FBAUtils::DoesArrayContainsAllItems(CommentFormatterParameters.NodesToFormat, NodeTree))
				{
					continue;
				}
				
				TSharedPtr<FCommentSubGraphFormatter> CommentFormatter = MakeShareable(new FCommentSubGraphFormatter(GraphHandler, CommentFormatterParameters, ParentFormatter));
				SubGraphFormatters.Add(CurrentNode, CommentFormatter);
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

bool FCommentSubGraphFormatter::IsExecOrDelegatePin(UEdGraphPin* Pin)
{
	const bool bUseDelegatePins = GetMutableDefault<UBASettings>()->bTreatDelegatesAsExecutionPins && FBAUtils::IsDelegatePin(Pin);
	return FBAUtils::IsExecPin(Pin) || bUseDelegatePins;
}

void FCommentSubGraphFormatter::GetPinsOfSameHeight()
{
	TSet<UEdGraphNode*> NodesToCollisionCheck;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> TempChildren;
	GetPinsOfSameHeight_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks);
}

TSet<UEdGraphNode*> FCommentSubGraphFormatter::GetFormattedGraphNodes()
{
	TSet<UEdGraphNode*> OutNodes;
	for (UEdGraphNode* Node : NodePool)
		OutNodes.Append(GetParameterFormatter(Node)->GetFormattedNodes());

	return OutNodes;
}

void FCommentSubGraphFormatter::RefreshParameters(UEdGraphNode* Node)
{
	ParentFormatter->RefreshParameters(Node);
}

TArray<UEdGraphNode*> FCommentSubGraphFormatter::GetNodeTree(UEdGraphNode* InitialNode) const
{
	const auto& GraphHandlerCapture = GraphHandler;
	const auto& FormatterParametersCapture = FormatterParameters;
	const auto Filter = [&GraphHandlerCapture, &FormatterParametersCapture](const FPinLink& Link)
	{
		return GraphHandlerCapture->FilterDelegatePin(Link, FormatterParametersCapture.NodesToFormat);
	};
	return FBAUtils::GetNodeTreeWithFilter(InitialNode, Filter).Array();
}

bool FCommentSubGraphFormatter::IsInitialNodeValid(UEdGraphNode* Node) const
{
	if (!Node)
		return false;
	if (Cast<UEdGraphNode_Comment>(Node))
		return false;
	if (Cast<UK2Node_Knot>(Node))
		return false;

	return true;
}

FSlateRect FCommentSubGraphFormatter::GetClusterBoundsForNodes(const TArray<UEdGraphNode*>& Nodes)
{
	return ParentFormatter->GetClusterBoundsForNodes(Nodes);
}

TSharedPtr<FEdGraphParameterFormatter> FCommentSubGraphFormatter::GetParameterFormatter(UEdGraphNode* Node)
{
	return ParentFormatter->GetParameterFormatter(Node);
}

TSet<UEdGraphNode*> FCommentSubGraphFormatter::GetFormattedNodes()
{
	if (MainParameterFormatter.IsValid())
	{
		return MainParameterFormatter->GetFormattedNodes();
	}
	
	TSet<UEdGraphNode*> OutNodes;
	for (UEdGraphNode* Node : NodePool)
		OutNodes.Append(GetParameterFormatter(Node)->GetFormattedNodes());

	return OutNodes;
}

void FCommentSubGraphFormatter::FormatY()
{
	bAccountForComments = false;
	TSet<UEdGraphNode*> NodesToCollisionCheck;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> TempChildren;
	FormatY_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks, true, TempChildren);

	bAccountForComments = true;
	NodesToCollisionCheck.Reset();
	VisitedLinks.Reset();
	TempChildren.Reset();
	FormatY_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks, true, TempChildren);
}

bool FCommentSubGraphFormatter::AnyCollisionBetweenPins(UEdGraphPin* Pin, UEdGraphPin* OtherPin)
{
	TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();

	const FVector2D PinPos = FBAUtils::GetPinPos(GraphHandler, Pin);
	const FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, OtherPin);

	return NodeCollisionBetweenLocation(PinPos, OtherPinPos, {Pin->GetOwningNode(), OtherPin->GetOwningNode()});
}

bool FCommentSubGraphFormatter::NodeCollisionBetweenLocation(FVector2D Start, FVector2D End, TSet<UEdGraphNode*> IgnoredNodes)
{
	TSet<UEdGraphNode*> FormattedNodes = GetFormattedGraphNodes();

	for (UEdGraphNode* NodeToCollisionCheck : FormattedNodes)
	{
		if (IgnoredNodes.Contains(NodeToCollisionCheck))
			continue;

		FSlateRect NodeBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, NodeToCollisionCheck).ExtendBy(FMargin(0, TrackSpacing * 0.5f));
		if (FBAUtils::LineRectIntersection(NodeBounds, Start, End))
			return true;
	}

	return false;
}