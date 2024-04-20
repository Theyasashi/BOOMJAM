// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/States/SMStateMachine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMStateMachine() {}
// Cross Module References
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateMachine();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMState_Base();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMExposedFunctionHandler();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
// End Cross Module References

static_assert(std::is_polymorphic<FSMStateMachine>() == std::is_polymorphic<FSMState_Base>(), "USTRUCT FSMStateMachine cannot be polymorphic unless super FSMState_Base is polymorphic");

class UScriptStruct* FSMStateMachine::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMStateMachine_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMStateMachine, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMStateMachine"), sizeof(FSMStateMachine), Get_Z_Construct_UScriptStruct_FSMStateMachine_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMStateMachine>()
{
	return FSMStateMachine::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMStateMachine(FSMStateMachine::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMStateMachine"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMStateMachine
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMStateMachine()
	{
		UScriptStruct::DeferCppStructOps<FSMStateMachine>(FName(TEXT("SMStateMachine")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMStateMachine;
	struct Z_Construct_UScriptStruct_FSMStateMachine_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasAdditionalLogic_MetaData[];
#endif
		static void NewProp_bHasAdditionalLogic_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasAdditionalLogic;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReuseCurrentState_MetaData[];
#endif
		static void NewProp_bReuseCurrentState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReuseCurrentState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOnlyReuseIfNotEndState_MetaData[];
#endif
		static void NewProp_bOnlyReuseIfNotEndState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOnlyReuseIfNotEndState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowIndependentTick_MetaData[];
#endif
		static void NewProp_bAllowIndependentTick_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowIndependentTick;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCallReferenceTickOnManualUpdate_MetaData[];
#endif
		static void NewProp_bCallReferenceTickOnManualUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCallReferenceTickOnManualUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bWaitForEndState_MetaData[];
#endif
		static void NewProp_bWaitForEndState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWaitForEndState;
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NetworkedInterface_MetaData[];
#endif
		static const UE4CodeGen_Private::FInterfacePropertyParams NewProp_NetworkedInterface;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferencedStateMachineClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ReferencedStateMachineClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferencedTemplateName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ReferencedTemplateName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DynamicStateMachineReferenceVariable_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_DynamicStateMachineReferenceVariable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferencedStateMachine_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReferencedStateMachine;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsReferencedByInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IsReferencedByInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * State machines contain states and transitions. When a transition succeeds the current state advances to the next.\n * FSMStateMachine is also considered a state since it inherits from FSMState_Base, making it possible to nest state machines.\n * \n * When configured as a reference this will defer handling to the SMInstance (or in some cases the RootStateMachine) of the referenced Blueprint.\n */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "State machines contain states and transitions. When a transition succeeds the current state advances to the next.\nFSMStateMachine is also considered a state since it inherits from FSMState_Base, making it possible to nest state machines.\n\nWhen configured as a reference this will defer handling to the SMInstance (or in some cases the RootStateMachine) of the referenced Blueprint." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMStateMachine>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic_MetaData[] = {
		{ "Comment", "/** If this has additional logic associated with it. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "If this has additional logic associated with it." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bHasAdditionalLogic = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic = { "bHasAdditionalLogic", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState_MetaData[] = {
		{ "Comment", "/** The current state is not cleared on end and will be resumed on start. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "The current state is not cleared on end and will be resumed on start." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bReuseCurrentState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState = { "bReuseCurrentState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState_MetaData[] = {
		{ "Comment", "/** Don't reuse if the state machine is in an end state. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "Don't reuse if the state machine is in an end state." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bOnlyReuseIfNotEndState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState = { "bOnlyReuseIfNotEndState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick_MetaData[] = {
		{ "Comment", "/** Allows the state machine reference to tick on its own. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "Allows the state machine reference to tick on its own." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bAllowIndependentTick = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick = { "bAllowIndependentTick", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate_MetaData[] = {
		{ "Comment", "/** Notifies instance to call tick on manual update. Only valid for references. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "Notifies instance to call tick on manual update. Only valid for references." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bCallReferenceTickOnManualUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate = { "bCallReferenceTickOnManualUpdate", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState_MetaData[] = {
		{ "Comment", "/** Wait for an end state to be hit before evaluating transitions or being considered an end state itself. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "Wait for an end state to be hit before evaluating transitions or being considered an end state itself." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState_SetBit(void* Obj)
	{
		((FSMStateMachine*)Obj)->bWaitForEndState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState = { "bWaitForEndState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMStateMachine), &Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator_Inner = { "BeginStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator = { "BeginStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, BeginStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator_Inner = { "UpdateStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator = { "UpdateStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, UpdateStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator_Inner = { "EndStateGraphEvaluator", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMExposedFunctionHandler, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator = { "EndStateGraphEvaluator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, EndStateGraphEvaluator), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_NetworkedInterface_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
	};
#endif
	const UE4CodeGen_Private::FInterfacePropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_NetworkedInterface = { "NetworkedInterface", nullptr, (EPropertyFlags)0x0044000000000000, UE4CodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, NetworkedInterface), Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_NetworkedInterface_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_NetworkedInterface_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachineClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachineClass = { "ReferencedStateMachineClass", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, ReferencedStateMachineClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachineClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachineClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedTemplateName_MetaData[] = {
		{ "Comment", "/** The name of a template archetype to use when constructing a reference. This allows default values be passed into the reference. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "The name of a template archetype to use when constructing a reference. This allows default values be passed into the reference." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedTemplateName = { "ReferencedTemplateName", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, ReferencedTemplateName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedTemplateName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedTemplateName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_DynamicStateMachineReferenceVariable_MetaData[] = {
		{ "Comment", "/** The name of a variable stored on the owning SMInstance that should be used to find the class for this reference. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "The name of a variable stored on the owning SMInstance that should be used to find the class for this reference." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_DynamicStateMachineReferenceVariable = { "DynamicStateMachineReferenceVariable", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, DynamicStateMachineReferenceVariable), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_DynamicStateMachineReferenceVariable_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_DynamicStateMachineReferenceVariable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachine_MetaData[] = {
		{ "Comment", "/** This state machine is referencing an instance. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "This state machine is referencing an instance." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachine = { "ReferencedStateMachine", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, ReferencedStateMachine), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachine_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachine_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_IsReferencedByInstance_MetaData[] = {
		{ "Comment", "/** This state machine is being referenced from an instance. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateMachine.h" },
		{ "ToolTip", "This state machine is being referenced from an instance." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_IsReferencedByInstance = { "IsReferencedByInstance", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMStateMachine, IsReferencedByInstance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_IsReferencedByInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_IsReferencedByInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMStateMachine_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bHasAdditionalLogic,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bReuseCurrentState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bOnlyReuseIfNotEndState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bAllowIndependentTick,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bCallReferenceTickOnManualUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_bWaitForEndState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_BeginStateGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_UpdateStateGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_EndStateGraphEvaluator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_NetworkedInterface,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachineClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedTemplateName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_DynamicStateMachineReferenceVariable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_ReferencedStateMachine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMStateMachine_Statics::NewProp_IsReferencedByInstance,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMStateMachine_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMState_Base,
		&NewStructOps,
		"SMStateMachine",
		sizeof(FSMStateMachine),
		alignof(FSMStateMachine),
		Z_Construct_UScriptStruct_FSMStateMachine_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMStateMachine_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMStateMachine_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMStateMachine()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMStateMachine_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMStateMachine"), sizeof(FSMStateMachine), Get_Z_Construct_UScriptStruct_FSMStateMachine_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMStateMachine_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMStateMachine_Hash() { return 1448468428U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
