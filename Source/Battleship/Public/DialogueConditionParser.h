#pragma once

#include "CoreMinimal.h"
#include "CharacterSheet.h"
#include "UObject/NoExportTypes.h"
#include "DialogueConditionParser.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UDialogueConditionParser : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	static bool ParseConditionString(FString input, UCharacterSheet* characterSheet);
	
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	static bool Operator(FString input, UCharacterSheet* characterSheet, FString operation);
	
};
