

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UGridLocation;
class USplineMeshComponent;

UCLASS()
class BATTLESHIP_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Tile = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Indicator = nullptr;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box = nullptr;

	UPROPERTY(EditAnywhere)
	class UGridLocation* GridLocation = nullptr;

	UFUNCTION(BlueprintPure)
	inline int32 GetRequiredMP() { return RequiredMP + RotCost; }

	int32 RotCost = 0;

	void ClearPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform &Transform) override;

	UFUNCTION()
	void CustomActorBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void CustomActorEndCursorOver(UPrimitiveComponent* TouchedComponent);

private:
	void BuildPath();

	int32 RequiredMP = 0;

	TArray<USplineMeshComponent*> SplineMeshes;
};
