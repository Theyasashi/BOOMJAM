// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintAssistSettings.h"
#include "BlueprintAssistInputProcessor.h"
#include "BlueprintAssistModule.h"
#include "BlueprintAssistSizeCache.h"
#include "BlueprintEditor.h"

#include "../GraphFormatters/EdGraphFormatter.h"
#include "../GraphFormatters/BehaviorTreeGraphFormatter.h"
#include "../GraphFormatters/AnimationGraphFormatter.h"
#include "../GraphFormatters/MaterialGraphFormatter.h"
#include "../GraphFormatters/SoundCueGraphFormatter.h"

#include "SGraphPanel.h"
#include "SCommentBubble.h"
#include "ScopedTransaction.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Framework/Notifications/NotificationManager.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/Docking/SDockTab.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_ComponentBoundEvent.h"
#include "K2Node_ActorBoundEvent.h"
#include "EdGraphNode_Comment.h"
#include "Editor.h"
#include "Editor/BlueprintGraph/Classes/K2Node_Knot.h"
#include "BlueprintAssist/GraphFormatters/NiagaraGraphFormatter.h"
#include "Editor/EditorEngine.h"
// #include "Subsystems/AssetEditorSubsystem.h"

#if ENGINE_MINOR_VERSION >= 22
#include "Misc/AsyncTaskNotification.h"
#endif

FBAGraphHandler::FBAGraphHandler(
	TWeakPtr<SDockTab> InTab,
	TWeakPtr<SGraphEditor> InGraphEditor)
	: CachedGraphEditor(InGraphEditor)
	, CachedTab(InTab)
{
	check(GetGraphEditor().IsValid());
	check(GetFocusedEdGraph() != nullptr);
	check(GetGraphPanel().IsValid());
	check(GetTab().IsValid());

	TSharedPtr<SWidget> WindowWidget = FBAUtils::GetParentWidgetOfType(InTab.Pin(), "SWindow");
	if (WindowWidget.IsValid())
	{
		CachedWindow = StaticCastSharedPtr<SWindow>(WindowWidget);
	}

	InitGraphHandler();
}

FBAGraphHandler::~FBAGraphHandler()
{
	FormatterMap.Empty();
	SelectedPinHandle = nullptr;
	FocusedNode = nullptr;
	LastSelectedNode = nullptr;
	ResetTransactions();
}

void FBAGraphHandler::InitGraphHandler()
{
	NewNodeForFormatting = nullptr;
	Delay_ResetReplaceNode = -1;
	Delay_InitialCache = 2;
	bInitialZoomFinished = false;
	NodeSizeTimeout = 0.f;
	TicksOnFocusedNode = 0;
	Delay_ViewportZoomIn = 0;
	FocusedNode = nullptr;
	bFullyZoomed = false;
	LastSelectedNode = nullptr;
	bLerpViewport = false;
	bCenterWhileLerping = false;
	
	SetSelectedPin(nullptr);

	FormatterParameters.Reset();
	NodesCreatedThisFrame.Reset();
	NodesCreatedLastFrame.Reset();
	PendingFormatting.Reset();
	PendingSize.Reset();
	SeenNodes.Reset();
	CommentBubbleSizeCache.Reset();
	FormatAllColumns.Reset();
	FormatterMap.Reset();
	
	PendingTransaction.Reset();
	ReplaceNewNodeTransaction.Reset();
	FormatAllTransaction.Reset();

#if ENGINE_MINOR_VERSION >= 22
	if (CachingSizeNotification.IsValid())
	{
		CachingSizeNotification->SetComplete();
	}
	
	if (SizeTimeoutNotification.IsValid())
	{
		SizeTimeoutNotification->SetComplete();
	}
#endif
	
	GetGraphCache().CleanupGraph(GetFocusedEdGraph());

	GetGraphEditor()->GetViewLocation(LastGraphView, LastZoom);
}

void FBAGraphHandler::Cleanup()
{
	FormatterParameters.Reset();
	ResetTransactions();
	FormatterMap.Reset();

#if ENGINE_MINOR_VERSION >= 22
	if (CachingSizeNotification.IsValid())
	{
		CachingSizeNotification->SetComplete();
	}

	if (SizeTimeoutNotification.IsValid())
	{
		SizeTimeoutNotification->SetComplete();
	}
#endif
}

void FBAGraphHandler::OnSelectionChanged(UEdGraphNode* PreviousNode, UEdGraphNode* NewNode)
{
	if (NewNode == nullptr)
	{
		SetSelectedPin(nullptr);
		return;
	}

	if (FBAUtils::IsCommentNode(NewNode) || FBAUtils::IsKnotNode(NewNode))
	{
		SetSelectedPin(nullptr);
		return;
	}

	TArray<UEdGraphPin*> Pins = FBAUtils::GetPinsByDirection(NewNode);
	UEdGraphPin* SelectedPin = GetSelectedPin();

	const bool bKeepCurrentPin = SelectedPin != nullptr && SelectedPin->GetOwningNode() == NewNode;
	if (bKeepCurrentPin)
	{
		return;
	}

	if (Pins.Num() > 0)
	{
		const auto& Sorter = [](const UEdGraphPin& PinA, const UEdGraphPin& PinB)
		{
			const int32 PinAExec = PinA.PinType.PinCategory == UEdGraphSchema_K2::PC_Exec;
			const int32 PinBExec = PinB.PinType.PinCategory == UEdGraphSchema_K2::PC_Exec;

			if (PinAExec != PinBExec)
				return PinAExec > PinBExec;

			return PinA.Direction > PinB.Direction;
		};

		Pins.StableSort(Sorter);

		SetSelectedPin(Pins[0]);
	}
	else
	{
		SetSelectedPin(nullptr);
	}
}

void FBAGraphHandler::ProcessNodesCreatedLastFrame()
{
	// TODO: this logic has only been tested for blueprint graphs, needs testing for other graphs
	if (!FBAUtils::IsBlueprintGraph(GetFocusedEdGraph()))
	{
		return;
	}

	if (NodesCreatedLastFrame.Num() != 1)
	{
		return;
	}

	UEdGraphNode* SingleNewNode = NodesCreatedLastFrame[0];
	
	if (FBAUtils::IsNodeImpure(SingleNewNode))
	{
		ProcessNewImpureNode(SingleNewNode);
	}
	else if (FBAUtils::IsNodePure(SingleNewNode))
	{
		ProcessNewPureNode(SingleNewNode);
	}
	
	ProcessNewNode(SingleNewNode);
}

void FBAGraphHandler::ProcessNewImpureNode(UEdGraphNode* NodeCreated)
{
	TArray<UEdGraphPin*> LinkedPins = FBAUtils::GetLinkedPins(NodeCreated);

	// if we drag off a parameter pin, link the exec pin too (if it exists)
	const auto IsPinOwningNodeImpure = [](UEdGraphPin* Pin)
	{
		return FBAUtils::IsNodeImpure(Pin->GetOwningNode());
	};

	const auto IsLinkedToImpureNode = [IsPinOwningNodeImpure](UEdGraphPin* Pin)
	{
		// skip delegate pins
		return !FBAUtils::IsDelegatePin(Pin) && Pin->LinkedTo.FilterByPredicate(IsPinOwningNodeImpure).Num() > 0;
	};

	TArray<UEdGraphPin*> PinsLinkedToImpureNodes = LinkedPins.FilterByPredicate(IsLinkedToImpureNode);

	if (PinsLinkedToImpureNodes.Num() == 1)
	{
		UEdGraphPin* MyLinkedPin = PinsLinkedToImpureNodes[0];
		if (MyLinkedPin->LinkedTo.Num() == 1)
		{
			UEdGraphPin* OtherLinkedPin = MyLinkedPin->LinkedTo[0];

			if (OtherLinkedPin != nullptr)
			{
				UEdGraphNode* OtherLinkedNode = OtherLinkedPin->GetOwningNode();

				if (FBAUtils::IsNodeImpure(OtherLinkedNode))
				{
					TArray<UEdGraphPin*> ExecPins = FBAUtils::GetExecPins(NodeCreated, MyLinkedPin->Direction);

					if (ExecPins.FilterByPredicate(FBAUtils::IsPinLinked).Num() == 0)
					{
						TArray<UEdGraphPin*> OtherExecPins = FBAUtils::GetExecPins(OtherLinkedNode, UEdGraphPin::GetComplementaryDirection(MyLinkedPin->Direction));

						UEdGraphPin* OtherExecPin = OtherExecPins[0];
						if (OtherExecPin->LinkedTo.Num() > 0)
						{
							TArray<UEdGraphPin*> MyPinsInDirection = FBAUtils::GetExecPins(NodeCreated, OtherExecPin->Direction);
							if (MyPinsInDirection.Num() > 0)
							{
								FBAUtils::TryCreateConnection(OtherExecPin->LinkedTo[0], MyPinsInDirection[0]);
							}
						}

						FBAUtils::TryCreateConnection(ExecPins[0], OtherExecPin);
						return;
					}
				}
			}
		}
	}

	// if we drag off an exec pin in the input direction creating node C in a chain say A->B
	// this code makes it so we create A->C->B (by default it create A->B | C<-B)
	TArray<UEdGraphPin*> LinkedToPins = FBAUtils::GetLinkedToPins(NodeCreated);
	if (LinkedToPins.FilterByPredicate(FBAUtils::IsExecPin).Num() == 1)
	{
		UEdGraphPin* PinOnB = LinkedToPins[0];
		if (PinOnB->Direction == EGPD_Output)
			return;

		TArray<UEdGraphPin*> NodeCreatedOutputExecPins = FBAUtils::GetExecPins(NodeCreated, EGPD_Input);
		if (NodeCreatedOutputExecPins.Num() > 0)
		{
			if (PinOnB->LinkedTo.Num() > 1)
			{
				UEdGraphPin* ExecPinOnA = nullptr;

				for (UEdGraphPin* Pin : PinOnB->LinkedTo)
				{
					if (Pin->GetOwningNode() != NodeCreated)
					{
						ExecPinOnA = Pin;
					}
				}

				if (ExecPinOnA != nullptr)
				{
					FBAUtils::TryCreateConnection(ExecPinOnA, NodeCreatedOutputExecPins[0]);
				}
			}
		}
	}
}

void FBAGraphHandler::ProcessNewPureNode(UEdGraphNode* NodeCreated)
{
	// if we drag off a pin creating node C in a chain A->B
	// this code makes it so we create A->C->B (by default it create A->B | A->C)
	TArray<UEdGraphPin*> LinkedParameterPins = FBAUtils::GetLinkedPins(NodeCreated).FilterByPredicate(FBAUtils::IsParameterPin);

	if (LinkedParameterPins.Num() > 0)
	{
		UEdGraphPin* MyLinkedPin = LinkedParameterPins[0];
		UEdGraphPin* OtherLinkedPin = MyLinkedPin->LinkedTo[0];

		UEdGraphPin* PinToLinkTo = nullptr;
		for (UEdGraphPin* Pin : OtherLinkedPin->LinkedTo)
		{
			if (Pin != MyLinkedPin)
			{
				PinToLinkTo = Pin;
				break;
			}
		}

		if (PinToLinkTo != nullptr)
		{
			// try to link one of our pins to the pin to link to
			for (UEdGraphPin* Pin : FBAUtils::GetParameterPins(
				     NodeCreated,
				     OtherLinkedPin->Direction))
			{
				if (Pin->PinType == PinToLinkTo->PinType)
				{
					bool bConnected = FBAUtils::TryCreateConnection(Pin, PinToLinkTo);
					if (bConnected)
						return;
				}
			}
		}
	}
}

void FBAGraphHandler::ProcessNewNode(UEdGraphNode* NewNode)
{	
	// add to existing comment
	auto SelectedNodeCapture = LastSelectedNode;
	const auto IsSelectedNode = [SelectedNodeCapture](UEdGraphNode* LinkedNode) {return LinkedNode == SelectedNodeCapture; };
	auto LinkedInput = FBAUtils::GetLinkedNodes(NewNode, EGPD_Input).FilterByPredicate(IsSelectedNode);
	auto LinkedOutput = FBAUtils::GetLinkedNodes(NewNode, EGPD_Output).FilterByPredicate(IsSelectedNode);

	struct FLocal
	{
		static void TakeCommentNode(UEdGraph* Graph, UEdGraphNode* Node, UEdGraphNode* NodeToTakeFrom)
		{
			auto CommentNodes = FBAUtils::GetCommentNodesFromGraph(Graph);
			auto ContainingComments = FBAUtils::GetContainingCommentNodes(CommentNodes, NodeToTakeFrom);
			for (UEdGraphNode_Comment* CommentNode : ContainingComments)
			{
				CommentNode->AddNodeUnderComment(Node);
			}
		};
	};

	const auto AutoInsertStyle = GetDefault<UBASettings>()->AutoInsertComment;
	if (AutoInsertStyle == BAAutoInsertComment_Surrounded)
	{
		if (LinkedInput.Num() == 1 && LinkedOutput.Num() == 1)
		{
			const auto CommentNodes = FBAUtils::GetCommentNodesFromGraph(GetFocusedEdGraph());
			auto ContainingCommentsA = FBAUtils::GetContainingCommentNodes(CommentNodes, LinkedOutput[0]);
			auto ContainingCommentsB = FBAUtils::GetContainingCommentNodes(CommentNodes, LinkedInput[0]);

			ContainingCommentsA.RemoveAll([&ContainingCommentsB](UEdGraphNode_Comment* Comment)
			{
				return !ContainingCommentsB.Contains(Comment);
			});

			if (ContainingCommentsA.Num() > 0)
			{
				FLocal::TakeCommentNode(GetFocusedEdGraph(), NewNode, ContainingCommentsA[0]);
			}
		}
	}
	else if (AutoInsertStyle == BAAutoInsertComment_Always)
	{
		if (LinkedOutput.Num() == 1)
		{
			FLocal::TakeCommentNode(GetFocusedEdGraph(), NewNode, LinkedOutput[0]);
		}

		if (LinkedInput.Num() == 1)
		{
			FLocal::TakeCommentNode(GetFocusedEdGraph(), NewNode, LinkedInput[0]);
		}
	}
}

void FBAGraphHandler::Tick(float DeltaTime)
{
	if (IsGraphReadOnly())
		return;
	
	if (Delay_ResetReplaceNode > 0)
	{
		Delay_ResetReplaceNode -= 1;

		if (Delay_ResetReplaceNode == 0)
		{
			if (ReplaceNewNodeTransaction.IsValid())
			{
				ReplaceNewNodeTransaction->Cancel();
				ReplaceNewNodeTransaction.Reset();
			}
		}
	}

	if (!bInitialZoomFinished)
	{
		if (Delay_InitialCache > 0)
		{
			Delay_InitialCache -= 1;
		}
		else
		{
			TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
			if (LastGraphView == GraphPanel->GetViewOffset() && LastZoom == GraphPanel->GetZoomAmount())
			{
				bInitialZoomFinished = true;
			}
		}

		GetGraphEditor()->GetViewLocation(LastGraphView, LastZoom);
	}

	UpdateNewNodes();

	UpdateCachedNodeSize(DeltaTime);

	if (GetMutableDefault<UBASettings>()->bBetterWiringForNewNodes)
	{
		ProcessNodesCreatedLastFrame();
	}

	UpdateSelectedNode();

	HighlightSelectedPin();

	UpdateNodesRequiringFormatting();

	UpdateLerpViewport(DeltaTime);

	NodesCreatedLastFrame.Reset();
	NodesCreatedLastFrame.Append(NodesCreatedThisFrame);
	NodesCreatedThisFrame.Reset();
}

void FBAGraphHandler::UpdateSelectedNode()
{
	UEdGraphNode* CurrentSelectedNode = GetSelectedNode();

	if (CurrentSelectedNode != LastSelectedNode)
	{
		OnSelectionChanged(LastSelectedNode, CurrentSelectedNode);
	}

	LastSelectedNode = CurrentSelectedNode;
}

void FBAGraphHandler::HighlightSelectedPin()
{
	UEdGraphPin* SelectedPinObj = GetSelectedPin();
	if (SelectedPinObj == nullptr)
		return;

	TSharedPtr<SGraphNode> GraphNode = GetGraphNode(SelectedPinObj->GetOwningNode());
	if (!GraphNode.IsValid())
		return;

	TSharedPtr<SGraphPin> GraphPin = FBAUtils::GetGraphPin(GetGraphPanel(), GetSelectedPin());
	if (GraphPin.IsValid())
	{
		GraphPin->SetPinColorModifier(GetMutableDefault<UBASettings>()->PinHighlightColor);
		GraphPin->SetColorAndOpacity(GetMutableDefault<UBASettings>()->PinTextHighlightColor);
	}
}

TSharedPtr<SWindow> FBAGraphHandler::GetOrFindWindow()
{
	check(CachedTab.IsValid())

	TSharedPtr<SWidget> WindowWidget = FBAUtils::GetParentWidgetOfType(CachedTab.Pin(), "SWindow");
	if (WindowWidget.IsValid())
	{
		TSharedPtr<SWindow> NewWindow = StaticCastSharedPtr<SWindow>(WindowWidget);

		// if our cached window has changed, take the new window
		if (CachedWindow != NewWindow)
		{
			CachedWindow = NewWindow;
		}

		return CachedWindow.Pin();
	}

	return nullptr;
}

bool FBAGraphHandler::IsWindowActive()
{	
	return GetOrFindWindow() == FSlateApplication::Get().GetActiveTopLevelWindow();
}

bool FBAGraphHandler::IsGraphReadOnly()
{
	return FBlueprintEditorUtils::IsGraphReadOnly(GetFocusedEdGraph());
}

void FBAGraphHandler::UpdateNewNodes()
{
	UEdGraph* Graph = GetFocusedEdGraph();
	if (Graph == nullptr)
		return;

	// check all nodes on the graph
	TArray<UEdGraphNode*> NewNodes;
	for (UEdGraphNode* Node : Graph->Nodes)
	{
		const bool bIsCommentNode = FBAUtils::IsCommentNode(Node);
		if ((!FBAUtils::IsGraphNode(Node) && !bIsCommentNode) || FBAUtils::IsKnotNode(Node))
			continue;

		// if the node size hasn't been cached, add the node to be calculated
		if (!SeenNodes.Contains(Node) && !GetGraphCache().CachedNodes.Contains(Node->NodeGuid))
		{
			SeenNodes.Add(Node);

			if (!bIsCommentNode)
			{
				NodesCreatedThisFrame.Add(Node);
				NewNodes.Add(Node);
			}

			if (!GetMutableDefault<UBASettings>()->bCacheSizeWhenRequired)
			{
				PendingSize.Emplace(Node);
			}
		}
	}

	// if we are a new node and we are linked another node,
	// we were probably created from being dragged off a pin
	UEdGraphNode* NewNodeToFormat = nullptr;

	bool bHandledAlwaysFormatAll = false;
	if (GetMutableDefault<UBASettings>()->bAlwaysFormatAll)
	{
		TArray<UEdGraphNode*> PendingNodes = NewNodes;
		int32 ErrorCount = 0;
		while (PendingNodes.Num() > 0)
		{
			ErrorCount += 1;
			if (ErrorCount > 1000)
			{
				UE_LOG(LogBlueprintAssist, Error, TEXT("BlueprintAssist: Error infinite loop detected in FBAGraphHandler::UpdateNewNodes"));
				break;
			}

			UEdGraphNode* CurrentNode = PendingNodes.Pop();
			TArray<UEdGraphNode*> NodeTree = FBAUtils::GetNodeTree(CurrentNode).Array();
			if (NodeTree.FilterByPredicate(FBAUtils::IsEventNode).Num() > 0)
			{
				FormatAllEvents();
				bHandledAlwaysFormatAll = true;
				break;
			}

			PendingNodes.RemoveAllSwap([&NodeTree](UEdGraphNode* Node) { return NodeTree.Contains(Node); });
		}
	}

	if (bHandledAlwaysFormatAll)
		return;

	// if there is exactly 1 new node and it is linked, then format it
	if (NewNodes.Num() == 1)
	{
		UEdGraphNode* SingleNewNode = NewNodes[0];

		ReplaceSavedSelectedNode(SingleNewNode);

		NewNodeToFormat = SingleNewNode;
	}
	else // multiple new nodes, check if there is exactly 1 impure node and use that
	{
		TArray<UEdGraphNode*> NewImpureNodes = NewNodes.FilterByPredicate(FBAUtils::IsNodeImpure);
		if (NewImpureNodes.Num() == 1)
		{
			NewNodeToFormat = NewImpureNodes[0];
		}
	}
	
	const auto AutoFormatting = FBAUtils::GetFormatterSettings(Graph).AutoFormatting;

	if (NewNodeToFormat != nullptr && AutoFormatting != BAAutoFormat_Never)
	{
		// TODO: zoom to the newly created node
		if (GetDefault<UBASettings>()->bAutoPositionEventNodes && FBAUtils::IsEventNode(NewNodeToFormat))
		{
			FormatAllEvents();
		}
		else if (FBAUtils::GetLinkedNodes(NewNodeToFormat).Num() > 0)
		{
			FEdGraphFormatterParameters Parameters;

			if (AutoFormatting == BAAutoFormat_FormatSingleConnected)
			{
				Parameters.NodesToFormat = FBAUtils::GetLinkedNodes(NewNodeToFormat, EGPD_Input);
				if (Parameters.NodesToFormat.Num() == 0)
				{
					Parameters.NodesToFormat = FBAUtils::GetLinkedNodes(NewNodeToFormat, EGPD_Output);
				}
				Parameters.NodesToFormat.Add(NewNodeToFormat);
			}

			TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatNodeAfterAdding", "Format Node After Adding")));
			AddPendingFormatNodes(NewNodeToFormat, Transaction, Parameters);
			
			NewNodeForFormatting = NewNodeToFormat;
		}
	}
}

void FBAGraphHandler::ResetGraphEditor(TWeakPtr<SGraphEditor> NewGraphEditor)
{
	CachedGraphEditor = NewGraphEditor;
	InitGraphHandler();
}

void FBAGraphHandler::ReplaceSavedSelectedNode(UEdGraphNode* NewNode)
{
	TSharedPtr<FBAInputProcessor> InputProcessor = IBlueprintAssistModule::Get().GetInputProcessor();
	if (!InputProcessor.IsValid())
		return;

	UEdGraphNode* NodeToReplace = InputProcessor->SavedNodeToReplace;
	if (NodeToReplace != nullptr)
	{
		TArray<UEdGraphPin*> NodeToReplacePins = NodeToReplace->Pins;

		NodeToReplacePins.StableSort([](UEdGraphPin& PinA, UEdGraphPin& PinB)
		{
			return PinA.Direction > PinB.Direction;
		});

		TArray<FPinLink> PinsToLink;

		TArray<UEdGraphPin*> NewNodePins = NewNode->Pins;

		TSet<UEdGraphPin*> PinsConnected;

		// loop through our pins and check which pins can be connected to the new node
		for (int i = 0; i < 2; ++i)
		{
			for (UEdGraphPin* Pin : NodeToReplacePins)
			{
				if (Pin->LinkedTo.Num() == 0)
					continue;

				if (PinsConnected.Contains(Pin))
					continue;

				for (UEdGraphPin* NewNodePin : NewNodePins)
				{
					if (PinsConnected.Contains(NewNodePin))
						continue;
					
					// on the first run (i = 0), we only use pins which have the same name
					if (FBAUtils::GetPinName(Pin) == FBAUtils::GetPinName(NewNodePin) || i > 0)
					{
						TArray<UEdGraphPin*> LinkedTo = Pin->LinkedTo;

						bool bConnected = false;
						for (UEdGraphPin* LinkedPin : LinkedTo)
						{
							if (FBAUtils::CanConnectPins(LinkedPin, NewNodePin, true, false))
							{
								PinsToLink.Add(FPinLink(LinkedPin, NewNodePin));
								PinsConnected.Add(Pin);
								PinsConnected.Add(NewNodePin);
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
		}

		// link the pins marked in the last two loops
		for (auto& PinToLink : PinsToLink)
		{
			for (UEdGraphPin* Pin : NewNode->Pins)
			{
				if (Pin->PinId == PinToLink.To->PinId)
				{
					FBAUtils::TryCreateConnection(PinToLink.From, Pin);
					break;
					//UE_LOG(LogTemp, Warning, TEXT("\tConnected"));
				}
			}
		}

		FBAUtils::SafeDelete(SharedThis(this), NodeToReplace);

		InputProcessor->SavedNodeToReplace = nullptr;

		// when we format we will reset the transaction
		if (PendingFormatting.Contains(NewNode))
		{
			Delay_ResetReplaceNode = -1;
		}
		else
		{
			ReplaceNewNodeTransaction.Reset();
		}
	}
}

UEdGraphNode* FBAGraphHandler::GetRootNode(UEdGraphNode* InitialNode, const TArray<UEdGraphNode*>& NodesToFormat, bool bCheckSelectedNode)
{
	// @TODO Don't hardcode this, make it read the direction off the formatter
	EEdGraphPinDirection FormatterDirection = EGPD_Output;

	auto GraphType = FBAUtils::GetBAGraphType(GetFocusedEdGraph()).GetValue();
	switch (GraphType)
	{
	case BAGraphType_Unknown: break;
	case BAGraphType_Blueprint: break;
	case BAGraphType_BehaviorTree: break;
	case BAGraphType_NiagaraGraph:
		FormatterDirection = EGPD_Output;
		break;
	case BAGraphType_SoundCue:
	case BAGraphType_MaterialGraph:
	case BAGraphType_AnimGraph:
		FormatterDirection = EGPD_Input;
		break;
	}

	auto OppositeDirection = UEdGraphPin::GetComplementaryDirection(FormatterDirection);
	
	const auto NodeTreeFilter = [this, &NodesToFormat](const FPinLink& Link) { return FilterDelegatePin(Link, NodesToFormat); };
	TSet<UEdGraphNode*> NodeTree = FBAUtils::GetNodeTreeWithFilter(InitialNode, NodeTreeFilter);

	TArray<UEdGraphNode*> EventNodes;
	TArray<UEdGraphNode*> UnlinkedNodes;
	TArray<UEdGraphNode*> RootNodes;

	for (UEdGraphNode* Node : NodeTree)
	{
		if (FBAUtils::IsKnotNode(Node))
			continue;

		if (FBAUtils::IsExtraRootNode(Node))
		{
			RootNodes.Add(Node);
			continue;
		}
		
		if (FBAUtils::IsNodeImpure(Node))
		{
			if (FBAUtils::IsEventNode(Node))
			{
				EventNodes.Add(Node);
				continue;
			}

			TArray<UEdGraphPin*> LinkedInputPins = FBAUtils::GetLinkedPins(Node, OppositeDirection).FilterByPredicate(FBAUtils::IsExecPin);

			if (LinkedInputPins.Num() == 0)
			{
				UnlinkedNodes.Emplace(Node);
			}
		}
	}
	
	if (EventNodes.Num() == 0 && UnlinkedNodes.Num() == 0 && RootNodes.Num() == 0)
	{
		const auto Filter = [&](UEdGraphNode* Node) { return FilterSelectiveFormatting(Node, NodesToFormat) && FBAUtils::IsNodeImpure(Node); };
		UEdGraphNode* NodeInDirection = FBAUtils::GetTopMostWithFilter(InitialNode, OppositeDirection, Filter);

		const TArray<UEdGraphNode*> Visited = { NodeInDirection };
		while (UK2Node_Knot* Knot = Cast<UK2Node_Knot>(NodeInDirection))
		{
			const auto& LinkedOut = Knot->GetOutputPin()->LinkedTo;
			if (LinkedOut.Num() > 0)
			{
				auto NextNode = LinkedOut[0]->GetOwningNode();
				if (Visited.Contains(NextNode))
					break;
				
				NodeInDirection = NextNode;
			}
		}

		return NodeInDirection;
	}

	const auto& SortByDirection = [&FormatterDirection](const UEdGraphNode& A, const UEdGraphNode& B)
	{
		if (FormatterDirection == EGPD_Output) // sort left to right
		{
			if (A.NodePosX != B.NodePosX)
				return A.NodePosX < B.NodePosX;
		}
		else // sort right to left
		{
			if (A.NodePosX != B.NodePosX)
				return A.NodePosX > B.NodePosX;
		}

		// sort top to bottom
		return A.NodePosY < B.NodePosY;
	};

	UEdGraphNode* SelectedNode = GetSelectedNode();

	if (RootNodes.Num() > 0)
	{
		if (bCheckSelectedNode && RootNodes.Contains(SelectedNode))
		{
			return SelectedNode;
		}

		RootNodes.Sort(SortByDirection);
		RootNodes.StableSort([](UEdGraphNode& NodeA, UEdGraphNode& NodeB)
		{
			return FBAUtils::GetPinsByDirection(&NodeA, EGPD_Input).Num() < FBAUtils::GetPinsByDirection(&NodeB, EGPD_Input).Num();
		});

		return RootNodes[0];
	}
	
	if (EventNodes.Num() > 0) // use the top left most event node
	{
		if (bCheckSelectedNode && EventNodes.Contains(SelectedNode))
		{
			return SelectedNode;
		}
		
		EventNodes.Sort(SortByDirection);
		return EventNodes[0];
	}

	if (bCheckSelectedNode && UnlinkedNodes.Contains(SelectedNode))
	{
		return SelectedNode;
	}
	
	// use the top left most unlinked node
	UnlinkedNodes.Sort(SortByDirection);
	return UnlinkedNodes[0];
}

bool FBAGraphHandler::FilterSelectiveFormatting(UEdGraphNode* Node, const TArray<UEdGraphNode*>& NodesToFormat)
{
	if (NodesToFormat.Num() > 0)
	{
		return NodesToFormat.Contains(Node);
	}

	return true;
}

bool FBAGraphHandler::FilterDelegatePin(const FPinLink& PinLink, const TArray<UEdGraphNode*>& NodesToFormat)
{
	if (!FilterSelectiveFormatting(PinLink.To->GetOwningNode(), NodesToFormat))
	{
		return false;
	}

	if (GetMutableDefault<UBASettings>()->bTreatDelegatesAsExecutionPins || !FBAUtils::IsDelegatePin(PinLink.From))
	{
		return true;
	}

	return FBAUtils::IsNodePure(PinLink.From->GetOwningNode()) || FBAUtils::IsNodePure(PinLink.To->GetOwningNode());
}

FBACacheData& FBAGraphHandler::GetGraphCache()
{
	return IBlueprintAssistModule::Get().GetSizeCache().GetGraphData(GetFocusedEdGraph());
}

UEdGraph* FBAGraphHandler::GetFocusedEdGraph()
{
	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
	if (GraphPanel.IsValid())
	{
		return GraphPanel->GetGraphObj();
	}
	return nullptr;
}

TSharedPtr<SGraphEditor> FBAGraphHandler::GetGraphEditor()
{
	if (CachedGraphEditor.IsValid())
	{
		return CachedGraphEditor.Pin();
	}
	
	if (CachedTab.IsValid())
	{
		// grab the graph editor from the tab
		const TSharedRef<SWidget> TabContent = CachedTab.Pin()->GetContent();

		if (TabContent->GetTypeAsString() == "SGraphEditor")
		{
			TSharedPtr<SGraphEditor> TabContentAsGraphEditor = StaticCastSharedRef<SGraphEditor>(TabContent);

			if (TabContentAsGraphEditor.IsValid())
			{
				if (CachedGraphEditor != TabContentAsGraphEditor)
				{
					ResetGraphEditor(TWeakPtr<SGraphEditor>(TabContentAsGraphEditor));
					return CachedGraphEditor.Pin();
				}
			}
		}
	}

	return nullptr;
}

TSharedPtr<SGraphPanel> FBAGraphHandler::GetGraphPanel()
{
	if (CachedGraphPanel.IsValid())
	{
		return CachedGraphPanel.Pin();
	}
	
	TSharedPtr<SGraphEditor> GraphEditor = GetGraphEditor();
	if (!GraphEditor.IsValid())
	{
		return nullptr;
	}

	// try to grab the graph panel from the graph editor
	TSharedPtr<SWidget> GraphPanelWidget = FBAUtils::GetChildWidget(GraphEditor, "SGraphPanel");
	if (GraphPanelWidget.IsValid())
	{
		CachedGraphPanel = StaticCastSharedPtr<SGraphPanel>(GraphPanelWidget);
		return CachedGraphPanel.Pin();
	}

	return nullptr;
}

FSlateRect FBAGraphHandler::GetCachedNodeBounds(UEdGraphNode* Node, bool bWithCommentBubble)
{
	if (!Node)
		return FSlateRect();

	FVector2D Pos(Node->NodePosX, Node->NodePosY);

	FVector2D Size(300, 150);
	FVector2D* SizePtr = GetGraphCache().CachedNodes.Find(Node->NodeGuid);
	if (SizePtr != nullptr)
	{
		Size.X = SizePtr->X;
		Size.Y = SizePtr->Y;
	}

	FVector2D* CommentBubbleSizePtr = CommentBubbleSizeCache.Find(Node);
	if (bWithCommentBubble && CommentBubbleSizePtr != nullptr)
	{
		const FVector2D CommentBubbleSize = *CommentBubbleSizePtr;
		Pos.Y -= CommentBubbleSize.Y;
		Size.Y += CommentBubbleSize.Y;
	}

	return FSlateRect::FromPointAndExtent(Pos, Size);
}

UEdGraphPin* FBAGraphHandler::GetSelectedPin()
{
	if (!SelectedPinHandle.IsSet())
		return nullptr;

	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
	if (!GraphPanel.IsValid())
		return nullptr;

	UEdGraphPin* PinObj = SelectedPinHandle->GetPinObj(*GraphPanel.Get());
	if (!PinObj || PinObj->bHidden || PinObj->bWasTrashed || PinObj->bOrphanedPin)
		return nullptr;
	
	return PinObj;
}

UEdGraphNode* FBAGraphHandler::GetSelectedNode(bool bAllowCommentNodes)
{
	TArray<UEdGraphNode*> SelectedNodes = GetSelectedNodes(bAllowCommentNodes).Array();
	return SelectedNodes.Num() == 1 ? SelectedNodes[0] : nullptr;
}

TSet<UEdGraphNode*> FBAGraphHandler::GetSelectedNodes(bool bAllowCommentNodes)
{
	TSet<UEdGraphNode*> SelectedNodes;

	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
	if (GraphPanel.IsValid())
	{
		for (UObject* Obj : GraphPanel->SelectionManager.GetSelectedNodes())
		{
			if (UEdGraphNode* Node = Cast<UEdGraphNode>(Obj))
			{
				if (FBAUtils::IsGraphNode(Node) || FBAUtils::IsKnotNode(Node) || (bAllowCommentNodes && FBAUtils::IsCommentNode(Node)))
				{
					SelectedNodes.Emplace(Node);
				}
			}
		}
	}

	return SelectedNodes;
}

UBlueprint* FBAGraphHandler::GetBlueprint()
{
	if (UEdGraph* Graph = GetFocusedEdGraph())
		return Graph->GetTypedOuter<UBlueprint>();

	return nullptr;
}

// FBlueprintEditor* FBAGraphHandler::GetBlueprintEditor()
// {
// 	if (UBlueprint* BlueprintAsset = GetBlueprint())
// 	{
// 		FBlueprintEditor* BlueprintEditor = static_cast<FBlueprintEditor*>(GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->FindEditorForAsset(BlueprintAsset, false));
// 		return BlueprintEditor;
// 	}
//
// 	return nullptr;
// }

// TWeakPtr<SMyBlueprint> FBAGraphHandler::GetMyBlueprintWidget()
// {
// 	if (FBlueprintEditor* BlueprintEditor = GetBlueprintEditor())
// 	{
// 		return BlueprintEditor->GetMyBlueprintWidget();
// 	}
//
// 	return nullptr;
// }

void FBAGraphHandler::AddPendingFormatNodes(UEdGraphNode* Node, TSharedPtr<FScopedTransaction> InPendingTransaction, FEdGraphFormatterParameters InFormatterParameters)
{
	// UEditorEngine* Editor = static_cast<UEditorEngine*>(GEngine);
	// if (Editor->IsTransactionActive())
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Cannot format while transaction is active"));
	// 	return;
	// }
	
	PendingTransaction = InPendingTransaction;
	FormatterParameters = InFormatterParameters;
	
	if (FBAUtils::IsGraphNode(Node))
	{
		PendingFormatting.Add(Node);
	}

	if (GetMutableDefault<UBASettings>()->bCacheSizeWhenRequired)
	{
		// calculate size for all connected nodes which don't have a size
		TSet<UEdGraphNode*> NodeTree = FBAUtils::GetNodeTree(Node);
		for (UEdGraphNode* ConnectedNode : NodeTree)
		{
			if (FBAUtils::IsGraphNode(ConnectedNode) && !FBAUtils::IsKnotNode(ConnectedNode) && !GetGraphCache().CachedNodes.Contains(ConnectedNode->NodeGuid))
			{
				PendingSize.Add(ConnectedNode);
			}
		}
	}
}

void FBAGraphHandler::ResetSingleNewNodeTransaction()
{
	Delay_ResetReplaceNode = 2;
}

float FBAGraphHandler::GetPinY(UEdGraphPin* Pin)
{
	if (GetGraphCache().CachedPins.Contains(Pin->PinId))
		return Pin->GetOwningNode()->NodePosY + GetGraphCache().CachedPins[Pin->PinId];

	// cache pin offset
	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
	if (GraphPanel.IsValid())
	{
		TSharedPtr<SGraphNode> GraphNode = GetGraphNode(Pin->GetOwningNode());
		if (GraphNode.IsValid())
		{
			TSharedPtr<SGraphPin> GraphPin = GraphNode->FindWidgetForPin(Pin);
			if (GraphPin.IsValid())
			{
				if (GraphPin->GetPinObj() != nullptr)
				{
					return Pin->GetOwningNode()->NodePosY + GraphPin->GetNodeOffset().Y;
				}
			}
		}
	}

	return Pin->GetOwningNode()->NodePosY;
}

void FBAGraphHandler::UpdateCachedNodeSize(float DeltaTime)
{
	if (!bInitialZoomFinished)
	{
		return;
	}

	TSharedPtr<SGraphEditor> GraphEditor = GetGraphEditor();
	if (!GraphEditor.IsValid())
		return;

	UEdGraph* Graph = GetFocusedEdGraph();
	if (Graph == nullptr)
		return;

	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();

	// Save the currently viewport to restore once we are done
	if (PendingSize.Num() > 0 && !bFullyZoomed)
	{
		GraphEditor->GetViewLocation(ViewCache, ZoomCache);
		bFullyZoomed = true;

#if ENGINE_MINOR_VERSION >= 22
		if (GetDefault<UBASettings>()->bEnableCachingNodeSizeNotification && PendingSize.Num() > GetDefault<UBASettings>()->RequiredNumPendingSizeForNotification)
		{
			FAsyncTaskNotificationConfig CachingNodeSizeConfig;
			CachingNodeSizeConfig.TitleText = FText::FromString(FString::Printf(TEXT("Caching node sizes for graph <%s>"), *GetFocusedEdGraph()->GetName()));
			CachingNodeSizeConfig.bCanCancel = true;
			CachingNodeSizeConfig.FadeOutDuration = 0.5f;
			CachingSizeNotification = MakeUnique<FAsyncTaskNotification>(CachingNodeSizeConfig);
		}
#endif
	}

	if (PendingSize.Num() > 0)
	{
		UEdGraphNode* FirstNode = PendingSize[0];

		if (FocusedNode != FirstNode)
		{
			TicksOnFocusedNode = 0;
			Delay_ViewportZoomIn = 2;
			FocusedNode = FirstNode;

			// Zoom fully in, to cache the node size
			GraphEditor->SetViewLocation(FVector2D(FocusedNode->NodePosX, FocusedNode->NodePosY), 1.f);
		}
		else
		{
			GraphEditor->SetViewLocation(FVector2D(FocusedNode->NodePosX, FocusedNode->NodePosY), 1.f);

			TicksOnFocusedNode += 1;

			if (TicksOnFocusedNode == 100)
			{
				NodeSizeTimeout = 10.f;

#if ENGINE_MINOR_VERSION >= 22
				FAsyncTaskNotificationConfig TimeoutConfig;
				TimeoutConfig.TitleText = FText::FromString(FString::Printf(TEXT("Node \"%s\" is not fully visible on screen. Please resize the window to fit the node."), *FBAUtils::GetNodeName(FocusedNode)));
				TimeoutConfig.bCanCancel = true;
				TimeoutConfig.ExpireDuration = 4.f;
				SizeTimeoutNotification = MakeUnique<FAsyncTaskNotification>(TimeoutConfig);
#else
				const FString NotificationMsg = FString::Printf(
					TEXT("Warning: Node \"%s\" is not fully visible on screen. Please resize the window to fit the node."),
					*FBAUtils::GetNodeName(FocusedNode));

				FNotificationInfo Notification(FText::FromString(NotificationMsg));
				Notification.ExpireDuration = 10.0f;
				FSlateNotificationManager::Get().AddNotification(Notification);
#endif
			}

			if (TicksOnFocusedNode > 100)
			{
				NodeSizeTimeout -= DeltaTime;

				bool bNotificationCancel = false;

#if ENGINE_MINOR_VERSION >= 25
				SizeTimeoutNotification->SetProgressText(FText::FromString(FString::Printf(TEXT("Timeout in %.0f"), NodeSizeTimeout)));
				bNotificationCancel = SizeTimeoutNotification->GetPromptAction() == EAsyncTaskNotificationPromptAction::Cancel;
#elif ENGINE_MINOR_VERSION >= 22
				SizeTimeoutNotification->SetProgressText(FText::FromString(FString::Printf(TEXT("Timeout in %.0f"), NodeSizeTimeout)));
				bNotificationCancel = SizeTimeoutNotification->ShouldCancel();
#endif
				
				if (NodeSizeTimeout <= 0 || bNotificationCancel)
				{
					const FString NotificationMsg = FString::Printf(
						TEXT("Warning: Node \"%s\" has failed to calculate size and is using the default size"),
						*FBAUtils::GetNodeName(FocusedNode));

#if ENGINE_MINOR_VERSION >= 22
					SizeTimeoutNotification->SetProgressText(FText::FromString(NotificationMsg));
					SizeTimeoutNotification->SetComplete(false);
#endif

					// set default size to 300, 150
					PendingSize.RemoveSwap(FocusedNode);
					
					TSharedPtr<SGraphNode> GraphNode = GetGraphNode(FocusedNode);
					FVector2D NodeSize(300, 150);
					if (GraphNode.IsValid())
					{
						NodeSize = GraphNode->GetDesiredSize();
					}
					
					GetGraphCache().CachedNodes.Add(FocusedNode->NodeGuid, NodeSize);
				}
			}
		}
	}

	// delay for two ticks to make sure the size is accurate
	if (Delay_ViewportZoomIn > 0)
	{
		Delay_ViewportZoomIn -= 1;
		return;
	}

	// cache node sizes
	TArray<UEdGraphNode*> NodesCalculated;
	for (UEdGraphNode* Node : PendingSize)
	{
		const bool bIsCommentNode = FBAUtils::IsCommentNode(Node);

		if (Node != FocusedNode)
		{
			// only cache the focused node resulting in more accurate node caching
			if (GetMutableDefault<UBASettings>()->bSlowButAccurateSizeCaching)
				continue;

			// comment nodes should only cache size if they are the focused node
			if (bIsCommentNode && Node != FocusedNode)
				continue;
		}

		if (FBAUtils::IsNodeDeleted(Node))
		{
			NodesCalculated.Add(Node);
			continue;
		}
		
		TSharedPtr<SGraphNode> GraphNode = GetGraphNode(Node);

		if (!GraphNode.IsValid())
			continue;
		
		// to calculate the node size, the graph node must be visible on screen (unless it is a comment node)
		if (!FBAUtils::IsNodeVisible(GraphPanel, Node) && !bIsCommentNode)
			continue;

		FVector2D Size = GraphNode->GetDesiredSize();

		// for comment nodes we only want to cache the title bar height
		if (FBAUtils::IsCommentNode(Node))
		{
			Size.Y = GraphNode->GetDesiredSizeForMarquee().Y;
		}

		// the size can be zero when a node is initially created, do not use this value
		if (Size.SizeSquared() <= 0)
			continue;

		// set each node to the global resize comment bubble setting
		if (!FBAUtils::IsCommentNode(Node)) // we don't want to do this for comment nodes, the auto size comments plugin should handle this setting
		{
			Node->bCommentBubblePinned = GetMutableDefault<UBASettings>()->bSetAllCommentBubblePinned;
		}

		// cache pin offset
		TArray<TSharedRef<SWidget>> PinsAsWidgets;
		GraphNode->GetPins(PinsAsWidgets);
		bool bAllPinsCached = true;
		for (const TSharedRef<SWidget>& Widget : PinsAsWidgets)
		{
			TSharedPtr<SGraphPin> GraphPin = StaticCastSharedRef<SGraphPin>(Widget);
			if (GraphPin.IsValid())
			{
				if (UEdGraphPin* Pin = GraphPin->GetPinObj())
				{
					GetGraphCache().CachedPins.Add(Pin->PinId, GraphPin->GetNodeOffset().Y);
				}
			}
			else
			{
				UE_LOG(LogBlueprintAssist, Error,
				       TEXT("BlueprintAssistGraphHandler::UpdateCachedNodeSize: GraphPin is invalid for node %s"),
				       *FBAUtils::GetNodeName(Node));

				bAllPinsCached = false;
				break;
			}
		}

		if (bAllPinsCached)
		{
			if (!Node->IsAutomaticallyPlacedGhostNode())
			{
				SNodePanel::SNode::FNodeSlot* CommentSlot = GraphNode->GetSlot(ENodeZone::TopCenter);
				if (CommentSlot != nullptr)
				{
					TSharedPtr<SCommentBubble> CommentBubble = StaticCastSharedRef<SCommentBubble>(CommentSlot->GetWidget());

					if (CommentBubble.IsValid())
					{
						FVector2D CommentBubbleSize = CommentBubble->GetDesiredSize();
						CommentBubbleSizeCache.Add(Node, CommentBubbleSize);
					}
				}
			}

			GetGraphCache().CachedNodes.Add(Node->NodeGuid, Size);
			NodesCalculated.Add(Node);

			// Complete the size timeout notification
#if ENGINE_MINOR_VERSION >= 22
			if (SizeTimeoutNotification.IsValid())
			{
				SizeTimeoutNotification->SetProgressText(FText::FromString("Successfully calculated size"));
				SizeTimeoutNotification->SetComplete();
			}
#endif
	

			if (bIsCommentNode && GetMutableDefault<UBASettings>()->bTryToHandleCommentNodes)
			{
				UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(Node);

				FSlateRect CommentRect = FBAUtils::GetNodeBounds(CommentNode);

				FChildren* PanelChildren = GetGraphPanel()->GetAllChildren();
				const int32 NumChildren = PanelChildren->Num();

				// Iterate across all nodes in the graph
				for (int32 NodeIndex = 0; NodeIndex < NumChildren; ++NodeIndex)
				{
					const TSharedRef<SGraphNode> SomeNodeWidget = StaticCastSharedRef<SGraphNode>(PanelChildren->GetChildAt(NodeIndex));
					UObject* GraphObject = SomeNodeWidget->GetObjectBeingDisplayed();

					if (GraphObject == nullptr)
						continue;

					// skip if we already contain the graph obj
					if (CommentNode->GetNodesUnderComment().Contains(GraphObject))
						continue;

					// check if the node bounds is contained in ourself
					if (GraphObject != CommentNode)
					{
						const FVector2D SomeNodePosition = SomeNodeWidget->GetPosition();
						if (CommentRect.ContainsPoint(SomeNodePosition))
						{
							CommentNode->AddNodeUnderComment(GraphObject);
						}
					}
				}
			}
		}
	}

	// remove any nodes that we calculated the size for
	for (UEdGraphNode* Node : NodesCalculated)
	{
		PendingSize.RemoveSwap(Node);
	}

	// zoom out if we don't need to calculate any sizes
	bool bCancelSizeCaching = false;
#if ENGINE_MINOR_VERSION >= 25
	bCancelSizeCaching = CachingSizeNotification.IsValid() && CachingSizeNotification->GetPromptAction() == EAsyncTaskNotificationPromptAction::Cancel;
#elif ENGINE_MINOR_VERSION >= 22
	bCancelSizeCaching = CachingSizeNotification.IsValid() && CachingSizeNotification->ShouldCancel();
#endif
	
	if (bCancelSizeCaching || (PendingSize.Num() == 0 && bFullyZoomed))
	{
		GetGraphEditor()->SetViewLocation(ViewCache, ZoomCache);
		bFullyZoomed = false;
		FocusedNode = nullptr;
		FText Message = bCancelSizeCaching ? FText::FromString(TEXT("Cancelled")) : FText::FromString(TEXT("Complete"));

		if (bCancelSizeCaching)
		{
			PendingFormatting.Empty();
			PendingSize.Empty();
		}

#if ENGINE_MINOR_VERSION >= 22
		if (CachingSizeNotification.IsValid())
		{
			CachingSizeNotification->SetProgressText(Message);
			CachingSizeNotification->SetComplete();
		}
#endif
	}
	else
	{
#if ENGINE_MINOR_VERSION >= 22
		if (CachingSizeNotification.IsValid())
		{
			CachingSizeNotification->SetProgressText(FText::AsNumber(PendingSize.Num()));
		}
#endif
	}
}

void FBAGraphHandler::UpdateNodesRequiringFormatting()
{
	if (PendingFormatting.Num() == 0 && FormatAllColumns.Num() == 0)
		return;

	TArray<UEdGraphNode*> DeletedNodes = PendingFormatting.Array().FilterByPredicate(FBAUtils::IsNodeDeleted);
	for (UEdGraphNode* Node : DeletedNodes)
	{
		PendingFormatting.Remove(Node);
	}
	
	if (PendingSize.Num() > 0)
		return;

	const auto& GraphCacheCopy = GetGraphCache();
	const auto HasCachedSize = [GraphCacheCopy](UEdGraphNode* Node)
	{
		return GraphCacheCopy.CachedNodes.Contains(Node->NodeGuid);
	};

	// format dirty nodes
	TArray<UEdGraphNode*> NodesToFormatCopy = PendingFormatting.Array().FilterByPredicate(HasCachedSize);

	int CountError = NodesToFormatCopy.Num();

	while (NodesToFormatCopy.Num() > 0)
	{
		CountError -= 1;
		if (CountError < 0)
		{
			UE_LOG(LogBlueprintAssist, Error, TEXT("Failed to format pending nodes"));
			NodesToFormatCopy.Empty();
			PendingFormatting.Empty();
			break;
		}

		UEdGraphNode* NodeToFormat = NodesToFormatCopy.Pop();
		{
			// UE_LOG(LogTemp, Warning, TEXT("Formatting %s"), *FBAUtils::GetNodeName(NodeToFormat));
			
			check(GetGraphCache().CachedNodes.Contains(NodeToFormat->NodeGuid))

			TSharedPtr<FFormatterInterface> Formatter = FormatNodes(NodeToFormat);
			PendingFormatting.Remove(NodeToFormat);
			NodesToFormatCopy.Remove(NodeToFormat);

			if (Formatter.IsValid())
			{
				for (UEdGraphNode* Node : Formatter->GetFormattedNodes())
				{
					PendingFormatting.Remove(Node);
					NodesToFormatCopy.Remove(Node);
				}
			}
		}

		if (ReplaceNewNodeTransaction.IsValid())
		{
			ReplaceNewNodeTransaction.Reset();
		}
	}

	if (PendingFormatting.Num() == 0)
	{
		FormatterParameters.Reset();
		PendingTransaction.Reset();
		// UE_LOG(LogTemp, Warning, TEXT("Reset transactions?"));
	}

	// handle format all nodes
	if (FormatAllColumns.Num() > 0)
	{
		if (GetDefault<UBASettings>()->FormatAllStyle == BAFormatAll_Smart)
		{
			SmartFormatAll();
		}
		else
		{
			// this also handles BAFormatAll_NodeType, should separate into another function
			SimpleFormatAll();
		}
	}
}

void FBAGraphHandler::SimpleFormatAll()
{
	TSet<UEdGraphNode*> FormattedNodes;
	FSlateRect FormattedBounds;

	int32 ColumnX = 0;

	for (int i = 0; i < FormatAllColumns.Num(); ++i)
	{
		bool bFirst = true;

		for (UEdGraphNode* Node : FormatAllColumns[i])
		{
			if (FormattedNodes.Contains(Node))
				continue;
			
			TSharedPtr<FFormatterInterface> Formatter = FormatNodes(Node, true);
			UEdGraphNode* RootNode = Formatter->GetRootNode();
			
			if (!Formatter.IsValid())
				continue;

			// align the position of the formatted nodes to the column
			const int32 DeltaX = ColumnX - RootNode->NodePosX;

			// offset the first formatted node's Y position to zero
			const int32 DeltaY = bFirst ? 0 - RootNode->NodePosY : 0;
			
			for (auto FormattedNode : Formatter->GetFormattedNodes())
			{
				FormattedNode->NodePosX += DeltaX;
				FormattedNode->NodePosY += DeltaY;
			}
			
			FormattedNodes.Append(Formatter->GetFormattedNodes());

			const FSlateRect CurrentBounds = FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), Formatter->GetFormattedNodes().Array());

			if (bFirst)
			{
				bFirst = false;
				FormattedBounds = CurrentBounds;
			}
			else
			{
				const float Delta = (FormattedBounds.Bottom + GetMutableDefault<UBASettings>()->FormatAllPadding.Y) - CurrentBounds.Top;
				for (UEdGraphNode* FormattedNode : Formatter->GetFormattedNodes())
				{
					FormattedNode->NodePosY += Delta;
				}

				FormattedBounds = FormattedBounds.Expand(FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), Formatter->GetFormattedNodes().Array()));
			}
		}

		if (!bFirst) // if bFirst is false that also means we formatted at least 1 node
		{
			ColumnX = FormattedBounds.Right + GetMutableDefault<UBASettings>()->FormatAllPadding.X;
		}
	}

	FormatAllColumns.Empty();
	FormatAllTransaction.Reset();
}

void FBAGraphHandler::SmartFormatAll()
{
    TArray<TSharedPtr<FFormatterInterface>> AllFormatters;

	// format all the nodes
	TSet<UEdGraphNode*> PreviouslyFormattedNodes;
	
	for (UEdGraphNode* Node : FormatAllColumns[0])
	{
    	if (PreviouslyFormattedNodes.Contains(Node))
    		continue;
    	    	
		TSharedPtr<FFormatterInterface> Formatter = FormatNodes(Node, true);
    	AllFormatters.Add(Formatter);

    	PreviouslyFormattedNodes.Append(Formatter->GetFormattedNodes());
	}

    float ColumnX = 0;
    while (AllFormatters.Num() > 0)
    {
        TArray<TSharedPtr<FFormatterInterface>> AllFormattersCopy = AllFormatters;

    	// sort formatted nodes by left most
    	AllFormattersCopy.Sort([](TSharedPtr<FFormatterInterface> FormatterA, TSharedPtr<FFormatterInterface> FormatterB)
    	{
            UEdGraphNode* RootA = FormatterA->GetRootNode();
            UEdGraphNode* RootB = FormatterB->GetRootNode();
			if (RootA->NodePosX != RootB->NodePosX)
			{
				return RootA->NodePosX < RootB->NodePosX;
			}

    		return RootA->NodePosY < RootB->NodePosY;  
    	});

    	// get the bounds of the left most node
        TSharedPtr<FFormatterInterface> LeftMostNodeTree = AllFormattersCopy[0];
    	const FSlateRect LeftMostNodeBounds = FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), LeftMostNodeTree->GetFormattedNodes().Array());
    	float ColumnRight = ColumnX + LeftMostNodeBounds.GetSize().X;

    	TArray<TSharedPtr<FFormatterInterface>> CurrentColumn;
    	CurrentColumn.Add(LeftMostNodeTree);

    	// create columns by checking for overlapping formatted node-trees
    	for (TSharedPtr<FFormatterInterface> Formatter : AllFormattersCopy)
    	{
			if (Formatter == LeftMostNodeTree)
				continue;
    		
            TSet<UEdGraphNode*> FormatterNodes = Formatter->GetFormattedNodes();
			FSlateRect Bounds = FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), FormatterNodes.Array());

    		if (Bounds.Left < ColumnRight)
    		{
    			ColumnRight = FMath::Max(ColumnRight, ColumnX + Bounds.GetSize().X);
    			CurrentColumn.Add(Formatter);
    		}
    	}

    	FSlateRect FormattedBounds;

    	// Sort the column by height
    	CurrentColumn.Sort([](TSharedPtr<FFormatterInterface> FormatterA, TSharedPtr<FFormatterInterface> FormatterB)
    	{
    		UEdGraphNode* RootA = FormatterA->GetRootNode();
			UEdGraphNode* RootB = FormatterB->GetRootNode();
			if (RootA->NodePosY != RootB->NodePosY)
			{
			    return RootA->NodePosY < RootB->NodePosY;
			}

			return RootA->NodePosX < RootB->NodePosX;  
    	});

    	bool bFirst = true;

    	// position the node-trees into columns
    	for (TSharedPtr<FFormatterInterface> Formatter : CurrentColumn)
    	{
    		UEdGraphNode* RootNode = Formatter->GetRootNode();
    		
    		// align the position of the formatted nodes to the column
    		const int32 DeltaX = ColumnX - RootNode->NodePosX;
    
    		// offset the first formatted node's Y position to zero
    		const int32 DeltaY = bFirst ? 0 - RootNode->NodePosY : 0;

    		for (auto FormattedNode : Formatter->GetFormattedNodes())
    		{
    			FormattedNode->NodePosX += DeltaX;
    			FormattedNode->NodePosY += DeltaY;
    		}
    		
    		const FSlateRect CurrentBounds = FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), Formatter->GetFormattedNodes().Array());
    		
    		if (bFirst)
    		{
    			bFirst = false;
    			FormattedBounds = CurrentBounds;
    		}
    		else
    		{
    			const float Delta = (FormattedBounds.Bottom + GetDefault<UBASettings>()->FormatAllPadding.Y) - CurrentBounds.Top;
    			for (UEdGraphNode* FormattedNode : Formatter->GetFormattedNodes())
    			{
    				FormattedNode->NodePosY += Delta;
    			}
    
    			FormattedBounds = FormattedBounds.Expand(FBAUtils::GetCachedNodeArrayBounds(SharedThis(this), Formatter->GetFormattedNodes().Array()));
    		}

    		// UE_LOG(LogTemp, Warning, TEXT("\t%s"), *FBAUtils::GetNodeName(Formatter->GetRootNode()));
    		AllFormatters.Remove(Formatter);
    	}

    	ColumnX = ColumnRight + GetDefault<UBASettings>()->FormatAllPadding.X;
    }
    
    FormatAllColumns.Empty();
    FormatAllTransaction.Reset();
}

void FBAGraphHandler::SetSelectedPin(UEdGraphPin* NewPin)
{
	// if we changed pin, reset the color of the old selected pin
	if (SelectedPinHandle.IsSet() && !(SelectedPinHandle.GetValue() == FGraphPinHandle(NewPin)))
	{
		TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
		if (GraphPanel.IsValid())
		{
			UEdGraphPin* EdGraphPin = SelectedPinHandle->GetPinObj(*GraphPanel.Get());
			if (EdGraphPin != nullptr)
			{
				TSharedPtr<SGraphPin> GraphPin = GetGraphPin(EdGraphPin);
				if (GraphPin.IsValid())
				{
					GraphPin->SetPinColorModifier(FLinearColor::White);
					GraphPin->SetColorAndOpacity(FLinearColor::White);
				}
			}
		}
	}

	SelectedPinHandle = FGraphPinHandle(NewPin);
}

void FBAGraphHandler::UpdateLerpViewport(const float DeltaTime)
{
	if (bLerpViewport)
	{
		FVector2D CurrentView;
		float CurrentZoom;
		GetGraphEditor()->GetViewLocation(CurrentView, CurrentZoom);

		TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
		if (!GraphPanel.IsValid())
			return;

		FVector2D TargetView = TargetLerpLocation;
		if (bCenterWhileLerping)
		{
			const FGeometry Geometry = GraphPanel->GetCachedGeometry();
			const FVector2D HalfOfScreenInGraphSpace = 0.5f * Geometry.Size / GraphPanel->GetZoomAmount();
			TargetView -= HalfOfScreenInGraphSpace;
		}

		if (FVector2D::Distance(CurrentView, TargetView) > 10.f)
		{
			const FVector2D NewView = FMath::Vector2DInterpTo(CurrentView, TargetView, DeltaTime, 8.f);

			GetGraphEditor()->SetViewLocation(NewView, CurrentZoom);
		}
		else
		{
			bLerpViewport = false;
		}
	}
}

void FBAGraphHandler::BeginLerpViewport(const FVector2D TargetView, const bool bCenter)
{
	TargetLerpLocation = TargetView;
	bLerpViewport = true;
	bCenterWhileLerping = bCenter;
}

TSharedPtr<SGraphNode> FBAGraphHandler::GetGraphNode(UEdGraphNode* Node)
{
	TSharedPtr<SGraphPanel> GraphPanel = GetGraphPanel();
	if (GraphPanel.IsValid())
		return GraphPanel->GetNodeWidgetFromGuid(Node->NodeGuid);

	return nullptr;
}

TSharedPtr<SGraphPin> FBAGraphHandler::GetGraphPin(UEdGraphPin* Pin)
{
	return GetGraphNode(Pin->GetOwningNode())->FindWidgetForPin(Pin);
}

void FBAGraphHandler::RefreshNodeSize(UEdGraphNode* Node)
{
	if (FBAUtils::IsKnotNode(Node))
		return;
	
	if (FBAUtils::IsGraphNode(Node))
	{
		PendingSize.Add(Node);

		UEdGraphNode* NodeToFormat = GetRootNode(Node, TArray<UEdGraphNode*>());

		if (FormatterMap.Contains(NodeToFormat))
		{
			FormatterMap[NodeToFormat].Reset();
			FormatterMap.Remove(NodeToFormat);
		}
	}
	else if (FBAUtils::IsCommentNode(Node))
	{
		PendingSize.Add(Node);
	}
}

void FBAGraphHandler::RefreshAllNodeSizes()
{
	for (UEdGraphNode* Node : GetFocusedEdGraph()->Nodes)
	{
		RefreshNodeSize(Node);
	}
}

void FBAGraphHandler::ResetTransactions()
{
	ReplaceNewNodeTransaction.Reset();
	PendingTransaction.Reset();
	FormatAllTransaction.Reset();
}

void FBAGraphHandler::FormatAllEvents()
{
	UEdGraph* EdGraph = GetFocusedEdGraph();
	if (EdGraph == nullptr)
		return;

	const EBAFormatAllStyle FormatAllStyle = GetDefault<UBASettings>()->FormatAllStyle.GetValue();
	
	TArray<UEdGraphNode*> ExtraNodes;
	TArray<UEdGraphNode*> CustomEvents;
	TArray<UEdGraphNode*> InputEvents;
	TArray<UEdGraphNode*> ActorEvents;
	TArray<UEdGraphNode*> ComponentEvents;
	TArray<UEdGraphNode*> OtherEvents;

	for (UEdGraphNode* Node : EdGraph->Nodes)
	{
		if (GetMutableDefault<UBASettings>()->FormatAllStyle == BAFormatAll_NodeType)
		{
			if (FBAUtils::IsExtraRootNode(Node))
			{
				ExtraNodes.Add(Node);
			}
			else if (Node->IsA(UK2Node_CustomEvent::StaticClass()))
			{
				CustomEvents.Add(Node);
			}
			else if (FBAUtils::IsInputNode(Node))
			{
				InputEvents.Add(Node);
			}
			else if (Node->IsA(UK2Node_ComponentBoundEvent::StaticClass()))
			{
				ComponentEvents.Add(Node);
			}
			else if (Node->IsA(UK2Node_Event::StaticClass())) // Node->IsA(UK2Node_ActorBoundEvent::StaticClass()) ||  
			{
				ActorEvents.Add(Node);
			}
			else if (FBAUtils::IsEventNode(Node))
			{
				OtherEvents.Add(Node);
			}
		}
		else
		{
			if (FBAUtils::IsEventNode(Node) || FBAUtils::IsExtraRootNode(Node))
			{
				OtherEvents.Add(Node);
			}
		}
	}
	
	if (FormatAllStyle == BAFormatAll_NodeType)
	{
		// TODO: Add setting to allow for user-defined columns
		FormatAllColumns = {
			ExtraNodes,
            ActorEvents,
            CustomEvents,
            InputEvents,
            ComponentEvents,
            OtherEvents
        };
	}
	else
	{
		FormatAllColumns = { OtherEvents };
	}

	const auto ExtraRootNodeSorter = [](UEdGraphNode& NodeA, UEdGraphNode& NodeB)
	{
		return FBAUtils::GetPinsByDirection(&NodeA, EGPD_Input).Num() < FBAUtils::GetPinsByDirection(&NodeB, EGPD_Input).Num();
	};
	
	const auto TopMostSorter = [](UEdGraphNode& NodeA, UEdGraphNode& NodeB)
	{
		return NodeA.NodePosY < NodeB.NodePosY;
	};

	bool bHasNodeToFormat = false;

	for (int i = 0; i < FormatAllColumns.Num(); ++i)
	{
		TArray<UEdGraphNode*>& Column = FormatAllColumns[i];
		
		for (UEdGraphNode* Node : Column)
		{
			if (GetMutableDefault<UBASettings>()->bCacheSizeWhenRequired)
			{
				TSet<UEdGraphNode*> NodeTree = FBAUtils::GetNodeTree(Node);
				for (UEdGraphNode* ConnectedNode : NodeTree)
				{
					if (FBAUtils::IsGraphNode(ConnectedNode) && !FBAUtils::IsKnotNode(ConnectedNode) && !GetGraphCache().CachedNodes.Contains(ConnectedNode->NodeGuid))
					{
						PendingSize.Add(ConnectedNode);
					}
				}
			}
		}

		if (!bHasNodeToFormat && Column.Num() > 0)
			bHasNodeToFormat = true;

		// TODO: Handle extra root nodes properly
		if (i == 0 && FormatAllStyle == BAFormatAll_NodeType)
		{
			ExtraNodes.StableSort(ExtraRootNodeSorter);
		}
		else
		{
			Column.Sort(TopMostSorter);
		}
	}

	if (bHasNodeToFormat)
	{
		FormatAllTransaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatAllNodes", "Format All Nodes")));
	}
}

void FBAGraphHandler::ApplyCommentBubbleSetting()
{
	if (UEdGraph* EdGraph = GetFocusedEdGraph())
	{
		for (UEdGraphNode* Node : EdGraph->Nodes)
		{
			Node->bCommentBubblePinned = GetMutableDefault<UBASettings>()->bSetAllCommentBubblePinned;
		}
	}
}

int32 FBAGraphHandler::GetNumberOfPendingNodesToCache() const
{
	return PendingSize.Num();
}

void FBAGraphHandler::ClearCache()
{
	PendingSize.Reset();
	PendingFormatting.Reset();
	SeenNodes.Reset();
	Delay_ViewportZoomIn = 0;
	TicksOnFocusedNode = 0;
	FocusedNode = nullptr;
	bFullyZoomed = false;
	CachedGraphEditor.Pin()->SetViewLocation(ViewCache, ZoomCache);
}

void FBAGraphHandler::ClearFormatters()
{
	FormatterMap.Empty();
}

TSharedPtr<FFormatterInterface> FBAGraphHandler::FormatNodes(UEdGraphNode* Node, bool bUsingFormatAll)
{	
	if (!GetGraphPanel().IsValid())
	{
		return nullptr;
	}

	if (!FBAUtils::IsGraphNode(Node))
	{
		return nullptr;
	}

	UEdGraph* EdGraph = GetFocusedEdGraph();
	if (EdGraph == nullptr)
	{
		return nullptr;
	}

	if (FBlueprintEditorUtils::IsGraphReadOnly(EdGraph))
		return nullptr;

	TSharedPtr<FFormatterInterface> Formatter = nullptr;

	const bool bCheckSelectedNode = !bUsingFormatAll; // don't check selected node if we are running format all command
	UEdGraphNode* NodeToFormat = GetRootNode(Node, FormatterParameters.NodesToFormat, bCheckSelectedNode);

	const FName GraphClassName = EdGraph->GetClass()->GetFName();
	if (GetMutableDefault<UBASettings>()->UseBlueprintFormattingForTheseGraphs.Contains(GraphClassName))
	{
		if (FormatterMap.Contains(NodeToFormat) && GetMutableDefault<UBASettings>()->bEnableFasterFormatting)
		{
			Formatter = FormatterMap[NodeToFormat];
		}
		else
		{
			Formatter = MakeShared<FEdGraphFormatter>(SharedThis(this), FormatterParameters);
			FormatterMap.Add(NodeToFormat, Formatter);
		}
	}
	else
	{
		auto GraphType = FBAUtils::GetBAGraphType(EdGraph).GetValue();
		switch (GraphType)
		{
		case BAGraphType_BehaviorTree:
			Formatter = MakeShared<FBehaviorTreeGraphFormatter>(SharedThis(this));
			break;
		case BAGraphType_MaterialGraph:
			Formatter = MakeShared<FMaterialGraphFormatter>(SharedThis(this));
			break;
		case BAGraphType_NiagaraGraph:
			Formatter = MakeShared<FNiagaraGraphFormatter>(SharedThis(this));
			break;
		case BAGraphType_AnimGraph:
			Formatter = MakeShared<FAnimationGraphFormatter>(SharedThis(this));
			break;
		case BAGraphType_SoundCue:
			Formatter = MakeShared<FSoundCueGraphFormatter>(SharedThis(this));
			break;
		default:
		{
			const FString GraphName = GraphClassName.ToString();
			UE_LOG(LogBlueprintAssist, Log, 
				TEXT("Formatting for graph class %s not supported. Enable formatting by adding %s to the 'UseBlueprintFormattingForTheseGraphs' list in the settings"), *GraphName, *GraphName);
		}
		}
	}

	if (Formatter.IsValid())
	{
		//const double StartTime = FPlatformTime::Seconds();
		Formatter->FormatNode(NodeToFormat);
		//const double EndTime = FPlatformTime::Seconds();

		//UE_LOG(LogBlueprintAssist, Warning, TEXT("Formatting Took %f seconds for node %s on graph %s"),
		//       EndTime - StartTime,
		//       *FBAUtils::GetNodeName(Node),
		//       *GraphClassName.ToString());
	}

	return Formatter;
}

void FBAGraphHandler::CancelProcessingNodeSizes()
{
	// fill all pending nodes with size 300, 150
	for (UEdGraphNode* Node : PendingSize)
	{
		GetGraphCache().CachedNodes.Add(Node->NodeGuid, FVector2D(300, 150));
	}

	PendingSize.Reset();
	PendingFormatting.Reset();
}
