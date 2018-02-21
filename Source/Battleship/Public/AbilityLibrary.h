

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Ability.h"
#include "AbilityLibrary.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLESHIP_API UAbilityLibrary : public UObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityLibrary();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<FAbilityStruct> AbilityList;
};
