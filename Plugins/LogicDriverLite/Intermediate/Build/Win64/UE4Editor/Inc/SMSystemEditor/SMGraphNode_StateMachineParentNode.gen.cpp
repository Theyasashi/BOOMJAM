// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_StateMachineParentNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_StateMachineParentNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineParentNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineParentNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineStateNode();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraph_NoRegister();
// End Cross Module References
	void USMGraphNode_StateMachineParentNode::StaticRegisterNativesUSMGraphNode_StateMachineParentNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineParentNode_NoRegister()
	{
		return USMGraphNode_StateMachineParentNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ParentClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExpandedGraph_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExpandedGraph;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_StateMachineStateNode,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateMachineParentNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineParentNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ParentClass_MetaData[] = {
		{ "Category", "Parent State Machine" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineParentNode.h" },
		{ "NoResetToDefault", "" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ParentClass = { "ParentClass", nullptr, (EPropertyFlags)0x0014000002010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineParentNode, ParentClass), Z_Construct_UClass_USMInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ParentClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ParentClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ExpandedGraph_MetaData[] = {
		{ "Comment", "/** A cloned graph of the parent. Only valid during compile after ExpandParentNodes(). */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineParentNode.h" },
		{ "ToolTip", "A cloned graph of the parent. Only valid during compile after ExpandParentNodes()." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ExpandedGraph = { "ExpandedGraph", nullptr, (EPropertyFlags)0x0010000400002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineParentNode, ExpandedGraph), Z_Construct_UClass_USMGraph_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ExpandedGraph_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ExpandedGraph_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ParentClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::NewProp_ExpandedGraph,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_StateMachineParentNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::ClassParams = {
		&USMGraphNode_StateMachineParentNode::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::PropPointers),
		0,
		0x008804A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineParentNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_StateMachineParentNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_StateMachineParentNode, 3214843540);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_StateMachineParentNode>()
	{
		return USMGraphNode_StateMachineParentNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_StateMachineParentNode(Z_Construct_UClass_USMGraphNode_StateMachineParentNode, &USMGraphNode_StateMachineParentNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_StateMachineParentNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_StateMachineParentNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
