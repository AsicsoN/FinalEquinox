

#pragma once

#include "Object.h"
#include "Race.h"
#include "Crew.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UCrew : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString CrewName = "Player";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	ERace CrewRace = ERace::Human;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	bool IsMale = true;
	
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
};
