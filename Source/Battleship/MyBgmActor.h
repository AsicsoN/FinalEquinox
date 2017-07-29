

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBgmActor.generated.h"

UCLASS()
class BATTLESHIP_API AMyBgmActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyOptionsMenu")
	static void SetVolume(AActor* BgmActor, float volume);


public:	
	// Sets default values for this actor's properties
	AMyBgmActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
