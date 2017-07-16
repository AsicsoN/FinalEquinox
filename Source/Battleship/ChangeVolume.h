

#pragma once

#include "CoreMinimal.h"
#include "ChangeVolume.generated.h"


/**
 * 
 */
class BATTLESHIP_API ChangeVolume
{
public:
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "VolumeControls")
		static FString GetSaveGamesDirectory();

	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
		static TArray<FString> GetSaveGameFiles();

	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
		static FString GetLatestSaveFile();

};