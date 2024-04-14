// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTestHelpers.h"
#include "SMTestContext.h"
#include "Helpers/SMTestBoilerplate.h"

#include "Utilities/SMBlueprintEditorUtils.h"
#include "Blueprints/SMBlueprintFactory.h"
#include "Graph/SMGraph.h"
#include "Graph/SMStateGraph.h"
#include "Graph/Nodes/SMGraphK2Node_StateMachineNode.h"
#include "Graph/Nodes/SMGraphNode_StateNode.h"
#include "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"

#include "Blueprints/SMBlueprint.h"
#include "SMUtils.h"
#include "SMRuntimeSettings.h"

#include "Kismet2/KismetEditorUtilities.h"

#if WITH_DEV_AUTOMATION_TESTS

#if PLATFORM_DESKTOP

/**
 * Run a state machine consisting of 100 custom state classes with custom transitions.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNodeInstanceRunStateMachineTest, "LogicDriver.NodeInstance.RunStateMachine", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FNodeInstanceRunStateMachineTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(100)
	UEdGraphPin* LastStatePin = nullptr;
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin, USMStateTestInstance::StaticClass(), USMTransitionTestInstance::StaticClass());
	TestHelpers::TestLinearStateMachine(this, NewBP, TotalStates);

	return true;
}

/**
 * Verify node instance struct wrapper methods work properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNodeInstanceMethodsTest, "LogicDriver.NodeInstance.Methods", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FNodeInstanceMethodsTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(2)

	{
		UEdGraphPin* LastStatePin = nullptr;
		//Verify default instances load correctly.
		TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin, USMStateInstance::StaticClass(), USMTransitionInstance::StaticClass());
		int32 A, B, C;
		TestHelpers::RunStateMachineToCompletion(this, NewBP, A, B, C);
		FSMBlueprintEditorUtils::RemoveAllNodesFromGraph(StateMachineGraph);
	}
	
	// Load test instances.
	UEdGraphPin* LastStatePin = nullptr;
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin, USMStateTestInstance::StaticClass(), USMTransitionTestInstance::StaticClass());
	FKismetEditorUtilities::CompileBlueprint(NewBP);
	
	USMTestContext* Context = NewObject<USMTestContext>();
	USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);
	
	FSMState_Base* InitialState = StateMachineInstance->GetRootStateMachine().GetSingleInitialState();
	USMStateInstance_Base* NodeInstance = CastChecked<USMStateInstance_Base>(InitialState->GetNodeInstance());
	InitialState->bAlwaysUpdate = true; // Needed since we are manually switching states later.

	{
		// Test root and entry nodes.
		
		USMStateMachineInstance* RootStateMachineInstance = StateMachineInstance->GetRootStateMachineNodeInstance();
		TestNotNull("Root node not null", RootStateMachineInstance);
		TestEqual("Root node discoverable", RootStateMachineInstance, Cast<USMStateMachineInstance>(StateMachineInstance->GetRootStateMachine().GetNodeInstance()));

		TArray<USMStateInstance_Base*> EntryStates;
		RootStateMachineInstance->GetEntryStates(EntryStates);
		check(EntryStates.Num() == 1);

		TestEqual("Entry states discoverable", EntryStates[0], NodeInstance);
		TestTrue("Entry state is configured", EntryStates[0]->IsEntryState());
	}
	
	TestEqual("Correct state machine", NodeInstance->GetStateMachineInstance(), StateMachineInstance);
	TestEqual("Guids correct", NodeInstance->GetGuid(), InitialState->GetGuid());
	TestEqual("Name correct", NodeInstance->GetNodeName(), InitialState->GetNodeName());
	
	TestFalse("Initial state not active", NodeInstance->IsActive());
	StateMachineInstance->Start();
	TestTrue("Initial state active", NodeInstance->IsActive());

	InitialState->TimeInState = 3;
	TestEqual("Time correct", NodeInstance->GetTimeInState(), InitialState->TimeInState);

	FSMStateInfo StateInfo;
	NodeInstance->GetStateInfo(StateInfo);

	TestEqual("State info guids correct", StateInfo.Guid, InitialState->GetGuid());
	TestEqual("State info instance correct", StateInfo.NodeInstance, Cast<USMNodeInstance>(NodeInstance));
	TestFalse("Not a state machine", NodeInstance->IsStateMachine());
	TestFalse("Not in end state", NodeInstance->IsInEndState());
	TestFalse("Has not updated", NodeInstance->HasUpdated());
	TestNull("No transition to take", NodeInstance->GetTransitionToTake());

	USMStateInstance_Base* NextState = CastChecked<USMStateInstance_Base>(InitialState->GetOutgoingTransitions()[0]->GetToState()->GetNodeInstance());

	// Test searching nodes.
	TArray<USMNodeInstance*> FoundNodes;
	NodeInstance->GetAllNodesOfType(FoundNodes, USMStateInstance::StaticClass());

	TestEqual("All nodes found", FoundNodes.Num(), TotalStates);
	TestEqual("Correct state found", FoundNodes[0], Cast<USMNodeInstance>(NodeInstance));
	TestEqual("Correct state found", FoundNodes[1], Cast<USMNodeInstance>(NextState));
	TestFalse("Initial state not set", NextState->IsEntryState());
	
	// Verify state machine instance methods to retrieve node instances are correct.
	TArray<USMStateInstance_Base*> StateInstances;
	StateMachineInstance->GetAllStateInstances(StateInstances);
	TestEqual("All states found", StateInstances.Num(), StateMachineInstance->GetStateMap().Num());
	for (USMStateInstance_Base* StateInstance : StateInstances)
	{
		USMStateInstance_Base* FoundStateInstance = StateMachineInstance->GetStateInstanceByGuid(StateInstance->GetGuid());
		TestEqual("State instance retrieved from sm instance", FoundStateInstance, StateInstance);
		if (StateInstance->GetOwningNode() != InitialState)
		{
			TestFalse("Initial state not set", NextState->IsEntryState());
		}
	}
	
	TArray<USMTransitionInstance*> TransitionInstances;
	StateMachineInstance->GetAllTransitionInstances(TransitionInstances);
	TestEqual("All transitions found", TransitionInstances.Num(), StateMachineInstance->GetTransitionMap().Num());
	for (USMTransitionInstance* TransitionInstance : TransitionInstances)
	{
		USMTransitionInstance* FoundTransitionInstance = StateMachineInstance->GetTransitionInstanceByGuid(TransitionInstance->GetGuid());
		TestEqual("Transition instance retrieved from sm instance", FoundTransitionInstance, TransitionInstance);
	}
	
	// Test transition instance.
	USMTransitionInstance* NextTransition = CastChecked<USMTransitionInstance>(InitialState->GetOutgoingTransitions()[0]->GetNodeInstance());
	{
		TArray<USMTransitionInstance*> Transitions;
		NodeInstance->GetOutgoingTransitions(Transitions);

		TestEqual("One outgoing transition", Transitions.Num(), 1);
		USMTransitionInstance* TransitionInstance = Transitions[0];

		TestEqual("Transition instance correct", TransitionInstance, NextTransition);
		
		FSMTransitionInfo TransitionInfo;
		TransitionInstance->GetTransitionInfo(TransitionInfo);

		TestEqual("Transition info instance correct", TransitionInfo.NodeInstance, Cast<USMNodeInstance>(NextTransition));

		TestEqual("Prev state correct", TransitionInstance->GetPreviousStateInstance(), NodeInstance);
		TestEqual("Next state correct", TransitionInstance->GetNextStateInstance(), NextState);

		TestNull("Source state correct", TransitionInstance->GetSourceStateForActiveTransition());
		TestNull("Dest state correct", TransitionInstance->GetDestinationStateForActiveTransition());
	}

	{
		bool bResult = NodeInstance->SwitchToLinkedState(NextState);
		TestTrue("Transition taken", bResult);
	}
	
	TestFalse("State no longer active", NodeInstance->IsActive());
	TestTrue("Node has updated from bAlwaysUpdate", NodeInstance->HasUpdated());
	TestEqual("Transition to take set", NodeInstance->GetTransitionToTake(), NextTransition);

	{
		// Source/Dest states should have updated after taking the transition.
		
		USMTransitionInstance* PreviousTransition = NextTransition;
	
		TestEqual("Source state correct", PreviousTransition->GetSourceStateForActiveTransition(), NodeInstance);
		TestEqual("Dest state correct", PreviousTransition->GetDestinationStateForActiveTransition(), NextState);
	}
	
	USMTransitionInstance* PreviousTransition = CastChecked<USMTransitionInstance>((NextState->GetOwningNodeAs<FSMState_Base>())->GetIncomingTransitions()[0]->GetNodeInstance());
	{
		TestEqual("Previous transition is correct instance", PreviousTransition, NextTransition);
		
		TArray<USMTransitionInstance*> Transitions;
		NextState->GetIncomingTransitions(Transitions);

		TestEqual("One incoming transition", Transitions.Num(), 1);
		USMTransitionInstance* TransitionInstance = Transitions[0];

		TestEqual("Transition instance correct", TransitionInstance, PreviousTransition);

		FSMTransitionInfo TransitionInfo;
		TransitionInstance->GetTransitionInfo(TransitionInfo);

		TestEqual("Transition info instance correct", TransitionInfo.NodeInstance, Cast<USMNodeInstance>(PreviousTransition));

		TestEqual("Prev state correct", TransitionInstance->GetPreviousStateInstance(), NodeInstance);
		TestEqual("Next state correct", TransitionInstance->GetNextStateInstance(), NextState);
	}

	NodeInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetSingleActiveState()->GetNodeInstance());
	TestTrue("Is end state", NodeInstance->IsInEndState());

	// Test State Name Retrieval per FSM.
	{
		StateMachineInstance->Stop();
		StateMachineInstance->Start();

		InitialState = StateMachineInstance->GetRootStateMachine().GetSingleInitialState();
		NodeInstance = CastChecked<USMStateInstance_Base>(InitialState->GetNodeInstance());
		
		bool bResult = NodeInstance->SwitchToLinkedStateByName(NextState->GetNodeName());
		TestTrue("Transition taken", bResult);
		
		TestFalse("State no longer active", NodeInstance->IsActive());
		TestEqual("State switched by name", StateMachineInstance->GetSingleActiveStateInstance(), NextState);
		TestTrue("Node has updated from bAlwaysUpdate", NodeInstance->HasUpdated());
		TestEqual("Transition to take set", NodeInstance->GetTransitionToTake(), NextTransition);

		TestTrue("Next state activated", NodeInstance->GetTransitionByIndex(0)->GetNextStateInstance()->IsActive());
		StateMachineInstance->Update();
		TestTrue("Next state active", NodeInstance->GetTransitionByIndex(0)->GetNextStateInstance()->IsActive());
	}

	// Test Switch to linked state by transition.
	{
		StateMachineInstance->Stop();
		StateMachineInstance->Start();

		InitialState = StateMachineInstance->GetRootStateMachine().GetSingleInitialState();
		NodeInstance = CastChecked<USMStateInstance_Base>(InitialState->GetNodeInstance());

		USMTransitionInstance* TransitionToUse = NodeInstance->GetTransitionByIndex(0);
		bool bResult = NodeInstance->SwitchToLinkedStateByTransition(TransitionToUse);
		TestTrue("Transition taken", bResult);

		USMStateInstance_Base* NextStateInstance = TransitionToUse->GetNextStateInstance();
		
		TestFalse("State no longer active", NodeInstance->IsActive());
		TestEqual("State switched by name", StateMachineInstance->GetSingleActiveStateInstance(), NextState);
		TestTrue("Node has updated from bAlwaysUpdate", NodeInstance->HasUpdated());
		TestEqual("Transition to take set", NodeInstance->GetTransitionToTake(), NextTransition);

		TestTrue("Next state activated", NextStateInstance->IsActive());
		StateMachineInstance->Update();
		TestTrue("Next state active", NextStateInstance->IsActive());

		AddExpectedError("Attempted to switch to linked state by transition", EAutomationExpectedErrorFlags::Contains, 1);
		bResult = NextStateInstance->SwitchToLinkedStateByTransition(TransitionToUse);
		TestFalse("Did not switch to a state from a transition with a different 'FromState'", bResult);
		TestTrue("Next state active", NextStateInstance->IsActive());
		TestFalse("Previous state still not active", NodeInstance->IsActive());
	}
	
	//  Test nested reference FSM can retrieve transitions.
	{
		LastStatePin = nullptr;
		FSMBlueprintEditorUtils::RemoveAllNodesFromGraph(StateMachineGraph, NewBP);
		TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin);

		USMGraphNode_StateMachineStateNode* NestedFSM = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->EntryNode->GetOutputNode()));
		FKismetEditorUtilities::CompileBlueprint(NewBP);

		USMBlueprint* NewReferencedBlueprint = FSMBlueprintEditorUtils::ConvertStateMachineToReference(NestedFSM, false, nullptr, nullptr);

		Context = NewObject<USMTestContext>();
		StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);
		USMStateMachineInstance* FSMClass = CastChecked< USMStateMachineInstance>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());

		TArray<USMTransitionInstance*> Transitions;
		FSMClass->GetOutgoingTransitions(Transitions);
		TestEqual("Outgoing transitions found of reference FSM", Transitions.Num(), 1);
	}
	
	return true;
}

/**
 * Test nested state machines with a state machine class set evaluate graphs properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNodeInstanceStateMachineClassTest, "LogicDriver.NodeInstance.StateMachineClass", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FNodeInstanceStateMachineClassTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(2)

	UEdGraphPin* LastStatePin = nullptr;

	// Build state machine.
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin, USMStateTestInstance::StaticClass(), USMTransitionTestInstance::StaticClass());

	USMGraphNode_StateMachineStateNode* NestedFSMNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(CastChecked<USMGraphNode_Base>(StateMachineGraph->GetEntryNode()->GetOutputNode()));
	USMGraphNode_StateMachineStateNode* NestedFSMNode2 = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(NestedFSMNode->GetNextNode());

	TestHelpers::SetNodeClass(this, NestedFSMNode, USMStateMachineTestInstance::StaticClass());
	TestHelpers::SetNodeClass(this, NestedFSMNode2, USMStateMachineTestInstance::StaticClass());

	FKismetEditorUtilities::CompileBlueprint(NewBP);
	
	USMTestContext* Context = NewObject<USMTestContext>();
	USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

	FSMState_Base* InitialState = StateMachineInstance->GetRootStateMachine().GetSingleInitialState();
	USMStateMachineTestInstance* NodeInstance = CastChecked<USMStateMachineTestInstance>(InitialState->GetNodeInstance());
	InitialState->bAlwaysUpdate = true; // Needed since we are manually switching states later.

	TestEqual("Correct state machine", NodeInstance->GetStateMachineInstance(), StateMachineInstance);
	TestEqual("Guids correct", NodeInstance->GetGuid(), InitialState->GetGuid());
	TestEqual("Name correct", NodeInstance->GetNodeName(), InitialState->GetNodeName());
	
	TestFalse("Initial state not active", NodeInstance->IsActive());
	
	StateMachineInstance->Start();

	TestTrue("Initial state active", NodeInstance->IsActive());
	InitialState->TimeInState = 3;
	TestEqual("Time correct", NodeInstance->GetTimeInState(), InitialState->TimeInState);
	
	FSMStateInfo StateInfo;
	NodeInstance->GetStateInfo(StateInfo);

	TestEqual("State info guids correct", StateInfo.Guid, InitialState->GetGuid());
	TestEqual("State info instance correct", StateInfo.NodeInstance, Cast<USMNodeInstance>(NodeInstance));
	TestTrue("Is a state machine", NodeInstance->IsStateMachine());
	TestFalse("Has not updated", NodeInstance->HasUpdated());
	TestNull("No transition to take", NodeInstance->GetTransitionToTake());

	USMStateMachineTestInstance* NextState = CastChecked<USMStateMachineTestInstance>(InitialState->GetOutgoingTransitions()[0]->GetToState()->GetNodeInstance());

	// Test transition instance.
	USMTransitionInstance* NextTransition = CastChecked<USMTransitionInstance>(InitialState->GetOutgoingTransitions()[0]->GetNodeInstance());
	{
		TArray<USMTransitionInstance*> Transitions;
		NodeInstance->GetOutgoingTransitions(Transitions);

		TestEqual("One outgoing transition", Transitions.Num(), 1);
		USMTransitionInstance* TransitionInstance = Transitions[0];

		TestEqual("Transition instance correct", TransitionInstance, NextTransition);

		FSMTransitionInfo TransitionInfo;
		TransitionInstance->GetTransitionInfo(TransitionInfo);

		TestEqual("Transition info instance correct", TransitionInfo.NodeInstance, Cast<USMNodeInstance>(NextTransition));

		TestEqual("Prev state correct", Cast<USMStateMachineTestInstance>(TransitionInstance->GetPreviousStateInstance()), NodeInstance);
		TestEqual("Next state correct", Cast<USMStateMachineTestInstance>(TransitionInstance->GetNextStateInstance()), NextState);
	}
	
	StateMachineInstance->Update(0.f);

	TestFalse("State no longer active", NodeInstance->IsActive());
	TestTrue("Node has updated from bAlwaysUpdate", NodeInstance->HasUpdated());
	TestEqual("Transition to take set", NodeInstance->GetTransitionToTake(), NextTransition);

	NodeInstance = CastChecked<USMStateMachineTestInstance>(StateMachineInstance->GetSingleActiveState()->GetNodeInstance());
	TestTrue("Is end state", NodeInstance->IsInEndState());

	StateMachineInstance->Stop();
	
	return true;
}

/**
 * Check behavior and optimizations around default node classes and loading them on demand.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNodeInstanceOnDemandTest, "LogicDriver.NodeInstance.OnDemand", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FNodeInstanceOnDemandTest::RunTest(const FString& Parameters)
{
	SETUP_NEW_STATE_MACHINE_FOR_TEST(4)

	UEdGraphPin* LastStatePin = nullptr;

	// Build single state - state machine.
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin, USMStateInstance::StaticClass(), USMTransitionInstance::StaticClass());

	UClass* TestNodeClass = USMStateTestInstance::StaticClass();
	USMGraphNode_StateNode* LastState = CastChecked<USMGraphNode_StateNode>(LastStatePin->GetOwningNode());
	TestHelpers::SetNodeClass(this, LastState, TestNodeClass);

	FKismetEditorUtilities::CompileBlueprint(NewBP);

	GetMutableDefault<USMRuntimeSettings>()->bPreloadDefaultNodes = true;
	{
		USMInstance* Instance = USMBlueprintUtils::CreateStateMachineInstance(NewBP->GetGeneratedClass(), NewObject<USMTestContext>());

		for (const auto& KeyVal : Instance->GetNodeMap())
		{
			USMNodeInstance* NodeInstance = KeyVal.Value->GetNodeInstance();
			TestNotNull("Node instance created",  NodeInstance);
		}
	}

	auto TestInstance = [this, TestNodeClass](const USMInstance* Instance, bool bExpectAllValid = false)
	{
		bool bFound = false;
		for (const auto& KeyVal : Instance->GetNodeMap())
		{
			USMNodeInstance* NodeInstance = KeyVal.Value->GetNodeInstance();
			if (NodeInstance || bExpectAllValid)
			{
				if (bExpectAllValid)
				{
					TestNotNull("Instance valid", NodeInstance);
					continue;
				}
				TestFalse("Only 1 node instance exists", bFound);
				TestEqual("Node instance created during initialization", NodeInstance->GetClass(), TestNodeClass);
				bFound = true;
			}
			else
			{
				TestNull("Node instance not created.", KeyVal.Value->GetNodeInstance());
				NodeInstance = KeyVal.Value->GetOrCreateNodeInstance();
				TestNotNull("Node instance created",  NodeInstance);
			}
		}	
	};
	
	GetMutableDefault<USMRuntimeSettings>()->bPreloadDefaultNodes = false;
	{
		USMInstance* Instance = USMBlueprintUtils::CreateStateMachineInstance(NewBP->GetGeneratedClass(), NewObject<USMTestContext>());
		TestInstance(Instance);
	}

	// Test running the state machine and verifying nodes are not created by default.
	{
		USMInstance* Instance = USMBlueprintUtils::CreateStateMachineInstance(NewBP->GetGeneratedClass(), NewObject<USMTestContext>());
		TestHelpers::RunAllStateMachinesToCompletion(this, Instance);
		TestInstance(Instance);

		TArray<USMStateInstance_Base*> States;
		TArray<USMTransitionInstance*> Transitions;
		Instance->GetAllStateInstances(States);
		Instance->GetAllTransitionInstances(Transitions);
		TestInstance(Instance, true);
	}

	// Test preload all nodes.
	{
		USMInstance* Instance = USMBlueprintUtils::CreateStateMachineInstance(NewBP->GetGeneratedClass(), NewObject<USMTestContext>());
		Instance->PreloadAllNodeInstances();
		TestInstance(Instance, true);
	}
	
	return NewAsset.DeleteAsset(this);
}

#endif

#endif //WITH_DEV_AUTOMATION_TESTS