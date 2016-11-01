

#pragma once

#include "GameFramework/Pawn.h"
#include "ShipPawnBase.generated.h"

UCLASS()
class BATTLESHIP_API AShipPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawnBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Initiative = -1;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
