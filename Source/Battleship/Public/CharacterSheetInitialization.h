#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSheet.h"
#include "CharacterSheetInitialization.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UCharacterSheetInitialization : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Initialization")
	static UCharacterSheet* CreateStartingCharacterSheet();
};
