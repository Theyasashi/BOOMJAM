// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

#include "Engine/CurveTable.h"


UCurveTable * UMyBlueprintFunctionLibrary::LoadCurveTable(const FSoftObjectPath& SoftPath)
{
    return Cast<UCurveTable>(SoftPath.TryLoad());
}

FGameplayTag UMyBlueprintFunctionLibrary::MakeGameplayTagFromString(const FString & TagName)
{
    return FGameplayTag::RequestGameplayTag(FName(TagName));
}

FGameplayTag UMyBlueprintFunctionLibrary::MakeGameplayTagFromName(const FName & TagName)
{
    return FGameplayTag::RequestGameplayTag(TagName);
}
