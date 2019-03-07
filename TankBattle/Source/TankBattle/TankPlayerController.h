// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // this must be the last include

/**
 *
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// properties
	
	// Returns an OUT parameter, true if it hits landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5F;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333F;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0F; // 10km in cm

private:
	// methods
	ATank* GetControlledTank() const;
	
	void AimTowardsCrosshair();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// const -> not going to change member variables of class
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const; 

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
