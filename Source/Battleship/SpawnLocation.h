

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnLocation.generated.h"

UCLASS()
class BATTLESHIP_API ASpawnLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
