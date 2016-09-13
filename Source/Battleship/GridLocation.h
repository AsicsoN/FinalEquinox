#pragma once

#include "Components/ActorComponent.h"
#include "GridLocation.generated.h"

UENUM(BlueprintType)
enum class EGLRotation : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Clockwise25 UMETA(DisplayName = "Clockwise25Percent"),
	Clockwise50	UMETA(DisplayName = "Clockwise50Percent"),
	Clockwise75	UMETA(DisplayName = "Clockwise75Percent")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLESHIP_API UGridLocation : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGridLocation();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LocationX = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LocationY = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Width = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Length = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EGLRotation Rotation = EGLRotation::Normal;

};