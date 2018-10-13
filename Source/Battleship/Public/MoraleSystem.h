

#pragma once

#include "CoreMinimal.h"

class UCrew;
class AShipPawnBase;

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
	static void ApplyDialogueMorale(EMoraleType PositiveType, EMoraleType NegativeTypeOne, EMoraleType NegativeTypeTwo, APlayerShipPawnBase* Ship, const int32 PositiveModifier, const int32 NegativeModifier);

	// Gameplay Morale Functions
	UFUNCTION(BlueprintCallable)
	static void ApplyTravelMoraleLoss(const TArray<APlayerShipPawnBase*>& Ships);
	UFUNCTION(BlueprintCallable)
	static void ApplyShipMoraleLoss(const TArray<APlayerShipPawnBase*>& Ships);
	UFUNCTION(BlueprintCallable)
	static void ApplyShipMoraleGain(const TArray<APlayerShipPawnBase*>& Ships);

	// Information Functions
	UFUNCTION(BlueprintCallable)
	static FString GetShipMoraleDescriptor(APlayerShipPawnBase* Ship);
	UFUNCTION(BlueprintCallable)
	static int32 GetShipMoraleValue(APlayerShipPawnBase* Ship);
	UFUNCTION(BlueprintCallable)
	static FString GetFleetMoraleDescriptor(const TArray<APlayerShipPawnBase*>& Ships);
	UFUNCTION(BlueprintCallable)
	static int32 GetFleetMoraleValue(const TArray<APlayerShipPawnBase*>& Ships);

	// Utility Functions
	UFUNCTION(BlueprintCallable)
	static FString GetMoraleDescriptor(int32 MoraleValue);

private:
	// Modify Crew Morale
	static void ReduceCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Reduction);
	static void ImproveCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Additive);

	// Modify Ship Morale
	static void ReduceShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Reduction);
	static void ImproveShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Additive);

	int32 TravelLossModifier = 2;
};
