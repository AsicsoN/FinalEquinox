#include "Battleship.h"
#include "SettingsHelper.h"

float USettingsHelper::GetFloat(FString name)
{
	FString FilePath = FString(FPaths::ProjectSavedDir()) + FString("Config/Settings.txt");

	if (!FPaths::FileExists(FilePath))
	{
		// Default volume levels
		FString output = FString("MusicVolume=0.3\nEffectsVolume=0.5\nUIVolume=0.6\n");
		FFileHelper::SaveStringToFile(output, *FilePath);
	}

	FString FileData = "";
	FFileHelper::LoadFileToString(FileData, *FilePath);

	TArray<FString> Lines;
	FileData.ParseIntoArrayLines(Lines, true);

	for (FString Line : Lines)
	{
		FString left;
		FString right;
		if (Line.Split(FString("="), &left, &right))
		{
			if (left.Compare(name, ESearchCase::IgnoreCase) == 0)
			{
				if (right.IsNumeric())
				{
					return FCString::Atof(*right);
				}
			}
		}
	}

	return 0.5f;
}

void USettingsHelper::SetFloat(FString name, float value)
{
	FString FilePath = FString(FPaths::ProjectSavedDir()) + FString("Config/Settings.txt");

	if (!FPaths::FileExists(FilePath))
	{
		FString output = FString("");
		FFileHelper::SaveStringToFile(output, *FilePath);
	}

	FString FileData = "";
	FFileHelper::LoadFileToString(FileData, *FilePath);

	TArray<FString> Lines;
	FileData.ParseIntoArrayLines(Lines, true);

	FString output = FString("");
	bool lineFound = false;

	for (FString Line : Lines)
	{
		FString left;
		FString right;
		if (Line.Split(FString("="), &left, &right))
		{
			if (left.Compare(name, ESearchCase::IgnoreCase) == 0)
			{
				output += name + FString("=") + FString::SanitizeFloat(value) + FString("\n");
				lineFound = true;
			}
			else
			{
				output += Line + FString("\n");
			}
		}
		else
		{
			output += Line + FString("\n");
		}
	}

	if (!lineFound)
	{
		output += name + FString("=") + FString::SanitizeFloat(value) + FString("\n");
	}

	FFileHelper::SaveStringToFile(output, *FilePath);
}

float USettingsHelper::GetMusicVolume()
{
	return USettingsHelper::GetFloat(FString("MusicVolume"));
}

float USettingsHelper::GetEffectsVolume()
{
	return USettingsHelper::GetFloat(FString("EffectsVolume"));
}

float USettingsHelper::GetUIVolume()
{
	return USettingsHelper::GetFloat(FString("UIVolume"));
}

void USettingsHelper::SetMusicVolume(float value)
{
	SetFloat(FString("MusicVolume"), value);
}

void USettingsHelper::SetEffectsVolume( float value)
{
	SetFloat(FString("EffectsVolume"), value);
}

void USettingsHelper::SetUIVolume(float value)
{
	SetFloat(FString("UIVolume"), value);
}