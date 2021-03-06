// Copyright David Radobenko

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward decleration
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
protected:
	APawn* controlledTank = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* aimCompRef);

private:

	UPROPERTY(EditDefaultsOnly)
		float crossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
		float crossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
		float lineTraceRange = 1000000; //10km

	UTankAimingComponent* aimingComponent = nullptr;

	// Moves the Tank barrel to the Aimed destination
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& outHitLocation) const;

	bool GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;

	virtual void SetPawn(APawn* inPawn) override;

	UFUNCTION()
		void OnControlledTankDeath();
};
