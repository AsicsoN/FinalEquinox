

#pragma once

#include "Object.h"
#include "Race.h"
#include "Crew.generated.h"

USTRUCT(BlueprintType)
struct BATTLESHIP_API FCrewMorale {
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	int32 General = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morale")
	int32 Fear = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morale")
	int32 Respect = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Morale")
	int32 Love = 0;
};

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UCrew : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool IsLocked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString CrewName = "Player";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ERace CrewRace = ERace::Human;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool IsMale = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	UTexture2D* Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool CanDie = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Leadership = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Navigation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Communication = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Gunnery = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Engineering = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Science = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Tactics = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 SubsystemRepair = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 ShieldRepair = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	int32 Level = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	int32 ExperiencePoints = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FCrewMorale Morale;

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentMorale();

	UFUNCTION(BlueprintCallable)
	FString GetMoraleDescriptor(int32 MoraleLevel);
};
