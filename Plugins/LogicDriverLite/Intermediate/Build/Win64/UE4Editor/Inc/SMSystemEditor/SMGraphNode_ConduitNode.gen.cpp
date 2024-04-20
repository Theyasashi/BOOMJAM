// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_ConduitNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_ConduitNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_ConduitNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_ConduitNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMConduitInstance_NoRegister();
// End Cross Module References
	void USMGraphNode_ConduitNode::StaticRegisterNativesUSMGraphNode_ConduitNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_ConduitNode_NoRegister()
	{
		return USMGraphNode_ConduitNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_ConduitNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConduitClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ConduitClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEvalWithTransitions_MetaData[];
#endif
		static void NewProp_bEvalWithTransitions_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEvalWithTransitions;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_StateNodeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/Nodes/SMGraphNode_ConduitNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_ConduitNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_ConduitClass_MetaData[] = {
		{ "BlueprintBaseOnly", "" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_ConduitNode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_ConduitClass = { "ConduitClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_ConduitNode, ConduitClass), Z_Construct_UClass_USMConduitInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_ConduitClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_ConduitClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_ConduitNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions_SetBit(void* Obj)
	{
		((USMGraphNode_ConduitNode*)Obj)->bEvalWithTransitions_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions = { "bEvalWithTransitions", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_ConduitNode), &Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_ConduitClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::NewProp_bEvalWithTransitions,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_ConduitNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::ClassParams = {
		&USMGraphNode_ConduitNode::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::PropPointers),
		0,
		0x008804A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_ConduitNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_ConduitNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_ConduitNode, 3954549833);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_ConduitNode>()
	{
		return USMGraphNode_ConduitNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_ConduitNode(Z_Construct_UClass_USMGraphNode_ConduitNode, &USMGraphNode_ConduitNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_ConduitNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_ConduitNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
