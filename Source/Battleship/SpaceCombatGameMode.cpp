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

	/*for (TActorIterator<AGridController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GridController = *ActorItr;
	}

	SpawnShips();

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ShipArray.Add(*ActorItr);
	}

	ShipArray.Sort(SortShipPawnBase);

	for (auto& Ship : ShipArray)
	{

		UE_LOG(LogTemp, Error, TEXT("Initiative: %d"), Ship->Initiative);
	}

	SelectShip(ShipArray[0]);*/
}

void ASpaceCombatGameMode::SortShipPawnArrayByInitiative(TArray<AShipPawnBase*> PawnArrayIn)
{
	PawnArrayIn.Sort(SortShipPawnBase);
}

// Called every frame
void ASpaceCombatGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*void ASpaceCombatGameMode::SpawnShips()
{
	TArray<ASpawnLocation*> SpawnLocations;
	for (TActorIterator<ASpawnLocation> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		SpawnLocations.Add(*ActorItr);
	}

	for (int32 i = 0; i < ShipsArray.Length; i++)
	{
		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		GetWorld()->SpawnActor<AShipPawnBase>(Location, Rotation, SpawnInfo);
	}
}

void ASpaceCombatGameMode::SelectShip(AShipPawnBase* Ship)
{
	SelectedShip = Ship;
}*/

void ASpaceCombatGameMode::EndCombat(bool PlayerWon)
{
	bDidPlayerWin = PlayerWon;
	bIsCombatEnded = true;
}

bool ASpaceCombatGameMode::DidPlayerWin()
{
	return bDidPlayerWin;
}

UCrew* ASpaceCombatGameMode::GenerateRandomCrewMember()
{
	UCrew* crew = NewObject<UCrew>();
	//UCrew* crew = ConstructObject<UCrew>(UCrew::StaticClass());
	crew->CrewName = "John Smith";
	crew->CrewRace = ERace::Human;
	crew->IsMale = true;
	crew->Leadership = 3;
	crew->Piloting = 3;
	crew->Gunnery = 3;
	crew->Mechanics = 3;
	crew->Hacking = 3;

	return crew;
}

void ASpaceCombatGameMode::WriteToCombatLog(FText message)
{
	OnCombatEvent.Broadcast(message);
}

