// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class DialoguePlugin : ModuleRules
	{
        public DialoguePlugin(TargetInfo Target)
		{
            PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
                  	"Engine",
                    "SlateCore"
                }
			);
			
		}
	}
}