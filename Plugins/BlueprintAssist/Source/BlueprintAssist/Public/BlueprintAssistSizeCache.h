// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SGraphPin.h"

#include "BlueprintAssistSizeCache.generated.h"

USTRUCT()
struct BLUEPRINTASSIST_API FBACacheData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<FGuid, FVector2D> CachedNodes;

	UPROPERTY()
	TMap<FGuid, float> CachedPins;

	void CleanupGraph(UEdGraph* Graph);
};

USTRUCT()
struct BLUEPRINTASSIST_API FBAGraphData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<FGuid, FBACacheData> GraphCache;
};

USTRUCT()
struct BLUEPRINTASSIST_API FBAPackageData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TMap<FName, FBAGraphData> PackageCache;
};

class BLUEPRINTASSIST_API FBASizeCache : public TSharedFromThis<FBASizeCache>
{
public:
	FBASizeCache();

	FBAPackageData& GetPackageData() { return PackageData; }

	void LoadCache();

	void SaveCache();

	void DeleteCache();

	void CleanupFiles();

	FBACacheData& GetGraphData(UEdGraph* Graph);

	FString GetCachePath();

private:
	FBAPackageData PackageData;
};
