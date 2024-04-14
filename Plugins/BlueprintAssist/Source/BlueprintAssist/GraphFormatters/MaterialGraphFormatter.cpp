// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "MaterialGraphFormatter.h"

FMaterialGraphFormatter::FMaterialGraphFormatter(const TSharedPtr<FBAGraphHandler>& InGraphHandler)
	: FSimpleFormatter(InGraphHandler)
{
	FormatterDirection = EGPD_Input;
}

FBAFormatterSettings FMaterialGraphFormatter::GetFormatterSettings()
{
	return GetDefault<UBASettings>()->MaterialGraphFormatterSettings;
}