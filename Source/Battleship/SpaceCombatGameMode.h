#pragma once

#include "GameFramework/GameMode.h"
#include "ShipPawnBase.h"
#include "GridController.h"
#include "SpaceCombatGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	ASpaceCombatGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;	
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void EndCombat();

private:
	AGridController* GridController = nullptr;
	TArray<AShipPawnBase*> ShipArray;

	inline static bool SortShipPawnBase(const AShipPawnBase& ship1, const AShipPawnBase& ship2)
	{
		return (ship1.Initiative > ship2.Initiative);
	}

};
