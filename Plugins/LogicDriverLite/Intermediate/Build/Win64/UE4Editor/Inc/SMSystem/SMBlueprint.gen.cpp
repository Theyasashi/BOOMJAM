// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Blueprints/SMBlueprint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMBlueprint() {}
// Cross Module References
	SMSYSTEM_API UClass* Z_Construct_UClass_USMBlueprint_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMBlueprint();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprint();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeBlueprint_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeBlueprint();
// End Cross Module References
	void USMBlueprint::StaticRegisterNativesUSMBlueprint()
	{
	}
	UClass* Z_Construct_UClass_USMBlueprint_NoRegister()
	{
		return USMBlueprint::StaticClass();
	}
	struct Z_Construct_UClass_USMBlueprint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetVersion_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AssetVersion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMBlueprint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprint,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMBlueprint_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * State Machine Blueprints allow you to assemble a finite state machine which is capable of running normal Blueprint logic.\n * Any UObject instance may be passed as a context for the state machine.\n */" },
		{ "DisplayName", "State Machine Blueprint" },
		{ "IncludePath", "Blueprints/SMBlueprint.h" },
		{ "ModuleRelativePath", "Public/Blueprints/SMBlueprint.h" },
		{ "ToolTip", "State Machine Blueprints allow you to assemble a finite state machine which is capable of running normal Blueprint logic.\nAny UObject instance may be passed as a context for the state machine." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMBlueprint_Statics::NewProp_AssetVersion_MetaData[] = {
		{ "ModuleRelativePath", "Public/Blueprints/SMBlueprint.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USMBlueprint_Statics::NewProp_AssetVersion = { "AssetVersion", nullptr, (EPropertyFlags)0x0010010000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMBlueprint, AssetVersion), METADATA_PARAMS(Z_Construct_UClass_USMBlueprint_Statics::NewProp_AssetVersion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMBlueprint_Statics::NewProp_AssetVersion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMBlueprint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMBlueprint_Statics::NewProp_AssetVersion,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMBlueprint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMBlueprint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMBlueprint_Statics::ClassParams = {
		&USMBlueprint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMBlueprint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMBlueprint_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMBlueprint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMBlueprint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMBlueprint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMBlueprint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMBlueprint, 1872076467);
	template<> SMSYSTEM_API UClass* StaticClass<USMBlueprint>()
	{
		return USMBlueprint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMBlueprint(Z_Construct_UClass_USMBlueprint, &USMBlueprint::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMBlueprint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMBlueprint);
	void USMNodeBlueprint::StaticRegisterNativesUSMNodeBlueprint()
	{
	}
	UClass* Z_Construct_UClass_USMNodeBlueprint_NoRegister()
	{
		return USMNodeBlueprint::StaticClass();
	}
	struct Z_Construct_UClass_USMNodeBlueprint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMNodeBlueprint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprint,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMNodeBlueprint_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * State Machine Node Class Blueprints allow you to define custom classes for nodes within your State Machine Blueprint. Reusable logic can be encapsulated\n * here as well as the ability to take more direct control over state machines by gaining access to other node class instances. Additionally these classes\n * can be extended using C++.\n */" },
		{ "DisplayName", "State Machine Node Class Blueprint" },
		{ "IncludePath", "Blueprints/SMBlueprint.h" },
		{ "ModuleRelativePath", "Public/Blueprints/SMBlueprint.h" },
		{ "ToolTip", "State Machine Node Class Blueprints allow you to define custom classes for nodes within your State Machine Blueprint. Reusable logic can be encapsulated\nhere as well as the ability to take more direct control over state machines by gaining access to other node class instances. Additionally these classes\ncan be extended using C++." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMNodeBlueprint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMNodeBlueprint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMNodeBlueprint_Statics::ClassParams = {
		&USMNodeBlueprint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMNodeBlueprint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMNodeBlueprint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMNodeBlueprint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMNodeBlueprint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMNodeBlueprint, 4258258114);
	template<> SMSYSTEM_API UClass* StaticClass<USMNodeBlueprint>()
	{
		return USMNodeBlueprint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMNodeBlueprint(Z_Construct_UClass_USMNodeBlueprint, &USMNodeBlueprint::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMNodeBlueprint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMNodeBlueprint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
