// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward decleration
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
protected:

	// How far can AI Tank can get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float acceptanceRadius = 8000;

private:
	APawn* playerTank;

	APawn* possessedTank;

	UTankAimingComponent* aimingComponent = nullptr;

	virtual void SetPawn(APawn* inPawn) override;
	
	UFUNCTION()
		void OnPossessedTankDeath();
};
