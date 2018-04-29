#include "Battleship.h"
#include "SpaceCombatGameMode.h"
#include "SpaceCombatAiController.h"

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

	if (!AiController)
	{
		UWorld* World = GetWorld();
		AiController = World->SpawnActor<ASpaceCombatAiController>(ASpaceCombatAiController::StaticClass());
	}

	for (TActorIterator<AGridController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GridController = *ActorItr;
	}

	SpawnShips();

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ShipArray.Add(*ActorItr);
	}

	ShipArray.Sort(SortShipPawnBase);

	SelectPawn(ShipArray[0]);

	AiController->InitializeAI(this);

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

void ASpaceCombatGameMode::StartAiTurn()
{
	AiController->Possess(SelectedShip);
	AiController->BeginAiTurn();
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

void ASpaceCombatGameMode::CheckCombatState()
{
	int32 PlayerCount = 0;
	int32 EnemyCount = 0;

	for (const AShipPawnBase* Ship : ShipArray)
	{
		if (Ship->Faction == EFaction::Player)
		{
			PlayerCount++;
		}
		else
		{
			EnemyCount++;
		}
	}

	if (PlayerCount && EnemyCount)
	{
		return;
	}

	if (!PlayerCount)
	{
		EndCombat(false);
	}
	else
	{
		EndCombat(true);
	}
}

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
	float Chance = 0.0f;

	// Calculate Distance per Square
	float Distance = CalculateDistance(SelectedShip, TargetShip);

	// Speed Difference between ships
	float SpeedDifference = 5 * (SelectedShip->Speed - TargetShip->Speed);

	// Selected Ships Gunnery Modifier
	float GunneryDifference = 7 * (SelectedShip->Gunnery);

	// Target Ship Navigation Modifier
	float NavigationDifference = 7 * (TargetShip->Navigation);

	// Enviornmental Penalty
	float Penalty = 0.0f;

	if (GridController != nullptr)
	{
		if (GridController->IsSpaceObjectIntersectingShip(SelectedShip))
		{
			ASpaceObject* object = GridController->GetIntersectingSpaceObject(SelectedShip);
			Penalty -= object->HitChancePenalty;
		}
		if (GridController->IsSpaceObjectIntersectingShip(TargetShip))
		{
			ASpaceObject* object = GridController->GetIntersectingSpaceObject(TargetShip);
			Penalty -= object->HitChancePenalty;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GridController is not defined in SpaceCombatGameMode"));
	}

	// (100 - (DistanceInSquares * 5)) + SpeedDifference + NavigationDifference + (GunneryModifier * 1.5) + Penalty;
	float HitChance = (100 - (Distance * 5)) + SpeedDifference + NavigationDifference + (GunneryDifference * 1.5);
	float HitBonus = SelectedShip->HitBonus;
	
	if (SelectedShip->ScannedShips.Contains(TargetShip))
	{
		HitBonus += 0.2f;
	}

	HitChance *= (1.0f + HitBonus);
	HitChance += Penalty;
	return HitChance;
}

float ASpaceCombatGameMode::CalculateDistance(AShipPawnBase* Ship1, AShipPawnBase* Ship2)
{
	float ShipDistance = Ship1->GetDistanceTo(Ship2);

	ShipDistance = FMath::FloorToInt(ShipDistance / 256.0f);

	return ShipDistance;

	/*float toReturn = 0.0f;

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

	return toReturn;*/
}

void ASpaceCombatGameMode::RepairShip(AShipPawnBase* Ship, FString Type)
{
	int32 repairAmount = 0; // = Ship->Engineer->Engineering + FMath::RandRange(1, 10);
	int32 maxRepairAmount = 0; // Ship->HitPoints - Ship->CurrentHitPoints;
	float Engineering = 0.0f;

	if (Type == "Hull")
	{
		Engineering += Ship->HullRepair;

		maxRepairAmount = Ship->HitPoints - Ship->CurrentHitPoints;

		int32 Chance = FMath::RandRange(1, 10);

		repairAmount = FMath::Clamp(FMath::CeilToInt(Engineering) * Chance, 0, maxRepairAmount);

		UE_LOG(LogTemp, Warning, TEXT("Engineering: %f  RepairAmount: %d"), Engineering, repairAmount);

		if (Chance == 10)
		{
			repairAmount += (repairAmount / 100) * 30;
		}
	}
	else if (Type == "Shield")
	{
		Engineering += Ship->ShieldRepair;

		maxRepairAmount = Ship->ShieldHitPoints - Ship->CurrentShieldHitPoints;

		int32 Chance = FMath::RandRange(1, 10);

		repairAmount = FMath::Clamp(FMath::CeilToInt(Engineering) + Chance, 0, maxRepairAmount);

		if (Chance == 10)
		{
			repairAmount += (repairAmount / 100) * 30;
		}
	}
	else
	{
		Engineering += Ship->SubsystemRepair;

		// TODO add once subsystems have been added 
		// d3
	}
	
	if (repairAmount > maxRepairAmount)
	{
		repairAmount = maxRepairAmount;
	}

	FFormatNamedArguments Arguments;
	Arguments.Add(TEXT("Name"), FText::FromString(Ship->Name));
	Arguments.Add(TEXT("RepairAmount"), FText::AsNumber(repairAmount));

	if (Type == "Hull")
	{
		Arguments.Add(TEXT("Type"), FText::FromString("Hull"));
		Ship->CurrentHitPoints += repairAmount;
		Ship->CurrentActionPoints = Ship->CurrentActionPoints - 8;
	}
	else if (Type == "Shield")
	{
		Arguments.Add(TEXT("Type"), FText::FromString("Shield"));
		Ship->CurrentShieldHitPoints += repairAmount;
		Ship->CurrentActionPoints = Ship->CurrentActionPoints - 6;
	}
	else
	{
		//TODO add subsystem when ready
		/*Arguments.Add(TEXT("Type"), FText::FromString("Subsystem"));
		Ship->CurrentShieldHitPoints += repairAmount;
		Ship->CurrentActionPoints = Ship->CurrentActionPoints - 4;*/
	}

	WriteToCombatLog(FText::Format(LOCTEXT("Repair", "{Name} repaired {RepairAmount} {Type} hit points"), Arguments));
}
