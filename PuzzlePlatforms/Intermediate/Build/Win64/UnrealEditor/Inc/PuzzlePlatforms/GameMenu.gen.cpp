// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PuzzlePlatforms/MenuSystems/GameMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameMenu() {}
// Cross Module References
	PUZZLEPLATFORMS_API UClass* Z_Construct_UClass_UGameMenu_NoRegister();
	PUZZLEPLATFORMS_API UClass* Z_Construct_UClass_UGameMenu();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_PuzzlePlatforms();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UGameMenu::execCancelPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CancelPressed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameMenu::execJoinToMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinToMenu();
		P_NATIVE_END;
	}
	void UGameMenu::StaticRegisterNativesUGameMenu()
	{
		UClass* Class = UGameMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CancelPressed", &UGameMenu::execCancelPressed },
			{ "JoinToMenu", &UGameMenu::execJoinToMenu },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameMenu_CancelPressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMenu_CancelPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MenuSystems/GameMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMenu_CancelPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMenu, nullptr, "CancelPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameMenu_CancelPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMenu_CancelPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameMenu_CancelPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMenu_CancelPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MenuSystems/GameMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameMenu, nullptr, "JoinToMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameMenu_JoinToMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameMenu_JoinToMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameMenu);
	UClass* Z_Construct_UClass_UGameMenu_NoRegister()
	{
		return UGameMenu::StaticClass();
	}
	struct Z_Construct_UClass_UGameMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InGameCancel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGameCancel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InGameMenu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InGameMenu;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_PuzzlePlatforms,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameMenu_CancelPressed, "CancelPressed" }, // 2224101878
		{ &Z_Construct_UFunction_UGameMenu_JoinToMenu, "JoinToMenu" }, // 790136290
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameMenu_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MenuSystems/GameMenu.h" },
		{ "ModuleRelativePath", "MenuSystems/GameMenu.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameCancel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MenuSystems/GameMenu.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameCancel = { "InGameCancel", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameMenu, InGameCancel), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameCancel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameCancel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameMenu_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MenuSystems/GameMenu.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameMenu = { "InGameMenu", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameMenu, InGameMenu), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameMenu_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameCancel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameMenu_Statics::NewProp_InGameMenu,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameMenu>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameMenu_Statics::ClassParams = {
		&UGameMenu::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameMenu_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenu_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameMenu_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameMenu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameMenu()
	{
		if (!Z_Registration_Info_UClass_UGameMenu.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameMenu.OuterSingleton, Z_Construct_UClass_UGameMenu_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameMenu.OuterSingleton;
	}
	template<> PUZZLEPLATFORMS_API UClass* StaticClass<UGameMenu>()
	{
		return UGameMenu::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameMenu);
	struct Z_CompiledInDeferFile_FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameMenu, UGameMenu::StaticClass, TEXT("UGameMenu"), &Z_Registration_Info_UClass_UGameMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameMenu), 1714377456U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_1249572462(TEXT("/Script/PuzzlePlatforms"),
		Z_CompiledInDeferFile_FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PuzzlePlatforms_Source_PuzzlePlatforms_MenuSystems_GameMenu_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
