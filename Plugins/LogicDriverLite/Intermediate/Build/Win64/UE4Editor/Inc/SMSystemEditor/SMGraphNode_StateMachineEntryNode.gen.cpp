// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_StateMachineEntryNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_StateMachineEntryNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineEntryNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateMachine();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_RuntimeNodeContainer();
// End Cross Module References
	void USMGraphNode_StateMachineEntryNode::StaticRegisterNativesUSMGraphNode_StateMachineEntryNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_NoRegister()
	{
		return USMGraphNode_StateMachineEntryNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateMachineNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StateMachineNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Created for normal state machine UEdGraphs. */" },
		{ "HideCategories", "Class Display" },
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
		{ "ToolTip", "Created for normal state machine UEdGraphs." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData[] = {
		{ "Category", "State Machines" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::NewProp_StateMachineNode = { "StateMachineNode", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineEntryNode, StateMachineNode), Z_Construct_UScriptStruct_FSMStateMachine, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::NewProp_StateMachineNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_StateMachineEntryNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::ClassParams = {
		&USMGraphNode_StateMachineEntryNode::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::PropPointers),
		0,
		0x008804A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineEntryNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_StateMachineEntryNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_StateMachineEntryNode, 1896378249);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_StateMachineEntryNode>()
	{
		return USMGraphNode_StateMachineEntryNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_StateMachineEntryNode(Z_Construct_UClass_USMGraphNode_StateMachineEntryNode, &USMGraphNode_StateMachineEntryNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_StateMachineEntryNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_StateMachineEntryNode);
	void USMGraphK2Node_StateMachineEntryNode::StaticRegisterNativesUSMGraphK2Node_StateMachineEntryNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_NoRegister()
	{
		return USMGraphK2Node_StateMachineEntryNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateMachineNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StateMachineNode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphK2Node_RuntimeNodeContainer,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Created by compiler for nested state machine entry points. */" },
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
		{ "ToolTip", "Created by compiler for nested state machine entry points." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData[] = {
		{ "Category", "State Machines" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineEntryNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::NewProp_StateMachineNode = { "StateMachineNode", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphK2Node_StateMachineEntryNode, StateMachineNode), Z_Construct_UScriptStruct_FSMStateMachine, METADATA_PARAMS(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::NewProp_StateMachineNode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::NewProp_StateMachineNode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphK2Node_StateMachineEntryNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::ClassParams = {
		&USMGraphK2Node_StateMachineEntryNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::PropPointers),
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphK2Node_StateMachineEntryNode, 3548344503);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphK2Node_StateMachineEntryNode>()
	{
		return USMGraphK2Node_StateMachineEntryNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphK2Node_StateMachineEntryNode(Z_Construct_UClass_USMGraphK2Node_StateMachineEntryNode, &USMGraphK2Node_StateMachineEntryNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphK2Node_StateMachineEntryNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphK2Node_StateMachineEntryNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
