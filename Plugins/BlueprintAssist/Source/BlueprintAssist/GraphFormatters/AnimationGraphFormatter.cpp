// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "AnimationGraphFormatter.h"

FAnimationGraphFormatter::FAnimationGraphFormatter(const TSharedPtr<FBAGraphHandler>& InGraphHandler)
	: FSimpleFormatter(InGraphHandler)
{
	FormatterDirection = EGPD_Input;
}

FBAFormatterSettings FAnimationGraphFormatter::GetFormatterSettings()
{
	return GetDefault<UBASettings>()->AnimationGraphFormatterSettings;
}