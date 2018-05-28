#pragma once

#include "GameFramework/Character.h"
#include "Components/AudioComponent.h"
#include "Crew.h"
#include "Ability.h"
#include "DestructibleComponent.h"
#include "DestructibleMesh.h"
#include "ShipPawnBase.generated.h"

class UShipInfoBaseWidget;

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


USTRUCT(BlueprintType)
struct BATTLESHIP_API FSubsystems {

	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Engine")
	float Engine = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Guns")
	float Guns = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShieldGen")
	float ShieldGen = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanners")
	float Scanners = 1.0f;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDestructibleComponent* Destructible;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
	FSubsystems Subsystems;


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	bool bScanned = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "System Stats")
	TArray<AShipPawnBase*> ScannedShips;	

	//
	// Rotation Variables
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FRotator StartRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FRotator NewRotation;

	//
	// Abilities and Effects
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<FAbilityStruct> Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSet<AAbility*> Buffs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSet<AAbility*> Debuffs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	float AttackBonus;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	float HitBonus;

	UFUNCTION(BlueprintCallable)
	void CheckExpiryBuffs();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	int32 CalculateLaserDamage(bool CriticalHit);

	UFUNCTION(BlueprintCallable, Category = "Actions")
	int32 CalculateMissileDamage(bool CriticalHit);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Actions")
	void FireVFX(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TurnSequence")
	bool ShowThisShipActive();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TurnSequence")
	bool ShowThisShipInactive();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TurnSequence")
	void ChangeCollision(bool bIsAiTurn);

	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	virtual void Instantiate();

	UFUNCTION(BlueprintCallable)
	void Rotate(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void CalculateFinalRotation(FVector Destination);

	UFUNCTION(BlueprintCallable, Category = "Game State")
	bool IsTurnOver();

	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ShipDestroyed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	bool bAdjustRotation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State")
	bool ForceTurnEnd = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserInterface")
	UShipInfoBaseWidget* ShipInfoWidget = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actions")
	UAudioComponent* MovementSound = nullptr;
};
