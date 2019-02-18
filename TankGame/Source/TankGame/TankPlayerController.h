// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"   //Must be the last include

/**
 * 
 */

class ATank;
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

private:
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so the shot will hit 
	//where the crosshair intersects the world
	void AimTowardsCrosshair(); 

	//Return an OUT parameter
	//true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairX = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairY = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
