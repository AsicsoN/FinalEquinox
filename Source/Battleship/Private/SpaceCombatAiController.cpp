

#include "Battleship.h"
#include "SpaceCombatAiController.h"
#include "ShipPawnBase.h"
#include "SpaceCombatPlayerController.h"
#include "SpaceCombatGameMode.h"

void ASpaceCombatAiController::InitializeAI(const TArray<AShipPawnBase*> AiShips, ASpaceCombatGameMode* NewGameMode)
{
	EnemyShips = AiShips;
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
	AiLogicLoop();
}

void ASpaceCombatAiController::AiLogicLoop()
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

	// Move ship to ready range
	if (MoveShip() && SelectedShip->CurrentMovementPoints > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s ready to attack target"), *SelectedShip->Name);
		AttackPlayer();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s moving to target"), *SelectedShip->Name);
		World->GetTimerManager().SetTimer(AiTurnCycleHandle, this, &ASpaceCombatAiController::AiLogicLoop, 10.0f);
	}
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

bool ASpaceCombatAiController::MoveShip() 
{
	//TODO Swap this for precision movement to tiles
	EPathFollowingRequestResult::Type Result = MoveToActor(Target, 500.0f);

	if (Result == EPathFollowingRequestResult::AlreadyAtGoal)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship reached destination"));
		return true;
	}
	else
	{
		return false;
	}
}

void ASpaceCombatAiController::AttackPlayer()
{
	AShipPawnBase* SelectedShip = Cast<AShipPawnBase>(GetPawn());
	UWorld* World = GetWorld();

	if (World->GetTimerManager().IsTimerActive(AiTurnCycleHandle))
	{
		World->GetTimerManager().ClearTimer(AiTurnCycleHandle);
	}

	UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s ready to attack %s"), *SelectedShip->Name, *Target->Name);

	if (SelectedShip->CurrentActionPoints >= 0)
	{
		ASpaceCombatPlayerController* PlayerController = Cast<ASpaceCombatPlayerController>(World->GetFirstPlayerController());

		UnPossess();

		PlayerController->Possess(SelectedShip);
		PlayerController->PrepareToFire(true);

		UE_LOG(LogTemp, Warning, TEXT("Enemy Ship %s FIRING"), *SelectedShip->Name);

		PlayerController->Fire(Target);
		PlayerController->UnPossess();

		Possess(SelectedShip);

		//TODO We will want to eventually go back into the AiLogicLoop for other targets
		World->GetTimerManager().SetTimer(AiSwapCycleHandle, this, &ASpaceCombatAiController::AttackPlayer, 3.0f);
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

	//TODO Clear AI Controller and Unpossess();
	UnPossess();

	// Call GameMode to SwapPawn()
	//GameMode->SelectPawn();
}