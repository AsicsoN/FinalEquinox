

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

void MoraleSystem::ApplyTravelMoraleLoss(const TArray<APlayerShipPawnBase*>& Ships)
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
		for (APlayerShipPawnBase* Ship : Ships)
		{
			if (!Ship)
			{
				continue;
			}

			ReduceShipMorale(EMoraleType::GENERAL, Ship, Loss);
		}
	}
}

void MoraleSystem::ApplyShipMoraleLoss(const TArray<APlayerShipPawnBase*>& Ships)
{
	// Randomly Generate the Morale Loss
	int32 Loss = (FMath::RandRange(1, 20) <= 8) ? 1 : 0;

	// Apply Modifier if we have lost morale
	if (Loss)
	{
		for (APlayerShipPawnBase* Ship : Ships)
		{
			if (!Ship)
			{
				continue;
			}

			ReduceShipMorale(EMoraleType::GENERAL, Ship, Loss);
		}
	}
}

void MoraleSystem::ApplyShipMoraleGain(const TArray<APlayerShipPawnBase*>& Ships)
{
	// Randomly Generate the Morale Gain
	int32 Gain = (FMath::RandRange(1, 20) >= 16) ? 1 : 0;

	// Apply Modifier if we have gained morale
	if (Gain)
	{
		for (APlayerShipPawnBase* Ship : Ships)
		{
			if (!Ship)
			{
				continue;
			}

			ImproveShipMorale(EMoraleType::GENERAL, Ship, Gain);
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

FString MoraleSystem::GetShipMoraleDescriptor(APlayerShipPawnBase* Ship)
{
	int MoraleValue = GetShipMoraleValue(Ship);

	return GetMoraleDescriptor(MoraleValue);
}

int32 MoraleSystem::GetShipMoraleValue(APlayerShipPawnBase* Ship)
{
	const TArray<UCrew*> Crew = Ship->GetCrew();

	int MoraleValue = 0;

	for (UCrew* Member : Crew)
	{
		if (!Member)
		{
			continue;
		}

		MoraleValue += Member->GetCurrentMorale();
	}

	return MoraleValue / Crew.Num();
}

FString MoraleSystem::GetFleetMoraleDescriptor(const TArray<APlayerShipPawnBase*>& Ships)
{
	int MoraleValue = GetFleetMoraleValue(Ships);

	return GetMoraleDescriptor(MoraleValue);
}

int32 MoraleSystem::GetFleetMoraleValue(const TArray<APlayerShipPawnBase*>& Ships)
{
	int MoraleValue = 0;

	for (APlayerShipPawnBase* Ship : Ships)
	{
		if (!Ship)
		{
			continue;
		}

		MoraleValue += GetShipMoraleValue(Ship);
	}

	return MoraleValue / Ships.Num();
}

FString MoraleSystem::GetMoraleDescriptor(int32 MoraleValue)
{
	FString Description;
	if (MoraleValue <= 20 && MoraleValue > 15)
	{
		Description = "Content";
	}
	else if (MoraleValue <= 15 && MoraleValue > 10)
	{
		Description = "Disgruntled";
	}
	else if (MoraleValue <= 10 && MoraleValue > 5)
	{
		Description = "Upset";
	}
	else
	{
		Description = "Furious";
	}

	return Description;
}
