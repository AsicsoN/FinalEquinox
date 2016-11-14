

#pragma once

#include "Object.h"
#include "ShipPawnBase.h"
#include "Crew.h"
#include "Ship.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UShip : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Information")
	TSubclassOf<class AShipPawnBase> PawnClass;

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
	
	
};
