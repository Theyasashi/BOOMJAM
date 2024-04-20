// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_TransitionEdge.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_TransitionEdge() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_TransitionEdge_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_TransitionEdge();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_Base();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance_NoRegister();
	SMSYSTEMEDITOR_API UEnum* Z_Construct_UEnum_SMSystemEditor_ESMDelegateOwner();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
// End Cross Module References
	void USMGraphNode_TransitionEdge::StaticRegisterNativesUSMGraphNode_TransitionEdge()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_TransitionEdge_NoRegister()
	{
		return USMGraphNode_TransitionEdge::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_TransitionClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelegateOwnerInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DelegateOwnerInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelegateOwnerClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DelegateOwnerClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelegatePropertyGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DelegatePropertyGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelegatePropertyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_DelegatePropertyName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEventTriggersTargetedUpdate_MetaData[];
#endif
		static void NewProp_bEventTriggersTargetedUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEventTriggersTargetedUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEventTriggersFullUpdate_MetaData[];
#endif
		static void NewProp_bEventTriggersFullUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEventTriggersFullUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanEvaluate_MetaData[];
#endif
		static void NewProp_bCanEvaluate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanEvaluate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanEvaluateFromEvent_MetaData[];
#endif
		static void NewProp_bCanEvaluateFromEvent_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanEvaluateFromEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanEvalWithStartState_MetaData[];
#endif
		static void NewProp_bCanEvalWithStartState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanEvalWithStartState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PriorityOrder_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_PriorityOrder;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_TransitionClass_MetaData[] = {
		{ "BlueprintBaseOnly", "" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_TransitionClass = { "TransitionClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, TransitionClass), Z_Construct_UClass_USMTransitionInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_TransitionClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_TransitionClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerInstance_MetaData[] = {
		{ "Category", "Event Trigger" },
		{ "Comment", "/**\n\x09 * The instance which owns the delegate the transition should bind to.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "The instance which owns the delegate the transition should bind to." },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerInstance = { "DelegateOwnerInstance", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, DelegateOwnerInstance), Z_Construct_UEnum_SMSystemEditor_ESMDelegateOwner, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerClass_MetaData[] = {
		{ "Category", "Event Trigger" },
		{ "Comment", "/**\n\x09 * The class of the instance containing the delegate.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "The class of the instance containing the delegate." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerClass = { "DelegateOwnerClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, DelegateOwnerClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyGuid_MetaData[] = {
		{ "Comment", "/**\n\x09 * The guid assigned to this property if one exists.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "The guid assigned to this property if one exists." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyGuid = { "DelegatePropertyGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, DelegatePropertyGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyName_MetaData[] = {
		{ "Category", "Event Trigger" },
		{ "Comment", "/**\n\x09 * Available delegates.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "Available delegates." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyName = { "DelegatePropertyName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, DelegatePropertyName), METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate_MetaData[] = {
		{ "Category", "Event Trigger" },
		{ "Comment", "/**\n\x09 * If the event should trigger a targeted update of the state machine limited to this\n\x09 * transition and destination state.\n\x09 * \n\x09 * This can efficiently allow state machines with tick disabled to update. This\n\x09 * won't evaluate parallel or super state transitions.\n\x09 *\n\x09 * This setting can also be changed on each Event Trigger Result Node.\n\x09 */" },
		{ "DisplayName", "Targeted Update" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "If the event should trigger a targeted update of the state machine limited to this\ntransition and destination state.\n\nThis can efficiently allow state machines with tick disabled to update. This\nwon't evaluate parallel or super state transitions.\n\nThis setting can also be changed on each Event Trigger Result Node." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate_SetBit(void* Obj)
	{
		((USMGraphNode_TransitionEdge*)Obj)->bEventTriggersTargetedUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate = { "bEventTriggersTargetedUpdate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_TransitionEdge), &Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate_MetaData[] = {
		{ "Category", "Event Trigger" },
		{ "Comment", "/**\n\x09 * If the event should trigger a full update of the state machine. Setting this will be applied\n\x09 * after 'Targeted Update'. A full update consists of evaluating transitions top down from the\n\x09 * root state machine, as well as running OnStateUpdate if necessary.\n\x09 *\n\x09 * This is a legacy setting. To maintain old legacy behavior enable this setting and\n\x09 * disable 'Targeted Update'.\n\x09 *\n\x09 * This setting can also be changed on each Event Trigger Result Node.\n\x09 */" },
		{ "DisplayName", "Full Update" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "If the event should trigger a full update of the state machine. Setting this will be applied\nafter 'Targeted Update'. A full update consists of evaluating transitions top down from the\nroot state machine, as well as running OnStateUpdate if necessary.\n\nThis is a legacy setting. To maintain old legacy behavior enable this setting and\ndisable 'Targeted Update'.\n\nThis setting can also be changed on each Event Trigger Result Node." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate_SetBit(void* Obj)
	{
		((USMGraphNode_TransitionEdge*)Obj)->bEventTriggersFullUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate = { "bEventTriggersFullUpdate", nullptr, (EPropertyFlags)0x0010040000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_TransitionEdge), &Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate_SetBit(void* Obj)
	{
		((USMGraphNode_TransitionEdge*)Obj)->bCanEvaluate_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate = { "bCanEvaluate", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_TransitionEdge), &Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent_SetBit(void* Obj)
	{
		((USMGraphNode_TransitionEdge*)Obj)->bCanEvaluateFromEvent_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent = { "bCanEvaluateFromEvent", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_TransitionEdge), &Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState_SetBit(void* Obj)
	{
		((USMGraphNode_TransitionEdge*)Obj)->bCanEvalWithStartState_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState = { "bCanEvalWithStartState", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_TransitionEdge), &Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_PriorityOrder_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_TransitionEdge.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_PriorityOrder = { "PriorityOrder", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_TransitionEdge, PriorityOrder_DEPRECATED), METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_PriorityOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_PriorityOrder_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_TransitionClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegateOwnerClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_DelegatePropertyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersTargetedUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bEventTriggersFullUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvaluateFromEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_bCanEvalWithStartState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::NewProp_PriorityOrder,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_TransitionEdge>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::ClassParams = {
		&USMGraphNode_TransitionEdge::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::PropPointers),
		0,
		0x009004A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_TransitionEdge()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_TransitionEdge_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_TransitionEdge, 822318728);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_TransitionEdge>()
	{
		return USMGraphNode_TransitionEdge::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_TransitionEdge(Z_Construct_UClass_USMGraphNode_TransitionEdge, &USMGraphNode_TransitionEdge::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_TransitionEdge"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_TransitionEdge);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
