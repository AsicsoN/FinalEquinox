#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BattleshipGameInstance.generated.h"

class UAbilityLibrary;
class UCharacterSheet;

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

	UFUNCTION(BlueprintCallable, Category = "Testing")
	UCharacterSheet* CreateDefaultCharacterSheet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterId")
	FString CharacterId;

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Initialize();
};
