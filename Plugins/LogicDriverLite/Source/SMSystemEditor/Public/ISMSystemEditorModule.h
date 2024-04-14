// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/**
 * The public interface to this module
 */
class ISMSystemEditorModule : public IModuleInterface
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static ISMSystemEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked< ISMSystemEditorModule >( "SMSystemEditor" );
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "SMSystemEditor" );
	}

	virtual TSharedPtr<class FExtensibilityManager> GetMenuExtensibilityManager() const = 0;
	virtual TSharedPtr<class FExtensibilityManager> GetToolBarExtensibilityManager() const = 0;
	virtual bool IsPlayingInEditor() const = 0;
};

