#include "Battleship.h"
#include "BattleshipCheatManager.h"

void UBattleshipCheatManager::HelloWorld()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hello World!"));
}

void UBattleshipCheatManager::CrashNow()
{
	volatile int* ptr = nullptr;
	volatile int crash = *ptr;
}
