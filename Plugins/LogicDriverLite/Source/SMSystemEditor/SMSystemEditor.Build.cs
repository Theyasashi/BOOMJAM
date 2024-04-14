// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class SMSystemEditor : ModuleRules
{
    public SMSystemEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        DefaultBuildSettings = BuildSettingsVersion.V2;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUsePrecompiled = true;

        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Public")
				// ... add public include paths required here ...
			});

        
        PrivateIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Private")
				// ... add other private include paths required here ...
			});

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "SMSystem",
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
				// Core modules
				"Engine",
                "CoreUObject",
                "Projects",
				"UnrealEd", 
				"RenderCore",
                "InputCore",
                "SlateCore",
                "Slate",
                "EditorStyle",
                "EditorWidgets",
                "ToolMenus",
                "AssetTools",
                "GameplayTags",

                "WorkspaceMenuStructure",
				"DetailCustomizations",
                "PropertyEditor",

				"BlueprintGraph",
                "Kismet",
                "KismetCompiler",
                "KismetWidgets",
                
				"GraphEditor",
                "ContentBrowser",
                
				"ApplicationCore"
            }
            );

        PrivateIncludePathModuleNames.AddRange(
        new string[] {
                    "AssetRegistry",
                    "AssetTools",
                    "BlueprintGraph",
                    "Kismet",
                    "KismetCompiler",
                    "KismetWidgets",
                    "EditorWidgets",
                    "ContentBrowser",
        });

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
