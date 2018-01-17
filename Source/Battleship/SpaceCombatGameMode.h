#pragma once

#include "GameFramework/GameMode.h"
#include "ShipPawnBase.h"
#include "GridController.h"
#include "Crew.h"
#include "SpawnLocation.h"
#include "SpaceCombatGameMode.generated.h"

class ASpaceCombatAiController;

UENUM(BlueprintType)
enum class ESpaceCombatPhase : uint8
{
	Intro UMETA(DisplayName = "Intro"),
	PreCombat UMETA(DisplayName = "Pre-combat"),
	Combat UMETA(DisplayName = "Combat"),
	Outro UMETA(DisplayName = "Outro")
};

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ASpaceCombatGameMode : public AGameMode
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatLogDelegate, FText, Message);
	
public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCombatLogDelegate OnCombatEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	AShipPawnBase* SelectedShip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool bIsCombatEnded = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	ESpaceCombatPhase Phase = ESpaceCombatPhase::Intro;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	TArray<AShipPawnBase*> ShipArray;

	ASpaceCombatGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;	
	
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void EndCombat(bool PlayerWon);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool DidPlayerWin();

	//UFUNCTION(BlueprintCallable, Category = "Gameplay")
	//void SelectShip(AShipPawnBase* Ship);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SortShipPawnArrayByInitiative(TArray<AShipPawnBase*> PawnArrayIn);

	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	UCrew* GenerateRandomCrewMember();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void WriteToCombatLog(FText message);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	float CalculateHitChance(AShipPawnBase* TargetShip);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	float CalculateDistance(AShipPawnBase* Ship1, AShipPawnBase* Ship2);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Instantiation")
	bool SpawnShips();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool SelectPawn(AShipPawnBase* Pawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool Forward();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool LeftTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool RightTurn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Gameplay")
	bool DestroyPawn(AShipPawnBase* Pawn);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void RepairShip(AShipPawnBase* Ship, FString Type);

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	AGridController* GetGridController();

	UFUNCTION(BlueprintCallable, Category = "Turn Management")
	void StartAiTurn();

private:
	bool bDidPlayerWin = false;

	AGridController* GridController = nullptr;

	ASpaceCombatAiController* AiController = nullptr;

	inline static bool SortShipPawnBase(const AShipPawnBase& ship1, const AShipPawnBase& ship2)
	{
		return (ship1.Initiative > ship2.Initiative);
	}

};
