#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSheet.h"
#include "JsonSerializeAndDeserialize.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESHIP_API UJsonSerializeAndDeserialize : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static FString SerializeCharacterSheetToJson(UCharacterSheet* CharacterSheet);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static UCharacterSheet* DeserializeCharacterSheetFromJson(FString CharacterSheetString);

	static TSharedPtr<FJsonObject> SerializeCrewToJsonObject(UCrew* Crew);

	static UCrew* DeserializeCrewFromJsonObject(TSharedPtr<FJsonObject> JsonObject, UObject* Parent);

	static TSharedPtr<FJsonObject> SerializeShipToJsonObject(APlayerShipPawnBase* Ship);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static FString ConvertRaceToString(ERace Race);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static ERace ConvertStringToRace(FString RaceString);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static FString ConvertCharacterBackgroundToString(ECharacterBackground Background);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static ECharacterBackground ConvertStringToCharacterBackground(FString BackgroundString);

	UFUNCTION(BlueprintCallable, Category = "JsonSerializeAndDeserialize")
	static FString ConvertTypeToString(EType Type);
};
