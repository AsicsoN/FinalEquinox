#include "Battleship.h"
#include "Stardate.h"
#include "Crew.h"
#include "PlayerCrewObject.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.h"
#include "JsonSerializeAndDeserialize.h"

FString UJsonSerializeAndDeserialize::ConvertRaceToString(ERace Race)
{
	if (Race == ERace::Malderian)
	{
		return "Malderian";
	}
	else if (Race == ERace::Krum)
	{
		return "Krum";
	}
	else if (Race == ERace::Barkhomi)
	{
		return "Barkhomi";
	}
	else
	{
		return "Human";
	}
}

FString UJsonSerializeAndDeserialize::ConvertCharacterBackgroundToString(ECharacterBackground Background)
{
	if (Background == ECharacterBackground::Innerworlds)
	{
		return "Innerworlds";
	}
	else if (Background == ECharacterBackground::Military)
	{
		return "Military";
	}
	else if (Background == ECharacterBackground::Noble)
	{
		return "Noble";
	}
	else if (Background == ECharacterBackground::Outerworlds)
	{
		return "Outerworlds";
	}
	else
	{
		return "Trader";
	}
}

FString UJsonSerializeAndDeserialize::ConvertTypeToString(EType Type)
{
	if (Type == EType::Large)
	{
		return "Large";
	}
	else if (Type == EType::Medium)
	{
		return "Medium";
	}
	else if (Type == EType::Small)
	{
		return "Small";
	}
	else
	{
		return "None";
	}
}

TSharedPtr<FJsonObject> UJsonSerializeAndDeserialize::SerializeCrewToJsonObject(UCrew* Crew)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetBoolField("isLocked", Crew->IsLocked);
	JsonObject->SetStringField("crewName", Crew->CrewName);
	JsonObject->SetStringField("crewRace", ConvertRaceToString(Crew->CrewRace));
	JsonObject->SetBoolField("isMale", Crew->IsMale);
	JsonObject->SetStringField("portrait", Crew->Portrait->GetPathName());
	JsonObject->SetBoolField("canDie", Crew->CanDie);
	JsonObject->SetNumberField("leadership", Crew->Leadership);
	JsonObject->SetNumberField("navigation", Crew->Navigation);
	JsonObject->SetNumberField("communication", Crew->Communication);
	JsonObject->SetNumberField("gunnery", Crew->Gunnery);
	JsonObject->SetNumberField("engineering", Crew->Engineering);
	JsonObject->SetNumberField("science", Crew->Science);
	JsonObject->SetNumberField("tactics", Crew->Tactics);
	JsonObject->SetNumberField("subsystemRepair", Crew->SubsystemRepair);
	JsonObject->SetNumberField("shieldRepair", Crew->ShieldRepair);
	JsonObject->SetNumberField("level", Crew->Level);
	JsonObject->SetNumberField("experiencePoints", Crew->ExperiencePoints);

	return JsonObject;
}

TSharedPtr<FJsonObject> UJsonSerializeAndDeserialize::SerializeShipToJsonObject(APlayerShipPawnBase* Ship)
{
	FString referencePath;
	FString objectName;
	FString pathName = Ship->GetClass()->GetPathName();
	pathName.Split(".", &referencePath, &objectName);
	FString reference = referencePath + "." + Ship->GetName();
	UE_LOG(LogTemp, Log, TEXT("Ship reference: %s"), *reference);

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", Ship->Name);
	JsonObject->SetStringField("reference", reference);

	JsonObject->SetNumberField("subsystemEngine", Ship->Subsystems.Engine);
	JsonObject->SetNumberField("subsystemGuns", Ship->Subsystems.Guns);
	JsonObject->SetNumberField("subsystemShieldGen", Ship->Subsystems.ShieldGen);
	JsonObject->SetNumberField("subsystemScanners", Ship->Subsystems.Scanners);

	JsonObject->SetNumberField("currentHitPoints", Ship->CurrentHitPoints);
	JsonObject->SetNumberField("currentShieldHitPoints", Ship->CurrentShieldHitPoints);
	JsonObject->SetNumberField("missiles", Ship->Missiles);
	JsonObject->SetNumberField("fighters", Ship->Fighters);

	JsonObject->SetObjectField("captain", SerializeCrewToJsonObject(Ship->Captain));
	JsonObject->SetObjectField("navigationOfficer", SerializeCrewToJsonObject(Ship->NavigationOfficer));
	JsonObject->SetObjectField("tacticsOfficer", SerializeCrewToJsonObject(Ship->TacticsOfficer));
	JsonObject->SetObjectField("scienceOfficer", SerializeCrewToJsonObject(Ship->ScienceOfficer));
	JsonObject->SetObjectField("engineer", SerializeCrewToJsonObject(Ship->Engineer));
	//JsonObject->SetObjectField("cag", SerializeCrewToJsonObject(Ship->CAG));

	return JsonObject;
}

FString UJsonSerializeAndDeserialize::SerializeCharacterSheetToJson(UCharacterSheet* CharacterSheet)
{
	if (CharacterSheet == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Character sheet is null!"));
		return "";
	}

	TSharedPtr<FJsonObject> StardateJsonObject = MakeShareable(new FJsonObject);
	StardateJsonObject->SetNumberField("year", CharacterSheet->Stardate->GetYear());
	StardateJsonObject->SetNumberField("month", CharacterSheet->Stardate->GetMonth());
	StardateJsonObject->SetNumberField("day", CharacterSheet->Stardate->GetDay());

	FString StardateJsonString;
	TSharedRef<TJsonWriter<>> StardateWriter = TJsonWriterFactory<>::Create(&StardateJsonString);
	FJsonSerializer::Serialize(StardateJsonObject.ToSharedRef(), StardateWriter);

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("name", CharacterSheet->Name);
	JsonObject->SetStringField("race", ConvertRaceToString(CharacterSheet->Race));
	JsonObject->SetStringField("background", ConvertCharacterBackgroundToString(CharacterSheet->Background));
	JsonObject->SetBoolField("genderIsMale", CharacterSheet->GenderIsMale);
	JsonObject->SetNumberField("culture", CharacterSheet->Culture);
	JsonObject->SetNumberField("language", CharacterSheet->Language);
	JsonObject->SetNumberField("medicine", CharacterSheet->Medicine);
	JsonObject->SetNumberField("barter", CharacterSheet->Barter);
	JsonObject->SetNumberField("deception", CharacterSheet->Deception);
	JsonObject->SetNumberField("leadership", CharacterSheet->Leadership);
	JsonObject->SetNumberField("intimidate", CharacterSheet->Intimidate);
	JsonObject->SetNumberField("tactics", CharacterSheet->Tactics);
	JsonObject->SetNumberField("navigation", CharacterSheet->Navigation);
	JsonObject->SetNumberField("science", CharacterSheet->Science);
	JsonObject->SetNumberField("gunnery", CharacterSheet->Gunnery);
	JsonObject->SetNumberField("shieldRepair", CharacterSheet->ShieldRepair);
	JsonObject->SetNumberField("engineering", CharacterSheet->Engineering);
	JsonObject->SetNumberField("subsystemRepair", CharacterSheet->SubsystemRepair);
	JsonObject->SetNumberField("supplies", CharacterSheet->Supplies);
	JsonObject->SetBoolField("sentanaTutorialCompleted", CharacterSheet->SentanaTutorialCompleted);
	JsonObject->SetObjectField("stardate", StardateJsonObject);

	TArray<TSharedPtr<FJsonValue>> unusedCrew;
	for (auto& Crew : CharacterSheet->UnusedCrew)
	{
		TSharedRef<FJsonValueObject> JsonValue = MakeShareable(new FJsonValueObject(SerializeCrewToJsonObject(Crew)));
		unusedCrew.Add(JsonValue);
	}
	JsonObject->SetArrayField("unusedCrew", unusedCrew);

	TArray<TSharedPtr<FJsonValue>> fleet;
	for (auto& Ship : CharacterSheet->Fleet)
	{
		TSharedRef<FJsonValueObject> JsonValue = MakeShareable(new FJsonValueObject(SerializeShipToJsonObject(Ship)));
		fleet.Add(JsonValue);
	}
	JsonObject->SetArrayField("fleet", fleet);

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	UE_LOG(LogTemp, VeryVerbose, TEXT("resulting jsonString -> %s"), *OutputString);

	return OutputString;
	//return toReturn;
}

ERace UJsonSerializeAndDeserialize::ConvertStringToRace(FString RaceString)
{
	if (RaceString == "Barkhomi")
	{
		return ERace::Barkhomi;
	}
	if (RaceString == "Krum")
	{
		return ERace::Krum;
	}
	if (RaceString == "Malderian")
	{
		return ERace::Malderian;
	}
	else
	{
		return ERace::Human;
	}
}

ECharacterBackground UJsonSerializeAndDeserialize::ConvertStringToCharacterBackground(FString BackgroundString)
{
	if (BackgroundString == "Innerworlds")
	{
		return ECharacterBackground::Innerworlds;
	}
	else if (BackgroundString == "Military")
	{
		return ECharacterBackground::Military;
	}
	else if (BackgroundString == "Noble")
	{
		return ECharacterBackground::Noble;
	}
	else if (BackgroundString == "Outerworlds")
	{
		return ECharacterBackground::Outerworlds;
	}
	else
	{
		return ECharacterBackground::Trader;
	}
}

UCrew* UJsonSerializeAndDeserialize::DeserializeCrewFromJsonObject(TSharedPtr<FJsonObject> JsonObject, UObject* Parent)
{
	UCrew* crew = NewObject<UCrew>();

	crew->CrewName = JsonObject->GetStringField("crewName");
	crew->IsLocked = JsonObject->GetBoolField("isLocked");
	crew->CrewRace = ConvertStringToRace(JsonObject->GetStringField("crewRace"));
	crew->IsMale = JsonObject->GetBoolField("isMale");
	FString portrait = JsonObject->GetStringField("portrait");
	crew->Portrait = LoadObject<UTexture2D>(Parent, *portrait, NULL, LOAD_None, NULL);
	crew->Leadership = JsonObject->GetNumberField("leadership");
	crew->Navigation = JsonObject->GetNumberField("navigation");
	crew->Gunnery = JsonObject->GetNumberField("gunnery");
	crew->Engineering = JsonObject->GetNumberField("engineering");
	crew->Science = JsonObject->GetNumberField("science");
	crew->Tactics = JsonObject->GetNumberField("tactics");
	crew->Communication = JsonObject->GetNumberField("communication");
	crew->SubsystemRepair = JsonObject->GetNumberField("subsystemRepair");
	crew->ShieldRepair = JsonObject->GetNumberField("shieldRepair");
	crew->Level = JsonObject->GetNumberField("level");
	crew->ExperiencePoints = JsonObject->GetNumberField("experiencePoints");

	return crew;
}

UCharacterSheet* UJsonSerializeAndDeserialize::DeserializeCharacterSheetFromJson(FString CharacterSheetString)
{
	UCharacterSheet* characterSheet;
	characterSheet = NewObject<UCharacterSheet>();

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(CharacterSheetString);

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		characterSheet->Name = JsonObject->GetStringField("name");
		characterSheet->Race = ConvertStringToRace(JsonObject->GetStringField("race"));
		characterSheet->Background = ConvertStringToCharacterBackground(JsonObject->GetStringField("background"));
		characterSheet->GenderIsMale = JsonObject->GetBoolField("genderIsMale");

		characterSheet->Culture = JsonObject->GetNumberField("culture");
		characterSheet->Language = JsonObject->GetNumberField("language");
		characterSheet->Medicine = JsonObject->GetNumberField("medicine");
		characterSheet->Barter = JsonObject->GetNumberField("barter");
		characterSheet->Deception = JsonObject->GetNumberField("deception");
		characterSheet->Leadership = JsonObject->GetNumberField("leadership");
		characterSheet->Intimidate = JsonObject->GetNumberField("intimidate");
		characterSheet->Tactics = JsonObject->GetNumberField("tactics");
		characterSheet->Navigation = JsonObject->GetNumberField("navigation");
		characterSheet->Science = JsonObject->GetNumberField("science");
		characterSheet->Gunnery = JsonObject->GetNumberField("gunnery");
		characterSheet->ShieldRepair = JsonObject->GetNumberField("shieldRepair");
		characterSheet->Engineering = JsonObject->GetNumberField("engineering");
		characterSheet->SubsystemRepair = JsonObject->GetNumberField("subsystemRepair");

		characterSheet->Supplies = JsonObject->GetNumberField("supplies");

		characterSheet->SentanaTutorialCompleted = JsonObject->GetBoolField("sentanaTutorialCompleted");

		TSharedPtr<FJsonObject> stardateJsonObject = JsonObject->GetObjectField("stardate");
		int32 year = stardateJsonObject->GetNumberField("year");
		int32 month = stardateJsonObject->GetNumberField("month");
		int32 day = stardateJsonObject->GetNumberField("day");
		characterSheet->Stardate = NewObject<UStardate>();
		characterSheet->Stardate->SetStardate(year, month, day);

		TArray<TSharedPtr<FJsonValue>> unusedCrew = JsonObject->GetArrayField("unusedCrew");
		for (auto& crewJson : unusedCrew)
		{
			TSharedPtr<FJsonObject> crewJsonObject = crewJson->AsObject();
			characterSheet->UnusedCrew.Add(DeserializeCrewFromJsonObject(crewJsonObject, characterSheet));
		}

		TArray<TSharedPtr<FJsonValue>> fleet = JsonObject->GetArrayField("fleet");
		for (auto& shipJson : fleet)
		{
			TSharedPtr<FJsonObject> shipJsonObject = shipJson->AsObject();
			FString reference = shipJsonObject->GetStringField("reference");
			UE_LOG(LogTemp, Log, TEXT("Ship reference: %s"), *reference);

			APlayerShipPawnBase* shipDefaultObject = LoadObject<APlayerShipPawnBase>(characterSheet, *reference, NULL, LOAD_None, NULL);
			// Duplicate ship so we have our own instance of it
			APlayerShipPawnBase* ship = DuplicateObject(shipDefaultObject, NULL);
			if (ship == NULL)
			{
				UE_LOG(LogTemp, Error, TEXT("Ship was null"));
			}
			else
			{
				ship->Name = shipJsonObject->GetStringField("name");
				if (ship->Name == "HCS Odysseus")
				{
					characterSheet->PlayerCrewObject = NewObject<UPlayerCrewObject>();
					ship->Captain = characterSheet->PlayerCrewObject;
				}
				else
				{
					TSharedPtr<FJsonObject> captainJsonObject = shipJsonObject->GetObjectField("captain");
					ship->Captain = DeserializeCrewFromJsonObject(captainJsonObject, characterSheet);
				}

				ship->NavigationOfficer = DeserializeCrewFromJsonObject(shipJsonObject->GetObjectField("navigationOfficer"), characterSheet);
				ship->TacticsOfficer = DeserializeCrewFromJsonObject(shipJsonObject->GetObjectField("tacticsOfficer"), characterSheet);
				ship->ScienceOfficer = DeserializeCrewFromJsonObject(shipJsonObject->GetObjectField("scienceOfficer"), characterSheet);
				ship->Engineer = DeserializeCrewFromJsonObject(shipJsonObject->GetObjectField("engineer"), characterSheet);
				//ship->CAG = DeserializeCrewFromJsonObject(shipJsonObject->GetObjectField("cag"), characterSheet);

				ship->Subsystems.Engine = shipJsonObject->GetNumberField("subsystemEngine");
				ship->Subsystems.Guns = shipJsonObject->GetNumberField("subsystemGuns");
				ship->Subsystems.ShieldGen = shipJsonObject->GetNumberField("subsystemShieldGen");
				ship->Subsystems.Scanners = shipJsonObject->GetNumberField("subsystemScanners");

				ship->CurrentHitPoints = shipJsonObject->GetNumberField("currentHitPoints");
				ship->CurrentShieldHitPoints = shipJsonObject->GetNumberField("currentShieldHitPoints");
				ship->Missiles = shipJsonObject->GetNumberField("missiles");
				ship->Fighters = shipJsonObject->GetNumberField("fighters");

				characterSheet->Fleet.Add(ship);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize character sheet"));
	}

	return characterSheet;
}
