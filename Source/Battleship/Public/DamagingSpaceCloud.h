#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceObject.h"
#include "ShipPawnBase.h"
#include "DamagingSpaceCloud.generated.h"

UCLASS()
class BATTLESHIP_API ADamagingSpaceCloud : public ASpaceObject
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADamagingSpaceCloud();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool TriggerDamageEffect(AShipPawnBase* Ship);
	
};
