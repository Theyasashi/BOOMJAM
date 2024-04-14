// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistInputProcessor.h"

#include "BlueprintAssistModule.h"
#include "BlueprintAssistUtils.h"
#include "BlueprintAssistCommands.h"
#include "../GraphFormatters/GraphFormatterTypes.h"
#include "../GraphFormatters/FormatterInterface.h"
#include "../BlueprintAssistWidgets/LinkPinMenu.h"
#include "../BlueprintAssistWidgets/GoToSymbolMenu.h"
#include "../BlueprintAssistWidgets/GoToSettingsMenu.h"
#include "../BlueprintAssistWidgets/FocusSearchBoxMenu.h"
#include "../BlueprintAssistWidgets/VariableSelectorMenu.h"
#include "../BlueprintAssistWidgets/AddSymbolMenu.h"
#include "../BlueprintAssistWidgets/EditDetailsMenu.h"

#include "BlueprintAssistGraphHandler.h"
#include "BlueprintAssistTabHandler.h"
#include "BlueprintAssistSettings.h"

#include "SGraphPanel.h"
#include "SNodePanel.h"

#include "EdGraph/EdGraph.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphNode_Comment.h"
#include "EdGraphSchema_K2_Actions.h"
#include "EdGraphUtilities.h"
#include "Editor/BlueprintGraph/Classes/K2Node_Knot.h"

#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/Input/SEditableTextBox.h"

#include "Framework/Application/SlateApplication.h"
#include "Framework/Notifications/NotificationManager.h"

#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

#include "K2Node_Event.h"
#include "K2Node_Variable.h"
#include "K2Node_CustomEvent.h"
#include "K2Node_VariableGet.h"
#include "K2Node_CallFunction.h"
#include "K2Node_CallFunctionOnMember.h"
#include "K2Node_Literal.h"
#include "K2Node_ActorBoundEvent.h"
#include "K2Node_ComponentBoundEvent.h"

#include "ScopedTransaction.h"
#include "Templates/SharedPointer.h"
#include "Editor.h"
#include "ISettingsModule.h"
#include "BlueprintAssist/BlueprintAssistWidgets/BlueprintAssistHotkeyMenu.h"
#include "BlueprintAssist/BlueprintAssistWidgets/CreateVariableMenu.h"

//~ Begin COPY OF BlueprintEditor.cpp FUpdatePastedNodes struct
struct FUpdatePastedNodes_Copy
{
	TSet<UK2Node_VariableGet*> AddedTargets;
	TSet<UK2Node_CallFunction*> AddedFunctions;
	TSet<UK2Node_Literal*> ReplacedTargets;
	TSet<UK2Node_CallFunctionOnMember*> ReplacedFunctions;

	UClass* CurrentClass;
	UEdGraph* Graph;
	TSet<UEdGraphNode*>& PastedNodes;
	const UEdGraphSchema_K2* K2Schema;

	FUpdatePastedNodes_Copy(
		UClass* InCurrentClass,
		TSet<UEdGraphNode*>& InPastedNodes,
		UEdGraph* InDestinationGraph)
		: CurrentClass(InCurrentClass)
		, Graph(InDestinationGraph)
		, PastedNodes(InPastedNodes)
		, K2Schema(GetDefault<UEdGraphSchema_K2>())
	{
		check(InCurrentClass && InDestinationGraph && K2Schema);
	}

	/**
	 *	Replace UK2Node_CallFunctionOnMember called on actor with a UK2Node_CallFunction.
	 *	When the blueprint has the member.
	 */
	void ReplaceAll()
	{
		for (UEdGraphNode* PastedNode : PastedNodes)
		{
			if (UK2Node_CallFunctionOnMember* CallOnMember = Cast<UK2Node_CallFunctionOnMember>(
				PastedNode))
			{
				if (UEdGraphPin* TargetInPin = CallOnMember->FindPin(UEdGraphSchema_K2::PN_Self))
				{
					const UClass* TargetClass = Cast<const UClass>(
						TargetInPin->PinType.PinSubCategoryObject.Get());

					const bool bTargetIsNullOrSingleLinked =
						TargetInPin->LinkedTo.Num() == 1 ||
						(!TargetInPin->LinkedTo.Num() && !TargetInPin->DefaultObject);

					const bool bCanCurrentBlueprintReplace = TargetClass
						&& CurrentClass->IsChildOf(TargetClass)
						// If current class if of the same type, it has the called member
						&& (!CallOnMember->MemberVariableToCallOn.IsSelfContext() && (TargetClass !=
							CurrentClass))
						// Make sure the class isn't self, using a explicit check in case the class hasn't been compiled since the member was added
						&& bTargetIsNullOrSingleLinked;

					if (bCanCurrentBlueprintReplace)
					{
						UEdGraphNode* TargetNode = TargetInPin->LinkedTo.Num()
							? TargetInPin->LinkedTo[0]->GetOwningNode()
							: nullptr;
						UK2Node_Literal* TargetLiteralNode = Cast<UK2Node_Literal>(TargetNode);

						const bool bPastedNodeShouldBeReplacedWithTarget = TargetLiteralNode
							&& !TargetLiteralNode->GetObjectRef()
							//The node delivering target actor is invalid
							&& PastedNodes.Contains(TargetLiteralNode);

						const bool bPastedNodeShouldBeReplacedWithoutTarget = !TargetNode || !
							PastedNodes.Contains(
								TargetNode);

						if (bPastedNodeShouldBeReplacedWithTarget ||
							bPastedNodeShouldBeReplacedWithoutTarget)
						{
							Replace(TargetLiteralNode, CallOnMember);
						}
					}
				}
			}
		}

		UpdatePastedCollection();
	}

private:

	void UpdatePastedCollection()
	{
		for (UK2Node_Literal* ReplacedTarget : ReplacedTargets)
		{
			if (ReplacedTarget && ReplacedTarget->GetValuePin() && !ReplacedTarget
			                                                        ->GetValuePin()->LinkedTo.Num())
			{
				PastedNodes.Remove(ReplacedTarget);
				Graph->RemoveNode(ReplacedTarget);
			}
		}
		for (UK2Node_CallFunctionOnMember* ReplacedFunction : ReplacedFunctions)
		{
			PastedNodes.Remove(ReplacedFunction);
			Graph->RemoveNode(ReplacedFunction);
		}
		for (UK2Node_VariableGet* AddedTarget : AddedTargets)
		{
			PastedNodes.Add(AddedTarget);
		}
		for (UK2Node_CallFunction* AddedFunction : AddedFunctions)
		{
			PastedNodes.Add(AddedFunction);
		}
	}

	bool MoveAllLinksExeptSelf(UK2Node* NewNode, UK2Node* OldNode)
	{
		bool bResult = true;
		for (UEdGraphPin* OldPin : OldNode->Pins)
		{
			if (OldPin && (OldPin->PinName != UEdGraphSchema_K2::PN_Self))
			{
				UEdGraphPin* NewPin = NewNode->FindPin(OldPin->PinName);
				if (NewPin)
				{
					if (!K2Schema->MovePinLinks(*OldPin, *NewPin).CanSafeConnect())
					{
						UE_LOG(
							LogBlueprint,
							Error,
							TEXT("FUpdatePastedNodes: Cannot connect pin '%s' node '%s'"),
							*OldPin->PinName.ToString(),
							*OldNode->GetName());
						bResult = false;
					}
				}
				else
				{
					UE_LOG(
						LogBlueprint,
						Error,
						TEXT("FUpdatePastedNodes: Cannot find pin '%s'"),
						*OldPin->PinName.ToString());
					bResult = false;
				}
			}
		}
		return bResult;
	}

	void InitializeNewNode(
		UK2Node* NewNode,
		UK2Node* OldNode,
		float NodePosX = 0.0f,
		float NodePosY = 0.0f)
	{
		NewNode->NodePosX = OldNode ? OldNode->NodePosX : NodePosX;
		NewNode->NodePosY = OldNode ? OldNode->NodePosY : NodePosY;
		NewNode->SetFlags(RF_Transactional);
		Graph->AddNode(NewNode, false, false);
		NewNode->PostPlacedNewNode();
		NewNode->AllocateDefaultPins();
	}

	bool Replace(UK2Node_Literal* OldTarget, UK2Node_CallFunctionOnMember* OldCall)
	{
		bool bResult = true;
		check(OldCall);

		UK2Node_VariableGet* NewTarget = nullptr;
#if ENGINE_MINOR_VERSION >= 25
		const FProperty* Property = OldCall->MemberVariableToCallOn.ResolveMember<FProperty>();
#else
		const UProperty* Property = OldCall->MemberVariableToCallOn.ResolveMember<UProperty>();
#endif
		
		for (UK2Node_VariableGet* AddedTarget : AddedTargets)
		{
#if ENGINE_MINOR_VERSION >= 25
			if (AddedTarget && (Property == AddedTarget->VariableReference.ResolveMember<FProperty>(CurrentClass)))
#else
			if (AddedTarget && (Property == AddedTarget->VariableReference.ResolveMember<UProperty>(CurrentClass)))
#endif
			{
				NewTarget = AddedTarget;
				break;
			}
		}

		if (!NewTarget)
		{
			NewTarget = NewObject<UK2Node_VariableGet>(Graph);
			check(NewTarget);
#if ENGINE_MINOR_VERSION < 24
			NewTarget->SetFromProperty(Property, true);
#else
			NewTarget->SetFromProperty(Property, true, Property->GetOwnerClass());
#endif
			AddedTargets.Add(NewTarget);
			const float AutoNodeOffsetX = 160.0f;
			InitializeNewNode(
				NewTarget,
				OldTarget,
				OldCall->NodePosX - AutoNodeOffsetX,
				OldCall->NodePosY);
		}

		if (OldTarget)
		{
			ReplacedTargets.Add(OldTarget);
		}

		UK2Node_CallFunction* NewCall = NewObject<UK2Node_CallFunction>(Graph);
		check(NewCall);
		NewCall->SetFromFunction(OldCall->GetTargetFunction());
		InitializeNewNode(NewCall, OldCall);
		AddedFunctions.Add(NewCall);

		if (!MoveAllLinksExeptSelf(NewCall, OldCall))
		{
			bResult = false;
		}

		if (NewTarget)
		{
			UEdGraphPin* SelfPin = NewCall->FindPinChecked(UEdGraphSchema_K2::PN_Self);
			if (!K2Schema->TryCreateConnection(SelfPin, NewTarget->GetValuePin()))
			{
				UE_LOG(LogBlueprint, Error, TEXT("FUpdatePastedNodes: Cannot connect new self."));
				bResult = false;
			}
		}

		OldCall->BreakAllNodeLinks();

		ReplacedFunctions.Add(OldCall);
		return bResult;
	}
};

//~ End COPY OF BlueprintEditor.cpp FUpdatePastedNodes struct

FBAInputProcessor::FBAInputProcessor()
{
	TabHandler = MakeShareable(new FBATabHandler());
	GlobalCommands = MakeShareable(new FUICommandList());
	GraphCommands = MakeShareable(new FUICommandList());
	GraphReadOnlyCommands = MakeShareable(new FUICommandList());
	SingleNodeCommands = MakeShareable(new FUICommandList());
	MultipleNodeCommands = MakeShareable(new FUICommandList());
	MultipleNodeCommandsIncludingComments = MakeShareable(new FUICommandList());
	PinCommands = MakeShareable(new FUICommandList());
	TabCommands = MakeShareable(new FUICommandList());
	ActionMenuCommands = MakeShareable(new FUICommandList());
	PinEditCommands = MakeShareable(new FUICommandList());
	CreateGraphEditorCommands();
}

FBAInputProcessor::~FBAInputProcessor()
{
	SavedNodeToReplace = nullptr;
}

void FBAInputProcessor::Cleanup()
{
	TabHandler->Cleanup();
	SavedNodeToReplace = nullptr;
}

void FBAInputProcessor::Tick(
	const float DeltaTime,
	FSlateApplication& SlateApp,
	TSharedRef<ICursor> Cursor)
{
	if (GEditor->bIsSimulatingInEditor || GEditor->PlayWorld != nullptr)
		return;

	TabHandler->Tick(DeltaTime);
}

bool FBAInputProcessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	// TODO: Perhaps implement a NavigationConfig, so users can't change focus on widgets
	// See FSlateApplication::SetNavigationConfig

	if (GEditor->bIsSimulatingInEditor || GEditor->PlayWorld != nullptr)
		return false;

	if (SlateApp.IsInitialized())
	{
		GraphHandler = TabHandler->GetGraphHandler();

		if (GlobalCommands->ProcessCommandBindings(
			InKeyEvent.GetKey(),
			FSlateApplication::Get().GetModifierKeys(),
			InKeyEvent.IsRepeat()))
			return true;

		if (!GraphHandler.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Invalid graph handler"));
			return false;
		}

		// cancel processing node sizes and when you press esc
		if (InKeyEvent.GetKey() == EKeys::Escape)
		{
			if (GraphHandler->IsCalculatingNodeSize())
			{
				GraphHandler->CancelProcessingNodeSizes();
				GraphHandler->ResetTransactions();
			}
		}

		TSharedPtr<SDockTab> Tab = GraphHandler->GetTab();
		if (!Tab.IsValid() || !Tab->IsForeground())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Tab invalid or not foreground"));
			return false;
		}

		TSharedPtr<SWidget> KeyboardFocusedWidget = SlateApp.GetKeyboardFocusedWidget();
		if (KeyboardFocusedWidget.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("%s | %s"), *KeyboardFocusedWidget->GetTypeAsString(), *KeyboardFocusedWidget->ToString());
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("No keyboard focused widget!"));
		}

		// try process graph action menu hotkeys
		TSharedPtr<SWindow> Menu = SlateApp.GetActiveTopLevelWindow();
		if (Menu.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Top Level window %s | %s"), *Menu->GetTitle().ToString(), *Menu->ToString());

			if (Menu->GetContent()->GetTypeAsString().Contains("SMenuContentWrapper"))
			{
				TSharedPtr<SWidget> ActionMenu = FBAUtils::GetChildWidget(Menu, "SGraphActionMenu");
				if (ActionMenu.IsValid())
				{
					//UE_LOG(LogTemp, Warning, TEXT("Processing commands for action menu"));

					if (ActionMenuCommands->ProcessCommandBindings(
						InKeyEvent.GetKey(),
						FSlateApplication::Get().GetModifierKeys(),
						InKeyEvent.IsRepeat()))
						return true;
				}
			}
		}

		// get the keyboard focused widget
		if (!Menu.IsValid() || !KeyboardFocusedWidget.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Focus graph panel"));

			TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
			SlateApp.SetKeyboardFocus(GraphPanel);
			KeyboardFocusedWidget = GraphPanel;
		}

		// process commands for when you are editing a user input widget
		if (FBAUtils::IsUserInputWidget(KeyboardFocusedWidget))
		{
			if (FBAUtils::GetParentWidgetOfType(KeyboardFocusedWidget, "SGraphPin").IsValid())
			{
				if (PinEditCommands->ProcessCommandBindings(
					InKeyEvent.GetKey(),
					SlateApp.GetModifierKeys(),
					InKeyEvent.IsRepeat()))
					return true;
			}

			if (InKeyEvent.GetKey() == EKeys::Escape)
			{
				SlateApp.SetKeyboardFocus(GraphHandler->GetGraphPanel());
			}

			return false;
		}

		// process commands for when the tab is open
		if (TabCommands->ProcessCommandBindings(
			InKeyEvent.GetKey(),
			SlateApp.GetModifierKeys(),
			InKeyEvent.IsRepeat()))
			return true;

		//UE_LOG(LogTemp, Warning, TEXT("Process tab commands"));

		if (!GraphHandler->IsWindowActive())
		{
			//TSharedPtr<SWindow> CurrentWindow = FSlateApplication::Get().GetActiveTopLevelWindow();
			//const FString CurrentWindowStr = CurrentWindow.IsValid()
			//	? CurrentWindow->GetTitle().ToString()
			//	: "nullptr";

			//TSharedPtr<SWindow> GHWindow = GraphHandler->GetOrFindWindow();
			//FString GHWindowStr = GHWindow.IsValid() ? GHWindow->GetTitle().ToString() : "Nullptr";
			//UE_LOG(
			//	LogTemp,
			//	Warning,
			//	TEXT("Graph Handler window is not active %s current window | GH Window %s"),
			//	*CurrentWindowStr,
			//	*GHWindowStr);
			return false;
		}

		
		// process commands for when the graph exists but is read only
		if (GraphReadOnlyCommands->ProcessCommandBindings(
            InKeyEvent.GetKey(),
            SlateApp.GetModifierKeys(),
            InKeyEvent.IsRepeat()))
		{
			return true;
		}

		// skip all other graph commands if read only
		if (GraphHandler->IsGraphReadOnly())
		{
			return false;
		}
		
		// process commands for when the graph
		if (GraphCommands->ProcessCommandBindings(
			InKeyEvent.GetKey(),
			SlateApp.GetModifierKeys(),
			InKeyEvent.IsRepeat()))
			return true;

		// process commands for which require a node to be selected
		if (GraphHandler->GetSelectedPin() != nullptr)
		{
			if (PinCommands->ProcessCommandBindings(
				InKeyEvent.GetKey(),
				SlateApp.GetModifierKeys(),
				InKeyEvent.IsRepeat()))
				return true;
		}

		// process commands for which require a single node to be selected
		if (GraphHandler->GetSelectedNode() != nullptr)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Process node commands"));
			if (SingleNodeCommands->ProcessCommandBindings(
				InKeyEvent.GetKey(),
				SlateApp.GetModifierKeys(),
				InKeyEvent.IsRepeat()))
				return true;

			if (InKeyEvent.GetKey() == EKeys::Escape)
			{
				GraphHandler->GetGraphPanel()->SelectionManager.ClearSelectionSet();
				return true;
			}
		}

		// process commands for which require multiple nodes to be selected
		if (GraphHandler->GetSelectedNodes().Num() > 0)
		{
			if (MultipleNodeCommands->ProcessCommandBindings(
				InKeyEvent.GetKey(),
				SlateApp.GetModifierKeys(),
				InKeyEvent.IsRepeat()))
				return true;

			if (InKeyEvent.GetKey() == EKeys::Escape)
			{
				GraphHandler->GetGraphPanel()->SelectionManager.ClearSelectionSet();
				return true;
			}
		}

		// process commands for which require multiple nodes (incl comments) to be selected
		if (GraphHandler->GetSelectedNodes(true).Num() > 0)
		{
			if (MultipleNodeCommandsIncludingComments->ProcessCommandBindings(
				InKeyEvent.GetKey(),
				SlateApp.GetModifierKeys(),
				InKeyEvent.IsRepeat()))
				return true;

			if (InKeyEvent.GetKey() == EKeys::Escape)
			{
				GraphHandler->GetGraphPanel()->SelectionManager.ClearSelectionSet();
				return true;
			}
		}
	}
	else
	{
		UE_LOG(LogBlueprintAssist, Error, TEXT("HandleKeyDown: Slate App not initialized"));
	}
	return false;
}

bool FBAInputProcessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		TSharedPtr<FBAGraphHandler> MyGraphHandler = TabHandler->GetGraphHandler();

		if (MyGraphHandler.IsValid())
		{
			TSharedPtr<SGraphPanel> GraphPanel = MyGraphHandler->GetGraphPanel();
			if (MyGraphHandler->GetGraphPanel().IsValid())
			{
				TSharedPtr<SGraphPin> GraphPin = FBAUtils::GetHoveredGraphPin(GraphPanel);
				if (GraphPin.IsValid())
				{
					UEdGraphPin* Pin = GraphPin->GetPinObj();

					TabHandler->GetGraphHandler()->SetSelectedPin(Pin);

					GraphPanel->SelectionManager.SelectSingleNode(Pin->GetOwningNode());
				}

				if (GetMutableDefault<UBASettings>()->bCustomDebug == 100)
				{
					TSharedPtr<SGraphNode> GraphNode = FBAUtils::GetHoveredGraphNode(GraphPanel);
					if (GraphNode.IsValid())
					{
						UEdGraphNode* Node = GraphNode->GetNodeObj();
						FBAUtils::PrintNodeInfo(Node);
					}
				}
			}
		}
	}

	return false;
}

void FBAInputProcessor::CreateGraphEditorCommands()
{
	////////////////////////////////////////////////////////////
	// Single Node Commands
	////////////////////////////////////////////////////////////

	SingleNodeCommands->MapAction(
		FBACommands::Get().ConnectUnlinkedPins,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnSmartWireSelectedNode)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().ZoomToNodeTree,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ZoomToNodeTree)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().DisconnectAllNodeLinks,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DisconnectAllNodeLinks)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().SelectPinUp,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectPinInDirection, 0, -1),
		FCanExecuteAction::CreateRaw(this, &FBAInputProcessor::CanSelectPinInDirection)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().SelectPinDown,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectPinInDirection, 0, 1),
		FCanExecuteAction::CreateRaw(this, &FBAInputProcessor::CanSelectPinInDirection)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().SelectPinLeft,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectPinInDirection, -1, 0),
		FCanExecuteAction::CreateRaw(this, &FBAInputProcessor::CanSelectPinInDirection)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().SelectPinRight,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectPinInDirection, 1, 0),
		FCanExecuteAction::CreateRaw(this, &FBAInputProcessor::CanSelectPinInDirection)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().GetContextMenuForNode,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnGetContextMenuActions, false)
	);

	SingleNodeCommands->MapAction(
		FBACommands::Get().ReplaceNodeWith,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ReplaceNodeWith)
	);

	////////////////////////////////////////////////////////////
	// Multiple Node Commands
	////////////////////////////////////////////////////////////

	MultipleNodeCommands->MapAction(
		FBACommands::Get().FormatNodes,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::FormatNodes)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().FormatNodes_Selectively,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::FormatNodesSelectively)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().FormatNodes_Helixing,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::FormatNodesWithHelixing)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().FormatNodes_LHS,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::FormatNodesWithLHS)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().LinkNodesBetweenWires,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::LinkNodesBetweenWires)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().DisconnectNodeExecution,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DisconnectExecutionOfSelectedNode)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().SwapNodeLeft,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SwapNodeInDirection, EGPD_Input)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().SwapNodeRight,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SwapNodeInDirection, EGPD_Output)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().DeleteAndLink,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DeleteAndLink)
	);

	MultipleNodeCommands->MapAction(
		FBACommands::Get().ToggleNode,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ToggleNodes)
	);

	////////////////////////////////////////////////////////////
	// Multiple Node Including Comments Commands
	////////////////////////////////////////////////////////////

	MultipleNodeCommandsIncludingComments->MapAction(
		FBACommands::Get().RefreshNodeSizes,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::RefreshNodeSizes)
	);
	
	////////////////////////////////////////////////////////////
	// Pin Commands
	////////////////////////////////////////////////////////////

	PinCommands->MapAction(
		FBACommands::Get().GetContextMenuForPin,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnGetContextMenuActions, true)
	);

	PinCommands->MapAction(
		FBACommands::Get().LinkToHoveredPin,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::LinkToHoveredPin)
	);

	PinCommands->MapAction(
		FBACommands::Get().LinkPinMenu,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenPinLinkMenu)
	);

	PinCommands->MapAction(
		FBACommands::Get().DuplicateNodeForEachLink,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DuplicateNodeForEachLink)
	);

	PinCommands->MapAction(
		FBACommands::Get().EditSelectedPinValue,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnEditSelectedPinValue)
	);

	////////////////////////////////////////////////////////////
	// Tab Commands
	////////////////////////////////////////////////////////////

	TabCommands->MapAction(
		FBACommands::Get().SelectNodeUp,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectAnyNodeInDirection, 0, -1)
	);

	TabCommands->MapAction(
		FBACommands::Get().SelectNodeDown,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectAnyNodeInDirection, 0, 1)
	);

	TabCommands->MapAction(
		FBACommands::Get().SelectNodeLeft,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectAnyNodeInDirection, -1, 0)
	);

	TabCommands->MapAction(
		FBACommands::Get().SelectNodeRight,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::SelectAnyNodeInDirection, 1, 0)
	);

	TabCommands->MapAction(
		FBACommands::Get().ShiftCameraUp,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ShiftCameraInDirection, 0, -1)
	);

	TabCommands->MapAction(
		FBACommands::Get().ShiftCameraDown,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ShiftCameraInDirection, 0, 1)
	);

	TabCommands->MapAction(
		FBACommands::Get().ShiftCameraLeft,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ShiftCameraInDirection, -1, 0)
	);

	TabCommands->MapAction(
		FBACommands::Get().ShiftCameraRight,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::ShiftCameraInDirection, 1, 0)
	);

	TabCommands->MapAction(
		FBACommands::Get().GoToInGraph,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenGoToSymbolMenu)
	);

	////////////////////////////////////////////////////////////
	// Graph Commands
	////////////////////////////////////////////////////////////

	GraphCommands->MapAction(
		FBACommands::Get().FormatAllEvents,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnFormatAllEvents)
	);

	GraphCommands->MapAction(
		FBACommands::Get().OpenContextMenu,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnOpenContextMenu)
	);

	GraphCommands->MapAction(
		FBACommands::Get().VariableSelectorMenu,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenVariableSelectorMenu)
	);

	GraphCommands->MapAction(
		FBACommands::Get().AddSymbolMenu,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenCreateSymbolMenu)
	);

	GraphCommands->MapAction(
        FBACommands::Get().AddVariableMenu,
        FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenAddVariableMenu)
    );
	
	GraphCommands->MapAction(
		FBACommands::Get().DisconnectPinLink,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DisconnectPinOrWire)
	);

	GraphCommands->MapAction(
        FBACommands::Get().SplitPin,
        FExecuteAction::CreateRaw(this, &FBAInputProcessor::SplitPin)
    );

	GraphCommands->MapAction(
		FBACommands::Get().RecombinePin,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::RecombinePin)
	);

	GraphCommands->MapAction(
		FBACommands::Get().CreateRerouteNode,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::CreateRerouteNode)
	);

	////////////////////////////////////////////////////////////
	// Graph Read Only Commands
	////////////////////////////////////////////////////////////
	
	GraphReadOnlyCommands->MapAction(
		FBACommands::Get().DebugPrintGraphInfo,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::DebugPrintGraphUnderCursor)
	);
	
	////////////////////////////////////////////////////////////
	// Global Commands
	////////////////////////////////////////////////////////////

	GlobalCommands->MapAction(
		FBACommands::Get().FocusSearchBox,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenFocusSearchBoxMenu)
	);

	GlobalCommands->MapAction(
		FBACommands::Get().EditDetailsMenu,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenEditDetailsMenu)
	);

	GlobalCommands->MapAction(
		FBACommands::Get().GoToSettings,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenGoToSettingsMenu)
	);

	GlobalCommands->MapAction(
        FBACommands::Get().OpenBlueprintAssistHotkeySheet,
        FExecuteAction::CreateRaw(this, &FBAInputProcessor::OpenBlueprintAssistHotkeyMenu)
    );
	
	////////////////////////////////////////////////////////////
	// Action Menu Commands
	////////////////////////////////////////////////////////////

	ActionMenuCommands->MapAction(
		FBACommands::Get().ToggleContextSensitive,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnToggleActionMenuContextSensitive)
	);

	////////////////////////////////////////////////////////////
	// Pin Edit Commands
	////////////////////////////////////////////////////////////

	PinEditCommands->MapAction(
		FBACommands::Get().EditSelectedPinValue,
		FExecuteAction::CreateRaw(this, &FBAInputProcessor::OnEditSelectedPinValue)
	);
}

void FBAInputProcessor::LinkToHoveredPin()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();
	if (SelectedPin != nullptr)
	{
		TSharedPtr<SGraphPin> HoveredPin = FBAUtils::GetHoveredGraphPin(GraphPanel);
		if (HoveredPin.IsValid())
		{
			const FScopedTransaction Transaction(
				NSLOCTEXT("UnrealEd", "LinkToHoveredPin", "Link To Hovered Pin"));

			if (FBAUtils::CanConnectPins(SelectedPin, HoveredPin->GetPinObj(), true, false))
			{
				FBAUtils::TryLinkPins(SelectedPin, HoveredPin->GetPinObj());
			}
		}
	}
}

void FBAInputProcessor::LinkNodesBetweenWires()
{
	if (!GraphHandler.IsValid())
		return;

	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (!Graph)
		return;
	
	TSharedPtr<SGraphPin> GraphPinForHoveredWire = FBAUtils::GetHoveredGraphPin(
		GraphHandler->GetGraphPanel());
	if (!GraphPinForHoveredWire.IsValid())
		return;

	UEdGraphPin* PinForHoveredWire = GraphPinForHoveredWire->GetPinObj();
	if (PinForHoveredWire == nullptr)
		return;

	TArray<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes().Array();

	if (SelectedNodes.Num() == 0)
		return;

	const auto LeftMostSort = [](const UEdGraphNode& NodeA, const UEdGraphNode& NodeB)
	{
		return NodeA.NodePosX < NodeB.NodePosX;
	};
	SelectedNodes.Sort(LeftMostSort);

	const auto IsSelected = [&SelectedNodes](UEdGraphNode* Node)
	{
		return SelectedNodes.Contains(Node);
	};

	UEdGraphNode* LeftMostNode =
		FBAUtils::GetTopMostWithFilter(SelectedNodes[0], EGPD_Input, IsSelected);

	UEdGraphNode* RightMostNode =
		FBAUtils::GetTopMostWithFilter(SelectedNodes[0], EGPD_Output, IsSelected);

	TSharedPtr<FScopedTransaction> Transaction =
		MakeShareable(
			new FScopedTransaction(
				NSLOCTEXT("UnrealEd", "LinkNodesBetweenWires", "Link Nodes Between Wires")));

	UEdGraphNode* First = PinForHoveredWire->Direction == EGPD_Output
		? LeftMostNode
		: RightMostNode;

	bool bCancelTransaction = true;

	TArray<FPinLink> PendingLinks;
	PendingLinks.Reserve(2);

	for (UEdGraphPin* Pin : First->Pins)
	{
		if (FBAUtils::CanConnectPins(PinForHoveredWire, Pin, true, false, false))
		{
			PendingLinks.Add(FPinLink(Pin, PinForHoveredWire));
			break;
		}
	}

	UEdGraphPin* ConnectedPin
		= PinForHoveredWire->LinkedTo.Num() > 0
		? PinForHoveredWire->LinkedTo[0]
		: nullptr;

	if (ConnectedPin != nullptr)
	{
		UEdGraphNode* ConnectedNode =
			PinForHoveredWire->Direction == EGPD_Output ? RightMostNode : LeftMostNode;

		for (UEdGraphPin* Pin : ConnectedNode->Pins)
		{
			if (FBAUtils::CanConnectPins(ConnectedPin, Pin, true, false, false))
			{
				PendingLinks.Add(FPinLink(Pin, ConnectedPin));
				break;
			}
		}
	}

	FEdGraphFormatterParameters FormatterParams;
	if (FBAUtils::GetFormatterSettings(Graph).AutoFormatting == BAAutoFormat_FormatSingleConnected)
	{
		FormatterParams.NodesToFormat.Append(SelectedNodes);
		FormatterParams.NodesToFormat.Add(PinForHoveredWire->GetOwningNode());
	}

	for (const FPinLink& Link : PendingLinks)
	{
		Link.From->BreakAllPinLinks();
		
		const bool bMadeLink = FBAUtils::TryCreateConnection(Link.From, Link.To);
		if (bMadeLink)
		{
			if (FBAUtils::GetFormatterSettings(Graph).AutoFormatting != BAAutoFormat_Never)
			{
				GraphHandler->AddPendingFormatNodes(Link.GetFromNode(), Transaction, FormatterParams);
				GraphHandler->AddPendingFormatNodes(Link.GetToNode(), Transaction, FormatterParams);
			}

			bCancelTransaction = false;
		}
	}

	if (bCancelTransaction)
	{
		Transaction->Cancel();
	}
}

void FBAInputProcessor::CreateContextMenuFromPin(
	UEdGraphPin* Pin,
	const FVector2D& MenuLocation,
	const FVector2D& NodeLocation) const
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	TArray<UEdGraphPin*> DragFromPins;
	DragFromPins.Add(Pin);
	TSharedPtr<SWidget> Widget = GraphPanel->SummonContextMenu(
		MenuLocation,
		NodeLocation,
		nullptr,
		nullptr,
		DragFromPins);

	FSlateApplication::Get().SetKeyboardFocus(Widget);
}

void FBAInputProcessor::OpenPinLinkMenu()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	UEdGraphPin* Pin = GraphHandler->GetSelectedPin();
	check(Pin != nullptr)

	TSharedRef<SLinkPinMenu> Widget =
		SNew(SLinkPinMenu, SharedThis(this))
		.SourcePin(Pin)
		.GraphHandler(GraphHandler);

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		GraphPanel->AsShared(),
		FWidgetPath(),
		Widget,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = Widget->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenGoToSymbolMenu()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	if (!GraphEditor.IsValid())
		return;

	UBlueprint* Blueprint = GraphHandler->GetBlueprint();
	if (Blueprint == nullptr)
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	TSharedRef<SGoToSymbolMenu> Widget =
		SNew(SGoToSymbolMenu, SharedThis(this))
		.GraphHandler(GraphHandler)
		.NodeLocation(GraphEditor->GetPasteLocation())
		.MenuLocation(CursorPos);

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		GraphPanel->AsShared(),
		FWidgetPath(),
		Widget,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = Widget->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenGoToSettingsMenu()
{
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().GetActiveTopLevelWindow();

	TSharedRef<SGoToSettingsMenu> Widget = SNew(SGoToSettingsMenu, SharedThis(this));

	FVector2D WindowPosition = FSlateApplication::Get().GetCursorPos();
	if (ParentWindow.IsValid())
	{
		FSlateRect ParentMonitorRect = ParentWindow->GetFullScreenInfo();
		const FVector2D MonitorCenter((ParentMonitorRect.Right + ParentMonitorRect.Left) * 0.5f, (ParentMonitorRect.Top + ParentMonitorRect.Bottom) * 0.5f);
		WindowPosition = MonitorCenter - Widget->WidgetSize * 0.5f;
	}

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		ParentWindow.ToSharedRef(),
		FWidgetPath(),
		Widget,
		WindowPosition,
		FPopupTransitionEffect(FPopupTransitionEffect::None)
	);
	
	TSharedPtr<SEditableTextBox> FilterBox = Widget->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenFocusSearchBoxMenu()
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!Window.IsValid())
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	TSharedRef<SFocusSearchBoxMenu> SearchBox = SNew(SFocusSearchBoxMenu, SharedThis(this));

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		Window->AsShared(),
		FWidgetPath(),
		SearchBox,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = SearchBox->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenVariableSelectorMenu()
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!Window.IsValid())
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	TSharedRef<SVariableSelectorMenu> SearchBox = SNew(SVariableSelectorMenu, SharedThis(this));

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		Window->AsShared(),
		FWidgetPath(),
		SearchBox,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = SearchBox->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenCreateSymbolMenu()
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!Window.IsValid())
		return;

	TSharedPtr<SWidget> ActionMenuWidget = FBAUtils::GetChildWidget(Window, "SGraphActionMenu");
	if (!ActionMenuWidget.IsValid())
		return;
	
	TSharedPtr<SWidget> WidgetToSearchThrough = FBAUtils::GetChildWidget(
        ActionMenuWidget,
        "SListPanel");

	if (!WidgetToSearchThrough.IsValid())
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	TSharedRef<SAddSymbolMenu> CreatedWidget = SNew(SAddSymbolMenu, SharedThis(this), WidgetToSearchThrough);

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		Window->AsShared(),
		FWidgetPath(),
		CreatedWidget,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = CreatedWidget->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenEditDetailsMenu()
{
	TSharedPtr<SWindow> Window = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!Window.IsValid())
		return;

	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	TSharedRef<SEditDetailsMenu> CreatedWidget = SNew(SEditDetailsMenu, SharedThis(this));

	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
		Window->AsShared(),
		FWidgetPath(),
		CreatedWidget,
		CursorPos,
		FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
	);

	TSharedPtr<SEditableTextBox> FilterBox = CreatedWidget->GetFilterTextBox();
	FSlateApplication::Get().SetKeyboardFocus(FilterBox);
}

void FBAInputProcessor::OpenAddVariableMenu()
{
	TSharedRef<SCreateVariableMenu> Widget = SNew(SCreateVariableMenu, GraphHandler);
	FBAUtils::PushMenuAtCenterOfWindow(Widget, Widget->GetWidgetSize(), Widget->GetWidgetToFocus());
}

void FBAInputProcessor::DuplicateNodeForEachLink() const
{
	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();
	if (SelectedPin == nullptr)
		return;

	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode == nullptr)
		return;

	if (!FBAUtils::IsVarNode(SelectedNode))
	{
		FNotificationInfo Notification(
			FText::FromString(
				"ERROR: Duplicate Node For Each Link currently only supports variable nodes"));
		Notification.ExpireDuration = 3.0f;
		FSlateNotificationManager::Get().AddNotification(Notification);
		return;
	}

	// Find the graph editor with focus
	UEdGraph* DestinationGraph = GraphHandler->GetFocusedEdGraph();
	if (DestinationGraph == nullptr)
		return;

	if (!FBAUtils::IsBlueprintGraph(DestinationGraph))
	{
		UE_LOG(LogBlueprintAssist, Warning, TEXT("Duplicate node for each link is currently only supported for Blueprint graphs"));
		return;
	}

	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(
		new FScopedTransaction(
			NSLOCTEXT("UnrealEd", "DuplicateNodesForEachLink", "Duplicate Node For Each Link")));

	DestinationGraph->Modify();

	// logic from FBlueprintEditor::PasteNodesHere
	UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraph(DestinationGraph);

	FGraphPanelSelectionSet SelectedNodes;
	SelectedNodes.Emplace(SelectedNode);
	SelectedNode->PrepareForCopying();
	FString ExportedText;
	FEdGraphUtilities::ExportNodesToText(SelectedNodes, /*out*/ ExportedText);

	struct FLocal
	{
		static void DeleteKnotsAndGetLinkedPins(
			UEdGraphPin* InPin,
			TArray<UEdGraphPin*>& LinkedPins)
		{
			/** Iterate across all linked pins */
			TArray<UEdGraphPin*> LinkedCopy = InPin->LinkedTo;
			for (UEdGraphPin* LinkedPin : LinkedCopy)
			{
				UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();

				if (FBAUtils::IsKnotNode(LinkedNode))
				{
					for (UEdGraphPin* Pin : FBAUtils::GetPinsByDirection(
						     LinkedNode,
						     InPin->Direction))
					{
						DeleteKnotsAndGetLinkedPins(Pin, LinkedPins);
					}
				}
				else
				{
					LinkedPins.Emplace(LinkedPin);
				}
			}

			/** Delete all connections for each knot node */
			if (UK2Node_Knot* KnotNode = Cast<UK2Node_Knot>(InPin->GetOwningNode()))
			{
				FBAUtils::DisconnectKnotNode(KnotNode);
				FBAUtils::DeleteNode(KnotNode);
			}
		}
	};

	TArray<UEdGraphPin*> LinkedPins;
	FLocal::DeleteKnotsAndGetLinkedPins(SelectedPin, LinkedPins);

	if (LinkedPins.Num() <= 1)
		return;

	bool bNeedToModifyStructurally = false;

	FEdGraphFormatterParameters FormatterParams;

	const auto& AutoFormatting = FBAUtils::GetFormatterSettings(DestinationGraph).AutoFormatting;

	for (UEdGraphPin* LinkedToPin : LinkedPins)
	{
		// duplicate the node for each linked to pin
		SelectedPin->BreakLinkTo(LinkedToPin);

		// Import the nodes
		TSet<UEdGraphNode*> PastedNodes;
		FEdGraphUtilities::ImportNodesFromText(DestinationGraph, ExportedText, /*out*/ PastedNodes);

		UClass* CurrentClass = Blueprint ? Blueprint->GeneratedClass : nullptr;
		if (CurrentClass)
		{
			FUpdatePastedNodes_Copy ReplaceNodes(CurrentClass, PastedNodes, DestinationGraph);
			ReplaceNodes.ReplaceAll();
		}

		for (TSet<UEdGraphNode*>::TIterator It(PastedNodes); It; ++It)
		{
			UEdGraphNode* Node = *It;

			Node->CreateNewGuid();

			UK2Node* K2Node = Cast<UK2Node>(Node);
			if (K2Node != nullptr && K2Node->NodeCausesStructuralBlueprintChange())
			{
				bNeedToModifyStructurally = true;
			}

			UEdGraphPin* ValuePin = FBAUtils::GetPinsByDirection(Node, EGPD_Output)[0];
			ValuePin->MakeLinkTo(LinkedToPin);

			if (AutoFormatting == BAAutoFormat_FormatSingleConnected)
			{
				FormatterParams.NodesToFormat.Add(Node);
			}
		}
	}

	FBlueprintEditorUtils::RemoveNode(Blueprint, SelectedNode, true);

	if (bNeedToModifyStructurally)
	{
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	}
	else
	{
		FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
	}

	// Update UI
	DestinationGraph->NotifyGraphChanged();

	if (AutoFormatting == BAAutoFormat_FormatSingleConnected)
	{
		for (UEdGraphPin* LinkedToPin : LinkedPins)
		{
			FormatterParams.NodesToFormat.Add(LinkedToPin->GetOwningNode());
		}
	}

	for (UEdGraphPin* LinkedToPin : LinkedPins)
	{
		if (AutoFormatting != BAAutoFormat_Never)
		{
			GraphHandler->AddPendingFormatNodes(LinkedToPin->GetOwningNode(), Transaction, FormatterParams);
		}
		else
		{
			Transaction.Reset();
		}
	}
}

void FBAInputProcessor::RefreshNodeSizes() const
{
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes(true);

	auto Graph = GraphHandler->GetFocusedEdGraph();
	
	auto AutoFormatting = FBAUtils::GetFormatterSettings(Graph).AutoFormatting;

	if (SelectedNodes.Num() > 0)
	{
		TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "RefreshNodeSize", "Refresh Node Size")));

		FEdGraphFormatterParameters FormatterParams;

		if (AutoFormatting == BAAutoFormat_FormatSingleConnected)
		{
			TSet<UEdGraphNode*> NodeSet;
			for (UEdGraphNode* Node : SelectedNodes)
			{
				if (FBAUtils::IsGraphNode(Node))
				{
					NodeSet.Add(Node);
					if (UEdGraphNode* Linked = FBAUtils::GetFirstLinkedNodePreferringInput(Node))
					{
						NodeSet.Add(Linked);
					}
				}
			}
			
			FormatterParams.NodesToFormat = NodeSet.Array();
		}
		
		for (UEdGraphNode* Node : SelectedNodes)
		{
			GraphHandler->RefreshNodeSize(Node);

			if (AutoFormatting != BAAutoFormat_Never)
			{
				GraphHandler->AddPendingFormatNodes(Node, Transaction, FormatterParams);
			}
			else
			{
				Transaction->Cancel();
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Commands Event
//////////////////////////////////////////////////////////////////////////

void FBAInputProcessor::OnOpenContextMenu()
{
	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	if (!GraphEditor.IsValid())
		return;

	const FVector2D MenuLocation = FSlateApplication::Get().GetCursorPos();
	const FVector2D SpawnLocation = GraphEditor->GetPasteLocation();

	SavedNodeToReplace = nullptr;

	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();

	if (SelectedPin != nullptr)
	{
		CreateContextMenuFromPin(SelectedPin, MenuLocation, SpawnLocation);
	}
	else
	{
		OpenContextMenu(MenuLocation, SpawnLocation);
	}
}

void FBAInputProcessor::FormatNodes() const
{
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes();
	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatNode", "Format Node")));
	for (UEdGraphNode* Node : SelectedNodes)
	{
		if (FBAUtils::IsGraphNode(Node))
		{
			GraphHandler->AddPendingFormatNodes(Node, Transaction);
		}
	}
}

void FBAInputProcessor::FormatNodesSelectively()
{
	// TODO: Make selective formatting work with formatters other than EdGraph
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes();
	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatOnlySelectedNodes", "Format Only Selected Nodes")));

	if (SelectedNodes.Num() == 1)
	{
		UEdGraphNode* SelectedNode = SelectedNodes.Array()[0];
		
		EEdGraphPinDirection Direction = FBAUtils::IsNodeImpure(SelectedNode) ? EGPD_Output : EGPD_Input;
		
		SelectedNodes = FBAUtils::GetNodeTree(SelectedNode, Direction, true);
	}
	
	for (UEdGraphNode* Node : SelectedNodes)
	{
		if (FBAUtils::IsGraphNode(Node))
		{
			FEdGraphFormatterParameters FormatterParameters;
			FormatterParameters.NodesToFormat = SelectedNodes.Array();
			GraphHandler->AddPendingFormatNodes(Node, Transaction, FormatterParameters);
		}
	}
}

void FBAInputProcessor::FormatNodesWithHelixing() const
{
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes();
	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatNodeHelixing", "Format Node with Helixing")));
	for (UEdGraphNode* Node : SelectedNodes)
	{
		if (FBAUtils::IsGraphNode(Node))
		{
			FEdGraphFormatterParameters FormatterParameters;
			FormatterParameters.OverrideFormattingStyle = MakeShareable(new EBAParameterFormattingStyle(BAParameterFormatting_Helixing));
			GraphHandler->AddPendingFormatNodes(Node, Transaction, FormatterParameters);
		}
	}
}

void FBAInputProcessor::FormatNodesWithLHS() const
{
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes();
	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "FormatNodeLHS", "Format Node with LHS")));
	for (UEdGraphNode* Node : SelectedNodes)
	{
		if (FBAUtils::IsGraphNode(Node))
		{
			FEdGraphFormatterParameters FormatterParameters;
			FormatterParameters.OverrideFormattingStyle = MakeShareable(new EBAParameterFormattingStyle(BAParameterFormatting_LeftSide));
			GraphHandler->AddPendingFormatNodes(Node, Transaction, FormatterParameters);
		}
	}
}

void FBAInputProcessor::SmartWireNode(UEdGraphNode* Node) const
{
	if (!FBAUtils::IsGraphNode(Node))
	{
		return;
	}

	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (!Graph)
		return;

	TSet<UEdGraphNode*> LHSNodes, RHSNodes;
	TSet<UEdGraphPin*> LHSPins, RHSPins;
	FBAUtils::SortNodesOnGraphByDistance(Node, Graph, LHSNodes, RHSNodes, LHSPins, RHSPins);

	TArray<TArray<UEdGraphPin*>> PinsByType;
	TArray<UEdGraphPin*> ExecPins = FBAUtils::GetExecPins(Node);
	TArray<UEdGraphPin*> ParamPins = FBAUtils::GetParameterPins(Node);
	PinsByType.Add(ExecPins);
	PinsByType.Add(ParamPins);
	for (const TArray<UEdGraphPin*>& Pins : PinsByType)
	{
		for (UEdGraphPin* PinA : Pins)
		{
			// skip if pin is hidden or if the pin already is connected
			if (PinA->bHidden || PinA->LinkedTo.Num() > 0 || PinA->Direction == EGPD_MAX)
				continue;

			// check all pins to the left if we are an input pin
			// check all pins to the right if we are an output pin
			bool IsInputPin = PinA->Direction == EGPD_Input;
			for (UEdGraphPin* PinB : IsInputPin ? LHSPins : RHSPins)
			{
				// skip if has connection
				if (PinB->LinkedTo.Num() > 0)
					continue;

				// UE_LOG(LogTemp, Warning, TEXT("Checking pins %s %s"), *FBAUtils::GetPinName(PinA), *FBAUtils::GetPinName(PinB));
				
				//bool bShouldOverrideLink = FBlueprintAssistUtils::IsExecPin(PinA);
				if (!FBAUtils::CanConnectPins(PinA, PinB, false, false, false))
				{
					// UE_LOG(LogTemp, Warning, TEXT("\tSkipping"));
					continue;
				}
				
				TSharedPtr<FScopedTransaction> Transaction = MakeShareable(
					new FScopedTransaction(
						NSLOCTEXT("UnrealEd", "ConnectUnlinkedPins", "Connect Unlinked Pins")
					));

				FBAUtils::TryLinkPins(PinA, PinB);

				if (FBAUtils::GetFormatterSettings(Graph).AutoFormatting != BAAutoFormat_Never)
				{
					FEdGraphFormatterParameters FormatterParams;
					if (FBAUtils::GetFormatterSettings(Graph).AutoFormatting == BAAutoFormat_FormatSingleConnected)
					{
						FormatterParams.NodesToFormat.Add(PinA->GetOwningNode());
						FormatterParams.NodesToFormat.Add(PinB->GetOwningNode());
					}
					
					GraphHandler->AddPendingFormatNodes(PinA->GetOwningNode(), Transaction, FormatterParams);
				}
				else
				{
					Transaction.Reset();
				}

				return;
			}
		}
	}
}

// TODO: unused function maybe merge this with smart wire
void FBAInputProcessor::LinkPinToNearest(
	UEdGraphPin* InPin,
	bool bOverrideLink,
	bool bFilterByDirection,
	float DistLimit) const
{
	if (InPin != nullptr)
	{
		FVector2D InPinPos = FBAUtils::GetPinPos(GraphHandler, InPin);

		// gather all the valid exec pins which we can connect to
		TArray<UEdGraphPin*> ValidPins;
		for (UEdGraphNode* Node : GraphHandler->GetFocusedEdGraph()->Nodes)
		{
			for (UEdGraphPin* Pin : Node->Pins)
			{
				// don't link to the same node
				if (Node == InPin->GetOwningNode())
					continue;

				FVector2D OtherPinPos = FBAUtils::GetPinPos(GraphHandler, Pin);

				// skip all pins further than the distance limit
				if (DistLimit > 0 && DistLimit <= FVector2D::Distance(InPinPos, OtherPinPos))
				{
					continue;
				}

				if (bFilterByDirection)
				{
					if (InPin->Direction == EGPD_Input)
					{
						if (OtherPinPos.X > InPinPos.X)
						{
							continue;
						}
					}
					else if (InPin->Direction == EGPD_Output)
					{
						if (OtherPinPos.X < InPinPos.X)
						{
							continue;
						}
					}
				}

				if (FBAUtils::CanConnectPins(InPin, Pin, bOverrideLink, false))
				{
					ValidPins.Add(Pin);
				}
			}
		}

		if (ValidPins.Num() > 0)
		{
			const auto DistanceSorter = [&](UEdGraphPin& PinA, UEdGraphPin& PinB)
			{
				const float DistA = FVector2D::Distance(InPinPos, FBAUtils::GetPinPos(GraphHandler, &PinA));
				const float DistB = FVector2D::Distance(InPinPos, FBAUtils::GetPinPos(GraphHandler, &PinB));
				return DistA < DistB;
			};
			ValidPins.Sort(DistanceSorter);
			UEdGraphPin* ClosestPin = ValidPins[0];
			FBAUtils::TryLinkPins(InPin, ClosestPin);
		}
	}
}

void FBAInputProcessor::OpenContextMenu(
	const FVector2D& MenuLocation,
	const FVector2D& NodeSpawnPosition) const
{
	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (!Graph)
		return;

	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	if (!GraphEditor.IsValid())
		return;

	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	const TArray<UEdGraphPin*> DummyPins;
	TSharedPtr<SWidget> WidgetToFocus = GraphPanel->SummonContextMenu(
		FSlateApplication::Get().GetCursorPos(),
		NodeSpawnPosition,
		nullptr,
		nullptr,
		DummyPins);

	// Focus the newly created context menu
	if (WidgetToFocus.IsValid())
	{
		FSlateApplication& SlateApp = FSlateApplication::Get();
		SlateApp.SetKeyboardFocus(WidgetToFocus);
	}
}

void FBAInputProcessor::OnSmartWireSelectedNode() const
{
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode == nullptr)
		return;

	//const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "SmartWire", "Smart Wire Node"));
	SmartWireNode(SelectedNode);
}

void FBAInputProcessor::OnFormatAllEvents() const
{
	GraphHandler->FormatAllEvents();
}

void FBAInputProcessor::SelectNodeInDirection(
	const TArray<UEdGraphNode*>& Nodes,
	const int X,
	const int Y,
	const float DistLimit) const
{
	if (Nodes.Num() == 0)
		return;

	TSharedPtr<SGraphPanel> Panel = GraphHandler->GetGraphPanel();
	if (!Panel.IsValid())
		return;

	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (!Graph)
		return;

	// if selected node is null, then use the cursor location
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	const FVector2D StartPosition
		= SelectedNode != nullptr
		? FVector2D(SelectedNode->NodePosX, SelectedNode->NodePosY)
		: Panel->GetPastePosition();

	// filter all nodes on the graph towards our direction
	TArray<UEdGraphNode*> FilteredNodes;
	bool bIsXDirection = X != 0;
	for (UEdGraphNode* Other : Nodes)
	{
		// skip the currently selected
		if (Other == SelectedNode)
			continue;

		// skip comment nodes and knot nodes
		if (!FBAUtils::IsGraphNode(Other))
			continue;

		const float DeltaX = Other->NodePosX - StartPosition.X;
		const float DeltaY = Other->NodePosY - StartPosition.Y;

		if (bIsXDirection)
		{
			if (FMath::Sign(DeltaX) == FMath::RoundToInt(X))
				if (DistLimit <= 0 || (FMath::Abs(DeltaX) < DistLimit && FMath::Abs(DeltaY) < DistLimit * 0.5f))
					FilteredNodes.Add(Other);
		}
		else // y direction
		{
			if (FMath::Sign(DeltaY) == FMath::RoundToInt(Y))
				if (DistLimit <= 0 || (FMath::Abs(DeltaY) < DistLimit && FMath::Abs(DeltaX) < DistLimit * 0.5f))
					FilteredNodes.Add(Other);
		}
	}

	// no nodes found stop
	if (FilteredNodes.Num() == 0)
		return;

	// sort nodes by distance
	const auto& Sorter = [StartPosition, bIsXDirection](UEdGraphNode& A, UEdGraphNode& B)-> bool
	{
		const float XWeight = bIsXDirection ? 1 : 5;
		const float YWeight = bIsXDirection ? 5 : 1;

		float DeltaX = A.NodePosX - StartPosition.X;
		float DeltaY = A.NodePosY - StartPosition.Y;
		const float DistA = XWeight * DeltaX * DeltaX + YWeight * DeltaY * DeltaY;

		DeltaX = B.NodePosX - StartPosition.X;
		DeltaY = B.NodePosY - StartPosition.Y;
		const float DistB = XWeight * DeltaX * DeltaX + YWeight * DeltaY * DeltaY;

		return DistA < DistB;
	};
	FilteredNodes.Sort(Sorter);

	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();

	// now that we have sorted the nodes we get the closest node and select it
	UEdGraphNode* NodeToSelect = FilteredNodes[0];
	GraphPanel->SelectionManager.SelectSingleNode(NodeToSelect);

	// if the node selected is not visible, then we lerp the viewport
	const FSlateRect NodeBounds = FBAUtils::GetNodeBounds(NodeToSelect);
	if (!GraphPanel->IsRectVisible(NodeBounds.GetTopLeft(), NodeBounds.GetBottomRight()))
		GraphHandler->BeginLerpViewport(NodeBounds.GetCenter());
}

void FBAInputProcessor::SelectAnyNodeInDirection(const int X, const int Y) const
{
	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (Graph == nullptr)
		return;

	SelectNodeInDirection(Graph->Nodes, X, Y, 5000);
}

void FBAInputProcessor::ShiftCameraInDirection(const int X, const int Y) const
{
	/** get the current view location */
	FVector2D ViewLocation;
	float Zoom;
	GraphHandler->GetGraphEditor()->GetViewLocation(ViewLocation, Zoom);

	/** Shift the current view location */
	const FVector2D Offset = FVector2D(X, Y) * GetDefault<UBASettings>()->ShiftCameraDistance / Zoom;
	GraphHandler->BeginLerpViewport(ViewLocation + Offset, false);
}

void FBAInputProcessor::SelectCustomEventNodeInDirection(const int X, const int Y) const
{
	UEdGraph* Graph = GraphHandler->GetFocusedEdGraph();
	if (Graph == nullptr)
		return;

	const TArray<UEdGraphNode*> EventNodes = Graph->Nodes.FilterByPredicate(FBAUtils::IsEventNode);
	SelectNodeInDirection(EventNodes, X, Y, 0);
}

void FBAInputProcessor::SelectPinInDirection(const int X, const int Y) const
{
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode == nullptr)
	{
		GraphHandler->SetSelectedPin(nullptr);
		return;
	}

	if (FBAUtils::IsCommentNode(SelectedNode) || FBAUtils::IsKnotNode(SelectedNode))
	{
		GraphHandler->SetSelectedPin(nullptr);
		return;
	}

	const TArray<UEdGraphPin*> PinsOnSelectedNode = FBAUtils::GetPinsByDirection(SelectedNode);
	if (PinsOnSelectedNode.Num() == 0)
	{
		GraphHandler->SetSelectedPin(nullptr);
		return;
	}

	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();

	if (SelectedPin == nullptr)
	{
		GraphHandler->SetSelectedPin(FBAUtils::GetPinsByDirection(SelectedNode)[0]);
	}
	else
	{
		if (SelectedPin->GetOwningNode() != SelectedNode)
		{
			GraphHandler->SetSelectedPin(FBAUtils::GetPinsByDirection(SelectedNode)[0]);
		}
		else
		{
			const auto& IsPinVisibleAsAdvanced = [&](UEdGraphPin* Pin)
			{
				TSharedPtr<SGraphPin> GraphPin = GraphHandler->GetGraphPin(Pin);
				return GraphPin.IsValid() &&
					GraphPin->IsPinVisibleAsAdvanced() == EVisibility::Visible;
			};

			if (X != 0) // x direction - switch to the opposite pins on the current node
			{
				if (X < 0 && SelectedPin->Direction == EGPD_Input)
					return;

				if (X > 0 && SelectedPin->Direction == EGPD_Output)
					return;

				auto Direction = UEdGraphPin::GetComplementaryDirection(SelectedPin->Direction);

				TArray<UEdGraphPin*> Pins = FBAUtils::GetPinsByDirection(SelectedNode, Direction).FilterByPredicate(IsPinVisibleAsAdvanced);

				if (Pins.Num() > 0)
				{
					const int32 PinIndex = FBAUtils::GetPinIndex(SelectedPin);

					if (PinIndex != -1)
					{
						const int32 NextPinIndex = FMath::Min(Pins.Num() - 1, PinIndex);
						if (Pins.Num() > 0)
							GraphHandler->SetSelectedPin(Pins[NextPinIndex]);
					}
				}
			}
			else if (Y != 0) // y direction - move the selected pin up / down
			{
				TArray<UEdGraphPin*> Pins =
					FBAUtils::GetPinsByDirection(SelectedNode, SelectedPin->Direction)
					.FilterByPredicate(IsPinVisibleAsAdvanced);

				if (Pins.Num() > 1)
				{
					int32 PinIndex;
					Pins.Find(SelectedPin, PinIndex);
					if (PinIndex != -1) // we couldn't find the pin index
					{
						int32 NextPinIndex = PinIndex + Y;

						if (NextPinIndex < 0)
							NextPinIndex = Pins.Num() + NextPinIndex;
						else
							NextPinIndex = NextPinIndex % Pins.Num();

						GraphHandler->SetSelectedPin(Pins[NextPinIndex]);
					}
				}
			}
		}
	}
}

bool FBAInputProcessor::CanSelectPinInDirection()
{
	return !FBAUtils::IsKnotNode(GraphHandler->GetSelectedNode());
}

void FBAInputProcessor::SwapNodeInDirection(const EEdGraphPinDirection Direction) const
{
	// PinA: Linked to pin in direction
	// PinB: Linked to pin opposite
	// PinC: Linked to PinA's Node in direction

	auto GraphHandlerCapture = GraphHandler;
	const auto TopMostPinSort = [GraphHandlerCapture](UEdGraphPin& PinA, UEdGraphPin& PinB)
	{
		return GraphHandlerCapture->GetPinY(&PinA) < GraphHandlerCapture->GetPinY(&PinB);
	};

	TArray<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes().Array();

	if (SelectedNodes.Num() == 0)
		return;

	const auto IsSelectedAndPure = [&SelectedNodes](UEdGraphNode* Node)
	{
		return FBAUtils::IsNodeImpure(Node) && SelectedNodes.Contains(Node);
	};

	UEdGraphNode* LeftMostNode = FBAUtils::GetTopMostWithFilter(SelectedNodes[0], EGPD_Input, IsSelectedAndPure);

	UEdGraphNode* RightMostNode = FBAUtils::GetTopMostWithFilter(SelectedNodes[0], EGPD_Output, IsSelectedAndPure);

	UEdGraphNode* NodeInDirection = Direction == EGPD_Input ? LeftMostNode : RightMostNode;
	UEdGraphNode* NodeOpposite = Direction == EGPD_Input ? RightMostNode : LeftMostNode;

	// Process NodeInDirection
	TArray<UEdGraphPin*> LinkedPins =
		FBAUtils::GetLinkedPins(NodeInDirection, Direction).FilterByPredicate(FBAUtils::IsExecPin);

	if (LinkedPins.Num() == 0)
		return;

	UEdGraphPin* PinInDirection = LinkedPins[0];
	if (PinInDirection->LinkedTo.Num() == 0)
		return;

	// Process NodeOpposite
	const auto OppositeDirection = UEdGraphPin::GetComplementaryDirection(Direction);
	TArray<UEdGraphPin*> PinsOpposite = FBAUtils::GetPinsByDirection(NodeOpposite, OppositeDirection).FilterByPredicate(FBAUtils::IsExecPin);

	if (PinsOpposite.Num() == 0)
		return;

	UEdGraphPin* PinOpposite = PinsOpposite[0];

	//UE_LOG(LogTemp, Warning, TEXT("PinInDirection %s (%s)"), *FBAUtils::GetPinName(PinInDirection), *FBAUtils::GetNodeName(PinInDirection->GetOwningNode()));
	//UE_LOG(LogTemp, Warning, TEXT("PinOpposite %s (%s)"), *FBAUtils::GetPinName(PinOpposite), *FBAUtils::GetNodeName(PinOpposite->GetOwningNode()));

	// Process NodeA
	PinInDirection->LinkedTo.StableSort(TopMostPinSort);
	UEdGraphPin* PinA = PinInDirection->LinkedTo[0];
	//UE_LOG(LogTemp, Warning, TEXT("PinA %s (%s)"), *FBAUtils::GetPinName(PinA), *FBAUtils::GetNodeName(PinA->GetOwningNode()));
	UEdGraphNode* NodeA = PinA->GetOwningNode();

	TArray<UEdGraphPin*> PinsAInDirection = FBAUtils::GetPinsByDirection(NodeA, Direction).FilterByPredicate(FBAUtils::IsExecPin);

	TArray<FPinLink> PendingConnections;
	PendingConnections.Reserve(3);

	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "SwapNodes", "Swap Nodes")));

	if (PinsAInDirection.Num() > 0)
	{
		UEdGraphPin* PinAInDirection = PinsAInDirection[0];
		PendingConnections.Add(FPinLink(PinAInDirection, PinOpposite));

		// Optional PinB
		if (PinAInDirection->LinkedTo.Num() > 0)
		{
			PinAInDirection->LinkedTo.StableSort(TopMostPinSort);
			UEdGraphPin* PinB = PinAInDirection->LinkedTo[0];
			//UE_LOG(LogTemp, Warning, TEXT("PinB %s (%s)"), *FBAUtils::GetPinName(PinB), *FBAUtils::GetNodeName(PinB->GetOwningNode()));
			PinB->BreakLinkTo(PinAInDirection);
			PendingConnections.Add(FPinLink(PinB, PinInDirection));
		}
	}

	// Optional PinC
	if (PinOpposite->LinkedTo.Num() > 0)
	{
		PinOpposite->LinkedTo.StableSort(TopMostPinSort);
		UEdGraphPin* PinC = PinOpposite->LinkedTo[0];
		//UE_LOG(LogTemp, Warning, TEXT("PinC %s (%s)"), *FBAUtils::GetPinName(PinC), *FBAUtils::GetNodeName(PinC->GetOwningNode()));
		PinC->BreakLinkTo(PinOpposite);
		PendingConnections.Add(FPinLink(PinC, PinA));
	}

	if (PendingConnections.Num() == 0)
	{
		Transaction->Cancel();
	}

	PinInDirection->BreakLinkTo(PinA);

	for (FPinLink& Link : PendingConnections)
	{
		FBAUtils::TryCreateConnection(Link.From, Link.To);
	}

	auto AutoFormatting = FBAUtils::GetFormatterSettings(GraphHandler->GetFocusedEdGraph()).AutoFormatting;
	
	if (AutoFormatting != BAAutoFormat_Never)
	{
		FEdGraphFormatterParameters FormatterParams;
		if (AutoFormatting == BAAutoFormat_FormatSingleConnected)
		{
			FormatterParams.NodesToFormat.Append(SelectedNodes);
			FormatterParams.NodesToFormat.Add(PinInDirection->GetOwningNode());
		}
		
		GraphHandler->AddPendingFormatNodes(NodeInDirection, Transaction, FormatterParams);
	}
	else
	{
		Transaction.Reset();
	}
}

void FBAInputProcessor::OnEditSelectedPinValue() const
{
	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();
	if (SelectedPin == nullptr)
		return;

	TSharedPtr<SGraphPin> GraphPin = GraphHandler->GetGraphPin(SelectedPin);
	if (!GraphPin.IsValid())
		return;

	struct FLocal
	{
		static void GetEditableWidgets(TSharedPtr<SWidget> Widget, TArray<TSharedPtr<SWidget>>& EditableWidgets, TArray<TSharedPtr<SWidget>>& ClickableWidgets)
		{
			if (Widget.IsValid())
			{
				if (FBAUtils::IsUserInputWidget(Widget))
					EditableWidgets.Add(Widget);
				else if (FBAUtils::IsClickableWidget(Widget))
					ClickableWidgets.Add(Widget);

				// iterate through children
				FChildren* Children = Widget->GetChildren();
				for (int i = 0; i < Children->Num(); i++)
					GetEditableWidgets(Children->GetChildAt(i), EditableWidgets, ClickableWidgets);
			}
		}
	};

	TArray<TSharedPtr<SWidget>> EditableWidgets;
	TArray<TSharedPtr<SWidget>> ClickableWidgets;
	FLocal::GetEditableWidgets(GraphPin, EditableWidgets, ClickableWidgets);

	if (EditableWidgets.Num() > 0)
	{
		TSharedPtr<SWidget> CurrentlyFocusedWidget = FSlateApplication::Get().GetKeyboardFocusedWidget();
		const int32 CurrentIndex = EditableWidgets.IndexOfByKey(CurrentlyFocusedWidget);

		if (CurrentIndex == -1)
		{
			FSlateApplication::Get().SetKeyboardFocus(EditableWidgets[0], EFocusCause::Navigation);
		}
		else
		{
			const int32 NextIndex = (CurrentIndex + 1) % (EditableWidgets.Num());
			FSlateApplication::Get().SetKeyboardFocus(EditableWidgets[NextIndex], EFocusCause::Navigation);
		}
	}
	else if (ClickableWidgets.Num() > 0)
	{
		FBAUtils::InteractWithWidget(ClickableWidgets[0]);
	}
}

void FBAInputProcessor::DeleteAndLink()
{
	const auto& ShouldDeleteNode = [](UEdGraphNode* Node)
	{
		return Node->CanUserDeleteNode();
	};

	TArray<UEdGraphNode*> NodesToDelete = GraphHandler->GetSelectedNodes().Array().FilterByPredicate(ShouldDeleteNode);
	if (NodesToDelete.Num() > 0)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "DeleteAndLink", "Delete and link"));

		DisconnectExecutionOfNodes(NodesToDelete);
		for (UEdGraphNode* Node : NodesToDelete)
		{
			FBAUtils::SafeDelete(GraphHandler, Node);
		}
	}
}

void FBAInputProcessor::ZoomToNodeTree() const
{
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode == nullptr)
		return;

	TSet<UEdGraphNode*> NodeTree = FBAUtils::GetNodeTree(SelectedNode);

	// selecting a set of nodes requires the ptrs to be const
	TSet<const UEdGraphNode*> ConstNodeTree;
	for (UEdGraphNode* Node : NodeTree)
		ConstNodeTree.Add(Node);

	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	GraphHandler->GetFocusedEdGraph()->SelectNodeSet(ConstNodeTree);
	GraphHandler->GetGraphEditor()->ZoomToFit(true);
}

void FBAInputProcessor::OnGetContextMenuActions(const bool bUsePin) const
{
	UEdGraph* EdGraph = GraphHandler->GetFocusedEdGraph();
	if (EdGraph == nullptr)
		return;

	const UEdGraphSchema* Schema = EdGraph->GetSchema();
	if (Schema == nullptr)
		return;

	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	const FVector2D MenuLocation = FSlateApplication::Get().GetCursorPos();
	const FVector2D SpawnLocation = GraphEditor->GetPasteLocation();

	UEdGraphNode* Node = GraphHandler->GetSelectedNode();

	UEdGraphPin* Pin = bUsePin
		? GraphHandler->GetSelectedPin()
		: nullptr;

	const TArray<UEdGraphPin*> DummyPins;
	GraphHandler->GetGraphPanel()->SummonContextMenu(MenuLocation, SpawnLocation, Node, Pin, DummyPins);
}

void FBAInputProcessor::PrintSelectedNodeInfo() const
{
	UEdGraphNode* Node = GraphHandler->GetSelectedNode(true);
	if (!Node)
		return;

	const FString NodeName = FBAUtils::GetNodeName(Node);
	const FString IsNodePure = FBAUtils::IsNodePure(Node) ? FString("True") : FString("False");

	const FString WidgetName = FBAUtils::GetGraphNode(GraphHandler->GetGraphPanel(), Node)->GetTypeAsString();
	
	UE_LOG(LogBlueprintAssist, Warning, TEXT("Debug Print for %s (Pure: %s): %s | %s"), *NodeName, *IsNodePure, *Node->GetClass()->GetFName().ToString(), *WidgetName);

	for (UEdGraphPin* Pin : Node->GetAllPins())
	{
		UE_LOG(LogBlueprintAssist, Warning,
		       TEXT("\tPin %s (%s) | Category %s | SubCategory %s"),
		       *Pin->PinName.ToString(),
		       *Pin->PinFriendlyName.ToString(),
		       *Pin->PinType.PinCategory.ToString(),
		       *Pin->PinType.PinSubCategory.ToString()
		);
	}
}

void FBAInputProcessor::OnToggleActionMenuContextSensitive() const
{
	TSharedPtr<SWindow> Menu = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!Menu.IsValid())
		return;

	if (!Menu->GetContent()->GetTypeAsString().Contains("SMenuContentWrapper"))
		return;

	TSharedPtr<SWidget> BlueprintActionMenu = FBAUtils::GetChildWidget(Menu, "SGraphActionMenu");
	if (!BlueprintActionMenu.IsValid())
		return;

	TSharedPtr<SWidget> ToggleSensitiveWidget = FBAUtils::GetChildWidget(Menu, "SCheckBox");
	if (!ToggleSensitiveWidget.IsValid())
		return;

	TSharedPtr<SCheckBox> ToggleSensitiveCheckBox = StaticCastSharedPtr<SCheckBox>(ToggleSensitiveWidget);
	ToggleSensitiveCheckBox->ToggleCheckedState();
}

void FBAInputProcessor::DisconnectPinOrWire()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();

	if (GraphPanel.IsValid())
	{
		TSharedPtr<SGraphPin> HoveredPin = FBAUtils::GetHoveredGraphPin(GraphPanel);
		if (HoveredPin.IsValid())
		{
			const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "DisconnectPinLink", "Disconnect Pin Link"));

			HoveredPin->GetPinObj()->BreakAllPinLinks();
			return;
		}
	}

	UEdGraphPin* SelectedPin = GraphHandler->GetSelectedPin();
	if (SelectedPin != nullptr)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "DisconnectPinLink", "DisconectPinLink"));

		SelectedPin->BreakAllPinLinks();
	}
}

void FBAInputProcessor::DisconnectExecutionOfSelectedNode()
{
	TArray<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes().Array();
	DisconnectExecutionOfNodes(SelectedNodes);
}

void FBAInputProcessor::DisconnectExecutionOfNodes(TArray<UEdGraphNode*> Nodes)
{
	// TODO: Make this work for pure nodes
	FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "DisconnectExecutionForNodes", "Disconnect Execution for Nodes"));

	if (Nodes.Num() == 0)
	{
		Transaction.Cancel();
		return;
	}

	int CountError = 0;

	while (Nodes.Num() > 0)
	{
		CountError += 1;
		if (CountError > 1000)
		{
			UE_LOG(LogBlueprintAssist, Error, TEXT("DisconnectExecutionOfNodes caused infinite loop: Please report this on the wiki"));
			return;
		}

		UEdGraphNode* NextNode = Nodes[0];

		const auto Filter = [&Nodes](UEdGraphNode* Node)
		{
			return Nodes.Contains(Node);
		};

		TArray<UEdGraphNode*> NodeTree = FBAUtils::GetExecutionTreeWithFilter(NextNode, Filter).Array();
		if (NodeTree.Num() > 0)
		{
			const auto InNodeTree = [&NodeTree](UEdGraphNode* Node)
			{
				return NodeTree.Contains(Node);
			};

			UEdGraphNode* LeftMostNode = FBAUtils::GetTopMostWithFilter(NodeTree[0], EGPD_Input, InNodeTree);
			UEdGraphNode* RightMostNode = FBAUtils::GetTopMostWithFilter(NodeTree[0], EGPD_Output, InNodeTree);

			TArray<UEdGraphPin*> LinkedToInput = FBAUtils::GetLinkedToPins(LeftMostNode, EGPD_Input).FilterByPredicate(FBAUtils::IsExecPin);
			TArray<UEdGraphPin*> LinkedToOutput = FBAUtils::GetLinkedToPins(RightMostNode, EGPD_Output).FilterByPredicate(FBAUtils::IsExecPin);

			for (UEdGraphPin* Input : LinkedToInput)
			{
				for (UEdGraphPin* Output : LinkedToOutput)
				{
					if (FBAUtils::CanConnectPins(Input, Output, true, false))
					{
						Input->MakeLinkTo(Output);
						break;
					}
				}
			}

			for (UEdGraphPin* Pin : FBAUtils::GetExecPins(LeftMostNode, EGPD_Input))
			{
				Pin->BreakAllPinLinks();
			}

			for (UEdGraphPin* Pin : FBAUtils::GetExecPins(RightMostNode, EGPD_Output))
			{
				Pin->BreakAllPinLinks();
			}
		}

		for (UEdGraphNode* Node : NodeTree)
		{
			Nodes.RemoveSwap(Node);
		}
	}
}

void FBAInputProcessor::DisconnectAllNodeLinks()
{
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode != nullptr)
	{
		const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "DisconnectAllNodeLinks", "Disconnect All Node Links"));

		for (UEdGraphPin* Pin : SelectedNode->GetAllPins())
		{
			Pin->BreakAllPinLinks();
		}
	}
}

void FBAInputProcessor::ReplaceNodeWith()
{
	UEdGraphNode* SelectedNode = GraphHandler->GetSelectedNode();
	if (SelectedNode == nullptr || !SelectedNode->CanUserDeleteNode())
		return;

	SavedNodeToReplace = SelectedNode;

	TSharedPtr<SGraphEditor> GraphEditor = GraphHandler->GetGraphEditor();
	if (!GraphEditor.IsValid())
		return;

	const FVector2D MenuLocation = FSlateApplication::Get().GetCursorPos();
	const FVector2D SpawnLocation(SelectedNode->NodePosX, SelectedNode->NodePosY);

	TSharedPtr<FScopedTransaction> Transaction = MakeShareable(new FScopedTransaction(NSLOCTEXT("UnrealEd", "ReplaceNodeWith", "Replace Node With")));

	OpenContextMenu(MenuLocation, SpawnLocation);

	GraphHandler->SetReplaceNewNodeTransaction(Transaction);

	FSlateApplication& SlateApp = FSlateApplication::Get();
	if (SlateApp.IsInitialized())
	{
		TSharedPtr<SWindow> Menu = SlateApp.GetActiveTopLevelWindow();

		if (Menu.IsValid())
		{
			if (Menu->GetContent()->GetTypeAsString().Contains("SMenuContentWrapper"))
			{
				TSharedPtr<SWidget> ActionMenu = FBAUtils::GetChildWidget(Menu, "SGraphActionMenu");

				if (ActionMenu.IsValid())
				{
#if ENGINE_MINOR_VERSION < 22
					Menu->SetOnWindowClosed(FOnWindowClosed::CreateRaw(this, &FBAInputProcessor::OnReplaceNodeMenuClosed));
#else
					OnReplaceMenuClosedDelegate = Menu->GetOnWindowClosedEvent().AddRaw(this, &FBAInputProcessor::OnReplaceNodeMenuClosed);
#endif
				}
			}
		}
	}
}

void FBAInputProcessor::OnReplaceNodeMenuClosed(const TSharedRef<SWindow>& Window)
{
	GraphHandler->ResetSingleNewNodeTransaction();
	OnReplaceMenuClosedDelegate.Reset();
}

void FBAInputProcessor::DebugPrintGraphUnderCursor() const
{	
	FSlateApplication& SlateApp = FSlateApplication::Get();
	FWidgetPath Path = SlateApp.LocateWindowUnderMouse(SlateApp.GetCursorPos(), SlateApp.GetInteractiveTopLevelWindows());
	if (Path.IsValid())
	{
		TSharedRef<SWidget> Widget = Path.GetLastWidget();
		TSharedPtr<SWidget> GraphPanelAsWidget = FBAUtils::GetChildWidget(Widget, "SGraphPanel");
		if (GraphPanelAsWidget.IsValid())
		{
			auto GraphPanel = StaticCastSharedPtr<SGraphPanel>(GraphPanelAsWidget);
			if (GraphPanel.IsValid())
			{
				if (UEdGraph* EdGraph = GraphPanel->GetGraphObj())
				{
					FName GraphTypeName = EdGraph->GetClass()->GetFName();
					EGraphType GraphType = FBAUtils::GetGraphType(EdGraph);
					
					UE_LOG(LogBlueprintAssist, Log, TEXT("PRINTING GRAPH INFO: GraphName <%s> | GraphType <%d>"), *GraphTypeName.ToString(), GraphType);
				}
			}
		}
	}
	
	PrintSelectedNodeInfo();
}

void FBAInputProcessor::ToggleNodes()
{
	TSet<UEdGraphNode*> SelectedNodes = GraphHandler->GetSelectedNodes();

	auto OnlyPureNodes = [](UEdGraphNode* Node)
	{
		return !FBAUtils::IsKnotNode(Node) && !FBAUtils::IsCommentNode(Node) && FBAUtils::IsNodeImpure(Node);
	};

	TArray<UEdGraphNode*> FilteredNodes = SelectedNodes.Array().FilterByPredicate(OnlyPureNodes);

	if (FilteredNodes.Num() == 0)
	{
		return;
	}
	
	FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "ToggleNodes", "Toggle Nodes"));
	
	bool bAllNodesDisabled = true;
	for (UEdGraphNode* Node : FilteredNodes)
	{
		if (Node->GetDesiredEnabledState() != ENodeEnabledState::Disabled)
		{
			bAllNodesDisabled = false;
			break;
		}
	}
	
	for (UEdGraphNode* Node : FilteredNodes)
	{
		if (bAllNodesDisabled) // Set nodes to their default state
		{
			ENodeEnabledState DefaultEnabledState = ENodeEnabledState::Enabled;
			if (UFunction* Function = FFunctionFromNodeHelper::FunctionFromNode(static_cast<const UK2Node*>(Node)))
			{
				if (Function->HasMetaData(FBlueprintMetadata::MD_DevelopmentOnly))
				{
					DefaultEnabledState = ENodeEnabledState::DevelopmentOnly;
				}
			}

			Node->Modify();
			Node->SetEnabledState(DefaultEnabledState);
		}
		else // Set all nodes to disabled
		{
			if (Node->GetDesiredEnabledState() != ENodeEnabledState::Disabled)
			{
				Node->Modify();
				Node->SetEnabledState(ENodeEnabledState::Disabled);
			}
		}
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GraphHandler->GetBlueprint());
}

void FBAInputProcessor::SplitPin()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	if (!GraphPanel.IsValid())
		return;

	auto EdGraph = GraphHandler->GetFocusedEdGraph();
	if (!EdGraph)
		return;
	
	UEdGraphPin* PinToUse = nullptr;
	
    TSharedPtr<SGraphPin> HoveredPin = FBAUtils::GetHoveredGraphPin(GraphPanel);
    if (HoveredPin.IsValid())
    {
    	PinToUse = HoveredPin->GetPinObj();
    }

	if (PinToUse == nullptr)
	{
		PinToUse = GraphHandler->GetSelectedPin();
	}

	if (PinToUse != nullptr)
	{
		const UEdGraphSchema* Schema = EdGraph->GetSchema();

		if (PinToUse->GetOwningNode()->CanSplitPin(PinToUse))
		{
			const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "SplitPin", "Split Pin"));
			
			Schema->SplitPin(PinToUse);

			GraphHandler->SetSelectedPin(PinToUse->SubPins[0]);
		}
	}
}

void FBAInputProcessor::RecombinePin()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
    if (!GraphPanel.IsValid())
    	return;

    auto EdGraph = GraphHandler->GetFocusedEdGraph();
    if (!EdGraph)
    	return;
    
    UEdGraphPin* PinToUse = nullptr;
    
    TSharedPtr<SGraphPin> HoveredPin = FBAUtils::GetHoveredGraphPin(GraphPanel);
    if (HoveredPin.IsValid())
    {
        PinToUse = HoveredPin->GetPinObj();
    }

    if (PinToUse == nullptr)
    {
    	PinToUse = GraphHandler->GetSelectedPin();
    }

    if (PinToUse != nullptr)
    {
    	const UEdGraphSchema* Schema = EdGraph->GetSchema();

		if (PinToUse->ParentPin != nullptr)
    	{
    		const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "RecombinePin", "Recombine Pin"));
			GraphHandler->SetSelectedPin(PinToUse->ParentPin);
			Schema->RecombinePin(PinToUse);
    	}
    }
}

void FBAInputProcessor::CreateRerouteNode()
{
	TSharedPtr<SGraphPanel> GraphPanel = GraphHandler->GetGraphPanel();
	const FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();
	const FVector2D GraphPosition = GraphPanel->PanelCoordToGraphCoord(GraphPanel->GetCachedGeometry().AbsoluteToLocal(CursorPos));

	UEdGraphPin* PinToCreateFrom = nullptr;
	
	// get pin from knot node
	auto SelectedNode = GraphHandler->GetSelectedNode();
	bool bHasSelectedKnotNode = false;
	if (auto KnotNode = Cast<UK2Node_Knot>(SelectedNode))
	{
		bHasSelectedKnotNode = true;

		if (GraphPosition.X > KnotNode->NodePosX)
		{
			PinToCreateFrom = KnotNode->GetOutputPin();
		}
		else
		{
			PinToCreateFrom = KnotNode->GetInputPin();
		}
		
		// if (!FBAUtils::IsPinLinked(KnotNode->GetOutputPin()))
		// {
		// 	PinToCreateFrom = KnotNode->GetOutputPin();
		// }
		// else if (!FBAUtils::IsPinLinked(KnotNode->GetInputPin()))
		// {
		// 	PinToCreateFrom = KnotNode->GetInputPin();
		// }
	}

	// get selected pin
	if (!PinToCreateFrom)
	{
		PinToCreateFrom = GraphHandler->GetSelectedPin(); 
	}
	
	if (!PinToCreateFrom)
		return;

	// get hovered graph pin
	auto HoveredGraphPin = FBAUtils::GetHoveredGraphPin(GraphHandler->GetGraphPanel());
	if (HoveredGraphPin.IsValid())
	{
		UEdGraphPin* HoveredPin = HoveredGraphPin->GetPinObj();

		if (FBAUtils::CanConnectPins(PinToCreateFrom, HoveredPin, true))
		{
			if (FBAUtils::TryCreateConnection(PinToCreateFrom, HoveredPin, true))
			{
				return;
			}
		}
	}

	UEdGraphPin* LinkedPin = PinToCreateFrom->LinkedTo.Num() > 0 ? PinToCreateFrom->LinkedTo[0] : nullptr;
	
    //@TODO: This constant is duplicated from inside of SGraphNodeKnot
    const FVector2D NodeSpacerSize(42.0f, 14.0f);
	
    FVector2D KnotTopLeft = GraphPosition;

    // Create a new knot
    UEdGraph* ParentGraph = PinToCreateFrom->GetOwningNode()->GetGraph();
    if (!FBlueprintEditorUtils::IsGraphReadOnly(ParentGraph))
    {
    	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "CreateRerouteNode_BlueprintAssist", "Create Reroute Node"));
    	
    	UK2Node_Knot* NewKnot = FEdGraphSchemaAction_K2NewNode::SpawnNode<UK2Node_Knot>(ParentGraph, KnotTopLeft - NodeSpacerSize * 0.5f, EK2NewNodeFlags::SelectNewNode);

    	// Move the connections across (only notifying the knot, as the other two didn't really change)
		UEdGraphPin* NewKnotPin = (PinToCreateFrom->Direction == EGPD_Output) ? NewKnot->GetInputPin() : NewKnot->GetOutputPin();
    	
    	PinToCreateFrom->MakeLinkTo(NewKnotPin);

    	if (LinkedPin != nullptr)
    	{
    		PinToCreateFrom->BreakLinkTo(LinkedPin);
    		UEdGraphPin* NewKnotPinForLinkedPin = (LinkedPin->Direction == EGPD_Output) ? NewKnot->GetInputPin() : NewKnot->GetOutputPin();
    		LinkedPin->MakeLinkTo(NewKnotPinForLinkedPin);
    	}

    	NewKnot->PostReconstructNode();
    	
    	TSharedPtr<SGraphPin> GraphPin = FBAUtils::GetGraphPin(GraphPanel, PinToCreateFrom);
    	const float PinY = PinToCreateFrom->GetOwningNode()->NodePosY + GraphPin->GetNodeOffset().Y;
    	const float HeightDiff = FMath::Abs(PinY - KnotTopLeft.Y);
		if (HeightDiff < 25)
		{
			NewKnot->NodePosY = PinY - NodeSpacerSize.Y * 0.5f;
		}

    	// Dirty the blueprint
    	UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraphChecked(ParentGraph);
    	FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
    }
}

void FBAInputProcessor::OpenBlueprintAssistHotkeyMenu()
{
	TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().GetActiveTopLevelWindow();
	if (!ParentWindow.IsValid())
	{
		return;
	}

	TSharedRef<SBAHotkeyMenu> Widget = SNew(SBAHotkeyMenu);

	FVector2D WindowPosition = FSlateApplication::Get().GetCursorPos();
	FSlateRect ParentMonitorRect = ParentWindow->GetFullScreenInfo();
	const FVector2D MonitorCenter((ParentMonitorRect.Right + ParentMonitorRect.Left) * 0.5f, (ParentMonitorRect.Top + ParentMonitorRect.Bottom) * 0.5f);
	WindowPosition = MonitorCenter - Widget->WidgetSize * 0.5f;
	
	TSharedPtr<IMenu> Menu = FSlateApplication::Get().PushMenu(
        ParentWindow->AsShared(),
        FWidgetPath(),
        Widget,
        WindowPosition,
        FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu)
    );
}
