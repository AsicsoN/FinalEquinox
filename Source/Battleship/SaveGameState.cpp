

#include "Battleship.h"
#include "SaveGameState.h"

void ASaveGameState::runSaveGame() {
	UE_LOG(LogTemp, Warning, TEXT("runSaveGame!!"));

	FString saveDirectory = FString(FPaths::GameDir()) + FString("/SaveData");		// location of save directory

																					// save file
	FString fileSurName = FString("battleshipSave");
	int fileNum = 0;												// file name number
	FString fileExtention = FString(".dat");
	FString fileName = FString(fileSurName) +
		FString::FormatAsNumber(fileNum) +
		FString(fileExtention);

	// random data to save file
	FString saveText = FString("Hello battleship!! ") +
		FString::FormatAsNumber(fileNum);
	bool fileExisted = true;										// determines is save file is generated

	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString absoluteFilePath = saveDirectory + "/" + fileName;;

	UE_LOG(LogTemp, Warning, TEXT("Save text contains %s"), *saveText);

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
			absoluteFilePath = saveDirectory + "/" + fileName;

			// update text
			saveText = FString("Hello battleship!! ") +
				FString::FormatAsNumber(fileNum);
			UE_LOG(LogTemp, Warning, TEXT("Save text contains %s"), *saveText);

			fileExisted = platformFile.FileExists(*absoluteFilePath);
			// file doesn't already exist
			if (!fileExisted)
			{
				FFileHelper::SaveStringToFile(saveText, *absoluteFilePath);
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("File existed. Generating a new one."));
				fileNum++;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Save ."));
}

ASaveGameState::ASaveGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("Welcome to MySaveState!!"));
}

void ASaveGameState::SetDataMap(FString key1, FString value1)
{
	dataMap.Add(key1, value1);
}

TMap<FString, FString> ASaveGameState::GetDataMap()
{
	return dataMap;
}


