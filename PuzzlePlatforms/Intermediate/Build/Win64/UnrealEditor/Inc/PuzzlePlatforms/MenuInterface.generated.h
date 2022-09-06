// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PUZZLEPLATFORMS_MenuInterface_generated_h
#error "MenuInterface.generated.h already included, missing '#pragma once' in MenuInterface.h"
#endif
#define PUZZLEPLATFORMS_MenuInterface_generated_h

#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_SPARSE_DATA
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_RPC_WRAPPERS
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PUZZLEPLATFORMS_API UMenuInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMenuInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PUZZLEPLATFORMS_API, UMenuInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMenuInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	PUZZLEPLATFORMS_API UMenuInterface(UMenuInterface&&); \
	PUZZLEPLATFORMS_API UMenuInterface(const UMenuInterface&); \
public:


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PUZZLEPLATFORMS_API UMenuInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	PUZZLEPLATFORMS_API UMenuInterface(UMenuInterface&&); \
	PUZZLEPLATFORMS_API UMenuInterface(const UMenuInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PUZZLEPLATFORMS_API, UMenuInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMenuInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMenuInterface)


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUMenuInterface(); \
	friend struct Z_Construct_UClass_UMenuInterface_Statics; \
public: \
	DECLARE_CLASS(UMenuInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/PuzzlePlatforms"), PUZZLEPLATFORMS_API) \
	DECLARE_SERIALIZER(UMenuInterface)


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IMenuInterface() {} \
public: \
	typedef UMenuInterface UClassType; \
	typedef IMenuInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~IMenuInterface() {} \
public: \
	typedef UMenuInterface UClassType; \
	typedef IMenuInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_11_PROLOG
#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_SPARSE_DATA \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_RPC_WRAPPERS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_SPARSE_DATA \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PUZZLEPLATFORMS_API UClass* StaticClass<class UMenuInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_MenuInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
