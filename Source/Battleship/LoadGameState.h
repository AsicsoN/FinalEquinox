

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LoadGameState.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API ALoadGameState : public AGameStateBase
{
	GENERATED_BODY()
		// Allows blueprint to refer to this class
		UFUNCTION(BlueprintCallable, Category = "SaveMenu")
		static FString runLoadGame();

protected:

public:
	ALoadGameState();									// default constructor
};
