

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

class UTexture2D;
class UAnimMontage;
class AShipPawnBase;

UENUM(BlueprintType)
enum class EAbilityType : uint8
{
	NONE UMETA(DisplayName = "None"),
	BUFF UMETA(DisplayName = "Buff"),
	DEBUFF UMETA(DisplayName = "Debuff"),
};

UENUM(BlueprintType)
enum class EBuffType : uint8
{
	NONE UMETA(DisplayName = "None"),
	STAT UMETA(DisplayName = "Stat"),
	SKILL UMETA(DisplayName = "Skill"),
};

UENUM(BlueprintType)
enum class EAbilitySkill : uint8
{
	NONE UMETA(DisplayName = "None"),
	TACTICS UMETA(DisplayName = "Tactics"),
	NAVIGATION UMETA(DisplayName = "Navigation"),
	SCIENCE UMETA(DisplayName = "Science"),
	ENGINEERING UMETA(DisplayName = "Engineering"),
	LEADERSHIP UMETA(DisplayName = "Leadership"),
	HIT UMETA(DisplayName = "Hit Chance"),
};

UENUM(BlueprintType)
enum class EAbilityStat : uint8
{
	NONE UMETA(DisplayName = "None"),
	HEALTH UMETA(DisplayName = "Hit Points"),
	SHIELDS UMETA(DisplayName = "Shields"),
	SPEED UMETA(DisplayName = "Speed"),
	ATTACK UMETA(DisplayName = "Attack"),
};

USTRUCT(BlueprintType)
struct BATTLESHIP_API FAbilityStruct
{
	GENERATED_BODY();

	FAbilityStruct();

	/***
	* Ability Description
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	EAbilityType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	UAnimMontage* Animation;

	/***
	* Ability Mechanic Values
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	EBuffType BuffType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	EAbilitySkill AffectedSkill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	EAbilityStat AffectedStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	int ActionCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	float Power;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	TMap<EAbilitySkill, int> SkillRequirements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	bool bIsTargeted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	bool bAffectsAll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mechanic")
	int NumberTurns = 1;

	/***
	* Ability Variables
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	int AffectedDistance = 0;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Physics","Rendering", "Replication", "Actor", "Replication", "Input", "HLOD", "Actor Tick"))
class BATTLESHIP_API AAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbility();

	UFUNCTION(BlueprintCallable)
	void Execute(AShipPawnBase* TargetShip = nullptr);

	void TickAbility();
	
	void Cleanup(AShipPawnBase* Ship);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TargettedAbility(AShipPawnBase* TargetShip);
	void AoeAbility();
	void SelfAbility();

	void BoostStats(AShipPawnBase* Ship);
	void ReduceStats(AShipPawnBase* Ship);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Description")
	FAbilityStruct Info;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Description")
	TMap<AShipPawnBase*, float> AffectedValues;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
	TSet<AShipPawnBase*> AffectedShips;
};
