// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BOOMJAM_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static class UCurveTable* LoadCurveTable(const FSoftObjectPath& SoftPath);

	UFUNCTION(BlueprintCallable)
	static FGameplayTag MakeGameplayTagFromString(const FString& TagName);

	UFUNCTION(BlueprintCallable)
	static FGameplayTag MakeGameplayTagFromName(const FName& TagName);
};
