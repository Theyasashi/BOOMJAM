// Copyright 2020 fpwong, Inc. All Rights Reserved.

using UnrealBuildTool;

using System.IO; // Note this import, it's needed below

public class BlueprintAssist : ModuleRules
{
    public BlueprintAssist(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bUsePrecompiled = true;
        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
            }
            );

        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
            }
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
				// ... add other public dependencies that you statically link with here ...
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...
                "GraphEditor",
                "Kismet",
                "KismetWidgets",
                "InputCore",
                "BlueprintGraph",
                "AssetTools",
                "EditorStyle",
                "EditorWidgets",
                "UnrealEd",
                "MaterialEditor",
                "BehaviorTreeEditor",
                "AIGraph",
                "AudioEditor",
                "Projects",
                "Json",
                "JsonUtilities",
                "EngineSettings",
                "AssetRegistry",
                "AnimGraph"
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
