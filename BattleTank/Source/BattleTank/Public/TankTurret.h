// Copyright David Radobenko

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float relativeSpeed);
	
private:
	// Set's throttle between -1 and +1
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float maxDegreesPerSecond = 25;
	
};
