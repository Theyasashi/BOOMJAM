// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTestHelpers.h"
#include "SMTestContext.h"
#include "Helpers/SMTestBoilerplate.h"

#include "Blueprints/SMBlueprint.h"

#include "Blueprints/SMBlueprintFactory.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Graph/SMGraph.h"
#include "Graph/SMStateGraph.h"
#include "Graph/Nodes/SMGraphK2Node_StateMachineNode.h"
#include "Graph/Nodes/SMGraphNode_StateNode.h"
#include "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"
#include "Graph/Nodes/SMGraphNode_AnyStateNode.h"
#include "Graph/Nodes/Helpers/SMGraphK2Node_StateReadNodes.h"

#include "EdGraph/EdGraph.h"
#include "Kismet2/KismetEditorUtilities.h"

#include "K2Node_InputKey.h"
#include "InputCoreTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

#if PLATFORM_DESKTOP

/**
 * Test nested state machines' bWaitForEndState flag.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FWaitForEndStateTest, "LogicDriver.States.WaitForEndState", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FWaitForEndStateTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST_NO_STATES()

	// Total states to test.
	int32 TotalTopLevelStates = 3;
	int32 TotalNestedStates = 2;
	
	UEdGraphPin* LastStatePin = nullptr;

	// Build state machine first state.
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, 1, &LastStatePin);

	// Connect nested FSM.
	UEdGraphPin* EntryPointForNestedStateMachine = LastStatePin;
	USMGraphNode_StateMachineStateNode* NestedFSM = TestHelpers::BuildNestedStateMachine(this, StateMachineGraph, TotalNestedStates, &EntryPointForNestedStateMachine, nullptr);
	LastStatePin = NestedFSM->GetOutputPin();
	
	NestedFSM->GetNodeTemplateAs<USMStateMachineInstance>()->SetWaitForEndState(false);

	// Third state regular state.
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, 1, &LastStatePin);

	// Test transition evaluation waiting for end state.
	// [A -> [A -> B] -> C
	{
		int32 EntryHits = 0; int32 UpdateHits = 0; int32 EndHits = 0;
		TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits, UpdateHits, EndHits);
		TestEqual("Didn't wait for end state.", EntryHits, TotalTopLevelStates);
		TestEqual("Didn't wait for end state.", EndHits, TotalTopLevelStates);

		NestedFSM->GetNodeTemplateAs<USMStateMachineInstance>()->SetWaitForEndState(true);

		TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits, UpdateHits, EndHits);
		TestEqual("Waited for end state.", EntryHits, TotalTopLevelStates + TotalNestedStates - 1);
		TestEqual("Waited for end state.", EndHits, TotalTopLevelStates + TotalNestedStates - 1);
	}

	USMGraphNode_StateMachineStateNode* EndFSM = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(NestedFSM->GetNextNode());
	TestHelpers::BuildLinearStateMachine(this, CastChecked<USMGraph>(EndFSM->GetBoundGraph()), TotalNestedStates, nullptr);

	TotalNestedStates *= 2;
	
	// Test root end state not being considered until fsm is in end state.
	// [A -> [A -> B] -> [A -> B]
	{
		int32 EntryHits = 0; int32 UpdateHits = 0; int32 EndHits = 0;
		// Will hit all states of first FSM, then stop on first state of second fsm.
		TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits, UpdateHits, EndHits);
		TestEqual("Didn't wait for end state.", EntryHits, 4); // [A -> [A -> B] -> [A]
		TestEqual("Didn't wait for end state.", EndHits, 4);

		EndFSM->GetNodeTemplateAs<USMStateMachineInstance>()->SetWaitForEndState(true);

		// Will hit all states of all FSMs. This test doesn't stop until the root state machine is in an end state.
		TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits, UpdateHits, EndHits);
		TestEqual("Waited for end state.", EntryHits, TotalTopLevelStates + TotalNestedStates - 2); // [A -> [A -> B] -> [A -> B]
		TestEqual("Waited for end state.", EndHits, TotalTopLevelStates + TotalNestedStates - 2);
	}
	
	return true;
}

/**
 * Test creating an any state node.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnyStateTest, "LogicDriver.States.AnyStateTest", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FAnyStateTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST_NO_STATES()

	// Total states to test.
	UEdGraphPin* LastStatePin = nullptr;
	
	// Build a state machine of only two states.
	{
		const int32 CurrentStates = 2;
		TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, CurrentStates, &LastStatePin);
	}

	USMGraphNode_StateNodeBase* LastNormalState = CastChecked<USMGraphNode_StateNodeBase>(LastStatePin->GetOwningNode());
	LastNormalState->GetNodeTemplateAs<USMStateInstance_Base>()->SetExcludeFromAnyState(false);
	
	// Add any state.
	FGraphNodeCreator<USMGraphNode_AnyStateNode> AnyStateNodeCreator(*StateMachineGraph);
	USMGraphNode_AnyStateNode* AnyState = AnyStateNodeCreator.CreateNode();
	AnyStateNodeCreator.Finalize();

	FString AnyStateInitialStateName = "AnyState_Initial";
	{
		UEdGraphPin* InputPin = AnyState->GetOutputPin();

		// Connect a state to anystate.
		TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, 1, &InputPin);

		AnyState->GetNextNode()->GetBoundGraph()->Rename(*AnyStateInitialStateName, nullptr, REN_DontCreateRedirectors);
	}

	USMGraphNode_TransitionEdge* TransitionEdge = AnyState->GetNextTransition();
	TransitionEdge->GetNodeTemplateAs<USMTransitionInstance>()->SetPriorityOrder(1);
	TestTrue("Graph Transition from Any State", TransitionEdge->IsFromAnyState());

	{
		FKismetEditorUtilities::CompileBlueprint(NewBP);
		USMTestContext* Context = NewObject<USMTestContext>();
		USMInstance* Instance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

		TArray<USMTransitionInstance*> RuntimeTransitions;
		Instance->GetAllTransitionInstances(RuntimeTransitions);
		check(RuntimeTransitions.Num() == 3);
		TestTrue("Runtime transition from Any State", RuntimeTransitions[0]->IsTransitionFromAnyState());
		TestTrue("Runtime transition from Any State", RuntimeTransitions[1]->IsTransitionFromAnyState());
		TestFalse("Runtime transition not from Any State", RuntimeTransitions[2]->IsTransitionFromAnyState());
		
		TArray<USMStateInstance_Base*> RuntimeStates;
		Instance->GetAllStateInstances(RuntimeStates);
		check(RuntimeStates.Num() == 4);
		TestFalse("Runtime state outgoing transitions Any State", RuntimeStates[0]->AreAllOutgoingTransitionsFromAnAnyState());
		TestFalse("Runtime state outgoing transitions Any State", RuntimeStates[1]->AreAllOutgoingTransitionsFromAnAnyState());
		TestTrue("Runtime state outgoing transitions Any State", RuntimeStates[2]->AreAllOutgoingTransitionsFromAnAnyState());
		TestFalse("Runtime state outgoing transitions Any State", RuntimeStates[3]->AreAllOutgoingTransitionsFromAnAnyState());

		TestFalse("Runtime state incoming transitions Any State", RuntimeStates[0]->AreAllIncomingTransitionsFromAnAnyState());
		TestTrue("Runtime state incoming transitions Any State", RuntimeStates[1]->AreAllIncomingTransitionsFromAnAnyState());
		TestFalse("Runtime state incoming transitions Any State", RuntimeStates[2]->AreAllIncomingTransitionsFromAnAnyState());
		TestFalse("Runtime state incoming transitions Any State", RuntimeStates[3]->AreAllIncomingTransitionsFromAnAnyState());
		
		Instance->Start();
		TestEqual("State machine still in initial state", Instance->GetRootStateMachine().GetSingleActiveState(), Instance->GetRootStateMachine().GetSingleInitialState());

		// Any state shouldn't be triggered because priority is lower.
		Instance->Update();
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		TestFalse("Not considered end state", Instance->IsInEndState());
		
		// No other transitions left except any state.
		Instance->Update();
		TestEqual("Any state transition called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);
		
		Instance->Shutdown();
	}
	
	TransitionEdge->GetNodeTemplateAs<USMTransitionInstance>()->SetPriorityOrder(-1);
	
	{
		FKismetEditorUtilities::CompileBlueprint(NewBP);
		USMTestContext* Context = NewObject<USMTestContext>();
		USMInstance* Instance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

		Instance->Start();
		TestEqual("State machine still in initial state", Instance->GetRootStateMachine().GetSingleActiveState(), Instance->GetRootStateMachine().GetSingleInitialState());

		// Any state should evaluate first.
		Instance->Update();
		TestEqual("Any state transition called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		Instance->Shutdown();
	}
	
	// Try reference nodes such as Time in State
	{
		TestHelpers::AddSpecialFloatTransitionLogic<USMGraphK2Node_StateReadNode_TimeInState>(this, TransitionEdge);
		FKismetEditorUtilities::CompileBlueprint(NewBP);
		USMTestContext* Context = NewObject<USMTestContext>();
		USMInstance* Instance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

		Instance->Start();
		TestEqual("State machine still in initial state", Instance->GetRootStateMachine().GetSingleActiveState(), Instance->GetRootStateMachine().GetSingleInitialState());

		// Any state shouldn't be triggered yet.
		Instance->Update(1);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);
		TestFalse("Not considered end state because any state is not excluded from end.", Instance->IsInEndState());
		
		Instance->Update(3);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		Instance->Update(3);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);
		
		Instance->Update(1);
		TestEqual("Any state transition called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		Instance->Shutdown();
	}

	LastNormalState->GetNodeTemplateAs<USMStateInstance_Base>()->SetExcludeFromAnyState(true);

	// Try reference nodes such as Time in State
	{
		TestHelpers::AddSpecialFloatTransitionLogic<USMGraphK2Node_StateReadNode_TimeInState>(this, TransitionEdge);
		FKismetEditorUtilities::CompileBlueprint(NewBP);
		USMTestContext* Context = NewObject<USMTestContext>();
		USMInstance* Instance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

		Instance->Start();
		TestEqual("State machine still in initial state", Instance->GetRootStateMachine().GetSingleActiveState(), Instance->GetRootStateMachine().GetSingleInitialState());

		// Any state shouldn't be triggered yet.
		Instance->Update(1);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);
		TestTrue("Considered end state because any state is excluded from end.", Instance->IsInEndState());

		Instance->Update(3);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		// Should not be called because last state is excluded.
		Instance->Update(5);
		TestNotEqual("Any state transition not called", Instance->GetRootStateMachine().GetSingleActiveState()->GetNodeName(), AnyStateInitialStateName);

		Instance->Shutdown();
	}
	
	return true;
}

#endif

#endif //WITH_DEV_AUTOMATION_TESTS