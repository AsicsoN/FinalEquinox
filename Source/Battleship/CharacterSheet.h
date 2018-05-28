
#pragma once

#include "Object.h"
#include "Race.h"
#include "Crew.h"
#include "CharacterSheet.generated.h"

UENUM(BlueprintType)
enum class ECharacterBackground : uint8
{
	Noble UMETA(DisplayName = "Noble"),
	Outerworlds UMETA(DisplayName = "Outerworlds"),
	Innerworlds UMETA(DisplayName = "Innerworlds"),
	Military UMETA(DisplayName = "Military"),
	Trader UMETA(DisplayName = "Trader")
};

class APlayerShipPawnBase;
class UStardate;
class UPlayerCrewObject;

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UCharacterSheet : public UObject
{
	GENERATED_BODY()
	
public:
	UCharacterSheet();

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void SetDefaultFleet(TSubclassOf<APlayerShipPawnBase> BattleshipPawnClass, TSubclassOf<APlayerShipPawnBase> DestroyerPawnClass);

	UFUNCTION(BlueprintCallable, Category = "Options")
	void SetCharacterOption(FString option);

	UFUNCTION(BlueprintCallable, Category = "Options")
	bool GetCharacterOption(FString option);

	UFUNCTION(BlueprintCallable, Category = "Information")
	FString GetVariableValue(FString variableName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString Name = "Player";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ERace Race = ERace::Human;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ECharacterBackground Background = ECharacterBackground::Outerworlds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool GenderIsMale = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fleet")
	TArray<APlayerShipPawnBase*> Fleet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting")
	int32 Brawling = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting")
	int32 EnergyWeapons = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting")
	int32 BladeWeapons = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting")
	int32 ProjectileWeapons = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighting")
	int32 Gunnery = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quickness")
	int32 Pilot = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quickness")
	int32 Sneak = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quickness")
	int32 Acrobatics = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Knowledge")
	int32 Culture = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Knowledge")
	int32 Science = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Knowledge")
	int32 Medicine = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Knowledge")
	int32 Explosives = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "World Knowledge")
	int32 Language = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Knowledge")
	int32 Mechanics = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Knowledge")
	int32 Tactics = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Knowledge")
	int32 Engineering = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Knowledge")
	int32 Navigation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Knowledge")
	int32 Hacking = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charisma")
	int32 Barter = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charisma")
	int32 Deception = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charisma")
	int32 Persuasion = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charisma")
	int32 Leadership = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charisma")
	int32 Intimidate = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue Choices")
	bool AskedAboutEdward = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	TArray<UCrew*> UnusedCrew;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	UStardate* Stardate = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	int32 Supplies = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sentana")
	bool SentanaTutorialCompleted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Repair")
	int32 ShieldRepair = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Repair")
	int32 SubsystemRepair = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	UPlayerCrewObject* PlayerCrewObject = nullptr;

};
