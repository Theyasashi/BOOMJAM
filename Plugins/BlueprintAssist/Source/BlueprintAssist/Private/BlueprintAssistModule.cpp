// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "BlueprintAssistModule.h"

#include "Modules/ModuleManager.h"
#include "GraphEditorModule.h"
#include "PropertyEditorModule.h"

#include "BlueprintEditorModule.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"

#include "Developer/Settings/Public/ISettingsModule.h"

#include "BlueprintAssistSettings.h"
#include "BlueprintAssistCommands.h"
#include "BlueprintAssistInputProcessor.h"
#include "BlueprintAssistSizeCache.h"
#include "BlueprintAssistToolbar.h"

#if ENGINE_MINOR_VERSION >= 24
#include "Subsystems/AssetEditorSubsystem.h"
#endif

#define LOCTEXT_NAMESPACE "BlueprintAssist"

DEFINE_LOG_CATEGORY(LogBlueprintAssist)

class FBlueprintAssistModule : public IBlueprintAssistModule
{
public:
	void StartupModule() override;

	void ShutdownModule() override;

	TSharedPtr<FBAInputProcessor> GetInputProcessor() override { return InputProcessor; }

	void BindAssetOpenedDelegate() override;

	void UnbindAssetOpenedDelegate() override;

	FBASizeCache& GetSizeCache() override { return SizeCache; }

private:
	bool bWasModuleInitialized = false;

	TSharedPtr<FBAInputProcessor> InputProcessor;

	FDelegateHandle OnAssetOpenedDelegateHandle;

	TSharedPtr<FExtender> ToolbarExtender;

	FBASizeCache SizeCache;

	FBAToolbar ToolbarMenu;

	void OnAssetOpenedInEditor(UObject* Asset, class IAssetEditorInstance* AssetEditor);
};

IMPLEMENT_MODULE(FBlueprintAssistModule, BlueprintAssist)

void FBlueprintAssistModule::StartupModule()
{
	if (!FSlateApplication::IsInitialized())
	{
		UE_LOG(LogBlueprintAssist, Log, TEXT("FBlueprintAssistModule: Slate App is not initialized, not loading the plugin"));
		return;
	}

	bWasModuleInitialized = true;

	// Initialize custom commands
	FBACommands::Register();
	FBAToolbarCommands::Register();

	ToolbarMenu.BindToolbarCommands();

	// Register custom settings to appear in the project settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings(
			"Editor",
			"Plugins",
			"BlueprintAssist",
			LOCTEXT("BlueprintAssistSettingsName", "Blueprint Assist"),
			LOCTEXT("BlueprintAssistSettingsNameDesc", "Configure the Blueprint Assist plugin"),
			GetMutableDefault<UBASettings>()
		);
	}
	else
	{
		UE_LOG(LogBlueprintAssist, Warning, TEXT("FBlueprintAssistModule: Failed to load settings module"));
	}

	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomClassLayout(UBASettings::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FBASettingsDetails::MakeInstance));

	// Initialize and register input processor
	InputProcessor = MakeShareable(new FBAInputProcessor());
	FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor);

	// Add toolbar extender
	if (GetMutableDefault<UBASettings>()->bAddToolbarWidget)
	{
		BindAssetOpenedDelegate();
	}

	UE_LOG(LogBlueprintAssist, Log, TEXT("Finished loaded BlueprintAssist Module"));
}

void FBlueprintAssistModule::ShutdownModule()
{
	if (!bWasModuleInitialized)
	{
		return;
	}

	// Cleanup input processor
	if (InputProcessor.IsValid())
	{
		if (FSlateApplication::IsInitialized())
		{
			FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);
		}

		InputProcessor->Cleanup();
		InputProcessor.Reset();
	}

	UnbindAssetOpenedDelegate();

	ToolbarExtender.Reset();

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Editor", "Plugins", "BlueprintAssist");
	}

	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout(UBASettings::StaticClass()->GetFName());

	FBACommands::Unregister();
	FBAToolbarCommands::Unregister();

	UE_LOG(LogBlueprintAssist, Log, TEXT("Shutdown BlueprintAssist Module"));
}

void FBlueprintAssistModule::BindAssetOpenedDelegate()
{
	// TODO: There no asset closed in editor delegate? This might cause issues if you reload the module
#if ENGINE_MINOR_VERSION < 24
	OnAssetOpenedDelegateHandle = FAssetEditorManager::Get().OnAssetOpenedInEditor().AddRaw(this, &FBlueprintAssistModule::OnAssetOpenedInEditor);
#else
	if (!GEditor)
	{
		UE_LOG(LogBlueprintAssist, Error, TEXT("GEditor Invalid: Toolbar cannot be loaded"));
		return;
	}
	
	UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	if (!AssetEditorSubsystem)
	{
		UE_LOG(LogBlueprintAssist, Error, TEXT("Asset Editor Subsystem Invalid: Toolbar cannot be loaded"));
		return;
	}
	OnAssetOpenedDelegateHandle = AssetEditorSubsystem->OnAssetOpenedInEditor().AddRaw(this, &FBlueprintAssistModule::OnAssetOpenedInEditor);
#endif
}

void FBlueprintAssistModule::UnbindAssetOpenedDelegate()
{
	if (OnAssetOpenedDelegateHandle.IsValid())
	{
#if ENGINE_MINOR_VERSION < 24
		FAssetEditorManager::Get().OnAssetOpenedInEditor().Remove(OnAssetOpenedDelegateHandle);
#else
		if (GEditor != nullptr)
		{
			if (UAssetEditorSubsystem* AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>())
			{
				AssetEditorSubsystem->OnAssetOpenedInEditor().Remove(OnAssetOpenedDelegateHandle);
			}
		}
#endif
		OnAssetOpenedDelegateHandle.Reset();
	}
}

void FBlueprintAssistModule::OnAssetOpenedInEditor(UObject* Asset, IAssetEditorInstance* AssetEditor)
{
	//UE_LOG(LogTemp, Warning, TEXT("Asset opened in editor %s"), *Instance->GetEditorName().ToString());

	FAssetEditorToolkit* AssetEditorToolkit = StaticCast<FAssetEditorToolkit*>(AssetEditor);
	TSharedRef<FUICommandList> ToolkitCommands = AssetEditorToolkit->GetToolkitCommands();

	if (ToolbarExtender.IsValid())
	{
		AssetEditorToolkit->RemoveToolbarExtender(ToolbarExtender);
		ToolbarExtender.Reset();
	}

	ToolbarExtender = MakeShareable(new FExtender);
	
	ToolbarExtender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		ToolkitCommands,
		FToolBarExtensionDelegate::CreateRaw(&ToolbarMenu, &FBAToolbar::ExtendToolbar)
	);

	AssetEditorToolkit->AddToolbarExtender(ToolbarExtender);
}

#undef LOCTEXT_NAMESPACE
