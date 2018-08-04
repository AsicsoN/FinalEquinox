using UnrealBuildTool;

public class RichText : ModuleRules
{
    public RichText(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        /*PublicIncludePaths.AddRange(
            new string[] {
                "RichText/Public"
            }
        );*/

        PrivateIncludePaths.AddRange(
            new string[] {
                "RichText/Private",
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UMG"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(new string[]{});
    }
}
