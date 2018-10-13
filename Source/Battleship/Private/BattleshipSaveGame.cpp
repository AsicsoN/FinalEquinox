#include "Battleship.h"
#include "BattleshipSaveGame.h"

UBattleshipSaveGame::UBattleshipSaveGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	TimeStamp = FDateTime::UtcNow();
	SaveId = FGuid::NewGuid().ToString();
}
