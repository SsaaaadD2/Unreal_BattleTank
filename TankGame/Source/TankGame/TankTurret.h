// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is min, +1 is max
	void Rotate(float RelativeSpeed);
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 25;
};
