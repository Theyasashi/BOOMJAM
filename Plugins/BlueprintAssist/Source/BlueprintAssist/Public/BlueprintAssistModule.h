// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBlueprintAssist, Log, All)

class FBASizeCache;

/**
* The public interface to this module
*/
class IBlueprintAssistModule : public IModuleInterface
{
public:
	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline IBlueprintAssistModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IBlueprintAssistModule>("BlueprintAssist");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("BlueprintAssist");
	}

	virtual TSharedPtr<class FBAInputProcessor> GetInputProcessor() { return nullptr; }

	virtual void BindAssetOpenedDelegate() = 0;

	virtual void UnbindAssetOpenedDelegate() = 0;

	virtual FBASizeCache& GetSizeCache() = 0;
};
