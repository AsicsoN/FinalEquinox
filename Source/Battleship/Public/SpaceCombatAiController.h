

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SpaceCombatAiController.generated.h"

class AShipPawnBase;
class ASpaceCombatGameMode;

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	void InitializeAI(const TArray<AShipPawnBase*> AiShips, ASpaceCombatGameMode* NewGameMode);

	void BeginAiTurn();

protected:
	void AiLogicLoop();

	void SelectTarget();

	bool MoveShip();

	void AttackPlayer();

	void SwapShip();

private:



	// Enemy Ships
	TArray<AShipPawnBase*> EnemyShips;

	// Target Ship
	AShipPawnBase* Target = nullptr;

	// GameMode
	ASpaceCombatGameMode* GameMode = nullptr;

	// Timer Handles
	FTimerHandle AiTurnCycleHandle;
	FTimerHandle AiAttackCycleHandle;
	FTimerHandle AiSwapCycleHandle;
};
