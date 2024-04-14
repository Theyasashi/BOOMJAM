// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once
#include "Kismet2/BlueprintEditorUtils.h"

class UBlueprint;

// Helpers for managing version updates.
class SMSYSTEMEDITOR_API FSMVersionUtils : public FBlueprintEditorUtils
{
public:
	/**
	 * State machine blueprints are saved with this version number.
	 * On plugin load this version is checked against the asset version.
	 */
	static int32 GetCurrentBlueprintVersion();

	/**
	 * Node blueprints are saved with this version number.
	 * On plugin load this version is checked against the asset version.
	 */
	static int32 GetCurrentBlueprintNodeVersion();
	
	/** Check all SM blueprints and update to a new version if necessary. */
	static void UpdateBlueprintsToNewVersion();

	/** Checks if the state machine needs an update. */
	static bool IsStateMachineUpToDate(int32 CompareVersion);

	/** Checks if the state machine node needs an update. */
	static bool IsStateMachineNodeUpToDate(int32 CompareVersion);
	
	/** Checks if a Logic Driver blueprint is up to date. */
	static bool IsAssetUpToDate(UBlueprint* Blueprint);

	/** Checks if the state machine is from a new plugin version than installed. */
	static bool IsStateMachineFromNewerPluginVersion(int32 CompareVersion);

	/** Checks if the state machine node is from a new plugin version than installed. */
	static bool IsStateMachineNodeFromNewerPluginVersion(int32 CompareVersion);
	
	/** Sets the version tag of the asset. */
	static void SetToLatestVersion(UBlueprint* Blueprint);
	
private:
	static void DismissWrongVersionNotification();
};

