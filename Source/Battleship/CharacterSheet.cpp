#include "Battleship.h"
#include "CharacterSheet.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.h"

UCharacterSheet::UCharacterSheet()
{

}

FString UCharacterSheet::GetVariableValue(FString variableName)
{
	if (variableName.Contains("+"))
	{
		FString left;
		FString right;
		if (variableName.Split(FString("+"), &left, &right))
		{
			left = left.TrimStartAndEnd();
			right = right.TrimStartAndEnd();

			FString leftValue = GetVariableValue(left);
			FString rightValue = GetVariableValue(right);

			int32 leftInt = 0;
			int32 rightInt = 0;

			if (leftValue == "N/A")
			{
				leftInt = FCString::Atoi(*left);
			}
			else
			{
				leftInt = FCString::Atoi(*leftValue);
			}


			if (rightValue == "N/A")
			{
				rightInt = FCString::Atoi(*right);
			}
			else
			{
				rightInt = FCString::Atoi(*rightValue);
			}

			return FString::FromInt(leftInt + rightInt);
		}
	}
	else if (variableName.Contains("-"))
	{
		FString left;
		FString right;
		if (variableName.Split(FString("-"), &left, &right))
		{
			left = left.TrimStartAndEnd();
			right = right.TrimStartAndEnd();

			FString leftValue = GetVariableValue(left);
			FString rightValue = GetVariableValue(right);

			int32 leftInt = 0;
			int32 rightInt = 0;

			if (leftValue == "N/A")
			{
				leftInt = FCString::Atoi(*left);
			}
			else
			{
				leftInt = FCString::Atoi(*leftValue);
			}


			if (rightValue == "N/A")
			{
				rightInt = FCString::Atoi(*right);
			}
			else
			{
				rightInt = FCString::Atoi(*rightValue);
			}

			return FString::FromInt(leftInt - rightInt);
		}
	}
	else if (variableName.Contains("*"))
	{
		FString left;
		FString right;
		if (variableName.Split(FString("*"), &left, &right))
		{
			left = left.TrimStartAndEnd();
			right = right.TrimStartAndEnd();

			FString leftValue = GetVariableValue(left);
			FString rightValue = GetVariableValue(right);

			int32 leftInt = 0;
			int32 rightInt = 0;

			if (leftValue == "N/A")
			{
				leftInt = FCString::Atoi(*left);
			}
			else
			{
				leftInt = FCString::Atoi(*leftValue);
			}


			if (rightValue == "N/A")
			{
				rightInt = FCString::Atoi(*right);
			}
			else
			{
				rightInt = FCString::Atoi(*rightValue);
			}

			return FString::FromInt(leftInt * rightInt);
		}

	}
	else if (variableName.Contains("/"))
	{
		FString left;
		FString right;
		if (variableName.Split(FString("/"), &left, &right))
		{
			left = left.TrimStartAndEnd();
			right = right.TrimStartAndEnd();

			FString leftValue = GetVariableValue(left);
			FString rightValue = GetVariableValue(right);

			int32 leftInt = 0;
			int32 rightInt = 0;

			if (leftValue == "N/A")
			{
				leftInt = FCString::Atoi(*left);
			}
			else
			{
				leftInt = FCString::Atoi(*leftValue);
			}


			if (rightValue == "N/A")
			{
				rightInt = FCString::Atoi(*right);
			}
			else
			{
				rightInt = FCString::Atoi(*rightValue);
			}

			return FString::FromInt(leftInt / rightInt);
		}
	}
	else
	{
		if (variableName == "Race")
		{
			if (Race == ERace::Malderian)
			{
				return "Malderian";
			}
			else if (Race == ERace::Krum)
			{
				return "Krum";
			}
			else
			{
				return "Human";
			}
		}
		else if (variableName == "Gender")
		{
			if (GenderIsMale == true)
			{
				return "Male";
			}
			else
			{
				return "Female";
			}
		}
		else if (variableName == "Background")
		{
			if (Background == ECharacterBackground::Innerworlds)
			{
				return "Innerworlds";
			}
			else if (Background == ECharacterBackground::Outerworlds)
			{
				return "Outerworlds";
			}
			else if (Background == ECharacterBackground::Military)
			{
				return "Military";
			}
			else if (Background == ECharacterBackground::Noble)
			{
				return "Noble";
			}
			else
			{
				return "Trader";
			}
		}
		else if (variableName == "Gunnery")
		{
			return FString::FromInt(Gunnery);
		}
		else if (variableName == "Pilot")
		{
			return FString::FromInt(Pilot);
		}
		else if (variableName == "Engineering")
		{
			return FString::FromInt(Engineering);
		}
		else if (variableName == "Science")
		{
			return FString::FromInt(Science);
		}
		else if (variableName == "AskedAboutEdward")
		{
			if (AskedAboutEdward == true)
			{
				return "true";
			}
			else
			{
				return "false";
			}
		}
	}
	return variableName;
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

void UCharacterSheet::SetDefaultFleet(TSubclassOf<APlayerShipPawnBase> BattleshipPawnClass, TSubclassOf<APlayerShipPawnBase> DestroyerPawnClass)
{
	if (Fleet.Num() == 0)
	{
		UCrew* crew1 = NewObject<UCrew>();
		UCrew* crew2 = NewObject<UCrew>();
		UCrew* crew3 = NewObject<UCrew>();

		crew1->CrewName = "Bernkhnn Rnaep";
		crew1->CrewRace = ERace::Krum;
		crew1->IsMale = true;
		crew1->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitKrumMale1"), NULL, LOAD_None, NULL);
		crew1->Leadership = 1;
		crew1->Navigation = 2;
		crew1->Gunnery = 3;
		crew1->Engineering = 0;
		crew1->Science = -1;
		crew1->Tactics = -2;
		crew1->Communication = -3;
		crew1->SubsystemRepair = 0;
		crew1->ShieldRepair = 0;

		crew2->CrewName = "Xopown Napehb";
		crew2->CrewRace = ERace::Krum;
		crew2->IsMale = true;
		crew2->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitKrumMale1"), NULL, LOAD_None, NULL);
		crew2->Leadership = -1;
		crew2->Navigation = -2;
		crew2->Gunnery = -3;
		crew2->Engineering = 0;
		crew2->Science = 1;
		crew2->Tactics = 2;
		crew2->Communication = 3;
		crew2->SubsystemRepair = 4;
		crew2->ShieldRepair = 5;

		crew3->CrewName = "Coigreach Air Thuaiream";
		crew3->CrewRace = ERace::Human;
		crew3->IsMale = true;
		crew3->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitHumanMale2"), NULL, LOAD_None, NULL);
		crew3->Leadership = 0;
		crew3->Navigation = 0;
		crew3->Gunnery = 0;
		crew3->Engineering = 0;
		crew3->Science = 0;
		crew3->Tactics = 0;
		crew3->Communication = 0;
		crew3->SubsystemRepair = 0;
		crew3->ShieldRepair = 0;

		UnusedCrew.Add(crew1);
		UnusedCrew.Add(crew2);
		UnusedCrew.Add(crew3);

		APlayerShipPawnBase* flagship = BattleshipPawnClass.GetDefaultObject();
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
		flagship->Captain->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitMalderianMale1"), NULL, LOAD_None, NULL);
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
		flagship->NavigationOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitHumanMale1"), NULL, LOAD_None, NULL);
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
		flagship->TacticsOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitKrumMale1"), NULL, LOAD_None, NULL);
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
		flagship->ScienceOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitMalderianMale1"), NULL, LOAD_None, NULL);
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
		flagship->Engineer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitHumanMale2"), NULL, LOAD_None, NULL);
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

		APlayerShipPawnBase* destroyer = DestroyerPawnClass.GetDefaultObject();
		destroyer->Name = "GCS Selene";
		destroyer->Type = EType::Medium;
		destroyer->Captain = NewObject<UCrew>();
		destroyer->NavigationOfficer = NewObject<UCrew>();
		destroyer->TacticsOfficer = NewObject<UCrew>();
		destroyer->ScienceOfficer = NewObject<UCrew>();
		destroyer->Engineer = NewObject<UCrew>();
		destroyer->CAG = NewObject<UCrew>();

		destroyer->Captain->CrewName = "Ard Kentar";
		destroyer->Captain->CrewRace = ERace::Malderian;
		destroyer->Captain->IsMale = false;
		destroyer->Captain->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitMalderianMale1"), NULL, LOAD_None, NULL);
		destroyer->Captain->Leadership = 0;
		destroyer->Captain->Navigation = 0;
		destroyer->Captain->Gunnery = 0;
		destroyer->Captain->Engineering = 0;
		destroyer->Captain->Science = 0;
		destroyer->Captain->Tactics = 1;
		destroyer->Captain->Communication = 1;
		destroyer->Captain->SubsystemRepair = -1;
		destroyer->Captain->ShieldRepair = -1;


		destroyer->NavigationOfficer->CrewName = "Kevin Sawall";
		destroyer->NavigationOfficer->CrewRace = ERace::Human;
		destroyer->NavigationOfficer->IsMale = true;
		destroyer->NavigationOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitHumanMale2"), NULL, LOAD_None, NULL);
		destroyer->NavigationOfficer->Leadership = 0;
		destroyer->NavigationOfficer->Navigation = 2;
		destroyer->NavigationOfficer->Gunnery = 0;
		destroyer->NavigationOfficer->Engineering = 0;
		destroyer->NavigationOfficer->Science = 0;
		destroyer->NavigationOfficer->Tactics = 1;
		destroyer->NavigationOfficer->Communication = 1;
		destroyer->NavigationOfficer->SubsystemRepair = -1;
		destroyer->NavigationOfficer->ShieldRepair = -1;


		destroyer->TacticsOfficer->CrewName = "Xiohe Inwei";
		destroyer->TacticsOfficer->CrewRace = ERace::Krum;
		destroyer->TacticsOfficer->IsMale = false;
		destroyer->TacticsOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitKrumMale1"), NULL, LOAD_None, NULL);
		destroyer->TacticsOfficer->Leadership = 0;
		destroyer->TacticsOfficer->Navigation = 0;
		destroyer->TacticsOfficer->Gunnery = 0;
		destroyer->TacticsOfficer->Engineering = 0;
		destroyer->TacticsOfficer->Science = 0;
		destroyer->TacticsOfficer->Tactics = 3;
		destroyer->TacticsOfficer->Communication = 1;
		destroyer->TacticsOfficer->SubsystemRepair = -1;
		destroyer->TacticsOfficer->ShieldRepair = -1;


		destroyer->ScienceOfficer->CrewName = "Io Ra";
		destroyer->ScienceOfficer->CrewRace = ERace::Malderian;
		destroyer->ScienceOfficer->IsMale = true;
		destroyer->ScienceOfficer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitMalderianMale1"), NULL, LOAD_None, NULL);
		destroyer->ScienceOfficer->Leadership = 0;
		destroyer->ScienceOfficer->Navigation = 0;
		destroyer->ScienceOfficer->Gunnery = 0;
		destroyer->ScienceOfficer->Engineering = 0;
		destroyer->ScienceOfficer->Science = 4;
		destroyer->ScienceOfficer->Tactics = 1;
		destroyer->ScienceOfficer->Communication = 1;
		destroyer->ScienceOfficer->SubsystemRepair = -1;
		destroyer->ScienceOfficer->ShieldRepair = -1;


		destroyer->Engineer->CrewName = "Sam Samson";
		destroyer->Engineer->CrewRace = ERace::Human;
		destroyer->Engineer->IsMale = false;
		destroyer->Engineer->Portrait = LoadObject<UTexture2D>(crew1, TEXT("/Game/Textures/Crew/CrewPortraitHumanFemale1"), NULL, LOAD_None, NULL);
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
}