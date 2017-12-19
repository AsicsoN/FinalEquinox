

#include "Battleship.h"
#include "CharacterSheet.h"
#include "ShipPawnBase.h"

UCharacterSheet::UCharacterSheet()
{

}

void UCharacterSheet::SetCharacterOption(FString option)
{
	if (option == "option_human")
	{
		Race = ERace::Human;
	}
	else if (option == "option_malderian")
	{
		Race = ERace::Malderian;
	}
	else if (option == "option_krum")
	{
		Race = ERace::Krum;
	}
	else if (option == "option_male")
	{
		GenderIsMale = true;
	}
	else if (option == "option_female")
	{
		GenderIsMale = false;
	}
	else if (option == "background_outerworlds")
	{
		Background = ECharacterBackground::Outerworlds;
		Barter++;
		ProjectileWeapons++;
	}
	else if (option == "background_innerworlds")
	{
		Background = ECharacterBackground::Innerworlds;
		Culture++;
		Persuasion++;
	}
	else if (option == "background_noble")
	{
		Background = ECharacterBackground::Noble;
		Leadership++;
		Persuasion++;
	}
	else if (option == "background_military")
	{
		Background = ECharacterBackground::Military;
		Tactics++;
		Navigation++;
	}
	else if (option == "background_trader")
	{
		Background = ECharacterBackground::Trader;
		Barter += 2;
	}
	else if (option == "option_gunnery")
	{
		Gunnery += 2;
		Explosives++;
	}
	else if (option == "option_communications")
	{
		Barter++;
		Deception++;
		Persuasion++;
	}
	else if (option == "option_Navigation")
	{
		Pilot += 2;
		Gunnery++;
	}
	else if (option == "option_navigation")
	{
		Navigation += 2;
		Tactics++;
	}
	else if (option == "option_Engineering")
	{
		Engineering += 2;
		Engineering++;
	}
	else if (option == "option_workedhard")
	{
		Science++;
		Engineering++;
		Navigation++;
		Pilot++;
		Leadership++;
		Barter--;
		Deception--;
	}
	else if (option == "option_politics")
	{
		Persuasion += 2;
		Culture += 2;
		Leadership--;
		Tactics--;
	}
	else if (option == "option_scientist")
	{
		Science += 3;
		Leadership--;
	}
	else if (option == "option_celebrity")
	{
		Leadership += 2;
		Barter += 2;
		Navigation--;
	}
	else if (option == "option_victory")
	{
		Leadership += 3;
		Tactics += 2;
		Culture--;
		Barter--;
		Deception--;
	}
	else if (option == "option_connected")
	{
		Leadership += 2;
		Persuasion += 3;
		Engineering--;
		Science--;
		Leadership--;
	}
	else if (option == "option_traitor")
	{
		Deception += 3;
		Persuasion++;
		Tactics--;
		Leadership--;
	}
	else if (option == "asked_about_edward")
	{
		AskedAboutEdward = true;
	}


}

bool UCharacterSheet::GetCharacterOption(FString option)
{
	if (option.StartsWith("!"))
	{
		option.RemoveAt(0);
		return !GetCharacterOption(option);
	}
	else
	{
		if (option == "option_human")
		{
			if (Race == ERace::Human)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (option == "option_malderian")
		{
			if (Race == ERace::Malderian)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (option == "option_krum")
		{
			if (Race == ERace::Krum)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (option == "option_male")
		{
			if (GenderIsMale)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (option == "option_female")
		{
			if (!GenderIsMale)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (option == "asked_about_edward")
		{
			return AskedAboutEdward;
		}
		return false;
	}
}

void UCharacterSheet::SetDefaultFleet(TSubclassOf<AShipPawnBase> BattleshipPawnClass, TSubclassOf<AShipPawnBase> DestroyerPawnClass)
{
	AShipPawnBase* flagship = BattleshipPawnClass.GetDefaultObject();
	flagship->Name = "GCS Odysseus";
	flagship->Type = EType::Large;
	flagship->Captain = NewObject<UCrew>();
	flagship->NavigationOfficer = NewObject<UCrew>();
	flagship->TacticsOfficer = NewObject<UCrew>();
	flagship->ScienceOfficer = NewObject<UCrew>();
	flagship->Engineer = NewObject<UCrew>();
	flagship->CAG = NewObject<UCrew>();

	flagship->Captain->CrewName = "Ixa Rkeok";
	flagship->Captain->CrewRace = ERace::Malderian;
	flagship->Captain->IsMale = false;
	flagship->Captain->Leadership = 2;
	flagship->Captain->Navigation = -2;
	flagship->Captain->Gunnery = -3;
	flagship->Captain->Engineering = 2;
	flagship->Captain->Science = 1;
	flagship->Captain->Tactics = 1;
	flagship->Captain->Communication = 1;
	flagship->Captain->SubsystemRepair = -1;
	flagship->Captain->ShieldRepair = -1;

	flagship->NavigationOfficer->CrewName = "Edvin Tjaard";
	flagship->NavigationOfficer->CrewRace = ERace::Human;
	flagship->NavigationOfficer->IsMale = true;
	flagship->NavigationOfficer->Leadership = 1;
	flagship->NavigationOfficer->Navigation = 4;
	flagship->NavigationOfficer->Gunnery = -1;
	flagship->NavigationOfficer->Engineering = 1;
	flagship->NavigationOfficer->Science = -2;
	flagship->NavigationOfficer->Tactics = 1;
	flagship->NavigationOfficer->Communication = 1;
	flagship->NavigationOfficer->SubsystemRepair = -1;
	flagship->NavigationOfficer->ShieldRepair = -1;

	flagship->TacticsOfficer->CrewName = "Tu'Vol Strogonar";
	flagship->TacticsOfficer->CrewRace = ERace::Krum;
	flagship->TacticsOfficer->IsMale = true;
	flagship->TacticsOfficer->Leadership = 1;
	flagship->TacticsOfficer->Navigation = -3;
	flagship->TacticsOfficer->Gunnery = 1;
	flagship->TacticsOfficer->Engineering = 0;
	flagship->TacticsOfficer->Science = -1;
	flagship->TacticsOfficer->Tactics = 3;
	flagship->TacticsOfficer->Communication = 0;
	flagship->TacticsOfficer->SubsystemRepair = 0;
	flagship->TacticsOfficer->ShieldRepair = 0;

	flagship->ScienceOfficer->CrewName = "Mar-Tun";
	flagship->ScienceOfficer->CrewRace = ERace::Malderian;
	flagship->ScienceOfficer->IsMale = true;
	flagship->ScienceOfficer->Leadership = 0;
	flagship->ScienceOfficer->Navigation = 0;
	flagship->ScienceOfficer->Gunnery = 0;
	flagship->ScienceOfficer->Engineering = 0;
	flagship->ScienceOfficer->Science = 4;
	flagship->ScienceOfficer->Tactics = 1;
	flagship->ScienceOfficer->Communication = 1;
	flagship->ScienceOfficer->SubsystemRepair = -1;
	flagship->ScienceOfficer->ShieldRepair = -1;

	flagship->Engineer->CrewName = "Sheldon Matthaus";
	flagship->Engineer->CrewRace = ERace::Human;
	flagship->Engineer->IsMale = true;
	flagship->Engineer->Leadership = 0;
	flagship->Engineer->Navigation = 0;
	flagship->Engineer->Gunnery = 0;
	flagship->Engineer->Engineering = 6;
	flagship->Engineer->Science = 0;
	flagship->Engineer->Tactics = 1;
	flagship->Engineer->Communication = 1;
	flagship->Engineer->SubsystemRepair = -1;
	flagship->Engineer->ShieldRepair = -1;

	Fleet.Add(flagship);

	AShipPawnBase* destroyer = DestroyerPawnClass.GetDefaultObject();
	destroyer->Name = "GCS Selene";
	destroyer->Type = EType::Medium;
	destroyer->Captain = NewObject<UCrew>();
	destroyer->NavigationOfficer = NewObject<UCrew>();
	destroyer->TacticsOfficer = NewObject<UCrew>();
	destroyer->ScienceOfficer = NewObject<UCrew>();
	destroyer->Engineer = NewObject<UCrew>();
	destroyer->CAG = NewObject<UCrew>();

	destroyer->Captain->CrewName = "Ixa Rkeok";
	destroyer->Captain->CrewRace = ERace::Malderian;
	destroyer->Captain->IsMale = false;
	destroyer->Captain->Leadership = 0;
	destroyer->Captain->Navigation = 0;
	destroyer->Captain->Gunnery = 0;
	destroyer->Captain->Engineering = 0;
	destroyer->Captain->Science = 0;
	destroyer->Captain->Tactics = 1;
	destroyer->Captain->Communication = 1;
	destroyer->Captain->SubsystemRepair = -1;
	destroyer->Captain->ShieldRepair = -1;


	destroyer->NavigationOfficer->CrewName = "Edvin Tjaard";
	destroyer->NavigationOfficer->CrewRace = ERace::Human;
	destroyer->NavigationOfficer->IsMale = true;
	destroyer->NavigationOfficer->Leadership = 0;
	destroyer->NavigationOfficer->Navigation = 2;
	destroyer->NavigationOfficer->Gunnery = 0;
	destroyer->NavigationOfficer->Engineering = 0;
	destroyer->NavigationOfficer->Science = 0;
	destroyer->NavigationOfficer->Tactics = 1;
	destroyer->NavigationOfficer->Communication = 1;
	destroyer->NavigationOfficer->SubsystemRepair = -1;
	destroyer->NavigationOfficer->ShieldRepair = -1;


	destroyer->TacticsOfficer->CrewName = "Tu'Vol Strogonar";
	destroyer->TacticsOfficer->CrewRace = ERace::Krum;
	destroyer->TacticsOfficer->IsMale = true;
	destroyer->TacticsOfficer->Leadership = 0;
	destroyer->TacticsOfficer->Navigation = 0;
	destroyer->TacticsOfficer->Gunnery = 0;
	destroyer->TacticsOfficer->Engineering = 0;
	destroyer->TacticsOfficer->Science = 0;
	destroyer->TacticsOfficer->Tactics = 3;
	destroyer->TacticsOfficer->Communication = 1;
	destroyer->TacticsOfficer->SubsystemRepair = -1;
	destroyer->TacticsOfficer->ShieldRepair = -1;


	destroyer->ScienceOfficer->CrewName = "Mar-Tun";
	destroyer->ScienceOfficer->CrewRace = ERace::Malderian;
	destroyer->ScienceOfficer->IsMale = true;
	destroyer->ScienceOfficer->Leadership = 0;
	destroyer->ScienceOfficer->Navigation = 0;
	destroyer->ScienceOfficer->Gunnery = 0;
	destroyer->ScienceOfficer->Engineering = 0;
	destroyer->ScienceOfficer->Science = 4;
	destroyer->ScienceOfficer->Tactics = 1;
	destroyer->ScienceOfficer->Communication = 1;
	destroyer->ScienceOfficer->SubsystemRepair = -1;
	destroyer->ScienceOfficer->ShieldRepair = -1;


	destroyer->Engineer->CrewName = "Sheldon Matthaus";
	destroyer->Engineer->CrewRace = ERace::Human;
	destroyer->Engineer->IsMale = true;
	destroyer->Engineer->Leadership = 0;
	destroyer->Engineer->Navigation = 0;
	destroyer->Engineer->Gunnery = 0;
	destroyer->Engineer->Engineering = 3;
	destroyer->Engineer->Science = 0;
	destroyer->Engineer->Tactics = 1;
	destroyer->Engineer->Communication = 1;
	destroyer->Engineer->SubsystemRepair = -1;
	destroyer->Engineer->ShieldRepair = -1;

	Fleet.Add(destroyer);
}