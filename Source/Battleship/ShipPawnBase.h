#pragma once

#include "GameFramework/Character.h"
#include "Crew.h"
#include "ShipPawnBase.generated.h"

UENUM(BlueprintType)
enum class EFaction : uint8
{
	Player UMETA(DisplayName = "Player"),
	Enemy1 UMETA(DisplayName = "Enemy1")
};

UENUM(BlueprintType)
enum class EType : uint8
{
	None UMETA(DisplayName = "None"),
	Small UMETA(DisplayName = "Small"),
	Medium UMETA(DisplayName = "Medium"),
	Large UMETA(DisplayName = "Large")
};

UCLASS()
class BATTLESHIP_API AShipPawnBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipPawnBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EFaction Faction = EFaction::Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EType Type = EType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	UTexture2D* Thumbnail;
	
	//
	// Ship Stats
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	int32 Speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	int32 PowerLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	int32 Initiative = -1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Leadership = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Tactics = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Communication = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Navigation = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Gunnery = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float Science = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float ShieldRepair = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float HullRepair = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	float SubsystemRepair = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship Stats")
	int32 FighterSkill = 0;


	//
	// Ship Inventory
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 ActionPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 CurrentActionPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 MovementPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 CurrentMovementPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 HitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 CurrentHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 ShieldHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 CurrentShieldHitPoints = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 MaxMissiles = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 Missiles = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	int32 Fighters = -1;

	

	//
	// Rotation Variables
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FRotator StartRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FRotator NewRotation;

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
	virtual void Instantiate();

	UFUNCTION(BlueprintCallable, Category = "Game State")
	bool IsTurnOver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State")
	bool ForceTurnEnd = false;
};
