#pragma once

#include "CoreMinimal.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API APlayerShipPawnBase : public AShipPawnBase
{
	GENERATED_BODY()
	
public:

	//
	// Crew Objects
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* Captain = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* NavigationOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* TacticsOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* ScienceOfficer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* Engineer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crew")
	UCrew* CAG = nullptr;
	
	UFUNCTION(BlueprintCallable, Category = "Instantiation")
	virtual void Instantiate() override;
	
};
