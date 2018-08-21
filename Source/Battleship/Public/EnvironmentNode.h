

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnvironmentNode.generated.h"

//class Environment;

/**
 * User Display on Map Blueprint of individual LevelEnvironments
 */
UCLASS()
class BATTLESHIP_API UEnvironmentNode : public UUserWidget
{
	GENERATED_BODY()

	FString Name;
	FString Description;
	//Environment EnvironmentInfo;
	
};
