// Fill out your copyright notice in the Description page of Project Settings.

#include "Flier.h"
#include "FlierHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "FlierPawn.h"
#include "FlierGameMode.h"
#include "Ship.h"

AFlierHUD::AFlierHUD(){
	ReachLimit = 4000;
	ScaleRatio = 40;
	Radius = 100;
	RadInc = 0.1;
	RadarCenter = FVector2D(100, 100);
	DotSize = 5;
}

void AFlierHUD::DrawHUD(){

	FVector2D dim = FVector2D(Canvas->SizeX, Canvas->SizeY);
	
	Super::DrawHUD();

	AFlierPawn* pawn = Cast<AFlierPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	AFlierGameMode* mode = Cast<AFlierGameMode>(UGameplayStatics::GetGameMode(this));

	DrawRadar();

	for (AShip *ship : mode->ShipArray){

		float Dist = FVector2D::Distance(FVector2D(ship->GetActorLocation()), FVector2D(pawn->GetActorLocation()));
		
		if (Dist <= ReachLimit){
			FVector localPos = pawn->GetTransform().InverseTransformPosition(ship->GetActorLocation());


			localPos = FRotator(0.f, 90.f, 0.f).RotateVector(localPos);

			localPos /= ScaleRatio;

			DrawRect(FLinearColor::Red, RadarCenter.X - localPos.X, RadarCenter.Y - localPos.Y, DotSize, DotSize);
		}
	}
}

void AFlierHUD::DrawRadar()
{

	for (float i = 0; i < 360; i += RadInc)
	{
		float fixedX = FMath::Cos(i) * Radius;
		float fixedY = FMath::Sin(i) * Radius;

		FLinearColor hudBG = FLinearColor::White;

		//Draw Radar
		DrawLine(RadarCenter.X, RadarCenter.Y, RadarCenter.X + fixedX, RadarCenter.Y + fixedY, hudBG);

		//Draw PivotDot
		DrawRect(FLinearColor::Blue, RadarCenter.X - DotSize / 2, RadarCenter.X - DotSize / 2, DotSize, DotSize);
	}
}