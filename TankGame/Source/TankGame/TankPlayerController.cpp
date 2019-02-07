// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank != NULL){
		UE_LOG(LogTemp, Warning, TEXT("Player controller possessing: %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank not found by PlayerController"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());

}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank){ return;  }

	//Get world position of linetrace through crosshair
	//if it hits the landscape
		//Controlled tank aims towards this point
}