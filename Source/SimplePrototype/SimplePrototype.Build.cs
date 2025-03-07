// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SimplePrototype : ModuleRules
{
	public SimplePrototype(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput"
		});

		PublicIncludePaths.AddRange(new string[]
		{
			"SimplePrototype/Public"
		});
	}
}
