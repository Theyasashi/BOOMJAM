// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistSizeCache.h"
#include "BlueprintAssistModule.h"

#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"

#include "Projects/Public/Interfaces/IPluginManager.h"
#include "Core/Public/Misc/FileHelper.h"
#include "Core/Public/HAL/PlatformFilemanager.h"
#include "Core/Public/Misc/CoreDelegates.h"
#include "JsonUtilities/Public/JsonObjectConverter.h"
#include "EngineSettings/Classes/GeneralProjectSettings.h"
#include "AssetRegistry/Public/IAssetRegistry.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "AssetRegistry/Public/AssetRegistryState.h"
#include "Engine/Blueprint.h"
#include "BlueprintAssistSettings.h"

FBASizeCache::FBASizeCache()
{
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
	AssetRegistry.OnFilesLoaded().AddLambda([&]()
	{
		LoadCache();
	});

	FCoreDelegates::OnPreExit.AddRaw(this, &FBASizeCache::SaveCache);
}

void FBASizeCache::LoadCache()
{
	if (!GetDefault<UBASettings>()->bSaveBlueprintAssistCacheToFile)
	{
		return;
	}

	const auto CachePath = GetCachePath();

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*CachePath))
	{
		FString FileData;
		FFileHelper::LoadFileToString(FileData, *CachePath);

		if (FJsonObjectConverter::JsonObjectStringToUStruct(FileData, &PackageData, 0, 0))
		{
			UE_LOG(LogBlueprintAssist, Log, TEXT("Loaded blueprint assist node size cache: %s"), *CachePath);
		}
		else
		{
			UE_LOG(LogBlueprintAssist, Log, TEXT("Failed to load node size cache: %s"), *CachePath);
		}
	}

	CleanupFiles();
}

void FBASizeCache::SaveCache()
{
	if (!GetDefault<UBASettings>()->bSaveBlueprintAssistCacheToFile)
	{
		return;
	}

	const auto CachePath = GetCachePath();

	// Write data to file
	FString JsonAsString;
	FJsonObjectConverter::UStructToJsonObjectString(PackageData, JsonAsString);
	FFileHelper::SaveStringToFile(JsonAsString, *CachePath);
	UE_LOG(LogBlueprintAssist, Log, TEXT("Saved node cache to %s"), *CachePath);
}

void FBASizeCache::DeleteCache()
{
	FString CachePath = GetCachePath();
	PackageData.PackageCache.Empty();

	if (FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*CachePath))
	{
		UE_LOG(LogBlueprintAssist, Log, TEXT("Deleted cache file at %s"), *CachePath);
	}
	else
	{
		UE_LOG(LogBlueprintAssist, Log, TEXT("Delete cache failed: Cache file does not exist or is read-only %s"), *CachePath);
	}
}

void FBASizeCache::CleanupFiles()
{
	// Get all assets
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	// Get package guids from assets
	TSet<FName> CurrentPackageNames;
	const auto& AssetDataMap = AssetRegistry.GetAssetRegistryState()->GetObjectPathToAssetDataMap();
	for (const TPair<FName, const FAssetData*>& AssetDataPair : AssetDataMap)
	{
		const FAssetData* AssetData = AssetDataPair.Value;
		CurrentPackageNames.Add(AssetData->PackageName);
	}

	// Remove missing files
	TArray<FName> OldPackageGuids;
	PackageData.PackageCache.GetKeys(OldPackageGuids);
	for (FName PackageGuid : OldPackageGuids)
	{
		if (!CurrentPackageNames.Contains(PackageGuid))
		{
			PackageData.PackageCache.Remove(PackageGuid);
		}
	}
}

FBACacheData& FBASizeCache::GetGraphData(UEdGraph* Graph)
{
	UPackage* Package = Graph->GetOutermost();

	FBAGraphData& CacheData = PackageData.PackageCache.FindOrAdd(Package->GetFName());

	return CacheData.GraphCache.FindOrAdd(Graph->GraphGuid);
}

FString FBASizeCache::GetCachePath()
{
	const FString PluginDir = IPluginManager::Get().FindPlugin("BlueprintAssist")->GetBaseDir();

	const UGeneralProjectSettings* ProjectSettings = GetDefault<UGeneralProjectSettings>();
	const FGuid& ProjectID = ProjectSettings->ProjectID;

	return PluginDir + "/NodeSizeCache/" + ProjectID.ToString() + ".json";
}

void FBACacheData::CleanupGraph(UEdGraph* Graph)
{
	if (Graph == nullptr)
	{
		UE_LOG(LogBlueprintAssist, Error, TEXT("Tried to cleanup null graph"));
	}
	
	// Get all the current nodes and pins from the graph
	TSet<FGuid> CurrentNodes;
	TSet<FGuid> CurrentPins;
	for (UEdGraphNode* Node : Graph->Nodes)
	{
		CurrentNodes.Add(Node->NodeGuid);
		for (UEdGraphPin* Pin : Node->Pins)
		{
			CurrentPins.Add(Pin->PinId);
		}
	}

	// Remove any missing guids from the cached nodes
	TArray<FGuid> CachedNodeGuids;
	CachedNodes.GetKeys(CachedNodeGuids);

	for (FGuid NodeGuid : CachedNodeGuids)
	{
		if (!CurrentNodes.Contains(NodeGuid))
		{
			CachedNodes.Remove(NodeGuid);
		}
	}

	// Remove any missing guids from the cached pins
	TArray<FGuid> CachedPinGuids;
	CachedPins.GetKeys(CachedPinGuids);
	for (FGuid PinGuid : CachedPinGuids)
	{
		if (!CurrentPins.Contains(PinGuid))
		{
			CachedPins.Remove(PinGuid);
		}
	}
}
