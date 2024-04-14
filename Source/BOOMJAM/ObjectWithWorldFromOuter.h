// Fill out your copyright notice in the Description page of Project Settings.
 
#pragma once
 
#include "CoreMinimal.h"
#include "ObjectWithWorldFromOuter.generated.h"
 
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract)
class BOOMJAM_API UObjectWithWorldFromOuter : public UObject
{
    GENERATED_BODY()
 
public:
    UWorld* GetWorld() const override;
     
};