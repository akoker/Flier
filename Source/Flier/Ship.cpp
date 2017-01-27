// Fill out your copyright notice in the Description page of Project Settings.

#include "Flier.h"
#include "Ship.h"
#include <iostream>

using namespace std;

// Sets default values
AShip::AShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Set the ship ID
	//AShip::ID = ShipID;
	USphereComponent* ShipSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = ShipSphere;

	ShipSphere->InitSphereRadius(40.0f);
	ShipSphere->SetCollisionProfileName(TEXT("Ship"));

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->AttachTo(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}


	//UE_LOG(LogTemp, Warning, TEXT("ship is added to the scene"));
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShip::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


}