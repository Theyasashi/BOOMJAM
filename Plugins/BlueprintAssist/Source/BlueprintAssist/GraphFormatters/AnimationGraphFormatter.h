// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleFormatter.h"

class BLUEPRINTASSIST_API FAnimationGraphFormatter final
	: public FSimpleFormatter
{
public:
	FAnimationGraphFormatter(const TSharedPtr<FBAGraphHandler> & InGraphHandler);
	FBAFormatterSettings GetFormatterSettings() override;
};
