// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards the player
		// TODO aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		
		// TODO Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		//UE_LOG(LogTemp, Warning, TEXT("No PlayerPawn found"));
		return nullptr;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController found: %s"), *(PlayerPawn->GetName()));
		return Cast<ATank>(PlayerPawn);
	}
}