#include "Battleship.h"
#include "SpaceCombatAiController.h"
#include "ShipPawnBase.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"
#include "Tile.h"
#include "DestructibleObject.h"
#include "SpaceCombatCameraBase.h"
#include "NavigationPath.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"

#define LOCTEXT_NAMESPACE "SpaceCombat" 

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

	if (SelectedShip->CurrentHitPoints <= 0)
	{
		// Ship should be destroyed, initiate self destruct
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(*SelectedShip->Name));
		GameMode->WriteToCombatLog(FText::Format(LOCTEXT("Destroyed", "{Name} has suffered a critical reactor failure!"), Arguments));

		GameMode->SelectedPawnIndex = GameMode->SelectedPawnIndex - 1;

		SelectedShip->ShipDestroyed();

		GetWorld()->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::SwapShip, 5.0f);
	}
	else
	{
		// Commence Ai Logic Cycle
		GenerateTurnInformation();
	}
}

void ASpaceCombatAiController::GenerateTurnInformation()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());

	if (!SelectedShip)
	{
		return;
	}

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

	if (!SelectedShip || !Target)
	{
		return;
	}

	FVector Start = SelectedShip->GetActorLocation();

	float TotalDistance = FVector::Distance(Start, Target->GetActorLocation());

	float FactionEngageDistance = 0.0f;

	// Knock off Faction Bonus
	if (SelectedShip->Faction == EFaction::Enemy1)
	{
		FactionEngageDistance = 256.0f * 10;
	}

	// If Total Distance is at or below engagement distance, we need to move away
	if (TotalDistance < FactionEngageDistance)
	{
		TotalDistance = FactionEngageDistance * 3;
	}

	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	// Calculate the AI Pathing using the Nav system.
	int32 MaxTravesals = 100;
	FVector End;
	while (MaxTravesals)
	{
		// Grab random point around Ship within distance
		End = NavSys->GetRandomPointInNavigableRadius(GetWorld(), Start, FactionEngageDistance, NavSys->MainNavData);

		// Make sure that AI is moving towards target
		if (FVector::Dist(Target->GetActorLocation(), End) > TotalDistance || FVector::Dist(Target->GetActorLocation(), End) < 2000.0f)
		{
			MaxTravesals--;
			continue;
		}

		// Find Path to the Target Location
		UNavigationPath *NavResult = NavSys->FindPathToLocationSynchronously(GetWorld(), Start, End, SelectedShip);

		if (NavResult == nullptr)
		{
			MaxTravesals--;
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

		// Calculate Path Cost
		float PathLength = NavResult->GetPathLength();
		PathLength = PathLength / 256;

		if (SelectedShip->CurrentMovementPoints < FMath::RoundToInt(PathLength))
		{
			UE_LOG(LogTemp, Error, TEXT("Ship Movement: %d Required: %d"), SelectedShip->CurrentMovementPoints, FMath::RoundToInt(PathLength));
			FactionEngageDistance = FactionEngageDistance + 256.0f;
		}
		else
		{
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

			// Calculate the Final Rotation for the Enemy
			SelectedShip->CalculateFinalRotation(CurTile->GetActorLocation());
			
			// Check Enemy is not Colliding
			if (!CheckCollision(CurTile->GetActorLocation()))
			{
				SelectedShip->CurrentMovementPoints -= FMath::RoundToInt(PathLength);
				TargetTile = CurTile;
				UE_LOG(LogTemp, Error, TEXT("%s"), *TargetTile->GetName());
				break;

				// Check Enemy is Facing Target
				/*if (CheckFacing(End))
				{
				//}*/
			}
		}

		MaxTravesals--;
	}

	if (MaxTravesals == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Max Nav Attempts Reached -- Not Moving to Current Location"));
		ATile* CurTile = nullptr;

		// Calculate our target tile
		for (TActorIterator<ATile> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (!CurTile)
			{
				CurTile = *ActorItr;
			}

			float CurrentDistance = FVector::Distance(CurTile->GetActorLocation(), Start);
			float NewDistance = FVector::Distance(ActorItr->GetActorLocation(), Start);

			if (NewDistance < CurrentDistance)
			{
				CurTile = *ActorItr;
			}
		}

		TargetTile = CurTile;
	}

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

	if (!SelectedShip || !Target)
	{
		return;
	}

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

	if (!SelectedShip)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s finished turn"), *SelectedShip->Name);

	SelectedShip->ChangeCollision(false);

	UnPossess();

	// Call GameMode to SwapPawn()
	SelectedShip->ForceTurnEnd = true;
}

bool ASpaceCombatAiController::CheckCollision(FVector MoveLocation)
{
	AShipPawnBase* SelectedShip = GameMode->SelectedShip;

	if (SelectedShip)
	{
		TArray<UActorComponent*> Meshes = SelectedShip->GetComponentsByTag(UStaticMeshComponent::StaticClass(), FName("Ship"));

		if (!Meshes.Num())
		{
			return false;
		}

		UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(Meshes[0]);

		if (Mesh->IsValidLowLevel())
		{
			FVector StartLoc = Mesh->RelativeLocation;
			FRotator StartRot = Mesh->RelativeRotation;

			Mesh->SetRelativeRotation(SelectedShip->NewRotation);

			FVector MoveLoc = FVector(MoveLocation.X, MoveLocation.Y, StartLoc.Z);
			Mesh->SetWorldLocation(MoveLoc, false, nullptr, ETeleportType::TeleportPhysics);

			TArray<AActor*> OverlappingActors;
			Mesh->GetOverlappingActors(OverlappingActors, ADestructibleObject::StaticClass());

			TArray<AActor*> OverlappingShips;
			Mesh->GetOverlappingActors(OverlappingShips, AShipPawnBase::StaticClass());
			if (OverlappingShips.Contains(SelectedShip))
			{
				OverlappingShips.Remove(SelectedShip);
			}

			Mesh->SetRelativeLocationAndRotation(StartLoc, StartRot, false, nullptr, ETeleportType::TeleportPhysics);

			bool isOverlapping = false;
			if (OverlappingActors.Num() || OverlappingShips.Num())
			{
				UE_LOG(LogTemp, Warning, TEXT("Overlapped: Asteroids %d Ships %d"), OverlappingActors.Num(), OverlappingShips.Num());
				isOverlapping = true;
			}

			return isOverlapping;
		}
	}

	return true;
}

bool ASpaceCombatAiController::CheckFacing(FVector MoveLocation)
{
	if (Target)
	{
		FRotator LookRot = (Target->GetActorLocation() - MoveLocation).Rotation();

		if (LookRot.Yaw > 45.0f)
		{
			// Not Facing
			return false;
		}
		else
		{
			// Facing Target
			return true;
		}
	}

	return false;
}

#undef LOCTEXT_NAMESPACE
