

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleObject.generated.h"

UCLASS(ClassGroup = (Custom), hidecategories = ("Collision", "Lighting", "Rendering", "Physics", "Tags", "Cooking", "Shape","Input", "Actor", "Mobile"))
class BATTLESHIP_API ADestructibleObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleObject();

	UFUNCTION(BlueprintCallable)
	inline int32 TakeDamage(int32 Damage) { Health -= Damage; return Health; }

	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UBoxComponent* Box = nullptr;

	UPROPERTY(EditAnywhere, Category = "Variables")
	int32 Health = 0;

	UPROPERTY(EditAnywhere, Category = "Variables")
	bool bIsDestructible = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;	
};
