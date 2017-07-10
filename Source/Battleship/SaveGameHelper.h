
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SaveGameHelper.generated.h"

/**
*
*/
UCLASS(BlueprintType)
class BATTLESHIP_API USaveGameHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
	static FString GetSaveGamesDirectory();

	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
		static TArray<FString> GetSaveGameFiles();

	UFUNCTION(BlueprintCallable, Category = "MySaveMenu")
		static FString GetLatestSaveFile();
};