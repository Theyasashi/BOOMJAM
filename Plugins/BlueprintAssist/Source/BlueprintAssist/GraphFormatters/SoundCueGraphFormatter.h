// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleFormatter.h"

class BLUEPRINTASSIST_API FSoundCueGraphFormatter final
	: public FSimpleFormatter
{
public:
	FSoundCueGraphFormatter(const TSharedPtr<FBAGraphHandler> & InGraphHandler);
	FBAFormatterSettings GetFormatterSettings() override;
};
