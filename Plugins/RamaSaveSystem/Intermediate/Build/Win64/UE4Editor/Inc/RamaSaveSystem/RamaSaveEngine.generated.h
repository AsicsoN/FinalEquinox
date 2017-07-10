// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RAMASAVESYSTEM_RamaSaveEngine_generated_h
#error "RamaSaveEngine.generated.h already included, missing '#pragma once' in RamaSaveEngine.h"
#endif
#define RAMASAVESYSTEM_RamaSaveEngine_generated_h

#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_20_GENERATED_BODY \
	friend RAMASAVESYSTEM_API class UScriptStruct* Z_Construct_UScriptStruct_FRamaSaveEngineParams(); \
	RAMASAVESYSTEM_API static class UScriptStruct* StaticStruct();


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_RPC_WRAPPERS
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_RPC_WRAPPERS_NO_PURE_DECLS
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_EVENT_PARMS \
	struct RamaSaveEngine_eventAsync_ProgressUpdate_Parms \
	{ \
		float Progress; \
	}; \
	struct RamaSaveEngine_eventAsync_SaveCancelled_Parms \
	{ \
		FString FileName; \
	}; \
	struct RamaSaveEngine_eventAsync_SaveFinished_Parms \
	{ \
		FString FileName; \
	}; \
	struct RamaSaveEngine_eventAsync_SaveStarted_Parms \
	{ \
		FString FileName; \
	};


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_CALLBACK_WRAPPERS
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARamaSaveEngine(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_ARamaSaveEngine(); \
public: \
	DECLARE_CLASS(ARamaSaveEngine, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(ARamaSaveEngine) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_INCLASS \
private: \
	static void StaticRegisterNativesARamaSaveEngine(); \
	friend RAMASAVESYSTEM_API class UClass* Z_Construct_UClass_ARamaSaveEngine(); \
public: \
	DECLARE_CLASS(ARamaSaveEngine, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RamaSaveSystem"), NO_API) \
	DECLARE_SERIALIZER(ARamaSaveEngine) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARamaSaveEngine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARamaSaveEngine) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARamaSaveEngine); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARamaSaveEngine); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARamaSaveEngine(ARamaSaveEngine&&); \
	NO_API ARamaSaveEngine(const ARamaSaveEngine&); \
public:


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARamaSaveEngine(ARamaSaveEngine&&); \
	NO_API ARamaSaveEngine(const ARamaSaveEngine&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARamaSaveEngine); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARamaSaveEngine); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARamaSaveEngine)


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_PRIVATE_PROPERTY_OFFSET
#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_39_PROLOG \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_EVENT_PARMS


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_PRIVATE_PROPERTY_OFFSET \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_RPC_WRAPPERS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_CALLBACK_WRAPPERS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_INCLASS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_PRIVATE_PROPERTY_OFFSET \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_CALLBACK_WRAPPERS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_INCLASS_NO_PURE_DECLS \
	battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID battleship_Plugins_RamaSaveSystem_Source_RamaSaveSystem_Public_RamaSaveEngine_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
