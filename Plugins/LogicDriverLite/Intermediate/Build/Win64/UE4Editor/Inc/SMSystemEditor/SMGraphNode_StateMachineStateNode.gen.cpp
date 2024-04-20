// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystemEditor/Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMGraphNode_StateMachineStateNode() {}
// Cross Module References
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineStateNode_NoRegister();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateMachineStateNode();
	SMSYSTEMEDITOR_API UClass* Z_Construct_UClass_USMGraphNode_StateNodeBase();
	UPackage* Z_Construct_UPackage__Script_SMSystemEditor();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMBlueprint_NoRegister();
// End Cross Module References
	void USMGraphNode_StateMachineStateNode::StaticRegisterNativesUSMGraphNode_StateMachineStateNode()
	{
	}
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineStateNode_NoRegister()
	{
		return USMGraphNode_StateMachineStateNode::StaticClass();
	}
	struct Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynamicClassVariable_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_DynamicClassVariable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReuseCurrentState_MetaData[];
#endif
		static void NewProp_bReuseCurrentState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReuseCurrentState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReuseIfNotEndState_MetaData[];
#endif
		static void NewProp_bReuseIfNotEndState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReuseIfNotEndState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowIndependentTick_MetaData[];
#endif
		static void NewProp_bAllowIndependentTick_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowIndependentTick;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCallTickOnManualUpdate_MetaData[];
#endif
		static void NewProp_bCallTickOnManualUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCallTickOnManualUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReuseReference_MetaData[];
#endif
		static void NewProp_bReuseReference_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReuseReference;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseTemplate_MetaData[];
#endif
		static void NewProp_bUseTemplate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferencedInstanceTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReferencedInstanceTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateMachineClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_StateMachineClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferencedStateMachine_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReferencedStateMachine;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DesiredNodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DesiredNodeName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShouldUseIntermediateGraph_MetaData[];
#endif
		static void NewProp_bShouldUseIntermediateGraph_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShouldUseIntermediateGraph;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNeedsNewReference_MetaData[];
#endif
		static void NewProp_bNeedsNewReference_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNeedsNewReference;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMGraphNode_StateNodeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystemEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DynamicClassVariable_MetaData[] = {
		{ "Category", "State Machine Reference" },
		{ "Comment", "/**\n\x09 * Dynamically choose the state machine class for the reference at run-time.\n\x09 * \n\x09 * Select a variable from this state machine of type TSubclassOf<USMInstance>\n\x09 * (State Machine Instance -> Class Reference)\n\x09 * \n\x09 * This variable will be checked during initialization time and the reference will be created\n\x09 * based on the class the variable is set to.\n\x09 *\n\x09 * The class should be a subclass of the default reference provided.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "Dynamically choose the state machine class for the reference at run-time.\n\nSelect a variable from this state machine of type TSubclassOf<USMInstance>\n(State Machine Instance -> Class Reference)\n\nThis variable will be checked during initialization time and the reference will be created\nbased on the class the variable is set to.\n\nThe class should be a subclass of the default reference provided." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DynamicClassVariable = { "DynamicClassVariable", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineStateNode, DynamicClassVariable), METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DynamicClassVariable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DynamicClassVariable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bReuseCurrentState_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState = { "bReuseCurrentState", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState_MetaData[] = {
		{ "Comment", "/**\n\x09 * @deprecated Set on the node template instead.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "@deprecated Set on the node template instead." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bReuseIfNotEndState_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState = { "bReuseIfNotEndState", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick_MetaData[] = {
		{ "Category", "State Machine Reference" },
		{ "Comment", "/**\n\x09 * Allows the state machine reference to tick on its own.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "Allows the state machine reference to tick on its own." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bAllowIndependentTick = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick = { "bAllowIndependentTick", nullptr, (EPropertyFlags)0x0010040000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate_MetaData[] = {
		{ "Category", "State Machine Reference" },
		{ "Comment", "/**\n\x09 * The Update method will call Tick only if Update was not called by native Tick.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "The Update method will call Tick only if Update was not called by native Tick." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bCallTickOnManualUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate = { "bCallTickOnManualUpdate", nullptr, (EPropertyFlags)0x0010040000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference_MetaData[] = {
		{ "Comment", "/**\n\x09 * Reuse one instance of this class multiple times in the same blueprint.\n\x09 * Only works with other references of the exact same class that have this flag checked.\n\x09 * Will not work with templating.\n\x09 * Will not work properly with looking up nodes by Guid or for serializing state information.\n\x09 * Do NOT use if the state machine needs to be saved to disk and reloaded during run-time.\n\n\x09 * This is to maintain legacy behavior and not encouraged for use.\n\x09 *\n\x09 * @deprecated Reusing references is no longer supported.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "Reuse one instance of this class multiple times in the same blueprint.\nOnly works with other references of the exact same class that have this flag checked.\nWill not work with templating.\nWill not work properly with looking up nodes by Guid or for serializing state information.\nDo NOT use if the state machine needs to be saved to disk and reloaded during run-time.\n\nThis is to maintain legacy behavior and not encouraged for use.\n\n@deprecated Reusing references is no longer supported." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bReuseReference_DEPRECATED = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference = { "bReuseReference", nullptr, (EPropertyFlags)0x0010000020000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate_MetaData[] = {
		{ "Category", "State Machine Reference" },
		{ "Comment", "/**\n\x09 * Enable the use of an archetype to allow default values to be set.\n\x09 */" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ToolTip", "Enable the use of an archetype to allow default values to be set." },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bUseTemplate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate = { "bUseTemplate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedInstanceTemplate_MetaData[] = {
		{ "Category", "State Machine Reference" },
		{ "DisplayName", "Template" },
		{ "DisplayThumbnail", "FALSE" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
		{ "ShowInnerProperties", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedInstanceTemplate = { "ReferencedInstanceTemplate", nullptr, (EPropertyFlags)0x0010000000030009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineStateNode, ReferencedInstanceTemplate), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedInstanceTemplate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedInstanceTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_StateMachineClass_MetaData[] = {
		{ "BlueprintBaseOnly", "" },
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_StateMachineClass = { "StateMachineClass", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineStateNode, StateMachineClass), Z_Construct_UClass_USMStateMachineInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_StateMachineClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_StateMachineClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedStateMachine_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedStateMachine = { "ReferencedStateMachine", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineStateNode, ReferencedStateMachine), Z_Construct_UClass_USMBlueprint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedStateMachine_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedStateMachine_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DesiredNodeName_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DesiredNodeName = { "DesiredNodeName", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMGraphNode_StateMachineStateNode, DesiredNodeName), METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DesiredNodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DesiredNodeName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bShouldUseIntermediateGraph = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph = { "bShouldUseIntermediateGraph", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference_MetaData[] = {
		{ "ModuleRelativePath", "Private/Graph/Nodes/SMGraphNode_StateMachineStateNode.h" },
	};
#endif
	void Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference_SetBit(void* Obj)
	{
		((USMGraphNode_StateMachineStateNode*)Obj)->bNeedsNewReference = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference = { "bNeedsNewReference", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMGraphNode_StateMachineStateNode), &Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DynamicClassVariable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseCurrentState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseIfNotEndState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bAllowIndependentTick,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bCallTickOnManualUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bReuseReference,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bUseTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedInstanceTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_StateMachineClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_ReferencedStateMachine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_DesiredNodeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bShouldUseIntermediateGraph,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::NewProp_bNeedsNewReference,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMGraphNode_StateMachineStateNode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::ClassParams = {
		&USMGraphNode_StateMachineStateNode::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::PropPointers),
		0,
		0x009004A4u,
		METADATA_PARAMS(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMGraphNode_StateMachineStateNode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMGraphNode_StateMachineStateNode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMGraphNode_StateMachineStateNode, 3119726410);
	template<> SMSYSTEMEDITOR_API UClass* StaticClass<USMGraphNode_StateMachineStateNode>()
	{
		return USMGraphNode_StateMachineStateNode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMGraphNode_StateMachineStateNode(Z_Construct_UClass_USMGraphNode_StateMachineStateNode, &USMGraphNode_StateMachineStateNode::StaticClass, TEXT("/Script/SMSystemEditor"), TEXT("USMGraphNode_StateMachineStateNode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMGraphNode_StateMachineStateNode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
