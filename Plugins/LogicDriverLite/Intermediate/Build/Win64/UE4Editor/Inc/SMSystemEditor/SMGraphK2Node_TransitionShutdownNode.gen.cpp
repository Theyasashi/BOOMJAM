// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/RootNodes/SMGraphK2Node_TransitionShutdownNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphK2Node_TransitionShutdownNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphK2Node_RuntimeNodeReference();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
// End Cross Module References
	void USMGraphK2Node_TransitionShutdownNode::StaticRegisterNativesUSMGraphK2Node_TransitionShutdownNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_NoRegister()
	{
		return USMGraphK2Node_TransitionShutdownNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphK2Node_RuntimeNodeReference,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Can be used in Transition graphs and Conduit graphs when they're configured as transitions.\n */" },
		{ "IncludePath", "Graph/Nodes/RootNodes/SMGraphK2Node_TransitionShutdownNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/RootNodes/SMGraphK2Node_TransitionShutdownNode.h" },
		{ "ToolTip", "Can be used in Transition graphs and Conduit graphs when they're configured as transitions." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphK2Node_TransitionShutdownNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::ClassParams = {
		&USMGraphK2Node_TransitionShutdownNode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphK2Node_TransitionShutdownNode, 3185803294);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphK2Node_TransitionShutdownNode>()
	{
		return USMGraphK2Node_TransitionShutdownNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphK2Node_TransitionShutdownNode(Z_Construct_UClass_USMGraphK2Node_TransitionShutdownNode, &USMGraphK2Node_TransitionShutdownNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphK2Node_TransitionShutdownNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphK2Node_TransitionShutdownNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
