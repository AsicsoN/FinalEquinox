

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

	virtual void Tick(float DeltatTime) override;

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

	FRotator Rotation;
	bool bRotate = false;

	// Timer Handles
	FTimerHandle AiTurnInfoHandle;
	FTimerHandle AiMoveCycleHandle;
	FTimerHandle AiAttackCycleHandle;
	FTimerHandle AiSwapCycleHandle;
};
