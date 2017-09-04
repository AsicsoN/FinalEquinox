#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceObject.generated.h"

UCLASS()
class BATTLESHIP_API ASpaceObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Hit chance percentage penalty for shooting ships in this cloud as well as shooting out of this cloud
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Information")
	float HitChancePenalty = 0.0f;

	// Are ships detectable when in this cloud?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Information")
	bool bAreShipsDetectable = true;

	// String to display in the combat log when talking about this type of space object
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Information")
	FString ObjectTypeDisplayName;
	
};
