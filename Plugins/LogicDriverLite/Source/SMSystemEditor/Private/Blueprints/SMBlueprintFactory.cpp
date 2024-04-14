// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMBlueprintFactory.h"
#include "Utilities/SMVersionUtils.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Graph/SMGraphK2.h"
#include "Graph/Schema/SMGraphK2Schema.h"
#include "Graph/Schema/SMGraphSchema.h"

#include "Blueprints/SMBlueprint.h"
#include "SMInstance.h"
#include "SMConduitInstance.h"
#include "SMStateMachineInstance.h"
#include "SMTransitionInstance.h"

#include "Modules/ModuleManager.h"
#include "Misc/MessageDialog.h"
#include "EdGraphSchema_K2.h"
#include "K2Node_CallFunction.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/SClassPickerDialog.h"
#include "BlueprintEditorSettings.h"
#include "ClassViewer/Private/UnloadedBlueprintData.h"

#define LOCTEXT_NAMESPACE "SMBlueprintFactory"

/**
 * Copied out of Factories/EditorFactories.cpp
 */
class FAssetClassParentFilter : public IClassViewerFilter
{
public:
	FAssetClassParentFilter()
		: DisallowedClassFlags(CLASS_None), bDisallowBlueprintBase(false)
	{}

	/** All children of these classes will be included unless filtered out by another setting. */
	TSet< const UClass* > AllowedChildrenOfClasses;

	/** Disallowed class flags. */
	EClassFlags DisallowedClassFlags;

	/** Disallow blueprint base classes. */
	bool bDisallowBlueprintBase;

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		bool bAllowed = !InClass->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;

		if (bAllowed && bDisallowBlueprintBase)
		{
			if (FKismetEditorUtilities::CanCreateBlueprintOfClass(InClass))
			{
				return false;
			}
		}

		return bAllowed;
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef< const IUnloadedBlueprintData > InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
	{
		if (bDisallowBlueprintBase)
		{
			return false;
		}

		return !InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags)
			&& InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) != EFilterReturn::Failed;
	}
};


USMBlueprintFactory::USMBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), BlueprintType()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = USMBlueprint::StaticClass();
	ParentClass = USMInstance::StaticClass();
}

UObject* USMBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	// Make sure we are trying to factory a SM Blueprint, then create and init one
	check(Class->IsChildOf(USMBlueprint::StaticClass()));

	// If they selected an interface, force the parent class to be UInterface
	if (BlueprintType == BPTYPE_Interface)
	{
		ParentClass = UInterface::StaticClass();
	}

	if (!ParentClass || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass) || !ParentClass->IsChildOf(USMInstance::StaticClass()))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), (ParentClass != NULL) ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateStateMachineBlueprint", "Cannot create a State Machine Blueprint based on the class '{ClassName}'."), Args));
		return nullptr;
	}

	USMBlueprint* NewStateMachineBP = CastChecked<USMBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BlueprintType, USMBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext));
	return NewStateMachineBP;
}

UObject* USMBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

bool USMBlueprintFactory::DoesSupportClass(UClass* Class)
{
	return Class == USMBlueprint::StaticClass();
}

FString USMBlueprintFactory::GetDefaultNewAssetName() const
{
	return "BP_StateMachine";
}

void USMBlueprintFactory::CreateGraphsForBlueprintIfMissing(USMBlueprint* Blueprint)
{
	if (FSMBlueprintEditorUtils::GetTopLevelStateMachineGraph(Blueprint) == nullptr)
	{
		CreateGraphsForNewBlueprint(Blueprint);
	}
}

void USMBlueprintFactory::CreateGraphsForNewBlueprint(USMBlueprint* Blueprint)
{
	// New blueprints should always be on the latest version.
	FSMVersionUtils::SetToLatestVersion(Blueprint);
	
	// Locate the blueprint's event graph or create a new one.
	UEdGraph* EventGraph = FindObject<UEdGraph>(Blueprint, *(UEdGraphSchema_K2::GN_EventGraph.ToString()));

	if (!EventGraph)
	{
#if WITH_EDITORONLY_DATA
		if (Blueprint->UbergraphPages.Num())
		{
			FBlueprintEditorUtils::RemoveGraphs(Blueprint, Blueprint->UbergraphPages);
		}
#endif
		EventGraph = FBlueprintEditorUtils::CreateNewGraph(Blueprint, UEdGraphSchema_K2::GN_EventGraph, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());

		FBlueprintEditorUtils::AddUbergraphPage(Blueprint, EventGraph);
		EventGraph->bAllowDeletion = false;

		const UEdGraphSchema* EventGraphSchema = EventGraph->GetSchema();
		EventGraphSchema->CreateDefaultNodesForGraph(*EventGraph);
	}

	UBlueprintEditorSettings* Settings = GetMutableDefault<UBlueprintEditorSettings>();
	if (Settings && Settings->bSpawnDefaultBlueprintNodes)
	{
		// Create default events.
		const int32 NodePositionX = 255;
		int32 NodePositionY = 0;
		
		// OnStateMachineStart
		UK2Node_Event* OnStateMachineStartedNode = FKismetEditorUtilities::AddDefaultEventNode(Blueprint, EventGraph, GET_FUNCTION_NAME_CHECKED(USMInstance, OnStateMachineStart), USMInstance::StaticClass(), NodePositionY);
		if (USMGraphK2Schema::GetThenPin(OnStateMachineStartedNode)->LinkedTo.Num() == 0)
		{
			FSMBlueprintEditorUtils::CreateParentFunctionCall(EventGraph, USMInstance::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMInstance, OnStateMachineStart)), OnStateMachineStartedNode, NodePositionX);
		}
		
		// Tick
		UK2Node_Event* TickFunctionNode = FKismetEditorUtilities::AddDefaultEventNode(Blueprint, EventGraph, GET_FUNCTION_NAME_CHECKED(USMInstance, Tick), USMInstance::StaticClass(), NodePositionY);
		if (USMGraphK2Schema::GetThenPin(TickFunctionNode)->LinkedTo.Num() == 0)
		{
			FSMBlueprintEditorUtils::CreateParentFunctionCall(EventGraph, USMInstance::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMInstance, Tick)), TickFunctionNode, NodePositionX);
		}

		int32 SafeXPosition = 0;
		int32 SafeYPosition = 0;

		if (EventGraph->Nodes.Num() != 0)
		{
			// Place right under OnStateMachineStart node.
			SafeXPosition = EventGraph->Nodes[0]->NodePosX;
			SafeYPosition = EventGraph->Nodes[0]->NodePosY + EventGraph->Nodes[0]->NodeHeight + 70;
		}

		// Add a getter for the context for the state machine.
		UK2Node_CallFunction* GetOwnerNode = NewObject<UK2Node_CallFunction>(EventGraph);
		UFunction* MakeNodeFunction = USMInstance::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(USMInstance, GetContext));
		GetOwnerNode->CreateNewGuid();
		GetOwnerNode->PostPlacedNewNode();
		GetOwnerNode->SetFromFunction(MakeNodeFunction);
		GetOwnerNode->SetFlags(RF_Transactional);
		GetOwnerNode->AllocateDefaultPins();
		GetOwnerNode->NodePosX = SafeXPosition;
		GetOwnerNode->NodePosY = SafeYPosition;
		UEdGraphSchema_K2::SetNodeMetaData(GetOwnerNode, FNodeMetadata::DefaultGraphNode);
		GetOwnerNode->MakeAutomaticallyPlacedGhostNode();

		EventGraph->AddNode(GetOwnerNode);
	}

	// Default top level state machine graph
	USMGraphK2* NewTopLevelGraph = CastChecked<USMGraphK2>(FBlueprintEditorUtils::CreateNewGraph(Blueprint, USMGraphK2Schema::GN_StateMachineDefinitionGraph, USMGraphK2::StaticClass(), USMGraphK2Schema::StaticClass()));
	NewTopLevelGraph->bAllowDeletion = false;
	FBlueprintEditorUtils::AddUbergraphPage(Blueprint, NewTopLevelGraph);

	const UEdGraphSchema* StateMachineGraphSchema = NewTopLevelGraph->GetSchema();
	StateMachineGraphSchema->CreateDefaultNodesForGraph(*NewTopLevelGraph);

	// Set the first graph to the new state machine.
	TArray<USMGraphK2Node_StateMachineNode*> StateMachineNodes;
	FBlueprintEditorUtils::GetAllNodesOfClass<USMGraphK2Node_StateMachineNode>(Blueprint, StateMachineNodes);
	check(StateMachineNodes.Num() == 1);

	USMGraph* StateMachineGraph = StateMachineNodes[0]->GetStateMachineGraph();
	Blueprint->LastEditedDocuments.Reset();
	Blueprint->LastEditedDocuments.Add(StateMachineGraph);
}

#undef LOCTEXT_NAMESPACE
