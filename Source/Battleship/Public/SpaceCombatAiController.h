

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SpaceCombatAiController.generated.h"

class AShipPawnBase;
class ASpaceCombatGameMode;
class ATile;

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	void InitializeAI(ASpaceCombatGameMode* NewGameMode);

	void BeginAiTurn();

protected:
	void GenerateTurnInformation();

	void SelectTarget();

	void CalculateTravelPoint();

	void MoveShip();

	void AttackPlayer();

	void SwapShip();

private:
	// Target Ship
	AShipPawnBase* Target = nullptr;

	// GameMode
	ASpaceCombatGameMode* GameMode = nullptr;

	// Target Tile
	ATile* TargetTile = nullptr;

	// Timer Handles
	FTimerHandle AiMoveCycleHandle;
	FTimerHandle AiAttackCycleHandle;
	FTimerHandle AiSwapCycleHandle;
};