#include "Battleship.h"
#include "PlayerShipPawnBase.h"

// Calculate ship stats
void APlayerShipPawnBase::Instantiate()
{
	// Super::Instantiate();

	Tactics = (Captain->Tactics * 0.4) + (TacticsOfficer->Tactics * 0.4) + (NavigationOfficer->Tactics * 0.2);
	Navigation = (NavigationOfficer->Navigation * 0.6) + (Captain->Navigation * 0.3) + (TacticsOfficer->Navigation * 0.1);
	Leadership = (Captain->Leadership * 0.6) + (TacticsOfficer->Leadership * 0.2) + (NavigationOfficer->Leadership * 0.2);
	Gunnery = (TacticsOfficer->Gunnery * 0.7) + (Captain->Gunnery * 0.3);
	Communication = (Captain->Communication * 0.5) + (NavigationOfficer->Communication * 0.25) + (TacticsOfficer->Communication * 0.25);
	ShieldRepair = (ScienceOfficer->ShieldRepair * 0.5) + (Engineer->ShieldRepair * 0.4) + (Captain->ShieldRepair * 0.1);
	HullRepair = (Engineer->Engineering * 0.8) + (Captain->Engineering * 0.2);
	SubsystemRepair = (Engineer->SubsystemRepair * 0.6) + (Captain->SubsystemRepair * 0.1) + (ScienceOfficer->SubsystemRepair * 0.3);
	Science = (ScienceOfficer->Science * 0.8) + (Captain->Science * 0.2);

	Initiative = Navigation + FMath::RandRange(1, 6) + Speed + Communication;
	Initiative = FMath::Clamp(Initiative, 0, 40);

	if (Type != EType::Small)
	{
		// Normal Ship Calculations
		ActionPoints = 5 + Tactics + FMath::RandRange(1, 8) + PowerLevel + Leadership + 4;
		ActionPoints = FMath::Clamp(ActionPoints, 0, 40);

		MovementPoints = Navigation + PowerLevel + FMath::RandRange(1, 8) + 4 + Tactics;
		MovementPoints = FMath::Clamp(MovementPoints, 0, 39);
	}
	else
	{
		// Fighter Calculation
		ActionPoints = FighterSkill + Tactics + FMath::RandRange(1, 6);
		ActionPoints = FMath::Clamp(ActionPoints, -3, 21);

		MovementPoints = FighterSkill + Communication + FMath::RandRange(1, 6);
		MovementPoints = FMath::Clamp(MovementPoints, -3, 21);
	}

	CurrentActionPoints = ActionPoints;
	CurrentMovementPoints = MovementPoints;

	CurrentHitPoints = HitPoints;
	CurrentShieldHitPoints = ShieldHitPoints;
}
