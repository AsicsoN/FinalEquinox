

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Leadership = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Piloting = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Gunnery = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Mechanics = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int32 Hacking = 0;	
};
