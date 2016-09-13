#include "Battleship.h"
#include "GridLocation.h"


// Sets default values for this component's properties
UGridLocation::UGridLocation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UGridLocation::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGridLocation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}