#include "Battleship.h"
#include "BattleshipGameInstance.h"
#include "CharacterSheetInitialization.h"
#include "AbilityLibrary.h"

UBattleshipGameInstance::UBattleshipGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Initialize();
}

void UBattleshipGameInstance::Initialize()
{
	CharacterId = FGuid::NewGuid().ToString();
	CharacterSheet = UCharacterSheetInitialization::CreateStartingCharacterSheet();
}
