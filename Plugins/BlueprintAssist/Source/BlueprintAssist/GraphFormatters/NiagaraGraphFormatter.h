// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleFormatter.h"

class BLUEPRINTASSIST_API FNiagaraGraphFormatter final
	: public FSimpleFormatter
{
public:
	FNiagaraGraphFormatter(const TSharedPtr<FBAGraphHandler> & InGraphHandler);
	FBAFormatterSettings GetFormatterSettings() override;
};