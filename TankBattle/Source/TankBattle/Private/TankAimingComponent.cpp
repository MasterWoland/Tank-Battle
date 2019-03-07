// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

UTankAimingComponent::UTankAimingComponent()
{
	bWantsBeginPlay = true; // is this necessary?
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	//UE_LOG(LogTemp, Warning, TEXT("TANK AIMING COMPONENT: Set Barrel Reference %s"), *BarrelToSet->GetReadableName());

	if (BarrelToSet == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TANK AIMING COMPONENT: Barrel Reference is nullptr"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TANK AIMING COMPONENT: Barrel Reference is NOT nullptr"));

		// This line of code will cause the UE Editor to crash: 
		//Barrel = BarrelToSet; 
	}

	//UE_LOG(LogTemp, Warning, TEXT("TANK AIMING COMPONENT: Set Barrel Reference: %s"), *Barrel->GetName());
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	// will crash if code below is being used

	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
}


