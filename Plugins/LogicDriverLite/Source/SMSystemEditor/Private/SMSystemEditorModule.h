// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "ISMSystemEditorModule.h"
#include "Blueprints/SMBlueprintAssetTypeActions.h"
#include "EdGraphUtilities.h"
#include "Compilers/SMKismetCompiler.h"

#include "EdGraphUtilities.h"

#define LOCTEXT_NAMESPACE "SMSystemEditorModule"

class FExtensibilityManager;

class FSMSystemEditorModule : public ISMSystemEditorModule
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Gets the extensibility managers for outside entities to extend this editor's menus and toolbars */
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() const override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() const override { return ToolBarExtensibilityManager; }

	/** If the user has pressed play in editor. */
	virtual bool IsPlayingInEditor() const override { return bPlayingInEditor; }
private:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);
	static TSharedPtr<FKismetCompilerContext> GetCompilerForStateMachineBP(UBlueprint* BP, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompileOptions);

	void RegisterSettings();
	void UnregisterSettings();

	void RegisterPinFactories();
	void UnregisterPinFactories();

	void BeginPIE(bool bValue);
	void EndPie(bool bValue);

	void OnAssetAdded(const FAssetData& InAssetData);
	
	void DisplayUpdateNotification();
	void OnViewNewPatchNotesClicked();
	void OnDismissUpdateNotificationClicked();
	
private:
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;

	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;

	TSharedPtr<FGraphPanelNodeFactory> SMGraphPanelNodeFactory;
	
	TSharedPtr<FGraphPanelPinFactory> SMGraphPinNodeFactory;

	TSharedPtr<FGraphPanelPinFactory> SMPinNodeNameFactory;
	FSMKismetCompiler SMBlueprintCompiler;

	FDelegateHandle RefreshAllNodesDelegateHandle;

	FDelegateHandle BeginPieHandle;
	FDelegateHandle EndPieHandle;

	FDelegateHandle AssetAddedHandle;
	FDelegateHandle FilesLoadedHandle;

	/** Notification popup that the plugin has updated. */
	TWeakPtr<SNotificationItem> NewVersionNotification;
	
	/** If the user has pressed play in editor. */
	bool bPlayingInEditor = false;
};

IMPLEMENT_MODULE(FSMSystemEditorModule, SMSystemEditor)


#undef LOCTEXT_NAMESPACE

