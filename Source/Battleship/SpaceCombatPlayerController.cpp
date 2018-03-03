#include "Battleship.h"
#include "SpaceCombatPlayerController.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Classes/Components/SplineComponent.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.h"
#include "DestructibleObject.h"
#include "Tile.h"
#include "Ability.h"

ASpaceCombatPlayerController::ASpaceCombatPlayerController()
{
	bEnableMouseOverEvents = true;
	PrimaryActorTick.bCanEverTick = true;

	PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("Path"));
	PathSpline->SetupAttachment(RootComponent);

	LineMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("LineMesh"));
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

bool ASpaceCombatPlayerController::LaunchFighters(TSubclassOf<AShipPawnBase> FighterBlueprint)
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* SelectedShip = GameMode->SelectedShip;

		if (SelectedShip)
		{
			// Check ship has required AP to launch fighter
			if (SelectedShip->CurrentActionPoints < 8)
			{
				return false;
			}

			float Distance = 256.0f;
			if (SelectedShip->Type == EType::Medium)
			{
				Distance = Distance * 2;
			}
			else
			{
				Distance = Distance * 4;
			}

			UWorld* World = GetWorld();

			TArray<FHitResult> HitResults;
			bool Hit = World->LineTraceMultiByChannel(HitResults, SelectedShip->GetActorLocation() * 256.0f, SelectedShip->GetActorForwardVector() * Distance, ECollisionChannel::ECC_Camera);

			if (Hit)
			{
				for (FHitResult HitResult : HitResults)
				{
					ATile* IsTile = Cast<ATile>(HitResult.GetActor());

					if (IsTile)
					{
						Hit = false;
					}
				}
			}
	
			if (!Hit && SelectedShip->Fighters)
			{
				FVector Location = SelectedShip->GetActorLocation();

				AShipPawnBase* Fighter = World->SpawnActor<AShipPawnBase>(FighterBlueprint);

				if (Fighter)
				{	
					// Setup Fighter
					Fighter->Instigator = SelectedShip;

					FVector NewLocation = Location + (SelectedShip->GetActorForwardVector() * Distance);

					Fighter->SetActorLocation(NewLocation);
					Fighter->SetActorRotation(SelectedShip->GetActorRotation());

					GameMode->ShipArray.Add(Fighter);

					// Take AP from Parent Ship
					SelectedShip->CurrentActionPoints -= 8;


					//FString OfficerName = Fighter->NavigationOfficer->CrewName;
					FString Result = Fighter->Name + " have launched successfully, Admiral";

					GameMode->WriteToCombatLog(FText::FromString(Result));

					return true;
				}
			}

			//FString OfficerName = SelectedShip->TacticsOfficer->CrewName;
			FString Result = "We can't launch our fighters at this time, Admiral";

			GameMode->WriteToCombatLog(FText::FromString(Result));
		}
	}

	return false;
}

bool ASpaceCombatPlayerController::CollectFighter()
{
	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		AShipPawnBase* Fighter = Cast<AShipPawnBase>(GameMode->SelectedShip);

		if (Fighter)
		{
			APlayerShipPawnBase* Parent = Cast<APlayerShipPawnBase>(Fighter->Instigator);

			if (Parent)
			{
				// Check Distance between Parent Ship and Fighter
				float Distance = 300.0f;
				if (Parent->Type == EType::Medium)
				{
					Distance = Distance * 2;
				}
				else
				{
					Distance = Distance * 4;
				}
				float ShipDistance = FVector::Dist(Fighter->GetActorLocation(), Parent->GetActorLocation());

				// If within distance and still alive, collect the fighter
				if (ShipDistance <= Distance && Fighter->CurrentHitPoints > 0.0f && Fighter->CurrentActionPoints >= 5)
				{
					// TODO add turn timer?
					// Replenish Parent Supply
					Parent->Fighters++;

					Fighter->ForceTurnEnd = true;

					// TODO add animation?
					// Remove Fighter
					Fighter->SetLifeSpan(0.1f);

					FString OfficerName = Parent->TacticsOfficer->CrewName;
					FString Result = OfficerName + ": Successfully retrieved " + Fighter->Name + ", Admiral";

					GameMode->WriteToCombatLog(FText::FromString(Result));

					return true;
				}
			}

			//FString OfficerName = Fighter->NavigationOfficer->CrewName;
			FString Result = "We can't dock, Admiral!";

			GameMode->WriteToCombatLog(FText::FromString(Result));
		}
	}

	return false;
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
				SelectedShip->NewRotation = SelectedShip->NewRotation.Add(0, -90, 0);

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
				SelectedShip->NewRotation = SelectedShip->NewRotation.Add(0, 90, 0);

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
			// Check Subsystems are operational
			if (!SelectedShip->Subsystems.Guns)
			{
				//FString OfficerName = SelectedShip->TacticsOfficer->CrewName;
				FString Result = "Our weapons are offline.";

				GameMode->WriteToCombatLog(FText::FromString(Result));

				bPreparingToFire = false;

				return false;
			}

			int32 ActionCost = 0;

			// Calculate Hit Chance
			float HitChance = GameMode->CalculateHitChance(TargetShip);
			int RandomChance = FMath::RandRange(0, 100);

			if (bFireModeIsLasers)
			{
				// Laser Damage
				if (SelectedShip->Type == EType::Large)
				{
					ActionCost = 4;
				}
				else
				{
					ActionCost = 5;
				}
			}
			else
			{
				// Missile Damage
				if (SelectedShip->Type == EType::Large)
				{
					ActionCost = 6;
				}
				else
				{
					ActionCost = 8;
				}
			}

			if (RandomChance <= HitChance)
			{
				// Hit Target
				HitChance = HitChance / 2;

				// Is a Critical Hit?
				bool CriticalHit = (RandomChance <= HitChance);
				int32 Damage = SelectedShip->AttackBonus;

				// Log Critical to CombatLog
				if (CriticalHit)
				{
					GameMode->WriteToCombatLog(FText::FromString("Critical Hit!"));
				}

				if (bFireModeIsLasers)
				{
					// Laser Damage
					Damage += SelectedShip->CalculateLaserDamage(CriticalHit);
				}
				else
				{
					// Missile Damage
					Damage += SelectedShip->CalculateMissileDamage(CriticalHit);
				}

				// Adjust by Gun Subsystems Status
				Damage = FMath::FloorToInt(Damage * SelectedShip->Subsystems.Guns);

				TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
				FDamageEvent DamageEvent(ValidDamageTypeClass);
				
				// Apply Damage
				// TODO Change to Damage event?
				if (!bFireAtSubsystems)
				{
					TargetShip->TakeDamage(Damage, DamageEvent, this, SelectedShip);
				}
				else
				{
					float SubsystemDamage =  float(Damage) / 100.0f;
					FString Subsystem;

					if (bFireAtScanners)
					{
						TargetShip->Subsystems.Scanners -= SubsystemDamage;
						Subsystem = "Scanners";
					}

					if (bFireAtGuns)
					{
						TargetShip->Subsystems.Guns -= SubsystemDamage;
						Subsystem = "Guns";
					}

					if (bFireAtEngines)
					{
						TargetShip->Subsystems.Engine -= SubsystemDamage;
						Subsystem = "Engines";
					}

					if (bFireAtShields)
					{
						TargetShip->Subsystems.ShieldGen -= SubsystemDamage;
						Subsystem = "Shield Generator";
					}

					FString AttackerName = SelectedShip->Name;
					FString DefenderName = TargetShip->Name;
					FString Result = AttackerName + " damaged " + DefenderName + " " + Subsystem;

					GameMode->WriteToCombatLog(FText::FromString(Result));
				}
			}
			else
			{
				// Missed Target
				FString AttackerName = SelectedShip->Name;
				FString DefenderName = TargetShip->Name;
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
			bFireAtSubsystems = false;
			bFireAtScanners = bFireAtGuns = bFireAtEngines = bFireAtShields = false;

			return true;
		}
	}


	return false;
}

bool ASpaceCombatPlayerController::PrepareToFire(bool FiringLasers, bool FireSubsystems)
{
	bFireAtSubsystems = FireSubsystems;
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
					SelectedShip->NewRotation = ShipRotation;
					
					if (SelectedShip->Type == EType::Large)
					{
						Tile->RotCost = 6;
					}
					else if (SelectedShip->Type == EType::Medium)
					{
						Tile->RotCost = 3;
					}
					else
					{
						Tile->RotCost = 1;
					}

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
			FRotator NewRotation = FMath::RInterpTo(ShipRotation, SelectedShip->NewRotation, DeltaTime, 2.0f);
			SelectedShip->SetActorRelativeRotation(NewRotation);

			// If nearly complete, snap rotation to fit
			if (ShipRotation.Equals(SelectedShip->NewRotation, 0.1f))
			{
				int32 Z = FMath::RoundToInt(ShipRotation.Yaw);

				SelectedShip->SetActorRotation(FRotator(0, Z, 0));
				Tile->RotCost = 0;

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
			StaticMesh->SetRelativeRotation(SelectedShip->StartRotation);
		
		
		}

		if (Tile)
		{
			Tile->ClearPath();
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
			SelectedShip->StartRotation = SelectedShip->NewRotation;
			SelectedShip->StartLocation = Tile->GetActorLocation();
		}
	}
}
