#pragma once

#include "CoreMinimal.h"
#include "Crew.h"
#include "PlayerCrewObject.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UPlayerCrewObject : public UCrew
{
	GENERATED_BODY()

public:

	UPlayerCrewObject();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void Refresh(UBattleshipGameInstance* GameInstance);
};
