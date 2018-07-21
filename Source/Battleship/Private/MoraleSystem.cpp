

#include "Battleship.h"
#include "MoraleSystem.h"
#include "PlayerShipPawnBase.h"
#include "Crew.h"

MoraleSystem::MoraleSystem()
{

}

MoraleSystem::~MoraleSystem()
{

}

void MoraleSystem::ApplyDialogueMorale(EMoraleType PositiveType, EMoraleType NegativeTypeOne, EMoraleType NegativeTypeTwo, APlayerShipPawnBase* Ship, const int32 PositiveModifier, const int32 NegativeModifier)
{
	if (!Ship)
	{
		return;
	}

	for (UCrew* Crew : Ship->GetCrew())
	{
		if (!Crew)
		{
			continue;
		}

		// Apply Dialogue Modifiers
		ImproveCrewMorale(PositiveType, Crew, PositiveModifier);
		ReduceCrewMorale(NegativeTypeOne, Crew, NegativeModifier);
		ReduceCrewMorale(NegativeTypeTwo, Crew, NegativeModifier);
	}
}

void MoraleSystem::ApplyTravelMoraleLoss(const TArray<AShipPawnBase*>& Ships)
{
	// Randomly Generate the Morale Loss
	int32 Chance = FMath::RandRange(1, 20);
	
	int32 Loss = 0;
	if (Chance <= 10)
	{
		Loss++;

		if (Chance <= 4)
		{
			Loss++;
		}
	}

	// Apply Modifier if we have lost morale
	if (Loss)
	{
		for (AShipPawnBase* Ship : Ships)
		{
			APlayerShipPawnBase* PlayerShip = Cast<APlayerShipPawnBase>(Ship);

			if (!PlayerShip)
			{
				continue;
			}

			ReduceShipMorale(EMoraleType::GENERAL, PlayerShip, Loss);
		}
	}
}

void MoraleSystem::ApplyShipMoraleLoss(const TArray<AShipPawnBase*>& Ships)
{
	// Randomly Generate the Morale Loss
	int32 Loss = (FMath::RandRange(1, 20) <= 8) ? 1 : 0;

	// Apply Modifier if we have lost morale
	if (Loss)
	{
		for (AShipPawnBase* Ship : Ships)
		{
			APlayerShipPawnBase* PlayerShip = Cast<APlayerShipPawnBase>(Ship);

			if (!PlayerShip)
			{
				continue;
			}

			ReduceShipMorale(EMoraleType::GENERAL, PlayerShip, Loss);
		}
	}
}

void MoraleSystem::ApplyShipMoraleGain(const TArray<AShipPawnBase*>& Ships)
{
	// Randomly Generate the Morale Gain
	int32 Gain = (FMath::RandRange(1, 20) >= 16) ? 1 : 0;

	// Apply Modifier if we have gained morale
	if (Gain)
	{
		for (AShipPawnBase* Ship : Ships)
		{
			APlayerShipPawnBase* PlayerShip = Cast<APlayerShipPawnBase>(Ship);

			if (!PlayerShip)
			{
				continue;
			}

			ImproveShipMorale(EMoraleType::GENERAL, PlayerShip, Gain);
		}
	}
}

void MoraleSystem::ReduceShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Reduction)
{
	if (!Ship)
	{
		return;
	}

	for (UCrew* Crew : Ship->GetCrew())
	{
		if (!Crew)
		{
			continue;
		}

		// Apply Negative Modifiers
		ReduceCrewMorale(Type, Crew, Reduction);
	}
}

void MoraleSystem::ImproveShipMorale(EMoraleType Type, APlayerShipPawnBase* Ship, const int32 Additive)
{
	if (!Ship)
	{
		return;
	}

	for (UCrew* Crew : Ship->GetCrew())
	{
		if (!Crew)
		{
			continue;
		}

		// Apply Positive Modifiers
		ImproveCrewMorale(Type, Crew, Additive);
	}
}

void MoraleSystem::ReduceCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Reduction)
{
	int32 CurrentMorale;

	if (Type == EMoraleType::GENERAL)
	{
		CurrentMorale = Crew->Morale.General;
		CurrentMorale = FMath::Clamp(CurrentMorale - Reduction, -15, 15);
		Crew->Morale.General = CurrentMorale;
	}
	else if (Type == EMoraleType::FEAR)
	{
		CurrentMorale = Crew->Morale.Fear;
		CurrentMorale = FMath::Clamp(CurrentMorale - Reduction, -15, 15);
		Crew->Morale.Fear = CurrentMorale;
	} 
	else if (Type == EMoraleType::RESPECT)
	{
		CurrentMorale = Crew->Morale.Respect;
		CurrentMorale = FMath::Clamp(CurrentMorale - Reduction, -15, 15);
		Crew->Morale.Respect = CurrentMorale;
	}
	else if (Type == EMoraleType::LOVE)
	{
		CurrentMorale = Crew->Morale.Love;
		CurrentMorale = FMath::Clamp(CurrentMorale - Reduction, -15, 15);
		Crew->Morale.Love = CurrentMorale;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoraleSystem::ReduceCrewMorale: We have attempted to modify morale without a type - please double check"));
	}
}

void MoraleSystem::ImproveCrewMorale(EMoraleType Type, UCrew* Crew, const int32 Additive)
{
	int32 CurrentMorale;

	if (Type == EMoraleType::GENERAL)
	{
		CurrentMorale = Crew->Morale.General;
		CurrentMorale = FMath::Clamp(CurrentMorale + Additive, -15, 15);
		Crew->Morale.General = CurrentMorale;
	}
	else if (Type == EMoraleType::FEAR)
	{
		CurrentMorale = Crew->Morale.Fear;
		CurrentMorale = FMath::Clamp(CurrentMorale + Additive, -15, 15);
		Crew->Morale.Fear = CurrentMorale;
	}
	else if (Type == EMoraleType::RESPECT)
	{
		CurrentMorale = Crew->Morale.Respect;
		CurrentMorale = FMath::Clamp(CurrentMorale + Additive, -15, 15);
		Crew->Morale.Respect = CurrentMorale;
	}
	else if (Type == EMoraleType::LOVE)
	{
		CurrentMorale = Crew->Morale.Love;
		CurrentMorale = FMath::Clamp(CurrentMorale + Additive, -15, 15);
		Crew->Morale.Love = CurrentMorale;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoraleSystem::ReduceCrewMorale: We have attempted to modify morale without a type - please double check"));
	}
}
