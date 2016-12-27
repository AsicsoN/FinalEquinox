

#include "Battleship.h"
#include "CharacterSheet.h"

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
	else if (option == "option_piloting")
	{
		Pilot += 2;
		Gunnery++;
	}
	else if (option == "option_navigation")
	{
		Navigation += 2;
		Tactics++;
	}
	else if (option == "option_mechanics")
	{
		Mechanics += 2;
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
		Mechanics--;
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

void UCharacterSheet::SetDefaultFleet(TSubclassOf<class AShipPawnBase> BattleshipPawnClass, TSubclassOf<class AShipPawnBase> DestroyerPawnClass)
{
	UShip* flagship = NewObject<UShip>();
	flagship->Name = "GCS Odysseus";
	flagship->PawnClass = BattleshipPawnClass;
	flagship->Captain = NewObject<UCrew>();
	flagship->NavigationOfficer = NewObject<UCrew>();
	flagship->WeaponsOfficer = NewObject<UCrew>();
	flagship->ScienceOfficer = NewObject<UCrew>();
	flagship->Engineer = NewObject<UCrew>();
	flagship->CAG = NewObject<UCrew>();

	flagship->Captain->CrewName = "Ixa Rkeok";
	flagship->Captain->CrewRace = ERace::Malderian;
	flagship->Captain->IsMale = false;
	flagship->Captain->Leadership = 7;
	flagship->Captain->Piloting = 4;
	flagship->Captain->Gunnery = 3;
	flagship->Captain->Mechanics = 5;
	flagship->Captain->Hacking = 1;

	flagship->NavigationOfficer->CrewName = "Edvin Tjaard";
	flagship->NavigationOfficer->CrewRace = ERace::Human;
	flagship->NavigationOfficer->IsMale = true;
	flagship->NavigationOfficer->Leadership = 2;
	flagship->NavigationOfficer->Piloting = 6;
	flagship->NavigationOfficer->Gunnery = 4;
	flagship->NavigationOfficer->Mechanics = 1;
	flagship->NavigationOfficer->Hacking = 3;

	flagship->WeaponsOfficer->CrewName = "Tu'Vol Strogonar";
	flagship->WeaponsOfficer->CrewRace = ERace::Krum;
	flagship->WeaponsOfficer->IsMale = true;
	flagship->WeaponsOfficer->Leadership = 4;
	flagship->WeaponsOfficer->Piloting = 4;
	flagship->WeaponsOfficer->Gunnery = 7;
	flagship->WeaponsOfficer->Mechanics = 4;
	flagship->WeaponsOfficer->Hacking = 1;

	flagship->ScienceOfficer->CrewName = "Mar-Tun";
	flagship->ScienceOfficer->CrewRace = ERace::Malderian;
	flagship->ScienceOfficer->IsMale = true;
	flagship->ScienceOfficer->Leadership = 7;
	flagship->ScienceOfficer->Piloting = 4;
	flagship->ScienceOfficer->Gunnery = 3;
	flagship->ScienceOfficer->Mechanics = 5;
	flagship->ScienceOfficer->Hacking = 7;

	flagship->Engineer->CrewName = "Sheldon Matthaus";
	flagship->Engineer->CrewRace = ERace::Human;
	flagship->Engineer->IsMale = true;
	flagship->Engineer->Leadership = 2;
	flagship->Engineer->Piloting = 6;
	flagship->Engineer->Gunnery = 2;
	flagship->Engineer->Mechanics = 7;
	flagship->Engineer->Hacking = 5;

	flagship->CAG->CrewName = "Jaylen Arthur";
	flagship->CAG->CrewRace = ERace::Human;
	flagship->CAG->IsMale = false;
	flagship->CAG->Leadership = 6;
	flagship->CAG->Piloting = 4;
	flagship->CAG->Gunnery = 5;
	flagship->CAG->Mechanics = 2;
	flagship->CAG->Hacking = 2;

	Fleet.Add(flagship);

	UShip* destroyer = NewObject<UShip>();
	destroyer->Name = "GCS Selene";
	destroyer->PawnClass = DestroyerPawnClass;
	destroyer->Captain = NewObject<UCrew>();
	destroyer->NavigationOfficer = NewObject<UCrew>();
	destroyer->WeaponsOfficer = NewObject<UCrew>();
	destroyer->ScienceOfficer = NewObject<UCrew>();
	destroyer->Engineer = NewObject<UCrew>();
	destroyer->CAG = NewObject<UCrew>();

	destroyer->Captain->CrewName = "Ixa Rkeok";
	destroyer->Captain->CrewRace = ERace::Malderian;
	destroyer->Captain->IsMale = false;
	destroyer->Captain->Leadership = 7;
	destroyer->Captain->Piloting = 4;
	destroyer->Captain->Gunnery = 3;
	destroyer->Captain->Mechanics = 5;
	destroyer->Captain->Hacking = 1;

	destroyer->NavigationOfficer->CrewName = "Edvin Tjaard";
	destroyer->NavigationOfficer->CrewRace = ERace::Human;
	destroyer->NavigationOfficer->IsMale = true;
	destroyer->NavigationOfficer->Leadership = 2;
	destroyer->NavigationOfficer->Piloting = 6;
	destroyer->NavigationOfficer->Gunnery = 4;
	destroyer->NavigationOfficer->Mechanics = 1;
	destroyer->NavigationOfficer->Hacking = 3;

	destroyer->WeaponsOfficer->CrewName = "Tu'Vol Strogonar";
	destroyer->WeaponsOfficer->CrewRace = ERace::Krum;
	destroyer->WeaponsOfficer->IsMale = true;
	destroyer->WeaponsOfficer->Leadership = 4;
	destroyer->WeaponsOfficer->Piloting = 4;
	destroyer->WeaponsOfficer->Gunnery = 7;
	destroyer->WeaponsOfficer->Mechanics = 4;
	destroyer->WeaponsOfficer->Hacking = 1;

	destroyer->ScienceOfficer->CrewName = "Mar-Tun";
	destroyer->ScienceOfficer->CrewRace = ERace::Malderian;
	destroyer->ScienceOfficer->IsMale = true;
	destroyer->ScienceOfficer->Leadership = 7;
	destroyer->ScienceOfficer->Piloting = 4;
	destroyer->ScienceOfficer->Gunnery = 3;
	destroyer->ScienceOfficer->Mechanics = 5;
	destroyer->ScienceOfficer->Hacking = 7;

	destroyer->Engineer->CrewName = "Sheldon Matthaus";
	destroyer->Engineer->CrewRace = ERace::Human;
	destroyer->Engineer->IsMale = true;
	destroyer->Engineer->Leadership = 2;
	destroyer->Engineer->Piloting = 6;
	destroyer->Engineer->Gunnery = 2;
	destroyer->Engineer->Mechanics = 7;
	destroyer->Engineer->Hacking = 5;

	destroyer->CAG->CrewName = "Jaylen Arthur";
	destroyer->CAG->CrewRace = ERace::Human;
	destroyer->CAG->IsMale = false;
	destroyer->CAG->Leadership = 6;
	destroyer->CAG->Piloting = 4;
	destroyer->CAG->Gunnery = 5;
	destroyer->CAG->Mechanics = 2;
	destroyer->CAG->Hacking = 2;

	Fleet.Add(destroyer);
}