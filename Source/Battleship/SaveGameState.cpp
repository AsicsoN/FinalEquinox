

#include "Battleship.h"
#include "SaveGameState.h"
<<<<<<< HEAD
#include "CharacterSheet.h"

void ASaveGameState::runSaveGame() {
	UE_LOG(LogTemp, Warning, TEXT("runSaveGame!!"));

	FString saveDirectory = FString(FPaths::GameDir()) + FString("/SaveData");		// location of save directory

																					// save file
	FString fileSurName = FString("battleshipSave");
	int fileNum = 0;												// file name number
	FString fileExtention = FString(".dat");
=======

ASaveGameState::ASaveGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("Welcome to MySaveState!!"));
}

FString ASaveGameState::GenerateLatestSave() {
	UE_LOG(LogTemp, Warning, TEXT("SaveGameState::generateSaveLocation"));
	FString saveDirectory = FString(FPaths::GameSavedDir()) + FString("SaveGames/");		// location of save directory

																					// save file
	FString fileSurName = FString("save");
	bool fileExisted = true;					// determines is save file is generated
	int fileNum = 0;							// file name number
	FString fileExtention = FString(".sav");
>>>>>>> pause_menu
	FString fileName = FString(fileSurName) +
		FString::FormatAsNumber(fileNum) +
		FString(fileExtention);

<<<<<<< HEAD
	GetDataMap();

	// random data to save file
	FString saveText = FString("Hello battleship!! ") +
		FString::FormatAsNumber(fileNum);
	bool fileExisted = true;										// determines is save file is generated

	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString absoluteFilePath = saveDirectory + "/" + fileName;;

	UE_LOG(LogTemp, Warning, TEXT("Save text contains %s"), *saveText);
=======
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString absolutePath = saveDirectory + fileName;
>>>>>>> pause_menu

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
<<<<<<< HEAD
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
=======
			absolutePath = saveDirectory + fileName;

			fileExisted = platformFile.FileExists(*absolutePath);
			// file doesn't already exist
			if (fileExisted) {
>>>>>>> pause_menu
				UE_LOG(LogTemp, Warning, TEXT("File existed. Generating a new one."));
				fileNum++;
			}
		}
	}
<<<<<<< HEAD
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
	UCharacterSheet tempCharacter;
	dataMap.Add("name", tempCharacter.Name);
	return dataMap;
}


=======
	return absolutePath;
}
>>>>>>> pause_menu
