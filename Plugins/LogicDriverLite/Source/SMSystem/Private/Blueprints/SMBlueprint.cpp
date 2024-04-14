// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "Blueprints/SMBlueprint.h"
#include "Blueprints/SMBlueprintGeneratedClass.h"
#include "SMInstance.h"
#include "SMNodeInstance.h"
#include "SMStateInstance.h"
#include "SMStateMachineInstance.h"
#include "SMTransitionInstance.h"


USMBlueprint::USMBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BlueprintType = BPTYPE_Normal;
#if WITH_EDITORONLY_DATA
	BlueprintCategory = "State Machines";
#endif
}

#if WITH_EDITOR

UClass* USMBlueprint::GetBlueprintClass() const
{
	return USMBlueprintGeneratedClass::StaticClass();
}

void USMBlueprint::GetReparentingRules(TSet<const UClass*>& AllowedChildrenOfClasses,
	TSet<const UClass*>& DisallowedChildrenOfClasses) const
{
	AllowedChildrenOfClasses.Add(USMInstance::StaticClass());
}

USMBlueprint::FOnRenameGraph USMBlueprint::OnRenameGraphEvent;

void USMBlueprint::NotifyGraphRenamed(UEdGraph* Graph, FName OldName, FName NewName)
{
	Super::NotifyGraphRenamed(Graph, OldName, NewName);
	OnRenameGraphEvent.Broadcast(this, Graph, OldName, NewName);
}

USMBlueprint* USMBlueprint::FindOldestParentBlueprint() const
{
	USMBlueprint* ParentBP = nullptr;

	// Find the root State Machine.
	for (UClass* NextParentClass = ParentClass; NextParentClass && (UObject::StaticClass() != NextParentClass); NextParentClass = NextParentClass->GetSuperClass())
	{
		if (USMBlueprint* TestBP = Cast<USMBlueprint>(ParentClass->ClassGeneratedBy))
		{
			ParentBP = TestBP;
		}
	}

	return ParentBP;
}
#endif

USMBlueprintGeneratedClass* USMBlueprint::GetGeneratedClass() const
{
	return Cast<USMBlueprintGeneratedClass>(*GeneratedClass);
}


USMNodeBlueprint::USMNodeBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BlueprintType = BPTYPE_Normal;
#if WITH_EDITORONLY_DATA
	BlueprintCategory = "State Machines";
#endif
}

#if WITH_EDITOR

UClass* USMNodeBlueprint::GetBlueprintClass() const
{
	return USMNodeBlueprintGeneratedClass::StaticClass();
}

void USMNodeBlueprint::GetReparentingRules(TSet<const UClass*>& AllowedChildrenOfClasses,
	TSet<const UClass*>& DisallowedChildrenOfClasses) const
{
	if (ParentClass)
	{
		if (ParentClass->IsChildOf(USMStateInstance::StaticClass()))
		{
			AllowedChildrenOfClasses.Add(USMStateInstance::StaticClass());
		}
		else if (ParentClass->IsChildOf(USMTransitionInstance::StaticClass()))
		{
			AllowedChildrenOfClasses.Add(USMTransitionInstance::StaticClass());
		}
		else if (ParentClass->IsChildOf(USMStateMachineInstance::StaticClass()))
		{
			AllowedChildrenOfClasses.Add(USMStateMachineInstance::StaticClass());
		}
	}

	if (AllowedChildrenOfClasses.Num() == 0)
	{
		AllowedChildrenOfClasses.Add(USMNodeInstance::StaticClass());
	}
}

#endif

USMNodeBlueprintGeneratedClass* USMNodeBlueprint::GetGeneratedClass() const
{
	return Cast<USMNodeBlueprintGeneratedClass>(*GeneratedClass);
}
