#pragma once

#include "GameFramework/Pawn.h"
#include "Crew.h"
#include "ShipPawnBase.generated.h"

UCLASS()
class BATTLESHIP_API AShipPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawnBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 PowerLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Initiative = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ActionPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentActionPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MovementPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentMovementPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* Captain = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* NavigationOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* WeaponsOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* ScienceOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* Engineer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* CAG = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	TArray<UCrew*> Passengers;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actions")
	bool Fire(AShipPawnBase* EnemyShip);
	
	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	void CalculateActionPoints(int32 Tactics);

	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	void Instantiate(int32 Tactics);
};
