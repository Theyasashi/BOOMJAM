// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTransitionGraph.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Nodes/SMGraphNode_TransitionEdge.h"
#include "Nodes/Helpers/SMGraphK2Node_FunctionNodes.h"
#include "Nodes/Helpers/SMGraphK2Node_StateWriteNodes.h"
#include "Nodes/RootNodes/SMGraphK2Node_TransitionEnteredNode.h"
#include "Nodes/RootNodes/SMGraphK2Node_TransitionPreEvaluateNode.h"
#include "Nodes/RootNodes/SMGraphK2Node_TransitionPostEvaluateNode.h"
#include "Nodes/RootNodes/SMGraphK2Node_TransitionInitializedNode.h"
#include "Nodes/RootNodes/SMGraphK2Node_TransitionShutdownNode.h"

#include "EdGraph/EdGraphPin.h"

USMTransitionGraph::USMTransitionGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), ResultNode(nullptr)
{
}

USMGraphNode_TransitionEdge* USMTransitionGraph::GetOwningTransitionNode() const
{
	return Cast<USMGraphNode_TransitionEdge>(GetOuter());
}

USMGraphNode_TransitionEdge* USMTransitionGraph::GetOwningTransitionNodeChecked() const
{
	return CastChecked<USMGraphNode_TransitionEdge>(GetOuter());
}

bool USMTransitionGraph::HasAnyLogicConnections() const
{
	if (bHasLogicConnectionsCached.IsSet())
	{
		return bHasLogicConnectionsCached.GetValue();
	}
	
	// Check if there are any pins wired to this boolean input.
	TArray<USMGraphK2Node_TransitionResultNode*> RootNodeList;

	// We want to find the node even if it's buried in a nested graph.
	FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphK2Node_TransitionResultNode>(const_cast<USMTransitionGraph*>(this), RootNodeList);

	for (USMGraphK2Node_RootNode* RootNode : RootNodeList)
	{
		if (RootNode->GetInputPin()->LinkedTo.Num() || RootNode->GetInputPin()->DefaultValue.ToBool())
		{
			bHasLogicConnectionsCached = true;
			return true;
		}
	}

	// Check event triggers.
	{
		TArray<USMGraphK2Node_FunctionNode_TransitionEvent*> EventEntryList;
		FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphK2Node_FunctionNode_TransitionEvent>(const_cast<USMTransitionGraph*>(this), EventEntryList);

		if (EventEntryList.Num() > 0)
		{
			// Check result nodes... not the greatest check since it doesn't verify they're connected to the entry node.
			TArray<USMGraphK2Node_StateWriteNode_TransitionEventReturn*> EventResultList;
			FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphK2Node_StateWriteNode_TransitionEventReturn>(const_cast<USMTransitionGraph*>(this), EventResultList);
			for (USMGraphK2Node_StateWriteNode_TransitionEventReturn* Node : EventResultList)
			{
				bHasLogicConnectionsCached = true;
				return true;
			}
		}
	}

	bHasLogicConnectionsCached = false;
	
	return false;
}

ESMConditionalEvaluationType USMTransitionGraph::GetConditionalEvaluationType() const
{
	// Check if there are any pins wired to this boolean input.
	TArray<USMGraphK2Node_TransitionResultNode*> RootNodeList;

	// We want to find the node even if it's buried in a nested graph.
	FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphK2Node_TransitionResultNode>(const_cast<USMTransitionGraph*>(this), RootNodeList);

	for (const USMGraphK2Node_RootNode* RootNode : RootNodeList)
	{
		UEdGraphPin* Pin = RootNode->GetInputPin();
		
		if (Pin->LinkedTo.Num() == 0)
		{
			return Pin->DefaultValue.ToBool() ? ESMConditionalEvaluationType::SM_AlwaysTrue : ESMConditionalEvaluationType::SM_AlwaysFalse;
		}
	}

	return ESMConditionalEvaluationType::SM_Graph;
}

bool USMTransitionGraph::HasTransitionEnteredLogic() const
{
	return HasNodeWithExecutionLogic<USMGraphK2Node_TransitionEnteredNode>();
}

bool USMTransitionGraph::HasPreEvalLogic() const
{
	return HasNodeWithExecutionLogic<USMGraphK2Node_TransitionPreEvaluateNode>();
}

bool USMTransitionGraph::HasPostEvalLogic() const
{
	return HasNodeWithExecutionLogic<USMGraphK2Node_TransitionPostEvaluateNode>();
}

bool USMTransitionGraph::HasInitLogic() const
{
	return HasNodeWithExecutionLogic<USMGraphK2Node_TransitionInitializedNode>();
}

bool USMTransitionGraph::HasShutdownLogic() const
{
	return HasNodeWithExecutionLogic<USMGraphK2Node_TransitionShutdownNode>();
}

template<typename T>
bool USMTransitionGraph::HasNodeWithExecutionLogic() const
{
	TArray<T*> CompletedNodeList;

	// We want to find the node even if it's buried in a nested graph.
	FSMBlueprintEditorUtils::GetAllNodesOfClassNested<T>(const_cast<USMTransitionGraph*>(this), CompletedNodeList);

	for (USMGraphK2Node_RootNode* Node : CompletedNodeList)
	{
		if (Node->GetOutputNode())
		{
			return true;
		}
	}

	return false;
}