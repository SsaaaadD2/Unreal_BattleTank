// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank == NULL){
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found by TankAIController"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player tank, player: %s"), *PlayerTank->GetName())
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetControlledTank()) { return; }

	if (GetPlayerTank())
	{
		//TODO Move towards player
		FVector HitLocation = GetPlayerTank()->GetActorLocation();

		GetControlledTank()->AimAt(HitLocation);
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn == NULL) { return nullptr; }
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}