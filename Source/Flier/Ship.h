// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Ship.generated.h"

UCLASS()
class FLIER_API AShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Updates the ship position
	/*virtual void UpdateShipPosition();

	// Sets position
	virtual void SetShipPosition(FVector Pos);

	*/
	// ID
	int ID;

	// Position of the ship
	FVector ShipPosition;

	// Hit points left
	int HP;
};
