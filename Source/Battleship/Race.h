

#pragma once

#include "Object.h"
#include "Race.generated.h"

UENUM(BlueprintType)
enum class ERace : uint8
{
	Human UMETA(DisplayName = "Human"),
	Malderian UMETA(DisplayName = "Malderian"),
	Krum UMETA(DisplayName = "Krum"),
	Barkhomi UMETA(DisplayName = "Barkhomi")
};

/**
 * 
 */
UCLASS()
class BATTLESHIP_API URace : public UObject
{
	GENERATED_BODY()
};
