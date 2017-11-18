#include "Battleship.h"
#include "SpaceCombatPlayerController.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"
#include "DestructibleObject.h"
#include "Tile.h"

ASpaceCombatPlayerController::ASpaceCombatPlayerController()
{
	bEnableMouseOverEvents = true;
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void ASpaceCombatPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPreparingToMove && bMoving)
	{
		float X, Y;
		GetInputMouseDelta(X, Y);

		MouseX += X;
	}
}


bool ASpaceCombatPlayerController::LeftTurn()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;
		
		if (SelectedShip)
		{
			AAIController* AiController = Cast<AAIController>(SelectedShip->GetController());

			if (AiController)
			{
				FVector Location = SelectedShip->GetActorLocation();

				// Rotate anti-clockwise around existing axis 
				Location = Location.RotateAngleAxis(-90.0f, FVector(0.0f, 0.0f, 1.0f));

				UNavigationSystem* NavSys = GetWorld()->GetNavigationSystem();

				// Set Ai to move player ship
				NavSys->SimpleMoveToLocation(AiController, Location);

				// Update End Rotation of Ship
				Rotation = Rotation.Add(0, -90, 0);

				return true;
			}
		}
	}

	return false;
}

bool ASpaceCombatPlayerController::RightTurn()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			AAIController* AiController = Cast<AAIController>(SelectedShip->GetController());

			if (AiController)
			{
				FVector Location = SelectedShip->GetActorLocation();

				// Rotate anti-clockwise around existing axis 
				Location = Location.RotateAngleAxis(-90.0f, FVector(0.0f, 0.0f, 1.0f));

				// Set Ai to move player ship
				UNavigationSystem::SimpleMoveToLocation(AiController, Location);

				// Update End Rotation of Ship
				Rotation = Rotation.Add(0, 90, 0);

				return true;
			}
		}
	}

	return false;
}

bool ASpaceCombatPlayerController::Fire(AShipPawnBase* TargetShip)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	// TODO refactor to include objects too
	if (GameMode && TargetShip)
	{
		// Hit Target
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;
		if (SelectedShip)
		{
			int32 ActionCost = 0;

			// Calculate Hit Chance
			float HitChance = GameMode->CalculateHitChance(TargetShip);
			int RandomChance = FMath::RandRange(0, 100);

			if (bFireModeIsLasers)
			{
				// Laser Damage
				ActionCost = 4;
			}
			else
			{
				// Missile Damage
				ActionCost = 6;
			}

			if (RandomChance <= HitChance)
			{
				// Hit Target
				HitChance = HitChance / 2;

				// Is a Critical Hit?
				bool CriticalHit = (RandomChance <= HitChance);
				int32 Damage = 0;

				// Log Critical to CombatLog
				if (CriticalHit)
				{
					GameMode->WriteToCombatLog(FText::FromString("Critical Hit!"));
				}

				if (bFireModeIsLasers)
				{
					// Laser Damage
					Damage = SelectedShip->CalculateLaserDamage(CriticalHit);
				}
				else
				{
					// Missile Damage
					Damage = SelectedShip->CalculateMissileDamage(CriticalHit);
				}

				TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
				FDamageEvent DamageEvent(ValidDamageTypeClass);
				
				// Apply Damage
				TargetShip->TakeDamage(Damage, DamageEvent, this, SelectedShip);
			}
			else
			{
				// Missed Target
				FString AttackerName = SelectedShip->GetName();
				FString DefenderName = TargetShip->GetName();
				FString Result = AttackerName + " missed " + DefenderName;

				GameMode->WriteToCombatLog(FText::FromString(Result));
			}

			// Update AP and Reset 
			int32 CurrentActionPoints = SelectedShip->CurrentActionPoints;
			int32 ActionPoints = CurrentActionPoints - ActionCost;
			SelectedShip->CurrentActionPoints = ActionPoints;

			// Update Missile Count
			if (!bFireModeIsLasers)
			{
				SelectedShip->Missiles--;
			}

			bPreparingToFire = false;

			return true;
		}
	}


	return false;
}

bool ASpaceCombatPlayerController::PrepareToFire(bool FiringLasers)
{
	bFireModeIsLasers = FiringLasers;
	bPreparingToFire = true;
	return true;
}

bool ASpaceCombatPlayerController::GetFinalRotation()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		// Hit Target
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			if (MouseX != 0 && (MouseX > 2 || MouseX < -2))
			{
				if (Tile)
				{
					bAdjustFinalRotation = true;

					TArray<UActorComponent*> Components = Tile->GetComponentsByTag(UActorComponent::StaticClass(), FName("Indicator"));
					UStaticMeshComponent* Indicator = Cast<UStaticMeshComponent>(Components[0]);
					UStaticMeshComponent* Mesh = SelectedShip->FindComponentByClass<UStaticMeshComponent>();
		
					FRotator ShipRotation = Mesh->GetComponentRotation();

					if (MouseX >= 1)
					{
						// Rotate Clockwise
						ShipRotation.Add(0, 90, 0);
					}
					else
					{
						// Rotate Anti-Clockwise
						ShipRotation.Add(0, -90, 0);
					}

					// Set Updated Rotations
					Tile->SetActorRotation(ShipRotation);
					Mesh->SetRelativeRotation(ShipRotation);

					// Set Final Rotation
					Rotation = ShipRotation;

					// Refresh MouseX
					MouseX = 0.0f;

					return true;
				}
			}
		}
	}
	
	return false;
}

bool ASpaceCombatPlayerController::RotatePawn(float DeltaTime)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			FRotator ShipRotation = SelectedShip->GetActorRotation();

			// Rotate Pawn Progressively
			FRotator NewRotation = FMath::RInterpTo(ShipRotation, Rotation, DeltaTime, 2.0f);
			SelectedShip->SetActorRelativeRotation(NewRotation);

			// If nearly complete, snap rotation to fit
			if (ShipRotation.Equals(Rotation, 0.1f))
			{
				int32 Z = FMath::RoundToInt(ShipRotation.Yaw);

				SelectedShip->SetActorRotation(FRotator(0, Z, 0));

				return true;
			}
		}
	}

	return false;
}

bool ASpaceCombatPlayerController::IsColliding()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			TArray<AActor*> OverlappingActors;
			SelectedShip->GetOverlappingActors(OverlappingActors);

			bool isOverlapping = false;

			for (AActor* Actor : OverlappingActors)
			{
				if (Cast<AShipPawnBase>(Actor))
				{
					// Overlapping Ship
					isOverlapping = true;
					break;
				}
				if (Cast<ADestructibleObject>(Actor))
				{
					// Overlapping Object
					isOverlapping = true;
					break;
				}
			}

			return isOverlapping;
		}
	}

	// Overlapping
	return true;
}

void ASpaceCombatPlayerController::ResetShip()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			UStaticMeshComponent* StaticMesh = SelectedShip->FindComponentByClass<UStaticMeshComponent>();

			FVector Location = StaticMesh->GetRelativeTransform().GetLocation();

			// Realign Static Mesh to Ship
			StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, Location.Z), false, nullptr, ETeleportType::TeleportPhysics);
			StaticMesh->SetRelativeRotation(SelectedShip->GetActorRotation());
		}
	}
}

void ASpaceCombatPlayerController::SaveShipLocale()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip && Tile)
		{
			// Save Ship Position
			SelectedShip->StartRotation = Rotation;
			SelectedShip->StartLocation = Tile->GetActorLocation();
		}
	}
}
