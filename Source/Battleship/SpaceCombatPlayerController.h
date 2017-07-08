#pragma once

#include "GameFramework/PlayerController.h"
#include "ShipPawnBase.h"
#include "SpaceCombatPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToFire = false;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool LeftTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool RightTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Forward();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Fire(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool PrepareToFire();
	
};
