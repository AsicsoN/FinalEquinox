

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGameState.generated.h"

/**
*
*/
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

	