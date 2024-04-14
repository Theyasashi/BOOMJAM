// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "SimpleFormatter.h"
#include "BlueprintAssistUtils.h"
#include "Containers/Queue.h"

FSimpleFormatter::FSimpleFormatter(TSharedPtr<FBAGraphHandler> InGraphHandler)
	: GraphHandler(InGraphHandler)
	, RootNode(nullptr)
{
	TrackSpacing = GetMutableDefault<UBASettings>()->BlueprintKnotTrackSpacing;
}

void FSimpleFormatter::FormatNode(UEdGraphNode* Node)
{
	RootNode = Node;
	
	FormatterSettings = GetFormatterSettings();

	int32 SavedNodePosX = RootNode->NodePosX;
	int32 SavedNodePosY = RootNode->NodePosY;

	CommentHandler.Init(GraphHandler);
	
	FormatX();
	FormatY();

	// reset root node position
	const float DeltaX = SavedNodePosX - RootNode->NodePosX;
	const float DeltaY = SavedNodePosY - RootNode->NodePosY;

	for (auto FormattedNode : FormattedNodes)
	{
		FormattedNode->NodePosX += DeltaX;
		FormattedNode->NodePosY += DeltaY;
	}
}

void FSimpleFormatter::FormatX()
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

	EEdGraphPinDirection LastDirection = FormatterDirection;

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

		FormattedNodes.Add(CurrentNode);
		
		// UE_LOG(LogTemp, Warning, TEXT("Processing %s | %s"), *FBAUtils::GetNodeName(CurrentNode), *CurrentInfo->Link.ToString());
		const int32 NewX = GetChildX(CurrentInfo->Link);

		if (!FormatXInfoMap.Contains(CurrentNode))
		{
			if (CurrentNode != RootNode)
			{
				CurrentInfo->SetParent(CurrentInfo->Parent);
				CurrentNode->NodePosX = NewX;

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

		TArray<UEdGraphPin*> LinkedPins = FBAUtils::GetLinkedPins(CurrentInfo->GetNode());

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

				if (FBAUtils::IsNodePure(LinkedNode))
					continue;

				// UE_LOG(LogTemp, Warning, TEXT("\t\t\tIterating pin link %s"), *PinLink.ToString());

				TSharedPtr<FFormatXInfo> LinkedInfo = MakeShareable(new FFormatXInfo(PinLink, CurrentInfo));

				if (ParentPin->Direction == FormatterDirection)
				{
					OutputStack.Push(LinkedInfo);
					// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tAdded to output stack"));
				}
				else
				{
					if (GetMutableDefault<UBASettings>()->FormattingStyle == BANodeFormatting_Expanded)
					{
						EEdGraphPinDirection OppositeDirection = UEdGraphPin::GetComplementaryDirection(FormatterDirection);
						
						
						if (CurrentInfo->Link.GetDirection() == FormatterDirection)
						{
							const bool bHasCycle = PendingNodes.Contains(LinkedNode) || FBAUtils::GetExecTree(LinkedNode, OppositeDirection).Contains(CurrentInfo->GetNode());
							
							if (!bHasCycle)
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
		ExpandPendingNodes();
	}
}

int32 FSimpleFormatter::GetChildX(const FPinLink& Link)
{
	if (Link.From == nullptr)
	{
		return GetRelativeNodeBounds(Link.GetNode(), nullptr).Left;
	}

	EEdGraphPinDirection Direction = Link.GetDirection();
	UEdGraphNode* Parent = Link.From->GetOwningNode();
	UEdGraphNode* Child = Link.To->GetOwningNode();
	FSlateRect ParentBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, Parent);


	TSet<UEdGraphNode*> RelativeNodes;
	auto RelativeBounds = GetRelativeNodeBounds(Parent, Child, RelativeNodes);
	// auto SameRowPtr = false;// SameRowMapping.Find(Link);
	// if (SameRowPtr != nullptr && *SameRowPtr)
	// {
	// 	// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tTaking Relative bounds %s | OLD %s"), *RelativeBounds.ToString(), *ParentBounds.ToString());
	// 	ParentBounds = RelativeBounds;
	// }
	// else
	{
		const auto NodesBounds = FBAUtils::GetCachedNodeArrayBounds(GraphHandler, RelativeNodes.Array());

		bool bIsSame = Link.GetDirection() == EGPD_Output ? NodesBounds.Right == ParentBounds.Right : NodesBounds.Left == ParentBounds.Left;

		if (bIsSame)
		{
			// UE_LOG(LogTemp, Warning, TEXT("\t\t\t\t\tTaking Relative bounds %s | OLD %s"), *RelativeBounds.ToString(), *ParentBounds.ToString());
			ParentBounds = RelativeBounds;
		}
	}

	// if (Direction == EGPD_Output)
	// {
	// 	return ParentBounds.Right + Padding.X;
	// }

	FSlateRect ChildBounds = FBAUtils::GetCachedNodeBounds(GraphHandler, Child);

	FSlateRect LargerBounds = GetRelativeNodeBounds(Child, Parent);

	float NewNodePos;
	if (Link.From->Direction == EGPD_Input)
	{
		const float Delta = LargerBounds.Right - ChildBounds.Left;
		NewNodePos = ParentBounds.Left - Delta - FormatterSettings.Padding.X;// -1;
	}
	else
	{
		const float Delta = ChildBounds.Left - LargerBounds.Left;
		NewNodePos = ParentBounds.Right + Delta + FormatterSettings.Padding.X;// +1;
	}

	return FMath::RoundToInt(NewNodePos);
	// return ParentBounds.Left - Padding.X - ChildBounds.GetSize().X;
}

FSlateRect FSimpleFormatter::GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking)
{
	TSet<UEdGraphNode*> Unused;
	return GetRelativeNodeBounds(Node, NodeAsking, Unused);
}

FSlateRect FSimpleFormatter::GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes)
{
	return CommentHandler.GetRelativeNodeBounds(Node, NodeAsking, RelativeNodes);
}

FSlateRect FSimpleFormatter::GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking)
{
	TSet<UEdGraphNode*> Unused;
	return GetRelativeBoundsForNodes(Nodes, NodeAsking, Unused);
}

FSlateRect FSimpleFormatter::GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes)
{
	TArray<FSlateRect> AllBounds;

	for (UEdGraphNode* Node : Nodes)
	{
		AllBounds.Add(GetRelativeNodeBounds(Node, NodeAsking, RelativeNodes));
	}

	return FBAUtils::GetGroupedBounds(AllBounds);
}

void FSimpleFormatter::ExpandPendingNodes()
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

		auto OppositeDirection = UEdGraphPin::GetComplementaryDirection(FormatterDirection);
		TArray<UEdGraphNode*> Children = Info->GetChildren(OppositeDirection);


		// UE_LOG(LogTemp, Warning, TEXT("Expand X %s | %s"), *FBAUtils::GetNodeName(Info->GetNode()), *FBAUtils::GetNodeName(Parent));

		if (Children.Num() > 0)
		{
			FSlateRect ChildrenBounds = GetRelativeBoundsForNodes(Children, Parent);

			FSlateRect ParentBounds = GetRelativeNodeBounds(Parent, Node);

			bool bShouldExpand = FormatterDirection == EGPD_Output
				? ParentBounds.Right > ChildrenBounds.Left
				: ChildrenBounds.Right > ParentBounds.Left;
			
			if (bShouldExpand)
			{
				const float Delta = FormatterDirection == EGPD_Output
					? ParentBounds.Right - ChildrenBounds.Left + FormatterSettings.Padding.X
					: ParentBounds.Left - ChildrenBounds.Right - FormatterSettings.Padding.X;

				// UE_LOG(LogTemp, Warning, TEXT("Expanding node %s by %f"), *FBAUtils::GetNodeName(Node), Delta);

				Node->NodePosX += Delta;

				TArray<UEdGraphNode*> AllChildren = Info->GetChildren();
				for (UEdGraphNode* Child : AllChildren)
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tChild %s"), *FBAUtils::GetNodeName(Child));
					Child->NodePosX += Delta;
				}
			}
		}
	}
}

void FSimpleFormatter::FormatY()
{
	// UE_LOG(LogTemp, Warning, TEXT("Format y?!?!?"));
	
	TSet<UEdGraphNode*> NodesToCollisionCheck;
	TSet<FPinLink> VisitedLinks;
	TSet<UEdGraphNode*> TempChildren;
	FormatY_Recursive(RootNode, nullptr, nullptr, NodesToCollisionCheck, VisitedLinks, true, TempChildren);
}

void FSimpleFormatter::FormatY_Recursive(
	UEdGraphNode* CurrentNode, 
	UEdGraphPin* CurrentPin, 
	UEdGraphPin* ParentPin, 
	TSet<UEdGraphNode*>& NodesToCollisionCheck, 
	TSet<FPinLink>& VisitedLinks, 
	bool bSameRow, 
	TSet<UEdGraphNode*>& Children)
{
// 	const FString NodeNameA = CurrentNode == nullptr
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

			FSlateRect MyBounds = GetRelativeNodeBounds(CurrentNode, NodeToCollisionCheck, NodesToMove);
			const FMargin CollisionPadding(0, 0, FormatterSettings.Padding.X * 0.75f, FormatterSettings.Padding.Y);

			FSlateRect OtherBounds = GetRelativeNodeBounds(NodeToCollisionCheck, CurrentNode);

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

	const EEdGraphPinDirection Direction = ParentPin == nullptr ? EGPD_Input : ParentPin->Direction.GetValue();

	// UE_LOG(LogTemp, Warning, TEXT("Pin Direction: %d"), Direction);

	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, Direction));
	OutputInput.Add(FBAUtils::GetLinkedPins(CurrentNode, UEdGraphPin::GetComplementaryDirection(Direction)));

	bool bFirstPin = true;

	UEdGraphPin* MainPin = CurrentPin;

	auto& GraphHandlerCapture = GraphHandler;

	for (TArray<UEdGraphPin*>& Pins : OutputInput)
	{
		UEdGraphPin* LastLinked = CurrentPin;
		UEdGraphPin* LastProcessed = nullptr;

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
					// || !NodePool.Contains(OtherNode)
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
						FSlateRect Bounds = GetRelativeBoundsForNodes(LocalChildren.Array(), CurrentNode, NodesToMove);
						
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
	}

	Children.Add(CurrentNode);

	if (bSameRow && ParentPin != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("\t\t\tStraightening pin from %s to %s"),
		//       *FBAUtils::GetPinName(CurrentPin),
		//       *FBAUtils::GetPinName(ParentPin));

		FBAUtils::StraightenPin(GraphHandler, CurrentPin, ParentPin);
	}
}

TSet<UEdGraphNode*> FSimpleFormatter::GetFormattedNodes()
{
	return FormattedNodes;
}