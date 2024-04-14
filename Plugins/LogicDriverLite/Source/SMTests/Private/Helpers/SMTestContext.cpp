// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMTestContext.h"

float USMTestContext::GreaterThanTest = 5;

void USMTestContext::IncreaseUpdateInt(float Value)
{
	TestUpdateFromDeltaSecondsInt += FMath::RoundToInt(Value);
	TimesUpdateHit.Increase();
}

void USMTestContext::IncreaseTransitionInit()
{
	TestTransitionInit.Increase();
}

void USMTestContext::IncreaseTransitionShutdown()
{
	TestTransitionShutdown.Increase();
}

USMStateMachineTestComponent::USMStateMachineTestComponent(class FObjectInitializer const& ObjectInitializer) : Super(ObjectInitializer)
{
}

void USMStateMachineTestComponent::SetStateMachineClass(UClass* NewClass)
{
	StateMachineClass = NewClass;
}

void USMStateMachineTestComponent::ClearTemplateInstance()
{
	InstanceTemplate = nullptr;
}

void USMStateMachineTestComponent::SetAllowTick(bool bAllowOverride, bool bCanEverTick)
{
	bOverrideTick_DEPRECATED = bAllowOverride;
	bCanEverTick_DEPRECATED = bCanEverTick;
}

void USMStateMachineTestComponent::SetTickInterval(bool bAllowOverride, float TickInterval)
{
	bOverrideTickInterval_DEPRECATED = bAllowOverride;
	TickInterval_DEPRECATED = TickInterval;
}

void USMStateMachineTestComponent::ImportDeprecatedProperties_Public()
{
	ImportDeprecatedProperties();
}
