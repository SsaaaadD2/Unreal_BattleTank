// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	if (ensure(PlayerTank && GetPawn()))
	{
		//TODO Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);


		FVector HitLocation = PlayerTank->GetActorLocation();

		AimingComponent->AimAt(HitLocation);

		//AimingComponent->Fire();  //TODO: Fix firing
	}
}
