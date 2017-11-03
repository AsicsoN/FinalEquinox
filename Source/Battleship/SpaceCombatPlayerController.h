#pragma once

#include "GameFramework/PlayerController.h"
#include "ShipPawnBase.h"
#include "Tile.h"
#include "SpaceCombatPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASpaceCombatPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToFire = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToMove = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bMoving = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	ATile* Tile = nullptr;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool LeftTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool RightTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Forward();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Fire(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool PrepareToFire(bool FiringLasers);
	
};
