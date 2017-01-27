// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Flier.h"
#include "FlierGameMode.h"
#include "FlierPawn.h"
#include "Ship.h"
#include "FlierHUD.h"

AFlierGameMode::AFlierGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AFlierPawn::StaticClass();
	HUDClass = (UClass*)AFlierHUD::StaticClass();
	InitiateShipArray();
}

void AFlierGameMode::InitiateShipArray(){
	TObjectIterator<AShip> Itr;

	for (Itr; Itr; ++Itr)
	{
		// Filter out objects not contained in the target world.
		if (Itr->GetName().Contains("Ship") && Itr->GetWorld() == GetWorld()){
			ShipArray.Add(*Itr);
		}
	}
}