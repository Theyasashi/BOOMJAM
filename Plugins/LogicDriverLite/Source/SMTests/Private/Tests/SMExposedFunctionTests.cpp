// Copyright Recursoft LLC 2019-2022. All Rights Reserved.


#include "SMTestHelpers.h"
#include "SMTestContext.h"
#include "Helpers/SMTestBoilerplate.h"

#include "Blueprints/SMBlueprint.h"

#include "Blueprints/SMBlueprintFactory.h"
#include "Utilities/SMBlueprintEditorUtils.h"

#include "Graph/SMGraph.h"
#include "Graph/Nodes/SMGraphK2Node_StateMachineNode.h"
#include "Graph/Nodes/SMGraphNode_StateNode.h"
#include "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#include "Graph/Nodes/Helpers/SMGraphK2Node_StateWriteNodes.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_IntermediateNodes.h"

#include "K2Node_CallFunction.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"
#include "Kismet2/KismetEditorUtilities.h"

#if WITH_DEV_AUTOMATION_TESTS

#if PLATFORM_DESKTOP

#define ENTRYFUNCTIONS_TEST_SETUP() \
SETUP_NEW_STATE_MACHINE_FOR_TEST(2) \
UEdGraphPin* LastStatePin = nullptr; \
TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin); \
FKismetEditorUtilities::CompileBlueprint(NewBP); \
USMGraphNode_StateNodeBase* FirstNode = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->GetEntryNode()->GetOutputNode()); \

static void TestNodePossibilities(FAutomationTestBase* Test, UBlueprint* InBlueprint, USMGraphK2Node_RuntimeNode_Base* InRuntimeNode_Base, USMGraphNode_Base* InGraphNode, UClass* NodeClassToUse)
{
	// No logic.
	{
		InGraphNode->SetNodeClass(nullptr);
		InRuntimeNode_Base->BreakAllNodeLinks();
		FKismetEditorUtilities::CompileBlueprint(InBlueprint);
		
		Test->TestEqual("Has no logic", InRuntimeNode_Base->GetGraphExecutionType(), ESMExposedFunctionExecutionType::SM_None);
		Test->TestTrue("Fast path enabled", InRuntimeNode_Base->IsFastPathEnabled());
	}
		
	// With logic.
	{
		TestHelpers::AddGenericContextLogicToExecutionEntry(Test, InRuntimeNode_Base, GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseEntryInt));
		FKismetEditorUtilities::CompileBlueprint(InBlueprint);
		Test->TestEqual("Has graph logic", InRuntimeNode_Base->GetGraphExecutionType(), ESMExposedFunctionExecutionType::SM_Graph);
		Test->TestFalse("Fast path disabled", InRuntimeNode_Base->IsFastPathEnabled());
	}

	// Node instance.
	{
		InRuntimeNode_Base->BreakAllNodeLinks();
		InGraphNode->SetNodeClass(NodeClassToUse);
		FKismetEditorUtilities::CompileBlueprint(InBlueprint);

		if (InGraphNode->IsA<USMGraphNode_StateMachineStateNode>())
		{
			Test->TestEqual("No instance optimization for state machines", InRuntimeNode_Base->GetGraphExecutionType(),
				ESMExposedFunctionExecutionType::SM_None);
		}
	}
		
	InRuntimeNode_Base->BreakAllNodeLinks();
}

static void TestUSMGraphNode(FAutomationTestBase* Test, UBlueprint* InBlueprint, USMGraphNode_Base* InGraphNode, TSubclassOf<USMNodeInstance> InNodeInstanceClass, int32 ExpectedFunctionNodes)
{
	// Quick way of creating all execution nodes.
	InGraphNode->SetNodeClass(InNodeInstanceClass);

	TArray<USMGraphK2Node_RuntimeNode_Base*> EventExecutionNodes;
	FSMBlueprintEditorUtils::GetAllRuntimeEntryNodes(InGraphNode->GetBoundGraph(), EventExecutionNodes);
	Test->TestEqual("Execution nodes found", EventExecutionNodes.Num(), ExpectedFunctionNodes);

	for (USMGraphK2Node_RuntimeNode_Base* ExecutionNode : EventExecutionNodes)
	{
		if (!ExecutionNode->IsNodePure())
		{
			TestNodePossibilities(Test, InBlueprint, ExecutionNode, InGraphNode, InNodeInstanceClass);
		}
	}
}

/**
 * Check state exposed functions are optimized properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFEntryFunctionsStateOptimizationTest, "LogicDriver.EntryFunctions.Optimization.State", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FFEntryFunctionsStateOptimizationTest::RunTest(const FString& Parameters)
{
	ENTRYFUNCTIONS_TEST_SETUP()

	const int32 TotalExpectedEntryNodes = 3;
	
	TestUSMGraphNode(this, NewBP, FirstNode, USMStateTestInstance::StaticClass(), TotalExpectedEntryNodes);
	
	return NewAsset.DeleteAsset(this);
}

/**
 * Check transition exposed functions are optimized properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEntryFunctionsTransitionOptimizationTest, "LogicDriver.EntryFunctions.Optimization.Transition", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEntryFunctionsTransitionOptimizationTest::RunTest(const FString& Parameters)
{
	ENTRYFUNCTIONS_TEST_SETUP()

	const int32 TotalExpectedEntryNodes = 1;

	USMGraphNode_TransitionEdge* TransitionEdge = FirstNode->GetNextTransition();
	
	TestUSMGraphNode(this, NewBP, TransitionEdge, USMTransitionTestInstance::StaticClass(), TotalExpectedEntryNodes);
	
	return NewAsset.DeleteAsset(this);
}

/**
 * Check conduit exposed functions are optimized properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEntryFunctionsConduitOptimizationTest, "LogicDriver.EntryFunctions.Optimization.Conduit", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEntryFunctionsConduitOptimizationTest::RunTest(const FString& Parameters)
{
	ENTRYFUNCTIONS_TEST_SETUP()

	const int32 TotalExpectedEntryNodes = 1;

	USMGraphNode_ConduitNode* ConduitNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_ConduitNode>(FirstNode);

	TestUSMGraphNode(this, NewBP, ConduitNode, USMConduitTestInstance::StaticClass(), TotalExpectedEntryNodes);
	
	return NewAsset.DeleteAsset(this);
}

/**
 * Check state machine exposed functions are optimized properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEntryFunctionsStateMachineOptimizationTest, "LogicDriver.EntryFunctions.Optimization.StateMachine", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEntryFunctionsStateMachineOptimizationTest::RunTest(const FString& Parameters)
{
	ENTRYFUNCTIONS_TEST_SETUP()

	const int32 TotalExpectedEntryNodes = 3;

	USMGraphNode_StateMachineStateNode* StateMachineNode = FSMBlueprintEditorUtils::CollapseNodesAndCreateStateMachine({FirstNode});
	check(StateMachineNode);
	
	TestUSMGraphNode(this, NewBP, StateMachineNode, USMStateMachineTestInstance::StaticClass(), TotalExpectedEntryNodes);
	
	return NewAsset.DeleteAsset(this);
}

/**
 * Check state machine exposed functions are optimized properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEntryFunctionsStateMachineReferenceOptimizationTest, "LogicDriver.EntryFunctions.Optimization.StateMachineReference", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FEntryFunctionsStateMachineReferenceOptimizationTest::RunTest(const FString& Parameters)
{
	ENTRYFUNCTIONS_TEST_SETUP()

	const int32 TotalExpectedEntryNodes = 3;

	USMGraphNode_StateMachineStateNode* StateMachineNode = FSMBlueprintEditorUtils::CollapseNodesAndCreateStateMachine({FirstNode});
	check(StateMachineNode);

	USMBlueprint* NewReferencedBlueprint = FSMBlueprintEditorUtils::ConvertStateMachineToReference(StateMachineNode, false, nullptr, nullptr);
	FKismetEditorUtilities::CompileBlueprint(NewReferencedBlueprint);

	FAssetHandler ReferencedAsset = TestHelpers::CreateAssetFromBlueprint(NewReferencedBlueprint);

	// No execution nodes to test without intermediate graph.
	StateMachineNode->SetUseIntermediateGraph(true);
	
	TestUSMGraphNode(this, NewBP, StateMachineNode, USMStateMachineTestInstance::StaticClass(), TotalExpectedEntryNodes);

	ReferencedAsset.DeleteAsset(this);
	return NewAsset.DeleteAsset(this);
}

#endif

#endif //WITH_DEV_AUTOMATION_TESTS