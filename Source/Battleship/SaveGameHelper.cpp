#include "Battleship.h"
#include "BattleshipSaveGame.h"
#include "SaveGameHelper.h"

FString USaveGameHelper::GetSaveGamesDirectory()
{
	return FPaths::Combine(FPaths::ProjectSavedDir(), FString(TEXT("SaveGames")));
}

TArray<FString> USaveGameHelper::GetSaveGameFiles()
{
	FString saveDirectory = GetSaveGamesDirectory();
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();

	FString FinalPath = saveDirectory + "/*.sav";
	UE_LOG(LogTemp, Warning, TEXT("getFileList, FinalPath = %s"), *FinalPath);
	FileManager.FindFiles(Files, *FinalPath, true, false);

	for (FString myFile : Files) {
		UE_LOG(LogTemp, Warning, TEXT("getFileList, saveFile = %s"), *myFile);
	}

	return Files;
}

FString USaveGameHelper::GetLatestSaveFile()
{
	FString latestFile = "NotFound";
	FString saveDirectory = GetSaveGamesDirectory();
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();

	FString FinalPath = saveDirectory + "/*.sav";
	UE_LOG(LogTemp, Warning, TEXT("getFileList, FinalPath = %s"), *FinalPath);
	FileManager.FindFiles(Files, *FinalPath, true, false);

	FDateTime latestTime = FDateTime::FromUnixTimestamp(0);

	for (FString myFile : Files) {
		FString saveSlot = myFile.Replace(TEXT(".sav"), TEXT("")); //saveDirectory + myFile;

		UBattleshipSaveGame* saveGame = Cast<UBattleshipSaveGame>(UGameplayStatics::LoadGameFromSlot(saveSlot, 0));

		if (saveGame == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load save file: %s"), *myFile);
		}
		else if (saveGame->TimeStamp == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("Save file %s does not contain timestamp."), *myFile);
			//latestFile = saveSlot;
		}
		else if (saveGame->TimeStamp > latestTime)
		{
			latestTime = saveGame->TimeStamp;
			latestFile = saveSlot;
		}

		/*FString PlayerNameToDisplay = LoadGameInstance->PlayerName;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, PlayerNameToDisplay);
		}*/
	}

	UE_LOG(LogTemp, Warning, TEXT("Latest save file: %s"), *latestFile);

	return latestFile;
}

bool USaveGameHelper::AnySaveFiles()
{
	FString saveDirectory = GetSaveGamesDirectory();
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();

	FString FinalPath = saveDirectory + "/*.sav";
	FileManager.FindFiles(Files, *FinalPath, true, false);

	return Files.Num() > 0;
}

TArray<UBattleshipSaveGame*> USaveGameHelper::GetSaveGames()
{
	TArray<UBattleshipSaveGame*> saveGames;

	TArray<FString> files = GetSaveGameFiles();

	for (FString saveFile : files) {
		FString saveSlot = saveFile.Replace(TEXT(".sav"), TEXT(""));

		UBattleshipSaveGame* saveGame = Cast<UBattleshipSaveGame>(UGameplayStatics::LoadGameFromSlot(saveSlot, 0));

		if (saveGame == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load save file: %s"), *saveFile);
		}
		else if (saveGame->TimeStamp == NULL)
		{
			UE_LOG(LogTemp, Warning, TEXT("Save file %s does not contain timestamp."), *saveFile);
		}
		else
		{
			saveGames.Add(saveGame);
			/*FString characterId = saveGame->CharacterId;

			if (!saveGames.Contains(characterId))
			{
				TArray<UBattleshipSaveGame*> characterSaves;
				saveGames.Add(characterId, characterSaves);
			}

			saveGames[characterId].Add(saveGame);*/
		}
	}

	return saveGames;
}

TArray<FString> USaveGameHelper::FindUniqueCharacterIds(TArray<UBattleshipSaveGame*> SaveGames)
{
	TArray<FString> characterIds;

	for (UBattleshipSaveGame* save : SaveGames)
	{
		if (!characterIds.Contains(save->CharacterId))
		{
			characterIds.Add(save->CharacterId);
		}
	}

	characterIds.Sort(SortCharacters);

	return characterIds;
}

TArray<UBattleshipSaveGame*> USaveGameHelper::FindSaveGamesForCharacters(FString CharacterId, TArray<UBattleshipSaveGame*> SaveGames)
{
	TArray<UBattleshipSaveGame*> saveGamesForCharacter;

	for (UBattleshipSaveGame* save : SaveGames)
	{
		if (save->CharacterId == CharacterId)
		{
			saveGamesForCharacter.Add(save);
		}
	}

	saveGamesForCharacter.Sort(SortSaves);

	return saveGamesForCharacter;
}
