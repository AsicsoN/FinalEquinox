// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDateTime;
class UObject;
class URamaSaveComponent;
class AActor;
class URamaSaveObject;
#ifdef RAMASAVESYSTEM_RamaSaveLibrary_generated_h
#error "RamaSaveLibrary.generated.h already included, missing '#pragma once' in RamaSaveLibrary.h"
#endif
#define RAMASAVESYSTEM_RamaSaveLibrary_generated_h

#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRamaSavePaths_SavedDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_SavedDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSavePaths_GameRootDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_GameRootDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSavePaths_BinaryLocation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_BinaryLocation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDocumentsFolder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::GetDocumentsFolder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DateTimeFromString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_AsString); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_TheDateTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_DateTimeFromString(Z_Param_AsString,Z_Param_Out_TheDateTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DateTimeToString) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_TheDateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_AsString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_DateTimeToString(Z_Param_Out_TheDateTime,Z_Param_Out_AsString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaFileIO_GetFiles) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FullPathOfBaseDir); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_FilenamesOut); \
		P_GET_UBOOL(Z_Param_Recursive); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilterByExtension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaFileIO_GetFiles(Z_Param_FullPathOfBaseDir,Z_Param_Out_FilenamesOut,Z_Param_Recursive,Z_Param_FilterByExtension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRenameFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dest); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RenameFile(Z_Param_Dest,Z_Param_Source); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_CopyFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dest); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Src); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_CopyFile(Z_Param_Dest,Z_Param_Src); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DeleteFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_DeleteFile(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_GetFileTimeStampText) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_GET_UBOOL(Z_Param_Verbose); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FText*)Z_Param__Result=URamaSaveLibrary::RamaSave_GetFileTimeStampText(Z_Param_File,Z_Param_Verbose); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_GetFileTimeStamp) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FDateTime*)Z_Param__Result=URamaSaveLibrary::RamaSave_GetFileTimeStamp(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_FolderExists) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dir); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_FolderExists(Z_Param_Dir); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_FileExists) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_FileExists(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_ClearLevel) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_DontDestroyPlayers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ClearOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_ClearLevel(Z_Param_WorldContextObject,Z_Param_DontDestroyPlayers,Z_Param_ClearOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveComponentsWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_GET_TARRAY_REF(URamaSaveComponent*,Z_Param_Out_RamaSaveComponents); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GetOnlyStreamingLevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveComponentsWithTags(Z_Param_WorldContextObject,Z_Param_Out_SaveTags,Z_Param_Out_RamaSaveComponents,Z_Param_GetOnlyStreamingLevelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveComponents) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(URamaSaveComponent*,Z_Param_Out_RamaSaveComponents); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GetOnlyStreamingLevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveComponents(Z_Param_WorldContextObject,Z_Param_Out_RamaSaveComponents,Z_Param_GetOnlyStreamingLevelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveActorsWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_RamaSaveActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveActorsWithTags(Z_Param_WorldContextObject,Z_Param_Out_SaveTags,Z_Param_Out_RamaSaveActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveActors) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_RamaSaveActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveActors(Z_Param_WorldContextObject,Z_Param_Out_RamaSaveActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadFromFileWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_LoadOnlyActorsWithSaveTags); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL(Z_Param_DestroyActorsBeforeLoad); \
		P_GET_UBOOL(Z_Param_DontLoadPlayerPawns); \
		P_GET_UBOOL(Z_Param_HandleStreamingLevelsLoadingAndUnloading); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LoadOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_LoadFromFileWithTags(Z_Param_WorldContextObject,Z_Param_Out_LoadOnlyActorsWithSaveTags,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_DestroyActorsBeforeLoad,Z_Param_DontLoadPlayerPawns,Z_Param_HandleStreamingLevelsLoadingAndUnloading,Z_Param_LoadOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadStreamingStateFromFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StreamingLevelsStates); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URamaSaveLibrary::RamaSave_LoadStreamingStateFromFile(Z_Param_WorldContextObject,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_Out_StreamingLevelsStates); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadFromFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL(Z_Param_DestroyActorsBeforeLoad); \
		P_GET_UBOOL(Z_Param_DontLoadPlayerPawns); \
		P_GET_UBOOL(Z_Param_HandleStreamingLevelsLoadingAndUnloading); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LoadOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_LoadFromFile(Z_Param_WorldContextObject,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_DestroyActorsBeforeLoad,Z_Param_DontLoadPlayerPawns,Z_Param_HandleStreamingLevelsLoadingAndUnloading,Z_Param_LoadOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadStaticDataFromFile) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(URamaSaveObject**)Z_Param__Result=URamaSaveLibrary::RamaSave_LoadStaticDataFromFile(Z_Param_Out_FileIOSuccess,Z_Param_FileName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_CancelAsyncSaveProcess) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_CancelAsyncSaveProcess(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_SaveToFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_UBOOL_REF(Z_Param_Out_AllComponentsSaved); \
		P_GET_PROPERTY(UStrProperty,Z_Param_SaveOnlyStreamingLevel); \
		P_GET_OBJECT(URamaSaveObject,Z_Param_StaticSaveData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_SaveToFile(Z_Param_WorldContextObject,Z_Param_FileName,Z_Param_Out_FileIOSuccess,Z_Param_Out_AllComponentsSaved,Z_Param_SaveOnlyStreamingLevel,Z_Param_StaticSaveData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveLevelPIEPrefix) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RemoveLevelPIEPrefix(Z_Param_LevelName); \
		P_NATIVE_END; \
	}


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRamaSavePaths_SavedDir) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_SavedDir(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSavePaths_GameRootDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_GameRootDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSavePaths_BinaryLocation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RamaSavePaths_BinaryLocation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetDocumentsFolder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::GetDocumentsFolder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DateTimeFromString) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_AsString); \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_TheDateTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_DateTimeFromString(Z_Param_AsString,Z_Param_Out_TheDateTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DateTimeToString) \
	{ \
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_TheDateTime); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_AsString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_DateTimeToString(Z_Param_Out_TheDateTime,Z_Param_Out_AsString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaFileIO_GetFiles) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FullPathOfBaseDir); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_FilenamesOut); \
		P_GET_UBOOL(Z_Param_Recursive); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FilterByExtension); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaFileIO_GetFiles(Z_Param_FullPathOfBaseDir,Z_Param_Out_FilenamesOut,Z_Param_Recursive,Z_Param_FilterByExtension); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRenameFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dest); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RenameFile(Z_Param_Dest,Z_Param_Source); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_CopyFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dest); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Src); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_CopyFile(Z_Param_Dest,Z_Param_Src); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_DeleteFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_DeleteFile(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_GetFileTimeStampText) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_GET_UBOOL(Z_Param_Verbose); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FText*)Z_Param__Result=URamaSaveLibrary::RamaSave_GetFileTimeStampText(Z_Param_File,Z_Param_Verbose); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_GetFileTimeStamp) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FDateTime*)Z_Param__Result=URamaSaveLibrary::RamaSave_GetFileTimeStamp(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_FolderExists) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Dir); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_FolderExists(Z_Param_Dir); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_FileExists) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_File); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_FileExists(Z_Param_File); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_ClearLevel) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_DontDestroyPlayers); \
		P_GET_PROPERTY(UStrProperty,Z_Param_ClearOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_ClearLevel(Z_Param_WorldContextObject,Z_Param_DontDestroyPlayers,Z_Param_ClearOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveComponentsWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_GET_TARRAY_REF(URamaSaveComponent*,Z_Param_Out_RamaSaveComponents); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GetOnlyStreamingLevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveComponentsWithTags(Z_Param_WorldContextObject,Z_Param_Out_SaveTags,Z_Param_Out_RamaSaveComponents,Z_Param_GetOnlyStreamingLevelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveComponents) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(URamaSaveComponent*,Z_Param_Out_RamaSaveComponents); \
		P_GET_PROPERTY(UStrProperty,Z_Param_GetOnlyStreamingLevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveComponents(Z_Param_WorldContextObject,Z_Param_Out_RamaSaveComponents,Z_Param_GetOnlyStreamingLevelName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveActorsWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_RamaSaveActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveActorsWithTags(Z_Param_WorldContextObject,Z_Param_Out_SaveTags,Z_Param_Out_RamaSaveActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllRamaSaveActors) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_RamaSaveActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::GetAllRamaSaveActors(Z_Param_WorldContextObject,Z_Param_Out_RamaSaveActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadFromFileWithTags) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_LoadOnlyActorsWithSaveTags); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL(Z_Param_DestroyActorsBeforeLoad); \
		P_GET_UBOOL(Z_Param_DontLoadPlayerPawns); \
		P_GET_UBOOL(Z_Param_HandleStreamingLevelsLoadingAndUnloading); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LoadOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_LoadFromFileWithTags(Z_Param_WorldContextObject,Z_Param_Out_LoadOnlyActorsWithSaveTags,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_DestroyActorsBeforeLoad,Z_Param_DontLoadPlayerPawns,Z_Param_HandleStreamingLevelsLoadingAndUnloading,Z_Param_LoadOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadStreamingStateFromFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StreamingLevelsStates); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=URamaSaveLibrary::RamaSave_LoadStreamingStateFromFile(Z_Param_WorldContextObject,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_Out_StreamingLevelsStates); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadFromFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL(Z_Param_DestroyActorsBeforeLoad); \
		P_GET_UBOOL(Z_Param_DontLoadPlayerPawns); \
		P_GET_UBOOL(Z_Param_HandleStreamingLevelsLoadingAndUnloading); \
		P_GET_PROPERTY(UStrProperty,Z_Param_LoadOnlyStreamingLevel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_LoadFromFile(Z_Param_WorldContextObject,Z_Param_Out_FileIOSuccess,Z_Param_FileName,Z_Param_DestroyActorsBeforeLoad,Z_Param_DontLoadPlayerPawns,Z_Param_HandleStreamingLevelsLoadingAndUnloading,Z_Param_LoadOnlyStreamingLevel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_LoadStaticDataFromFile) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(URamaSaveObject**)Z_Param__Result=URamaSaveLibrary::RamaSave_LoadStaticDataFromFile(Z_Param_Out_FileIOSuccess,Z_Param_FileName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_CancelAsyncSaveProcess) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URamaSaveLibrary::RamaSave_CancelAsyncSaveProcess(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_SaveToFile) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_UBOOL_REF(Z_Param_Out_FileIOSuccess); \
		P_GET_UBOOL_REF(Z_Param_Out_AllComponentsSaved); \
		P_GET_PROPERTY(UStrProperty,Z_Param_SaveOnlyStreamingLevel); \
		P_GET_OBJECT(URamaSaveObject,Z_Param_StaticSaveData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveLibrary::RamaSave_SaveToFile(Z_Param_WorldContextObject,Z_Param_FileName,Z_Param_Out_FileIOSuccess,Z_Param_Out_AllComponentsSaved,Z_Param_SaveOnlyStreamingLevel,Z_Param_StaticSaveData); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveLevelPIEPrefix) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_LevelName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=URamaSaveLibrary::RemoveLevelPIEPrefix(Z_Param_LevelName); \
		P_NATIVE_END; \
	}


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURamaSaveLibrary(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveLibrary(); \
public: \
	DECLARE_CLASS(URamaSaveLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(URamaSaveLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_INCLASS \
private: \
	static void StaticRegisterNativesURamaSaveLibrary(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveLibrary(); \
public: \
	DECLARE_CLASS(URamaSaveLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(URamaSaveLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URamaSaveLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URamaSaveLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URamaSaveLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URamaSaveLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URamaSaveLibrary(URamaSaveLibrary&&); \
	NO_API URamaSaveLibrary(const URamaSaveLibrary&); \
public:


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URamaSaveLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URamaSaveLibrary(URamaSaveLibrary&&); \
	NO_API URamaSaveLibrary(const URamaSaveLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URamaSaveLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URamaSaveLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URamaSaveLibrary)


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_PRIVATE_PROPERTY_OFFSET
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_12_PROLOG
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_RPC_WRAPPERS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_INCLASS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_INCLASS_NO_PURE_DECLS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
