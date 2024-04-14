// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMVersionUtils.h"

#include "Utilities/SMBlueprintEditorUtils.h"
#include "Blueprints/SMBlueprintFactory.h"

#include "Blueprints/SMBlueprint.h"

#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "AssetRegistryModule.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Misc/ScopedSlowTask.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "SMVersionUtils"

#define LD_SM_BLUEPRINT_VERSION 3
#define LD_NODE_BLUEPRINT_VERSION 1

static TWeakPtr<SNotificationItem> WrongVersionNotification;

int32 FSMVersionUtils::GetCurrentBlueprintVersion()
{
	return LD_SM_BLUEPRINT_VERSION;
}

int32 FSMVersionUtils::GetCurrentBlueprintNodeVersion()
{
	return LD_NODE_BLUEPRINT_VERSION;
}

void FSMVersionUtils::UpdateBlueprintsToNewVersion()
{
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry")).Get();

	TArray<FAssetData> OutStateMachineAssets, AssetsToUpdate;
	AssetRegistry.GetAssetsByClass(USMBlueprint::StaticClass()->GetFName(), OutStateMachineAssets, true);

	bool bIsAssetVersionNotSupported = false;

	// State machines next.
	for (const FAssetData& Asset : OutStateMachineAssets)
	{
		int32 Version = 0;
		
		const bool bVersionFound = Asset.GetTagValue(GET_MEMBER_NAME_CHECKED(USMBlueprint, AssetVersion), Version);
		if (!bVersionFound || !IsStateMachineUpToDate(Version))
		{
			AssetsToUpdate.Add(Asset);
			continue;
		}

		if (IsStateMachineFromNewerPluginVersion(Version))
		{
			bIsAssetVersionNotSupported = true;
		}
	}

	if (bIsAssetVersionNotSupported)
	{
		// There are assets from a newer version of the plugin.
		FNotificationInfo Info(LOCTEXT("LogicDriverAssetsFromNewerVersion", "Logic Driver assets are from a newer version of the plugin!\nPlease update Logic Driver and verify your team is using the same version."));
		Info.bFireAndForget = false;
		Info.bUseLargeFont = false;
		Info.bUseThrobber = false;
		Info.FadeOutDuration = 0.25f;
		Info.ButtonDetails.Add(FNotificationButtonInfo(LOCTEXT("LogicDriverWrongVersionDismiss", "Dismiss"), LOCTEXT("LogicDriverWrongVersionDismissTT", "Dismiss this notification"), FSimpleDelegate::CreateStatic(&FSMVersionUtils::DismissWrongVersionNotification)));
		
		WrongVersionNotification = FSlateNotificationManager::Get().AddNotification(Info);
		WrongVersionNotification.Pin()->SetCompletionState(SNotificationItem::CS_Pending);
	}

	if (AssetsToUpdate.Num() > 0)
	{
		FScopedSlowTask Feedback(AssetsToUpdate.Num(), NSLOCTEXT("LogicDriver", "LogicDriverAssetUpdate", "Updating Logic Driver assets to the current version..."));

		if (FSMBlueprintEditorUtils::GetProjectEditorSettings()->bDisplayAssetUpdateProgress)
		{
			Feedback.MakeDialog(true);
		}
		
		for (FAssetData& Asset : AssetsToUpdate)
		{
			if (USMBlueprint* SMBlueprint = Cast<USMBlueprint>(Asset.GetAsset()))
			{
				// Fixes existing broken graphs for t-141.
				USMBlueprintFactory::CreateGraphsForBlueprintIfMissing(SMBlueprint);
				
				TArray<USMGraphNode_Base*> GraphNodes;
				FSMBlueprintEditorUtils::GetAllNodesOfClassNested<USMGraphNode_Base>(SMBlueprint, GraphNodes);

				for (USMGraphNode_Base* Node : GraphNodes)
				{
					Node->ConvertToCurrentVersion(false);
				}

				SetToLatestVersion(SMBlueprint);
				SMBlueprint->MarkPackageDirty();
			}
			else if (USMNodeBlueprint* NodeBlueprint = Cast<USMNodeBlueprint>(Asset.GetAsset()))
			{
				SetToLatestVersion(NodeBlueprint);
				// For now we just need to recompile the node BP.
				FBlueprintEditorUtils::MarkBlueprintAsModified(NodeBlueprint);
			}
			
			Feedback.CompletedWork += 1;
		}
	}
}

bool FSMVersionUtils::IsStateMachineUpToDate(int32 CompareVersion)
{
	return CompareVersion >= GetCurrentBlueprintVersion();
}

bool FSMVersionUtils::IsStateMachineNodeUpToDate(int32 CompareVersion)
{
	return CompareVersion >= GetCurrentBlueprintNodeVersion();
}

bool FSMVersionUtils::IsAssetUpToDate(UBlueprint* Blueprint)
{
	if (USMBlueprint* SMBlueprint = Cast<USMBlueprint>(Blueprint))
	{
		const int32 Version = SMBlueprint->AssetVersion;
		return IsStateMachineUpToDate(Version);
	}
	
	return false;
}

bool FSMVersionUtils::IsStateMachineFromNewerPluginVersion(int32 CompareVersion)
{
	return CompareVersion > GetCurrentBlueprintVersion();
}

bool FSMVersionUtils::IsStateMachineNodeFromNewerPluginVersion(int32 CompareVersion)
{
	return CompareVersion > GetCurrentBlueprintNodeVersion();
}

void FSMVersionUtils::SetToLatestVersion(UBlueprint* Blueprint)
{
	if (USMBlueprint* SMBlueprint = Cast<USMBlueprint>(Blueprint))
	{
		SMBlueprint->AssetVersion = GetCurrentBlueprintVersion();
	}
}

void FSMVersionUtils::DismissWrongVersionNotification()
{
	WrongVersionNotification.Pin()->ExpireAndFadeout();
}

#undef LOCTEXT_NAMESPACE
