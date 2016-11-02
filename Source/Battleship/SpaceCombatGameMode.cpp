#include "Battleship.h"
#include "SpaceCombatGameMode.h"

// Sets default values
ASpaceCombatGameMode::ASpaceCombatGameMode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceCombatGameMode::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AGridController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GridController = *ActorItr;
	}

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ShipArray.Add(*ActorItr);
	}

	ShipArray.Sort(SortShipPawnBase);

	for (auto& Ship : ShipArray)
	{
		UE_LOG(LogTemp, Error, TEXT("Initiative: %d"), Ship->Initiative);
	}

	SelectShip(ShipArray[0]);
}

// Called every frame
void ASpaceCombatGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpaceCombatGameMode::SelectShip(AShipPawnBase* Ship)
{
	SelectedShip = Ship;
}

void ASpaceCombatGameMode::EndCombat()
{

}


