

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGameState.generated.h"

/**
*
*/
<<<<<<< HEAD
UCLASS()
class BATTLESHIP_API ASaveGameState : public AGameStateBase
{
	GENERATED_BODY()
		// Allows blueprint to refer to this class
		UFUNCTION(BlueprintCallable, Category = "SaveMenu")
		static void runSaveGame();

protected:
	TMap<FString, FString> dataMap;						// stores global data in a HashMap
														//	bool generateSaveFile(FString fileDirectory, FString filename, FString saveText);

public:
	ASaveGameState();									// default constructor
	void SetDataMap(FString key1, FString value1);		// setters
	TMap<FString, FString> GetDataMap();				// getters	
};
=======
UCLASS(Blueprintable)
class BATTLESHIP_API ASaveGameState : public AGameStateBase
{
	GENERATED_BODY()


public:
	// Allows blueprint to refer to this class
	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
		static FString GenerateLatestSave();

public:
	ASaveGameState();									// default constructor
};

	
>>>>>>> pause_menu
