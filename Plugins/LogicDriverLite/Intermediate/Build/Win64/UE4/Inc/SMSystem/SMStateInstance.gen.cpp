// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/States/SMStateInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMStateInstance() {}
// Cross Module References
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base_NoRegister();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateInfo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateEndSignature_Parms
		{
			USMStateInstance_Base* StateInstance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::NewProp_StateInstance = { "StateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateEndSignature_Parms, StateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::NewProp_StateInstance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateEndSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateEndSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateUpdateSignature_Parms
		{
			USMStateInstance_Base* StateInstance;
			float DeltaSeconds;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateInstance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::NewProp_StateInstance = { "StateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateUpdateSignature_Parms, StateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateUpdateSignature_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::NewProp_StateInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateUpdateSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateUpdateSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateBeginSignature_Parms
		{
			USMStateInstance_Base* StateInstance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::NewProp_StateInstance = { "StateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateBeginSignature_Parms, StateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::NewProp_StateInstance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateBeginSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateBeginSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSetExcludeFromAnyState)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetExcludeFromAnyState(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetExcludeFromAnyState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetExcludeFromAnyState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSetEvalTransitionsOnStart)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEvalTransitionsOnStart(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetEvalTransitionsOnStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetEvalTransitionsOnStart();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSetDisableTickTransitionEvaluation)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDisableTickTransitionEvaluation(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetDisableTickTransitionEvaluation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetDisableTickTransitionEvaluation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSetAlwaysUpdate)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAlwaysUpdate(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetAlwaysUpdate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetAlwaysUpdate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetServerTimeInState)
	{
		P_GET_UBOOL_REF(Z_Param_Out_bOutUsedLocalTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetServerTimeInState(Z_Param_Out_bOutUsedLocalTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetStartTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetStartTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execAreAllIncomingTransitionsFromAnAnyState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AreAllIncomingTransitionsFromAnAnyState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execAreAllOutgoingTransitionsFromAnAnyState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AreAllOutgoingTransitionsFromAnAnyState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetPreviousActiveTransition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMTransitionInstance**)Z_Param__Result=P_THIS->GetPreviousActiveTransition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetPreviousActiveState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetPreviousActiveState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetPreviousStateByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_StateName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetPreviousStateByName(Z_Param_StateName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetNextStateByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_StateName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetNextStateByName(Z_Param_StateName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetNextStateByTransitionIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetNextStateByTransitionIndex(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetTransitionByIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMTransitionInstance**)Z_Param__Result=P_THIS->GetTransitionByIndex(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSwitchToLinkedStateByTransition)
	{
		P_GET_OBJECT(USMTransitionInstance,Z_Param_TransitionInstance);
		P_GET_UBOOL(Z_Param_bRequireTransitionToPass);
		P_GET_UBOOL(Z_Param_bActivateNow);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SwitchToLinkedStateByTransition(Z_Param_TransitionInstance,Z_Param_bRequireTransitionToPass,Z_Param_bActivateNow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSwitchToLinkedStateByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_NextStateName);
		P_GET_UBOOL(Z_Param_bRequireTransitionToPass);
		P_GET_UBOOL(Z_Param_bActivateNow);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SwitchToLinkedStateByName(Z_Param_NextStateName,Z_Param_bRequireTransitionToPass,Z_Param_bActivateNow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSwitchToLinkedState)
	{
		P_GET_OBJECT(USMStateInstance_Base,Z_Param_NextStateInstance);
		P_GET_UBOOL(Z_Param_bRequireTransitionToPass);
		P_GET_UBOOL(Z_Param_bActivateNow);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SwitchToLinkedState(Z_Param_NextStateInstance,Z_Param_bRequireTransitionToPass,Z_Param_bActivateNow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetTransitionToTake)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMTransitionInstance**)Z_Param__Result=P_THIS->GetTransitionToTake();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetIncomingTransitions)
	{
		P_GET_TARRAY_REF(USMTransitionInstance*,Z_Param_Out_Transitions);
		P_GET_UBOOL(Z_Param_bExcludeAlwaysFalse);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIncomingTransitions(Z_Param_Out_Transitions,Z_Param_bExcludeAlwaysFalse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetOutgoingTransitions)
	{
		P_GET_TARRAY_REF(USMTransitionInstance*,Z_Param_Out_Transitions);
		P_GET_UBOOL(Z_Param_bExcludeAlwaysFalse);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetOutgoingTransitions(Z_Param_Out_Transitions,Z_Param_bExcludeAlwaysFalse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execEvaluateTransitions)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EvaluateTransitions();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execSetActive)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_GET_UBOOL(Z_Param_bSetAllParents);
		P_GET_UBOOL(Z_Param_bActivateNow);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetActive(Z_Param_bValue,Z_Param_bSetAllParents,Z_Param_bActivateNow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execIsEntryState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsEntryState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execIsStateMachine)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsStateMachine();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMStateInstance_Base::execGetStateInfo)
	{
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetStateInfo(Z_Param_Out_State);
		P_NATIVE_END;
	}
	void USMStateInstance_Base::StaticRegisterNativesUSMStateInstance_Base()
	{
		UClass* Class = USMStateInstance_Base::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AreAllIncomingTransitionsFromAnAnyState", &USMStateInstance_Base::execAreAllIncomingTransitionsFromAnAnyState },
			{ "AreAllOutgoingTransitionsFromAnAnyState", &USMStateInstance_Base::execAreAllOutgoingTransitionsFromAnAnyState },
			{ "EvaluateTransitions", &USMStateInstance_Base::execEvaluateTransitions },
			{ "GetAlwaysUpdate", &USMStateInstance_Base::execGetAlwaysUpdate },
			{ "GetDisableTickTransitionEvaluation", &USMStateInstance_Base::execGetDisableTickTransitionEvaluation },
			{ "GetEvalTransitionsOnStart", &USMStateInstance_Base::execGetEvalTransitionsOnStart },
			{ "GetExcludeFromAnyState", &USMStateInstance_Base::execGetExcludeFromAnyState },
			{ "GetIncomingTransitions", &USMStateInstance_Base::execGetIncomingTransitions },
			{ "GetNextStateByName", &USMStateInstance_Base::execGetNextStateByName },
			{ "GetNextStateByTransitionIndex", &USMStateInstance_Base::execGetNextStateByTransitionIndex },
			{ "GetOutgoingTransitions", &USMStateInstance_Base::execGetOutgoingTransitions },
			{ "GetPreviousActiveState", &USMStateInstance_Base::execGetPreviousActiveState },
			{ "GetPreviousActiveTransition", &USMStateInstance_Base::execGetPreviousActiveTransition },
			{ "GetPreviousStateByName", &USMStateInstance_Base::execGetPreviousStateByName },
			{ "GetServerTimeInState", &USMStateInstance_Base::execGetServerTimeInState },
			{ "GetStartTime", &USMStateInstance_Base::execGetStartTime },
			{ "GetStateInfo", &USMStateInstance_Base::execGetStateInfo },
			{ "GetTransitionByIndex", &USMStateInstance_Base::execGetTransitionByIndex },
			{ "GetTransitionToTake", &USMStateInstance_Base::execGetTransitionToTake },
			{ "IsEntryState", &USMStateInstance_Base::execIsEntryState },
			{ "IsStateMachine", &USMStateInstance_Base::execIsStateMachine },
			{ "SetActive", &USMStateInstance_Base::execSetActive },
			{ "SetAlwaysUpdate", &USMStateInstance_Base::execSetAlwaysUpdate },
			{ "SetDisableTickTransitionEvaluation", &USMStateInstance_Base::execSetDisableTickTransitionEvaluation },
			{ "SetEvalTransitionsOnStart", &USMStateInstance_Base::execSetEvalTransitionsOnStart },
			{ "SetExcludeFromAnyState", &USMStateInstance_Base::execSetExcludeFromAnyState },
			{ "SwitchToLinkedState", &USMStateInstance_Base::execSwitchToLinkedState },
			{ "SwitchToLinkedStateByName", &USMStateInstance_Base::execSwitchToLinkedStateByName },
			{ "SwitchToLinkedStateByTransition", &USMStateInstance_Base::execSwitchToLinkedStateByTransition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics
	{
		struct SMStateInstance_Base_eventAreAllIncomingTransitionsFromAnAnyState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventAreAllIncomingTransitionsFromAnAnyState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventAreAllIncomingTransitionsFromAnAnyState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Checks if every incoming transition was created by an Any State. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Checks if every incoming transition was created by an Any State." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "AreAllIncomingTransitionsFromAnAnyState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventAreAllIncomingTransitionsFromAnAnyState_Parms), Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics
	{
		struct SMStateInstance_Base_eventAreAllOutgoingTransitionsFromAnAnyState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventAreAllOutgoingTransitionsFromAnAnyState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventAreAllOutgoingTransitionsFromAnAnyState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Checks if every outgoing transition was created by an Any State. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Checks if every outgoing transition was created by an Any State." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "AreAllOutgoingTransitionsFromAnAnyState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventAreAllOutgoingTransitionsFromAnAnyState_Parms), Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Signals to the owning state machine to process transition evaluation.\n\x09 * This is similar to calling Update on the owner root state machine, however state update logic (Tick) won't execute.\n\x09 * All transitions are evaluated as normal starting from the root state machine down.\n\x09 * Depending on super state transitions it's possible the state machine this state is part of may exit.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Signals to the owning state machine to process transition evaluation.\nThis is similar to calling Update on the owner root state machine, however state update logic (Tick) won't execute.\nAll transitions are evaluated as normal starting from the root state machine down.\nDepending on super state transitions it's possible the state machine this state is part of may exit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "EvaluateTransitions", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics
	{
		struct SMStateInstance_Base_eventGetAlwaysUpdate_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetAlwaysUpdate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetAlwaysUpdate_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bAlwaysUpdate. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public getter for #bAlwaysUpdate." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetAlwaysUpdate", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetAlwaysUpdate_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics
	{
		struct SMStateInstance_Base_eventGetDisableTickTransitionEvaluation_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetDisableTickTransitionEvaluation_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetDisableTickTransitionEvaluation_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bDisableTickTransitionEvaluation. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public getter for #bDisableTickTransitionEvaluation." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetDisableTickTransitionEvaluation", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetDisableTickTransitionEvaluation_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics
	{
		struct SMStateInstance_Base_eventGetEvalTransitionsOnStart_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetEvalTransitionsOnStart_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetEvalTransitionsOnStart_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bEvalTransitionsOnStart. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public setter for #bEvalTransitionsOnStart." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetEvalTransitionsOnStart", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetEvalTransitionsOnStart_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics
	{
		struct SMStateInstance_Base_eventGetExcludeFromAnyState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetExcludeFromAnyState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetExcludeFromAnyState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bExcludeFromAnyState. Only valid for the editor. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public getter for #bExcludeFromAnyState. Only valid for the editor." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetExcludeFromAnyState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetExcludeFromAnyState_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics
	{
		struct SMStateInstance_Base_eventGetIncomingTransitions_Parms
		{
			TArray<USMTransitionInstance*> Transitions;
			bool bExcludeAlwaysFalse;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Transitions_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Transitions;
		static void NewProp_bExcludeAlwaysFalse_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeAlwaysFalse;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_Transitions_Inner = { "Transitions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_Transitions = { "Transitions", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetIncomingTransitions_Parms, Transitions), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_bExcludeAlwaysFalse_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetIncomingTransitions_Parms*)Obj)->bExcludeAlwaysFalse = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_bExcludeAlwaysFalse = { "bExcludeAlwaysFalse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetIncomingTransitions_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_bExcludeAlwaysFalse_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetIncomingTransitions_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetIncomingTransitions_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_Transitions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_Transitions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_bExcludeAlwaysFalse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return all incoming transition instances.\n\x09 * @param Transitions The incoming transitions.\n\x09 * @param bExcludeAlwaysFalse Skip over transitions that can't ever be true.\n\x09 * @return True if any transitions exist.\n\x09 */" },
		{ "CPP_Default_bExcludeAlwaysFalse", "true" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return all incoming transition instances.\n@param Transitions The incoming transitions.\n@param bExcludeAlwaysFalse Skip over transitions that can't ever be true.\n@return True if any transitions exist." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetIncomingTransitions", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetIncomingTransitions_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics
	{
		struct SMStateInstance_Base_eventGetNextStateByName_Parms
		{
			FString StateName;
			USMStateInstance_Base* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_StateName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_StateName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_StateName = { "StateName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetNextStateByName_Parms, StateName), METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_StateName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_StateName_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetNextStateByName_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_StateName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return the next state connected by an outgoing transition.\n\x09 * O(n) by number of transitions.\n\x09 * @param StateName Name of the state to search for.\n\x09 *\n\x09 * @return The connected state or nullptr.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return the next state connected by an outgoing transition.\nO(n) by number of transitions.\n@param StateName Name of the state to search for.\n\n@return The connected state or nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetNextStateByName", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetNextStateByName_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics
	{
		struct SMStateInstance_Base_eventGetNextStateByTransitionIndex_Parms
		{
			int32 Index;
			USMStateInstance_Base* ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetNextStateByTransitionIndex_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetNextStateByTransitionIndex_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return the next connected state given a transition index.\n\x09 * @param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.\n\x09 *\n\x09 * @return The connected state or nullptr.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return the next connected state given a transition index.\n@param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.\n\n@return The connected state or nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetNextStateByTransitionIndex", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetNextStateByTransitionIndex_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics
	{
		struct SMStateInstance_Base_eventGetOutgoingTransitions_Parms
		{
			TArray<USMTransitionInstance*> Transitions;
			bool bExcludeAlwaysFalse;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Transitions_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Transitions;
		static void NewProp_bExcludeAlwaysFalse_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExcludeAlwaysFalse;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_Transitions_Inner = { "Transitions", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_Transitions = { "Transitions", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetOutgoingTransitions_Parms, Transitions), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_bExcludeAlwaysFalse_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetOutgoingTransitions_Parms*)Obj)->bExcludeAlwaysFalse = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_bExcludeAlwaysFalse = { "bExcludeAlwaysFalse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetOutgoingTransitions_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_bExcludeAlwaysFalse_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetOutgoingTransitions_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetOutgoingTransitions_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_Transitions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_Transitions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_bExcludeAlwaysFalse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return all outgoing transition instances.\n\x09 * @param Transitions The outgoing transitions.\n\x09 * @param bExcludeAlwaysFalse Skip over transitions that can't ever be true.\n\x09 * @return True if any transitions exist.\n\x09 */" },
		{ "CPP_Default_bExcludeAlwaysFalse", "true" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return all outgoing transition instances.\n@param Transitions The outgoing transitions.\n@param bExcludeAlwaysFalse Skip over transitions that can't ever be true.\n@return True if any transitions exist." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetOutgoingTransitions", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetOutgoingTransitions_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics
	{
		struct SMStateInstance_Base_eventGetPreviousActiveState_Parms
		{
			USMStateInstance_Base* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetPreviousActiveState_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Retrieve the last active state that transitioned to this state.\n\x09 * This will not count transition conduits.\n\x09 *\n\x09 * @return The state instance last active before this state became active. May be nullptr.\n\x09 * \n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Retrieve the last active state that transitioned to this state.\nThis will not count transition conduits.\n\n@return The state instance last active before this state became active. May be nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetPreviousActiveState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetPreviousActiveState_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics
	{
		struct SMStateInstance_Base_eventGetPreviousActiveTransition_Parms
		{
			USMTransitionInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetPreviousActiveTransition_Parms, ReturnValue), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Retrieve the last transition taken to this state.\n\x09 *\n\x09 * @return The transition instance last active before this state became active. May be nullptr.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Retrieve the last transition taken to this state.\n\n@return The transition instance last active before this state became active. May be nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetPreviousActiveTransition", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetPreviousActiveTransition_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics
	{
		struct SMStateInstance_Base_eventGetPreviousStateByName_Parms
		{
			FString StateName;
			USMStateInstance_Base* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_StateName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_StateName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_StateName = { "StateName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetPreviousStateByName_Parms, StateName), METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_StateName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_StateName_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetPreviousStateByName_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_StateName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return a previous state connected through an incoming transition.\n\x09 * O(n) by number of transitions.\n\x09 * @param StateName Name of the state to search for.\n\x09 *\n\x09 * @return The connected state or nullptr.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return a previous state connected through an incoming transition.\nO(n) by number of transitions.\n@param StateName Name of the state to search for.\n\n@return The connected state or nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetPreviousStateByName", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetPreviousStateByName_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics
	{
		struct SMStateInstance_Base_eventGetServerTimeInState_Parms
		{
			bool bOutUsedLocalTime;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOutUsedLocalTime_MetaData[];
#endif
		static void NewProp_bOutUsedLocalTime_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOutUsedLocalTime;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime_MetaData[] = {
		{ "DisplayName", "UsedLocalTime" },
	};
#endif
	void Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventGetServerTimeInState_Parms*)Obj)->bOutUsedLocalTime = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime = { "bOutUsedLocalTime", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventGetServerTimeInState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetServerTimeInState_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_bOutUsedLocalTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Retrieve the time the server spent in the state. This is retrieved from network transactions\n\x09 * and can match the TimeInState from the server.\n\x09 *\n\x09 * This will only match the server after OnStateEnd() is called and provided the client received the replicated\n\x09 * transition. When using client state change authority, `bWaitForTransactionsFromServer` must be set to true\n\x09 * for the client to receive the updated server time.\n\x09 *\n\x09 * When the server time can't be calculated the local time will be returned instead, using GetTimeInState().\n\x09 *\n\x09 * The return value is impacted by bCalculateServerTimeForClients of the state machine component's network settings,\n\x09 * and whether the state machine is networked, a client or server, or is ticking.\n\x09 *\n\x09 * @param bOutUsedLocalTime [Out] Indicates that local time from GetTimeInState() was used.\n\x09 * @return The total time spent in the state, either matching the server or the current local time spent.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Retrieve the time the server spent in the state. This is retrieved from network transactions\nand can match the TimeInState from the server.\n\nThis will only match the server after OnStateEnd() is called and provided the client received the replicated\ntransition. When using client state change authority, `bWaitForTransactionsFromServer` must be set to true\nfor the client to receive the updated server time.\n\nWhen the server time can't be calculated the local time will be returned instead, using GetTimeInState().\n\nThe return value is impacted by bCalculateServerTimeForClients of the state machine component's network settings,\nand whether the state machine is networked, a client or server, or is ticking.\n\n@param bOutUsedLocalTime [Out] Indicates that local time from GetTimeInState() was used.\n@return The total time spent in the state, either matching the server or the current local time spent." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetServerTimeInState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetServerTimeInState_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics
	{
		struct SMStateInstance_Base_eventGetStartTime_Parms
		{
			FDateTime ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetStartTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Retrieve the UTC time when the state last started. If this is called before the state has started once,\n\x09 * or before initialization (such as during an editor construction script) the datetime will be initialized to 0.\n\x09 *\n\x09 * @return DateTime in UTC. This is when the state started locally and won't be in sync with the server.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Retrieve the UTC time when the state last started. If this is called before the state has started once,\nor before initialization (such as during an editor construction script) the datetime will be initialized to 0.\n\n@return DateTime in UTC. This is when the state started locally and won't be in sync with the server." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetStartTime", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetStartTime_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetStartTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetStartTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics
	{
		struct SMStateInstance_Base_eventGetStateInfo_Parms
		{
			FSMStateInfo State;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetStateInfo_Parms, State), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Return read only information about the owning state. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return read only information about the owning state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetStateInfo", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetStateInfo_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics
	{
		struct SMStateInstance_Base_eventGetTransitionByIndex_Parms
		{
			int32 Index;
			USMTransitionInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetTransitionByIndex_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetTransitionByIndex_Parms, ReturnValue), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Return a transition given the transition index.\n\x09 * @param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.\n\x09 *\n\x09 * @return The transition or nullptr.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Return a transition given the transition index.\n@param Index The array index of the transition. If transitions have manual priorities they should correlate with the index value.\n\n@return The transition or nullptr." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetTransitionByIndex", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetTransitionByIndex_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics
	{
		struct SMStateInstance_Base_eventGetTransitionToTake_Parms
		{
			USMTransitionInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventGetTransitionToTake_Parms, ReturnValue), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The transition this state will be taking. Generally only valid on EndState and if this state isn't an end state. May be null. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "The transition this state will be taking. Generally only valid on EndState and if this state isn't an end state. May be null." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "GetTransitionToTake", nullptr, nullptr, sizeof(SMStateInstance_Base_eventGetTransitionToTake_Parms), Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics
	{
		struct SMStateInstance_Base_eventIsEntryState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventIsEntryState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventIsEntryState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** If this state is an entry state within a state machine. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "If this state is an entry state within a state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "IsEntryState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventIsEntryState_Parms), Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_IsEntryState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_IsEntryState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics
	{
		struct SMStateInstance_Base_eventIsStateMachine_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventIsStateMachine_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventIsStateMachine_Parms), &Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Checks if this state is a state machine. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Checks if this state is a state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "IsStateMachine", nullptr, nullptr, sizeof(SMStateInstance_Base_eventIsStateMachine_Parms), Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics
	{
		struct SMStateInstance_Base_eventSetActive_Parms
		{
			bool bValue;
			bool bSetAllParents;
			bool bActivateNow;
		};
		static void NewProp_bValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static void NewProp_bSetAllParents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSetAllParents;
		static void NewProp_bActivateNow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bActivateNow;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetActive_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetActive_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bSetAllParents_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetActive_Parms*)Obj)->bSetAllParents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bSetAllParents = { "bSetAllParents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetActive_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bSetAllParents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bActivateNow_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetActive_Parms*)Obj)->bActivateNow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bActivateNow = { "bActivateNow", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetActive_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bActivateNow_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bSetAllParents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::NewProp_bActivateNow,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Force set the active flag of this state. This call is replicated and can be called from the server or from a client.\n\x09 * The caller must have state change authority.\n\x09 *\n\x09 * When calling from a state, it should be done either OnStateBegin or OnStateUpdate. When calling from a transition\n\x09 * it should be done from OnTransitionEntered and limited to the previous state. If this is called from other\n\x09 * state or transition methods it may cause issues with the normal update cycle of a state machine.\n\x09 * \n\x09 * @param bValue True activates the state, false deactivates the state.\n\x09 * @param bSetAllParents Sets the active state of all super state machines. A parent state machine won't be deactivated unless there are no other states active.\n\x09 * @param bActivateNow If the state is becoming active it will fully activate and run OnStateBegin this tick. If this is false it will do so on the next update cycle.\n\x09 */" },
		{ "CPP_Default_bActivateNow", "true" },
		{ "CPP_Default_bSetAllParents", "false" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Force set the active flag of this state. This call is replicated and can be called from the server or from a client.\nThe caller must have state change authority.\n\nWhen calling from a state, it should be done either OnStateBegin or OnStateUpdate. When calling from a transition\nit should be done from OnTransitionEntered and limited to the previous state. If this is called from other\nstate or transition methods it may cause issues with the normal update cycle of a state machine.\n\n@param bValue True activates the state, false deactivates the state.\n@param bSetAllParents Sets the active state of all super state machines. A parent state machine won't be deactivated unless there are no other states active.\n@param bActivateNow If the state is becoming active it will fully activate and run OnStateBegin this tick. If this is false it will do so on the next update cycle." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SetActive", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSetActive_Parms), Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SetActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SetActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics
	{
		struct SMStateInstance_Base_eventSetAlwaysUpdate_Parms
		{
			bool bValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bValue_MetaData[];
#endif
		static void NewProp_bValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetAlwaysUpdate_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetAlwaysUpdate_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bAlwaysUpdate. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public setter for #bAlwaysUpdate." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SetAlwaysUpdate", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSetAlwaysUpdate_Parms), Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics
	{
		struct SMStateInstance_Base_eventSetDisableTickTransitionEvaluation_Parms
		{
			bool bValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bValue_MetaData[];
#endif
		static void NewProp_bValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetDisableTickTransitionEvaluation_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetDisableTickTransitionEvaluation_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bDisableTickTransitionEvaluation. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public setter for #bDisableTickTransitionEvaluation." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SetDisableTickTransitionEvaluation", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSetDisableTickTransitionEvaluation_Parms), Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics
	{
		struct SMStateInstance_Base_eventSetEvalTransitionsOnStart_Parms
		{
			bool bValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bValue_MetaData[];
#endif
		static void NewProp_bValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetEvalTransitionsOnStart_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetEvalTransitionsOnStart_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bEvalTransitionsOnStart. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public setter for #bEvalTransitionsOnStart." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SetEvalTransitionsOnStart", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSetEvalTransitionsOnStart_Parms), Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics
	{
		struct SMStateInstance_Base_eventSetExcludeFromAnyState_Parms
		{
			bool bValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bValue_MetaData[];
#endif
		static void NewProp_bValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSetExcludeFromAnyState_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSetExcludeFromAnyState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/**\n\x09 * Public setter for #bExcludeFromAnyState.\n\x09 * Only valid from the editor construction script.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Public setter for #bExcludeFromAnyState.\nOnly valid from the editor construction script." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SetExcludeFromAnyState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSetExcludeFromAnyState_Parms), Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics
	{
		struct SMStateInstance_Base_eventSwitchToLinkedState_Parms
		{
			USMStateInstance_Base* NextStateInstance;
			bool bRequireTransitionToPass;
			bool bActivateNow;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NextStateInstance;
		static void NewProp_bRequireTransitionToPass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireTransitionToPass;
		static void NewProp_bActivateNow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bActivateNow;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_NextStateInstance = { "NextStateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventSwitchToLinkedState_Parms, NextStateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bRequireTransitionToPass_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedState_Parms*)Obj)->bRequireTransitionToPass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bRequireTransitionToPass = { "bRequireTransitionToPass", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bRequireTransitionToPass_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bActivateNow_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedState_Parms*)Obj)->bActivateNow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bActivateNow = { "bActivateNow", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bActivateNow_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedState_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_NextStateInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bRequireTransitionToPass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_bActivateNow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\x09 *\n\x09 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\n\x09 * issues with the normal update cycle of a state machine.\n\x09 * \n\x09 * @param NextStateInstance The state node instance to switch to.\n\x09 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n\x09 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\x09 *\n\x09 * @return True if the active state was switched.\n\x09 */" },
		{ "CPP_Default_bActivateNow", "true" },
		{ "CPP_Default_bRequireTransitionToPass", "true" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\nThis should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\nissues with the normal update cycle of a state machine.\n\n@param NextStateInstance The state node instance to switch to.\n@param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n@param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\n@return True if the active state was switched." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SwitchToLinkedState", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSwitchToLinkedState_Parms), Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics
	{
		struct SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms
		{
			FString NextStateName;
			bool bRequireTransitionToPass;
			bool bActivateNow;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NextStateName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NextStateName;
		static void NewProp_bRequireTransitionToPass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireTransitionToPass;
		static void NewProp_bActivateNow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bActivateNow;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_NextStateName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_NextStateName = { "NextStateName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms, NextStateName), METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_NextStateName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_NextStateName_MetaData)) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bRequireTransitionToPass_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms*)Obj)->bRequireTransitionToPass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bRequireTransitionToPass = { "bRequireTransitionToPass", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bRequireTransitionToPass_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bActivateNow_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms*)Obj)->bActivateNow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bActivateNow = { "bActivateNow", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bActivateNow_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_NextStateName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bRequireTransitionToPass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_bActivateNow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\x09 *\n\x09 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\n\x09 * issues with the normal update cycle of a state machine.\n\x09 * \n\x09 * @param NextStateName The name of the state to switch to.\n\x09 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n\x09 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\x09 *\n\x09 * @return True if the active state was switched.\n\x09 */" },
		{ "CPP_Default_bActivateNow", "true" },
		{ "CPP_Default_bRequireTransitionToPass", "true" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\nThis should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\nissues with the normal update cycle of a state machine.\n\n@param NextStateName The name of the state to switch to.\n@param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n@param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\n@return True if the active state was switched." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SwitchToLinkedStateByName", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByName_Parms), Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics
	{
		struct SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms
		{
			USMTransitionInstance* TransitionInstance;
			bool bRequireTransitionToPass;
			bool bActivateNow;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TransitionInstance;
		static void NewProp_bRequireTransitionToPass_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireTransitionToPass;
		static void NewProp_bActivateNow_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bActivateNow;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_TransitionInstance = { "TransitionInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms, TransitionInstance), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bRequireTransitionToPass_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms*)Obj)->bRequireTransitionToPass = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bRequireTransitionToPass = { "bRequireTransitionToPass", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bRequireTransitionToPass_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bActivateNow_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms*)Obj)->bActivateNow = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bActivateNow = { "bActivateNow", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bActivateNow_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms), &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_TransitionInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bRequireTransitionToPass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_bActivateNow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\x09 *\n\x09 * This should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\n\x09 * issues with the normal update cycle of a state machine.\n\x09 * \n\x09 * @param TransitionInstance The transition which should be taken to the next state.\n\x09 * @param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n\x09 * @param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\x09 *\n\x09 * @return True if the active state was switched.\n\x09 */" },
		{ "CPP_Default_bActivateNow", "true" },
		{ "CPP_Default_bRequireTransitionToPass", "true" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Forcibly move to the next state providing this state is active and a transition is directly connecting the states.\n\nThis should be done either OnStateBegin or OnStateUpdate. If this is called from other state methods it may cause\nissues with the normal update cycle of a state machine.\n\n@param TransitionInstance The transition which should be taken to the next state.\n@param bRequireTransitionToPass Will evaluate the transition and only switch states if it passes.\n@param bActivateNow If the state switches the destination state will activate and run OnStateBegin this tick. Otherwise, it will do so in the next update cycle.\n\n@return True if the active state was switched." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMStateInstance_Base, nullptr, "SwitchToLinkedStateByTransition", nullptr, nullptr, sizeof(SMStateInstance_Base_eventSwitchToLinkedStateByTransition_Parms), Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USMStateInstance_Base_NoRegister()
	{
		return USMStateInstance_Base::StaticClass();
	}
	struct Z_Construct_UClass_USMStateInstance_Base_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NodeEndStateColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NodeEndStateColor;
#endif // WITH_EDITORONLY_DATA
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateBeginEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateBeginEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPostStateBeginEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPostStateBeginEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateUpdateEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateUpdateEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateEndEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateEndEvent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMStateInstance_Base_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMNodeInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USMStateInstance_Base_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USMStateInstance_Base_AreAllIncomingTransitionsFromAnAnyState, "AreAllIncomingTransitionsFromAnAnyState" }, // 1339928371
		{ &Z_Construct_UFunction_USMStateInstance_Base_AreAllOutgoingTransitionsFromAnAnyState, "AreAllOutgoingTransitionsFromAnAnyState" }, // 607248454
		{ &Z_Construct_UFunction_USMStateInstance_Base_EvaluateTransitions, "EvaluateTransitions" }, // 2716448595
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetAlwaysUpdate, "GetAlwaysUpdate" }, // 2469519245
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetDisableTickTransitionEvaluation, "GetDisableTickTransitionEvaluation" }, // 776889542
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetEvalTransitionsOnStart, "GetEvalTransitionsOnStart" }, // 883413381
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetExcludeFromAnyState, "GetExcludeFromAnyState" }, // 2679094276
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetIncomingTransitions, "GetIncomingTransitions" }, // 3924555540
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByName, "GetNextStateByName" }, // 1734701581
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetNextStateByTransitionIndex, "GetNextStateByTransitionIndex" }, // 3882039236
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetOutgoingTransitions, "GetOutgoingTransitions" }, // 1697055068
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveState, "GetPreviousActiveState" }, // 2862044617
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetPreviousActiveTransition, "GetPreviousActiveTransition" }, // 969211339
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetPreviousStateByName, "GetPreviousStateByName" }, // 114495713
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetServerTimeInState, "GetServerTimeInState" }, // 1712163407
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetStartTime, "GetStartTime" }, // 892459278
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetStateInfo, "GetStateInfo" }, // 3461840850
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetTransitionByIndex, "GetTransitionByIndex" }, // 2609230699
		{ &Z_Construct_UFunction_USMStateInstance_Base_GetTransitionToTake, "GetTransitionToTake" }, // 3205035428
		{ &Z_Construct_UFunction_USMStateInstance_Base_IsEntryState, "IsEntryState" }, // 3286908519
		{ &Z_Construct_UFunction_USMStateInstance_Base_IsStateMachine, "IsStateMachine" }, // 295450310
		{ &Z_Construct_UFunction_USMStateInstance_Base_SetActive, "SetActive" }, // 2517132751
		{ &Z_Construct_UFunction_USMStateInstance_Base_SetAlwaysUpdate, "SetAlwaysUpdate" }, // 2291168987
		{ &Z_Construct_UFunction_USMStateInstance_Base_SetDisableTickTransitionEvaluation, "SetDisableTickTransitionEvaluation" }, // 3018439498
		{ &Z_Construct_UFunction_USMStateInstance_Base_SetEvalTransitionsOnStart, "SetEvalTransitionsOnStart" }, // 385997031
		{ &Z_Construct_UFunction_USMStateInstance_Base_SetExcludeFromAnyState, "SetExcludeFromAnyState" }, // 2858886726
		{ &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedState, "SwitchToLinkedState" }, // 4193880814
		{ &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByName, "SwitchToLinkedStateByName" }, // 2043182747
		{ &Z_Construct_UFunction_USMStateInstance_Base_SwitchToLinkedStateByTransition, "SwitchToLinkedStateByTransition" }, // 3595528446
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The abstract base class for all state type nodes including state machine nodes and conduits.\n */" },
		{ "DisplayName", "State Class Base" },
		{ "HideCategories", "SMStateInstance_Base SMNodeInstance" },
		{ "IncludePath", "Nodes/States/SMStateInstance.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "The abstract base class for all state type nodes including state machine nodes and conduits." },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_NodeEndStateColor_MetaData[] = {
		{ "Comment", "/** The color this node should be when it is an end state. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "The color this node should be when it is an end state." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_NodeEndStateColor = { "NodeEndStateColor", nullptr, (EPropertyFlags)0x0020080800000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateInstance_Base, NodeEndStateColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_NodeEndStateColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_NodeEndStateColor_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate_MetaData[] = {
		{ "Category", "State" },
		{ "Comment", "/**\n\x09 * Always update the state at least once before ending.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "Always update the state at least once before ending." },
	};
#endif
	void Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate_SetBit(void* Obj)
	{
		((USMStateInstance_Base*)Obj)->bAlwaysUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate = { "bAlwaysUpdate", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMStateInstance_Base), &Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData[] = {
		{ "Category", "State" },
		{ "Comment", "/**\n\x09 * Prevents conditional transitions for this state from being evaluated on Tick.\n\x09 * This is good to use if the transitions leading out of the state are event based\n\x09 * or if you are manually calling EvaluateTransitions from a state instance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "Prevents conditional transitions for this state from being evaluated on Tick.\nThis is good to use if the transitions leading out of the state are event based\nor if you are manually calling EvaluateTransitions from a state instance." },
	};
#endif
	void Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit(void* Obj)
	{
		((USMStateInstance_Base*)Obj)->bDisableTickTransitionEvaluation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation = { "bDisableTickTransitionEvaluation", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMStateInstance_Base), &Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData[] = {
		{ "Category", "State" },
		{ "Comment", "/**\n\x09 * Allows transitions to be evaluated in the same tick as Start State.\n\x09 * Normally transitions are evaluated on the second tick.\n\x09 * This can be chained with other nodes that have this checked making it\n\x09   possible to evaluate multiple nodes and transitions in a single tick.\n\x09 \n\x09 * When using this consider performance implications and any potential\n\x09   infinite loops such as if you are using a self transition on this state.\n\n\x09 * Individual transitions can modify this behavior with bCanEvalWithStartState.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "Allows transitions to be evaluated in the same tick as Start State.\nNormally transitions are evaluated on the second tick.\nThis can be chained with other nodes that have this checked making it\n          possible to evaluate multiple nodes and transitions in a single tick.\n\nWhen using this consider performance implications and any potential\n          infinite loops such as if you are using a self transition on this state.\n\nIndividual transitions can modify this behavior with bCanEvalWithStartState." },
	};
#endif
	void Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart_SetBit(void* Obj)
	{
		((USMStateInstance_Base*)Obj)->bEvalTransitionsOnStart = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart = { "bEvalTransitionsOnStart", nullptr, (EPropertyFlags)0x0040040000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMStateInstance_Base), &Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState_MetaData[] = {
		{ "Category", "Any State" },
		{ "Comment", "/**\n\x09 * Prevents the `Any State` node from adding transitions to this node.\n\x09 * This can be useful for maintaining end states.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "Prevents the `Any State` node from adding transitions to this node.\nThis can be useful for maintaining end states." },
	};
#endif
	void Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState_SetBit(void* Obj)
	{
		((USMStateInstance_Base*)Obj)->bExcludeFromAnyState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState = { "bExcludeFromAnyState", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMStateInstance_Base), &Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateBeginEvent_MetaData[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Called right before the state has started. This is meant for an observer to be aware of when a state is about\n\x09 * to start. This will only be called for state stack instances if the state is allowed to execute logic.\n\x09 * Do not change states from within this event, the state change process will still be in progress.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Called right before the state has started. This is meant for an observer to be aware of when a state is about\nto start. This will only be called for state stack instances if the state is allowed to execute logic.\nDo not change states from within this event, the state change process will still be in progress." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateBeginEvent = { "OnStateBeginEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateInstance_Base, OnStateBeginEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateBeginEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateBeginEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnPostStateBeginEvent_MetaData[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Called right after the state has started. This is meant for an observer to be aware of when a state has started.\n\x09 * If you need to change states this event is safer to use, but ideally state changes should be managed by transitions\n\x09 * or from within the state.\n\x09 *\n\x09 * This will only be called for state stack instances if the state is allowed to execute logic, and will be called before\n\x09 * the primary instance's OnPostStateBeginEvent. It is not safe to change states from this event when broadcast from\n\x09 * a state stack instance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Called right after the state has started. This is meant for an observer to be aware of when a state has started.\nIf you need to change states this event is safer to use, but ideally state changes should be managed by transitions\nor from within the state.\n\nThis will only be called for state stack instances if the state is allowed to execute logic, and will be called before\nthe primary instance's OnPostStateBeginEvent. It is not safe to change states from this event when broadcast from\na state stack instance." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnPostStateBeginEvent = { "OnPostStateBeginEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateInstance_Base, OnPostStateBeginEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateBeginSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnPostStateBeginEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnPostStateBeginEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateUpdateEvent_MetaData[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Called before the state has updated. This is meant for an observer to be aware of when a state is updating\n\x09 * and it is not advised to switch states from this event.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Called before the state has updated. This is meant for an observer to be aware of when a state is updating\nand it is not advised to switch states from this event." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateUpdateEvent = { "OnStateUpdateEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateInstance_Base, OnStateUpdateEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateUpdateSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateUpdateEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateUpdateEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateEndEvent_MetaData[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Called before the state has ended. It is not advised to switch states during this event.\n\x09 * The state machine will already be in the process of switching states.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "Called before the state has ended. It is not advised to switch states during this event.\nThe state machine will already be in the process of switching states." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateEndEvent = { "OnStateEndEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMStateInstance_Base, OnStateEndEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateEndSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateEndEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateEndEvent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMStateInstance_Base_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_NodeEndStateColor,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bAlwaysUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bDisableTickTransitionEvaluation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bEvalTransitionsOnStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_bExcludeFromAnyState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateBeginEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnPostStateBeginEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateUpdateEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMStateInstance_Base_Statics::NewProp_OnStateEndEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMStateInstance_Base_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMStateInstance_Base>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMStateInstance_Base_Statics::ClassParams = {
		&USMStateInstance_Base::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USMStateInstance_Base_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Base_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Base_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMStateInstance_Base()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMStateInstance_Base_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMStateInstance_Base, 2380236871);
	template<> SMSYSTEM_API UClass* StaticClass<USMStateInstance_Base>()
	{
		return USMStateInstance_Base::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMStateInstance_Base(Z_Construct_UClass_USMStateInstance_Base, &USMStateInstance_Base::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMStateInstance_Base"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMStateInstance_Base);
	void USMStateInstance::StaticRegisterNativesUSMStateInstance()
	{
	}
	UClass* Z_Construct_UClass_USMStateInstance_NoRegister()
	{
		return USMStateInstance::StaticClass();
	}
	struct Z_Construct_UClass_USMStateInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMStateInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMStateInstance_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMStateInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The base class for state nodes. This is where most execution logic should be defined.\n */" },
		{ "DisplayName", "State Class" },
		{ "HideCategories", "SMStateInstance SMStateInstance_Base SMNodeInstance" },
		{ "IncludePath", "Nodes/States/SMStateInstance.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMStateInstance.h" },
		{ "ToolTip", "The base class for state nodes. This is where most execution logic should be defined." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMStateInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMStateInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMStateInstance_Statics::ClassParams = {
		&USMStateInstance::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMStateInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMStateInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMStateInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMStateInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMStateInstance, 2254861342);
	template<> SMSYSTEM_API UClass* StaticClass<USMStateInstance>()
	{
		return USMStateInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMStateInstance(Z_Construct_UClass_USMStateInstance, &USMStateInstance::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMStateInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMStateInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
