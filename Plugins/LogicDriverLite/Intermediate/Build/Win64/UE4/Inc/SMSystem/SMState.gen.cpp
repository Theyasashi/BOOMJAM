// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/States/SMState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMState() {}
// Cross Module References
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMState();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMState_Base();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMExposedFunctionHandler();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMNode_Base();
// End Cross Module References

static_assert(std::is_polymorphic<FSMState>() == std::is_polymorphic<FSMState_Base>(), "USTRUCT FSMState cannot be polymorphic unless super FSMState_Base is polymorphic");

class UScriptStruct* FSMState::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMState_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMState, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMState"), sizeof(FSMState), Get_Z_Construct_UScriptStruct_FSMState_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMState>()
{
	return FSMState::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMState(FSMState::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMState"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMState
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMState()
	{
		UScriptStruct::DeferCppStructOps<FSMState>(FName(TEXT("SMState")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMState;
	struct Z_Construct_UScriptStruct_FSMState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BeginStateGraphEvaluator_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BeginStateGraphEvaluator_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_BeginStateGraphEvaluator;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UpdateStateGraphEvaluator_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UpdateStateGraphEvaluator_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UpdateStateGraphEvaluator;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EndStateGraphEvaluator_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndStateGraphEvaluator_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_EndStateGraphEvaluator;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * State nodes that can execute Blueprint logic.\n */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "State nodes that can execute Blueprint logic." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMState>();
	}
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator_Inner = { "BeginStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator = { "BeginStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMState, BeginStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator_Inner = { "UpdateStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator = { "UpdateStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMState, UpdateStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator_Inner = { "EndStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator = { "EndStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMState, EndStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_BeginStateGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_UpdateStateGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Statics::NewProp_EndStateGraphEvaluator,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMState_Base,
		&NewStructOps,
		"SMState",
		sizeof(FSMState),
		alignof(FSMState),
		Z_Construct_UScriptStruct_FSMState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMState()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMState_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMState"), sizeof(FSMState), Get_Z_Construct_UScriptStruct_FSMState_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMState_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMState_Hash() { return 3453179011U; }

static_assert(std::is_polymorphic<FSMState_Base>() == std::is_polymorphic<FSMNode_Base>(), "USTRUCT FSMState_Base cannot be polymorphic unless super FSMNode_Base is polymorphic");

class UScriptStruct* FSMState_Base::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMState_Base_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMState_Base, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMState_Base"), sizeof(FSMState_Base), Get_Z_Construct_UScriptStruct_FSMState_Base_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMState_Base>()
{
	return FSMState_Base::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMState_Base(FSMState_Base::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMState_Base"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMState_Base
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMState_Base()
	{
		UScriptStruct::DeferCppStructOps<FSMState_Base>(FName(TEXT("SMState_Base")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMState_Base;
	struct Z_Construct_UScriptStruct_FSMState_Base_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsRootNode_MetaData[];
#endif
		static void NewProp_bIsRootNode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsRootNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlwaysUpdate_MetaData[];
#endif
		static void NewProp_bAlwaysUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlwaysUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEvalTransitionsOnStart_MetaData[];
#endif
		static void NewProp_bEvalTransitionsOnStart_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEvalTransitionsOnStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisableTickTransitionEvaluation_MetaData[];
#endif
		static void NewProp_bDisableTickTransitionEvaluation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisableTickTransitionEvaluation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStayActiveOnStateChange_MetaData[];
#endif
		static void NewProp_bStayActiveOnStateChange_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStayActiveOnStateChange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowParallelReentry_MetaData[];
#endif
		static void NewProp_bAllowParallelReentry_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowParallelReentry;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * The base class for all state typed nodes. This should never be instantiated by itself but inherited by children.\n */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "The base class for all state typed nodes. This should never be instantiated by itself but inherited by children." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMState_Base_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMState_Base>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode_MetaData[] = {
		{ "Comment", "/** Entry node to state machine. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "Entry node to state machine." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bIsRootNode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode = { "bIsRootNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate_MetaData[] = {
		{ "Comment", "/** Always call state update at least once before ending. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "Always call state update at least once before ending." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bAlwaysUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate = { "bAlwaysUpdate", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData[] = {
		{ "Comment", "/** Allows transitions to be evaluated in the same tick as Start State. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "Allows transitions to be evaluated in the same tick as Start State." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bEvalTransitionsOnStart = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart = { "bEvalTransitionsOnStart", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData[] = {
		{ "Comment", "/** Prevents conditional transitions for this state from being evaluated on Tick. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "Prevents conditional transitions for this state from being evaluated on Tick." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bDisableTickTransitionEvaluation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation = { "bDisableTickTransitionEvaluation", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange_MetaData[] = {
		{ "Comment", "/** If the state should remain active even after a transition is taken from this state. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "If the state should remain active even after a transition is taken from this state." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bStayActiveOnStateChange = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange = { "bStayActiveOnStateChange", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry_MetaData[] = {
		{ "Comment", "/** If this state can be reentered from a parallel state if this state is already active. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMState.h" },
		{ "ToolTip", "If this state can be reentered from a parallel state if this state is already active." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry_SetBit(void* Obj)
	{
		((FSMState_Base*)Obj)->bAllowParallelReentry = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry = { "bAllowParallelReentry", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMState_Base), &Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMState_Base_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bIsRootNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAlwaysUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bEvalTransitionsOnStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bDisableTickTransitionEvaluation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bStayActiveOnStateChange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMState_Base_Statics::NewProp_bAllowParallelReentry,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMState_Base_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMNode_Base,
		&NewStructOps,
		"SMState_Base",
		sizeof(FSMState_Base),
		alignof(FSMState_Base),
		Z_Construct_UScriptStruct_FSMState_Base_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMState_Base_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMState_Base_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMState_Base()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMState_Base_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMState_Base"), sizeof(FSMState_Base), Get_Z_Construct_UScriptStruct_FSMState_Base_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMState_Base_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMState_Base_Hash() { return 1232388177U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
