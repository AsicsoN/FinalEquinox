// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class DialoguePluginEditor : ModuleRules
	{
        public DialoguePluginEditor(ReadOnlyTargetRules Target) : base(Target)
        {
			PrivateIncludePaths.Add("DialoguePluginEditor/Private");
			
            PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
                    "EditorStyle",
					"Engine",
                    "InputCore",
					"LevelEditor",
					"Slate",
                    "AssetTools",
                    "KismetWidgets",
                    "WorkspaceMenuStructure",
                    "Projects",
                    "GraphEditor",
                    "AnimGraph"
                }
			);

            PrivateDependencyModuleNames.AddRange(
				new string[]
				{					
					"PropertyEditor",
					"SlateCore",
					"UnrealEd",
					"DialoguePlugin"
				}
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[] 
				{
					"MainFrame",
					"Settings"
				}
			);

			PrivateIncludePathModuleNames.AddRange(
				new string[] 
				{
					"MainFrame",
					"Settings"
				}
			);

			
		}
	}
}