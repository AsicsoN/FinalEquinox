

#include "Battleship.h"
#include "LoadGameState.h"

FString ALoadGameState::runLoadGame() {
	UE_LOG(LogTemp, Warning, TEXT("runLoadGame!!"));

	IFileManager& fileManager = IFileManager::Get();
	TArray<FString> myFiles;
	FString saveDirectory = FString(FPaths::ProjectDir()) + FString("/SaveData");		// location of save directory

	FString result = "Empty";

	myFiles.Empty();
	fileManager.FindFiles(myFiles, *saveDirectory, true, false);

	if (myFiles.IsValidIndex(0)) {
		result = myFiles.Last();
		UE_LOG(LogTemp, Warning, TEXT("Last Saved File: %s"), *result);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Saved Files Found"));
	}

	return result;
}

ALoadGameState::ALoadGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("Welcome to MySaveState!!"));
}
