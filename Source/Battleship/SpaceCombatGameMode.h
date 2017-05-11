#pragma once

#include "GameFramework/GameMode.h"
#include "ShipPawnBase.h"
#include "GridController.h"
#include "Crew.h"
#include "SpawnLocation.h"
#include "SpaceCombatGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	AShipPawnBase* SelectedShip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool bIsCombatEnded = false;

	ASpaceCombatGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;	
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void EndCombat(bool PlayerWon);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool DidPlayerWin();

	//UFUNCTION(BlueprintCallable, Category = "Gameplay")
	//void SelectShip(AShipPawnBase* Ship);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SortShipPawnArrayByInitiative(TArray<AShipPawnBase*> PawnArrayIn);

	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	UCrew* GenerateRandomCrewMember();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Instantiation")
	bool SpawnShips();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool SelectPawn(AShipPawnBase* Pawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Forward();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool LeftTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool RightTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool DestroyPawn(AShipPawnBase* Pawn);

private:
	bool bDidPlayerWin = false;

	AGridController* GridController = nullptr;
	TArray<AShipPawnBase*> ShipArray;

	inline static bool SortShipPawnBase(const AShipPawnBase& ship1, const AShipPawnBase& ship2)
	{
		return (ship1.Initiative > ship2.Initiative);
	}

};
