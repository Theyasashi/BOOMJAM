// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMGraphNode_ConduitNode.h"

#include "Graph/Schema/SMConduitGraphSchema.h"
#include "Graph/SMConduitGraph.h"
#include "RootNodes/SMGraphK2Node_IntermediateNodes.h"
#include "RootNodes/SMGraphK2Node_TransitionInitializedNode.h"
#include "RootNodes/SMGraphK2Node_TransitionShutdownNode.h"
#include "RootNodes/SMGraphK2Node_TransitionEnteredNode.h"
#include "Utilities/SMBlueprintEditorUtils.h"

#include "Kismet2/Kismet2NameValidators.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "SMGraphConduitNode"

USMGraphNode_ConduitNode::USMGraphNode_ConduitNode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), bEvalWithTransitions_DEPRECATED(false), bWasEvaluating(false)
{
}

void USMGraphNode_ConduitNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, TEXT("Transition"), TEXT("In"));
	CreatePin(EGPD_Output, TEXT("Transition"), TEXT("Out"));
}

FText USMGraphNode_ConduitNode::GetTooltipText() const
{
	return LOCTEXT("ConduitNodeTooltip", "A conduit allows a single condition to be checked before selecting one of many transitions.");
}

void USMGraphNode_ConduitNode::PostPlacedNewNode()
{
	SetToCurrentVersion();
	
	// Create a new state machine graph
	check(BoundGraph == NULL);
	BoundGraph = FBlueprintEditorUtils::CreateNewGraph(
		this,
		NAME_None,
		USMConduitGraph::StaticClass(),
		USMConduitGraphSchema::StaticClass());
	check(BoundGraph);

	// Find an interesting name
	TSharedPtr<INameValidatorInterface> NameValidator = FNameValidatorFactory::MakeValidator(this);
	FBlueprintEditorUtils::RenameGraphWithSuggestion(BoundGraph, NameValidator, TEXT("Conduit"));

	// Initialize the state machine graph
	const UEdGraphSchema* Schema = BoundGraph->GetSchema();
	Schema->CreateDefaultNodesForGraph(*BoundGraph);

	// Add the new graph as a child of our parent graph
	UEdGraph* ParentGraph = GetGraph();

	if (ParentGraph->SubGraphs.Find(BoundGraph) == INDEX_NONE)
	{
		ParentGraph->SubGraphs.Add(BoundGraph);
	}

	if (bGenerateTemplateOnNodePlacement)
	{
		InitTemplate();
		if (USMConduitInstance* ConduitInstance = GetNodeTemplateAs<USMConduitInstance>())
		{
			ConduitInstance->SetEvalWithTransitions(FSMBlueprintEditorUtils::GetProjectEditorSettings()->bConfigureNewConduitsAsTransitions);
		}
	}
}

void USMGraphNode_ConduitNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	// Enable templates
	bool bStateChange = false;
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(USMGraphNode_ConduitNode, ConduitClass))
	{
		InitTemplate();

		bStateChange = true;
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if (bStateChange && IsSafeToConditionallyCompile(PropertyChangedEvent.ChangeType))
	{
		FSMBlueprintEditorUtils::ConditionallyCompileBlueprint(FSMBlueprintEditorUtils::FindBlueprintForNodeChecked(this), false);
	}
}

void USMGraphNode_ConduitNode::ResetDebugState()
{
	Super::ResetDebugState();

	// Prevents a previous cycle from showing it as running.
	if (const FSMConduit* DebugNode = (FSMConduit*)GetDebugNode())
	{
		DebugNode->bWasEvaluating = bWasEvaluating = false;
	}
}

void USMGraphNode_ConduitNode::UpdateTime(float DeltaTime)
{
	const USMEditorSettings* Settings = FSMBlueprintEditorUtils::GetEditorSettings();
	if (ShouldEvalWithTransitions() && Settings->bDisplayTransitionEvaluation)
	{
		if (const FSMConduit* DebugNode = (FSMConduit*)GetDebugNode())
		{
			if (WasEvaluating() && (DebugNode->IsActive() || DebugNode->bWasActive))
			{
				// Cancel evaluation display and let the super method reset.
				bWasEvaluating = false;
				bWasDebugActive = false;
			}
			else if (DebugNode->bIsEvaluating || DebugNode->bWasEvaluating)
			{
				// Not active but evaluating.
				bIsDebugActive = true;
				bWasEvaluating = true;
			}
			DebugNode->bWasEvaluating = false;
		}
	}

	Super::UpdateTime(DeltaTime);

	if (!WasDebugNodeActive())
	{
		bWasEvaluating = false;
	}
}

void USMGraphNode_ConduitNode::ImportDeprecatedProperties()
{
	Super::ImportDeprecatedProperties();

	if (USMConduitInstance* Instance = Cast<USMConduitInstance>(GetNodeTemplate()))
	{
		if (GetLoadedVersion() < TEMPLATE_PROPERTY_VERSION)
		{
			Instance->SetEvalWithTransitions(bEvalWithTransitions_DEPRECATED);
		}
	}
}

void USMGraphNode_ConduitNode::PlaceDefaultInstanceNodes()
{
	Super::PlaceDefaultInstanceNodes();
}

void USMGraphNode_ConduitNode::SetNodeClass(UClass* Class)
{
	ConduitClass = Class;
	Super::SetNodeClass(Class);
}

void USMGraphNode_ConduitNode::SetRuntimeDefaults(FSMState_Base& State) const
{
	Super::SetRuntimeDefaults(State);
	FSMConduit& Conduit = static_cast<FSMConduit&>(State);
	Conduit.bEvalWithTransitions = ShouldEvalWithTransitions();
	if (const USMConduitInstance* Instance = Cast<USMConduitInstance>(GetNodeTemplate()))
	{
		Conduit.bCanEvaluate = Instance->bCanEvaluate;
		Conduit.ConditionalEvaluationType = CastChecked<USMConduitGraph>(BoundGraph)->GetConditionalEvaluationType();
	}
}

FLinearColor USMGraphNode_ConduitNode::GetActiveBackgroundColor() const
{
	const FLinearColor BaseColor = Super::GetActiveBackgroundColor();
	
	if (ShouldEvalWithTransitions())
	{
		const USMEditorSettings* Settings = FSMBlueprintEditorUtils::GetEditorSettings();
		if (Settings->bDisplayTransitionEvaluation)
		{
			if (const FSMConduit* DebugNode = (FSMConduit*)GetDebugNode())
			{
				if (DebugNode->bIsEvaluating || bWasEvaluating)
				{
					const float TimeToFade = 0.7f;
					const float DebugTime = GetDebugTime();
					if (DebugTime < TimeToFade)
					{
						return FLinearColor::LerpUsingHSV(Settings->EvaluatingTransitionColor, BaseColor, DebugTime / TimeToFade);
					}
				}
			}
		}
	}

	return BaseColor;
}

UObject* USMGraphNode_ConduitNode::GetJumpTargetForDoubleClick() const
{
	return Super::GetJumpTargetForDoubleClick();
}

bool USMGraphNode_ConduitNode::ShouldEvalWithTransitions() const
{
	if (USMConduitInstance* Instance = Cast<USMConduitInstance>(GetNodeTemplate()))
	{
		return Instance->GetEvalWithTransitions();
	}

	return false;
}

FLinearColor USMGraphNode_ConduitNode::Internal_GetBackgroundColor() const
{
	const FLinearColor ColorModifier(1.f, 1.f, 1.f, 0.5f);

	if (IsEndState())
	{
		return FLinearColor::Red * ColorModifier;
	}

	const FLinearColor DefaultColor = FLinearColor(0.7f, 0.7f, 0.7f, 1.f);

	if (USMConduitGraph* Graph = Cast<USMConduitGraph>(BoundGraph))
	{
		// This conduit will never be evaluated.
		if (!Graph->HasAnyLogicConnections())
		{
			return FLinearColor::Red * ColorModifier;
		}
	}

	return DefaultColor * ColorModifier;
}

#undef LOCTEXT_NAMESPACE
