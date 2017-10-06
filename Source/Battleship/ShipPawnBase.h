#pragma once

#include "GameFramework/Pawn.h"
#include "Crew.h"
#include "ShipPawnBase.generated.h"

UENUM(BlueprintType)
enum class EFaction : uint8
{
	Player UMETA(DisplayName = "Player"),
	Enemy1 UMETA(DisplayName = "Enemy1")
};

UCLASS()
class BATTLESHIP_API AShipPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawnBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFaction Faction = EFaction::Player;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ShieldHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentShieldHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxMissiles = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Missiles = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ForceTurnEnd = false;

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

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actions")
	int32 CalculateLaserDamage(bool CriticalHit);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actions")
	int32 CalculateMissileDamage(bool CriticalHit);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TurnSequence")
	bool ShowThisShipActive();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TurnSequence")
	bool ShowThisShipInactive();

	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	void Instantiate(int32 Tactics);

	UFUNCTION(BlueprintCallable, Category = "Game State")
	bool IsTurnOver();
};
