

#include "Battleship.h"
#include "SpaceCombatAiController.h"
#include "ShipPawnBase.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"
#include "Tile.h"
#include "SpaceCombatCamerabase.h"
#include "AI/Navigation/NavigationPath.h"


void ASpaceCombatAiController::Tick(float DeltaTime)
{
	
}

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

	Rotation = SelectedShip->GetActorRotation();

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s moving to target"), *SelectedShip->Name);
	MoveShip();
}

void ASpaceCombatAiController::SelectTarget()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	for (AShipPawnBase* Ship : GameMode->ShipArray)
	{
		if (Ship == SelectedShip || Ship->Faction == EFaction::Enemy1)
		{
			continue;
		}

		if (!Target)
		{
			Target = Ship;
		} 
		else
		{
			float PotentialDistance = FVector::Distance(SelectedShip->GetActorLocation(), Ship->GetActorLocation());
			float TargetDistance = FVector::Distance(SelectedShip->GetActorLocation(), Target->GetActorLocation());
			
			if (SelectedShip->Type == Ship->Type)
			{
				if (PotentialDistance <= TargetDistance)
				{
					Target = Ship;
				}
			} 
			else
			{
				if (PotentialDistance <= TargetDistance && Target->Type != SelectedShip->Type)
				{
					Target = Ship;
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

		// Grab random point around target
		End = NavSys->GetRandomPointInNavigableRadius(GetWorld(), Target->GetActorLocation(), FactionEngageDistance, NavSys->MainNavData);

		// Make sure that our enemies keep a fixed minimum distance away.
		if (FVector::Dist(Target->GetActorLocation(), End) < 512.0f)
		{
			continue;
		}

		bool isOverlapping = false;
		for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			AShipPawnBase *Ship = Cast<AShipPawnBase>(*ActorItr);

			if (!Ship)
			{
				continue;
			}

			if (Ship->Faction != EFaction::Player)
			{
				continue;
			}

			if (FVector::Dist(Ship->GetActorLocation(), End) <= 600.0f)
			{
				isOverlapping = true;
				break;
			}
		}

		if (isOverlapping)
		{
			continue;
		}

		// Find Path to the Target Location
		UNavigationPath *NavResult = NavSys->FindPathToLocationSynchronously(GetWorld(), Start, End, SelectedShip);

		if (NavResult == nullptr)
		{
			continue;
		}

		#pragma region Debug Logic
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
		#pragma endregion

		float PathLength = NavResult->GetPathLength();

		PathLength = PathLength / 256;

		if (SelectedShip->CurrentMovementPoints < FMath::RoundToInt(PathLength))
		{
			FactionEngageDistance = FactionEngageDistance + 256.0f;
		}
		else
		{
			SelectedShip->CurrentMovementPoints -= FMath::RoundToInt(PathLength);
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

	SelectedShip->CalculateFinalRotation(TargetTile->GetActorLocation());

	#pragma region Debug Logic
	FColor LineColor = FColor();

	// Draw the central dot in the circle
	DrawDebugLine(
		GetWorld(),
		TargetTile->GetActorLocation(),
		TargetTile->GetActorLocation(),
		LineColor.Red,
		true,
		-1,
		0,
		20.0f
	);
	#pragma endregion
}

void ASpaceCombatAiController::MoveShip()
{
	UWorld* World = GetWorld();

	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	if (SelectedShip) 
	{
		bool EnginesOnline = (SelectedShip->Subsystems.Engine != 0.0f);

		EPathFollowingRequestResult::Type Result = EPathFollowingRequestResult::RequestSuccessful;

		// Calculate the AI Pathing using the Nav system.
		if (GetMoveStatus() != EPathFollowingStatus::Moving)
		{
			for (TActorIterator<ASpaceCombatCameraBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				UE_LOG(LogTemp, Warning, TEXT("StartFollowingShip"));
				ActorItr->StartFollowingShip(SelectedShip);
			}
			
			Result = MoveToActor(TargetTile, 20.0f);
			if (!SelectedShip->MovementSound->IsPlaying())
			{
				SelectedShip->MovementSound->FadeIn(2.0f);
			}
		}

		if (!EnginesOnline || Result == EPathFollowingRequestResult::AlreadyAtGoal)
		{
			World->GetTimerManager().ClearTimer(AiMoveCycleHandle);

			UE_LOG(LogTemp, Warning, TEXT("Enemy Ship reached destination"));
			StopMovement();

			for (TActorIterator<ASpaceCombatCameraBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				UE_LOG(LogTemp, Warning, TEXT("StopFollowingShip"));
				ActorItr->StopFollowingShip();
			}
			
			SelectedShip->bAdjustRotation = true;
			if (!SelectedShip->MovementSound->IsPlaying())
			{
				SelectedShip->MovementSound->FadeOut(1.0f, 0.0f);
			}
			
			World->GetTimerManager().SetTimer(AiAttackCycleHandle, this, &ASpaceCombatAiController::AttackPlayer, 2.0f);
		}
		else
		{
			World->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::MoveShip, 0.1f);
		}
	}
}

void ASpaceCombatAiController::AttackPlayer()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());
	UWorld* World = GetWorld();

	// Wait until rotation is complete
	if (SelectedShip->bAdjustRotation)
	{
		World->GetTimerManager().SetTimer(AiAttackCycleHandle, this, &ASpaceCombatAiController::AttackPlayer, 1.0f);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s ready to attack %s"), *SelectedShip->Name, *Target->Name);

	if (SelectedShip->CurrentActionPoints > 0)
	{
		ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(World->GetFirstPlayerController());

		PlayerController->PrepareToFire(true);

		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s FIRING"), *SelectedShip->Name);

		if (!SelectedShip->Subsystems.Guns)
		{
			SelectedShip->CurrentActionPoints = 0;
		}

		SelectedShip->FireVFX(Target);

		PlayerController->Fire(Target);

		if (Target->CurrentHitPoints <= 0)
		{
			// Target has died, Look for new Target!
			Target = nullptr;

			World->GetTimerManager().SetTimer(AiTurnInfoHandle, this, &ASpaceCombatAiController::GenerateTurnInformation, 5.0f);
		}
		else
		{
			World->GetTimerManager().SetTimer(AiAttackCycleHandle, this, &ASpaceCombatAiController::AttackPlayer, 5.0f);
		}
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

	SelectedShip->ChangeCollision(false);

	UnPossess();

	// Call GameMode to SwapPawn()
	SelectedShip->ForceTurnEnd = true;
}