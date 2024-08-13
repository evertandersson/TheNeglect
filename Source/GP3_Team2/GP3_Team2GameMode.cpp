// Copyright Epic Games, Inc. All Rights Reserved.

#include "GP3_Team2GameMode.h"
#include "GP3_Team2Character.h"
#include "UObject/ConstructorHelpers.h"

AGP3_Team2GameMode::AGP3_Team2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
