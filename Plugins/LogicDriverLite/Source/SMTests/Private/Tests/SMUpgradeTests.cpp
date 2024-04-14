// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "Blueprints/SMBlueprint.h"
#include "SMTestHelpers.h"
#include "Blueprints/SMBlueprintFactory.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Utilities/SMVersionUtils.h"
#include "SMTestContext.h"
#include "Graph/SMConduitGraph.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Graph/SMGraph.h"
#include "Graph/SMStateGraph.h"
#include "Graph/SMIntermediateGraph.h"
#include "Graph/Schema/SMGraphK2Schema.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_StateMachineSelectNode.h"
#include "Graph/Nodes/SMGraphK2Node_StateMachineNode.h"
#include "Graph/Nodes/SMGraphNode_StateNode.h"
#include "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionInitializedNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionShutdownNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionPreEvaluateNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionPostEvaluateNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionEnteredNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_StateEndNode.h"
#include "Graph/Nodes/RootNodes/SMGraphK2Node_StateUpdateNode.h"


#if WITH_DEV_AUTOMATION_TESTS

#if PLATFORM_DESKTOP

/**
 * Validate old blueprints can be updated properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUpdateBlueprintVersionTest, "LogicDriver.Upgrade.UpdateBlueprintVersion", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

	bool FUpdateBlueprintVersionTest::RunTest(const FString& Parameters)
{
	FAssetHandler NewSMAsset;
	if (!TestHelpers::TryCreateNewStateMachineAsset(this, NewSMAsset, false))
	{
		return false;
	}

	USMBlueprint* NewBP = NewSMAsset.GetObjectAs<USMBlueprint>();
	NewBP->AssetVersion = 0;
	{
		// Verify new version set correctly.
		TestFalse("Instance version is not correctly created", FSMVersionUtils::IsAssetUpToDate(NewBP));
		NewSMAsset.SaveAsset(this);
		TestFalse("Asset saved and not dirty", NewBP->GetOutermost()->IsDirty());
	}

	FSMVersionUtils::UpdateBlueprintsToNewVersion();

	TestTrue("SM Asset dirty after update", NewBP->GetOutermost()->IsDirty());
	TestTrue("SM Asset up to date", FSMVersionUtils::IsAssetUpToDate(NewBP));

	return NewSMAsset.DeleteAsset(this);
}

/**
 * Validate pre 2.3 nodes have their templates setup properly and deprecated node values are imported.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUpdateNodeTemplateTest, "LogicDriver.Upgrade.UpdateNodeTemplate", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)
	bool FUpdateNodeTemplateTest::RunTest(const FString& Parameters)
{
	FAssetHandler NewAsset;
	if (!TestHelpers::TryCreateNewStateMachineAsset(this, NewAsset, false))
	{
		return false;
	}

	USMBlueprint* NewBP = NewAsset.GetObjectAs<USMBlueprint>();

	// Find root state machine.
	USMGraphK2Node_StateMachineNode* RootStateMachineNode = FSMBlueprintEditorUtils::GetRootStateMachineNode(NewBP);

	// Find the state machine graph.
	USMGraph* StateMachineGraph = RootStateMachineNode->GetStateMachineGraph();

	// Total states to test.
	int32 TotalStates = 3;

	// Load default instances.
	UEdGraphPin* LastStatePin = nullptr;
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, TotalStates, &LastStatePin);

	// Test importing state values.
	{
		USMGraphNode_StateNodeBase* FirstState = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->EntryNode->GetOutputNode());
		// Default templates
		{
			FirstState->DestroyTemplate();

			TestFalse("Default value correct", FirstState->bDisableTickTransitionEvaluation_DEPRECATED);
			TestFalse("Default value correct", FirstState->bEvalTransitionsOnStart_DEPRECATED);
			TestFalse("Default value correct", FirstState->bExcludeFromAnyState_DEPRECATED);
			TestFalse("Default value correct", FirstState->bAlwaysUpdate_DEPRECATED);

			FirstState->bDisableTickTransitionEvaluation_DEPRECATED = true;
			FirstState->bEvalTransitionsOnStart_DEPRECATED = true;
			FirstState->bExcludeFromAnyState_DEPRECATED = true;
			FirstState->bAlwaysUpdate_DEPRECATED = true;

			FirstState->ForceSetVersion(0);
			FirstState->ConvertToCurrentVersion(true);
			TestNull("Template still null since this wasn't a load.", FirstState->GetNodeTemplate());

			FirstState->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", FirstState->GetNodeTemplate());

			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());

				// Default class templates don't get compiled into the CDO, but the Getters will retrieve the struct version which should be the new values.
				TestTrue("Default value imported to runtime", StateInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", StateInstance->GetEvalTransitionsOnStart());
				TestFalse("Default value NOT imported to runtime", StateInstance->GetExcludeFromAnyState()); // Not stored on node.
				TestTrue("Default value imported to runtime", StateInstance->GetAlwaysUpdate());
			}
		}

		// Existing templates
		{
			const int32 TestInt = 7;
			{
				// Apply user template to a node that already has a default template created.
				FirstState->SetNodeClass(USMStateTestInstance::StaticClass());

				// Defaults already set since we are applying the node class after the initial template was created. Old values should be copied to new template.
				TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
				TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
				TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			}

			// Recreate so there are no existing values to be copied.
			{
				FirstState->DestroyTemplate();
				FirstState->SetNodeClass(USMStateTestInstance::StaticClass());
			}

			FirstState->ForceSetVersion(0);
			FirstState->ConvertToCurrentVersion(true);
			TestFalse("Default value not imported since it's not load", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestFalse("Default value not imported since it's not load", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestFalse("Default value not imported since it's not load", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestFalse("Default value not imported since it's not load", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			FirstState->ForceSetVersion(0);
			FirstState->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", FirstState->GetNodeTemplate());

			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", FirstState->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateTestInstance* StateInstance = CastChecked<USMStateTestInstance>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());

				// User templates get copied to the CDO so their values should match the node values.
				TestTrue("Default value imported to runtime", StateInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", StateInstance->GetEvalTransitionsOnStart());
				TestTrue("Default value imported to runtime", StateInstance->GetExcludeFromAnyState());
				TestTrue("Default value imported to runtime", StateInstance->GetAlwaysUpdate());
			}
		}
	}

	// Test importing transition values.
	{
		const int32 PriorityOrder = 4;
		USMGraphNode_TransitionEdge* Transition = CastChecked<USMGraphNode_TransitionEdge>(CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->EntryNode->GetOutputNode())->GetNextTransition());
		// Default templates.
		{
			Transition->DestroyTemplate();

			TestEqual("Default value correct", Transition->PriorityOrder_DEPRECATED, 0);
			TestTrue("Default value correct", Transition->bCanEvaluate_DEPRECATED);
			TestTrue("Default value correct", Transition->bCanEvaluateFromEvent_DEPRECATED);
			TestTrue("Default value correct", Transition->bCanEvalWithStartState_DEPRECATED);

			Transition->PriorityOrder_DEPRECATED = PriorityOrder;
			Transition->bCanEvaluate_DEPRECATED = false;
			Transition->bCanEvaluateFromEvent_DEPRECATED = false;
			Transition->bCanEvalWithStartState_DEPRECATED = false;

			Transition->ForceSetVersion(0);
			Transition->ConvertToCurrentVersion(true);
			TestNull("Template still null since this wasn't a load.", Transition->GetNodeTemplate());

			Transition->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", Transition->GetNodeTemplate());

			TestEqual("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetPriorityOrder(), PriorityOrder);
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluate());
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluateFromEvent());
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvalWithStartState());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				TArray<USMTransitionInstance*> Transitions;
				StateInstance->GetOutgoingTransitions(Transitions, false);
				USMTransitionInstance* TransitionInstance = Transitions[0];

				// Default class templates don't get compiled into the CDO, but the Getters will retrieve the struct version which should be the new values.
				TestEqual("Default value imported to runtime", TransitionInstance->GetPriorityOrder(), PriorityOrder);
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvaluate());
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvaluateFromEvent());
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvalWithStartState());
			}
		}

		// Existing templates
		{
			const int32 TestInt = 7;
			{
				// Apply user template to a node that already has a default template created.
				Transition->SetNodeClass(USMTransitionTestInstance::StaticClass());

				// Defaults already set since we are applying the node class after the initial template was created. Old values should be copied to new template.
				TestEqual("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetPriorityOrder(), PriorityOrder);
				TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluate());
				TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluateFromEvent());
				TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvalWithStartState());
			}

			// Recreate so there are no existing values to be copied.
			{
				Transition->DestroyTemplate();
				Transition->SetNodeClass(USMTransitionTestInstance::StaticClass());
			}

			Transition->ForceSetVersion(0);
			Transition->ConvertToCurrentVersion(true);
			TestEqual("Default value not imported since it's not load", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetPriorityOrder(), 0);
			TestTrue("Default value not imported since it's not load", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluate());
			TestTrue("Default value not imported since it's not load", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluateFromEvent());
			TestTrue("Default value not imported since it's not load", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvalWithStartState());

			Transition->ForceSetVersion(0);
			Transition->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", Transition->GetNodeTemplate());

			TestEqual("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetPriorityOrder(), PriorityOrder);
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluate());
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvaluateFromEvent());
			TestFalse("Default value imported", Transition->GetNodeTemplateAs<USMTransitionInstance>(true)->GetCanEvalWithStartState());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				TArray<USMTransitionInstance*> Transitions;
				StateInstance->GetOutgoingTransitions(Transitions, false);
				USMTransitionTestInstance* TransitionInstance = CastChecked< USMTransitionTestInstance>(Transitions[0]);

				// Default class templates don't get compiled into the CDO, so the values should still be default in runtime.
				TestEqual("Default value imported to runtime", TransitionInstance->GetPriorityOrder(), PriorityOrder);
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvaluate());
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvaluateFromEvent());
				TestFalse("Default value imported to runtime", TransitionInstance->GetCanEvalWithStartState());
			}
		}
	}

	// Test importing conduit values.
	{
		USMGraphNode_StateNodeBase* SecondState = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->EntryNode->GetOutputNode())->GetNextNode();
		USMGraphNode_ConduitNode* ConduitNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_ConduitNode>(SecondState);

		// Default template.
		{
			ConduitNode->DestroyTemplate();

			TestFalse("Default value correct", ConduitNode->bDisableTickTransitionEvaluation_DEPRECATED);
			TestFalse("Default value correct", ConduitNode->bEvalTransitionsOnStart_DEPRECATED);
			TestFalse("Default value correct", ConduitNode->bExcludeFromAnyState_DEPRECATED);
			TestFalse("Default value correct", ConduitNode->bAlwaysUpdate_DEPRECATED);

			TestFalse("Default value correct", ConduitNode->bEvalWithTransitions_DEPRECATED);

			ConduitNode->bDisableTickTransitionEvaluation_DEPRECATED = true;
			ConduitNode->bEvalTransitionsOnStart_DEPRECATED = true;
			ConduitNode->bExcludeFromAnyState_DEPRECATED = true;
			ConduitNode->bAlwaysUpdate_DEPRECATED = true;
			ConduitNode->bEvalWithTransitions_DEPRECATED = true;

			ConduitNode->ForceSetVersion(0);
			ConduitNode->ConvertToCurrentVersion(true);
			TestNull("Template still null since this wasn't a load.", ConduitNode->GetNodeTemplate());

			ConduitNode->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", ConduitNode->GetNodeTemplate());

			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMConduitInstance>(true)->GetEvalWithTransitions());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				USMConduitInstance* ConduitInstance = CastChecked<USMConduitInstance>(StateInstance->GetNextStateByTransitionIndex(0));

				// Default class templates don't get compiled into the CDO, but the Getters will retrieve the struct version which should be the new values.
				TestTrue("Default value imported to runtime", ConduitInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", ConduitInstance->GetEvalTransitionsOnStart());
				TestFalse("Default value NOT imported to runtime", ConduitInstance->GetExcludeFromAnyState());
				TestTrue("Default value imported to runtime", ConduitInstance->GetAlwaysUpdate());

				TestTrue("Default value imported to runtime", ConduitInstance->GetEvalWithTransitions());
			}
		}

		// Existing templates
		{
			const int32 TestInt = 7;
			{
				// Apply user template to a node that already has a default template created.
				ConduitNode->SetNodeClass(USMConduitTestInstance::StaticClass());
				ConduitNode->GetNodeTemplateAs<USMConduitTestInstance>(true)->IntValue = TestInt;

				// Defaults already set since we are applying the node class after the initial template was created. Old values should be copied to new template.
				TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
				TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
				TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

				TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMConduitInstance>(true)->GetEvalWithTransitions());

				TestEqual("Edited value maintained", ConduitNode->GetNodeTemplateAs<USMConduitTestInstance>(true)->IntValue, TestInt);
			}

			// Recreate so there are no existing values to be copied.
			{
				ConduitNode->DestroyTemplate();
				ConduitNode->SetNodeClass(USMConduitTestInstance::StaticClass());
				ConduitNode->GetNodeTemplateAs<USMConduitTestInstance>(true)->IntValue = TestInt;
			}

			ConduitNode->ForceSetVersion(0);
			ConduitNode->ConvertToCurrentVersion(true);
			TestFalse("Default value not imported since it's not load", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestFalse("Default value not imported since it's not load", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestFalse("Default value not imported since it's not load", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestFalse("Default value not imported since it's not load", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			TestFalse("Default value not imported since it's not load", ConduitNode->GetNodeTemplateAs<USMConduitInstance>(true)->GetEvalWithTransitions());

			TestEqual("Edited value maintained", ConduitNode->GetNodeTemplateAs<USMConduitTestInstance>(true)->IntValue, TestInt);

			ConduitNode->ForceSetVersion(0);
			ConduitNode->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", ConduitNode->GetNodeTemplate());

			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			TestTrue("Default value imported", ConduitNode->GetNodeTemplateAs<USMConduitInstance>(true)->GetEvalWithTransitions());

			TestEqual("Edited value maintained", ConduitNode->GetNodeTemplateAs<USMConduitTestInstance>(true)->IntValue, TestInt);

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				USMConduitTestInstance* ConduitInstance = CastChecked<USMConduitTestInstance>(StateInstance->GetNextStateByTransitionIndex(0));

				// Default class templates don't get compiled into the CDO, so the values should still be default in runtime.
				TestTrue("Default value imported to runtime", ConduitInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", ConduitInstance->GetEvalTransitionsOnStart());
				TestTrue("Default value imported to runtime", ConduitInstance->GetExcludeFromAnyState());
				TestTrue("Default value imported to runtime", ConduitInstance->GetAlwaysUpdate());

				TestEqual("Edited value maintained", ConduitInstance->IntValue, TestInt);

				TestTrue("Default value imported to runtime", ConduitInstance->GetEvalWithTransitions());
			}
		}
	}

	// Test importing state machine values.
	{
		USMGraphNode_StateNodeBase* ThirdState = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->EntryNode->GetOutputNode())->GetNextNode()->GetNextNode();
		USMGraphNode_StateMachineStateNode* FSMNode = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_StateMachineStateNode>(ThirdState);

		// Default template.
		{
			FSMNode->DestroyTemplate();

			TestFalse("Default value correct", FSMNode->bDisableTickTransitionEvaluation_DEPRECATED);
			TestFalse("Default value correct", FSMNode->bEvalTransitionsOnStart_DEPRECATED);
			TestFalse("Default value correct", FSMNode->bExcludeFromAnyState_DEPRECATED);
			TestFalse("Default value correct", FSMNode->bAlwaysUpdate_DEPRECATED);

			TestFalse("Default value correct", FSMNode->bReuseIfNotEndState_DEPRECATED);
			TestFalse("Default value correct", FSMNode->bReuseCurrentState_DEPRECATED);

			FSMNode->bDisableTickTransitionEvaluation_DEPRECATED = true;
			FSMNode->bEvalTransitionsOnStart_DEPRECATED = true;
			FSMNode->bExcludeFromAnyState_DEPRECATED = true;
			FSMNode->bAlwaysUpdate_DEPRECATED = true;

			FSMNode->bReuseIfNotEndState_DEPRECATED = true;
			FSMNode->bReuseCurrentState_DEPRECATED = true;

			FSMNode->ForceSetVersion(0);
			FSMNode->ConvertToCurrentVersion(true);
			TestNull("Template still null since this wasn't a load.", FSMNode->GetNodeTemplate());

			FSMNode->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", FSMNode->GetNodeTemplate());

			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateInstance_Base>(true)->GetAlwaysUpdate());

			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseIfNotEndState());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseCurrentState());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				USMStateMachineInstance* FSMInstance = CastChecked<USMStateMachineInstance>(StateInstance->GetNextStateByTransitionIndex(0)->GetNextStateByTransitionIndex(0));

				// Default class templates don't get compiled into the CDO, but the Getters will retrieve the struct version which should be the new values.
				TestTrue("Default value imported to runtime", FSMInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", FSMInstance->GetEvalTransitionsOnStart());
				TestFalse("Default value NOT imported to runtime", FSMInstance->GetExcludeFromAnyState());
				TestTrue("Default value imported to runtime", FSMInstance->GetAlwaysUpdate());

				TestTrue("Default value imported to runtime", FSMInstance->GetReuseIfNotEndState());
				TestTrue("Default value imported to runtime", FSMInstance->GetReuseCurrentState());
			}
		}

		// Existing templates
		{
			const int32 TestInt = 7;
			{
				// Apply user template to a node that already has a default template created.
				FSMNode->SetNodeClass(USMStateMachineTestInstance::StaticClass());

				// Defaults already set since we are applying the node class after the initial template was created. Old values should be copied to new template.
				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetEvalTransitionsOnStart());
				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetExcludeFromAnyState());
				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetAlwaysUpdate());

				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseIfNotEndState());
				TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseCurrentState());
			}

			// Recreate so there are no existing values to be copied.
			{
				FSMNode->DestroyTemplate();
				FSMNode->SetNodeClass(USMStateMachineTestInstance::StaticClass());
			}

			FSMNode->ForceSetVersion(0);
			FSMNode->ConvertToCurrentVersion(true);
			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetDisableTickTransitionEvaluation());
			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetEvalTransitionsOnStart());
			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetExcludeFromAnyState());
			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetAlwaysUpdate());

			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetReuseIfNotEndState());
			TestFalse("Default value not imported since it's not load", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetReuseCurrentState());

			FSMNode->ForceSetVersion(0);
			FSMNode->ConvertToCurrentVersion(false);
			TestNotNull("Template created.", FSMNode->GetNodeTemplate());

			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetDisableTickTransitionEvaluation());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetEvalTransitionsOnStart());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetExcludeFromAnyState());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineTestInstance>(true)->GetAlwaysUpdate());

			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseIfNotEndState());
			TestTrue("Default value imported", FSMNode->GetNodeTemplateAs<USMStateMachineInstance>(true)->GetReuseCurrentState());

			// Test runtime with default values.
			{
				FKismetEditorUtilities::CompileBlueprint(NewBP);
				USMTestContext* Context = NewObject<USMTestContext>();
				USMInstance* StateMachineInstance = TestHelpers::CreateNewStateMachineInstanceFromBP(this, NewBP, Context);

				USMStateInstance_Base* StateInstance = CastChecked<USMStateInstance_Base>(StateMachineInstance->GetRootStateMachine().GetSingleInitialState()->GetNodeInstance());
				USMStateMachineTestInstance* FSMInstance = CastChecked<USMStateMachineTestInstance>(StateInstance->GetNextStateByTransitionIndex(0)->GetNextStateByTransitionIndex(0));

				// Default class templates don't get compiled into the CDO, so the values should still be default in runtime.
				TestTrue("Default value imported to runtime", FSMInstance->GetDisableTickTransitionEvaluation());
				TestTrue("Default value imported to runtime", FSMInstance->GetEvalTransitionsOnStart());
				TestTrue("Default value imported to runtime", FSMInstance->GetExcludeFromAnyState());
				TestTrue("Default value imported to runtime", FSMInstance->GetAlwaysUpdate());

				TestTrue("Default value imported to runtime", FSMInstance->GetReuseIfNotEndState());
				TestTrue("Default value imported to runtime", FSMInstance->GetReuseCurrentState());
			}
		}
	}

	return true;
}

/**
 * Validate components import their deprecated values correctly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FUpdateComponentTest, "LogicDriver.Upgrade.UpdateComponent", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

	bool FUpdateComponentTest::RunTest(const FString& Parameters)
{
	FAssetHandler NewAsset;
	if (!TestHelpers::TryCreateNewStateMachineAsset(this, NewAsset, false))
	{
		return false;
	}
	
	USMBlueprint* NewBP = NewAsset.GetObjectAs<USMBlueprint>();

	USMStateMachineTestComponent* TestComponent = NewObject<USMStateMachineTestComponent>(GetTransientPackage(), NAME_None, RF_ArchetypeObject | RF_Public);
	TestComponent->SetStateMachineClass(NewBP->GetGeneratedClass());

	bool bOverrideCanEverTick = true;
	bool bCanEverTick = false;

	bool bOverrideTickinterval = true;
	float TickInterval = 0.5f;

	// Test valid changes that will be imported.
	TestComponent->SetAllowTick(bOverrideCanEverTick, bCanEverTick);
	TestComponent->SetTickInterval(bOverrideTickinterval, TickInterval);

	TestComponent->ImportDeprecatedProperties_Public();

	USMInstance* Template = TestComponent->GetTemplateForInstance();
	TestNotNull("Instance template created", Template);

	TestEqual("CanTick", Template->CanEverTick(), bCanEverTick);
	TestEqual("TickInterval", Template->GetTickInterval(), TickInterval);

	// Prepare for changed values but without allowing override.
	bOverrideCanEverTick = false;
	TestComponent->SetAllowTick(bOverrideCanEverTick, bCanEverTick);
	bOverrideTickinterval = false;
	TestComponent->SetTickInterval(bOverrideTickinterval, TickInterval);

	// This shouldn't work and values should remain the same because we have a template and class set.
	TestComponent->ImportDeprecatedProperties_Public();
	Template = TestComponent->GetTemplateForInstance();
	TestNotNull("Instance template created", Template);
	TestEqual("CanTick", Template->CanEverTick(), bCanEverTick);
	TestEqual("TickInterval", Template->GetTickInterval(), TickInterval);

	// Clear and rerun, values should be default since overrides are disabled.
	TestComponent->ClearTemplateInstance();
	TestComponent->ImportDeprecatedProperties_Public();
	Template = TestComponent->GetTemplateForInstance();
	TestNotNull("Instance template created", Template);
	TestEqual("CanTick", Template->CanEverTick(), !bCanEverTick);
	TestEqual("TickInterval", Template->GetTickInterval(), 0.f);

	PRAGMA_DISABLE_DEPRECATION_WARNINGS
#define DEFAULT_AUTHORITY SM_Client
#define DEFAULT_EXECUTION SM_ClientAndServer
#define DEFAULT_WAIT_RPC  false

#define CHANGED_AUTHORITY SM_ClientAndServer
#define CHANGED_EXECUTION SM_Client
#define CHANGED_WAIT_RPC  true
	
	// Net Properties
	
	// Test defaults.
	TestEqual("Deprecated property is default", TestComponent->NetworkTransitionConfiguration, DEFAULT_AUTHORITY); 
	TestEqual("Deprecated property is default", TestComponent->NetworkStateConfiguration, DEFAULT_EXECUTION);
	TestEqual("Deprecated property is default", TestComponent->bTakeTransitionsFromServerOnly, DEFAULT_WAIT_RPC);

	TestEqual("Updated property is default", TestComponent->StateChangeAuthority, DEFAULT_AUTHORITY); 
	TestEqual("Updated property is default", TestComponent->NetworkStateExecution, DEFAULT_EXECUTION);
	TestEqual("Updated property is default", TestComponent->bWaitForTransactionsFromServer, DEFAULT_WAIT_RPC);
	
	TestComponent->NetworkTransitionConfiguration = CHANGED_AUTHORITY;
	TestComponent->NetworkStateConfiguration = CHANGED_EXECUTION;
	TestComponent->bTakeTransitionsFromServerOnly =  CHANGED_WAIT_RPC;

	// Test deprecated values imported.
	TestComponent->ImportDeprecatedProperties_Public();

	TestEqual("Updated property is set", TestComponent->StateChangeAuthority, CHANGED_AUTHORITY); 
	TestEqual("Updated property is set", TestComponent->NetworkStateExecution, CHANGED_EXECUTION);
	TestEqual("Updated property is set", TestComponent->bWaitForTransactionsFromServer, CHANGED_WAIT_RPC);

	TestEqual("Deprecated property is default", TestComponent->NetworkTransitionConfiguration, DEFAULT_AUTHORITY); 
	TestEqual("Deprecated property is default", TestComponent->NetworkStateConfiguration, DEFAULT_EXECUTION);
	TestEqual("Deprecated property is default", TestComponent->bTakeTransitionsFromServerOnly, DEFAULT_WAIT_RPC);

	// Test no change.
	TestComponent->ImportDeprecatedProperties_Public();

	TestEqual("Updated property is set", TestComponent->StateChangeAuthority, CHANGED_AUTHORITY); 
	TestEqual("Updated property is set", TestComponent->NetworkStateExecution, CHANGED_EXECUTION);
	TestEqual("Updated property is set", TestComponent->bWaitForTransactionsFromServer, CHANGED_WAIT_RPC);

	TestEqual("Deprecated property is default", TestComponent->NetworkTransitionConfiguration, DEFAULT_AUTHORITY); 
	TestEqual("Deprecated property is default", TestComponent->NetworkStateConfiguration, DEFAULT_EXECUTION);
	TestEqual("Deprecated property is default", TestComponent->bTakeTransitionsFromServerOnly, DEFAULT_WAIT_RPC);
	
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
	return NewAsset.DeleteAsset(this);
}

/**
 * Test the new pin names load correctly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSMPinConversionTest, "LogicDriver.Upgrade.PinConversion", EAutomationTestFlags::ApplicationContextMask |
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::EngineFilter)

bool FSMPinConversionTest::RunTest(const FString& Parameters)
{
	FAssetHandler NewAsset;
	if (!TestHelpers::TryCreateNewStateMachineAsset(this, NewAsset, false))
	{
		return false;
	}

	USMBlueprint* NewBP = NewAsset.GetObjectAs<USMBlueprint>();

	// Find root state machine.
	USMGraphK2Node_StateMachineNode* RootStateMachineNode = FSMBlueprintEditorUtils::GetRootStateMachineNode(NewBP);

	// Find the state machine graph.
	USMGraph* StateMachineGraph = RootStateMachineNode->GetStateMachineGraph();

	// Total states to test.
	UEdGraphPin* LastStatePin = nullptr;

	{
		TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, 2, &LastStatePin, USMStateTestInstance::StaticClass(), USMTransitionTestInstance::StaticClass());
	}

	USMGraphNode_StateNodeBase* FirstNode = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->GetEntryNode()->GetOutputNode());
	{
		USMGraphNode_TransitionEdge* Transition = CastChecked<USMGraphNode_TransitionEdge>(FirstNode->GetOutputPin()->LinkedTo[0]->GetOwningNode());
		
		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPreEvaluateNode>(this, Transition,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPreEval)));

		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPostEvaluateNode>(this, Transition,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPostEval)));
	}
	
	// Use a conduit
	USMGraphNode_ConduitNode* SecondNodeConduit = FSMBlueprintEditorUtils::ConvertNodeTo<USMGraphNode_ConduitNode>(CastChecked<USMGraphNode_StateNodeBase>(FirstNode->GetNextNode()));
	{
		SecondNodeConduit->SetNodeClass(USMConduitTestInstance::StaticClass());
		USMConduitGraph* Graph = CastChecked<USMConduitGraph>(SecondNodeConduit->GetBoundGraph());
		UEdGraphPin* CanEvalPin = Graph->ResultNode->GetInputPin();
		CanEvalPin->BreakAllPinLinks();
		CanEvalPin->DefaultValue = "True";

		// Pin was cleared out during conversion.
		LastStatePin = SecondNodeConduit->GetOutputPin();
	}
	
	UEdGraphPin* LastNestedPin = nullptr;
	USMGraphNode_StateMachineStateNode* ThirdNodeRef = TestHelpers::BuildNestedStateMachine(this, StateMachineGraph, 1, &LastStatePin, &LastNestedPin);
	{
		FString AssetName = "PinTestRef_1";
		UBlueprint* RefBlueprint = FSMBlueprintEditorUtils::ConvertStateMachineToReference(ThirdNodeRef, false, &AssetName, nullptr);
		FKismetEditorUtilities::CompileBlueprint(RefBlueprint);
		LastStatePin = ThirdNodeRef->GetOutputPin();
	}
	
	USMGraphNode_StateMachineStateNode* FourthNodeIntermediateRef = TestHelpers::BuildNestedStateMachine(this, StateMachineGraph, 1, &LastStatePin, &LastNestedPin);
	{
		FString AssetName = "PinTestRef_2";
		UBlueprint* RefBlueprint = FSMBlueprintEditorUtils::ConvertStateMachineToReference(FourthNodeIntermediateRef, false, &AssetName, nullptr);
		FKismetEditorUtilities::CompileBlueprint(RefBlueprint);
		
		FourthNodeIntermediateRef->SetUseIntermediateGraph(true);
		LastStatePin = FourthNodeIntermediateRef->GetOutputPin();
		
		TestHelpers::AddEventWithLogic<USMGraphK2Node_IntermediateStateMachineStartNode>(this, FourthNodeIntermediateRef,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseEntryInt)));
	}

	// Add one last state
	TestHelpers::BuildLinearStateMachine(this, StateMachineGraph, 1, &LastStatePin, USMStateTestInstance::StaticClass(), USMTransitionTestInstance::StaticClass());

	{
		USMGraphNode_TransitionEdge* Transition = CastChecked<USMGraphNode_TransitionEdge>(SecondNodeConduit->GetOutputPin()->LinkedTo[0]->GetOwningNode());
		TestHelpers::SetNodeClass(this, Transition, USMTransitionTestInstance::StaticClass());

		TestHelpers::AddTransitionResultLogic(this, Transition);
		
		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPreEvaluateNode>(this, Transition,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPreEval)));

		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPostEvaluateNode>(this, Transition,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPostEval)));
	}
	
	{
		// Signal the state after the nested state machine to wait for its completion.
		USMGraphNode_TransitionEdge* TransitionFromNestedStateMachine = CastChecked<USMGraphNode_TransitionEdge>(ThirdNodeRef->GetOutputPin()->LinkedTo[0]->GetOwningNode());

		TestHelpers::SetNodeClass(this, TransitionFromNestedStateMachine, USMTransitionTestInstance::StaticClass());
		TestHelpers::AddTransitionResultLogic(this, TransitionFromNestedStateMachine);
		
		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPreEvaluateNode>(this, TransitionFromNestedStateMachine,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPreEval)));

		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPostEvaluateNode>(this, TransitionFromNestedStateMachine,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPostEval)));
	}

	{
		// Signal the state after the nested state machine to wait for its completion.
		USMGraphNode_TransitionEdge* TransitionFromNestedStateMachine = CastChecked<USMGraphNode_TransitionEdge>(FourthNodeIntermediateRef->GetOutputPin()->LinkedTo[0]->GetOwningNode());

		TestHelpers::SetNodeClass(this, TransitionFromNestedStateMachine, USMTransitionTestInstance::StaticClass());
		TestHelpers::AddTransitionResultLogic(this, TransitionFromNestedStateMachine);
		
		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPreEvaluateNode>(this, TransitionFromNestedStateMachine,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPreEval)));

		TestHelpers::AddEventWithLogic<USMGraphK2Node_TransitionPostEvaluateNode>(this, TransitionFromNestedStateMachine,
			USMTestContext::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMTestContext, IncreaseTransitionPostEval)));
	}

	// Run as normal.
	int32 EntryHits = 0; int32 UpdateHits = 0; int32 EndHits = 0;
	USMInstance* Instance = TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits, UpdateHits, EndHits);

	USMTestContext* Context = CastChecked<USMTestContext>(Instance->GetContext());
	int32 PreEval = Context->TestTransitionPreEval.Count;
	int32 PostEval = Context->TestTransitionPostEval.Count;

	TestTrue("Pre/Post Evals hit", PreEval > 0 && PostEval > 0);
	
	// Rename all of the pins to pre 2.1 pin names.
	FName OldPinName = FName("");
	{
		{
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEntryNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateUpdateNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEndNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
		}
		
		{
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_IntermediateEntryNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateUpdateNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEndNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);

			TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_IntermediateStateMachineStartNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then, &OldPinName);
		}
	}

	// Verify it still works.
	int32 EntryHits2 = 0; int32 UpdateHits2 = 0; int32 EndHits2 = 0;
	Instance = TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits2, UpdateHits2, EndHits2);

	Context = CastChecked<USMTestContext>(Instance->GetContext());
	TestEqual("Hits match", Context->TestTransitionPreEval.Count, PreEval);
	TestEqual("Hits match", Context->TestTransitionPostEval.Count, PostEval);

	TestEqual("Hits match", EntryHits2, EntryHits);
	TestEqual("Hits match", UpdateHits2, UpdateHits);
	TestEqual("Hits match", EndHits2, EndHits);
	
	if (!NewAsset.SaveAsset(this))
	{
		return false;
	}

	if (!NewAsset.LoadAsset(this))
	{
		return false;
	}

	NewBP = NewAsset.GetObjectAs<USMBlueprint>();
	FSMBlueprintEditorUtils::ReconstructAllNodes(NewBP);
	
	RootStateMachineNode = FSMBlueprintEditorUtils::GetRootStateMachineNode(NewBP);
	StateMachineGraph = RootStateMachineNode->GetStateMachineGraph();
	FirstNode = CastChecked<USMGraphNode_StateNodeBase>(StateMachineGraph->GetEntryNode()->GetOutputNode());

	// Verify pins have been correctly renamed.
	{
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEntryNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then);
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateUpdateNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then);
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEndNode>(this, FirstNode->GetBoundGraph(), USMGraphK2Schema::PN_Then);
	}

	{
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_IntermediateEntryNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then);
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateUpdateNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then);
		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_StateEndNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then);

		TestHelpers::VerifyNodeWiredFromPin<USMGraphK2Node_IntermediateStateMachineStartNode>(this, FourthNodeIntermediateRef->GetBoundGraph(), USMGraphK2Schema::PN_Then);
	}

	Instance = TestHelpers::RunStateMachineToCompletion(this, NewBP, EntryHits2, UpdateHits2, EndHits2);

	Context = CastChecked<USMTestContext>(Instance->GetContext());
	TestEqual("Hits match", Context->TestTransitionPreEval.Count, PreEval);
	TestEqual("Hits match", Context->TestTransitionPostEval.Count, PostEval);
	
	TestEqual("Hits match", EntryHits2, EntryHits);
	TestEqual("Hits match", UpdateHits2, UpdateHits);
	TestEqual("Hits match", EndHits2, EndHits);
	
	return NewAsset.DeleteAsset(this);
}

#endif

#endif //WITH_DEV_AUTOMATION_TESTS