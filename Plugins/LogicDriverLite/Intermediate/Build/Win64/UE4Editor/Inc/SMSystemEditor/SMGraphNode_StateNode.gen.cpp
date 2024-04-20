// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_StateNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_StateNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNode();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_NoRegister();
// End Cross Module References
	void USMGraphNode_StateNodeBase::StaticRegisterNativesUSMGraphNode_StateNodeBase()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase_NoRegister()
	{
		return USMGraphNode_StateNodeBase::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AnyStateTags_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AnyStateTags;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlwaysUpdate_MetaData[];
#endif
		static void NewProp_bAlwaysUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlwaysUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisableTickTransitionEvaluation_MetaData[];
#endif
		static void NewProp_bDisableTickTransitionEvaluation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisableTickTransitionEvaluation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEvalTransitionsOnStart_MetaData[];
#endif
		static void NewProp_bEvalTransitionsOnStart_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEvalTransitionsOnStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExcludeFromAnyState_MetaData[];
#endif
		static void NewProp_bExcludeFromAnyState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeFromAnyState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/** Base class required as states and conduits branch separately from a common source. */" },
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "Base class required as states and conduits branch separately from a common source." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_AnyStateTags_MetaData[] = {
		{ "Category", "Any State" },
		{ "Comment", "/**\n\x09 * Add tags to this state that Any State nodes will recognize.\n\x09 * This can allow control over which specific Any State nodes should impact this state.\n\x09 *\n\x09 * On the Any State you can define an AnyStateTagQuery to control which tags an Any State should recognize.\n\x09 * Only valid in the editor.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "Add tags to this state that Any State nodes will recognize.\nThis can allow control over which specific Any State nodes should impact this state.\n\nOn the Any State you can define an AnyStateTagQuery to control which tags an Any State should recognize.\nOnly valid in the editor." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_AnyStateTags = { "AnyStateTags", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateNodeBase, AnyStateTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_AnyStateTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_AnyStateTags_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate_SetBit(void* Obj)
	{
		((USMGraphNode_StateNodeBase*)Obj)->bAlwaysUpdate_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate = { "bAlwaysUpdate", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateNodeBase), &Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit(void* Obj)
	{
		((USMGraphNode_StateNodeBase*)Obj)->bDisableTickTransitionEvaluation_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation = { "bDisableTickTransitionEvaluation", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateNodeBase), &Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart_SetBit(void* Obj)
	{
		((USMGraphNode_StateNodeBase*)Obj)->bEvalTransitionsOnStart_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart = { "bEvalTransitionsOnStart", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateNodeBase), &Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState_SetBit(void* Obj)
	{
		((USMGraphNode_StateNodeBase*)Obj)->bExcludeFromAnyState_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState = { "bExcludeFromAnyState", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateNodeBase), &Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_AnyStateTags,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bAlwaysUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bDisableTickTransitionEvaluation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bEvalTransitionsOnStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::NewProp_bExcludeFromAnyState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_StateNodeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::ClassParams = {
		&USMGraphNode_StateNodeBase::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::PropPointers),
		0,
		0x009004A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_StateNodeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_StateNodeBase, 3166189813);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_StateNodeBase>()
	{
		return USMGraphNode_StateNodeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_StateNodeBase(Z_Construct_UClass_USMGraphNode_StateNodeBase, &USMGraphNode_StateNodeBase::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_StateNodeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_StateNodeBase);
	void USMGraphNode_StateNode::StaticRegisterNativesUSMGraphNode_StateNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_StateNode_NoRegister()
	{
		return USMGraphNode_StateNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_StateNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_StateClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_StateNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_StateNodeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Regular state nodes which have K2 graphs.\n */" },
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
		{ "ToolTip", "Regular state nodes which have K2 graphs." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateNode_Statics::NewProp_StateClass_MetaData[] = {
		{ "BlueprintBaseOnly", "" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateNode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_StateNode_Statics::NewProp_StateClass = { "StateClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateNode, StateClass), Z_Construct_UClass_USMStateInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNode_Statics::NewProp_StateClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNode_Statics::NewProp_StateClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_StateNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateNode_Statics::NewProp_StateClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_StateNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_StateNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_StateNode_Statics::ClassParams = {
		&USMGraphNode_StateNode::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_StateNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNode_Statics::PropPointers),
		0,
		0x009004A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_StateNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_StateNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_StateNode, 2626554316);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_StateNode>()
	{
		return USMGraphNode_StateNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_StateNode(Z_Construct_UClass_USMGraphNode_StateNode, &USMGraphNode_StateNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_StateNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_StateNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
