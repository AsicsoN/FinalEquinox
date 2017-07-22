#include "Battleship.h"
#include "SaveGameHelper.h"

FString USaveGameHelper::GetSaveGamesDirectory()
{
	return FPaths::Combine(FPaths::GameSavedDir(), FString(TEXT("SaveGames")));
}

TArray<FString> USaveGameHelper::GetSaveGameFiles()
{
	FString saveDirectory = FString(FPaths::GameSavedDir()) + FString("SaveGames/");		// location of save directory
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();

	//FString FinalPath = GetSaveGamesDirectory() + "/*.sav";
	FString FinalPath = saveDirectory + "*.sav";
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
	FString saveDirectory = FString(FPaths::GameSavedDir()) + FString("SaveGames/");		// location of save directory
	TArray<FString> Files;
	IFileManager& FileManager = IFileManager::Get();

	//FString FinalPath = GetSaveGamesDirectory() + "/*.sav";
	FString FinalPath = saveDirectory + "*.sav";
	UE_LOG(LogTemp, Warning, TEXT("getFileList, FinalPath = %s"), *FinalPath);
	FileManager.FindFiles(Files, *FinalPath, true, false);

	for (FString myFile : Files) {
		latestFile = saveDirectory + myFile;
		UE_LOG(LogTemp, Warning, TEXT("getFileList, saveFile = %s"), *myFile);
	}

	return latestFile;
}
