// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "FlierHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLIER_API AFlierHUD : public AHUD
{
	GENERATED_BODY()
public:
	AFlierHUD();
	void UpdateHUD();
	void DrawRadar();
	virtual void DrawHUD() OVERRIDE;
	int Radius;
	float RadInc;
	FVector2D RadarCenter;
	int DotSize;
	int ReachLimit;
	int ScaleRatio;
};
