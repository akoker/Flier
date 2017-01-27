// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "FlierGameMode.generated.h"

UCLASS(minimalapi)
class AFlierGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AFlierGameMode();
	TArray<class AShip*> ShipArray;
	void InitiateShipArray();
};



