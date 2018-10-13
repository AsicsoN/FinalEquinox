#include "Battleship.h"
#include "BattleshipGameInstance.h"
#include "AbilityLibrary.h"
#include "CharacterSheet.h"

UBattleshipGameInstance::UBattleshipGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

UCharacterSheet* UBattleshipGameInstance::CreateDefaultCharacterSheet()
{
	CharacterSheet = NewObject<UCharacterSheet>();

	CharacterSheet->Supplies = 30;

	return CharacterSheet;
}