#pragma once

#include "GameFramework/PlayerController.h"
#include "SpaceCombatPlayerController.generated.h"

class ATile;

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
	bool bFireModeIsLasers = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bMoving = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bAdjustFinalRotation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	ATile* Tile = nullptr;

	/***
	* Gameplay Functions
	*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool LaunchFighters(TSubclassOf<AShipPawnBase> FighterBlueprint);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool CollectFighter();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool LeftTurn();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool RightTurn();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool Fire(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool PrepareToFire(bool FiringLasers);

	/***
	* Utility Functions
	*/
	UFUNCTION(BlueprintCallable, Category = "Utility")
	bool GetFinalRotation();

	UFUNCTION(BlueprintCallable, Category = "Utility")
	bool RotatePawn(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Utility")
	bool IsColliding();

	UFUNCTION(BlueprintCallable, Category = "Utility")
	void ResetShip();

	UFUNCTION(BlueprintCallable, Category = "Utility")
	void SaveShipLocale();

protected:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:
	float MouseX = 0.0f;

	FVector OrigForward;
};
