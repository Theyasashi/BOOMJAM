// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMProjectEditorSettings.h"

USMProjectEditorSettings::USMProjectEditorSettings()
{
	InstalledVersion = "";
	bUpdateAssetsOnStartup = true;
	bDisplayAssetUpdateProgress = true;
	bDisplayUpdateNotification = true;
	
	bDisplayMemoryLimitsOnCompile = true;
	bAlwaysDisplayStructMemoryUsage = false;
	StructMemoryLimitWarningThreshold = 0.9f;
	
	bRestrictInvalidCharacters = true;
	bValidateInstanceOnCompile = true;
	bWarnIfChildrenAreOutOfDate = true;
	bLinkerLoadHandling = true;
	
	bDefaultNewTransitionsToTrue = false;
	bConfigureNewConduitsAsTransitions = true;

	bEnableReferenceTemplatesByDefault = false;
}

void USMProjectEditorSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	SaveConfig();
}
