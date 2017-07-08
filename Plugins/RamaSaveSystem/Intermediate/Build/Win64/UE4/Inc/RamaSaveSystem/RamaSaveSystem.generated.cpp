// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/RamaSaveSystemPrivatePCH.h"
#include "RamaSaveSystem.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1RamaSaveSystem() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();
	ENGINE_API class UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FVector_NetQuantize100();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_ULevelStreaming_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	ENGINE_API class UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API class UClass* Z_Construct_UClass_UDeveloperSettings();

	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveUtility_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveUtility();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaPlayerLoadedSignature__DelegateSignature();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSavePreSaveSignature__DelegateSignature();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSaveFullyLoadedSignature__DelegateSignature();
	RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBLoad();
	RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBSave();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_GetActorIsInPersistentLevel();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_GetActorStreamingLevelPackageName();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasAnyOfSaveTags();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasSaveTag();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_PostLoad();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_PreSave();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveComponent_Test();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveComponent_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveComponent();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveObject_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveObject();
	RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRamaSaveEngineParams();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_ProgressUpdate();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveCancelled();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveFinished();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveStarted();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_ARamaSaveEngine_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_ARamaSaveEngine();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActors();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActorsWithTags();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponents();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponentsWithTags();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetDocumentsFolder();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaFileIO_GetFiles();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CancelAsyncSaveProcess();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_ClearLevel();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CopyFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeFromString();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeToString();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DeleteFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FileExists();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FolderExists();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStamp();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStampText();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFileWithTags();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStaticDataFromFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStreamingStateFromFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_SaveToFile();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_BinaryLocation();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_GameRootDirectory();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_SavedDir();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RemoveLevelPIEPrefix();
	RAMASAVESYSTEM_API class UFunction* Z_Construct_UFunction_URamaSaveLibrary_RenameFile();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveLibrary_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveLibrary();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveSystemSettings_NoRegister();
	RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveSystemSettings();
	RAMASAVESYSTEM_API class UPackage* Z_Construct_UPackage__Script_RamaSaveSystem();
	void URamaSaveUtility::StaticRegisterNativesURamaSaveUtility()
	{
	}
	UClass* Z_Construct_UClass_URamaSaveUtility_NoRegister()
	{
		return URamaSaveUtility::StaticClass();
	}
	UClass* Z_Construct_UClass_URamaSaveUtility()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = URamaSaveUtility::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;


				static TCppClassTypeInfo<TCppClassTypeTraits<URamaSaveUtility> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveUtility.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveUtility.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URamaSaveUtility, 1002914171);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URamaSaveUtility(Z_Construct_UClass_URamaSaveUtility, &URamaSaveUtility::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("URamaSaveUtility"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URamaSaveUtility);
	UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaPlayerLoadedSignature__DelegateSignature()
	{
		struct _Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms
		{
			APlayerController* PC;
			APawn* Pawn;
			int32 PlayerIndex;
		};
		UObject* Outer=Z_Construct_UPackage__Script_RamaSaveSystem();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaPlayerLoadedSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), NULL, 0x00130000, 65535, sizeof(_Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms));
			UProperty* NewProp_PlayerIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("PlayerIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(PlayerIndex, _Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms), 0x0010000000000080);
			UProperty* NewProp_Pawn = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Pawn"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Pawn, _Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms), 0x0010000000000080, Z_Construct_UClass_APawn_NoRegister());
			UProperty* NewProp_PC = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("PC"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(PC, _Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms), 0x0010000000000080, Z_Construct_UClass_APlayerController_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSavePreSaveSignature__DelegateSignature()
	{
		struct _Script_RamaSaveSystem_eventRamaSavePreSaveSignature_Parms
		{
			URamaSaveComponent* RamaSaveComponent;
		};
		UObject* Outer=Z_Construct_UPackage__Script_RamaSaveSystem();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSavePreSaveSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), NULL, 0x00130000, 65535, sizeof(_Script_RamaSaveSystem_eventRamaSavePreSaveSignature_Parms));
			UProperty* NewProp_RamaSaveComponent = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(RamaSaveComponent, _Script_RamaSaveSystem_eventRamaSavePreSaveSignature_Parms), 0x0010000000080080, Z_Construct_UClass_URamaSaveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_RamaSaveComponent, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSaveFullyLoadedSignature__DelegateSignature()
	{
		struct _Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms
		{
			URamaSaveComponent* RamaSaveComponent;
			FString LevelPackageName;
		};
		UObject* Outer=Z_Construct_UPackage__Script_RamaSaveSystem();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSaveFullyLoadedSignature__DelegateSignature"), RF_Public|RF_Transient|RF_MarkAsNative) UDelegateFunction(FObjectInitializer(), NULL, 0x00130000, 65535, sizeof(_Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms));
			UProperty* NewProp_LevelPackageName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("LevelPackageName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(LevelPackageName, _Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms), 0x0010000000000080);
			UProperty* NewProp_RamaSaveComponent = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(RamaSaveComponent, _Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms), 0x0010000000080080, Z_Construct_UClass_URamaSaveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_RamaSaveComponent, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
class UScriptStruct* FRBLoad::StaticStruct()
{
	extern RAMASAVESYSTEM_API class UPackage* Z_Construct_UPackage__Script_RamaSaveSystem();
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBLoad();
		extern RAMASAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FRBLoad_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRBLoad, Z_Construct_UPackage__Script_RamaSaveSystem(), TEXT("RBLoad"), sizeof(FRBLoad), Get_Z_Construct_UScriptStruct_FRBLoad_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRBLoad(FRBLoad::StaticStruct, TEXT("/Script/RamaSaveSystem"), TEXT("RBLoad"), false, nullptr, nullptr);
static struct FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBLoad
{
	FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBLoad()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RBLoad")),new UScriptStruct::TCppStructOps<FRBLoad>);
	}
} ScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBLoad;
	UScriptStruct* Z_Construct_UScriptStruct_FRBLoad()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_RamaSaveSystem();
		extern uint32 Get_Z_Construct_UScriptStruct_FRBLoad_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RBLoad"), sizeof(FRBLoad), Get_Z_Construct_UScriptStruct_FRBLoad_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RBLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FRBLoad>, EStructFlags(0x00000001));
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(ReturnStruct, TEXT("ToolTip"), TEXT("Runtime Only\n Needed for the PhysicsTimer, see .cpp for explanation of PhysicsTimer\n               This struct allows me to not save RB State for every primitive component in the whole world ;)\n                       by pairing each comp with the PhysState to be loaded"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRBLoad_CRC() { return 1325378150U; }
class UScriptStruct* FRBSave::StaticStruct()
{
	extern RAMASAVESYSTEM_API class UPackage* Z_Construct_UPackage__Script_RamaSaveSystem();
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBSave();
		extern RAMASAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FRBSave_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRBSave, Z_Construct_UPackage__Script_RamaSaveSystem(), TEXT("RBSave"), sizeof(FRBSave), Get_Z_Construct_UScriptStruct_FRBSave_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRBSave(FRBSave::StaticStruct, TEXT("/Script/RamaSaveSystem"), TEXT("RBSave"), false, nullptr, nullptr);
static struct FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBSave
{
	FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBSave()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RBSave")),new UScriptStruct::TCppStructOps<FRBSave>);
	}
} ScriptStruct_RamaSaveSystem_StaticRegisterNativesFRBSave;
	UScriptStruct* Z_Construct_UScriptStruct_FRBSave()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_RamaSaveSystem();
		extern uint32 Get_Z_Construct_UScriptStruct_FRBSave_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RBSave"), sizeof(FRBSave), Get_Z_Construct_UScriptStruct_FRBSave_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RBSave"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FRBSave>, EStructFlags(0x00000001));
			UProperty* NewProp_AngularVelocity = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("AngularVelocity"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(AngularVelocity, FRBSave), 0x0010000000000000, Z_Construct_UScriptStruct_FVector_NetQuantize100());
			UProperty* NewProp_LinearVelocity = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("LinearVelocity"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(LinearVelocity, FRBSave), 0x0010000000000000, Z_Construct_UScriptStruct_FVector_NetQuantize100());
			UProperty* NewProp_PhysicsRotation = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("PhysicsRotation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(PhysicsRotation, FRBSave), 0x0010000000000000, Z_Construct_UScriptStruct_FQuat());
			UProperty* NewProp_PhysicsLocation = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("PhysicsLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(PhysicsLocation, FRBSave), 0x0010000000000000, Z_Construct_UScriptStruct_FVector_NetQuantize100());
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(ReturnStruct, TEXT("ToolTip"), TEXT("Only intended for Static Meshs support, not skeletal ragdoll"));
			MetaData->SetValue(NewProp_AngularVelocity, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_LinearVelocity, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_PhysicsRotation, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_PhysicsLocation, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRBSave_CRC() { return 2254215919U; }
	static FName NAME_URamaSaveComponent_RamaSave_PostLoad = FName(TEXT("RamaSave_PostLoad"));
	void URamaSaveComponent::RamaSave_PostLoad()
	{
		ProcessEvent(FindFunctionChecked(NAME_URamaSaveComponent_RamaSave_PostLoad),NULL);
	}
	static FName NAME_URamaSaveComponent_RamaSave_PreSave = FName(TEXT("RamaSave_PreSave"));
	void URamaSaveComponent::RamaSave_PreSave()
	{
		ProcessEvent(FindFunctionChecked(NAME_URamaSaveComponent_RamaSave_PreSave),NULL);
	}
	void URamaSaveComponent::StaticRegisterNativesURamaSaveComponent()
	{
		UClass* Class = URamaSaveComponent::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetActorIsInPersistentLevel", (Native)&URamaSaveComponent::execGetActorIsInPersistentLevel },
			{ "GetActorStreamingLevelPackageName", (Native)&URamaSaveComponent::execGetActorStreamingLevelPackageName },
			{ "RamaSave_HasAnyOfSaveTags", (Native)&URamaSaveComponent::execRamaSave_HasAnyOfSaveTags },
			{ "RamaSave_HasSaveTag", (Native)&URamaSaveComponent::execRamaSave_HasSaveTag },
			{ "Test", (Native)&URamaSaveComponent::execTest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 5);
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_GetActorIsInPersistentLevel()
	{
		struct RamaSaveComponent_eventGetActorIsInPersistentLevel_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetActorIsInPersistentLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14020401, 65535, sizeof(RamaSaveComponent_eventGetActorIsInPersistentLevel_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveComponent_eventGetActorIsInPersistentLevel_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveComponent_eventGetActorIsInPersistentLevel_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveComponent_eventGetActorIsInPersistentLevel_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Is the owner of this component in the persistent level? :) <3 Rama"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_GetActorStreamingLevelPackageName()
	{
		struct RamaSaveComponent_eventGetActorStreamingLevelPackageName_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetActorStreamingLevelPackageName"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14020401, 65535, sizeof(RamaSaveComponent_eventGetActorStreamingLevelPackageName_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveComponent_eventGetActorStreamingLevelPackageName_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function tells you which streaming level the owner of this component is part of!!!! Yes!!! Those of you using UE4's Level Streaming system will love me for this! <3 Rama"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasAnyOfSaveTags()
	{
		struct RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms
		{
			TArray<FString> SaveTags;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_HasAnyOfSaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14420401, 65535, sizeof(RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms), sizeof(bool), true);
			UProperty* NewProp_SaveTags = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(SaveTags, RamaSaveComponent_eventRamaSave_HasAnyOfSaveTags_Parms), 0x0010000008000182);
			UProperty* NewProp_SaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_SaveTags, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
			MetaData->SetValue(NewProp_SaveTags, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasSaveTag()
	{
		struct RamaSaveComponent_eventRamaSave_HasSaveTag_Parms
		{
			FString SaveTag;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_HasSaveTag"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14020401, 65535, sizeof(RamaSaveComponent_eventRamaSave_HasSaveTag_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveComponent_eventRamaSave_HasSaveTag_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveComponent_eventRamaSave_HasSaveTag_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveComponent_eventRamaSave_HasSaveTag_Parms), sizeof(bool), true);
			UProperty* NewProp_SaveTag = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SaveTag"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SaveTag, RamaSaveComponent_eventRamaSave_HasSaveTag_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_PostLoad()
	{
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_PostLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_RamaSave_PreSave()
	{
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_PreSave"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveComponent_Test()
	{
		struct RamaSaveComponent_eventTest_Parms
		{
			UScriptStruct* Struct;
			TArray<uint8> ByteData;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Test"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(RamaSaveComponent_eventTest_Parms));
			UProperty* NewProp_ByteData = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ByteData"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ByteData, RamaSaveComponent_eventTest_Parms), 0x0010000000000180);
			UProperty* NewProp_ByteData_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ByteData, TEXT("ByteData"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_Struct = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Struct"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Struct, RamaSaveComponent_eventTest_Parms), 0x0010000000000080, UScriptStruct::StaticClass());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URamaSaveComponent_NoRegister()
	{
		return URamaSaveComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URamaSaveComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = URamaSaveComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;

				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_GetActorIsInPersistentLevel());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_GetActorStreamingLevelPackageName());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasAnyOfSaveTags());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasSaveTag());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_RamaSave_PostLoad());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_RamaSave_PreSave());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveComponent_Test());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_OwningActorTransform = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("OwningActorTransform"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(OwningActorTransform, URamaSaveComponent), 0x0010000000000000, Z_Construct_UScriptStruct_FTransform());
				UProperty* NewProp_RamaSaveEvent_PlayerLoaded = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSaveEvent_PlayerLoaded"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(RamaSaveEvent_PlayerLoaded, URamaSaveComponent), 0x0010000010080000, Z_Construct_UDelegateFunction_RamaSaveSystem_RamaPlayerLoadedSignature__DelegateSignature());
				UProperty* NewProp_RamaSaveEvent_PreSave = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSaveEvent_PreSave"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(RamaSaveEvent_PreSave, URamaSaveComponent), 0x0010000010080000, Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSavePreSaveSignature__DelegateSignature());
				UProperty* NewProp_RamaSaveEvent_ActorFullyLoaded = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSaveEvent_ActorFullyLoaded"), RF_Public|RF_Transient|RF_MarkAsNative) UMulticastDelegateProperty(CPP_PROPERTY_BASE(RamaSaveEvent_ActorFullyLoaded, URamaSaveComponent), 0x0010000010080000, Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSaveFullyLoadedSignature__DelegateSignature());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_SavePhysicsData, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_SavePhysicsData = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_SavePhysicsData"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_SavePhysicsData, URamaSaveComponent), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_SavePhysicsData, URamaSaveComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_LogAllSavedComponentProperties, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_LogAllSavedComponentProperties = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_LogAllSavedComponentProperties"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_LogAllSavedComponentProperties, URamaSaveComponent), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_LogAllSavedComponentProperties, URamaSaveComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_VerboseLog, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_VerboseLog = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_VerboseLog"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_VerboseLog, URamaSaveComponent), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_VerboseLog, URamaSaveComponent), sizeof(bool), true);
				UProperty* NewProp_RamaSave_ComponentVarsToSave = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_ComponentVarsToSave"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSave_ComponentVarsToSave, URamaSaveComponent), 0x0010000000000005);
				UProperty* NewProp_RamaSave_ComponentVarsToSave_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSave_ComponentVarsToSave, TEXT("RamaSave_ComponentVarsToSave"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_RamaSave_OwningActorVarsToSave = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_OwningActorVarsToSave"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSave_OwningActorVarsToSave, URamaSaveComponent), 0x0010000000000005);
				UProperty* NewProp_RamaSave_OwningActorVarsToSave_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSave_OwningActorVarsToSave, TEXT("RamaSave_OwningActorVarsToSave"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_ShouldSaveActor, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_ShouldSaveActor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_ShouldSaveActor"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_ShouldSaveActor, URamaSaveComponent), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_ShouldSaveActor, URamaSaveComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_ShouldLoadActorWorldPosition, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_ShouldLoadActorWorldPosition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_ShouldLoadActorWorldPosition"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_ShouldLoadActorWorldPosition, URamaSaveComponent), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_ShouldLoadActorWorldPosition, URamaSaveComponent), sizeof(bool), true);
				UProperty* NewProp_RamaSave_SaveTags = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSave_SaveTags, URamaSaveComponent), 0x0010000000000005);
				UProperty* NewProp_RamaSave_SaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSave_SaveTags, TEXT("RamaSave_SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(RamaSave_LogPersistentActorGUID, URamaSaveComponent, bool);
				UProperty* NewProp_RamaSave_LogPersistentActorGUID = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_LogPersistentActorGUID"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(RamaSave_LogPersistentActorGUID, URamaSaveComponent), 0x0010000000010005, CPP_BOOL_PROPERTY_BITMASK(RamaSave_LogPersistentActorGUID, URamaSaveComponent), sizeof(bool), true);
				UProperty* NewProp_RamaSave_PersistentActorUniqueID = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSave_PersistentActorUniqueID"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(RamaSave_PersistentActorUniqueID, URamaSaveComponent), 0x0010000000000005, Z_Construct_UScriptStruct_FGuid());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_GetActorIsInPersistentLevel(), "GetActorIsInPersistentLevel"); // 3994628863
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_GetActorStreamingLevelPackageName(), "GetActorStreamingLevelPackageName"); // 3073467157
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasAnyOfSaveTags(), "RamaSave_HasAnyOfSaveTags"); // 2710562799
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_RamaSave_HasSaveTag(), "RamaSave_HasSaveTag"); // 1921163087
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_RamaSave_PostLoad(), "RamaSave_PostLoad"); // 3965257358
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_RamaSave_PreSave(), "RamaSave_PreSave"); // 3563546169
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveComponent_Test(), "Test"); // 66864536
				static TCppClassTypeInfo<TCppClassTypeTraits<URamaSaveComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Rama"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("~~~ Rama Save System ~~~\n\n1. When saving, all actors with Rama Save Components are saved to disk!\n        These methods are called, in order:\n                a. RamaSave_PreSave_CPP()\n                b. RamaSave_PreSave()\n                c. RamaSaveEvent_PreSave()\n\n2. When loading, any existing actors with Rama Save Components are deleted!\n        These methods are called, in order:\n                a. RamaSave_PostLoad_CPP()\n                a. RamaSave_PostLoad()\n                b. RamaSaveEvent_ActorFullyLoaded()"));
				MetaData->SetValue(NewProp_OwningActorTransform, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSaveEvent_PlayerLoaded, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSaveEvent_PlayerLoaded, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSaveEvent_PreSave, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSaveEvent_PreSave, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSaveEvent_ActorFullyLoaded, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSaveEvent_ActorFullyLoaded, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_SavePhysicsData, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_SavePhysicsData, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_SavePhysicsData, TEXT("ToolTip"), TEXT("Whether to save/load Physics data for all primitive components of the Owning Actor. Please note that runtime dynamically added primitive components (static mesh, skel mesh) cannot be saved/loaded using my built in system. Custom BP or C++ code is required."));
				MetaData->SetValue(NewProp_RamaSave_LogAllSavedComponentProperties, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_LogAllSavedComponentProperties, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_LogAllSavedComponentProperties, TEXT("ToolTip"), TEXT("Whether to print out all properties of this Rama Save Component that are being saved to disk! <3"));
				MetaData->SetValue(NewProp_RamaSave_VerboseLog, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_VerboseLog, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_VerboseLog, TEXT("ToolTip"), TEXT("Whether to print extra information about the saving / loading process of this Rama Save Component, including reminders of which Actor Properties are not being saved in the list."));
				MetaData->SetValue(NewProp_RamaSave_ComponentVarsToSave, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_ComponentVarsToSave, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_ComponentVarsToSave, TEXT("ToolTip"), TEXT("If you want to save variables present in a subcomponent of this Actor\n then add them to this list!\n\n\nEssential Note: Component properties to be saved MUST have unique names\n  among all the other components and their variable names of the owning Actor.\n\nIf your variable is not getting saved/loaded properly, make sure it has a unique name!\n\n\nIf you later remove the component I will ignore the no-longer-valid saved data for the component!\n\nThis prevents the save system from crashing!\n\n<3 Rama"));
				MetaData->SetValue(NewProp_RamaSave_OwningActorVarsToSave, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_OwningActorVarsToSave, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_OwningActorVarsToSave, TEXT("ToolTip"), TEXT("~~~ All variables of this component are saved automatically for you! ~~~\n\nThis is a list of vars to save/load corresponding to the ~ owning actor ~ of this component.\n\nVariables can be from C++ base classes of the owning Actor or can be Blueprint-created!\n\nOther actor component variables of the owning actor are ignored.\n\nIt is a primary feature of the Rama Save System that you can simply enter Actor variable names\ninto this list and they will be saved for you, along with any variables you create for the Rama Save Component.\n\nSuggestion: Turn off ShowFriendlyNames via Editor Preferences to see accurate names to copy/paste.\n\n<3 Rama"));
				MetaData->SetValue(NewProp_RamaSave_ShouldSaveActor, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_ShouldSaveActor, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_ShouldSaveActor, TEXT("ToolTip"), TEXT("Customize whether or not a particular actor should be saved based on game conditions, such as whether the unit is alive!"));
				MetaData->SetValue(NewProp_RamaSave_ShouldLoadActorWorldPosition, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_ShouldLoadActorWorldPosition, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_ShouldLoadActorWorldPosition, TEXT("ToolTip"), TEXT("Customize whether or not a particular actor should be teleported to its position at the time of saving after a load has completed!\n\nIf this is false, all the data will be loaded into the actor, but the actor's transform will not be changed (position, rotation, scaling)\n\nYou are then free to apply custom logic as to what to do with a unit after a load event, inside of Actor Fully Loaded.\n\n<3 Rama"));
				MetaData->SetValue(NewProp_RamaSave_SaveTags, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_SaveTags, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_SaveTags, TEXT("ToolTip"), TEXT("Add tags to instances of an actor class / blueprint so you can identify to my save system which actors you want to load.\n\nThese tags are optional, and are ideal for things like level streaming or any other game-specific conditions where you want to selectively load actors based on your own game's needs."));
				MetaData->SetValue(NewProp_RamaSave_LogPersistentActorGUID, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_LogPersistentActorGUID, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_LogPersistentActorGUID, TEXT("ToolTip"), TEXT("Whether to log information regarding Actor GUID Saving and Loading"));
				MetaData->SetValue(NewProp_RamaSave_PersistentActorUniqueID, TEXT("Category"), TEXT("Rama Save System"));
				MetaData->SetValue(NewProp_RamaSave_PersistentActorUniqueID, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveComponent.h"));
				MetaData->SetValue(NewProp_RamaSave_PersistentActorUniqueID, TEXT("ToolTip"), TEXT("If you generate a unique ID for an instance of your actor that uses this component:\n\n1. I will NOT destroy the actor during level loading!\n\n2. I will save the unique ID with the data chunk and during loading, I will find an actor that has the same unique id and load the data to that actor.\n\nAll of my load events will still be called, like Actor Fully Loaded, but I will not be destroying the actor, only reloading data.\n\nThis is great for actors in your level blueprint or persistent actors that you don't want to destroy, including player characters and items that never leave the world.\n\n~~~ Unique Ids Must be Unique! ~~~\n3. Please understand that id's must be unique per instance, not per class, because that is the only way my save system can know exactly which actor to load data into.\n\nFor this reason it is best to generate a unique id in your constructor, if no valid GUID has been set yet.\n\n~~~ Actor Duplication ~~~\n4. Please note that during widget-drag actor duplication, the BP constructor does not run, you will have to manually click to generate a unique ID for duplicated actors.\n\nI am still investigating how to trigger a BP constructor activation during actor duplication without needing an editor plugin.\n\n~~~ Reversing the Process ~~~\nIf you change your mind, just invalidate the guid so it goes back to 0's and my save system will delete/recreate the actor again.\n\n~~~ Debugging ~~~\nCheck your log to see if I am ever ignoring two actors with the same GUID, and find the actors that are sharing the GUID and generate new unique ids for the actors.\n\nThe only likely bug you can encounter is if you have 2+ actors using same GUID, then my save system will be confused :)\n\nEvery actor instance in the world or spawned into the world MUST have a unique GUID :)\n\n\x2665 Rama"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URamaSaveComponent, 2319121857);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URamaSaveComponent(Z_Construct_UClass_URamaSaveComponent, &URamaSaveComponent::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("URamaSaveComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URamaSaveComponent);
	void URamaSaveObject::StaticRegisterNativesURamaSaveObject()
	{
	}
	UClass* Z_Construct_UClass_URamaSaveObject_NoRegister()
	{
		return URamaSaveObject::StaticClass();
	}
	UClass* Z_Construct_UClass_URamaSaveObject()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = URamaSaveObject::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100081;


				static TCppClassTypeInfo<TCppClassTypeTraits<URamaSaveObject> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveObject.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveObject.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URamaSaveObject, 3802520998);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URamaSaveObject(Z_Construct_UClass_URamaSaveObject, &URamaSaveObject::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("URamaSaveObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URamaSaveObject);
class UScriptStruct* FRamaSaveEngineParams::StaticStruct()
{
	extern RAMASAVESYSTEM_API class UPackage* Z_Construct_UPackage__Script_RamaSaveSystem();
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRamaSaveEngineParams();
		extern RAMASAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FRamaSaveEngineParams_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRamaSaveEngineParams, Z_Construct_UPackage__Script_RamaSaveSystem(), TEXT("RamaSaveEngineParams"), sizeof(FRamaSaveEngineParams), Get_Z_Construct_UScriptStruct_FRamaSaveEngineParams_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRamaSaveEngineParams(FRamaSaveEngineParams::StaticStruct, TEXT("/Script/RamaSaveSystem"), TEXT("RamaSaveEngineParams"), false, nullptr, nullptr);
static struct FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRamaSaveEngineParams
{
	FScriptStruct_RamaSaveSystem_StaticRegisterNativesFRamaSaveEngineParams()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RamaSaveEngineParams")),new UScriptStruct::TCppStructOps<FRamaSaveEngineParams>);
	}
} ScriptStruct_RamaSaveSystem_StaticRegisterNativesFRamaSaveEngineParams;
	UScriptStruct* Z_Construct_UScriptStruct_FRamaSaveEngineParams()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_RamaSaveSystem();
		extern uint32 Get_Z_Construct_UScriptStruct_FRamaSaveEngineParams_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RamaSaveEngineParams"), sizeof(FRamaSaveEngineParams), Get_Z_Construct_UScriptStruct_FRamaSaveEngineParams_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSaveEngineParams"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FRamaSaveEngineParams>, EStructFlags(0x00000001));
			UProperty* NewProp_LoadOnlyStreamingLevel = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("LoadOnlyStreamingLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(LoadOnlyStreamingLevel, FRamaSaveEngineParams), 0x0010000000000000);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DontLoadPlayerPawns, FRamaSaveEngineParams, bool);
			UProperty* NewProp_DontLoadPlayerPawns = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("DontLoadPlayerPawns"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DontLoadPlayerPawns, FRamaSaveEngineParams), 0x0010000000000000, CPP_BOOL_PROPERTY_BITMASK(DontLoadPlayerPawns, FRamaSaveEngineParams), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DestroyActorsBeforeLoad, FRamaSaveEngineParams, bool);
			UProperty* NewProp_DestroyActorsBeforeLoad = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("DestroyActorsBeforeLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DestroyActorsBeforeLoad, FRamaSaveEngineParams), 0x0010000000000000, CPP_BOOL_PROPERTY_BITMASK(DestroyActorsBeforeLoad, FRamaSaveEngineParams), sizeof(bool), true);
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, FRamaSaveEngineParams), 0x0010000000000000);
			UProperty* NewProp_LoadOnlyActorsWithSaveTags = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("LoadOnlyActorsWithSaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(LoadOnlyActorsWithSaveTags, FRamaSaveEngineParams), 0x0010000000000000);
			UProperty* NewProp_LoadOnlyActorsWithSaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_LoadOnlyActorsWithSaveTags, TEXT("LoadOnlyActorsWithSaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_LoadOnlyStreamingLevel, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_DontLoadPlayerPawns, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_DestroyActorsBeforeLoad, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_FileName, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_LoadOnlyActorsWithSaveTags, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRamaSaveEngineParams_CRC() { return 1464487910U; }
	static FName NAME_ARamaSaveEngine_Async_ProgressUpdate = FName(TEXT("Async_ProgressUpdate"));
	void ARamaSaveEngine::Async_ProgressUpdate(float Progress)
	{
		RamaSaveEngine_eventAsync_ProgressUpdate_Parms Parms;
		Parms.Progress=Progress;
		ProcessEvent(FindFunctionChecked(NAME_ARamaSaveEngine_Async_ProgressUpdate),&Parms);
	}
	static FName NAME_ARamaSaveEngine_Async_SaveCancelled = FName(TEXT("Async_SaveCancelled"));
	void ARamaSaveEngine::Async_SaveCancelled(const FString& FileName)
	{
		RamaSaveEngine_eventAsync_SaveCancelled_Parms Parms;
		Parms.FileName=FileName;
		ProcessEvent(FindFunctionChecked(NAME_ARamaSaveEngine_Async_SaveCancelled),&Parms);
	}
	static FName NAME_ARamaSaveEngine_Async_SaveFinished = FName(TEXT("Async_SaveFinished"));
	void ARamaSaveEngine::Async_SaveFinished(const FString& FileName)
	{
		RamaSaveEngine_eventAsync_SaveFinished_Parms Parms;
		Parms.FileName=FileName;
		ProcessEvent(FindFunctionChecked(NAME_ARamaSaveEngine_Async_SaveFinished),&Parms);
	}
	static FName NAME_ARamaSaveEngine_Async_SaveStarted = FName(TEXT("Async_SaveStarted"));
	void ARamaSaveEngine::Async_SaveStarted(const FString& FileName)
	{
		RamaSaveEngine_eventAsync_SaveStarted_Parms Parms;
		Parms.FileName=FileName;
		ProcessEvent(FindFunctionChecked(NAME_ARamaSaveEngine_Async_SaveStarted),&Parms);
	}
	void ARamaSaveEngine::StaticRegisterNativesARamaSaveEngine()
	{
	}
	UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_ProgressUpdate()
	{
		UObject* Outer=Z_Construct_UClass_ARamaSaveEngine();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Async_ProgressUpdate"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535, sizeof(RamaSaveEngine_eventAsync_ProgressUpdate_Parms));
			UProperty* NewProp_Progress = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Progress"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Progress, RamaSaveEngine_eventAsync_ProgressUpdate_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Value proceeds from 0 to 1 during async save <3 Rama"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveCancelled()
	{
		UObject* Outer=Z_Construct_UClass_ARamaSaveEngine();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Async_SaveCancelled"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535, sizeof(RamaSaveEngine_eventAsync_SaveCancelled_Parms));
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveEngine_eventAsync_SaveCancelled_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_FileName, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveFinished()
	{
		UObject* Outer=Z_Construct_UClass_ARamaSaveEngine();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Async_SaveFinished"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535, sizeof(RamaSaveEngine_eventAsync_SaveFinished_Parms));
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveEngine_eventAsync_SaveFinished_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_FileName, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARamaSaveEngine_Async_SaveStarted()
	{
		UObject* Outer=Z_Construct_UClass_ARamaSaveEngine();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Async_SaveStarted"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x08020800, 65535, sizeof(RamaSaveEngine_eventAsync_SaveStarted_Parms));
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveEngine_eventAsync_SaveStarted_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
			MetaData->SetValue(NewProp_FileName, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARamaSaveEngine_NoRegister()
	{
		return ARamaSaveEngine::StaticClass();
	}
	UClass* Z_Construct_UClass_ARamaSaveEngine()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = ARamaSaveEngine::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20800080;

				OuterClass->LinkChild(Z_Construct_UFunction_ARamaSaveEngine_Async_ProgressUpdate());
				OuterClass->LinkChild(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveCancelled());
				OuterClass->LinkChild(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveFinished());
				OuterClass->LinkChild(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveStarted());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Load_StreamingLevels = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Load_StreamingLevels"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(Load_StreamingLevels, ARamaSaveEngine), 0x0010000000000000);
				UProperty* NewProp_Load_StreamingLevels_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Load_StreamingLevels, TEXT("Load_StreamingLevels"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_ULevelStreaming_NoRegister());
				UProperty* NewProp_LoadParams = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LoadParams"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(LoadParams, ARamaSaveEngine), 0x0010000000000000, Z_Construct_UScriptStruct_FRamaSaveEngineParams());
				UProperty* NewProp_RamaSaveComponents = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSaveComponents, ARamaSaveEngine), 0x0010008000000008);
				UProperty* NewProp_RamaSaveComponents_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSaveComponents, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000080008, Z_Construct_UClass_URamaSaveComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ARamaSaveEngine_Async_ProgressUpdate(), "Async_ProgressUpdate"); // 2559216547
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveCancelled(), "Async_SaveCancelled"); // 1358828335
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveFinished(), "Async_SaveFinished"); // 1685999831
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ARamaSaveEngine_Async_SaveStarted(), "Async_SaveStarted"); // 1828057026
				static TCppClassTypeInfo<TCppClassTypeTraits<ARamaSaveEngine> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveEngine.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
				MetaData->SetValue(OuterClass, TEXT("ObjectInitializerConstructorDeclared"), TEXT(""));
				MetaData->SetValue(NewProp_Load_StreamingLevels, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
				MetaData->SetValue(NewProp_LoadParams, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
				MetaData->SetValue(NewProp_RamaSaveComponents, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_RamaSaveComponents, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveEngine.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARamaSaveEngine, 711306767);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARamaSaveEngine(Z_Construct_UClass_ARamaSaveEngine, &ARamaSaveEngine::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("ARamaSaveEngine"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARamaSaveEngine);
	void URamaSaveLibrary::StaticRegisterNativesURamaSaveLibrary()
	{
		UClass* Class = URamaSaveLibrary::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GetAllRamaSaveActors", (Native)&URamaSaveLibrary::execGetAllRamaSaveActors },
			{ "GetAllRamaSaveActorsWithTags", (Native)&URamaSaveLibrary::execGetAllRamaSaveActorsWithTags },
			{ "GetAllRamaSaveComponents", (Native)&URamaSaveLibrary::execGetAllRamaSaveComponents },
			{ "GetAllRamaSaveComponentsWithTags", (Native)&URamaSaveLibrary::execGetAllRamaSaveComponentsWithTags },
			{ "GetDocumentsFolder", (Native)&URamaSaveLibrary::execGetDocumentsFolder },
			{ "RamaFileIO_GetFiles", (Native)&URamaSaveLibrary::execRamaFileIO_GetFiles },
			{ "RamaSave_CancelAsyncSaveProcess", (Native)&URamaSaveLibrary::execRamaSave_CancelAsyncSaveProcess },
			{ "RamaSave_ClearLevel", (Native)&URamaSaveLibrary::execRamaSave_ClearLevel },
			{ "RamaSave_CopyFile", (Native)&URamaSaveLibrary::execRamaSave_CopyFile },
			{ "RamaSave_DateTimeFromString", (Native)&URamaSaveLibrary::execRamaSave_DateTimeFromString },
			{ "RamaSave_DateTimeToString", (Native)&URamaSaveLibrary::execRamaSave_DateTimeToString },
			{ "RamaSave_DeleteFile", (Native)&URamaSaveLibrary::execRamaSave_DeleteFile },
			{ "RamaSave_FileExists", (Native)&URamaSaveLibrary::execRamaSave_FileExists },
			{ "RamaSave_FolderExists", (Native)&URamaSaveLibrary::execRamaSave_FolderExists },
			{ "RamaSave_GetFileTimeStamp", (Native)&URamaSaveLibrary::execRamaSave_GetFileTimeStamp },
			{ "RamaSave_GetFileTimeStampText", (Native)&URamaSaveLibrary::execRamaSave_GetFileTimeStampText },
			{ "RamaSave_LoadFromFile", (Native)&URamaSaveLibrary::execRamaSave_LoadFromFile },
			{ "RamaSave_LoadFromFileWithTags", (Native)&URamaSaveLibrary::execRamaSave_LoadFromFileWithTags },
			{ "RamaSave_LoadStaticDataFromFile", (Native)&URamaSaveLibrary::execRamaSave_LoadStaticDataFromFile },
			{ "RamaSave_LoadStreamingStateFromFile", (Native)&URamaSaveLibrary::execRamaSave_LoadStreamingStateFromFile },
			{ "RamaSave_SaveToFile", (Native)&URamaSaveLibrary::execRamaSave_SaveToFile },
			{ "RamaSavePaths_BinaryLocation", (Native)&URamaSaveLibrary::execRamaSavePaths_BinaryLocation },
			{ "RamaSavePaths_GameRootDirectory", (Native)&URamaSaveLibrary::execRamaSavePaths_GameRootDirectory },
			{ "RamaSavePaths_SavedDir", (Native)&URamaSaveLibrary::execRamaSavePaths_SavedDir },
			{ "RemoveLevelPIEPrefix", (Native)&URamaSaveLibrary::execRemoveLevelPIEPrefix },
			{ "RenameFile", (Native)&URamaSaveLibrary::execRenameFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 26);
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActors()
	{
		struct RamaSaveLibrary_eventGetAllRamaSaveActors_Parms
		{
			UObject* WorldContextObject;
			TArray<AActor*> RamaSaveActors;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAllRamaSaveActors"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventGetAllRamaSaveActors_Parms));
			UProperty* NewProp_RamaSaveActors = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveActors"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSaveActors, RamaSaveLibrary_eventGetAllRamaSaveActors_Parms), 0x0010000000000180);
			UProperty* NewProp_RamaSaveActors_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSaveActors, TEXT("RamaSaveActors"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AActor_NoRegister());
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventGetAllRamaSaveActors_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Get an array of all actors that have Rama Save Components! Useful for iterating over all actors that will be saved / have just been loaded."));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActorsWithTags()
	{
		struct RamaSaveLibrary_eventGetAllRamaSaveActorsWithTags_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> SaveTags;
			TArray<AActor*> RamaSaveActors;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAllRamaSaveActorsWithTags"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventGetAllRamaSaveActorsWithTags_Parms));
			UProperty* NewProp_RamaSaveActors = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveActors"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSaveActors, RamaSaveLibrary_eventGetAllRamaSaveActorsWithTags_Parms), 0x0010000000000180);
			UProperty* NewProp_RamaSaveActors_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSaveActors, TEXT("RamaSaveActors"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AActor_NoRegister());
			UProperty* NewProp_SaveTags = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(SaveTags, RamaSaveLibrary_eventGetAllRamaSaveActorsWithTags_Parms), 0x0010000008000182);
			UProperty* NewProp_SaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_SaveTags, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventGetAllRamaSaveActorsWithTags_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("AutoCreateRefTerm"), TEXT("SaveTags"));
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Get an array of all actors that have Rama Save Components! Useful for iterating over all actors that will be saved / have just been loaded.\n\n              The save tag system is all-inclusive, so if you supply multiple tags, if ANY of the tags are found in an actor's Rama Save Component, then the actor will be returned."));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
			MetaData->SetValue(NewProp_SaveTags, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponents()
	{
		struct RamaSaveLibrary_eventGetAllRamaSaveComponents_Parms
		{
			UObject* WorldContextObject;
			TArray<URamaSaveComponent*> RamaSaveComponents;
			FString GetOnlyStreamingLevelName;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAllRamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventGetAllRamaSaveComponents_Parms));
			UProperty* NewProp_GetOnlyStreamingLevelName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("GetOnlyStreamingLevelName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(GetOnlyStreamingLevelName, RamaSaveLibrary_eventGetAllRamaSaveComponents_Parms), 0x0010000000000080);
			UProperty* NewProp_RamaSaveComponents = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSaveComponents, RamaSaveLibrary_eventGetAllRamaSaveComponents_Parms), 0x0010008000000180);
			UProperty* NewProp_RamaSaveComponents_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSaveComponents, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000080000, Z_Construct_UClass_URamaSaveComponent_NoRegister());
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventGetAllRamaSaveComponents_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Get an array of all Rama Save Components!\n\nUseful for iterating over all components that will be saved / have just been loaded.\n\n@param GetOnlyStreamingLevel Optional filter to only get components for actors in a specific sublevel that is present in your levels list! Use \"PersistentLevel\" for non-streaming main level.\n\n<3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
			MetaData->SetValue(NewProp_RamaSaveComponents, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponentsWithTags()
	{
		struct RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> SaveTags;
			TArray<URamaSaveComponent*> RamaSaveComponents;
			FString GetOnlyStreamingLevelName;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetAllRamaSaveComponentsWithTags"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms));
			UProperty* NewProp_GetOnlyStreamingLevelName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("GetOnlyStreamingLevelName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(GetOnlyStreamingLevelName, RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms), 0x0010000000000080);
			UProperty* NewProp_RamaSaveComponents = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(RamaSaveComponents, RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms), 0x0010008000000180);
			UProperty* NewProp_RamaSaveComponents_Inner = new(EC_InternalUseOnlyConstructor, NewProp_RamaSaveComponents, TEXT("RamaSaveComponents"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000080000, Z_Construct_UClass_URamaSaveComponent_NoRegister());
			UProperty* NewProp_SaveTags = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(SaveTags, RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms), 0x0010000008000182);
			UProperty* NewProp_SaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_SaveTags, TEXT("SaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventGetAllRamaSaveComponentsWithTags_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("AutoCreateRefTerm"), TEXT("SaveTags"));
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Get an array of all Rama Save Components! Useful for iterating over all components that will be saved / have just been loaded.\n\n              The save tag system is all-inclusive, so if you supply multiple tags, if ANY of the tags are found in an actor's Rama Save Component, then the component will be returned.\n\n              @param GetOnlyStreamingLevel Optional filter to only get components for actors in a specific sublevel that is present in your levels list! Use \"PersistentLevel\" for non-streaming main level.\n\n              <3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
			MetaData->SetValue(NewProp_RamaSaveComponents, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_SaveTags, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_GetDocumentsFolder()
	{
		struct RamaSaveLibrary_eventGetDocumentsFolder_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetDocumentsFolder"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventGetDocumentsFolder_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventGetDocumentsFolder_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|Paths"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Platform-specific user documents folder, not specific to Windows, works on any platform that Epic supports for this functionality."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaFileIO_GetFiles()
	{
		struct RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms
		{
			FString FullPathOfBaseDir;
			TArray<FString> FilenamesOut;
			bool Recursive;
			FString FilterByExtension;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaFileIO_GetFiles"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), sizeof(bool), true);
			UProperty* NewProp_FilterByExtension = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FilterByExtension"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FilterByExtension, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(Recursive, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms, bool);
			UProperty* NewProp_Recursive = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Recursive"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Recursive, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(Recursive, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), sizeof(bool), true);
			UProperty* NewProp_FilenamesOut = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FilenamesOut"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(FilenamesOut, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), 0x0010000000000180);
			UProperty* NewProp_FilenamesOut_Inner = new(EC_InternalUseOnlyConstructor, NewProp_FilenamesOut, TEXT("FilenamesOut"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_FullPathOfBaseDir = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FullPathOfBaseDir"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FullPathOfBaseDir, RamaSaveLibrary_eventRamaFileIO_GetFiles_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_Recursive"), TEXT("false"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This is my very own Get Files in Directory algorithm!\n\nRecursive ~ If you choose recursive, all files in all subfolders of the BaseDir will be included as well!\nI also give you back absolute file paths.\n\nIf recursive is false, then you are given only the file name itself and most concatenate that with the BaseDir to obtain the absolute path to your file.\n\nFilterByExtension ~ If this is not blank, then only files with exactly matching extension (regardless of case) will be returned.\n\n\x2665 Rama"));
			MetaData->SetValue(NewProp_FilterByExtension, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_FullPathOfBaseDir, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CancelAsyncSaveProcess()
	{
		struct RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms
		{
			UObject* WorldContextObject;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_CancelAsyncSaveProcess"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms), sizeof(bool), true);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_CancelAsyncSaveProcess_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("If you are using Async Saving then you can cancel after starting (and before it was going to finish) using this node! Returns true if an async save was in progress and was cancelled, false if no save was in process."));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_ClearLevel()
	{
		struct RamaSaveLibrary_eventRamaSave_ClearLevel_Parms
		{
			UObject* WorldContextObject;
			bool DontDestroyPlayers;
			FString ClearOnlyStreamingLevel;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_ClearLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_ClearLevel_Parms));
			UProperty* NewProp_ClearOnlyStreamingLevel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ClearOnlyStreamingLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ClearOnlyStreamingLevel, RamaSaveLibrary_eventRamaSave_ClearLevel_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DontDestroyPlayers, RamaSaveLibrary_eventRamaSave_ClearLevel_Parms, bool);
			UProperty* NewProp_DontDestroyPlayers = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("DontDestroyPlayers"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DontDestroyPlayers, RamaSaveLibrary_eventRamaSave_ClearLevel_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(DontDestroyPlayers, RamaSaveLibrary_eventRamaSave_ClearLevel_Parms), sizeof(bool), true);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_ClearLevel_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_DontDestroyPlayers"), TEXT("false"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Clear all actors out of the world that have a RamaSaveComponent with DestroyBeforeLoad set to true!\n\nThis gets called by RamaSave_LoadFromFile automatically if DestroyActorsBeforeLoad is set to true.\n\n@param ClearOnlyStreamingLevel Optional Param to clear only actors in a specific streaming level! Use \"PersistentLevel\" to only clear actors in main non-streaming level.\n\nThis is done automatically if you use a streaming level with the LoadFromFile BP node, and if you also specify DestroyActorsBeforeLoad as true :)\n\n<3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CopyFile()
	{
		struct RamaSaveLibrary_eventRamaSave_CopyFile_Parms
		{
			FString Dest;
			FString Src;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_CopyFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_CopyFile_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaSave_CopyFile_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaSave_CopyFile_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaSave_CopyFile_Parms), sizeof(bool), true);
			UProperty* NewProp_Src = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Src"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Src, RamaSaveLibrary_eventRamaSave_CopyFile_Parms), 0x0010000000000080);
			UProperty* NewProp_Dest = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Dest"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Dest, RamaSaveLibrary_eventRamaSave_CopyFile_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_Src, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_Dest, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeFromString()
	{
		struct RamaSaveLibrary_eventRamaSave_DateTimeFromString_Parms
		{
			FString AsString;
			FDateTime TheDateTime;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_DateTimeFromString"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14C22401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_DateTimeFromString_Parms));
			UProperty* NewProp_TheDateTime = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TheDateTime"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(TheDateTime, RamaSaveLibrary_eventRamaSave_DateTimeFromString_Parms), 0x0010000000000180, Z_Construct_UScriptStruct_FDateTime());
			UProperty* NewProp_AsString = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("AsString"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(AsString, RamaSaveLibrary_eventRamaSave_DateTimeFromString_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_AsString, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeToString()
	{
		struct RamaSaveLibrary_eventRamaSave_DateTimeToString_Parms
		{
			FDateTime TheDateTime;
			FString AsString;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_DateTimeToString"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14C22401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_DateTimeToString_Parms));
			UProperty* NewProp_AsString = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("AsString"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(AsString, RamaSaveLibrary_eventRamaSave_DateTimeToString_Parms), 0x0010000000000180);
			UProperty* NewProp_TheDateTime = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("TheDateTime"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(TheDateTime, RamaSaveLibrary_eventRamaSave_DateTimeToString_Parms), 0x0010000008000182, Z_Construct_UScriptStruct_FDateTime());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_TheDateTime, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DeleteFile()
	{
		struct RamaSaveLibrary_eventRamaSave_DeleteFile_Parms
		{
			FString File;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_DeleteFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_DeleteFile_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaSave_DeleteFile_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaSave_DeleteFile_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaSave_DeleteFile_Parms), sizeof(bool), true);
			UProperty* NewProp_File = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("File"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(File, RamaSaveLibrary_eventRamaSave_DeleteFile_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_File, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FileExists()
	{
		struct RamaSaveLibrary_eventRamaSave_FileExists_Parms
		{
			FString File;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_FileExists"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_FileExists_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaSave_FileExists_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaSave_FileExists_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaSave_FileExists_Parms), sizeof(bool), true);
			UProperty* NewProp_File = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("File"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(File, RamaSaveLibrary_eventRamaSave_FileExists_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_File, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FolderExists()
	{
		struct RamaSaveLibrary_eventRamaSave_FolderExists_Parms
		{
			FString Dir;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_FolderExists"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_FolderExists_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRamaSave_FolderExists_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRamaSave_FolderExists_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRamaSave_FolderExists_Parms), sizeof(bool), true);
			UProperty* NewProp_Dir = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Dir"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Dir, RamaSaveLibrary_eventRamaSave_FolderExists_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_Dir, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStamp()
	{
		struct RamaSaveLibrary_eventRamaSave_GetFileTimeStamp_Parms
		{
			FString File;
			FDateTime ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_GetFileTimeStamp"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14822401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_GetFileTimeStamp_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSave_GetFileTimeStamp_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FDateTime());
			UProperty* NewProp_File = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("File"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(File, RamaSaveLibrary_eventRamaSave_GetFileTimeStamp_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_File, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStampText()
	{
		struct RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms
		{
			FString File;
			bool Verbose;
			FText ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_GetFileTimeStampText"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UTextProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms), 0x0010000000000580);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(Verbose, RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms, bool);
			UProperty* NewProp_Verbose = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Verbose"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Verbose, RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(Verbose, RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms), sizeof(bool), true);
			UProperty* NewProp_File = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("File"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(File, RamaSaveLibrary_eventRamaSave_GetFileTimeStampText_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_File, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFile()
	{
		struct RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms
		{
			UObject* WorldContextObject;
			bool FileIOSuccess;
			FString FileName;
			bool DestroyActorsBeforeLoad;
			bool DontLoadPlayerPawns;
			bool HandleStreamingLevelsLoadingAndUnloading;
			FString LoadOnlyStreamingLevel;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_LoadFromFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms));
			UProperty* NewProp_LoadOnlyStreamingLevel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("LoadOnlyStreamingLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(LoadOnlyStreamingLevel, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms, bool);
			UProperty* NewProp_HandleStreamingLevelsLoadingAndUnloading = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("HandleStreamingLevelsLoadingAndUnloading"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms, bool);
			UProperty* NewProp_DontLoadPlayerPawns = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("DontLoadPlayerPawns"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms, bool);
			UProperty* NewProp_DestroyActorsBeforeLoad = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("DestroyActorsBeforeLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), sizeof(bool), true);
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms, bool);
			UProperty* NewProp_FileIOSuccess = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileIOSuccess"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), sizeof(bool), true);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_LoadFromFile_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_DestroyActorsBeforeLoad"), TEXT("true"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_DontLoadPlayerPawns"), TEXT("false"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_HandleStreamingLevelsLoadingAndUnloading"), TEXT("true"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("DestroyActorsBeforeLoad is how you specify whether actors that are being loaded should have any prior instances destroyed before load.\n\nActors are found and destroyed based on whether they have a Rama Save Component with DestroyBeforeLoad set to true.\n\n@param LoadOnlyStreamingLevel Optional param to only load actors from a specific streaming level! Use \"PersistentLevel\" to load only non-streaming main level actors.\n\n<3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFileWithTags()
	{
		struct RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> LoadOnlyActorsWithSaveTags;
			bool FileIOSuccess;
			FString FileName;
			bool DestroyActorsBeforeLoad;
			bool DontLoadPlayerPawns;
			bool HandleStreamingLevelsLoadingAndUnloading;
			FString LoadOnlyStreamingLevel;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_LoadFromFileWithTags"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms));
			UProperty* NewProp_LoadOnlyStreamingLevel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("LoadOnlyStreamingLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(LoadOnlyStreamingLevel, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms, bool);
			UProperty* NewProp_HandleStreamingLevelsLoadingAndUnloading = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("HandleStreamingLevelsLoadingAndUnloading"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(HandleStreamingLevelsLoadingAndUnloading, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms, bool);
			UProperty* NewProp_DontLoadPlayerPawns = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("DontLoadPlayerPawns"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(DontLoadPlayerPawns, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms, bool);
			UProperty* NewProp_DestroyActorsBeforeLoad = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("DestroyActorsBeforeLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(DestroyActorsBeforeLoad, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), sizeof(bool), true);
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms, bool);
			UProperty* NewProp_FileIOSuccess = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileIOSuccess"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), sizeof(bool), true);
			UProperty* NewProp_LoadOnlyActorsWithSaveTags = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("LoadOnlyActorsWithSaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(LoadOnlyActorsWithSaveTags, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000008000182);
			UProperty* NewProp_LoadOnlyActorsWithSaveTags_Inner = new(EC_InternalUseOnlyConstructor, NewProp_LoadOnlyActorsWithSaveTags, TEXT("LoadOnlyActorsWithSaveTags"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_LoadFromFileWithTags_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("AutoCreateRefTerm"), TEXT("LoadOnlyActorsWithSaveTags"));
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_DestroyActorsBeforeLoad"), TEXT("true"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_DontLoadPlayerPawns"), TEXT("false"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_HandleStreamingLevelsLoadingAndUnloading"), TEXT("true"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("If you supply any tags via LoadOnlyActorsWithSaveTags, only those actors will be loaded, otherwise all actors will be loaded.\n\n              Please note these \"Save Tags\" are stored on the Rama Save Component and have no relationship to the actor tags stored at the actor level that come with UE4.\n\n              The save tag system is all-inclusive, so if you supply multiple tags, if ANY of the tags are found in an actor's Rama Save Component, then the actor having those tags will be loaded.\n\n              DestroyActorsBeforeLoad is how you specify whether actors that are being loaded should have any prior instances destroyed before load. Actors are found and destroyed based on whether they have a Rama Save Component with DestroyBeforeLoad set to true.\n\n              @param LoadOnlyStreamingLevel Optional param to only load actors from a specific streaming level! Use \"PersistentLevel\" to load only non-streaming main level actors.\n\n              <3 RAma"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
			MetaData->SetValue(NewProp_LoadOnlyActorsWithSaveTags, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStaticDataFromFile()
	{
		struct RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms
		{
			bool FileIOSuccess;
			FString FileName;
			URamaSaveObject* ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_LoadStaticDataFromFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms), 0x0010000000000580, Z_Construct_UClass_URamaSaveObject_NoRegister());
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms, bool);
			UProperty* NewProp_FileIOSuccess = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileIOSuccess"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStaticDataFromFile_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Use this node with the same filename as your regular save data, but this node will extract only the RamaSaveObject Static Data, if you saved any with your file.\n\nThe advantage of this node is that you can run this node before the world has been fully loaded, as this node loads only pure data!\n\n~ Tip ~\nYou can cast the output of this node to your chosen RamaSaveObject BP or C++ class to retrieve all variable members!\n\n<3 Rama"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStreamingStateFromFile()
	{
		struct RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms
		{
			UObject* WorldContextObject;
			bool FileIOSuccess;
			FString FileName;
			TArray<FString> StreamingLevelsStates;
			int32 ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_LoadStreamingStateFromFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), 0x0010000000000580);
			UProperty* NewProp_StreamingLevelsStates = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("StreamingLevelsStates"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(StreamingLevelsStates, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), 0x0010000000000180);
			UProperty* NewProp_StreamingLevelsStates_Inner = new(EC_InternalUseOnlyConstructor, NewProp_StreamingLevelsStates, TEXT("StreamingLevelsStates"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms, bool);
			UProperty* NewProp_FileIOSuccess = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileIOSuccess"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(FileIOSuccess, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), sizeof(bool), true);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_LoadStreamingStateFromFile_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("~~~ Level Streaming File Information Acquisition (non destructive, informational only) ~~~\n\nLoad just the streaming levels information from a file, without loading or unloading any levels and without loading any actors.\n\nThis is purely information acquisition so you can handle level streaming in your own very pretty way.\n\nThe format I give you is an array of\n\nLevelStreamingName=Visible\n\nso you will see\n\nYourLevel=true\nYourLevel2=false\n\nUse \"Split String\" on the resultant string with \"=\" as your text to split on and then you can test if the right result == \"true\" and use the Left result as the Streaming Level name to load or unload!\n\n@return The number of Streaming Level States :)\n\n<3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSave_SaveToFile()
	{
		struct RamaSaveLibrary_eventRamaSave_SaveToFile_Parms
		{
			UObject* WorldContextObject;
			FString FileName;
			bool FileIOSuccess;
			bool AllComponentsSaved;
			FString SaveOnlyStreamingLevel;
			URamaSaveObject* StaticSaveData;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSave_SaveToFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04422401, 65535, sizeof(RamaSaveLibrary_eventRamaSave_SaveToFile_Parms));
			UProperty* NewProp_StaticSaveData = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("StaticSaveData"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(StaticSaveData, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000080, Z_Construct_UClass_URamaSaveObject_NoRegister());
			UProperty* NewProp_SaveOnlyStreamingLevel = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("SaveOnlyStreamingLevel"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(SaveOnlyStreamingLevel, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000080);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(AllComponentsSaved, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms, bool);
			UProperty* NewProp_AllComponentsSaved = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("AllComponentsSaved"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(AllComponentsSaved, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(AllComponentsSaved, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(FileIOSuccess, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms, bool);
			UProperty* NewProp_FileIOSuccess = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileIOSuccess"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FileIOSuccess, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000180, CPP_BOOL_PROPERTY_BITMASK(FileIOSuccess, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), sizeof(bool), true);
			UProperty* NewProp_FileName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("FileName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(FileName, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000080);
			UProperty* NewProp_WorldContextObject = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("WorldContextObject"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(WorldContextObject, RamaSaveLibrary_eventRamaSave_SaveToFile_Parms), 0x0010000000000080, Z_Construct_UClass_UObject_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("All Rama Save Components are found and their owning actors and all variables that you specify via the string array RamaSave_VarsToSave are saved into a single file!\n\n@param SaveOnlyStreamingLevel Optional param to save only actors in a particular streaming level! Use \"PersistentLevel\" to save only non-streaming main level actors.\n\n@param StaticSaveData For any simple data that is not associated with an actor that you want to be able to load even before the world has finished being created,  make a BP of my RamaSaveObject class and put all your data there! You can use Construct Object to create an instance of the RamaSaveObject and use it any where you like, then pass that instance to this save function at the time of saving.\n\n<3 Rama"));
			MetaData->SetValue(ReturnFunction, TEXT("WorldContext"), TEXT("WorldContextObject"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_BinaryLocation()
	{
		struct RamaSaveLibrary_eventRamaSavePaths_BinaryLocation_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSavePaths_BinaryLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSavePaths_BinaryLocation_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSavePaths_BinaryLocation_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|Paths"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("The location of your game's .exe even if the user moves your entire game file structure at any time! InstallDir/GameName/Binaries/OS such as Win64 or Win32, different on Linux/Mac/Mobile"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_GameRootDirectory()
	{
		struct RamaSaveLibrary_eventRamaSavePaths_GameRootDirectory_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSavePaths_GameRootDirectory"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSavePaths_GameRootDirectory_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSavePaths_GameRootDirectory_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|Paths"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Use these nodes to always save files relative to the actual location of your game's .exe! InstallDir/GameName"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_SavedDir()
	{
		struct RamaSaveLibrary_eventRamaSavePaths_SavedDir_Parms
		{
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RamaSavePaths_SavedDir"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRamaSavePaths_SavedDir_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRamaSavePaths_SavedDir_Parms), 0x0010000000000580);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|Paths"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Use these nodes to always save files relative to the actual location of your game's .exe! InstallDir/GameName/Saved"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RemoveLevelPIEPrefix()
	{
		struct RamaSaveLibrary_eventRemoveLevelPIEPrefix_Parms
		{
			FString LevelName;
			FString ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RemoveLevelPIEPrefix"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14022401, 65535, sizeof(RamaSaveLibrary_eventRemoveLevelPIEPrefix_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(ReturnValue, RamaSaveLibrary_eventRemoveLevelPIEPrefix_Parms), 0x0010000000000580);
			UProperty* NewProp_LevelName = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("LevelName"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(LevelName, RamaSaveLibrary_eventRemoveLevelPIEPrefix_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This returns actual level name after removing any path and any renaming that occurred for PIE (play in editor).\n\nThis is the name you can use with GetStreamingLevel for any level that is in your levels list!\n\nThis returns the same exact name whether you get the level name in PIE or in standalone or packaged game.\n\n<3 Rama"));
			MetaData->SetValue(NewProp_LevelName, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URamaSaveLibrary_RenameFile()
	{
		struct RamaSaveLibrary_eventRenameFile_Parms
		{
			FString Dest;
			FString Source;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_URamaSaveLibrary();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RenameFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(RamaSaveLibrary_eventRenameFile_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, RamaSaveLibrary_eventRenameFile_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, RamaSaveLibrary_eventRenameFile_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, RamaSaveLibrary_eventRenameFile_Parms), sizeof(bool), true);
			UProperty* NewProp_Source = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Source"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Source, RamaSaveLibrary_eventRenameFile_Parms), 0x0010000000000080);
			UProperty* NewProp_Dest = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Dest"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Dest, RamaSaveLibrary_eventRenameFile_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Rama Save System|File IO"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
			MetaData->SetValue(NewProp_Source, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_Dest, TEXT("NativeConst"), TEXT(""));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URamaSaveLibrary_NoRegister()
	{
		return URamaSaveLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_URamaSaveLibrary()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = URamaSaveLibrary::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20100080;

				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActors());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActorsWithTags());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponents());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponentsWithTags());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_GetDocumentsFolder());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaFileIO_GetFiles());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CancelAsyncSaveProcess());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_ClearLevel());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CopyFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeFromString());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeToString());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DeleteFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FileExists());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FolderExists());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStamp());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStampText());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFileWithTags());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStaticDataFromFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStreamingStateFromFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_SaveToFile());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_BinaryLocation());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_GameRootDirectory());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_SavedDir());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RemoveLevelPIEPrefix());
				OuterClass->LinkChild(Z_Construct_UFunction_URamaSaveLibrary_RenameFile());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActors(), "GetAllRamaSaveActors"); // 1170984108
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveActorsWithTags(), "GetAllRamaSaveActorsWithTags"); // 1478064328
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponents(), "GetAllRamaSaveComponents"); // 3093438668
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_GetAllRamaSaveComponentsWithTags(), "GetAllRamaSaveComponentsWithTags"); // 3973972692
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_GetDocumentsFolder(), "GetDocumentsFolder"); // 2708056798
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaFileIO_GetFiles(), "RamaFileIO_GetFiles"); // 1488818594
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CancelAsyncSaveProcess(), "RamaSave_CancelAsyncSaveProcess"); // 1393912150
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_ClearLevel(), "RamaSave_ClearLevel"); // 2550493267
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_CopyFile(), "RamaSave_CopyFile"); // 3764727551
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeFromString(), "RamaSave_DateTimeFromString"); // 940618437
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DateTimeToString(), "RamaSave_DateTimeToString"); // 1295809913
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_DeleteFile(), "RamaSave_DeleteFile"); // 3820447068
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FileExists(), "RamaSave_FileExists"); // 2320708621
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_FolderExists(), "RamaSave_FolderExists"); // 2523523718
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStamp(), "RamaSave_GetFileTimeStamp"); // 3544344157
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_GetFileTimeStampText(), "RamaSave_GetFileTimeStampText"); // 1039072797
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFile(), "RamaSave_LoadFromFile"); // 3710746080
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadFromFileWithTags(), "RamaSave_LoadFromFileWithTags"); // 4055419897
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStaticDataFromFile(), "RamaSave_LoadStaticDataFromFile"); // 313648742
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_LoadStreamingStateFromFile(), "RamaSave_LoadStreamingStateFromFile"); // 3884901072
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSave_SaveToFile(), "RamaSave_SaveToFile"); // 3314662736
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_BinaryLocation(), "RamaSavePaths_BinaryLocation"); // 2549217528
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_GameRootDirectory(), "RamaSavePaths_GameRootDirectory"); // 1282943832
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RamaSavePaths_SavedDir(), "RamaSavePaths_SavedDir"); // 2280049541
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RemoveLevelPIEPrefix(), "RemoveLevelPIEPrefix"); // 1138336874
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_URamaSaveLibrary_RenameFile(), "RenameFile"); // 85967771
				static TCppClassTypeInfo<TCppClassTypeTraits<URamaSaveLibrary> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveLibrary.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveLibrary.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URamaSaveLibrary, 2626140919);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URamaSaveLibrary(Z_Construct_UClass_URamaSaveLibrary, &URamaSaveLibrary::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("URamaSaveLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URamaSaveLibrary);
	void URamaSaveSystemSettings::StaticRegisterNativesURamaSaveSystemSettings()
	{
	}
	UClass* Z_Construct_UClass_URamaSaveSystemSettings_NoRegister()
	{
		return URamaSaveSystemSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_URamaSaveSystemSettings()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UDeveloperSettings();
			Z_Construct_UPackage__Script_RamaSaveSystem();
			OuterClass = URamaSaveSystemSettings::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000086;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(LogSavingAndLoadingOfEachStaticDataProperty, URamaSaveSystemSettings, bool);
				UProperty* NewProp_LogSavingAndLoadingOfEachStaticDataProperty = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LogSavingAndLoadingOfEachStaticDataProperty"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(LogSavingAndLoadingOfEachStaticDataProperty, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(LogSavingAndLoadingOfEachStaticDataProperty, URamaSaveSystemSettings), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Loading_GlobalDisablePhysicsLoad, URamaSaveSystemSettings, bool);
				UProperty* NewProp_Loading_GlobalDisablePhysicsLoad = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Loading_GlobalDisablePhysicsLoad"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Loading_GlobalDisablePhysicsLoad, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(Loading_GlobalDisablePhysicsLoad, URamaSaveSystemSettings), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Loading_GlobalVerboseLogging, URamaSaveSystemSettings, bool);
				UProperty* NewProp_Loading_GlobalVerboseLogging = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Loading_GlobalVerboseLogging"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Loading_GlobalVerboseLogging, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(Loading_GlobalVerboseLogging, URamaSaveSystemSettings), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Saving_PerformObjectValidityChecks, URamaSaveSystemSettings, bool);
				UProperty* NewProp_Saving_PerformObjectValidityChecks = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Saving_PerformObjectValidityChecks"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Saving_PerformObjectValidityChecks, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(Saving_PerformObjectValidityChecks, URamaSaveSystemSettings), sizeof(bool), true);
				UProperty* NewProp_AsyncSaveActorChunkSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AsyncSaveActorChunkSize"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(AsyncSaveActorChunkSize, URamaSaveSystemSettings), 0x0010000000004005);
				UProperty* NewProp_AsyncSaveTickInterval = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AsyncSaveTickInterval"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(AsyncSaveTickInterval, URamaSaveSystemSettings), 0x0010000000004005);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(AsyncSave, URamaSaveSystemSettings, bool);
				UProperty* NewProp_AsyncSave = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("AsyncSave"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(AsyncSave, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(AsyncSave, URamaSaveSystemSettings), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(SaveAllPropertiesMarkedAsSaveGame, URamaSaveSystemSettings, bool);
				UProperty* NewProp_SaveAllPropertiesMarkedAsSaveGame = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("SaveAllPropertiesMarkedAsSaveGame"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(SaveAllPropertiesMarkedAsSaveGame, URamaSaveSystemSettings), 0x0010000000004005, CPP_BOOL_PROPERTY_BITMASK(SaveAllPropertiesMarkedAsSaveGame, URamaSaveSystemSettings), sizeof(bool), true);
				UProperty* NewProp_RamaSaveEngineBP = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("RamaSaveEngineBP"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(RamaSaveEngineBP, URamaSaveSystemSettings), 0x0014000000004005, Z_Construct_UClass_ARamaSaveEngine_NoRegister(), UClass::StaticClass());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<URamaSaveSystemSettings> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("RamaSaveSystemSettings.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("<3 Rama"));
				MetaData->SetValue(NewProp_LogSavingAndLoadingOfEachStaticDataProperty, TEXT("Category"), TEXT("Debug"));
				MetaData->SetValue(NewProp_LogSavingAndLoadingOfEachStaticDataProperty, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_LogSavingAndLoadingOfEachStaticDataProperty, TEXT("ToolTip"), TEXT("If this is true and you save a RamaSaveObject as StaticData along with your save file, then each property being saved/loaded will print to log!"));
				MetaData->SetValue(NewProp_Loading_GlobalDisablePhysicsLoad, TEXT("Category"), TEXT("Debug"));
				MetaData->SetValue(NewProp_Loading_GlobalDisablePhysicsLoad, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_Loading_GlobalDisablePhysicsLoad, TEXT("ToolTip"), TEXT("If this is true, all loading of physics data from file will be disabled, primarly for debug purposes so you don't have to turn physics serialization off in each individual actor blueprint while testing"));
				MetaData->SetValue(NewProp_Loading_GlobalVerboseLogging, TEXT("Category"), TEXT("Debug"));
				MetaData->SetValue(NewProp_Loading_GlobalVerboseLogging, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_Loading_GlobalVerboseLogging, TEXT("ToolTip"), TEXT("If you need extensive debug information printed to UE4 Log during the loading process of a file, use this! If this is true, log info will be printed regardless of per-Rama-Save-Component log verbosity settings. <3 Rama"));
				MetaData->SetValue(NewProp_Saving_PerformObjectValidityChecks, TEXT("Category"), TEXT("Performance"));
				MetaData->SetValue(NewProp_Saving_PerformObjectValidityChecks, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_Saving_PerformObjectValidityChecks, TEXT("ToolTip"), TEXT("Unchecking this can increase the speed of saving in cases where you have actors with tons of variables that you've added yourself.\n\nIt is important if you are new to my save system to leave this checked until you understand the type of objects that can and can't be saved.\n\nAny asset object like a material asset reference or mesh asset ref can be saved.\n\nBut any objects created during runtime cannot be saved in their entirety, such as a material instance dynamic.\n\nTo save/load something like a runtime mesh or material instance dynamic, save the basic parameters in a global save actor and then during load, reconstruct the dynamically created object from the simple data values."));
				MetaData->SetValue(NewProp_AsyncSaveActorChunkSize, TEXT("Category"), TEXT("Async Save"));
				MetaData->SetValue(NewProp_AsyncSaveActorChunkSize, TEXT("editcondition"), TEXT("AsyncSave"));
				MetaData->SetValue(NewProp_AsyncSaveActorChunkSize, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_AsyncSaveActorChunkSize, TEXT("ToolTip"), TEXT("How many actors should be processed per tick?"));
				MetaData->SetValue(NewProp_AsyncSaveTickInterval, TEXT("Category"), TEXT("Async Save"));
				MetaData->SetValue(NewProp_AsyncSaveTickInterval, TEXT("editcondition"), TEXT("AsyncSave"));
				MetaData->SetValue(NewProp_AsyncSaveTickInterval, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_AsyncSaveTickInterval, TEXT("ToolTip"), TEXT("You can customize the interval of time between processing of chunks <3 Rama"));
				MetaData->SetValue(NewProp_AsyncSave, TEXT("Category"), TEXT("Async Save"));
				MetaData->SetValue(NewProp_AsyncSave, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_AsyncSave, TEXT("ToolTip"), TEXT("If false, entire saving of world is done in one loop and may cause a hitch for large worlds"));
				MetaData->SetValue(NewProp_SaveAllPropertiesMarkedAsSaveGame, TEXT("Category"), TEXT("Core"));
				MetaData->SetValue(NewProp_SaveAllPropertiesMarkedAsSaveGame, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
				MetaData->SetValue(NewProp_SaveAllPropertiesMarkedAsSaveGame, TEXT("ToolTip"), TEXT("+ Adds Support For UE4 \"SaveGame\" Property\n\n+ Adds Support For Actor Subcomponents With Same Property Name\n\n~~~ Important Note ~~~\nSave files that have this value true/false are incompatible, so only set this to true if you don't need to be able to load old save files / have your users load old save file data.\n\nSetting this value to true adds the new features listed above!\n\n~~~ Overview ~~~\nIn my original implementation any properties of the owning Actor or other components HAD to be put in a string variable list.\n\nNow with the new setup you have the option to simply mark any properties you want to save with UE4's SaveGame meta data in C++ or the property tag in Blueprints.\n\nIf your project was using both my save system and UE4's save system, you will probably want to revert to the old behavior by setting this to false.\n\n~~~ Saving Several Subcomponents of Actor that share a property with the same Name ~~~\n\nIf you have several subcomponents of an actor that had the same exact property name like \"Location\" or \"Health\", you can now save these same-name vars per-component with this new setup!\n\n~~~ How to Use ~~~\nYou can easily save subcomponent properties of an actor where several components have a property with the same name by setting the SaveGame flag on the relevant properties, or by adding Pre-existing properties to the RamaSave_ComponentVarsToSave list :)\n\n<3 Rama"));
				MetaData->SetValue(NewProp_RamaSaveEngineBP, TEXT("Category"), TEXT("Core"));
				MetaData->SetValue(NewProp_RamaSaveEngineBP, TEXT("ModuleRelativePath"), TEXT("Public/RamaSaveSystemSettings.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(URamaSaveSystemSettings, 4127301206);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URamaSaveSystemSettings(Z_Construct_UClass_URamaSaveSystemSettings, &URamaSaveSystemSettings::StaticClass, TEXT("/Script/RamaSaveSystem"), TEXT("URamaSaveSystemSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URamaSaveSystemSettings);
	UPackage* Z_Construct_UPackage__Script_RamaSaveSystem()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/RamaSaveSystem")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x7AAA4421;
			Guid.B = 0xFCA9D1B6;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

			Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSaveFullyLoadedSignature__DelegateSignature();
			Z_Construct_UDelegateFunction_RamaSaveSystem_RamaSavePreSaveSignature__DelegateSignature();
			Z_Construct_UDelegateFunction_RamaSaveSystem_RamaPlayerLoadedSignature__DelegateSignature();
		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
