

#include "Battleship.h"
#include "SpaceCombatAiController.h"
#include "ShipPawnBase.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"
#include "Tile.h"
#include "AI/Navigation/NavigationPath.h"

void ASpaceCombatAiController::InitializeAI(ASpaceCombatGameMode* NewGameMode)
{
	GameMode = NewGameMode;
}

void ASpaceCombatAiController::BeginAiTurn()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	if (!SelectedShip)
	{
		UE_LOG(LogTemp, Error, TEXT("ASpaceCombatAiController::BeginAiTurn: No enemy ship avaliable!"))
		SwapShip();
	}

	// Possess Pawn
	Possess(SelectedShip);

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s starting turn"), *SelectedShip->Name);

	// Commence Ai Logic Cycle
	GenerateTurnInformation();
}

void ASpaceCombatAiController::GenerateTurnInformation()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());
	UWorld* World = GetWorld();

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s entering loop"), *SelectedShip->Name);

	// Make sure the Ai has a target
	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s is selecting a target"), *SelectedShip->Name);
		SelectTarget();
	}

	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s can't get a target, have we won?"), *SelectedShip->GetName());
		World->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::SwapShip, 5.0f);
		return;
	}

	// Calculate Travel Point
	CalculateTravelPoint();

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s moving to target"), *SelectedShip->Name);
	MoveShip();
}

void ASpaceCombatAiController::SelectTarget()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	for (TActorIterator<AShipPawnBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (*ActorItr == SelectedShip || ActorItr->Faction == EFaction::Enemy1)
		{
			continue;
		}

		if (!Target)
		{
			Target = *ActorItr;
		} 
		else
		{
			float PotentialDistance = FVector::Distance(SelectedShip->GetActorLocation(), ActorItr->GetActorLocation());
			float TargetDistance = FVector::Distance(SelectedShip->GetActorLocation(), Target->GetActorLocation());
			
			if (SelectedShip->Type == ActorItr->Type)
			{
				if (PotentialDistance <= TargetDistance)
				{
					Target = *ActorItr;
				}
			} 
			else
			{
				if (PotentialDistance <= TargetDistance && Target->Type != SelectedShip->Type)
				{
					Target = *ActorItr;
				}
			}
		}
	}

	if (Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s has targetted %s"), *SelectedShip->Name, *Target->Name);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s couldn't get a target"), *SelectedShip->Name);
	}
}

void ASpaceCombatAiController::CalculateTravelPoint() 
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	FVector Start = SelectedShip->GetActorLocation();

	float TotalDistance = FVector::Distance(Start, Target->GetActorLocation());

	float FactionEngageDistance = 0.0f;

	// Knock off Faction Bonus
	if (SelectedShip->Faction == EFaction::Enemy1)
	{
		FactionEngageDistance = 256.0f * 10;
	}
	
	UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(GetWorld());

	// Calculate the AI Pathing using the Nav system.
	FVector End;
	while (true)
	{
		End = NavSys->GetRandomPointInNavigableRadius(GetWorld(), Target->GetActorLocation(), FactionEngageDistance, NavSys->MainNavData);
		UNavigationPath *NavResult = NavSys->FindPathToLocationSynchronously(GetWorld(), Start, End, SelectedShip);

		if (NavResult == nullptr)
		{
			continue;
		}

		FColor LineColor = FColor();

		for (int32 Index = 0; Index < NavResult->PathPoints.Num(); Index++)
		{
			int32 NextIndex = Index + 1;
			bool bIsEven = (NextIndex % 2 > 0) ? true : false;

			NextIndex = FMath::Clamp(NextIndex, 1, FMath::RoundToInt(NavResult->PathPoints.Num() - 1));

			if (NextIndex != NavResult->PathPoints.Num())
			{
				FVector PointA = NavResult->PathPoints[Index];
				FVector PointB = NavResult->PathPoints[NextIndex];
				DrawDebugLine(
					GetWorld(),
					PointA,
					PointB,
					LineColor.Red,
					true,
					-1,
					0,
					10.0f
				);
			}
		}

		// Draw the central dot in the circle
		DrawDebugLine(
			GetWorld(),
			End,
			End,
			LineColor.Red,
			true,
			-1,
			0,
			20.0f
		);

		float PathLength = NavResult->GetPathLength();

		PathLength = PathLength / 256;

		if (SelectedShip->CurrentMovementPoints < FMath::RoundToInt(PathLength))
		{
			FactionEngageDistance = FactionEngageDistance + 256.0f;
		}
		else
		{
			break;
		}
	}

	ATile* CurTile = nullptr;

	// Calculate our target tile
	for (TActorIterator<ATile> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (!CurTile)
		{
			CurTile = *ActorItr;
		}

		float CurrentDistance = FVector::Distance(CurTile->GetActorLocation(), End);
		float NewDistance = FVector::Distance(ActorItr->GetActorLocation(), End);

		if (NewDistance < CurrentDistance)
		{
			CurTile = *ActorItr;
		}
	}
	
	TargetTile = CurTile;
}

void ASpaceCombatAiController::MoveShip()
{
	UWorld* World = GetWorld();

	// Calculate the AI Pathing using the Nav system.
	EPathFollowingRequestResult::Type Result = MoveToActor(TargetTile, 500.0f);

	if (Result == EPathFollowingRequestResult::AlreadyAtGoal)
	{
		World->GetTimerManager().ClearTimer(AiMoveCycleHandle);

		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship reached destination"));
		StopMovement();

		AttackPlayer();
	}
	else
	{
		World->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::MoveShip, 3.0f);
	}
}

void ASpaceCombatAiController::AttackPlayer()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());
	UWorld* World = GetWorld();

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s ready to attack %s"), *SelectedShip->Name, *Target->Name);

	if (SelectedShip->CurrentActionPoints >= 0)
	{
		ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(World->GetFirstPlayerController());

		PlayerController->PrepareToFire(true);

		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s FIRING"), *SelectedShip->Name);

		PlayerController->Fire(Target);

		//TODO We will want to eventually go back into the AiLogicLoop for other targets
		World->GetTimerManager().SetTimer(AiAttackCycleHandle, this, &ASpaceCombatAiController::AttackPlayer, 5.0f);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s finished attacking"), *SelectedShip->Name);

		Target = nullptr;

		World->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::SwapShip, 5.0f);
	}
}

void ASpaceCombatAiController::SwapShip()
{
	UWorld* World = GetWorld();
	World->GetTimerManager().ClearAllTimersForObject(this);

	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s finished turn"), *SelectedShip->Name);

	UnPossess();

	// Call GameMode to SwapPawn()
	SelectedShip->ForceTurnEnd = true;
}