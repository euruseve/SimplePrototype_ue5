// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimplePrototypeGameMode.h"
#include "SimplePrototypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimplePrototypeGameMode::ASimplePrototypeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
