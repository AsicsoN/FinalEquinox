#include "Battleship.h"
#include "SpaceCombatGameMode.h"

#define LOCTEXT_NAMESPACE "SpaceCombat" 

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

	SpawnShips();

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Faction == EFaction::Enemy1)
		{
			ActorItr->CAG = GenerateRandomCrewMember();
			ActorItr->Engineer = GenerateRandomCrewMember();
			ActorItr->Captain = GenerateRandomCrewMember();
			ActorItr->NavigationOfficer = GenerateRandomCrewMember();
			ActorItr->ScienceOfficer = GenerateRandomCrewMember();
			ActorItr->TacticsOfficer = GenerateRandomCrewMember();
		}

		ShipArray.Add(*ActorItr);
	}

	ShipArray.Sort(SortShipPawnBase);

	SelectPawn(ShipArray[0]);

	for (auto& Ship : ShipArray)
	{
		UE_LOG(LogTemp, Error, TEXT("Initiative: %d"), Ship->Initiative);
	}
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

AGridController* ASpaceCombatGameMode::GetGridController()
{
	return GridController;
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
	crew->Leadership = 0;
	crew->Tactics = 0;
	crew->Gunnery = 0;
	crew->Engineering = 0;
	crew->Science = 0;
	crew->Tactics = 1;
	crew->Communication = 1;
	crew->SubsystemRepair = -1;
	crew->ShieldRepair = -1;

	return crew;
}

void ASpaceCombatGameMode::WriteToCombatLog(FText message)
{
	OnCombatEvent.Broadcast(message);
}

float ASpaceCombatGameMode::CalculateHitChance(AShipPawnBase* TargetShip)
{
	float toReturn = 0.0f;

	// base hit chance: y = -5x + 100
	toReturn = (-5 * CalculateDistance(SelectedShip, TargetShip)) + 100;

	// speed difference modifier: y = 5x
	toReturn += 5 * (SelectedShip->Speed - TargetShip->Speed);

	// selected ship WeaponsOfficer's gunnery skill modifier: y = 7x
	toReturn += 7 * (SelectedShip->TacticsOfficer->Gunnery);

	// target ship NavigationOfficer's piloting skill modifier: y = -7x
	toReturn += -7 * (TargetShip->NavigationOfficer->Navigation);

	if (GridController != nullptr)
	{
		if (GridController->IsSpaceObjectIntersectingShip(SelectedShip))
		{
			ASpaceObject* object = GridController->GetIntersectingSpaceObject(SelectedShip);
			toReturn -= object->HitChancePenalty;
		}
		if (GridController->IsSpaceObjectIntersectingShip(TargetShip))
		{
			ASpaceObject* object = GridController->GetIntersectingSpaceObject(TargetShip);
			toReturn -= object->HitChancePenalty;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GridController is not defined in SpaceCombatGameMode"));
	}

	return toReturn;
}

float ASpaceCombatGameMode::CalculateDistance(AShipPawnBase* Ship1, AShipPawnBase* Ship2)
{
	float toReturn = 0.0f;

	UGridLocation* loc1 = Ship1->FindComponentByClass<UGridLocation>();
	UGridLocation* loc2 = Ship2->FindComponentByClass<UGridLocation>();

	int32 ship1XMin = loc1->GetXMin();
	int32 ship1XMax = loc1->GetXMax();
	int32 ship2XMin = loc2->GetXMin();
	int32 ship2XMax = loc2->GetXMax();

	int32 ship1YMin = loc1->GetYMin();
	int32 ship1YMax = loc1->GetYMax();
	int32 ship2YMin = loc2->GetYMin();
	int32 ship2YMax = loc2->GetYMax();

	int32 difx = 0;
	if (ship2XMin > ship1XMax)
	{
		difx = ship2XMin - ship1XMax;
	}
	else if (ship1XMin > ship2XMax)
	{
		difx = ship1XMin - ship2XMax;
	}
	// all others difx = 0

	int32 dify = 0;
	if (ship2YMin > ship1YMax)
	{
		dify = ship2YMin - ship1YMax;
	}
	else if (ship1YMin > ship2YMax)
	{
		dify = ship1YMin - ship2YMax;
	}
	// all others dify = 0

	// Pythagorean theorem
	float csquared = (difx * difx) + (dify * dify);

	toReturn = sqrt(csquared);

	return toReturn;
}

void ASpaceCombatGameMode::RepairShip(AShipPawnBase* Ship)
{
	int32 repairAmount = Ship->Engineer->Engineering + FMath::RandRange(1, 10);

	int32 maxRepairAmount = Ship->HitPoints - Ship->CurrentHitPoints;

	if (repairAmount > maxRepairAmount)
	{
		repairAmount = maxRepairAmount;
	}

	Ship->CurrentHitPoints += repairAmount;

	FFormatNamedArguments Arguments;
	Arguments.Add(TEXT("Name"), FText::FromString(Ship->Name));
	Arguments.Add(TEXT("RepairAmount"), FText::AsNumber(repairAmount));

	Ship->ActionPoints = Ship->ActionPoints - 10;

	WriteToCombatLog(FText::Format(LOCTEXT("Repair", "{Name} repaired {RepairAmount} hit points"), Arguments));
}
