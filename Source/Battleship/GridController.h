#pragma once

#include "GameFramework/Actor.h"
#include "GridLocation.h"
#include "ShipPawnBase.h"
#include "GridController.generated.h"

struct gridLocation {
	int x, y;
	EGLRotation rotation;
};

UCLASS(Blueprintable)
class BATTLESHIP_API AGridController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGridController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SizeX = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SizeY = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Multiplier = 200;

	int32 GetSquareId(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Squares")
	bool IsSquareOccupied(AShipPawnBase* ship, int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Squares")
	bool IsSquareOutOfBounds(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Squares")
	int32 ConvertPositionToSquareId(FVector position);

	UFUNCTION(BlueprintCallable, Category = "Squares")
	bool IsPositionValid(AShipPawnBase* ship, int32 x, int32 y, int32 width, int32 length, EGLRotation rotation);

	UFUNCTION(BlueprintCallable, Category = "Squares")
	FVector ConvertSquareIdToPosition(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Move(AShipPawnBase* ship, int32 direction);	

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool CanRotateClockwise(AShipPawnBase* ship);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void RotateClockwise(AShipPawnBase* ship);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool CanRotateCounterClockwise(AShipPawnBase* ship);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void RotateCounterClockwise(AShipPawnBase* ship);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool CanMoveForward(AShipPawnBase* ship);

private:
	gridLocation CalculateClockwiseRotation(AShipPawnBase* ship);
	
	gridLocation CalculateCounterClockwiseRotation(AShipPawnBase* ship);

};
