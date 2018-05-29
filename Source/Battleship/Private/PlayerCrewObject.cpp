#include "Battleship.h"
#include "BattleshipGameInstance.h"
#include "PlayerCrewObject.h"

UPlayerCrewObject::UPlayerCrewObject()
{
	IsLocked = true;
	CanDie = false;
	Portrait = LoadObject<UTexture2D>(this, TEXT("/Game/Textures/Crew/CrewPortraitUnknown"), NULL, LOAD_None, NULL);
}

void UPlayerCrewObject::Refresh(UBattleshipGameInstance* GameInstance)
{
	if (GameInstance)
	{
		UCharacterSheet* CharacterSheet = GameInstance->CharacterSheet;
		if (CharacterSheet)
		{
			CrewName = CharacterSheet->Name;
			CrewRace = CharacterSheet->Race;
			IsMale = CharacterSheet->GenderIsMale;
			Leadership = CharacterSheet->Leadership;
			Navigation = CharacterSheet->Navigation;
			Communication = CharacterSheet->Language;
			Gunnery = CharacterSheet->Gunnery;
			Engineering = CharacterSheet->Engineering;
			Science = CharacterSheet->Science;
			Tactics = CharacterSheet->Tactics;
			SubsystemRepair = CharacterSheet->SubsystemRepair;
			ShieldRepair = CharacterSheet->ShieldRepair;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CharacterSheet is NULL!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameInstance is NULL!"));
	}
}
