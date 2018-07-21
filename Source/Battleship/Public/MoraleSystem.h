

#pragma once

#include "CoreMinimal.h"

class UCrew;
class APlayerShipPawnBase;

UENUM(BlueprintType)
enum class EMoraleType : uint8
{
	NONE UMETA(DisplayName = "None"),
	GENERAL UMETA(DisplayName = "General"),
	FEAR UMETA(DisplayName = "Ironfisted"),
	RESPECT UMETA(DisplayName = "Pragmatic"),
	LOVE UMETA(DisplayName = "Empathetic")
};

/**
 * Controller for Morale Affecting Events i.e. Travel Loss, Ship Victory / Destruction
 */
class BATTLESHIP_API MoraleSystem
{
public:
	MoraleSystem();
	~MoraleSystem();

	// Dialogue Morale Functions
	UFUNCTION(BlueprintCallable)
	void ApplyDialogueMorale(EMoraleType PositiveType, EMoraleType NegativeTypeOne, EMoraleType NegativeTypeTwo, APlayerShipPawnBase* Ship, const int32 PositiveModifier, const int32 NegativeModifier);

	// Gameplay Morale Functions
	UFUNCTION(BlueprintCallable)
	void ApplyTravelMoraleLoss(const TArray<AShipPawnBase*>& Ships);
	UFUNCTION(BlueprintCallable)
	void ApplyShipMoraleLoss(const TArray<AShipPawnBase*>& Ships);
	UFUNCTION(BlueprintCallable)
	void ApplyShipMoraleGain(const TArray<AShipPawnBase*>& Ships);

private:
	// Modify Crew Morale
	void ReduceCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Reduction);
	void ImproveCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Additive);

	// Modify Ship Morale
	void ReduceShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Reduction);
	void ImproveShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Additive);

	int32 TravelLossModifier = 2;
};
