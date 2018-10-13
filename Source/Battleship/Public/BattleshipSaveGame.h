#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BattleshipSaveGame.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API UBattleshipSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UBattleshipSaveGame(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FString SaveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FString CharacterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInformation)
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FDateTime TimeStamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FName LevelToLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FText LevelDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FString Data;
};
