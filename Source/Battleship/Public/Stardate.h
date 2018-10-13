#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Stardate.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UStardate : public UObject
{
	GENERATED_BODY()
	
public:

	UStardate();
	
	UFUNCTION(BlueprintCallable, Category = "Stardate")
	void SetStardate(int32 Year, int32 Month, int32 Day);

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	FText GetFormattedDate();

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	void AddDay();

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	void AddDays(int32 days);

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	int32 GetYear();

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	int32 GetMonth();

	UFUNCTION(BlueprintCallable, Category = "Stardate")
	int32 GetDay();

private:

	int32 Year = 5859;

	int32 Month = 6;

	int32 Day = 3;

};
