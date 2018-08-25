

#include "Battleship.h"
#include "SaveGameState.h"

ASaveGameState::ASaveGameState()
{
	//UE_LOG(LogTemp, Warning, TEXT("Welcome to MySaveState!!"));
}

FString ASaveGameState::GenerateLatestSave() {
	UE_LOG(LogTemp, Warning, TEXT("SaveGameState::generateSaveLocation"));
	FString saveDirectory = FString(FPaths::ProjectSavedDir()) + FString("SaveGames/");		// location of save directory

	FString fileSurName = FString("save");
	bool fileExisted = true;					// determines is save file is generated
	int fileNum = 0;							// file name number
	FString fileExtention = FString(".sav");
	FString fileName = FString(fileSurName) +
		FString::FormatAsNumber(fileNum) +
		FString(fileExtention);

	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString absolutePath = saveDirectory + fileName;

	while (fileExisted) {
		// CreateDirectoryTree returns true if the destination
		// directory existed prior to call or has been created
		// during the call.
		if (platformFile.CreateDirectoryTree(*saveDirectory))
		{
			// get new file name
			fileName = FString(fileSurName) +
				FString::FormatAsNumber(fileNum) +
				FString(fileExtention);
			absolutePath = saveDirectory + fileName;

			fileExisted = platformFile.FileExists(*absolutePath);
			// file doesn't already exist
			if (fileExisted) {
				UE_LOG(LogTemp, Warning, TEXT("File existed. Generating a new one."));
				fileNum++;
			}
		}
	}
	return absolutePath;
}
