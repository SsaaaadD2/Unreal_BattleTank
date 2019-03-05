// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"   //so we can implement OnDeath

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our method to our tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}

}

void ATankAIController::OnPossessedTankDeath()
{
	if (!(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
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

		//if aiming or locked, then fire
		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire();  //TODO: Fix firing
		}
	}
}
