#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShipInfoBaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UShipInfoBaseWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "UserInterface")
	void Update();
};
