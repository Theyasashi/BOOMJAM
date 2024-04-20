// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/Transitions/SMTransitionInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMTransitionInstance() {}
// Cross Module References
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMTransitionInfo();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnTransitionEnteredSignature_Parms
		{
			USMTransitionInstance* TransitionInstance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TransitionInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::NewProp_TransitionInstance = { "TransitionInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnTransitionEnteredSignature_Parms, TransitionInstance), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::NewProp_TransitionInstance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnTransitionEnteredSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnTransitionEnteredSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execSetCanEvalWithStartState)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanEvalWithStartState(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetCanEvalWithStartState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetCanEvalWithStartState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execSetCanEvaluateFromEvent)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanEvaluateFromEvent(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetCanEvaluateFromEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetCanEvaluateFromEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execSetPriorityOrder)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPriorityOrder(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetPriorityOrder)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetPriorityOrder();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetCanEvaluate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetCanEvaluate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execSetCanEvaluate)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanEvaluate(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execEvaluateFromManuallyBoundEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EvaluateFromManuallyBoundEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execIsTransitionFromAnyState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsTransitionFromAnyState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execDoesTransitionPass)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->DoesTransitionPass();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetServerTimestamp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetServerTimestamp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetTransitionInfo)
	{
		P_GET_STRUCT_REF(FSMTransitionInfo,Z_Param_Out_Transition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetTransitionInfo(Z_Param_Out_Transition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetDestinationStateForActiveTransition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetDestinationStateForActiveTransition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetSourceStateForActiveTransition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetSourceStateForActiveTransition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetNextStateInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetNextStateInstance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMTransitionInstance::execGetPreviousStateInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetPreviousStateInstance();
		P_NATIVE_END;
	}
	void USMTransitionInstance::StaticRegisterNativesUSMTransitionInstance()
	{
		UClass* Class = USMTransitionInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DoesTransitionPass", &USMTransitionInstance::execDoesTransitionPass },
			{ "EvaluateFromManuallyBoundEvent", &USMTransitionInstance::execEvaluateFromManuallyBoundEvent },
			{ "GetCanEvaluate", &USMTransitionInstance::execGetCanEvaluate },
			{ "GetCanEvaluateFromEvent", &USMTransitionInstance::execGetCanEvaluateFromEvent },
			{ "GetCanEvalWithStartState", &USMTransitionInstance::execGetCanEvalWithStartState },
			{ "GetDestinationStateForActiveTransition", &USMTransitionInstance::execGetDestinationStateForActiveTransition },
			{ "GetNextStateInstance", &USMTransitionInstance::execGetNextStateInstance },
			{ "GetPreviousStateInstance", &USMTransitionInstance::execGetPreviousStateInstance },
			{ "GetPriorityOrder", &USMTransitionInstance::execGetPriorityOrder },
			{ "GetServerTimestamp", &USMTransitionInstance::execGetServerTimestamp },
			{ "GetSourceStateForActiveTransition", &USMTransitionInstance::execGetSourceStateForActiveTransition },
			{ "GetTransitionInfo", &USMTransitionInstance::execGetTransitionInfo },
			{ "IsTransitionFromAnyState", &USMTransitionInstance::execIsTransitionFromAnyState },
			{ "SetCanEvaluate", &USMTransitionInstance::execSetCanEvaluate },
			{ "SetCanEvaluateFromEvent", &USMTransitionInstance::execSetCanEvaluateFromEvent },
			{ "SetCanEvalWithStartState", &USMTransitionInstance::execSetCanEvalWithStartState },
			{ "SetPriorityOrder", &USMTransitionInstance::execSetPriorityOrder },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics
	{
		struct SMTransitionInstance_eventDoesTransitionPass_Parms
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
	void Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventDoesTransitionPass_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventDoesTransitionPass_Parms), &Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Evaluates the transition's local graph which usually calls #CanEnterTransition of this instance.\n\x09 * This is equivalent to the state machine determining if a transition succeeds.\n\x09 *\n\x09 * This is best used from an external caller when checking a transition result.\n\x09 *\n\x09 * Do NOT call this from within CanEnterTransition of the instance or the local graph\n\x09 * or you may trigger an infinite loop.\n\x09 *\n\x09 * @return The transition result.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Evaluates the transition's local graph which usually calls #CanEnterTransition of this instance.\nThis is equivalent to the state machine determining if a transition succeeds.\n\nThis is best used from an external caller when checking a transition result.\n\nDo NOT call this from within CanEnterTransition of the instance or the local graph\nor you may trigger an infinite loop.\n\n@return The transition result." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "DoesTransitionPass", nullptr, nullptr, sizeof(SMTransitionInstance_eventDoesTransitionPass_Parms), Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Efficiently evaluate and take the transition immediately.\n\x09 * If the transition's CanEnterTransition method returns true the entire transition\n\x09 * chain this transition is part of will be evaluated and taken. Super state and parallel transitions\n\x09 * will not evaluate when this method is called.\n\x09 *\n\x09 * Steps this method performs:\n\x09 * 1. Enables SetCanEvaluate for this transition.\n\x09 * 2. Calls EvaluateAndTakeTransitionChain from the owning state machine instance.\n\x09 * 3. Sets SetCanEvaluate back to the original value.\n\x09 * \n\x09 * Use at the end of execution from manually bound events.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Efficiently evaluate and take the transition immediately.\nIf the transition's CanEnterTransition method returns true the entire transition\nchain this transition is part of will be evaluated and taken. Super state and parallel transitions\nwill not evaluate when this method is called.\n\nSteps this method performs:\n1. Enables SetCanEvaluate for this transition.\n2. Calls EvaluateAndTakeTransitionChain from the owning state machine instance.\n3. Sets SetCanEvaluate back to the original value.\n\nUse at the end of execution from manually bound events." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "EvaluateFromManuallyBoundEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics
	{
		struct SMTransitionInstance_eventGetCanEvaluate_Parms
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
	void Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventGetCanEvaluate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventGetCanEvaluate_Parms), &Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Check whether this transition is allowed to evaluate. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Check whether this transition is allowed to evaluate." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetCanEvaluate", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetCanEvaluate_Parms), Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics
	{
		struct SMTransitionInstance_eventGetCanEvaluateFromEvent_Parms
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
	void Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventGetCanEvaluateFromEvent_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventGetCanEvaluateFromEvent_Parms), &Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bCanEvaluateFromEvent. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public getter for #bCanEvaluateFromEvent." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetCanEvaluateFromEvent", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetCanEvaluateFromEvent_Parms), Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics
	{
		struct SMTransitionInstance_eventGetCanEvalWithStartState_Parms
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
	void Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventGetCanEvalWithStartState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventGetCanEvalWithStartState_Parms), &Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bCanEvalWithStartState. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public getter for #bCanEvalWithStartState." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetCanEvalWithStartState", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetCanEvalWithStartState_Parms), Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics
	{
		struct SMTransitionInstance_eventGetDestinationStateForActiveTransition_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetDestinationStateForActiveTransition_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09* Return the destination state we are transitioning to or last transitioned to.\n\x09* This may be a state after a transition conduit.\n\x09* This will be valid during OnTransitionEntered().\n\x09*\n\x09* @return The final state after the transition chain or null.\n\x09*/" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Return the destination state we are transitioning to or last transitioned to.\nThis may be a state after a transition conduit.\nThis will be valid during OnTransitionEntered().\n\n@return The final state after the transition chain or null." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetDestinationStateForActiveTransition", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetDestinationStateForActiveTransition_Parms), Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics
	{
		struct SMTransitionInstance_eventGetNextStateInstance_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetNextStateInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The state this transition leads to. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "The state this transition leads to." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetNextStateInstance", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetNextStateInstance_Parms), Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics
	{
		struct SMTransitionInstance_eventGetPreviousStateInstance_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetPreviousStateInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The state this transition leaves from. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "The state this transition leaves from." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetPreviousStateInstance", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetPreviousStateInstance_Parms), Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics
	{
		struct SMTransitionInstance_eventGetPriorityOrder_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetPriorityOrder_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #PriorityOrder. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public getter for #PriorityOrder." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetPriorityOrder", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetPriorityOrder_Parms), Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics
	{
		struct SMTransitionInstance_eventGetServerTimestamp_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetServerTimestamp_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Return the last server timestamp of this transition. If not networked this won't be set. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Return the last server timestamp of this transition. If not networked this won't be set." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetServerTimestamp", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetServerTimestamp_Parms), Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics
	{
		struct SMTransitionInstance_eventGetSourceStateForActiveTransition_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetSourceStateForActiveTransition_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09* Return the state that last triggered this transition.\n\x09* This may be a state prior to a transition conduit.\n\x09* This will be valid during OnTransitionEntered().\n\x09*\n\x09* @return The first state to trigger this transition chain or null.\n\x09*/" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Return the state that last triggered this transition.\nThis may be a state prior to a transition conduit.\nThis will be valid during OnTransitionEntered().\n\n@return The first state to trigger this transition chain or null." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetSourceStateForActiveTransition", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetSourceStateForActiveTransition_Parms), Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics
	{
		struct SMTransitionInstance_eventGetTransitionInfo_Parms
		{
			FSMTransitionInfo Transition;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transition;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::NewProp_Transition = { "Transition", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventGetTransitionInfo_Parms, Transition), Z_Construct_UScriptStruct_FSMTransitionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::NewProp_Transition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Return read only information about the owning transition. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Return read only information about the owning transition." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "GetTransitionInfo", nullptr, nullptr, sizeof(SMTransitionInstance_eventGetTransitionInfo_Parms), Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics
	{
		struct SMTransitionInstance_eventIsTransitionFromAnyState_Parms
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
	void Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventIsTransitionFromAnyState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventIsTransitionFromAnyState_Parms), &Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * If the transition was created by an Any State.\n\x09 * @return True if the transition was copied from an Any State.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "If the transition was created by an Any State.\n@return True if the transition was copied from an Any State." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "IsTransitionFromAnyState", nullptr, nullptr, sizeof(SMTransitionInstance_eventIsTransitionFromAnyState_Parms), Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics
	{
		struct SMTransitionInstance_eventSetCanEvaluate_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventSetCanEvaluate_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventSetCanEvaluate_Parms), &Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Sets whether this node is allowed to evaluate or not. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Sets whether this node is allowed to evaluate or not." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "SetCanEvaluate", nullptr, nullptr, sizeof(SMTransitionInstance_eventSetCanEvaluate_Parms), Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics
	{
		struct SMTransitionInstance_eventSetCanEvaluateFromEvent_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventSetCanEvaluateFromEvent_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventSetCanEvaluateFromEvent_Parms), &Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bCanEvaluateFromEvent. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public setter for #bCanEvaluateFromEvent." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "SetCanEvaluateFromEvent", nullptr, nullptr, sizeof(SMTransitionInstance_eventSetCanEvaluateFromEvent_Parms), Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics
	{
		struct SMTransitionInstance_eventSetCanEvalWithStartState_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMTransitionInstance_eventSetCanEvalWithStartState_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMTransitionInstance_eventSetCanEvalWithStartState_Parms), &Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bCanEvalWithStartState. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public setter for #bCanEvalWithStartState." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "SetCanEvalWithStartState", nullptr, nullptr, sizeof(SMTransitionInstance_eventSetCanEvalWithStartState_Parms), Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics
	{
		struct SMTransitionInstance_eventSetPriorityOrder_Parms
		{
			int32 Value;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMTransitionInstance_eventSetPriorityOrder_Parms, Value), METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::NewProp_Value_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::NewProp_Value_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/**\n\x09 * Public setter for #PriorityOrder.\n\x09 * Only valid from the editor construction script.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Public setter for #PriorityOrder.\nOnly valid from the editor construction script." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMTransitionInstance, nullptr, "SetPriorityOrder", nullptr, nullptr, sizeof(SMTransitionInstance_eventSetPriorityOrder_Parms), Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USMTransitionInstance_NoRegister()
	{
		return USMTransitionInstance::StaticClass();
	}
	struct Z_Construct_UClass_USMTransitionInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PriorityOrder_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_PriorityOrder;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnTransitionEnteredEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTransitionEnteredEvent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMTransitionInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMNodeInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USMTransitionInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USMTransitionInstance_DoesTransitionPass, "DoesTransitionPass" }, // 897518631
		{ &Z_Construct_UFunction_USMTransitionInstance_EvaluateFromManuallyBoundEvent, "EvaluateFromManuallyBoundEvent" }, // 1809604700
		{ &Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluate, "GetCanEvaluate" }, // 1988844674
		{ &Z_Construct_UFunction_USMTransitionInstance_GetCanEvaluateFromEvent, "GetCanEvaluateFromEvent" }, // 2454142442
		{ &Z_Construct_UFunction_USMTransitionInstance_GetCanEvalWithStartState, "GetCanEvalWithStartState" }, // 2303832878
		{ &Z_Construct_UFunction_USMTransitionInstance_GetDestinationStateForActiveTransition, "GetDestinationStateForActiveTransition" }, // 3634312258
		{ &Z_Construct_UFunction_USMTransitionInstance_GetNextStateInstance, "GetNextStateInstance" }, // 3292845094
		{ &Z_Construct_UFunction_USMTransitionInstance_GetPreviousStateInstance, "GetPreviousStateInstance" }, // 43124926
		{ &Z_Construct_UFunction_USMTransitionInstance_GetPriorityOrder, "GetPriorityOrder" }, // 793082204
		{ &Z_Construct_UFunction_USMTransitionInstance_GetServerTimestamp, "GetServerTimestamp" }, // 3208590456
		{ &Z_Construct_UFunction_USMTransitionInstance_GetSourceStateForActiveTransition, "GetSourceStateForActiveTransition" }, // 595063986
		{ &Z_Construct_UFunction_USMTransitionInstance_GetTransitionInfo, "GetTransitionInfo" }, // 1672147715
		{ &Z_Construct_UFunction_USMTransitionInstance_IsTransitionFromAnyState, "IsTransitionFromAnyState" }, // 1907448285
		{ &Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluate, "SetCanEvaluate" }, // 224791205
		{ &Z_Construct_UFunction_USMTransitionInstance_SetCanEvaluateFromEvent, "SetCanEvaluateFromEvent" }, // 4077180623
		{ &Z_Construct_UFunction_USMTransitionInstance_SetCanEvalWithStartState, "SetCanEvalWithStartState" }, // 3122574271
		{ &Z_Construct_UFunction_USMTransitionInstance_SetPriorityOrder, "SetPriorityOrder" }, // 3607960751
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The base class for transition connections.\n */" },
		{ "DisplayName", "Transition Class" },
		{ "HideCategories", "SMTransitionInstance SMNodeInstance" },
		{ "IncludePath", "Nodes/Transitions/SMTransitionInstance.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "The base class for transition connections." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_PriorityOrder_MetaData[] = {
		{ "Category", "Transition" },
		{ "Comment", "/**\n\x09 * Lower number transitions will be evaluated first.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "Lower number transitions will be evaluated first." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_PriorityOrder = { "PriorityOrder", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMTransitionInstance, PriorityOrder), METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_PriorityOrder_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_PriorityOrder_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate_MetaData[] = {
		{ "Category", "Transition" },
		{ "Comment", "/**\n\x09 * If this transition is allowed to evaluate conditionally.\n\x09 */" },
		{ "DisplayName", "Can Evaluate Conditionally" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "If this transition is allowed to evaluate conditionally." },
	};
#endif
	void Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate_SetBit(void* Obj)
	{
		((USMTransitionInstance*)Obj)->bCanEvaluate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate = { "bCanEvaluate", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMTransitionInstance), &Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent_MetaData[] = {
		{ "Category", "Transition" },
		{ "Comment", "/** If this transition can evaluate from auto-bound events. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "ToolTip", "If this transition can evaluate from auto-bound events." },
	};
#endif
	void Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent_SetBit(void* Obj)
	{
		((USMTransitionInstance*)Obj)->bCanEvaluateFromEvent = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent = { "bCanEvaluateFromEvent", nullptr, (EPropertyFlags)0x0040040000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMTransitionInstance), &Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState_MetaData[] = {
		{ "Category", "Transition" },
		{ "Comment", "/**\n\x09 * Setting to false forces this transition to never evaluate on the same tick as Start State.\n\x09 * Only checked if this transition's from state has bEvalTransitionsOnStart set to true.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "NodeBaseOnly", "" },
		{ "NoResetToDefault", "" },
		{ "ToolTip", "Setting to false forces this transition to never evaluate on the same tick as Start State.\nOnly checked if this transition's from state has bEvalTransitionsOnStart set to true." },
	};
#endif
	void Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState_SetBit(void* Obj)
	{
		((USMTransitionInstance*)Obj)->bCanEvalWithStartState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState = { "bCanEvalWithStartState", nullptr, (EPropertyFlags)0x0040040000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMTransitionInstance), &Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_OnTransitionEnteredEvent_MetaData[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Called when this transition has been entered from the previous state. */" },
		{ "ModuleRelativePath", "Public/Nodes/Transitions/SMTransitionInstance.h" },
		{ "ToolTip", "Called when this transition has been entered from the previous state." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_OnTransitionEnteredEvent = { "OnTransitionEnteredEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMTransitionInstance, OnTransitionEnteredEvent), Z_Construct_UDelegateFunction_SMSystem_OnTransitionEnteredSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_OnTransitionEnteredEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_OnTransitionEnteredEvent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMTransitionInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_PriorityOrder,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvaluateFromEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_bCanEvalWithStartState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMTransitionInstance_Statics::NewProp_OnTransitionEnteredEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMTransitionInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMTransitionInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMTransitionInstance_Statics::ClassParams = {
		&USMTransitionInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USMTransitionInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMTransitionInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMTransitionInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMTransitionInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMTransitionInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMTransitionInstance, 1644324730);
	template<> SMSYSTEM_API UClass* StaticClass<USMTransitionInstance>()
	{
		return USMTransitionInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMTransitionInstance(Z_Construct_UClass_USMTransitionInstance, &USMTransitionInstance::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMTransitionInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMTransitionInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
