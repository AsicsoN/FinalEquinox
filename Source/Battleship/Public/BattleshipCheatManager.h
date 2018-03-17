

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "BattleshipCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UBattleshipCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
	UFUNCTION(exec)
	virtual void HelloWorld();

	UFUNCTION(exec)
	virtual void CrashNow();
};
