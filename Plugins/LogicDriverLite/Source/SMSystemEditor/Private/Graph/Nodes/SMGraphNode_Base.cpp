// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMGraphNode_Base.h"
#include "SMGraphNode_StateNode.h"
#include "SMGraphNode_AnyStateNode.h"
#include "Graph/SMGraph.h"
#include "Graph/Schema/SMGraphSchema.h"

#include "EdGraphUtilities.h"
#include "Helpers/SMGraphK2Node_StateReadNodes.h"
#include "Customization/SMEditorCustomization.h"
#include "Blueprints/SMBlueprintEditor.h"
#include "SMGraphNode_StateNode.h"

#include "Utilities/SMBlueprintEditorUtils.h"
#include "Blueprints/SMBlueprint.h"
#include "SMUtils.h"

#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "UObject/UObjectThreadContext.h"
#include "EdGraphUtilities.h"

#define LOCTEXT_NAMESPACE "SMGraphNodeBase"

/** Log a message to the message log up to 4 arguments long. */
#define LOG_MESSAGE(LOG_TYPE, MESSAGE, ARGS, ARGS_COUNT) \
	do { \
		if (ARGS_COUNT == 0)\
			MessageLog.LOG_TYPE(MESSAGE); \
		else if (ARGS_COUNT == 1) \
			MessageLog.LOG_TYPE(MESSAGE, ARGS[0]); \
		else if (ARGS_COUNT == 2) \
			MessageLog.LOG_TYPE(MESSAGE, ARGS[0], ARGS[1]); \
		else if (ARGS_COUNT == 3) \
			MessageLog.LOG_TYPE(MESSAGE, ARGS[0], ARGS[1], ARGS[2]); \
		else if (ARGS_COUNT >= 4) \
			MessageLog.LOG_TYPE(MESSAGE, ARGS[0], ARGS[1], ARGS[2], ARGS[3]); \
	} while (0)

USMGraphNode_Base::USMGraphNode_Base(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCanRenameNode = true;
	DebugTotalTime = 0.f;
	bIsDebugActive = false;
	bWasDebugActive = false;
	bChangeFromRedirect = false;
	MaxTimeToShowDebug = 1.f;
	BoundGraph = nullptr;
	NodeInstanceTemplate = nullptr;
	CachedBrush = FSlateNoResource();
	bJustPasted = false;
	bIsEditUndo = false;
	bGenerateTemplateOnNodePlacement = true;
	bIsPrecompiling = false;
	bRequiresGuidRegeneration = false;
	bNeedsStateStackConversion = false;
	bTEST_ForceNoTemplateGuid = false;
}

void USMGraphNode_Base::DestroyNode()
{
	Super::DestroyNode();
}

void USMGraphNode_Base::PostPasteNode()
{
	bJustPasted = true;
	Super::PostPasteNode();

	if (UEdGraph* Graph = GetBoundGraph())
	{
		// Add the new graph as a child of our parent graph
		UEdGraph* ParentGraph = GetGraph();

		if (ParentGraph->SubGraphs.Find(Graph) == INDEX_NONE)
		{
			ParentGraph->SubGraphs.Add(Graph);
		}

		// Restore transactional flag that is lost during copy/paste process
		Graph->SetFlags(RF_Transactional);
	}

	InitTemplate();
	UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForNodeChecked(this);

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	bJustPasted = false;
}

void USMGraphNode_Base::PostEditUndo()
{
	bIsEditUndo = true;
	
	Super::PostEditUndo();

	if (NodeInstanceTemplate)
	{
		NodeInstanceTemplate->ClearFlags(RF_Transient);
	}
	
	// No bound graph prevents the property graphs from finding their blueprint. This could happen if a graph deletion was being redone.
	if (BoundGraph == nullptr)
	{
		return;
	}

	bIsEditUndo = false;
}

void USMGraphNode_Base::PostPlacedNewNode()
{
	SetToCurrentVersion();

	Super::PostPlacedNewNode();
}

void USMGraphNode_Base::OnRenameNode(const FString& NewName)
{
	FBlueprintEditorUtils::RenameGraph(GetBoundGraph(), NewName);
}

UObject* USMGraphNode_Base::GetJumpTargetForDoubleClick() const
{
	return BoundGraph;
}

bool USMGraphNode_Base::CanJumpToDefinition() const
{
	return GetJumpTargetForDoubleClick() != nullptr;
}

void USMGraphNode_Base::JumpToDefinition() const
{
	if (UObject* HyperlinkTarget = GetJumpTargetForDoubleClick())
	{
		if (HyperlinkTarget->GetPackage() != GetPackage())
		{
			if (USMNodeBlueprint* BlueprintTarget = Cast<USMNodeBlueprint>(HyperlinkTarget))
			{
				// For node blueprint targets set the debug object.
				FSMBlueprintEditorUtils::GetNodeBlueprintFromClassAndSetDebugObject(GetNodeClass(), this);
			}
		}
		
		FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(HyperlinkTarget);
	}
}

bool USMGraphNode_Base::CanCreateUnderSpecifiedSchema(const UEdGraphSchema* Schema) const
{
	return Schema->IsA(USMGraphSchema::StaticClass());
}

void USMGraphNode_Base::ReconstructNode()
{
	Super::ReconstructNode();

	// Node instance references may need to be updated if the node class changed.
	if (const UEdGraph* Graph = GetBoundGraph())
	{
		TArray<USMGraphK2Node_StateReadNode_GetNodeInstance*> NodesToReconstruct;
		FSMBlueprintEditorUtils::GetAllNodesOfClassNested(Graph, NodesToReconstruct);

		for (USMGraphK2Node_StateReadNode_GetNodeInstance* Node : NodesToReconstruct)
		{
			Node->ReconstructNode();
		}
	}
}

void USMGraphNode_Base::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	bChangeFromRedirect = PropertyChangedEvent.ChangeType == EPropertyChangeType::Redirected;
	
	FSMBlueprintEditorUtils::InvalidateCaches(FSMBlueprintEditorUtils::FindBlueprintForNode(this));
	// Lite specific since construction script manager isn't running.
	{
		RequestSlateRefresh();
	}
	bChangeFromRedirect = false;
}

void USMGraphNode_Base::PinConnectionListChanged(UEdGraphPin* Pin)
{
	Super::PinConnectionListChanged(Pin);
	FSMBlueprintEditorUtils::InvalidateCaches(FSMBlueprintEditorUtils::FindBlueprintForNode(this));
}

void USMGraphNode_Base::ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const
{
	Super::ValidateNodeDuringCompilation(MessageLog);

	for (const FSMGraphNodeLog& Log : CollectedLogs)
	{
		switch (Log.LogType)
		{
		case EMessageSeverity::Info:
		{
			LOG_MESSAGE(Note, *Log.ConsoleMessage, Log.ReferenceList, Log.ReferenceList.Num());
			break;
		}
		case EMessageSeverity::Warning:
		{
			LOG_MESSAGE(Warning, *Log.ConsoleMessage, Log.ReferenceList, Log.ReferenceList.Num());
			break;
		}
		case EMessageSeverity::Error:
		{
			LOG_MESSAGE(Error, *Log.ConsoleMessage, Log.ReferenceList, Log.ReferenceList.Num());
			break;
		}
		}
	}
}

UEdGraphPin* USMGraphNode_Base::GetInputPin() const
{
	if (Pins.Num() == 0 || Pins[INDEX_PIN_INPUT]->Direction == EGPD_Output)
	{
		return nullptr;
	}

	return Pins[INDEX_PIN_INPUT];
}

UEdGraphPin* USMGraphNode_Base::GetOutputPin() const
{
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin->Direction == EGPD_Output)
		{
			return Pin;
		}
	}

	return nullptr;
}

UEdGraphNode* USMGraphNode_Base::GetOutputNode() const
{
	UEdGraphPin* OutputPin = GetOutputPin();

	if (OutputPin)
	{
		if (OutputPin->LinkedTo.Num() > 0 && OutputPin->LinkedTo[INDEX_PIN_INPUT]->GetOwningNode() != nullptr)
		{
			return OutputPin->LinkedTo[INDEX_PIN_INPUT]->GetOwningNode();
		}
	}

	return nullptr;
}

void USMGraphNode_Base::GetAllOutputNodes(TArray<UEdGraphNode*>& OutNodes) const
{
	UEdGraphPin* OutputPin = GetOutputPin();

	if (OutputPin)
	{
		for (int32 Idx = 0; Idx < OutputPin->LinkedTo.Num(); ++Idx)
		{
			OutNodes.Add(OutputPin->LinkedTo[Idx]->GetOwningNode());
		}
	}
}

void USMGraphNode_Base::PreCompile(FSMKismetCompilerContext& CompilerContext)
{
	if (!BoundGraph)
	{
		return;
	}

	bIsPrecompiling = true;
	
	/** Call in case the version manager hasn't run. */
	ConvertToCurrentVersion();
	
	ResetLogMessages();

	bIsPrecompiling = false;
}

void USMGraphNode_Base::OnCompile(FSMKismetCompilerContext& CompilerContext)
{
	if (!BoundGraph)
	{
		return;
	}

	FSMNode_Base* RuntimeNode = FSMBlueprintEditorUtils::GetRuntimeNodeFromGraph(BoundGraph);
	check(RuntimeNode);
	RuntimeNode->SetNodeInstanceClass(GetNodeClass());
	if (NodeInstanceTemplate && !IsUsingDefaultNodeClass())
	{
		// We don't need the default template at runtime.
		CompilerContext.AddDefaultObjectTemplate(RuntimeNode->GetNodeGuid(), NodeInstanceTemplate, FTemplateContainer::NodeTemplate);
	}
}

void USMGraphNode_Base::ResetDebugState()
{
	// Prevents a previous cycle from showing it as running.
	if (const FSMNode_Base* DebugNode = GetDebugNode())
	{
		DebugNode->bWasActive = bWasDebugActive = false;
	}
}

void USMGraphNode_Base::OnWidgetConstruct()
{
	ResetDebugState();
}

void USMGraphNode_Base::UpdateTime(float DeltaTime)
{
	if (const FSMNode_Base* DebugNode = GetDebugNode())
	{
		MaxTimeToShowDebug = GetMaxDebugTime();
		
		// Toggle active status and reset time if switching active states.
		if (DebugNode->IsActive() || (DebugNode->bWasActive && !WasDebugNodeActive()))
		{
			bWasDebugActive = false;

			// Was active is debug only data and exists to help us determine if we should draw an active state.
			DebugNode->bWasActive = false;
			if (!IsDebugNodeActive())
			{
				bIsDebugActive = true;
				DebugTotalTime = 0.f;
			}
		}
		else if (IsDebugNodeActive())
		{
			bWasDebugActive = true;
			bIsDebugActive = false;
			DebugTotalTime = 0.f;
		}
		// In the event a node is no longer active but is still being reported it is and we don't want to display it any more.
		else if (WasDebugNodeActive() && !IsDebugNodeActive() && DebugTotalTime >= MaxTimeToShowDebug)
		{
			bWasDebugActive = false;
		}
		else
		{
			DebugTotalTime += DeltaTime;
		}
	}
	else
	{
		bIsDebugActive = bWasDebugActive = false;
	}
}

void USMGraphNode_Base::ResetLogMessages()
{
	CollectedLogs.Empty();
	bHasCompilerMessage = false;
}

void USMGraphNode_Base::UpdateErrorMessageFromLogs()
{
	bHasCompilerMessage = TryGetNodeLogMessage(ErrorMsg, ErrorType);
}

void USMGraphNode_Base::AddNodeLogMessage(const FSMGraphNodeLog& Message)
{
	CollectedLogs.Add(Message);
}

bool USMGraphNode_Base::TryGetNodeLogMessage(FString& OutMessage, int32& OutSeverity) const
{
	int32 Severity = EMessageSeverity::Info;
	FString Message;
	for (const FSMGraphNodeLog& Log : CollectedLogs)
	{
		if (!Message.IsEmpty())
		{
			Message += "\n";
		}

		Message += Log.NodeMessage;

		if (Log.LogType < Severity)
		{
			Severity = Log.LogType;
		}
	}

	OutMessage = Message;
	OutSeverity = Severity;

	return CollectedLogs.Num() > 0;
}

void USMGraphNode_Base::GoToLocalGraph() const
{
	return JumpToDefinition();
}

void USMGraphNode_Base::InitTemplate()
{
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT("USMGraphNode_Base::InitTemplate"), STAT_InitTemplate, STATGROUP_LogicDriverEditor);
	
	UClass* NodeClass = GetNodeClass();
	UClass* DefaultNodeClass = GetDefaultNodeClass();
	if (NodeClass == nullptr)
	{
		/* No longer allow null classes.
		 * The default class is used to configure shared properties for all states.
		 * A default template is not needed at runtime and won't be copied to the CDO. */
		if (!DefaultNodeClass)
		{
			ensureAlways(GetClass() == USMGraphNode_StateMachineEntryNode::StaticClass() || GetClass() == USMGraphNode_AnyStateNode::StaticClass());
			return;
		}
		
		SetNodeClass(DefaultNodeClass);
		return;
	}

	Modify();

	FString NodeName = GetName();
	NodeName = FSMBlueprintEditorUtils::GetSafeName(NodeName);
	
	const FString TemplateName = FString::Printf(TEXT("NODE_TEMPLATE_%s_%s_%s"), *NodeName, *NodeClass->GetName(), *FGuid::NewGuid().ToString());
	USMNodeInstance* NewTemplate = NewObject<USMNodeInstance>(this, NodeClass, *TemplateName, RF_ArchetypeObject | RF_Transactional | RF_Public);

	if (NodeInstanceTemplate)
	{
		NodeInstanceTemplate->Modify();
		
		if (NewTemplate)
		{
			UEngine::CopyPropertiesForUnrelatedObjects(NodeInstanceTemplate, NewTemplate);
		}

		// Original template isn't needed any more.
		DestroyTemplate();
	}

	NodeInstanceTemplate = NewTemplate;

	if (NodeClass != DefaultNodeClass)
	{
		PlaceDefaultInstanceNodes();
	}
	
	// Template may have new widgets to display.
	if (!bJustPasted)
	{
		// Pasting by default will call reconstruct node.
		ReconstructNode();
	}
}

void USMGraphNode_Base::DestroyTemplate()
{
	if (NodeInstanceTemplate)
	{
		NodeInstanceTemplate->Modify();
		FSMBlueprintEditorUtils::TrashObject(NodeInstanceTemplate);
		NodeInstanceTemplate = nullptr;
	}
}

void USMGraphNode_Base::PlaceDefaultInstanceNodes()
{
	Modify();

	if (BoundGraph)
	{
		BoundGraph->Modify();
	}
}

bool USMGraphNode_Base::IsSafeToConditionallyCompile(EPropertyChangeType::Type ChangeType) const
{
	return ChangeType != EPropertyChangeType::Redirected;
}

void USMGraphNode_Base::SetNodeClass(UClass* Class)
{
	InitTemplate();
}

UClass* USMGraphNode_Base::GetDefaultNodeClass() const
{
	if (FSMNode_Base* RuntimeNode = FindRuntimeNode())
	{
		return RuntimeNode->GetDefaultNodeInstanceClass();
	}

	return nullptr;
}

bool USMGraphNode_Base::IsNodeClassNative() const
{
	if (const UClass* Class = GetNodeClass())
	{
		return Class->IsNative();
	}

	return false;
}

bool USMGraphNode_Base::IsNodeFastPathEnabled() const
{
	if (BoundGraph == nullptr)
	{
		return false;
	}
	
	if (bFastPathEnabledCached.IsSet())
	{
		return *bFastPathEnabledCached;
	}

	bool bIsFastPath = true;
	
	TArray<USMGraphK2Node_RuntimeNode_Base*> RootNodeList;
	FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphK2Node_RuntimeNode_Base>(BoundGraph, RootNodeList);

	for (const USMGraphK2Node_RuntimeNode_Base* RootNode : RootNodeList)
	{
		if (RootNode->IsConsideredForEntryConnection() && !RootNode->IsFastPathEnabled())
		{
			bIsFastPath = false;
			break;
		}
	}

	bFastPathEnabledCached = bIsFastPath;
	return bIsFastPath;
}

USMGraph* USMGraphNode_Base::GetStateMachineGraph() const
{
	return Cast<USMGraph>(GetGraph());
}

FSMNode_Base* USMGraphNode_Base::FindRuntimeNode() const
{
	return FSMBlueprintEditorUtils::GetRuntimeNodeFromGraph(GetBoundGraph());
}

const FSMNode_Base* USMGraphNode_Base::GetDebugNode() const
{
	USMBlueprint* Blueprint = CastChecked<USMBlueprint>(FSMBlueprintEditorUtils::FindBlueprintForNode(this));

	if (USMInstance* Instance = Cast<USMInstance>(Blueprint->GetObjectBeingDebugged()))
	{
		if (FSMNode_Base* RuntimeNode = FindRuntimeNode())
		{
			const FSMDebugStateMachine& DebugMachine = Instance->GetDebugStateMachineConst();

			// Find the real runtime node being debugged.
			return DebugMachine.GetRuntimeNode(RuntimeNode->GetNodeGuid());
		}
	}

	return nullptr;
}

float USMGraphNode_Base::GetMaxDebugTime() const
{
	const USMEditorSettings* Settings = FSMBlueprintEditorUtils::GetEditorSettings();
	return Settings->TimeToDisplayLastActiveState + Settings->TimeToFadeLastActiveState;
}

FLinearColor USMGraphNode_Base::GetBackgroundColor() const
{
	const FLinearColor* CustomColor = GetCustomBackgroundColor();
	const FLinearColor BaseColor = Internal_GetBackgroundColor() * (CustomColor ? *CustomColor : FLinearColor(1.f, 1.f, 1.f, 1.f));
	const FLinearColor ActiveColor = GetActiveBackgroundColor();

	if (GetDebugNode() == nullptr)
	{
		return BaseColor;
	}

	if (IsDebugNodeActive())
	{
		return ActiveColor;
	}

	const float TimeToFade = 0.7f;
	const float DebugTime = GetDebugTime();

	if (bWasDebugActive && DebugTime < TimeToFade)
	{
		return FLinearColor::LerpUsingHSV(ActiveColor, BaseColor, DebugTime / TimeToFade);
	}

	return BaseColor;
}

FLinearColor USMGraphNode_Base::GetActiveBackgroundColor() const
{
	const USMEditorSettings* Settings = FSMBlueprintEditorUtils::GetEditorSettings();
	return Settings->ActiveStateColor;
}

const FSlateBrush* USMGraphNode_Base::GetNodeIcon()
{
	return nullptr;
}

bool USMGraphNode_Base::ConvertToCurrentVersion(bool bOnlyOnLoad)
{	
	if ((!IsTemplate() && GetLinker() && GetLinker()->IsPersistent() && GetLinker()->IsLoading()) || !bOnlyOnLoad)
	{
		if (GetDefaultNodeClass())
		{
			if (NodeInstanceTemplate == nullptr)
			{
				// Configure pre 2.3 nodes that are missing node instance templates.
				InitTemplate();
			}
			if (LoadedVersion < TEMPLATE_PROPERTY_VERSION)
			{
				// Pre 2.3 nodes need to have their properties imported to the node instance template.
				ImportDeprecatedProperties();
			}
			if (LoadedVersion < STATESTACK_VERSION)
			{
				// Pre 2.4 nodes need their graph property guids updated to account for different node templates.
				
				bRequiresGuidRegeneration = true;
				bNeedsStateStackConversion = true;

				if (!bIsPrecompiling)
				{
					// If pre-compile isn't what called the upgrade method we need to force recreate the properties
					// as a precaution because the booleans aren't saved and this is a one time upgrade. Testing
					// show that this branch shouldn't be called.
					bRequiresGuidRegeneration = false;
					bNeedsStateStackConversion = false;
				}
			}
		}

		return SetToCurrentVersion();
	}

	return false;
}

bool USMGraphNode_Base::SetToCurrentVersion()
{
	const int32 LastVersion = LoadedVersion;
	LoadedVersion = CURRENT_VERSION;

	return LastVersion != LoadedVersion;
}

void USMGraphNode_Base::ForceSetVersion(int32 NewVersion)
{
	LoadedVersion = NewVersion;
}


void USMGraphNode_Base::RequestSlateRefresh(bool bFullRefresh)
{
	OnGraphNodeRefreshRequestedEvent.Broadcast(this, bFullRefresh);
}

void USMGraphNode_Base::ResetCachedValues()
{
	bFastPathEnabledCached.Reset();
}

FLinearColor USMGraphNode_Base::Internal_GetBackgroundColor() const
{
	return FLinearColor::Black;
}

const FLinearColor* USMGraphNode_Base::GetCustomBackgroundColor(const USMNodeInstance* NodeInstance) const
{
	return nullptr;
}

#undef LOCTEXT_NAMESPACE
