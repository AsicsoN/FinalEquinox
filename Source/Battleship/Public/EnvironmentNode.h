

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnvironmentNode.generated.h"

//class UEnvironment;

/**
 * User Display on Map Blueprint of individual LevelEnvironments
 */
UCLASS()
class BATTLESHIP_API UEnvironmentNode : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	FString Description;

	UPROPERTY(EditAnywhere)
	UTexture2D* Image;

	UPROPERTY(EditAnywhere)
	TArray<UEnvironmentNode*> Children;

	UPROPERTY(EditAnywhere)
	FString LaunchLevel;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LaunchWidget;

	UFUNCTION(BlueprintCallable)
	void SetImage(UTexture2D* NewImage); 

	UFUNCTION(BlueprintCallable)
	UTexture2D* GetImage();

	UFUNCTION(BlueprintCallable)
	TArray<UEnvironmentNode*> GetChildren();

	UFUNCTION(BlueprintCallable)
	FString GetLaunchLevel();

	UFUNCTION(BlueprintCallable)
	TSubclassOf<UUserWidget> GetLaunchWidget();

	//UEnvironment EnvironmentInfo;
	
};
