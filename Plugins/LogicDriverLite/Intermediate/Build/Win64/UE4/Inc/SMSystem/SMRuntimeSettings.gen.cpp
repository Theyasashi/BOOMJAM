// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/SMRuntimeSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMRuntimeSettings() {}
// Cross Module References
	SMSYSTEM_API UClass* Z_Construct_UClass_USMRuntimeSettings_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMRuntimeSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
// End Cross Module References
	void USMRuntimeSettings::StaticRegisterNativesUSMRuntimeSettings()
	{
	}
	UClass* Z_Construct_UClass_USMRuntimeSettings_NoRegister()
	{
		return USMRuntimeSettings::StaticClass();
	}
	struct Z_Construct_UClass_USMRuntimeSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPreloadDefaultNodes_MetaData[];
#endif
		static void NewProp_bPreloadDefaultNodes_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPreloadDefaultNodes;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMRuntimeSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMRuntimeSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Logic Driver settings for runtime.\n */" },
		{ "IncludePath", "SMRuntimeSettings.h" },
		{ "ModuleRelativePath", "Public/SMRuntimeSettings.h" },
		{ "ToolTip", "Logic Driver settings for runtime." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes_MetaData[] = {
		{ "Category", "Performance" },
		{ "Comment", "/**\n\x09 * Optimize when default node instances are loaded. They are often not needed\n\x09 * unless programatically accessing the node. Leaving off can help memory usage\n\x09 * and initialization times.\n\x09 * \n\x09 * True - Loads all default node instances when initializing a state machine.\n\x09 * False - Only load default node instances on demand.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMRuntimeSettings.h" },
		{ "ToolTip", "Optimize when default node instances are loaded. They are often not needed\nunless programatically accessing the node. Leaving off can help memory usage\nand initialization times.\n\nTrue - Loads all default node instances when initializing a state machine.\nFalse - Only load default node instances on demand." },
	};
#endif
	void Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes_SetBit(void* Obj)
	{
		((USMRuntimeSettings*)Obj)->bPreloadDefaultNodes = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes = { "bPreloadDefaultNodes", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMRuntimeSettings), &Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMRuntimeSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMRuntimeSettings_Statics::NewProp_bPreloadDefaultNodes,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMRuntimeSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMRuntimeSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMRuntimeSettings_Statics::ClassParams = {
		&USMRuntimeSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMRuntimeSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMRuntimeSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_USMRuntimeSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMRuntimeSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMRuntimeSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMRuntimeSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMRuntimeSettings, 2953250576);
	template<> SMSYSTEM_API UClass* StaticClass<USMRuntimeSettings>()
	{
		return USMRuntimeSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMRuntimeSettings(Z_Construct_UClass_USMRuntimeSettings, &USMRuntimeSettings::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMRuntimeSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMRuntimeSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
