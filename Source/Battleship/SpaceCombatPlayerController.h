#pragma once

#include "GameFramework/PlayerController.h"
#include "SpaceCombatPlayerController.generated.h"

class ATile;
class AAbility;

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
	bool bFireAtSubsystems = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bFireAtScanners = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bFireAtGuns = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bFireAtEngines = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bFireAtShields = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bPreparingToScan = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bMoving = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bAdjustFinalRotation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	ATile* Tile = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool bUseAbility = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	AAbility* Ability = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class USplineComponent* PathSpline;

	UPROPERTY(EditAnywhere)
	class UStaticMesh* LineMesh = nullptr;

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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay")
	bool Fire(AShipPawnBase* TargetShip);
	virtual bool Fire_Implementation(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool PrepareToFire(bool FiringLasers, bool FireSubsystems = false);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Gameplay")
	bool ScanShip(AShipPawnBase* TargetShip);
	virtual bool ScanShip_Implementation(AShipPawnBase* TargetShip);

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
