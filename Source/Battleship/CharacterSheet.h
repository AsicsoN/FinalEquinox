

#pragma once

#include "Object.h"
#include "CharacterSheet.generated.h"

UENUM(BlueprintType)
enum class ERace : uint8
{
	Human UMETA(DisplayName = "Human"),
	Malderian UMETA(DisplayName = "Malderian"),
	Krum UMETA(DisplayName = "Krum")
};

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UCharacterSheet : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString PlayerName = "Player";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ERace PlayerRace = ERace::Human;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool GenderIsMale = true;

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

};
