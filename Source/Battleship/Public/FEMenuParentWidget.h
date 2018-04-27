

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FEMenuParentWidget.generated.h"

USTRUCT(BlueprintType)
struct BATTLESHIP_API FNestedButtons
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UButton*> Buttons;
};

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UFEMenuParentWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetNavigation")
	int32 CurrentRowIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetNavigation")
	int32 CurrentButtonIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetNavigation")
	TArray<FNestedButtons> NavigationLayout;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "WidgetNavigation")
	void KeyPressed(const FString& Key);

	UFUNCTION(BlueprintCallable, Category = "WidgetNavigation")
	virtual bool CheckKey(const TSet<FString> CheckKeys, const FString Key);

	UFUNCTION(BlueprintCallable, Category = "WidgetNavigation")
	virtual UButton* NavigateUpDown(int32 Mod);

	UFUNCTION(BlueprintCallable, Category = "WidgetNavigation")
	virtual UButton* NavigateLeftRight(int32 Mod);

	UFUNCTION(BlueprintCallable, Category = "WidgetNavigation")
	virtual UButton* GetCurrentButton();
};
