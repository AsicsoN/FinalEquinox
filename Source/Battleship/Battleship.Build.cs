// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Battleship : ModuleRules
{
	public Battleship(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "UMG", "ApexDestruction" });

        PrivateDependencyModuleNames.AddRange(new string[] {  });
        
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        PrivateDependencyModuleNames.Add("NavigationSystem");

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
