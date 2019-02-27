// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank && ControlledTank))
	{
		//TODO Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);


		FVector HitLocation = PlayerTank->GetActorLocation();

		ControlledTank->AimAt(HitLocation);

		ControlledTank->Fire();  //TODO: Don't fire every frame; limit firing rate
	}
}
