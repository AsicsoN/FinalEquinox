#include "Battleship.h"
#include "SpaceCombatPlayerController.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Classes/Components/SplineComponent.h"
#include "SpaceCombatGameMode.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.h"
#include "DestructibleObject.h"
#include "Tile.h"
#include "Ability.h"
#include "SpaceCombatDamageType.h"

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

			bool Hit = true;

			for (TActorIterator<AActor> ActorItr(World); ActorItr; ++ActorItr)
			{
				if (FVector::Distance(ActorItr->GetActorLocation(), SelectedShip->GetActorLocation() + (SelectedShip->GetActorForwardVector() * Distance)) < 100.0f)
				{
					if (*ActorItr == SelectedShip || Cast<ATile>(*ActorItr))
					{
						Hit = false;
					}
					else
					{
						UE_LOG(LogTemp, Error, TEXT("Hit: %s"), *ActorItr->GetName());

						Hit = true;
						break;
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

				UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

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
				UNavigationSystemV1::SimpleMoveToLocation(AiController, Location);

				// Update End Rotation of Ship
				SelectedShip->NewRotation = SelectedShip->NewRotation.Add(0, 90, 0);

				return true;
			}
		}
	}

	return false;
}

bool ASpaceCombatPlayerController::Fire_Implementation(AShipPawnBase* TargetShip)
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

				FDamageEvent DamageEvent;

				if (bFireModeIsLasers)
				{
					// Laser Damage
					Damage += SelectedShip->CalculateLaserDamage(CriticalHit);

					if (TargetShip->Subsystems.ShieldGen && TargetShip->CurrentShieldHitPoints > 0)
					{
						DamageEvent.DamageTypeClass = ULaserDamage::StaticClass();
					}
					else
					{
						DamageEvent.DamageTypeClass = UHullDamage::StaticClass();
					}
				}
				else
				{
					// Missile Damage
					Damage += SelectedShip->CalculateMissileDamage(CriticalHit);
					DamageEvent.DamageTypeClass = UMissileDamage::StaticClass();
				}

				// Adjust by Ship Position
				Damage = AddSideModifier(SelectedShip, TargetShip, Damage);

				// Adjust by Gun Subsystems Status
				Damage = FMath::FloorToInt(Damage * SelectedShip->Subsystems.Guns);

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
						TargetShip->Subsystems.Scanners = FMath::Clamp<float>(TargetShip->Subsystems.Scanners - SubsystemDamage, 0.0, 1.0f);
						Subsystem = "Scanners";
					}

					if (bFireAtGuns)
					{
						TargetShip->Subsystems.Guns = FMath::Clamp<float>(TargetShip->Subsystems.Guns - SubsystemDamage, 0.0, 1.0f);
						Subsystem = "Guns";
					}

					if (bFireAtEngines)
					{
						TargetShip->Subsystems.Engine = FMath::Clamp<float>(TargetShip->Subsystems.Engine - SubsystemDamage, 0.0, 1.0f);
						Subsystem = "Engines";
					}

					if (bFireAtShields)
					{
						TargetShip->Subsystems.ShieldGen = FMath::Clamp<float>(TargetShip->Subsystems.ShieldGen - SubsystemDamage, 0.0, 1.0f);
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

float ASpaceCombatPlayerController::AddSideModifier(const AShipPawnBase* SelectedShip, const AShipPawnBase* TargetShip, const float Damage)
{
	// Calculate LookAt Rotation
	FRotator LookRot = (TargetShip->GetActorLocation() - SelectedShip->GetActorLocation()).Rotation();

	// Apply Correct Modifier
	float Mod;
	if (LookRot.Yaw > 135.0f)
	{
		// Flanking Target (Behind)
		Mod = RearDamageMod;
	}
	else if (LookRot.Yaw > 45.0f && LookRot.Yaw <= 135.0f)
	{
		// Side of Target
		Mod = SideDamageMod;
	}
	else
	{
		// Facing Target
		Mod = FrontDamageMod;
	}

	return Damage * Mod;
}

bool ASpaceCombatPlayerController::PrepareToFire(bool FiringLasers, bool FireSubsystems)
{
	bFireAtSubsystems = FireSubsystems;
	bFireModeIsLasers = FiringLasers;
	bPreparingToFire = true;
	return true;
}

bool ASpaceCombatPlayerController::ScanShip_Implementation(AShipPawnBase* TargetShip)
{
	if (!bPreparingToScan || !TargetShip)
	{
		return false;
	}

	ASpaceCombatGameMode* GameMode = Cast<ASpaceCombatGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		APlayerShipPawnBase* SelectedShip = Cast<APlayerShipPawnBase>(GameMode->SelectedShip);

		FString SOfficerName = SelectedShip->ScienceOfficer->CrewName;
		FString DefenderName = TargetShip->Name;
		FString Result = "";

		// Check Our Scanners are functional
		if (!SelectedShip || !SelectedShip->Subsystems.Scanners)
		{
			Result = SOfficerName + ": We are unable to scan at this time!";
			GameMode->WriteToCombatLog(FText::FromString(Result));
			return false;
		}

		if (SelectedShip->CurrentActionPoints < 5)
		{
			Result = SOfficerName + ": We can't afford to scan at this time!";
			GameMode->WriteToCombatLog(FText::FromString(Result));
			return false;
		}

		// Deduct Scan Cost
		SelectedShip->CurrentActionPoints -= 5;

		// Calculate Scan Resistance
		float Resistance = (TargetShip->PowerLevel * 5) + TargetShip->CurrentShieldHitPoints;

		// Calculate Scan Hit
		float X = ((50) - (Resistance)) + ((5 + SelectedShip->Science) * 5);

		float Y = (100 - X) / FMath::RandRange(1, 100);

		if (Y < 1)
		{
			// Calculate Scan Crit
			X = FMath::RandRange(1, 100) / ((5 + SelectedShip->Science) * 5);

			bool bCrit = false;
			if (X < 1)
			{
				bCrit = true;
			}

			// Set Target Ship to Scanned
			TargetShip->bScanned = true;

			if (!bCrit)
			{
				Result = SOfficerName + ": We have scanned the enemy vessel '" + DefenderName + "'";
			}
			else
			{
				Result = SOfficerName + ": We have identified weakness in the enemy vessel '" + DefenderName + "'";
				SelectedShip->ScannedShips.Add(TargetShip);
			}

			GameMode->WriteToCombatLog(FText::FromString(Result));

			return true;
		}
		else
		{
			Result = SOfficerName + ": We failed to scan the enemy ship '" + DefenderName + "'";

			GameMode->WriteToCombatLog(FText::FromString(Result));

			return false;
		}
	}
	return false;
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
			if (Tile)
			{
				bAdjustFinalRotation = true;

				TArray<UActorComponent*> Components = Tile->GetComponentsByTag(UActorComponent::StaticClass(), FName("Indicator"));
				UStaticMeshComponent* Indicator = Cast<UStaticMeshComponent>(Components[0]);
				UStaticMeshComponent* Mesh = SelectedShip->FindComponentByClass<UStaticMeshComponent>();
		
				FRotator ShipRotation = Mesh->GetComponentRotation();

				// Rotate Clockwise
				ShipRotation.Add(0, 90, 0);

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
			TArray<UActorComponent*> Meshes = SelectedShip->GetComponentsByTag(UStaticMeshComponent::StaticClass(), FName("Ship"));

			if (!Meshes.Num())
			{
				return false;
			}

			UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(Meshes[0]);

			TArray<AActor*> OverlappingActors;
			Mesh->GetOverlappingActors(OverlappingActors, ADestructibleObject::StaticClass());

			TArray<AActor*> OverlappingShips;
			Mesh->GetOverlappingActors(OverlappingShips, AShipPawnBase::StaticClass());
			if (OverlappingShips.Contains(SelectedShip))
			{
				OverlappingShips.Remove(SelectedShip);
			}

			bool isOverlapping = false;
			if (OverlappingActors.Num() || OverlappingShips.Num())
			{
				isOverlapping = true;
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
			StaticMesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, Location.Z), FRotator::ZeroRotator, false, nullptr, ETeleportType::TeleportPhysics);
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
