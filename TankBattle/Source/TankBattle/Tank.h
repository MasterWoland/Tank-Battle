// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Tank.generated.h"

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

public:	
	// functions
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup") 
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	// properties
	UPROPERTY(VisibleDefaultsOnly)
	class UTankAimingComponent* TankAimingComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
