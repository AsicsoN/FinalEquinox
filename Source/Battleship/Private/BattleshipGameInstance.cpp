#include "Battleship.h"
#include "BattleshipGameInstance.h"
#include "CharacterSheetInitialization.h"
#include "AbilityLibrary.h"
#include "CharacterSheet.h"

UBattleshipGameInstance::UBattleshipGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Initialize();
}

void UBattleshipGameInstance::Initialize()
{
	CharacterId = FGuid::NewGuid().ToString();
	CharacterSheet = UCharacterSheetInitialization::CreateStartingCharacterSheet();
}

UCharacterSheet* UBattleshipGameInstance::CreateDefaultCharacterSheet()
{
	CharacterSheet = NewObject<UCharacterSheet>();

	CharacterSheet->Supplies = 30;

	return CharacterSheet;
}