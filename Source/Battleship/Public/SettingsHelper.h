#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SettingsHelper.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BATTLESHIP_API USettingsHelper : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static float GetMusicVolume();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static float GetEffectsVolume();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static float GetUIVolume();

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static void SetMusicVolume(float value);

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static void SetEffectsVolume(float value);

	UFUNCTION(BlueprintCallable, Category = "Settings")
	static void SetUIVolume(float value);
	
private:

	UFUNCTION()
	static float GetFloat(FString name);
	
	UFUNCTION()
	static void SetFloat(FString name, float value);
};
