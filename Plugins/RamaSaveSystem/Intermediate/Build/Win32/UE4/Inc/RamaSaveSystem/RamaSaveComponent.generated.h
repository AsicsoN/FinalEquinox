// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class APawn;
class URamaSaveComponent;
class UScriptStruct;
#ifdef RAMASAVESYSTEM_RamaSaveComponent_generated_h
#error "RamaSaveComponent.generated.h already included, missing '#pragma once' in RamaSaveComponent.h"
#endif
#define RAMASAVESYSTEM_RamaSaveComponent_generated_h

#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_81_GENERATED_BODY \
	friend RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBLoad(); \
	RAMASAVESYSTEM_API static class UScriptStruct* StaticStruct();


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_16_GENERATED_BODY \
	friend RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRBSave(); \
	RAMASAVESYSTEM_API static class UScriptStruct* StaticStruct();


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_10_DELEGATE \
struct _Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms \
{ \
	APlayerController* PC; \
	APawn* Pawn; \
	int32 PlayerIndex; \
}; \
static inline void FRamaPlayerLoadedSignature_DelegateWrapper(const FMulticastScriptDelegate& RamaPlayerLoadedSignature, APlayerController* PC, APawn* Pawn, int32 PlayerIndex) \
{ \
	_Script_RamaSaveSystem_eventRamaPlayerLoadedSignature_Parms Parms; \
	Parms.PC=PC; \
	Parms.Pawn=Pawn; \
	Parms.PlayerIndex=PlayerIndex; \
	RamaPlayerLoadedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_9_DELEGATE \
struct _Script_RamaSaveSystem_eventRamaSavePreSaveSignature_Parms \
{ \
	URamaSaveComponent* RamaSaveComponent; \
}; \
static inline void FRamaSavePreSaveSignature_DelegateWrapper(const FMulticastScriptDelegate& RamaSavePreSaveSignature, URamaSaveComponent* RamaSaveComponent) \
{ \
	_Script_RamaSaveSystem_eventRamaSavePreSaveSignature_Parms Parms; \
	Parms.RamaSaveComponent=RamaSaveComponent; \
	RamaSavePreSaveSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_8_DELEGATE \
struct _Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms \
{ \
	URamaSaveComponent* RamaSaveComponent; \
	FString LevelPackageName; \
}; \
static inline void FRamaSaveFullyLoadedSignature_DelegateWrapper(const FMulticastScriptDelegate& RamaSaveFullyLoadedSignature, URamaSaveComponent* RamaSaveComponent, const FString& LevelPackageName) \
{ \
	_Script_RamaSaveSystem_eventRamaSaveFullyLoadedSignature_Parms Parms; \
	Parms.RamaSaveComponent=RamaSaveComponent; \
	Parms.LevelPackageName=LevelPackageName; \
	RamaSaveFullyLoadedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRamaSave_HasAnyOfSaveTags) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RamaSave_HasAnyOfSaveTags(Z_Param_Out_SaveTags); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorIsInPersistentLevel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetActorIsInPersistentLevel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorStreamingLevelPackageName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=this->GetActorStreamingLevelPackageName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_HasSaveTag) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SaveTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RamaSave_HasSaveTag(Z_Param_SaveTag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTest) \
	{ \
		P_GET_OBJECT(UScriptStruct,Z_Param_Struct); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveComponent::Test(Z_Param_Struct,Z_Param_Out_ByteData); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRamaSave_HasAnyOfSaveTags) \
	{ \
		P_GET_TARRAY_REF(FString,Z_Param_Out_SaveTags); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RamaSave_HasAnyOfSaveTags(Z_Param_Out_SaveTags); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorIsInPersistentLevel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetActorIsInPersistentLevel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorStreamingLevelPackageName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=this->GetActorStreamingLevelPackageName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRamaSave_HasSaveTag) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_SaveTag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RamaSave_HasSaveTag(Z_Param_SaveTag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTest) \
	{ \
		P_GET_OBJECT(UScriptStruct,Z_Param_Struct); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_ByteData); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		URamaSaveComponent::Test(Z_Param_Struct,Z_Param_Out_ByteData); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_EVENT_PARMS
#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_CALLBACK_WRAPPERS
#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURamaSaveComponent(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveComponent(); \
public: \
	DECLARE_CLASS(URamaSaveComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(URamaSaveComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_INCLASS \
private: \
	static void StaticRegisterNativesURamaSaveComponent(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_URamaSaveComponent(); \
public: \
	DECLARE_CLASS(URamaSaveComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(URamaSaveComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URamaSaveComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URamaSaveComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URamaSaveComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URamaSaveComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URamaSaveComponent(URamaSaveComponent&&); \
	NO_API URamaSaveComponent(const URamaSaveComponent&); \
public:


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URamaSaveComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URamaSaveComponent(URamaSaveComponent&&); \
	NO_API URamaSaveComponent(const URamaSaveComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URamaSaveComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URamaSaveComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URamaSaveComponent)


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_115_PROLOG \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_EVENT_PARMS


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_RPC_WRAPPERS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_CALLBACK_WRAPPERS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_INCLASS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_CALLBACK_WRAPPERS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h_118_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
