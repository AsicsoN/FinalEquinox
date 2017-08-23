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
	
};
