#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceCombatCameraBase.generated.h"

class AShipPawnBase;

UCLASS()
class BATTLESHIP_API ASpaceCombatCameraBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceCombatCameraBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Camera")
	void StartFollowingShip(AShipPawnBase* TargetShip);
	virtual void StartFollowingShip_Implementation(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Camera")
	void StopFollowingShip();
	virtual void StopFollowingShip_Implementation();
	
};
