// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPC.generated.h"

/**
 * 
 */
UCLASS()
class BOOMJAM_API AMyPC : public APlayerController
{
	GENERATED_BODY()
	
	AMyPC();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
