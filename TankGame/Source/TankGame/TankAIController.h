// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 8000; //How close can the AI tank get to the player
	
};
