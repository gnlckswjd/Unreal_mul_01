// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PUZZLEPLATFORMS_GameMenu_generated_h
#error "GameMenu.generated.h already included, missing '#pragma once' in GameMenu.h"
#endif
#define PUZZLEPLATFORMS_GameMenu_generated_h

#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_SPARSE_DATA
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCancelPressed); \
	DECLARE_FUNCTION(execJoinToMenu);


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCancelPressed); \
	DECLARE_FUNCTION(execJoinToMenu);


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameMenu(); \
	friend struct Z_Construct_UClass_UGameMenu_Statics; \
public: \
	DECLARE_CLASS(UGameMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PuzzlePlatforms"), NO_API) \
	DECLARE_SERIALIZER(UGameMenu)


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUGameMenu(); \
	friend struct Z_Construct_UClass_UGameMenu_Statics; \
public: \
	DECLARE_CLASS(UGameMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PuzzlePlatforms"), NO_API) \
	DECLARE_SERIALIZER(UGameMenu)


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameMenu) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameMenu); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameMenu(UGameMenu&&); \
	NO_API UGameMenu(const UGameMenu&); \
public:


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameMenu(UGameMenu&&); \
	NO_API UGameMenu(const UGameMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameMenu); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameMenu)


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_15_PROLOG
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_SPARSE_DATA \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_RPC_WRAPPERS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_INCLASS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_SPARSE_DATA \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_INCLASS_NO_PURE_DECLS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PUZZLEPLATFORMS_API UClass* StaticClass<class UGameMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
