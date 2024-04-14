// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMNodeInstance.h"
#include "CoreMinimal.h"
#include "SMInstance.h"

#include "SMUtils.h"

#include "Engine/InputDelegateBinding.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"


DEFINE_STAT(STAT_NodeInstances);

USMNodeInstance::USMNodeInstance() : Super(), OwningNode(nullptr)
{
	INC_DWORD_STAT(STAT_NodeInstances)
}

UWorld* USMNodeInstance::GetWorld() const
{
	if (UObject* Context = GetContext())
	{
		return Context->GetWorld();
	}

	return nullptr;
}

void USMNodeInstance::BeginDestroy()
{
	Super::BeginDestroy();
	DEC_DWORD_STAT(STAT_NodeInstances)
}

UObject* USMNodeInstance::GetContext() const
{
	if (USMInstance* SMInstance = GetStateMachineInstance())
	{
		return SMInstance->GetContext();
	}

	return nullptr;
}

USMInstance* USMNodeInstance::GetStateMachineInstance(bool bTopMostInstance) const
{
	if (USMInstance* Instance = Cast<USMInstance>(GetOuter()))
	{
		if (bTopMostInstance)
		{
			return Instance->GetPrimaryReferenceOwner();
		}

		return Instance;
	}

	return nullptr;
}

void USMNodeInstance::SetOwningNode(FSMNode_Base* Node)
{
	OwningNode = Node;
}

USMStateMachineInstance* USMNodeInstance::GetOwningStateMachineNodeInstance() const
{
	if (const FSMNode_Base* Node = GetOwningNode())
	{
		if (FSMNode_Base* NodeOwner = Node->GetOwnerNode())
		{
			return Cast<USMStateMachineInstance>(NodeOwner->GetOrCreateNodeInstance());
		}
	}

	return nullptr;
}

TScriptInterface<ISMStateMachineNetworkedInterface> USMNodeInstance::GetNetworkInterface() const
{
	if (USMInstance* Instance = GetStateMachineInstance())
	{
		return Instance->GetNetworkInterface();
	}

	return nullptr;
}

float USMNodeInstance::GetTimeInState() const
{
	return OwningNode ? OwningNode->TimeInState : 0.f;
}

bool USMNodeInstance::IsInEndState() const
{
	return OwningNode ? OwningNode->bIsInEndState : false;
}

bool USMNodeInstance::HasUpdated() const
{
	return OwningNode ? OwningNode->bHasUpdated : false;
}

bool USMNodeInstance::IsActive() const
{
	return OwningNode ? OwningNode->IsActive() : false;
}

const FString& USMNodeInstance::GetNodeName() const
{
	static FString EmptyString;
	if (const FSMNode_Base* Node = GetOwningNodeContainer())
	{
		return Node->GetNodeName();
	}
	return EmptyString;
}

const FGuid& USMNodeInstance::GetGuid() const
{
	static FGuid BlankGuid;
	return OwningNode ? OwningNode->GetGuid() : BlankGuid;
}
