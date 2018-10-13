#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CharacterSheet.h"
#include "BattleshipGameInstance.generated.h"

class UAbilityLibrary;

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UBattleshipGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBattleshipGameInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterSheet")
	UCharacterSheet* CharacterSheet;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityLibrary")
	UAbilityLibrary* AbilityLibrary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterId")
	FString CharacterId;

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Initialize();
};
