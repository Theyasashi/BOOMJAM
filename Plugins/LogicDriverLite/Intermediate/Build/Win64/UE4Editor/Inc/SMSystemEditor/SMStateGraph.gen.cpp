// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/SMStateGraph.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMStateGraph() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMStateGraph_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMStateGraph();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_StateEntryNode_NoRegister();
// End Cross Module References
	void USMStateGraph::StaticRegisterNativesUSMStateGraph()
	{
	}
	UClass* Z_Construct_UClass_USMStateGraph_NoRegister()
	{
		return USMStateGraph::StaticClass();
	}
	struct Z_Construct_UClass_USMStateGraph_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EntryNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EntryNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMStateGraph_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphK2,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateGraph_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/SMStateGraph.h" },
		{ "ModuleRelativePath", "Private/Graph/SMStateGraph.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateGraph_Statics::NewProp_EntryNode_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/SMStateGraph.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMStateGraph_Statics::NewProp_EntryNode = { "EntryNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateGraph, EntryNode), Z_Construct_UClass_USMGraphK2Node_StateEntryNode_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMStateGraph_Statics::NewProp_EntryNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateGraph_Statics::NewProp_EntryNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMStateGraph_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateGraph_Statics::NewProp_EntryNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMStateGraph_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMStateGraph>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMStateGraph_Statics::ClassParams = {
		&USMStateGraph::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMStateGraph_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMStateGraph_Statics::PropPointers),
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMStateGraph_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateGraph_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMStateGraph()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMStateGraph_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMStateGraph, 3188632320);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMStateGraph>()
	{
		return USMStateGraph::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMStateGraph(Z_Construct_UClass_USMStateGraph, &USMStateGraph::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMStateGraph"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMStateGraph);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
