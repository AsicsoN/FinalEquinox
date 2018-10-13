#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSheet.h"
#include "BattleshipSaveGame.h"
#include "SaveGameHelper.generated.h"

/**
*
*/
UCLASS(BlueprintType)
class BATTLESHIP_API USaveGameHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static FString GetSaveGamesDirectory();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static TArray<FString> GetSaveGameFiles();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static FString GetLatestSaveFile();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static bool AnySaveFiles();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static TArray<UBattleshipSaveGame*> GetSaveGames();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static TArray<FString> FindUniqueCharacterIds(TArray<UBattleshipSaveGame*> SaveGames);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	static TArray<UBattleshipSaveGame*> FindSaveGamesForCharacters(FString CharacterId, TArray<UBattleshipSaveGame*> SaveGames);

private:
	inline static bool SortSaves(const UBattleshipSaveGame& Save1, const UBattleshipSaveGame& Save2)
	{
		return (Save1.TimeStamp > Save2.TimeStamp);
	}

	inline static bool SortCharacters(const FString CharacterId1, const FString CharacterId2)
	{
		TArray<UBattleshipSaveGame*> saveGames = GetSaveGames();

		TArray<UBattleshipSaveGame*> saves1 = FindSaveGamesForCharacters(CharacterId1, saveGames);
		TArray<UBattleshipSaveGame*> saves2 = FindSaveGamesForCharacters(CharacterId2, saveGames);

		return (saves1[0]->TimeStamp > saves2[0]->TimeStamp);
	}
};