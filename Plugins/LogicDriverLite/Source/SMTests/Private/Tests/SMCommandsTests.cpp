// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTestHelpers.h"
#include "Helpers/SMTestBoilerplate.h"

#include "Blueprints/SMBlueprintFactory.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "SMTestContext.h"
#include "EdGraph/EdGraph.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Graph/SMGraph.h"
#include "Graph/Nodes/SMGraphK2Node_StateMachineNode.h"
#include "Graph/Nodes/SMGraphNode_StateNode.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"
#include "Graph/Nodes/Helpers/SMGraphK2Node_StateReadNodes.h"

#include "Blueprints/SMBlueprint.h"

#include "EdGraph/EdGraph.h"
#include "Kismet2/KismetEditorUtilities.h"

#if WITH_DEV_AUTOMATION_TESTS

#if PLATFORM_DESKTOP

/**
 * Collapse states down to a nested state machine.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCollapseStateMachineTest, "LogicDriver.Commands.CollapseStateMachine", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FCollapseStateMachineTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(5)

	UEdGraphPin* LastStatePin = nullptr;

	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin);
	if (!NewAsset.SaveAsset(this))
	{
		return false;
	}
	TestHelpers::TestLinearStateMachine(this, NewBP, TotalStates);

	// Let the last node on the graph be the node after the new state machine.
	USMGraphNode_StateNodeBase* AfterNode = CastChecked<USMGraphNode_StateNodeBase>(LastStatePin->GetOwningNode());

	// Let the second node from the beginning be the node leading to the new state machine.
	USMGraphNode_StateNodeBase* BeforeNode = AfterNode->GetPreviousNode()->GetPreviousNode()->GetPreviousNode();
	check(BeforeNode);

	// The two states in between will become a state machine.
	TSet<UObject*> SelectedNodes;
	USMGraphNode_StateNodeBase* SMStartNode = BeforeNode->GetNextNode();
	USMGraphNode_StateNodeBase* SMEndNode = SMStartNode->GetNextNode();
	SelectedNodes.Add(SMStartNode);
	SelectedNodes.Add(SMEndNode);

	TestEqual("Start SM Node connects from before node", BeforeNode, SMStartNode->GetPreviousNode());
	TestEqual("Before Node connects to start SM node", SMStartNode, BeforeNode->GetNextNode());

	TestEqual("End SM Node connects from after node", AfterNode, SMEndNode->GetNextNode());
	TestEqual("After Node connects to end SM node", SMEndNode, AfterNode->GetPreviousNode());

	FSMBlueprintEditorUtils::CollapseNodesAndCreateStateMachine(SelectedNodes);

	TotalStates -= 1;

	TestNotEqual("Start SM Node no longer connects to before node", BeforeNode, SMStartNode->GetPreviousNode());
	TestNotEqual("Before Node no longer connects to start SM node", SMStartNode, BeforeNode->GetNextNode());

	TestNotEqual("End SM Node no longer connects from after node", AfterNode, SMEndNode->GetNextNode());
	TestNotEqual("After Node no longer connects to end SM node", SMEndNode, AfterNode->GetPreviousNode());

	USMGraphNode_StateMachineStateNode* NewSMNode = Cast<USMGraphNode_StateMachineStateNode>(BeforeNode->GetNextNode());
	TestNotNull("State Machine node created in proper location", NewSMNode);

	if (NewSMNode == nullptr)
	{
		return false;
	}

	TestEqual("New SM Node connects to correct node", NewSMNode->GetNextNode(), AfterNode);

	TestHelpers::TestLinearStateMachine(this, NewBP, TotalStates);

	return NewAsset.DeleteAsset(this);
}

/**
 * Replace a node in the state machine.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FReplaceNodesTest, "LogicDriver.Commands.ReplaceNodes", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FReplaceNodesTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(5)

	UEdGraphPin* LastStatePin = nullptr;

	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin);
	if (!NewAsset.SaveAsset(this))
	{
		return false;
	}
	TestHelpers::TestLinearStateMachine(this, NewBP, TotalStates);

	// Let the last node on the graph be the node after the new node.
	USMGraphNode_StateNodeBase* AfterNode = CastChecked<USMGraphNode_StateNodeBase>(LastStatePin->GetOwningNode());

	// Let node prior to the one we are replacing.
	USMGraphNode_StateNodeBase* BeforeNode = AfterNode->GetPreviousNode()->GetPreviousNode();
	check(BeforeNode);

	// The node we are replacing is the second to last node.
	USMGraphNode_StateNodeBase* NodeToReplace = AfterNode->GetPreviousNode();
	TestTrue("Node is state", NodeToReplace->IsA<USMGraphNode_StateNode>());

	// State machine -- can't easily test converting to reference but that is just setting a null reference.
	USMGraphNode_StateMachineStateNode* StateMachineNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(NodeToReplace);
	TestTrue("Node removed", NodeToReplace->GetNextNode() == nullptr && NodeToReplace->GetPreviousNode() == nullptr && NodeToReplace->GetBoundGraph() == nullptr);
	TestTrue("Node is state machine", StateMachineNode->IsA<USMGraphNode_StateMachineStateNode>());
	TestFalse("Node is not reference", StateMachineNode->IsStateMachineReference());
	TestEqual("Connected to original next node", StateMachineNode->GetNextNode(), AfterNode);
	TestEqual("Connected to original previous node", StateMachineNode->GetPreviousNode(), BeforeNode);

	int32 A, B;
	TestHelpers::RunStateMachineToCompletion(this, NewBP, TotalStates, A, B);
	
	// Conduit
	NodeToReplace = StateMachineNode;
	USMGraphNode_ConduitNode* ConduitNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_ConduitNode>(NodeToReplace);
	TestTrue("Node removed", NodeToReplace->GetNextNode() == nullptr && NodeToReplace->GetPreviousNode() == nullptr && NodeToReplace->GetBoundGraph() == nullptr);
	TestTrue("Node is conduit", ConduitNode->IsA<USMGraphNode_ConduitNode>());
	TestEqual("Connected to original next node", ConduitNode->GetNextNode(), AfterNode);
	TestEqual("Connected to original previous node", ConduitNode->GetPreviousNode(), BeforeNode);

	// Back to state
	NodeToReplace = ConduitNode;
	USMGraphNode_StateNode* StateNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateNode>(NodeToReplace);
	TestTrue("Node removed", NodeToReplace->GetNextNode() == nullptr && NodeToReplace->GetPreviousNode() == nullptr && NodeToReplace->GetBoundGraph() == nullptr);
	TestTrue("Node is state", StateNode->IsA<USMGraphNode_StateNode>());
	TestEqual("Connected to original next node", StateNode->GetNextNode(), AfterNode);
	TestEqual("Connected to original previous node", StateNode->GetPreviousNode(), BeforeNode);
	TestHelpers::RunStateMachineToCompletion(this, NewBP, TotalStates, A, B);

	
	return NewAsset.DeleteAsset(this);
}

#endif

#endif //WITH_DEV_AUTOMATION_TESTS