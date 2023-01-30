
using UnrealBuildTool;

public class LoadingScreen : ModuleRules
{
    public LoadingScreen(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "HeadMountedDisplay",
            "LoadingScreen",
            "MoviePlayer",
            "Slate",
            "SlateCore",
        });
    }
}
