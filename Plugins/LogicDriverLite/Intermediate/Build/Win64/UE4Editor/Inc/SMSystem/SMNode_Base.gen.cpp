// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/SMNode_Base.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMNode_Base() {}
// Cross Module References
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMNode_Base();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMExposedFunctionHandler();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
class UScriptStruct* FSMNode_Base::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMNode_Base_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMNode_Base, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMNode_Base"), sizeof(FSMNode_Base), Get_Z_Construct_UScriptStruct_FSMNode_Base_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMNode_Base>()
{
	return FSMNode_Base::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMNode_Base(FSMNode_Base::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMNode_Base"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMNode_Base
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMNode_Base()
	{
		UScriptStruct::DeferCppStructOps<FSMNode_Base>(FName(TEXT("SMNode_Base")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMNode_Base;
	struct Z_Construct_UScriptStruct_FSMNode_Base_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TransitionInitializedGraphEvaluators_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionInitializedGraphEvaluators_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TransitionInitializedGraphEvaluators;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TransitionShutdownGraphEvaluators_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransitionShutdownGraphEvaluators_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TransitionShutdownGraphEvaluators;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OnRootStateMachineStartedGraphEvaluator_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnRootStateMachineStartedGraphEvaluator_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OnRootStateMachineStartedGraphEvaluator;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OnRootStateMachineStoppedGraphEvaluator_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnRootStateMachineStoppedGraphEvaluator_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OnRootStateMachineStoppedGraphEvaluator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeInState_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeInState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsInEndState_MetaData[];
#endif
		static void NewProp_bIsInEndState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsInEndState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasUpdated_MetaData[];
#endif
		static void NewProp_bHasUpdated_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasUpdated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DuplicateId_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_DuplicateId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnerGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_OwnerGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NodeName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TemplateName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_TemplateName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwningInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwningInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NodeInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeInstanceClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_NodeInstanceClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Base struct for all state machine nodes. The Guid MUST be manually initialized right after construction.\n */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "Base struct for all state machine nodes. The Guid MUST be manually initialized right after construction." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMNode_Base>();
	}
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators_Inner = { "TransitionInitializedGraphEvaluators", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators_MetaData[] = {
		{ "Comment", "/** Entry point to when a transition is first initialized. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "Entry point to when a transition is first initialized." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators = { "TransitionInitializedGraphEvaluators", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, TransitionInitializedGraphEvaluators), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators_Inner = { "TransitionShutdownGraphEvaluators", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators_MetaData[] = {
		{ "Comment", "/** Entry point to when a transition is shutdown. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "Entry point to when a transition is shutdown." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators = { "TransitionShutdownGraphEvaluators", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, TransitionShutdownGraphEvaluators), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator_Inner = { "OnRootStateMachineStartedGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator_MetaData[] = {
		{ "Comment", "/** When the owning blueprint's root state machine starts. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "When the owning blueprint's root state machine starts." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator = { "OnRootStateMachineStartedGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, OnRootStateMachineStartedGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator_Inner = { "OnRootStateMachineStoppedGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator_MetaData[] = {
		{ "Comment", "/** When the owning blueprint's root state machine stops. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "When the owning blueprint's root state machine stops." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator = { "OnRootStateMachineStoppedGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, OnRootStateMachineStoppedGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TimeInState_MetaData[] = {
		{ "Category", "State Machines" },
		{ "Comment", "/** The current time spent in the state. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The current time spent in the state." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TimeInState = { "TimeInState", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, TimeInState), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TimeInState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TimeInState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState_MetaData[] = {
		{ "Category", "State Machines" },
		{ "Comment", "/** State Machine is in end state or the state is an end state. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "State Machine is in end state or the state is an end state." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState_SetBit(void* Obj)
	{
		((FSMNode_Base*)Obj)->bIsInEndState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState = { "bIsInEndState", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMNode_Base), &Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated_MetaData[] = {
		{ "Category", "State Machines" },
		{ "Comment", "/** State has updated at least once. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "State has updated at least once." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated_SetBit(void* Obj)
	{
		((FSMNode_Base*)Obj)->bHasUpdated = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated = { "bHasUpdated", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMNode_Base), &Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_DuplicateId_MetaData[] = {
		{ "Comment", "/** Special indicator in case this node is a duplicate within the same blueprint. If this isn't 0 then the NodeGuid will have been adjusted. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "Special indicator in case this node is a duplicate within the same blueprint. If this isn't 0 then the NodeGuid will have been adjusted." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_DuplicateId = { "DuplicateId", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, DuplicateId), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_DuplicateId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_DuplicateId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_Guid_MetaData[] = {
		{ "Category", "Graph Node" },
		{ "Comment", "/*\n\x09 * NodeGuid must always be unique. Do not duplicate the guid in any other node in any blueprint.\n\x09 *\n\x09 * This is not the same guid that is used at run-time. At run-time all NodeGuids in a path to a node\n\x09 * are hashed to form the PathGuid. This is done to account for multiple references and parent graph calls.\n\x09 *\n\x09 * If you need to change the path of a node (such as collapse it to a nested state machine) and you need to maintain\n\x09 * the old guid for run-time saves to work, you should use the GuidRedirectMap on the primary state machine instance\n\x09 * which accepts PathGuids.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "* NodeGuid must always be unique. Do not duplicate the guid in any other node in any blueprint.\n*\n* This is not the same guid that is used at run-time. At run-time all NodeGuids in a path to a node\n* are hashed to form the PathGuid. This is done to account for multiple references and parent graph calls.\n*\n* If you need to change the path of a node (such as collapse it to a nested state machine) and you need to maintain\n* the old guid for run-time saves to work, you should use the GuidRedirectMap on the primary state machine instance\n* which accepts PathGuids." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_Guid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwnerGuid_MetaData[] = {
		{ "Comment", "/** The state machine's NodeGuid owning this node. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The state machine's NodeGuid owning this node." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwnerGuid = { "OwnerGuid", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, OwnerGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwnerGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwnerGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_PathGuid_MetaData[] = {
		{ "Category", "Graph Node" },
		{ "Comment", "/*\n\x09 * Unique identifier calculated from this node's place in an instance.\n\x09 * Calculated by taking the MD5 hash of the full path of all owner NodeGuids and\n\x09 * this NodeGuid.\n\x09 * This is what is returned from GetGuid().\n\x09 * \n\x09 * ReadWrite so it can be easily read from custom graph nodes.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "* Unique identifier calculated from this node's place in an instance.\n* Calculated by taking the MD5 hash of the full path of all owner NodeGuids and\n* this NodeGuid.\n* This is what is returned from GetGuid().\n*\n* ReadWrite so it can be easily read from custom graph nodes." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_PathGuid = { "PathGuid", nullptr, (EPropertyFlags)0x0020080000000004, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, PathGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_PathGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_PathGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeName = { "NodeName", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, NodeName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TemplateName_MetaData[] = {
		{ "Comment", "/** The name of a template archetype to use when constructing an instance. This allows default values be passed into the instance. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The name of a template archetype to use when constructing an instance. This allows default values be passed into the instance." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TemplateName = { "TemplateName", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, TemplateName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TemplateName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TemplateName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwningInstance_MetaData[] = {
		{ "Comment", "/** The state machine instance owning this node. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The state machine instance owning this node." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwningInstance = { "OwningInstance", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, OwningInstance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwningInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwningInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstance_MetaData[] = {
		{ "Category", "Node Class" },
		{ "Comment", "/** The node instance for this node if it exists. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The node instance for this node if it exists." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstance = { "NodeInstance", nullptr, (EPropertyFlags)0x0020080000002004, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, NodeInstance), Z_Construct_UClass_USMNodeInstance_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstanceClass_MetaData[] = {
		{ "Category", "Node Class" },
		{ "Comment", "/** The class to use to construct the node instance if one exists. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNode_Base.h" },
		{ "ToolTip", "The class to use to construct the node instance if one exists." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstanceClass = { "NodeInstanceClass", nullptr, (EPropertyFlags)0x0020080000000004, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNode_Base, NodeInstanceClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstanceClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstanceClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMNode_Base_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionInitializedGraphEvaluators,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TransitionShutdownGraphEvaluators,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStartedGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OnRootStateMachineStoppedGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TimeInState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bIsInEndState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_bHasUpdated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_DuplicateId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwnerGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_PathGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_TemplateName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_OwningInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNode_Base_Statics::NewProp_NodeInstanceClass,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMNode_Base_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMNode_Base",
		sizeof(FSMNode_Base),
		alignof(FSMNode_Base),
		Z_Construct_UScriptStruct_FSMNode_Base_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNode_Base_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNode_Base_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMNode_Base()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMNode_Base_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMNode_Base"), sizeof(FSMNode_Base), Get_Z_Construct_UScriptStruct_FSMNode_Base_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMNode_Base_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMNode_Base_Hash() { return 2880391771U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
