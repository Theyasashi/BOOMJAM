// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleFormatter.h"

class BLUEPRINTASSIST_API FMaterialGraphFormatter final
	: public FSimpleFormatter
{
public:
	FMaterialGraphFormatter(const TSharedPtr<FBAGraphHandler> & InGraphHandler);
	FBAFormatterSettings GetFormatterSettings() override;
};
