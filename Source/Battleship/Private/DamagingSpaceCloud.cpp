#include "Battleship.h"
#include "DamagingSpaceCloud.h"


// Sets default values
ADamagingSpaceCloud::ADamagingSpaceCloud()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamagingSpaceCloud::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamagingSpaceCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
