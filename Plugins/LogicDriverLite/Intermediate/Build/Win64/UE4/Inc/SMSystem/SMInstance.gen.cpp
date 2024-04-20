// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/SMInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMInstance() {}
// Cross Module References
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateInfo();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMTransitionInfo();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature();
	SMSYSTEM_API UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMReferenceContainer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMDebugStateMachine();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMTransitionInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineInstance_NoRegister();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateHistory();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMStateMachine();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineInterface_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstanceInterface_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineStateStartedSignature_Parms
		{
			USMInstance* Instance;
			FSMStateInfo State;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStateStartedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStateStartedSignature_Parms, State), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::NewProp_Instance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineStateStartedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineStateStartedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineStateChangedSignature_Parms
		{
			USMInstance* Instance;
			FSMStateInfo NewState;
			FSMStateInfo PreviousState;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewState;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PreviousState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStateChangedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStateChangedSignature_Parms, NewState), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState = { "PreviousState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStateChangedSignature_Parms, PreviousState), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_Instance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_NewState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineStateChangedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineStateChangedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineTransitionTakenSignature_Parms
		{
			USMInstance* Instance;
			FSMTransitionInfo Transition;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transition;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineTransitionTakenSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::NewProp_Transition = { "Transition", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineTransitionTakenSignature_Parms, Transition), Z_Construct_UScriptStruct_FSMTransitionInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::NewProp_Instance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::NewProp_Transition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineTransitionTakenSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineTransitionTakenSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineStoppedSignature_Parms
		{
			USMInstance* Instance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStoppedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::NewProp_Instance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineStoppedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineStoppedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineUpdatedSignature_Parms
		{
			USMInstance* Instance;
			float DeltaSeconds;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineUpdatedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineUpdatedSignature_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::NewProp_Instance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineUpdatedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineUpdatedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineStartedSignature_Parms
		{
			USMInstance* Instance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineStartedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::NewProp_Instance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineStartedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineStartedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics
	{
		struct _Script_SMSystem_eventOnStateMachineInitializedSignature_Parms
		{
			USMInstance* Instance;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Instance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SMSystem_eventOnStateMachineInitializedSignature_Parms, Instance), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::NewProp_Instance,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SMSystem, nullptr, "OnStateMachineInitializedSignature__DelegateSignature", nullptr, nullptr, sizeof(_Script_SMSystem_eventOnStateMachineInitializedSignature_Parms), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
class UScriptStruct* FSMReferenceContainer::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMReferenceContainer_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMReferenceContainer, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMReferenceContainer"), sizeof(FSMReferenceContainer), Get_Z_Construct_UScriptStruct_FSMReferenceContainer_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMReferenceContainer>()
{
	return FSMReferenceContainer::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMReferenceContainer(FSMReferenceContainer::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMReferenceContainer"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMReferenceContainer
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMReferenceContainer()
	{
		UScriptStruct::DeferCppStructOps<FSMReferenceContainer>(FName(TEXT("SMReferenceContainer")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMReferenceContainer;
	struct Z_Construct_UScriptStruct_FSMReferenceContainer_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Reference_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Reference;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMReferenceContainer>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_PathGuid_MetaData[] = {
		{ "IgnoreForMemberInitializationTest", "" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_PathGuid = { "PathGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMReferenceContainer, PathGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_PathGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_PathGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_Reference_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_Reference = { "Reference", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMReferenceContainer, Reference), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_Reference_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_Reference_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_PathGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::NewProp_Reference,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMReferenceContainer",
		sizeof(FSMReferenceContainer),
		alignof(FSMReferenceContainer),
		Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMReferenceContainer()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMReferenceContainer_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMReferenceContainer"), sizeof(FSMReferenceContainer), Get_Z_Construct_UScriptStruct_FSMReferenceContainer_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMReferenceContainer_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMReferenceContainer_Hash() { return 4048526305U; }
class UScriptStruct* FSMDebugStateMachine::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMDebugStateMachine_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMDebugStateMachine, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMDebugStateMachine"), sizeof(FSMDebugStateMachine), Get_Z_Construct_UScriptStruct_FSMDebugStateMachine_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMDebugStateMachine>()
{
	return FSMDebugStateMachine::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMDebugStateMachine(FSMDebugStateMachine::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMDebugStateMachine"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMDebugStateMachine
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMDebugStateMachine()
	{
		UScriptStruct::DeferCppStructOps<FSMDebugStateMachine>(FName(TEXT("SMDebugStateMachine")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMDebugStateMachine;
	struct Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMDebugStateMachine>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMDebugStateMachine",
		sizeof(FSMDebugStateMachine),
		alignof(FSMDebugStateMachine),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMDebugStateMachine()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMDebugStateMachine_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMDebugStateMachine"), sizeof(FSMDebugStateMachine), Get_Z_Construct_UScriptStruct_FSMDebugStateMachine_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMDebugStateMachine_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMDebugStateMachine_Hash() { return 3192207374U; }
	DEFINE_FUNCTION(USMInstance::execInternal_EventCleanup)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_PathGuid);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_EventCleanup(Z_Param_Out_PathGuid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execInternal_EventUpdate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_EventUpdate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execInternal_EvaluateAndTakeTransitionChainByGuid)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_PathGuid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Internal_EvaluateAndTakeTransitionChainByGuid(Z_Param_Out_PathGuid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execInternal_Update)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_Update(Z_Param_DeltaSeconds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execRunUpdateAsReference)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RunUpdateAsReference(Z_Param_DeltaSeconds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineStateStarted)
	{
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineStateStarted_Implementation(Z_Param_Out_State);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineStateChanged)
	{
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_ToState);
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_FromState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineStateChanged_Implementation(Z_Param_Out_ToState,Z_Param_Out_FromState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineTransitionTaken)
	{
		P_GET_STRUCT_REF(FSMTransitionInfo,Z_Param_Out_Transition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineTransitionTaken_Implementation(Z_Param_Out_Transition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineStop_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineUpdate)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineUpdate_Implementation(Z_Param_DeltaSeconds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineStart_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineInitialized_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnPreStateMachineInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnPreStateMachineInitialized_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetStateMachineClass)
	{
		P_GET_OBJECT(UClass,Z_Param_NewStateMachineClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStateMachineClass(Z_Param_NewStateMachineClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStateMachineClass)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSubclassOf<USMStateMachineInstance> *)Z_Param__Result=P_THIS->GetStateMachineClass();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetMasterReferenceOwner)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMInstance**)Z_Param__Result=P_THIS->GetMasterReferenceOwner();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetPrimaryReferenceOwner)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMInstance**)Z_Param__Result=P_THIS->GetPrimaryReferenceOwner();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetReferenceOwner)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMInstance**)Z_Param__Result=P_THIS->GetReferenceOwner();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execREP_OnReplicatedReferencesLoaded)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->REP_OnReplicatedReferencesLoaded();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execIsInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInitialized();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execHasStarted)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasStarted();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execK2_TryGetNetworkInterface)
	{
		P_GET_TINTERFACE_REF(ISMStateMachineNetworkedInterface,Z_Param_Out_Interface);
		P_GET_UBOOL_REF(Z_Param_Out_bIsValid);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->K2_TryGetNetworkInterface(Z_Param_Out_Interface,Z_Param_Out_bIsValid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetNetworkInterface)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TScriptInterface<ISMStateMachineNetworkedInterface>*)Z_Param__Result=P_THIS->GetNetworkInterface();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllTransitionInstances)
	{
		P_GET_TARRAY_REF(USMTransitionInstance*,Z_Param_Out_TransitionInstances);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAllTransitionInstances(Z_Param_Out_TransitionInstances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllStateInstances)
	{
		P_GET_TARRAY_REF(USMStateInstance_Base*,Z_Param_Out_StateInstances);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAllStateInstances(Z_Param_Out_StateInstances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execClearStateHistory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearStateHistory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStateHistoryMaxCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetStateHistoryMaxCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetStateHistoryMaxCount)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStateHistoryMaxCount(Z_Param_NewSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStateHistory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FSMStateHistory>*)Z_Param__Result=P_THIS->GetStateHistory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetContext)
	{
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetContext(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execIsInEndState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInEndState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStopOnEndState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetStopOnEndState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetStopOnEndState)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStopOnEndState(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetTickInterval)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetTickInterval();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execCanAutoManageTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanAutoManageTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetAutoManageTime)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAutoManageTime(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetTickInterval)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTickInterval(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetTickBeforeBeginPlay)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTickBeforeBeginPlay(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetCanTickWhenPaused)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanTickWhenPaused(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execCanTickOnManualUpdate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanTickOnManualUpdate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetTickOnManualUpdate)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTickOnManualUpdate(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetCanEverTick)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanEverTick(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execCanEverTick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanEverTick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execIsActive)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsActive();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetRootStateMachineInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateMachineInstance**)Z_Param__Result=P_THIS->GetRootStateMachineInstance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetRootStateMachineNodeInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateMachineInstance**)Z_Param__Result=P_THIS->GetRootStateMachineNodeInstance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSetGuidRedirectMap)
	{
		P_GET_TMAP_REF(FGuid,FGuid,Z_Param_Out_InGuidMap);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGuidRedirectMap(Z_Param_Out_InGuidMap);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetGuidRedirectMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FGuid,FGuid>*)Z_Param__Result=P_THIS->GetGuidRedirectMap();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStateInstanceByQualifiedName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InFullPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetStateInstanceByQualifiedName(Z_Param_InFullPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetNodeInstanceByGuid)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMNodeInstance**)Z_Param__Result=P_THIS->GetNodeInstanceByGuid(Z_Param_Out_Guid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetTransitionInstanceByGuid)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMTransitionInstance**)Z_Param__Result=P_THIS->GetTransitionInstanceByGuid(Z_Param_Out_Guid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetStateInstanceByGuid)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetStateInstanceByGuid(Z_Param_Out_Guid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetReferencedInstanceByGuid)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMInstance**)Z_Param__Result=P_THIS->GetReferencedInstanceByGuid(Z_Param_Out_Guid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execTryGetTransitionInfo)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_GET_STRUCT_REF(FSMTransitionInfo,Z_Param_Out_TransitionInfo);
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TryGetTransitionInfo(Z_Param_Out_Guid,Z_Param_Out_TransitionInfo,Z_Param_Out_bSuccess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execTryGetStateInfo)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_Guid);
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_StateInfo);
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TryGetStateInfo(Z_Param_Out_Guid,Z_Param_Out_StateInfo,Z_Param_Out_bSuccess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllReferencedInstances)
	{
		P_GET_UBOOL(Z_Param_bIncludeChildren);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<USMInstance*>*)Z_Param__Result=P_THIS->GetAllReferencedInstances(Z_Param_bIncludeChildren);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllActiveStateInstances)
	{
		P_GET_TARRAY_REF(USMStateInstance_Base*,Z_Param_Out_ActiveStateInstances);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAllActiveStateInstances(Z_Param_Out_ActiveStateInstances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetSingleActiveStateInstance)
	{
		P_GET_UBOOL(Z_Param_bCheckNested);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetSingleActiveStateInstance(Z_Param_bCheckNested);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetActiveStateInstance)
	{
		P_GET_UBOOL(Z_Param_bCheckNested);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateInstance_Base**)Z_Param__Result=P_THIS->GetActiveStateInstance(Z_Param_bCheckNested);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllActiveStateGuids)
	{
		P_GET_TARRAY_REF(FGuid,Z_Param_Out_ActiveGuids);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetAllActiveStateGuids(Z_Param_Out_ActiveGuids);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetSingleActiveStateGuid)
	{
		P_GET_UBOOL(Z_Param_bCheckNested);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGuid*)Z_Param__Result=P_THIS->GetSingleActiveStateGuid(Z_Param_bCheckNested);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetAllCurrentStateGuids)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FGuid>*)Z_Param__Result=P_THIS->GetAllCurrentStateGuids();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execTryGetNestedActiveState)
	{
		P_GET_STRUCT_REF(FSMStateInfo,Z_Param_Out_FoundState);
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TryGetNestedActiveState(Z_Param_Out_FoundState,Z_Param_Out_bSuccess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetNestedActiveStateGuid)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGuid*)Z_Param__Result=P_THIS->GetNestedActiveStateGuid();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetActiveStateGuid)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGuid*)Z_Param__Result=P_THIS->GetActiveStateGuid();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetNestedActiveStateName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNestedActiveStateName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetActiveStateName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetActiveStateName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execOnStateMachineInitialStateLoaded)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_StateGuid);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStateMachineInitialStateLoaded_Implementation(Z_Param_Out_StateGuid);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execClearLoadedStates)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearLoadedStates();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execAreInitialStatesSetFromLoad)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AreInitialStatesSetFromLoad();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execLoadFromMultipleStates)
	{
		P_GET_TARRAY_REF(FGuid,Z_Param_Out_FromGuids);
		P_GET_UBOOL(Z_Param_bNotify);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadFromMultipleStates(Z_Param_Out_FromGuids,Z_Param_bNotify);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execLoadFromState)
	{
		P_GET_STRUCT_REF(FGuid,Z_Param_Out_FromGuid);
		P_GET_UBOOL(Z_Param_bAllParents);
		P_GET_UBOOL(Z_Param_bNotify);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadFromState(Z_Param_Out_FromGuid,Z_Param_bAllParents,Z_Param_bNotify);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSwitchActiveStateByQualifiedName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InFullPath);
		P_GET_UBOOL(Z_Param_bDeactivateOtherStates);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SwitchActiveStateByQualifiedName(Z_Param_InFullPath,Z_Param_bDeactivateOtherStates);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execSwitchActiveState)
	{
		P_GET_OBJECT(USMStateInstance_Base,Z_Param_NewStateInstance);
		P_GET_UBOOL(Z_Param_bDeactivateOtherStates);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SwitchActiveState(Z_Param_NewStateInstance,Z_Param_bDeactivateOtherStates);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execPreloadAllNodeInstances)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PreloadAllNodeInstances();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execTakeTransitionChain)
	{
		P_GET_TARRAY_REF(USMTransitionInstance*,Z_Param_Out_InTransitionChain);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TakeTransitionChain(Z_Param_Out_InTransitionChain);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execEvaluateAndFindTransitionChain)
	{
		P_GET_OBJECT(USMTransitionInstance,Z_Param_InFirstTransitionInstance);
		P_GET_TARRAY_REF(USMTransitionInstance*,Z_Param_Out_OutTransitionChain);
		P_GET_OBJECT_REF(USMStateInstance_Base,Z_Param_Out_OutDestinationState);
		P_GET_UBOOL(Z_Param_bRequirePreviousStateActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->EvaluateAndFindTransitionChain(Z_Param_InFirstTransitionInstance,Z_Param_Out_OutTransitionChain,Z_Param_Out_OutDestinationState,Z_Param_bRequirePreviousStateActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execEvaluateAndTakeTransitionChain)
	{
		P_GET_OBJECT(USMTransitionInstance,Z_Param_InFirstTransitionInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->EvaluateAndTakeTransitionChain(Z_Param_InFirstTransitionInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execEvaluateTransitions)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EvaluateTransitions();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execStartWithNewContext)
	{
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartWithNewContext(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execReplicatedRestart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReplicatedRestart();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execReplicatedStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReplicatedStop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execReplicatedStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReplicatedStart();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execShutdown)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Shutdown();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execRestart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Restart();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execUpdate)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaSeconds);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Update(Z_Param_DeltaSeconds);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Start();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execInitialize)
	{
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Initialize(Z_Param_Context);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetComponentOwner)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateMachineComponent**)Z_Param__Result=P_THIS->GetComponentOwner();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execGetContext)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetContext();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execIsTickableWhenPaused)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsTickableWhenPaused();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execIsTickable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsTickable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMInstance::execTick)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Tick_Implementation(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	static FName NAME_USMInstance_OnPreStateMachineInitialized = FName(TEXT("OnPreStateMachineInitialized"));
	void USMInstance::OnPreStateMachineInitialized()
	{
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnPreStateMachineInitialized),NULL);
	}
	static FName NAME_USMInstance_OnStateMachineInitialized = FName(TEXT("OnStateMachineInitialized"));
	void USMInstance::OnStateMachineInitialized()
	{
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineInitialized),NULL);
	}
	static FName NAME_USMInstance_OnStateMachineInitialStateLoaded = FName(TEXT("OnStateMachineInitialStateLoaded"));
	void USMInstance::OnStateMachineInitialStateLoaded(FGuid const& StateGuid)
	{
		SMInstance_eventOnStateMachineInitialStateLoaded_Parms Parms;
		Parms.StateGuid=StateGuid;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineInitialStateLoaded),&Parms);
	}
	static FName NAME_USMInstance_OnStateMachineStart = FName(TEXT("OnStateMachineStart"));
	void USMInstance::OnStateMachineStart()
	{
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineStart),NULL);
	}
	static FName NAME_USMInstance_OnStateMachineStateChanged = FName(TEXT("OnStateMachineStateChanged"));
	void USMInstance::OnStateMachineStateChanged(FSMStateInfo const& ToState, FSMStateInfo const& FromState)
	{
		SMInstance_eventOnStateMachineStateChanged_Parms Parms;
		Parms.ToState=ToState;
		Parms.FromState=FromState;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineStateChanged),&Parms);
	}
	static FName NAME_USMInstance_OnStateMachineStateStarted = FName(TEXT("OnStateMachineStateStarted"));
	void USMInstance::OnStateMachineStateStarted(FSMStateInfo const& State)
	{
		SMInstance_eventOnStateMachineStateStarted_Parms Parms;
		Parms.State=State;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineStateStarted),&Parms);
	}
	static FName NAME_USMInstance_OnStateMachineStop = FName(TEXT("OnStateMachineStop"));
	void USMInstance::OnStateMachineStop()
	{
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineStop),NULL);
	}
	static FName NAME_USMInstance_OnStateMachineTransitionTaken = FName(TEXT("OnStateMachineTransitionTaken"));
	void USMInstance::OnStateMachineTransitionTaken(FSMTransitionInfo const& Transition)
	{
		SMInstance_eventOnStateMachineTransitionTaken_Parms Parms;
		Parms.Transition=Transition;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineTransitionTaken),&Parms);
	}
	static FName NAME_USMInstance_OnStateMachineUpdate = FName(TEXT("OnStateMachineUpdate"));
	void USMInstance::OnStateMachineUpdate(float DeltaSeconds)
	{
		SMInstance_eventOnStateMachineUpdate_Parms Parms;
		Parms.DeltaSeconds=DeltaSeconds;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_OnStateMachineUpdate),&Parms);
	}
	static FName NAME_USMInstance_Tick = FName(TEXT("Tick"));
	void USMInstance::Tick(float DeltaTime)
	{
		SMInstance_eventTick_Parms Parms;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_USMInstance_Tick),&Parms);
	}
	void USMInstance::StaticRegisterNativesUSMInstance()
	{
		UClass* Class = USMInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AreInitialStatesSetFromLoad", &USMInstance::execAreInitialStatesSetFromLoad },
			{ "CanAutoManageTime", &USMInstance::execCanAutoManageTime },
			{ "CanEverTick", &USMInstance::execCanEverTick },
			{ "CanTickOnManualUpdate", &USMInstance::execCanTickOnManualUpdate },
			{ "ClearLoadedStates", &USMInstance::execClearLoadedStates },
			{ "ClearStateHistory", &USMInstance::execClearStateHistory },
			{ "EvaluateAndFindTransitionChain", &USMInstance::execEvaluateAndFindTransitionChain },
			{ "EvaluateAndTakeTransitionChain", &USMInstance::execEvaluateAndTakeTransitionChain },
			{ "EvaluateTransitions", &USMInstance::execEvaluateTransitions },
			{ "GetActiveStateGuid", &USMInstance::execGetActiveStateGuid },
			{ "GetActiveStateInstance", &USMInstance::execGetActiveStateInstance },
			{ "GetActiveStateName", &USMInstance::execGetActiveStateName },
			{ "GetAllActiveStateGuids", &USMInstance::execGetAllActiveStateGuids },
			{ "GetAllActiveStateInstances", &USMInstance::execGetAllActiveStateInstances },
			{ "GetAllCurrentStateGuids", &USMInstance::execGetAllCurrentStateGuids },
			{ "GetAllReferencedInstances", &USMInstance::execGetAllReferencedInstances },
			{ "GetAllStateInstances", &USMInstance::execGetAllStateInstances },
			{ "GetAllTransitionInstances", &USMInstance::execGetAllTransitionInstances },
			{ "GetComponentOwner", &USMInstance::execGetComponentOwner },
			{ "GetContext", &USMInstance::execGetContext },
			{ "GetGuidRedirectMap", &USMInstance::execGetGuidRedirectMap },
			{ "GetMasterReferenceOwner", &USMInstance::execGetMasterReferenceOwner },
			{ "GetNestedActiveStateGuid", &USMInstance::execGetNestedActiveStateGuid },
			{ "GetNestedActiveStateName", &USMInstance::execGetNestedActiveStateName },
			{ "GetNetworkInterface", &USMInstance::execGetNetworkInterface },
			{ "GetNodeInstanceByGuid", &USMInstance::execGetNodeInstanceByGuid },
			{ "GetPrimaryReferenceOwner", &USMInstance::execGetPrimaryReferenceOwner },
			{ "GetReferencedInstanceByGuid", &USMInstance::execGetReferencedInstanceByGuid },
			{ "GetReferenceOwner", &USMInstance::execGetReferenceOwner },
			{ "GetRootStateMachineInstance", &USMInstance::execGetRootStateMachineInstance },
			{ "GetRootStateMachineNodeInstance", &USMInstance::execGetRootStateMachineNodeInstance },
			{ "GetSingleActiveStateGuid", &USMInstance::execGetSingleActiveStateGuid },
			{ "GetSingleActiveStateInstance", &USMInstance::execGetSingleActiveStateInstance },
			{ "GetStateHistory", &USMInstance::execGetStateHistory },
			{ "GetStateHistoryMaxCount", &USMInstance::execGetStateHistoryMaxCount },
			{ "GetStateInstanceByGuid", &USMInstance::execGetStateInstanceByGuid },
			{ "GetStateInstanceByQualifiedName", &USMInstance::execGetStateInstanceByQualifiedName },
			{ "GetStateMachineClass", &USMInstance::execGetStateMachineClass },
			{ "GetStopOnEndState", &USMInstance::execGetStopOnEndState },
			{ "GetTickInterval", &USMInstance::execGetTickInterval },
			{ "GetTransitionInstanceByGuid", &USMInstance::execGetTransitionInstanceByGuid },
			{ "HasStarted", &USMInstance::execHasStarted },
			{ "Initialize", &USMInstance::execInitialize },
			{ "Internal_EvaluateAndTakeTransitionChainByGuid", &USMInstance::execInternal_EvaluateAndTakeTransitionChainByGuid },
			{ "Internal_EventCleanup", &USMInstance::execInternal_EventCleanup },
			{ "Internal_EventUpdate", &USMInstance::execInternal_EventUpdate },
			{ "Internal_Update", &USMInstance::execInternal_Update },
			{ "IsActive", &USMInstance::execIsActive },
			{ "IsInEndState", &USMInstance::execIsInEndState },
			{ "IsInitialized", &USMInstance::execIsInitialized },
			{ "IsTickable", &USMInstance::execIsTickable },
			{ "IsTickableWhenPaused", &USMInstance::execIsTickableWhenPaused },
			{ "K2_TryGetNetworkInterface", &USMInstance::execK2_TryGetNetworkInterface },
			{ "LoadFromMultipleStates", &USMInstance::execLoadFromMultipleStates },
			{ "LoadFromState", &USMInstance::execLoadFromState },
			{ "OnPreStateMachineInitialized", &USMInstance::execOnPreStateMachineInitialized },
			{ "OnStateMachineInitialized", &USMInstance::execOnStateMachineInitialized },
			{ "OnStateMachineInitialStateLoaded", &USMInstance::execOnStateMachineInitialStateLoaded },
			{ "OnStateMachineStart", &USMInstance::execOnStateMachineStart },
			{ "OnStateMachineStateChanged", &USMInstance::execOnStateMachineStateChanged },
			{ "OnStateMachineStateStarted", &USMInstance::execOnStateMachineStateStarted },
			{ "OnStateMachineStop", &USMInstance::execOnStateMachineStop },
			{ "OnStateMachineTransitionTaken", &USMInstance::execOnStateMachineTransitionTaken },
			{ "OnStateMachineUpdate", &USMInstance::execOnStateMachineUpdate },
			{ "PreloadAllNodeInstances", &USMInstance::execPreloadAllNodeInstances },
			{ "REP_OnReplicatedReferencesLoaded", &USMInstance::execREP_OnReplicatedReferencesLoaded },
			{ "ReplicatedRestart", &USMInstance::execReplicatedRestart },
			{ "ReplicatedStart", &USMInstance::execReplicatedStart },
			{ "ReplicatedStop", &USMInstance::execReplicatedStop },
			{ "Restart", &USMInstance::execRestart },
			{ "RunUpdateAsReference", &USMInstance::execRunUpdateAsReference },
			{ "SetAutoManageTime", &USMInstance::execSetAutoManageTime },
			{ "SetCanEverTick", &USMInstance::execSetCanEverTick },
			{ "SetCanTickWhenPaused", &USMInstance::execSetCanTickWhenPaused },
			{ "SetContext", &USMInstance::execSetContext },
			{ "SetGuidRedirectMap", &USMInstance::execSetGuidRedirectMap },
			{ "SetStateHistoryMaxCount", &USMInstance::execSetStateHistoryMaxCount },
			{ "SetStateMachineClass", &USMInstance::execSetStateMachineClass },
			{ "SetStopOnEndState", &USMInstance::execSetStopOnEndState },
			{ "SetTickBeforeBeginPlay", &USMInstance::execSetTickBeforeBeginPlay },
			{ "SetTickInterval", &USMInstance::execSetTickInterval },
			{ "SetTickOnManualUpdate", &USMInstance::execSetTickOnManualUpdate },
			{ "Shutdown", &USMInstance::execShutdown },
			{ "Start", &USMInstance::execStart },
			{ "StartWithNewContext", &USMInstance::execStartWithNewContext },
			{ "Stop", &USMInstance::execStop },
			{ "SwitchActiveState", &USMInstance::execSwitchActiveState },
			{ "SwitchActiveStateByQualifiedName", &USMInstance::execSwitchActiveStateByQualifiedName },
			{ "TakeTransitionChain", &USMInstance::execTakeTransitionChain },
			{ "Tick", &USMInstance::execTick },
			{ "TryGetNestedActiveState", &USMInstance::execTryGetNestedActiveState },
			{ "TryGetStateInfo", &USMInstance::execTryGetStateInfo },
			{ "TryGetTransitionInfo", &USMInstance::execTryGetTransitionInfo },
			{ "Update", &USMInstance::execUpdate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics
	{
		struct SMInstance_eventAreInitialStatesSetFromLoad_Parms
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
	void Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventAreInitialStatesSetFromLoad_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventAreInitialStatesSetFromLoad_Parms), &Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Checks if initial entry states have been set through LoadFromState() or LoadFromMultipleStates().\n\x09 * This will be true if at least one state was loaded this way and will become false once Stop() is called.\n\x09 *\n\x09 * In a replicated environment this is only accurate when called from the machine that performed the initial load.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Checks if initial entry states have been set through LoadFromState() or LoadFromMultipleStates().\nThis will be true if at least one state was loaded this way and will become false once Stop() is called.\n\nIn a replicated environment this is only accurate when called from the machine that performed the initial load." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "AreInitialStatesSetFromLoad", nullptr, nullptr, sizeof(SMInstance_eventAreInitialStatesSetFromLoad_Parms), Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics
	{
		struct SMInstance_eventCanAutoManageTime_Parms
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
	void Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventCanAutoManageTime_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventCanAutoManageTime_Parms), &Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "CanAutoManageTime", nullptr, nullptr, sizeof(SMInstance_eventCanAutoManageTime_Parms), Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_CanAutoManageTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_CanAutoManageTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_CanEverTick_Statics
	{
		struct SMInstance_eventCanEverTick_Parms
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
	void Z_Construct_UFunction_USMInstance_CanEverTick_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventCanEverTick_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_CanEverTick_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventCanEverTick_Parms), &Z_Construct_UFunction_USMInstance_CanEverTick_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_CanEverTick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_CanEverTick_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_CanEverTick_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_CanEverTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "CanEverTick", nullptr, nullptr, sizeof(SMInstance_eventCanEverTick_Parms), Z_Construct_UFunction_USMInstance_CanEverTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanEverTick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_CanEverTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanEverTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_CanEverTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_CanEverTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics
	{
		struct SMInstance_eventCanTickOnManualUpdate_Parms
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
	void Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventCanTickOnManualUpdate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventCanTickOnManualUpdate_Parms), &Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "CanTickOnManualUpdate", nullptr, nullptr, sizeof(SMInstance_eventCanTickOnManualUpdate_Parms), Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Clear all temporary initial states loaded through LoadFromState(). Do not use while the state machine\n\x09 * is active and replicated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Clear all temporary initial states loaded through LoadFromState(). Do not use while the state machine\nis active and replicated." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "ClearLoadedStates", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_ClearLoadedStates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_ClearLoadedStates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Empty the state history array.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Empty the state history array." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "ClearStateHistory", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_ClearStateHistory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_ClearStateHistory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics
	{
		struct SMInstance_eventEvaluateAndFindTransitionChain_Parms
		{
			USMTransitionInstance* InFirstTransitionInstance;
			TArray<USMTransitionInstance*> OutTransitionChain;
			USMStateInstance_Base* OutDestinationState;
			bool bRequirePreviousStateActive;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InFirstTransitionInstance;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutTransitionChain_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutTransitionChain;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutDestinationState;
		static void NewProp_bRequirePreviousStateActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequirePreviousStateActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_InFirstTransitionInstance = { "InFirstTransitionInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventEvaluateAndFindTransitionChain_Parms, InFirstTransitionInstance), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutTransitionChain_Inner = { "OutTransitionChain", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutTransitionChain = { "OutTransitionChain", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventEvaluateAndFindTransitionChain_Parms, OutTransitionChain), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutDestinationState = { "OutDestinationState", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventEvaluateAndFindTransitionChain_Parms, OutDestinationState), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_bRequirePreviousStateActive_SetBit(void* Obj)
	{
		((SMInstance_eventEvaluateAndFindTransitionChain_Parms*)Obj)->bRequirePreviousStateActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_bRequirePreviousStateActive = { "bRequirePreviousStateActive", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventEvaluateAndFindTransitionChain_Parms), &Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_bRequirePreviousStateActive_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif
	void Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventEvaluateAndFindTransitionChain_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventEvaluateAndFindTransitionChain_Parms), &Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_InFirstTransitionInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutTransitionChain_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutTransitionChain,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_OutDestinationState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_bRequirePreviousStateActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Evaluate an entire transition chain discovering the path to take. This will not switch states or take the\n\x09 * transition chain. It will only discover the first valid transition chain at the moment of execution.\n\x09 *\n\x09 * A transition chain is the first path that evaluates to true between two states, consisting of all transitions\n\x09 * and conduits that are configured to eval with transitions. In many cases it is of size 0 or 1.\n\x09 *\n\x09 * This should only be used for conditional (tick) evaluation. If an event has triggered a transition but the state\n\x09 * machine has not taken it yet, this method may clear the event status preventing the transition from being taken\n\x09 * natively.\n\x09 *\n\x09 * If the transition chain returned should be taken, use TakeTransitionChain().\n\x09 *\n\x09 * This method is for advanced usage and not required for normal operation.\n\x09 * \n\x09 * @param InFirstTransitionInstance The transition instance, which should be the first part of a transition chain.\n\x09 * @param OutTransitionChain The first valid transition chain where every node has evaluated to true. Only transitions are returned.\n\x09 * @param OutDestinationState The destination state at the end of the chain.\n\x09 * @param bRequirePreviousStateActive If the previous state is not active then cancel evaluation.\n\x09 * @return True if a valid transition chain was found.\n\x09 */" },
		{ "CPP_Default_bRequirePreviousStateActive", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Evaluate an entire transition chain discovering the path to take. This will not switch states or take the\ntransition chain. It will only discover the first valid transition chain at the moment of execution.\n\nA transition chain is the first path that evaluates to true between two states, consisting of all transitions\nand conduits that are configured to eval with transitions. In many cases it is of size 0 or 1.\n\nThis should only be used for conditional (tick) evaluation. If an event has triggered a transition but the state\nmachine has not taken it yet, this method may clear the event status preventing the transition from being taken\nnatively.\n\nIf the transition chain returned should be taken, use TakeTransitionChain().\n\nThis method is for advanced usage and not required for normal operation.\n\n@param InFirstTransitionInstance The transition instance, which should be the first part of a transition chain.\n@param OutTransitionChain The first valid transition chain where every node has evaluated to true. Only transitions are returned.\n@param OutDestinationState The destination state at the end of the chain.\n@param bRequirePreviousStateActive If the previous state is not active then cancel evaluation.\n@return True if a valid transition chain was found." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "EvaluateAndFindTransitionChain", nullptr, nullptr, sizeof(SMInstance_eventEvaluateAndFindTransitionChain_Parms), Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics
	{
		struct SMInstance_eventEvaluateAndTakeTransitionChain_Parms
		{
			USMTransitionInstance* InFirstTransitionInstance;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InFirstTransitionInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_InFirstTransitionInstance = { "InFirstTransitionInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventEvaluateAndTakeTransitionChain_Parms, InFirstTransitionInstance), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif
	void Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventEvaluateAndTakeTransitionChain_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventEvaluateAndTakeTransitionChain_Parms), &Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_InFirstTransitionInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Evaluate an entire transition chain discovering the path to take. If an entire chain passes\n\x09 * then switch to the destination state.\n\x09 *\n\x09 * A transition chain is the first path that evaluates to true between two states, consisting of all transitions\n\x09 * and conduits that are configured to eval with transitions.\n\x09 *\n\x09 * This method fails if the state machine isn't state change authoritative. The destination state won't\n\x09 * become active if this state machine doesn't have local state change authority.\n\x09 *\n\x09 * If the method passes each transition taken will be replicated in order.\n\x09 *\n\x09 * This method is for advanced usage and not required for normal operation.\n\x09 *\n\x09 * @param InFirstTransitionInstance The transition instance, which should be the first part of a transition chain.\n\x09 * @return True if the chain succeeded evaluation.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Evaluate an entire transition chain discovering the path to take. If an entire chain passes\nthen switch to the destination state.\n\nA transition chain is the first path that evaluates to true between two states, consisting of all transitions\nand conduits that are configured to eval with transitions.\n\nThis method fails if the state machine isn't state change authoritative. The destination state won't\nbecome active if this state machine doesn't have local state change authority.\n\nIf the method passes each transition taken will be replicated in order.\n\nThis method is for advanced usage and not required for normal operation.\n\n@param InFirstTransitionInstance The transition instance, which should be the first part of a transition chain.\n@return True if the chain succeeded evaluation." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "EvaluateAndTakeTransitionChain", nullptr, nullptr, sizeof(SMInstance_eventEvaluateAndTakeTransitionChain_Parms), Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Signals to the owning state machine to process transition evaluation.\n\x09 * This is similar to calling Update on the owner root state machine, however state update logic (Tick) won't execute.\n\x09 * All transitions are evaluated as normal starting from the root state machine down.\n\x09 * Depending on super state transitions it's possible the state machine this state is part of may exit.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Signals to the owning state machine to process transition evaluation.\nThis is similar to calling Update on the owner root state machine, however state update logic (Tick) won't execute.\nAll transitions are evaluated as normal starting from the root state machine down.\nDepending on super state transitions it's possible the state machine this state is part of may exit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "EvaluateTransitions", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_EvaluateTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_EvaluateTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics
	{
		struct SMInstance_eventGetActiveStateGuid_Parms
		{
			FGuid ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetActiveStateGuid_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetSingleActiveStateGuid` with bCheckNested = false." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetActiveStateGuid", nullptr, nullptr, sizeof(SMInstance_eventGetActiveStateGuid_Parms), Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetActiveStateGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetActiveStateGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics
	{
		struct SMInstance_eventGetActiveStateInstance_Parms
		{
			bool bCheckNested;
			USMStateInstance_Base* ReturnValue;
		};
		static void NewProp_bCheckNested_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCheckNested;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_bCheckNested_SetBit(void* Obj)
	{
		((SMInstance_eventGetActiveStateInstance_Parms*)Obj)->bCheckNested = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_bCheckNested = { "bCheckNested", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventGetActiveStateInstance_Parms), &Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_bCheckNested_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetActiveStateInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_bCheckNested,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "CPP_Default_bCheckNested", "true" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetSingleActiveStateInstance` instead." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetActiveStateInstance", nullptr, nullptr, sizeof(SMInstance_eventGetActiveStateInstance_Parms), Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetActiveStateInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetActiveStateInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics
	{
		struct SMInstance_eventGetActiveStateName_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetActiveStateName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetSingleActiveStateInstance` with bCheckNested = false instead and read `GetNodeName` from there." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetActiveStateName", nullptr, nullptr, sizeof(SMInstance_eventGetActiveStateName_Parms), Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetActiveStateName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetActiveStateName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics
	{
		struct SMInstance_eventGetAllActiveStateGuids_Parms
		{
			TArray<FGuid> ActiveGuids;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActiveGuids_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActiveGuids;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::NewProp_ActiveGuids_Inner = { "ActiveGuids", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::NewProp_ActiveGuids = { "ActiveGuids", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllActiveStateGuids_Parms, ActiveGuids), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::NewProp_ActiveGuids_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::NewProp_ActiveGuids,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Recursively retrieve the guids of all active states. Useful if saving the current state of a state machine.\n\x09 * @param ActiveGuids [Out] All current ActiveGuids. May be empty. Resets on method start.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Recursively retrieve the guids of all active states. Useful if saving the current state of a state machine.\n@param ActiveGuids [Out] All current ActiveGuids. May be empty. Resets on method start." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllActiveStateGuids", nullptr, nullptr, sizeof(SMInstance_eventGetAllActiveStateGuids_Parms), Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics
	{
		struct SMInstance_eventGetAllActiveStateInstances_Parms
		{
			TArray<USMStateInstance_Base*> ActiveStateInstances;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActiveStateInstances_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActiveStateInstances;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::NewProp_ActiveStateInstances_Inner = { "ActiveStateInstances", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::NewProp_ActiveStateInstances = { "ActiveStateInstances", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllActiveStateInstances_Parms, ActiveStateInstances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::NewProp_ActiveStateInstances_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::NewProp_ActiveStateInstances,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Recursively retrieve all active state instances.\n\x09 * @param ActiveStateInstances [Out] All active state instances. May be empty. Resets on method start.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Recursively retrieve all active state instances.\n@param ActiveStateInstances [Out] All active state instances. May be empty. Resets on method start." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllActiveStateInstances", nullptr, nullptr, sizeof(SMInstance_eventGetAllActiveStateInstances_Parms), Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics
	{
		struct SMInstance_eventGetAllCurrentStateGuids_Parms
		{
			TArray<FGuid> ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllCurrentStateGuids_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetAllActiveStateGuids` instead." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllCurrentStateGuids", nullptr, nullptr, sizeof(SMInstance_eventGetAllCurrentStateGuids_Parms), Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics
	{
		struct SMInstance_eventGetAllReferencedInstances_Parms
		{
			bool bIncludeChildren;
			TArray<USMInstance*> ReturnValue;
		};
		static void NewProp_bIncludeChildren_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIncludeChildren;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_bIncludeChildren_SetBit(void* Obj)
	{
		((SMInstance_eventGetAllReferencedInstances_Parms*)Obj)->bIncludeChildren = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_bIncludeChildren = { "bIncludeChildren", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventGetAllReferencedInstances_Parms), &Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_bIncludeChildren_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllReferencedInstances_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_bIncludeChildren,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Find all referenced instances. IncludeChildren will return all nested state machine references.*/" },
		{ "CPP_Default_bIncludeChildren", "false" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Find all referenced instances. IncludeChildren will return all nested state machine references." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllReferencedInstances", nullptr, nullptr, sizeof(SMInstance_eventGetAllReferencedInstances_Parms), Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllReferencedInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllReferencedInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics
	{
		struct SMInstance_eventGetAllStateInstances_Parms
		{
			TArray<USMStateInstance_Base*> StateInstances;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StateInstances_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_StateInstances;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::NewProp_StateInstances_Inner = { "StateInstances", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::NewProp_StateInstances = { "StateInstances", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllStateInstances_Parms, StateInstances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::NewProp_StateInstances_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::NewProp_StateInstances,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Retrieve all state instances throughout the entire state machine blueprint.\n\x09 * These can be states, state machines, and conduits.\n\x09 *\n\x09 * This includes all nested states in sub state machines and references.\n\x09 * This does not include State Stack instances.\n\x09 *\n\x09 * To retrieve only top level states call GetRootStateMachineNodeInstance() and\n\x09 * from there call 'GetAllStateInstances'.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Retrieve all state instances throughout the entire state machine blueprint.\nThese can be states, state machines, and conduits.\n\nThis includes all nested states in sub state machines and references.\nThis does not include State Stack instances.\n\nTo retrieve only top level states call GetRootStateMachineNodeInstance() and\nfrom there call 'GetAllStateInstances'." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllStateInstances", nullptr, nullptr, sizeof(SMInstance_eventGetAllStateInstances_Parms), Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllStateInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllStateInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics
	{
		struct SMInstance_eventGetAllTransitionInstances_Parms
		{
			TArray<USMTransitionInstance*> TransitionInstances;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TransitionInstances_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TransitionInstances;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::NewProp_TransitionInstances_Inner = { "TransitionInstances", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::NewProp_TransitionInstances = { "TransitionInstances", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetAllTransitionInstances_Parms, TransitionInstances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::NewProp_TransitionInstances_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::NewProp_TransitionInstances,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Retrieve all transition instances throughout the entire state machine blueprint.\n\x09 *\n\x09 * This includes all transitions nested in sub state machines and references.\n\x09 * This does not include Transition Stack instances.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Retrieve all transition instances throughout the entire state machine blueprint.\n\nThis includes all transitions nested in sub state machines and references.\nThis does not include Transition Stack instances." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetAllTransitionInstances", nullptr, nullptr, sizeof(SMInstance_eventGetAllTransitionInstances_Parms), Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetAllTransitionInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetAllTransitionInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics
	{
		struct SMInstance_eventGetComponentOwner_Parms
		{
			USMStateMachineComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetComponentOwner_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** The component owning this instance. Will be null during initialization or if this state machine was created without a component. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The component owning this instance. Will be null during initialization or if this state machine was created without a component." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetComponentOwner", nullptr, nullptr, sizeof(SMInstance_eventGetComponentOwner_Parms), Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetComponentOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetComponentOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetContext_Statics
	{
		struct SMInstance_eventGetContext_Parms
		{
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetContext_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** The object which this state machine is running for. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The object which this state machine is running for." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetContext", nullptr, nullptr, sizeof(SMInstance_eventGetContext_Parms), Z_Construct_UFunction_USMInstance_GetContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetContext_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetContext_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetContext_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics
	{
		struct SMInstance_eventGetGuidRedirectMap_Parms
		{
			TMap<FGuid,FGuid> ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_ValueProp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetGuidRedirectMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** A map of path guids which should be redirected to other path guids. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "A map of path guids which should be redirected to other path guids." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetGuidRedirectMap", nullptr, nullptr, sizeof(SMInstance_eventGetGuidRedirectMap_Parms), Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetGuidRedirectMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetGuidRedirectMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics
	{
		struct SMInstance_eventGetMasterReferenceOwner_Parms
		{
			USMInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetMasterReferenceOwner_Parms, ReturnValue), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetPrimaryReferenceOwner` instead." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetMasterReferenceOwner", nullptr, nullptr, sizeof(SMInstance_eventGetMasterReferenceOwner_Parms), Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics
	{
		struct SMInstance_eventGetNestedActiveStateGuid_Parms
		{
			FGuid ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetNestedActiveStateGuid_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetSingleActiveStateGuid` instead." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetNestedActiveStateGuid", nullptr, nullptr, sizeof(SMInstance_eventGetNestedActiveStateGuid_Parms), Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics
	{
		struct SMInstance_eventGetNestedActiveStateName_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetNestedActiveStateName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetSingleActiveStateInstance` instead and read `GetNodeName` from there." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetNestedActiveStateName", nullptr, nullptr, sizeof(SMInstance_eventGetNestedActiveStateName_Parms), Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetNestedActiveStateName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetNestedActiveStateName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics
	{
		struct SMInstance_eventGetNetworkInterface_Parms
		{
			TScriptInterface<ISMStateMachineNetworkedInterface> ReturnValue;
		};
		static const UE4CodeGen_Private::FInterfacePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UE4CodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetNetworkInterface_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Return the server interface if there is one. This may be null. Always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Return the server interface if there is one. This may be null. Always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetNetworkInterface", nullptr, nullptr, sizeof(SMInstance_eventGetNetworkInterface_Parms), Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetNetworkInterface()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetNetworkInterface_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics
	{
		struct SMInstance_eventGetNodeInstanceByGuid_Parms
		{
			FGuid Guid;
			USMNodeInstance* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetNodeInstanceByGuid_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetNodeInstanceByGuid_Parms, ReturnValue), Z_Construct_UClass_USMNodeInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly return any type of node instance. These could be transitions or states. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly return any type of node instance. These could be transitions or states. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetNodeInstanceByGuid", nullptr, nullptr, sizeof(SMInstance_eventGetNodeInstanceByGuid_Parms), Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics
	{
		struct SMInstance_eventGetPrimaryReferenceOwner_Parms
		{
			USMInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetPrimaryReferenceOwner_Parms, ReturnValue), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Look up the owners to find the top-most instance. Could be this instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Look up the owners to find the top-most instance. Could be this instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetPrimaryReferenceOwner", nullptr, nullptr, sizeof(SMInstance_eventGetPrimaryReferenceOwner_Parms), Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics
	{
		struct SMInstance_eventGetReferencedInstanceByGuid_Parms
		{
			FGuid Guid;
			USMInstance* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetReferencedInstanceByGuid_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetReferencedInstanceByGuid_Parms, ReturnValue), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly return a referenced instance given a state machine guid. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly return a referenced instance given a state machine guid. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetReferencedInstanceByGuid", nullptr, nullptr, sizeof(SMInstance_eventGetReferencedInstanceByGuid_Parms), Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics
	{
		struct SMInstance_eventGetReferenceOwner_Parms
		{
			USMInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetReferenceOwner_Parms, ReturnValue), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Get the instance owning this reference. If null this is not a reference. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Get the instance owning this reference. If null this is not a reference." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetReferenceOwner", nullptr, nullptr, sizeof(SMInstance_eventGetReferenceOwner_Parms), Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetReferenceOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetReferenceOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics
	{
		struct SMInstance_eventGetRootStateMachineInstance_Parms
		{
			USMStateMachineInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetRootStateMachineInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use `GetRootStateMachineNodeInstance` instead." },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetRootStateMachineInstance", nullptr, nullptr, sizeof(SMInstance_eventGetRootStateMachineInstance_Parms), Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics
	{
		struct SMInstance_eventGetRootStateMachineNodeInstance_Parms
		{
			USMStateMachineInstance* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetRootStateMachineNodeInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Return the root USMStateMachineInstance node.\n\x09 * \n\x09 * This is relative to the SMInstance you are calling it from. If this is a state machine reference\n\x09 * it will return the reference's root state machine node instance.\n\x09 *\n\x09 * To retrieve the primary root state machine node instance, call this method from GetPrimaryReferenceOwner().\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Return the root USMStateMachineInstance node.\n\nThis is relative to the SMInstance you are calling it from. If this is a state machine reference\nit will return the reference's root state machine node instance.\n\nTo retrieve the primary root state machine node instance, call this method from GetPrimaryReferenceOwner()." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetRootStateMachineNodeInstance", nullptr, nullptr, sizeof(SMInstance_eventGetRootStateMachineNodeInstance_Parms), Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics
	{
		struct SMInstance_eventGetSingleActiveStateGuid_Parms
		{
			bool bCheckNested;
			FGuid ReturnValue;
		};
		static void NewProp_bCheckNested_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCheckNested;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_bCheckNested_SetBit(void* Obj)
	{
		((SMInstance_eventGetSingleActiveStateGuid_Parms*)Obj)->bCheckNested = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_bCheckNested = { "bCheckNested", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventGetSingleActiveStateGuid_Parms), &Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_bCheckNested_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetSingleActiveStateGuid_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_bCheckNested,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Retrieve the first active state Guid. If a state is not active an invalid Guid will be returned.\n\x09 * For multiple states GetAllActiveStateGuids() should be called instead.\n\x09 * @param bCheckNested Check nested state machines.\n\x09 * @return the first active state guid.\n\x09 */" },
		{ "CPP_Default_bCheckNested", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Retrieve the first active state Guid. If a state is not active an invalid Guid will be returned.\nFor multiple states GetAllActiveStateGuids() should be called instead.\n@param bCheckNested Check nested state machines.\n@return the first active state guid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetSingleActiveStateGuid", nullptr, nullptr, sizeof(SMInstance_eventGetSingleActiveStateGuid_Parms), Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics
	{
		struct SMInstance_eventGetSingleActiveStateInstance_Parms
		{
			bool bCheckNested;
			USMStateInstance_Base* ReturnValue;
		};
		static void NewProp_bCheckNested_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCheckNested;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_bCheckNested_SetBit(void* Obj)
	{
		((SMInstance_eventGetSingleActiveStateInstance_Parms*)Obj)->bCheckNested = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_bCheckNested = { "bCheckNested", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventGetSingleActiveStateInstance_Parms), &Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_bCheckNested_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetSingleActiveStateInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_bCheckNested,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Locate the first active state instance. For multiple states GetAllActiveStateInstances() should be called instead.\n\x09 * \n\x09 * @param bCheckNested Check nested state machines.\n\x09 * @return A single active state's node instance.\n\x09 */" },
		{ "CPP_Default_bCheckNested", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Locate the first active state instance. For multiple states GetAllActiveStateInstances() should be called instead.\n\n@param bCheckNested Check nested state machines.\n@return A single active state's node instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetSingleActiveStateInstance", nullptr, nullptr, sizeof(SMInstance_eventGetSingleActiveStateInstance_Parms), Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStateHistory_Statics
	{
		struct SMInstance_eventGetStateHistory_Parms
		{
			TArray<FSMStateHistory> ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMStateHistory, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateHistory_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Retrieve an ordered history of states, oldest to newest, not including active state(s). This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Retrieve an ordered history of states, oldest to newest, not including active state(s). This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStateHistory", nullptr, nullptr, sizeof(SMInstance_eventGetStateHistory_Parms), Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStateHistory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStateHistory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics
	{
		struct SMInstance_eventGetStateHistoryMaxCount_Parms
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
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateHistoryMaxCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Return the maximum history count.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Return the maximum history count." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStateHistoryMaxCount", nullptr, nullptr, sizeof(SMInstance_eventGetStateHistoryMaxCount_Parms), Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics
	{
		struct SMInstance_eventGetStateInstanceByGuid_Parms
		{
			FGuid Guid;
			USMStateInstance_Base* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateInstanceByGuid_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateInstanceByGuid_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly return a state instance given the state guid. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly return a state instance given the state guid. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStateInstanceByGuid", nullptr, nullptr, sizeof(SMInstance_eventGetStateInstanceByGuid_Parms), Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics
	{
		struct SMInstance_eventGetStateInstanceByQualifiedName_Parms
		{
			FString InFullPath;
			USMStateInstance_Base* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFullPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InFullPath;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_InFullPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_InFullPath = { "InFullPath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateInstanceByQualifiedName_Parms, InFullPath), METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_InFullPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_InFullPath_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateInstanceByQualifiedName_Parms, ReturnValue), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_InFullPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Return a state instance by its fully qualified name in a state machine blueprint.\n\x09 * A top level state name of \"Locomotion\" would be found by searching \"Locomotion\".\n\x09 * A nested state of name \"Jump\" within a \"Locomotion\" state machine would be found by \"Locomotion.Jump\".\n\x09 *\n\x09 * It is not necessary to include the \"Root\" state machine node in the search.\n\x09 *\n\x09 * The search is performed iteratively and the performance is roughly O(n) by number of nodes in the path.\n\x09 * The lookup of each state is O(1).\n\x09 *\n\x09 * @param InFullPath The full path to the node. When the state machine type is known a UI dropdown is available [Pro Only].\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Return a state instance by its fully qualified name in a state machine blueprint.\nA top level state name of \"Locomotion\" would be found by searching \"Locomotion\".\nA nested state of name \"Jump\" within a \"Locomotion\" state machine would be found by \"Locomotion.Jump\".\n\nIt is not necessary to include the \"Root\" state machine node in the search.\n\nThe search is performed iteratively and the performance is roughly O(n) by number of nodes in the path.\nThe lookup of each state is O(1).\n\n@param InFullPath The full path to the node. When the state machine type is known a UI dropdown is available [Pro Only]." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStateInstanceByQualifiedName", nullptr, nullptr, sizeof(SMInstance_eventGetStateInstanceByQualifiedName_Parms), Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics
	{
		struct SMInstance_eventGetStateMachineClass_Parms
		{
			TSubclassOf<USMStateMachineInstance>  ReturnValue;
		};
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetStateMachineClass_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** The custom state machine class assigned to the root state machine. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The custom state machine class assigned to the root state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStateMachineClass", nullptr, nullptr, sizeof(SMInstance_eventGetStateMachineClass_Parms), Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStateMachineClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStateMachineClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics
	{
		struct SMInstance_eventGetStopOnEndState_Parms
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
	void Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventGetStopOnEndState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventGetStopOnEndState_Parms), &Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetStopOnEndState", nullptr, nullptr, sizeof(SMInstance_eventGetStopOnEndState_Parms), Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetStopOnEndState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetStopOnEndState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetTickInterval_Statics
	{
		struct SMInstance_eventGetTickInterval_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetTickInterval_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetTickInterval", nullptr, nullptr, sizeof(SMInstance_eventGetTickInterval_Parms), Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetTickInterval()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetTickInterval_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics
	{
		struct SMInstance_eventGetTransitionInstanceByGuid_Parms
		{
			FGuid Guid;
			USMTransitionInstance* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetTransitionInstanceByGuid_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventGetTransitionInstanceByGuid_Parms, ReturnValue), Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly return a transition instance given a transition guid. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly return a transition instance given a transition guid. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "GetTransitionInstanceByGuid", nullptr, nullptr, sizeof(SMInstance_eventGetTransitionInstanceByGuid_Parms), Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_HasStarted_Statics
	{
		struct SMInstance_eventHasStarted_Parms
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
	void Z_Construct_UFunction_USMInstance_HasStarted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventHasStarted_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_HasStarted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventHasStarted_Parms), &Z_Construct_UFunction_USMInstance_HasStarted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_HasStarted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_HasStarted_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_HasStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** True if the instance has started. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "True if the instance has started." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_HasStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "HasStarted", nullptr, nullptr, sizeof(SMInstance_eventHasStarted_Parms), Z_Construct_UFunction_USMInstance_HasStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_HasStarted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_HasStarted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_HasStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_HasStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_HasStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Initialize_Statics
	{
		struct SMInstance_eventInitialize_Parms
		{
			UObject* Context;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_Initialize_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventInitialize_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Initialize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Initialize_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Initialize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Prepare the state machine for use.\n\x09 *\n\x09 * @param Context The context to use for the state machine.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Prepare the state machine for use.\n\n@param Context The context to use for the state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Initialize", nullptr, nullptr, sizeof(SMInstance_eventInitialize_Parms), Z_Construct_UFunction_USMInstance_Initialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Initialize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Initialize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Initialize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Initialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Initialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics
	{
		struct SMInstance_eventInternal_EvaluateAndTakeTransitionChainByGuid_Parms
		{
			FGuid PathGuid;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuid;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_PathGuid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_PathGuid = { "PathGuid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventInternal_EvaluateAndTakeTransitionChainByGuid_Parms, PathGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_PathGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_PathGuid_MetaData)) };
	void Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventInternal_EvaluateAndTakeTransitionChainByGuid_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventInternal_EvaluateAndTakeTransitionChainByGuid_Parms), &Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_PathGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Internal logic for taking a transition chain by the path guid. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Internal logic for taking a transition chain by the path guid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Internal_EvaluateAndTakeTransitionChainByGuid", nullptr, nullptr, sizeof(SMInstance_eventInternal_EvaluateAndTakeTransitionChainByGuid_Parms), Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C80401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics
	{
		struct SMInstance_eventInternal_EventCleanup_Parms
		{
			FGuid PathGuid;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuid;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::NewProp_PathGuid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::NewProp_PathGuid = { "PathGuid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventInternal_EventCleanup_Parms, PathGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::NewProp_PathGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::NewProp_PathGuid_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::NewProp_PathGuid,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Internal cleanup logic after an auto-bound event fires. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Internal cleanup logic after an auto-bound event fires." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Internal_EventCleanup", nullptr, nullptr, sizeof(SMInstance_eventInternal_EventCleanup_Parms), Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C80401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Internal_EventCleanup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Internal_EventCleanup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Internal logic from when an auto-bound event might trigger an update. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Internal logic from when an auto-bound event might trigger an update." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Internal_EventUpdate", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Internal_EventUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Internal_EventUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Internal_Update_Statics
	{
		struct SMInstance_eventInternal_Update_Parms
		{
			float DeltaSeconds;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_Internal_Update_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventInternal_Update_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Internal_Update_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Internal_Update_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Internal_Update_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Internal update logic. Can be called during an update and used by event triggers. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Internal update logic. Can be called during an update and used by event triggers." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Internal_Update_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Internal_Update", nullptr, nullptr, sizeof(SMInstance_eventInternal_Update_Parms), Z_Construct_UFunction_USMInstance_Internal_Update_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_Update_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Internal_Update_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Internal_Update_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Internal_Update()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Internal_Update_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_IsActive_Statics
	{
		struct SMInstance_eventIsActive_Parms
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
	void Z_Construct_UFunction_USMInstance_IsActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventIsActive_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_IsActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventIsActive_Parms), &Z_Construct_UFunction_USMInstance_IsActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_IsActive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_IsActive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_IsActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_IsActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "IsActive", nullptr, nullptr, sizeof(SMInstance_eventIsActive_Parms), Z_Construct_UFunction_USMInstance_IsActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_IsActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_IsActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_IsActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_IsInEndState_Statics
	{
		struct SMInstance_eventIsInEndState_Parms
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
	void Z_Construct_UFunction_USMInstance_IsInEndState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventIsInEndState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_IsInEndState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventIsInEndState_Parms), &Z_Construct_UFunction_USMInstance_IsInEndState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_IsInEndState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_IsInEndState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_IsInEndState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** True if the root state machine is in an end state. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "True if the root state machine is in an end state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_IsInEndState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "IsInEndState", nullptr, nullptr, sizeof(SMInstance_eventIsInEndState_Parms), Z_Construct_UFunction_USMInstance_IsInEndState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsInEndState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_IsInEndState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsInEndState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_IsInEndState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_IsInEndState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_IsInitialized_Statics
	{
		struct SMInstance_eventIsInitialized_Parms
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
	void Z_Construct_UFunction_USMInstance_IsInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventIsInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_IsInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventIsInitialized_Parms), &Z_Construct_UFunction_USMInstance_IsInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_IsInitialized_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_IsInitialized_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_IsInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** If this instance is fully initialized. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "If this instance is fully initialized." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_IsInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "IsInitialized", nullptr, nullptr, sizeof(SMInstance_eventIsInitialized_Parms), Z_Construct_UFunction_USMInstance_IsInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsInitialized_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_IsInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_IsInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_IsInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_IsTickable_Statics
	{
		struct SMInstance_eventIsTickable_Parms
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
	void Z_Construct_UFunction_USMInstance_IsTickable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventIsTickable_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_IsTickable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventIsTickable_Parms), &Z_Construct_UFunction_USMInstance_IsTickable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_IsTickable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_IsTickable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_IsTickable_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_IsTickable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "IsTickable", nullptr, nullptr, sizeof(SMInstance_eventIsTickable_Parms), Z_Construct_UFunction_USMInstance_IsTickable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsTickable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_IsTickable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsTickable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_IsTickable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_IsTickable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics
	{
		struct SMInstance_eventIsTickableWhenPaused_Parms
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
	void Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventIsTickableWhenPaused_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventIsTickableWhenPaused_Parms), &Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "IsTickableWhenPaused", nullptr, nullptr, sizeof(SMInstance_eventIsTickableWhenPaused_Parms), Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_IsTickableWhenPaused()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_IsTickableWhenPaused_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics
	{
		struct SMInstance_eventK2_TryGetNetworkInterface_Parms
		{
			TScriptInterface<ISMStateMachineNetworkedInterface> Interface;
			bool bIsValid;
		};
		static const UE4CodeGen_Private::FInterfacePropertyParams NewProp_Interface;
		static void NewProp_bIsValid_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_Interface = { "Interface", nullptr, (EPropertyFlags)0x0014000000000180, UE4CodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventK2_TryGetNetworkInterface_Parms, Interface), Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_bIsValid_SetBit(void* Obj)
	{
		((SMInstance_eventK2_TryGetNetworkInterface_Parms*)Obj)->bIsValid = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventK2_TryGetNetworkInterface_Parms), &Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_Interface,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::NewProp_bIsValid,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Return the server interface if there is one. This may be null. Always executes from the primary instance. */" },
		{ "DisplayName", "TryGetNetworkInterface" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Return the server interface if there is one. This may be null. Always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "K2_TryGetNetworkInterface", nullptr, nullptr, sizeof(SMInstance_eventK2_TryGetNetworkInterface_Parms), Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics
	{
		struct SMInstance_eventLoadFromMultipleStates_Parms
		{
			TArray<FGuid> FromGuids;
			bool bNotify;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FromGuids_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FromGuids_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FromGuids;
		static void NewProp_bNotify_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNotify;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids_Inner = { "FromGuids", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids = { "FromGuids", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventLoadFromMultipleStates_Parms, FromGuids), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids_MetaData)) };
	void Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_bNotify_SetBit(void* Obj)
	{
		((SMInstance_eventLoadFromMultipleStates_Parms*)Obj)->bNotify = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_bNotify = { "bNotify", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventLoadFromMultipleStates_Parms), &Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_bNotify_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_FromGuids,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::NewProp_bNotify,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Set all owning parents' temporary initial state to the given guids. Useful for restoring multiple states within a state machine.\n\x09 * Best used when restoring from GetAllActiveStateGuids(). When the state machine starts it will default to these states.\n\x09 *\n\x09 * This should only be called on an initialized state machine that is stopped.\n\x09 *\n\x09 * When using with replication this should be called from the server, or from a client that has state change authority.\n\x09 * \n\x09 * @param FromGuids Array of state guids to load.\n\x09 * @param bNotify Calls OnStateMachineInitialStateLoaded on this instance and sets AreInitialStatesSetFromLoad().\n\x09 */" },
		{ "CPP_Default_bNotify", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Set all owning parents' temporary initial state to the given guids. Useful for restoring multiple states within a state machine.\nBest used when restoring from GetAllActiveStateGuids(). When the state machine starts it will default to these states.\n\nThis should only be called on an initialized state machine that is stopped.\n\nWhen using with replication this should be called from the server, or from a client that has state change authority.\n\n@param FromGuids Array of state guids to load.\n@param bNotify Calls OnStateMachineInitialStateLoaded on this instance and sets AreInitialStatesSetFromLoad()." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "LoadFromMultipleStates", nullptr, nullptr, sizeof(SMInstance_eventLoadFromMultipleStates_Parms), Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_LoadFromMultipleStates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_LoadFromMultipleStates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_LoadFromState_Statics
	{
		struct SMInstance_eventLoadFromState_Parms
		{
			FGuid FromGuid;
			bool bAllParents;
			bool bNotify;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FromGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FromGuid;
		static void NewProp_bAllParents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllParents;
		static void NewProp_bNotify_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNotify;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_FromGuid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_FromGuid = { "FromGuid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventLoadFromState_Parms, FromGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_FromGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_FromGuid_MetaData)) };
	void Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bAllParents_SetBit(void* Obj)
	{
		((SMInstance_eventLoadFromState_Parms*)Obj)->bAllParents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bAllParents = { "bAllParents", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventLoadFromState_Parms), &Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bAllParents_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bNotify_SetBit(void* Obj)
	{
		((SMInstance_eventLoadFromState_Parms*)Obj)->bNotify = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bNotify = { "bNotify", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventLoadFromState_Parms), &Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bNotify_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_LoadFromState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_FromGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bAllParents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_LoadFromState_Statics::NewProp_bNotify,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_LoadFromState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Sets a temporary initial state of the guid's owning state machine. When the state machine starts it will default to this state.\n\x09 * With AllParents to true this is useful for restoring a single active state of a state machine from GetSingleActiveStateGuid().\n\x09 * If there are multiple active states, or the state of non active sub state machines is important use LoadFromMultipleStates() instead.\n\x09 *\n\x09 * This should only be called on an initialized state machine that is stopped.\n\x09 *\n\x09 * When using with replication this should be called from the server, or from a client that has state change authority.\n\x09 * \n\x09 * @param FromGuid The state guid to load.\n\x09 * @param bAllParents Recursively set the initial state of all parent state machines.\n\x09 * @param bNotify Calls OnStateMachineInitialStateLoaded on this instance and sets AreInitialStatesSetFromLoad().\n\x09 */" },
		{ "CPP_Default_bAllParents", "true" },
		{ "CPP_Default_bNotify", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Sets a temporary initial state of the guid's owning state machine. When the state machine starts it will default to this state.\nWith AllParents to true this is useful for restoring a single active state of a state machine from GetSingleActiveStateGuid().\nIf there are multiple active states, or the state of non active sub state machines is important use LoadFromMultipleStates() instead.\n\nThis should only be called on an initialized state machine that is stopped.\n\nWhen using with replication this should be called from the server, or from a client that has state change authority.\n\n@param FromGuid The state guid to load.\n@param bAllParents Recursively set the initial state of all parent state machines.\n@param bNotify Calls OnStateMachineInitialStateLoaded on this instance and sets AreInitialStatesSetFromLoad()." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_LoadFromState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "LoadFromState", nullptr, nullptr, sizeof(SMInstance_eventLoadFromState_Parms), Z_Construct_UFunction_USMInstance_LoadFromState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_LoadFromState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_LoadFromState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_LoadFromState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_LoadFromState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/**\n\x09 * Called at the beginning of Initialize().\n\x09 * Most information will not be available at this stage other than the context.\n\x09 *\n\x09 * Warning: When using async initialization this does not run on the game thread.\n\x09 * Make sure your code is thread safe!\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called at the beginning of Initialize().\nMost information will not be available at this stage other than the context.\n\nWarning: When using async initialization this does not run on the game thread.\nMake sure your code is thread safe!" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnPreStateMachineInitialized", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called when the instance is first initialized.  */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when the instance is first initialized." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineInitialized", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StateGuid;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::NewProp_StateGuid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::NewProp_StateGuid = { "StateGuid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineInitialStateLoaded_Parms, StateGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::NewProp_StateGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::NewProp_StateGuid_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::NewProp_StateGuid,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/**\n\x09 * Called after an initial state has been set with LoadFromState() or LoadFromMultipleStates().\n\x09 * This may be called multiple times depending whether there is more than one state being loaded\n\x09 * or if parent state machines are also being loaded.\n\x09 *\n\x09 * @param StateGuid The guid of the state being loaded. The state instance can be retrieved with GetStateInstanceByGuid.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called after an initial state has been set with LoadFromState() or LoadFromMultipleStates().\nThis may be called multiple times depending whether there is more than one state being loaded\nor if parent state machines are also being loaded.\n\n@param StateGuid The guid of the state being loaded. The state instance can be retrieved with GetStateInstanceByGuid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineInitialStateLoaded", nullptr, nullptr, sizeof(SMInstance_eventOnStateMachineInitialStateLoaded_Parms), Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C80C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called right before the root state machine starts its initial state.  */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right before the root state machine starts its initial state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineStart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ToState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ToState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FromState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FromState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_ToState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_ToState = { "ToState", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineStateChanged_Parms, ToState), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_ToState_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_ToState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_FromState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_FromState = { "FromState", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineStateChanged_Parms, FromState), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_FromState_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_FromState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_ToState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::NewProp_FromState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called when a state machine has switched states. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a state machine has switched states." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineStateChanged", nullptr, nullptr, sizeof(SMInstance_eventOnStateMachineStateChanged_Parms), Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::NewProp_State_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineStateStarted_Parms, State), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::NewProp_State_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::NewProp_State_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called when a state has started. This happens after OnStateMachineStateChanged and all previous transitions have evaluated. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a state has started. This happens after OnStateMachineStateChanged and all previous transitions have evaluated." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineStateStarted", nullptr, nullptr, sizeof(SMInstance_eventOnStateMachineStateStarted_Parms), Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called right after the instance has been stopped. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right after the instance has been stopped." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineStop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transition;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::NewProp_Transition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::NewProp_Transition = { "Transition", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineTransitionTaken_Parms, Transition), Z_Construct_UScriptStruct_FSMTransitionInfo, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::NewProp_Transition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::NewProp_Transition_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::NewProp_Transition,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called when a transition has evaluated to true and is being taken. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a transition has evaluated to true and is being taken." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineTransitionTaken", nullptr, nullptr, sizeof(SMInstance_eventOnStateMachineTransitionTaken_Parms), Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventOnStateMachineUpdate_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** Called right before the root state machine updates.  */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right before the root state machine updates." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "OnStateMachineUpdate", nullptr, nullptr, sizeof(SMInstance_eventOnStateMachineUpdate_Parms), Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_OnStateMachineUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_OnStateMachineUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Ensure all default node instances are loaded into memory. Default node classes are normally loaded on demand to save on memory\n\x09 * and initialization time. Preloading isn't necessary unless most default nodes need to be accessed programatically, such as calling\n\x09 * GetNodeInstance() from a local state graph.\n\x09 *\n\x09 * This has no effect on nodes assigned a custom node class.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Ensure all default node instances are loaded into memory. Default node classes are normally loaded on demand to save on memory\nand initialization time. Preloading isn't necessary unless most default nodes need to be accessed programatically, such as calling\nGetNodeInstance() from a local state graph.\n\nThis has no effect on nodes assigned a custom node class." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "PreloadAllNodeInstances", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "REP_OnReplicatedReferencesLoaded", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Calls Restart() locally or on the component owner if valid.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Calls Restart() locally or on the component owner if valid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "ReplicatedRestart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_ReplicatedRestart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_ReplicatedRestart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Calls Start() locally or on the component owner if valid.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Calls Start() locally or on the component owner if valid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "ReplicatedStart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_ReplicatedStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_ReplicatedStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Calls Stop() locally or on the component owner if valid.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Calls Stop() locally or on the component owner if valid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "ReplicatedStop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_ReplicatedStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_ReplicatedStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Restart_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Restart_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Forcibly restart the state machine and place it back into an entry state.\n\x09 * This is a local call only and is not replicated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Forcibly restart the state machine and place it back into an entry state.\nThis is a local call only and is not replicated." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Restart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Restart", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Restart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Restart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Restart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Restart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics
	{
		struct SMInstance_eventRunUpdateAsReference_Parms
		{
			float DeltaSeconds;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventRunUpdateAsReference_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Call from an FSM reference. Avoids the update cancelling out if already in progress\n\x09 * and keeps behavior consistent with normal nested FSMs. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Call from an FSM reference. Avoids the update cancelling out if already in progress\nand keeps behavior consistent with normal nested FSMs." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "RunUpdateAsReference", nullptr, nullptr, sizeof(SMInstance_eventRunUpdateAsReference_Parms), Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_RunUpdateAsReference()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_RunUpdateAsReference_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics
	{
		struct SMInstance_eventSetAutoManageTime_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetAutoManageTime_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetAutoManageTime_Parms), &Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetAutoManageTime", nullptr, nullptr, sizeof(SMInstance_eventSetAutoManageTime_Parms), Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetAutoManageTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetAutoManageTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics
	{
		struct SMInstance_eventSetCanEverTick_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetCanEverTick_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetCanEverTick_Parms), &Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** If false IsTickable will return false. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "If false IsTickable will return false." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetCanEverTick", nullptr, nullptr, sizeof(SMInstance_eventSetCanEverTick_Parms), Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetCanEverTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetCanEverTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics
	{
		struct SMInstance_eventSetCanTickWhenPaused_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetCanTickWhenPaused_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetCanTickWhenPaused_Parms), &Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetCanTickWhenPaused", nullptr, nullptr, sizeof(SMInstance_eventSetCanTickWhenPaused_Parms), Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetContext_Statics
	{
		struct SMInstance_eventSetContext_Parms
		{
			UObject* Context;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_SetContext_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSetContext_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetContext_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Sets a new context. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Sets a new context." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetContext", nullptr, nullptr, sizeof(SMInstance_eventSetContext_Parms), Z_Construct_UFunction_USMInstance_SetContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetContext_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetContext_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetContext_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics
	{
		struct SMInstance_eventSetGuidRedirectMap_Parms
		{
			TMap<FGuid,FGuid> InGuidMap;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InGuidMap_ValueProp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InGuidMap_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InGuidMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_InGuidMap;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_ValueProp = { "InGuidMap", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_Key_KeyProp = { "InGuidMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap = { "InGuidMap", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSetGuidRedirectMap_Parms, InGuidMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::NewProp_InGuidMap,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Directly set the guid redirect map. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Directly set the guid redirect map." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetGuidRedirectMap", nullptr, nullptr, sizeof(SMInstance_eventSetGuidRedirectMap_Parms), Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetGuidRedirectMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetGuidRedirectMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics
	{
		struct SMInstance_eventSetStateHistoryMaxCount_Parms
		{
			int32 NewSize;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::NewProp_NewSize = { "NewSize", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSetStateHistoryMaxCount_Parms, NewSize), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::NewProp_NewSize,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Sets the maximum number of states to record into history.\n\x09 * Resizes the array removing older entries if needed.\n\x09 * @param NewSize The number of states to record. Set to -1 for no limit.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Sets the maximum number of states to record into history.\nResizes the array removing older entries if needed.\n@param NewSize The number of states to record. Set to -1 for no limit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetStateHistoryMaxCount", nullptr, nullptr, sizeof(SMInstance_eventSetStateHistoryMaxCount_Parms), Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics
	{
		struct SMInstance_eventSetStateMachineClass_Parms
		{
			TSubclassOf<USMStateMachineInstance>  NewStateMachineClass;
		};
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_NewStateMachineClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::NewProp_NewStateMachineClass = { "NewStateMachineClass", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSetStateMachineClass_Parms, NewStateMachineClass), Z_Construct_UClass_USMStateMachineInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::NewProp_NewStateMachineClass,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Sets the state machine node instance class.\n\x09 *\n\x09 * @param NewStateMachineClass The state machine class to set.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Sets the state machine node instance class.\n\n@param NewStateMachineClass The state machine class to set." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetStateMachineClass", nullptr, nullptr, sizeof(SMInstance_eventSetStateMachineClass_Parms), Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetStateMachineClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetStateMachineClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics
	{
		struct SMInstance_eventSetStopOnEndState_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetStopOnEndState_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetStopOnEndState_Parms), &Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetStopOnEndState", nullptr, nullptr, sizeof(SMInstance_eventSetStopOnEndState_Parms), Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetStopOnEndState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetStopOnEndState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics
	{
		struct SMInstance_eventSetTickBeforeBeginPlay_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetTickBeforeBeginPlay_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetTickBeforeBeginPlay_Parms), &Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetTickBeforeBeginPlay", nullptr, nullptr, sizeof(SMInstance_eventSetTickBeforeBeginPlay_Parms), Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetTickInterval_Statics
	{
		struct SMInstance_eventSetTickInterval_Parms
		{
			float Value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSetTickInterval_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Time in seconds between native ticks. This mostly affects the \"Update\" rate of the state machine. Overloaded Ticks won't be affected. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Time in seconds between native ticks. This mostly affects the \"Update\" rate of the state machine. Overloaded Ticks won't be affected." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetTickInterval", nullptr, nullptr, sizeof(SMInstance_eventSetTickInterval_Parms), Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetTickInterval()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetTickInterval_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics
	{
		struct SMInstance_eventSetTickOnManualUpdate_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((SMInstance_eventSetTickOnManualUpdate_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSetTickOnManualUpdate_Parms), &Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SetTickOnManualUpdate", nullptr, nullptr, sizeof(SMInstance_eventSetTickOnManualUpdate_Parms), Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Shutdown_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Shutdown_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Shutdown this instance. Calls Stop(). Must call Initialize() again before use.\n\x09 * If the goal is to restart the state machine later call Stop() instead.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Shutdown this instance. Calls Stop(). Must call Initialize() again before use.\nIf the goal is to restart the state machine later call Stop() instead." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Shutdown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Shutdown", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Shutdown_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Shutdown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Shutdown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Shutdown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Start_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Start_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Start the root state machine. This is a local call only and is not replicated.\n\x09 **/" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Start the root state machine. This is a local call only and is not replicated." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Start_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Start", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Start_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Start_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Start()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Start_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics
	{
		struct SMInstance_eventStartWithNewContext_Parms
		{
			UObject* Context;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventStartWithNewContext_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::NewProp_Context,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Sets a new context and starts the state machine.\n\x09 * The state machine should be stopped prior to calling.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Sets a new context and starts the state machine.\nThe state machine should be stopped prior to calling." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "StartWithNewContext", nullptr, nullptr, sizeof(SMInstance_eventStartWithNewContext_Parms), Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_StartWithNewContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_StartWithNewContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Stop_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Stop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Complete the state machine's current state and force the machine to end regardless of if the state is an end state.\n\x09 * This is a local call only and is not replicated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Complete the state machine's current state and force the machine to end regardless of if the state is an end state.\nThis is a local call only and is not replicated." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics
	{
		struct SMInstance_eventSwitchActiveState_Parms
		{
			USMStateInstance_Base* NewStateInstance;
			bool bDeactivateOtherStates;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewStateInstance;
		static void NewProp_bDeactivateOtherStates_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDeactivateOtherStates;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_NewStateInstance = { "NewStateInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSwitchActiveState_Parms, NewStateInstance), Z_Construct_UClass_USMStateInstance_Base_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_bDeactivateOtherStates_SetBit(void* Obj)
	{
		((SMInstance_eventSwitchActiveState_Parms*)Obj)->bDeactivateOtherStates = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_bDeactivateOtherStates = { "bDeactivateOtherStates", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSwitchActiveState_Parms), &Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_bDeactivateOtherStates_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_NewStateInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::NewProp_bDeactivateOtherStates,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Switch the activate state. Does not take any transition. Handles replication and requires state change authority.\n\x09 *\n\x09 * @param NewStateInstance The state to switch to. Null is accepted if you wish to deactivate all other states.\n\x09 * @param bDeactivateOtherStates If other states should be deactivated first. A state won't be deactivated if it is a super state machine to the new state.\n\x09 */" },
		{ "CPP_Default_bDeactivateOtherStates", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Switch the activate state. Does not take any transition. Handles replication and requires state change authority.\n\n@param NewStateInstance The state to switch to. Null is accepted if you wish to deactivate all other states.\n@param bDeactivateOtherStates If other states should be deactivated first. A state won't be deactivated if it is a super state machine to the new state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SwitchActiveState", nullptr, nullptr, sizeof(SMInstance_eventSwitchActiveState_Parms), Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SwitchActiveState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SwitchActiveState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics
	{
		struct SMInstance_eventSwitchActiveStateByQualifiedName_Parms
		{
			FString InFullPath;
			bool bDeactivateOtherStates;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFullPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InFullPath;
		static void NewProp_bDeactivateOtherStates_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDeactivateOtherStates;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_InFullPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_InFullPath = { "InFullPath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventSwitchActiveStateByQualifiedName_Parms, InFullPath), METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_InFullPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_InFullPath_MetaData)) };
	void Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_bDeactivateOtherStates_SetBit(void* Obj)
	{
		((SMInstance_eventSwitchActiveStateByQualifiedName_Parms*)Obj)->bDeactivateOtherStates = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_bDeactivateOtherStates = { "bDeactivateOtherStates", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventSwitchActiveStateByQualifiedName_Parms), &Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_bDeactivateOtherStates_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_InFullPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::NewProp_bDeactivateOtherStates,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Switch to a state instance by its fully qualified name in a state machine blueprint.\n\x09 * Does not take any transition. Handles replication and requires state change authority.\n\x09 * \n\x09 * A top level state name of \"Locomotion\" would be found by searching \"Locomotion\".\n\x09 * A nested state of name \"Jump\" within a \"Locomotion\" state machine would be found by \"Locomotion.Jump\".\n\x09 *\n\x09 * It is not necessary to include the \"Root\" state machine node in the search.\n\x09 *\n\x09 * The search is performed iteratively and the performance is roughly O(n) by number of nodes in the path.\n\x09 * The lookup of each state is O(1).\n\x09 *\n\x09 * @param InFullPath The full path to the node. When the state machine type is known a UI dropdown is available [Pro Only].\n\x09 * @param bDeactivateOtherStates If other states should be deactivated first. A state won't be deactivated if it is a super state machine to the new state.\n\x09 */" },
		{ "CPP_Default_bDeactivateOtherStates", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Switch to a state instance by its fully qualified name in a state machine blueprint.\nDoes not take any transition. Handles replication and requires state change authority.\n\nA top level state name of \"Locomotion\" would be found by searching \"Locomotion\".\nA nested state of name \"Jump\" within a \"Locomotion\" state machine would be found by \"Locomotion.Jump\".\n\nIt is not necessary to include the \"Root\" state machine node in the search.\n\nThe search is performed iteratively and the performance is roughly O(n) by number of nodes in the path.\nThe lookup of each state is O(1).\n\n@param InFullPath The full path to the node. When the state machine type is known a UI dropdown is available [Pro Only].\n@param bDeactivateOtherStates If other states should be deactivated first. A state won't be deactivated if it is a super state machine to the new state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "SwitchActiveStateByQualifiedName", nullptr, nullptr, sizeof(SMInstance_eventSwitchActiveStateByQualifiedName_Parms), Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics
	{
		struct SMInstance_eventTakeTransitionChain_Parms
		{
			TArray<USMTransitionInstance*> InTransitionChain;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InTransitionChain_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InTransitionChain_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InTransitionChain;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain_Inner = { "InTransitionChain", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_USMTransitionInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain = { "InTransitionChain", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTakeTransitionChain_Parms, InTransitionChain), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "DisplayName", "Success" },
	};
#endif
	void Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMInstance_eventTakeTransitionChain_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventTakeTransitionChain_Parms), &Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_InTransitionChain,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Tell the state machine to take a specific transition chain. The chain is assumed to be true and will not be\n\x09 * evaluated. There is no integrity checking to make sure the chain properly connects two states. All other\n\x09 * state change behavior is respected including requiring the previous state active.\n\x09 *\n\x09 * This method is for advanced usage and not required for normal operation.\n\x09 *\n\x09 * @param InTransitionChain The transition chain to be taken consisting of transitions and conduits.\n\x09 * @return True if the chain was taken and the state switched.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Tell the state machine to take a specific transition chain. The chain is assumed to be true and will not be\nevaluated. There is no integrity checking to make sure the chain properly connects two states. All other\nstate change behavior is respected including requiring the previous state active.\n\nThis method is for advanced usage and not required for normal operation.\n\n@param InTransitionChain The transition chain to be taken consisting of transitions and conduits.\n@return True if the chain was taken and the state switched." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "TakeTransitionChain", nullptr, nullptr, sizeof(SMInstance_eventTakeTransitionChain_Parms), Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_TakeTransitionChain()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_TakeTransitionChain_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Tick_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_Tick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTick_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Tick_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Tick_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Tick_Statics::Function_MetaDataParams[] = {
		{ "Category", "State Machine Instances" },
		{ "Comment", "/** The native tick is required to update the state machine. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The native tick is required to update the state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Tick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Tick", nullptr, nullptr, sizeof(SMInstance_eventTick_Parms), Z_Construct_UFunction_USMInstance_Tick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Tick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Tick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Tick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Tick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Tick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics
	{
		struct SMInstance_eventTryGetNestedActiveState_Parms
		{
			FSMStateInfo FoundState;
			bool bSuccess;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FoundState;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_FoundState = { "FoundState", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTryGetNestedActiveState_Parms, FoundState), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((SMInstance_eventTryGetNestedActiveState_Parms*)Obj)->bSuccess = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventTryGetNestedActiveState_Parms), &Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_FoundState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::NewProp_bSuccess,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Retrieve the lowest level single active state including all nested state machines. Returns read only information. */" },
		{ "DisplayName", "Try Get Single Nested Active State" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Retrieve the lowest level single active state including all nested state machines. Returns read only information." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "TryGetNestedActiveState", nullptr, nullptr, sizeof(SMInstance_eventTryGetNestedActiveState_Parms), Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_TryGetNestedActiveState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_TryGetNestedActiveState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics
	{
		struct SMInstance_eventTryGetStateInfo_Parms
		{
			FGuid Guid;
			FSMStateInfo StateInfo;
			bool bSuccess;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StateInfo;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTryGetStateInfo_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_StateInfo = { "StateInfo", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTryGetStateInfo_Parms, StateInfo), Z_Construct_UScriptStruct_FSMStateInfo, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((SMInstance_eventTryGetStateInfo_Parms*)Obj)->bSuccess = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventTryGetStateInfo_Parms), &Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_StateInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::NewProp_bSuccess,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly returns read only information of the state belonging to the given guid. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly returns read only information of the state belonging to the given guid. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "TryGetStateInfo", nullptr, nullptr, sizeof(SMInstance_eventTryGetStateInfo_Parms), Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_TryGetStateInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_TryGetStateInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics
	{
		struct SMInstance_eventTryGetTransitionInfo_Parms
		{
			FGuid Guid;
			FSMTransitionInfo TransitionInfo;
			bool bSuccess;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Guid;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TransitionInfo;
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_Guid_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTryGetTransitionInfo_Parms, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_Guid_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_Guid_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_TransitionInfo = { "TransitionInfo", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventTryGetTransitionInfo_Parms, TransitionInfo), Z_Construct_UScriptStruct_FSMTransitionInfo, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((SMInstance_eventTryGetTransitionInfo_Parms*)Obj)->bSuccess = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMInstance_eventTryGetTransitionInfo_Parms), &Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_Guid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_TransitionInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::NewProp_bSuccess,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Quickly returns read only information of the transition belonging to the given guid. This always executes from the primary instance. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Quickly returns read only information of the transition belonging to the given guid. This always executes from the primary instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "TryGetTransitionInfo", nullptr, nullptr, sizeof(SMInstance_eventTryGetTransitionInfo_Parms), Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_TryGetTransitionInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_TryGetTransitionInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMInstance_Update_Statics
	{
		struct SMInstance_eventUpdate_Parms
		{
			float DeltaSeconds;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaSeconds;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMInstance_Update_Statics::NewProp_DeltaSeconds = { "DeltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMInstance_eventUpdate_Parms, DeltaSeconds), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMInstance_Update_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMInstance_Update_Statics::NewProp_DeltaSeconds,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMInstance_Update_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Manual way of updating the root state machine if tick is disabled. */" },
		{ "CPP_Default_DeltaSeconds", "0.000000" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Manual way of updating the root state machine if tick is disabled." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMInstance_Update_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMInstance, nullptr, "Update", nullptr, nullptr, sizeof(SMInstance_eventUpdate_Parms), Z_Construct_UFunction_USMInstance_Update_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Update_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMInstance_Update_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMInstance_Update_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMInstance_Update()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMInstance_Update_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USMInstance_NoRegister()
	{
		return USMInstance::StaticClass();
	}
	struct Z_Construct_UClass_USMInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReplicatedReferences_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReplicatedReferences_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReplicatedReferences;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootStateMachineGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RootStateMachineGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPreStateMachineInitializedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPreStateMachineInitializedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineInitializedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineInitializedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineStartedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineStartedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineUpdatedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineUpdatedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineStoppedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineStoppedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineTransitionTakenEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineTransitionTakenEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineStateChangedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineStateChangedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateMachineStateStartedEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateMachineStateStartedEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComponentOwner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ComponentOwner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NetworkInterface_MetaData[];
#endif
		static const UE4CodeGen_Private::FInterfacePropertyParams NewProp_NetworkInterface;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootStateMachine_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RootStateMachine;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_R_StateMachineContext_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_R_StateMachineContext;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferenceOwner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReferenceOwner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateMachineClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_StateMachineClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAutoManageTime_MetaData[];
#endif
		static void NewProp_bAutoManageTime_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAutoManageTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStopOnEndState_MetaData[];
#endif
		static void NewProp_bStopOnEndState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStopOnEndState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanEverTick_MetaData[];
#endif
		static void NewProp_bCanEverTick_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanEverTick;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanTickInEditor_MetaData[];
#endif
		static void NewProp_bCanTickInEditor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanTickInEditor;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanTickWhenPaused_MetaData[];
#endif
		static void NewProp_bCanTickWhenPaused_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanTickWhenPaused;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTickRegistered_MetaData[];
#endif
		static void NewProp_bTickRegistered_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTickRegistered;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTickBeforeInitialize_MetaData[];
#endif
		static void NewProp_bTickBeforeInitialize_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTickBeforeInitialize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTickBeforeBeginPlay_MetaData[];
#endif
		static void NewProp_bTickBeforeBeginPlay_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTickBeforeBeginPlay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TickInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TickInterval;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StateHistory_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateHistory_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_StateHistory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StateHistoryMaxCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_StateHistoryMaxCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEnableLogging_MetaData[];
#endif
		static void NewProp_bEnableLogging_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnableLogging;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLogStateChange_MetaData[];
#endif
		static void NewProp_bLogStateChange_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLogStateChange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLogTransitionTaken_MetaData[];
#endif
		static void NewProp_bLogTransitionTaken_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLogTransitionTaken;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanReplicateAsReference_MetaData[];
#endif
		static void NewProp_bCanReplicateAsReference_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanReplicateAsReference;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuidRedirectMap_ValueProp;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PathGuidRedirectMap_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PathGuidRedirectMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_PathGuidRedirectMap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferenceTemplates_Inner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReferenceTemplates_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReferenceTemplates_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReferenceTemplates;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USMInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USMInstance_AreInitialStatesSetFromLoad, "AreInitialStatesSetFromLoad" }, // 3401725643
		{ &Z_Construct_UFunction_USMInstance_CanAutoManageTime, "CanAutoManageTime" }, // 471981628
		{ &Z_Construct_UFunction_USMInstance_CanEverTick, "CanEverTick" }, // 4161007471
		{ &Z_Construct_UFunction_USMInstance_CanTickOnManualUpdate, "CanTickOnManualUpdate" }, // 4139489058
		{ &Z_Construct_UFunction_USMInstance_ClearLoadedStates, "ClearLoadedStates" }, // 1983246836
		{ &Z_Construct_UFunction_USMInstance_ClearStateHistory, "ClearStateHistory" }, // 1408737105
		{ &Z_Construct_UFunction_USMInstance_EvaluateAndFindTransitionChain, "EvaluateAndFindTransitionChain" }, // 1291578657
		{ &Z_Construct_UFunction_USMInstance_EvaluateAndTakeTransitionChain, "EvaluateAndTakeTransitionChain" }, // 2063648536
		{ &Z_Construct_UFunction_USMInstance_EvaluateTransitions, "EvaluateTransitions" }, // 38027464
		{ &Z_Construct_UFunction_USMInstance_GetActiveStateGuid, "GetActiveStateGuid" }, // 3463871837
		{ &Z_Construct_UFunction_USMInstance_GetActiveStateInstance, "GetActiveStateInstance" }, // 2374145273
		{ &Z_Construct_UFunction_USMInstance_GetActiveStateName, "GetActiveStateName" }, // 1422888277
		{ &Z_Construct_UFunction_USMInstance_GetAllActiveStateGuids, "GetAllActiveStateGuids" }, // 310918647
		{ &Z_Construct_UFunction_USMInstance_GetAllActiveStateInstances, "GetAllActiveStateInstances" }, // 100051581
		{ &Z_Construct_UFunction_USMInstance_GetAllCurrentStateGuids, "GetAllCurrentStateGuids" }, // 194486786
		{ &Z_Construct_UFunction_USMInstance_GetAllReferencedInstances, "GetAllReferencedInstances" }, // 2611571
		{ &Z_Construct_UFunction_USMInstance_GetAllStateInstances, "GetAllStateInstances" }, // 692274397
		{ &Z_Construct_UFunction_USMInstance_GetAllTransitionInstances, "GetAllTransitionInstances" }, // 4145345702
		{ &Z_Construct_UFunction_USMInstance_GetComponentOwner, "GetComponentOwner" }, // 3868840581
		{ &Z_Construct_UFunction_USMInstance_GetContext, "GetContext" }, // 1215552215
		{ &Z_Construct_UFunction_USMInstance_GetGuidRedirectMap, "GetGuidRedirectMap" }, // 2291461927
		{ &Z_Construct_UFunction_USMInstance_GetMasterReferenceOwner, "GetMasterReferenceOwner" }, // 1508809854
		{ &Z_Construct_UFunction_USMInstance_GetNestedActiveStateGuid, "GetNestedActiveStateGuid" }, // 2263544582
		{ &Z_Construct_UFunction_USMInstance_GetNestedActiveStateName, "GetNestedActiveStateName" }, // 297596189
		{ &Z_Construct_UFunction_USMInstance_GetNetworkInterface, "GetNetworkInterface" }, // 2045113633
		{ &Z_Construct_UFunction_USMInstance_GetNodeInstanceByGuid, "GetNodeInstanceByGuid" }, // 1285087066
		{ &Z_Construct_UFunction_USMInstance_GetPrimaryReferenceOwner, "GetPrimaryReferenceOwner" }, // 3132597481
		{ &Z_Construct_UFunction_USMInstance_GetReferencedInstanceByGuid, "GetReferencedInstanceByGuid" }, // 389881814
		{ &Z_Construct_UFunction_USMInstance_GetReferenceOwner, "GetReferenceOwner" }, // 2967892076
		{ &Z_Construct_UFunction_USMInstance_GetRootStateMachineInstance, "GetRootStateMachineInstance" }, // 2865028128
		{ &Z_Construct_UFunction_USMInstance_GetRootStateMachineNodeInstance, "GetRootStateMachineNodeInstance" }, // 2273440652
		{ &Z_Construct_UFunction_USMInstance_GetSingleActiveStateGuid, "GetSingleActiveStateGuid" }, // 3760742361
		{ &Z_Construct_UFunction_USMInstance_GetSingleActiveStateInstance, "GetSingleActiveStateInstance" }, // 2730188930
		{ &Z_Construct_UFunction_USMInstance_GetStateHistory, "GetStateHistory" }, // 3849957570
		{ &Z_Construct_UFunction_USMInstance_GetStateHistoryMaxCount, "GetStateHistoryMaxCount" }, // 2759779564
		{ &Z_Construct_UFunction_USMInstance_GetStateInstanceByGuid, "GetStateInstanceByGuid" }, // 1426054156
		{ &Z_Construct_UFunction_USMInstance_GetStateInstanceByQualifiedName, "GetStateInstanceByQualifiedName" }, // 1005543119
		{ &Z_Construct_UFunction_USMInstance_GetStateMachineClass, "GetStateMachineClass" }, // 3148934325
		{ &Z_Construct_UFunction_USMInstance_GetStopOnEndState, "GetStopOnEndState" }, // 2404358120
		{ &Z_Construct_UFunction_USMInstance_GetTickInterval, "GetTickInterval" }, // 4271848512
		{ &Z_Construct_UFunction_USMInstance_GetTransitionInstanceByGuid, "GetTransitionInstanceByGuid" }, // 3145100152
		{ &Z_Construct_UFunction_USMInstance_HasStarted, "HasStarted" }, // 3130192865
		{ &Z_Construct_UFunction_USMInstance_Initialize, "Initialize" }, // 2298496890
		{ &Z_Construct_UFunction_USMInstance_Internal_EvaluateAndTakeTransitionChainByGuid, "Internal_EvaluateAndTakeTransitionChainByGuid" }, // 1100358743
		{ &Z_Construct_UFunction_USMInstance_Internal_EventCleanup, "Internal_EventCleanup" }, // 1643593813
		{ &Z_Construct_UFunction_USMInstance_Internal_EventUpdate, "Internal_EventUpdate" }, // 1477737690
		{ &Z_Construct_UFunction_USMInstance_Internal_Update, "Internal_Update" }, // 1471597806
		{ &Z_Construct_UFunction_USMInstance_IsActive, "IsActive" }, // 2461624586
		{ &Z_Construct_UFunction_USMInstance_IsInEndState, "IsInEndState" }, // 1267167771
		{ &Z_Construct_UFunction_USMInstance_IsInitialized, "IsInitialized" }, // 1254368168
		{ &Z_Construct_UFunction_USMInstance_IsTickable, "IsTickable" }, // 2093084529
		{ &Z_Construct_UFunction_USMInstance_IsTickableWhenPaused, "IsTickableWhenPaused" }, // 417885901
		{ &Z_Construct_UFunction_USMInstance_K2_TryGetNetworkInterface, "K2_TryGetNetworkInterface" }, // 3863643611
		{ &Z_Construct_UFunction_USMInstance_LoadFromMultipleStates, "LoadFromMultipleStates" }, // 3790379598
		{ &Z_Construct_UFunction_USMInstance_LoadFromState, "LoadFromState" }, // 1149014900
		{ &Z_Construct_UFunction_USMInstance_OnPreStateMachineInitialized, "OnPreStateMachineInitialized" }, // 3655500990
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineInitialized, "OnStateMachineInitialized" }, // 848312472
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineInitialStateLoaded, "OnStateMachineInitialStateLoaded" }, // 3446288392
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineStart, "OnStateMachineStart" }, // 1167695844
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineStateChanged, "OnStateMachineStateChanged" }, // 1698641580
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineStateStarted, "OnStateMachineStateStarted" }, // 374984380
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineStop, "OnStateMachineStop" }, // 3546532060
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineTransitionTaken, "OnStateMachineTransitionTaken" }, // 1876123575
		{ &Z_Construct_UFunction_USMInstance_OnStateMachineUpdate, "OnStateMachineUpdate" }, // 3801666792
		{ &Z_Construct_UFunction_USMInstance_PreloadAllNodeInstances, "PreloadAllNodeInstances" }, // 1713975220
		{ &Z_Construct_UFunction_USMInstance_REP_OnReplicatedReferencesLoaded, "REP_OnReplicatedReferencesLoaded" }, // 1193592304
		{ &Z_Construct_UFunction_USMInstance_ReplicatedRestart, "ReplicatedRestart" }, // 873067075
		{ &Z_Construct_UFunction_USMInstance_ReplicatedStart, "ReplicatedStart" }, // 2632640477
		{ &Z_Construct_UFunction_USMInstance_ReplicatedStop, "ReplicatedStop" }, // 2203254231
		{ &Z_Construct_UFunction_USMInstance_Restart, "Restart" }, // 3577973233
		{ &Z_Construct_UFunction_USMInstance_RunUpdateAsReference, "RunUpdateAsReference" }, // 2677354730
		{ &Z_Construct_UFunction_USMInstance_SetAutoManageTime, "SetAutoManageTime" }, // 3559483547
		{ &Z_Construct_UFunction_USMInstance_SetCanEverTick, "SetCanEverTick" }, // 1139067232
		{ &Z_Construct_UFunction_USMInstance_SetCanTickWhenPaused, "SetCanTickWhenPaused" }, // 3132853374
		{ &Z_Construct_UFunction_USMInstance_SetContext, "SetContext" }, // 74828265
		{ &Z_Construct_UFunction_USMInstance_SetGuidRedirectMap, "SetGuidRedirectMap" }, // 2330414266
		{ &Z_Construct_UFunction_USMInstance_SetStateHistoryMaxCount, "SetStateHistoryMaxCount" }, // 1299698798
		{ &Z_Construct_UFunction_USMInstance_SetStateMachineClass, "SetStateMachineClass" }, // 2016851323
		{ &Z_Construct_UFunction_USMInstance_SetStopOnEndState, "SetStopOnEndState" }, // 1115269331
		{ &Z_Construct_UFunction_USMInstance_SetTickBeforeBeginPlay, "SetTickBeforeBeginPlay" }, // 3281176324
		{ &Z_Construct_UFunction_USMInstance_SetTickInterval, "SetTickInterval" }, // 1641306261
		{ &Z_Construct_UFunction_USMInstance_SetTickOnManualUpdate, "SetTickOnManualUpdate" }, // 406059014
		{ &Z_Construct_UFunction_USMInstance_Shutdown, "Shutdown" }, // 1161223381
		{ &Z_Construct_UFunction_USMInstance_Start, "Start" }, // 2812632690
		{ &Z_Construct_UFunction_USMInstance_StartWithNewContext, "StartWithNewContext" }, // 3500348001
		{ &Z_Construct_UFunction_USMInstance_Stop, "Stop" }, // 3183071501
		{ &Z_Construct_UFunction_USMInstance_SwitchActiveState, "SwitchActiveState" }, // 758431157
		{ &Z_Construct_UFunction_USMInstance_SwitchActiveStateByQualifiedName, "SwitchActiveStateByQualifiedName" }, // 1643436977
		{ &Z_Construct_UFunction_USMInstance_TakeTransitionChain, "TakeTransitionChain" }, // 4017112691
		{ &Z_Construct_UFunction_USMInstance_Tick, "Tick" }, // 346956205
		{ &Z_Construct_UFunction_USMInstance_TryGetNestedActiveState, "TryGetNestedActiveState" }, // 3406158744
		{ &Z_Construct_UFunction_USMInstance_TryGetStateInfo, "TryGetStateInfo" }, // 820229605
		{ &Z_Construct_UFunction_USMInstance_TryGetTransitionInfo, "TryGetTransitionInfo" }, // 1904569171
		{ &Z_Construct_UFunction_USMInstance_Update, "Update" }, // 375369010
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "State Machine Instance|Tick State Machine Instance|Logging" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The base class all blueprint state machines inherit from. The compiled state machine is accessible through GetRootStateMachine().\n */" },
		{ "DisplayName", "State Machine Instance" },
		{ "HideCategories", "SMInstance" },
		{ "IncludePath", "SMInstance.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The base class all blueprint state machines inherit from. The compiled state machine is accessible through GetRootStateMachine()." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences_Inner = { "ReplicatedReferences", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMReferenceContainer, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences_MetaData[] = {
		{ "Comment", "/** Set at initialization time on the primary instance, containing all nested references. Used for reference replicated variables. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Set at initialization time on the primary instance, containing all nested references. Used for reference replicated variables." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences = { "ReplicatedReferences", "REP_OnReplicatedReferencesLoaded", (EPropertyFlags)0x0040000100002020, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, ReplicatedReferences), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachineGuid_MetaData[] = {
		{ "Comment", "/** Used to identify the root state machine during initialization. This is not a calculated value and represents the NodeGuid. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Used to identify the root state machine during initialization. This is not a calculated value and represents the NodeGuid." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachineGuid = { "RootStateMachineGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, RootStateMachineGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachineGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachineGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnPreStateMachineInitializedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/**\n\x09 * Called at the beginning of Initialize().\n\x09 * Most information will not be available at this stage other than the context.\n\x09 *\n\x09 * Warning: This will not fire when the state machine is initialized async, as\n\x09 * the broadcast is not thread safe.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called at the beginning of Initialize().\nMost information will not be available at this stage other than the context.\n\nWarning: This will not fire when the state machine is initialized async, as\nthe broadcast is not thread safe." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnPreStateMachineInitializedEvent = { "OnPreStateMachineInitializedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnPreStateMachineInitializedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnPreStateMachineInitializedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnPreStateMachineInitializedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineInitializedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called when the state machine is first initialized. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when the state machine is first initialized." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineInitializedEvent = { "OnStateMachineInitializedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineInitializedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineInitializedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineInitializedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineInitializedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStartedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called right before the state machine is started. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right before the state machine is started." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStartedEvent = { "OnStateMachineStartedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineStartedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStartedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStartedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStartedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineUpdatedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called right before the state machine is updated. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right before the state machine is updated." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineUpdatedEvent = { "OnStateMachineUpdatedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineUpdatedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineUpdatedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineUpdatedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineUpdatedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStoppedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called right after the state machine has ended. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called right after the state machine has ended." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStoppedEvent = { "OnStateMachineStoppedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineStoppedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStoppedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStoppedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStoppedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineTransitionTakenEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called when a transition has evaluated to true and is being taken. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a transition has evaluated to true and is being taken." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineTransitionTakenEvent = { "OnStateMachineTransitionTakenEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineTransitionTakenEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineTransitionTakenSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineTransitionTakenEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineTransitionTakenEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateChangedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called when a state machine has switched states. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a state machine has switched states." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateChangedEvent = { "OnStateMachineStateChangedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineStateChangedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateChangedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateChangedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateChangedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateStartedEvent_MetaData[] = {
		{ "Category", "Logic Driver|State Machine Instances" },
		{ "Comment", "/** Called when a state has started. This happens after OnStateMachineStateChanged and all previous transitions have evaluated. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Called when a state has started. This happens after OnStateMachineStateChanged and all previous transitions have evaluated." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateStartedEvent = { "OnStateMachineStateStartedEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, OnStateMachineStateStartedEvent), Z_Construct_UDelegateFunction_SMSystem_OnStateMachineStateStartedSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateStartedEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateStartedEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_ComponentOwner_MetaData[] = {
		{ "Comment", "/** The component owning this instance. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The component owning this instance." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ComponentOwner = { "ComponentOwner", nullptr, (EPropertyFlags)0x0020080000080028, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, ComponentOwner), Z_Construct_UClass_USMStateMachineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_ComponentOwner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_ComponentOwner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_NetworkInterface_MetaData[] = {
		{ "Comment", "/** Pointer to server object to notify of active transitions. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Pointer to server object to notify of active transitions." },
	};
#endif
	const UE4CodeGen_Private::FInterfacePropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_NetworkInterface = { "NetworkInterface", nullptr, (EPropertyFlags)0x0024080000000000, UE4CodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, NetworkInterface), Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_NetworkInterface_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_NetworkInterface_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachine_MetaData[] = {
		{ "Comment", "/** Top level state machine */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Top level state machine" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachine = { "RootStateMachine", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, RootStateMachine), Z_Construct_UScriptStruct_FSMStateMachine, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachine_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachine_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_R_StateMachineContext_MetaData[] = {
		{ "Comment", "/** The context to run the state machine in. */" },
		{ "DisplayName", "Context" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The context to run the state machine in." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_R_StateMachineContext = { "R_StateMachineContext", nullptr, (EPropertyFlags)0x0020080000002020, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, R_StateMachineContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_R_StateMachineContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_R_StateMachineContext_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceOwner_MetaData[] = {
		{ "Comment", "/** If this instance is owned by another instance making this a reference. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "If this instance is owned by another instance making this a reference." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceOwner = { "ReferenceOwner", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, ReferenceOwner), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceOwner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceOwner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_StateMachineClass_MetaData[] = {
		{ "BlueprintBaseOnly", "" },
		{ "Comment", "/** The custom node instance class to use for this state machine. This is not the same as USMInstance. */" },
		{ "DisplayName", "Node Class" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The custom node instance class to use for this state machine. This is not the same as USMInstance." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_StateMachineClass = { "StateMachineClass", nullptr, (EPropertyFlags)0x0024080000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, StateMachineClass), Z_Construct_UClass_USMStateMachineInstance_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_StateMachineClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_StateMachineClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime_MetaData[] = {
		{ "Category", "State Machine Instance" },
		{ "Comment", "/** Automatically calculate delta seconds if none are provided. Requires context with a valid World. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Automatically calculate delta seconds if none are provided. Requires context with a valid World." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bAutoManageTime = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime = { "bAutoManageTime", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState_MetaData[] = {
		{ "Category", "State Machine Instance" },
		{ "Comment", "/** Should this instance stop itself once an end state has been reached. An Update call is required for this to occur. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Should this instance stop itself once an end state has been reached. An Update call is required for this to occur." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bStopOnEndState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState = { "bStopOnEndState", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/** Should this instance tick. By default it will update the state machine. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Should this instance tick. By default it will update the state machine." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bCanEverTick = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick = { "bCanEverTick", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick_MetaData)) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/** Should this instance tick in editor. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Should this instance tick in editor." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bCanTickInEditor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor = { "bCanTickInEditor", nullptr, (EPropertyFlags)0x0020080800000001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/** Should this instance tick when the game is paused. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Should this instance tick when the game is paused." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bCanTickWhenPaused = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused = { "bCanTickWhenPaused", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/**\n\x09 * Setting to false physically prevents the tick function from being registered and the instance from ever ticking.\n\x09 * This is different from bCanEverTick in that it cannot be changed and it also offers slightly better performance.\n\x09 *\n\x09 * This is generally best used with non-component state machines created by CreateStateMachineInstance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Setting to false physically prevents the tick function from being registered and the instance from ever ticking.\nThis is different from bCanEverTick in that it cannot be changed and it also offers slightly better performance.\n\nThis is generally best used with non-component state machines created by CreateStateMachineInstance." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bTickRegistered = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered = { "bTickRegistered", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/**\n\x09 * Allow the state machine to tick before it is initialized.\n\x09 * This likely isn't necessary as CreateStateMachineInstance will initialize the state machine.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Allow the state machine to tick before it is initialized.\nThis likely isn't necessary as CreateStateMachineInstance will initialize the state machine." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bTickBeforeInitialize = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize = { "bTickBeforeInitialize", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "Comment", "/** When false IsTickable checks if the world has started play. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "When false IsTickable checks if the world has started play." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bTickBeforeBeginPlay = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay = { "bTickBeforeBeginPlay", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_TickInterval_MetaData[] = {
		{ "Category", "State Machine Instance|Tick" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** Time in seconds between native ticks. This mostly affects the \"Update\" rate of the state machine. Overloaded Ticks won't be affected. */" },
		{ "DisplayAfter", "bCanEverTick" },
		{ "DisplayName", "Tick Interval" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Time in seconds between native ticks. This mostly affects the \"Update\" rate of the state machine. Overloaded Ticks won't be affected." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_TickInterval = { "TickInterval", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, TickInterval), METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_TickInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_TickInterval_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory_Inner = { "StateHistory", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMStateHistory, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory_MetaData[] = {
		{ "Category", "State Machine Instance|History" },
		{ "Comment", "/** Ordered history of states, oldest to newest, not including active state(s). */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Ordered history of states, oldest to newest, not including active state(s)." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory = { "StateHistory", nullptr, (EPropertyFlags)0x0020080000020801, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, StateHistory), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistoryMaxCount_MetaData[] = {
		{ "Category", "State Machine Instance|History" },
		{ "ClampMin", "-1" },
		{ "Comment", "/** The total number of states to keep in history. Set to -1 for no limit. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "The total number of states to keep in history. Set to -1 for no limit." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistoryMaxCount = { "StateHistoryMaxCount", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, StateHistoryMaxCount), METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistoryMaxCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistoryMaxCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging_MetaData[] = {
		{ "Category", "State Machine Instance|Logging" },
		{ "Comment", "/** Enable info logging for the state machine. */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Enable info logging for the state machine." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bEnableLogging = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging = { "bEnableLogging", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange_MetaData[] = {
		{ "Category", "State Machine Instance|Logging" },
		{ "Comment", "/** Log when a state change occurs. This includes when a state machine starts or exits where transitions won't apply. */" },
		{ "EditCondition", "bEnableLogging" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Log when a state change occurs. This includes when a state machine starts or exits where transitions won't apply." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bLogStateChange = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange = { "bLogStateChange", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken_MetaData[] = {
		{ "Category", "State Machine Instance|Logging" },
		{ "Comment", "/** Log whenever a transition occurs. */" },
		{ "EditCondition", "bEnableLogging" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "Log whenever a transition occurs." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bLogTransitionTaken = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken = { "bLogTransitionTaken", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference_MetaData[] = {
		{ "Category", "State Machine Instance|Replication" },
		{ "Comment", "/**\n\x09 * If this specific instance should be replicated if it is referenced by another state machine. Requires a component\n\x09 * and proper network setup. This allows RPCs and replicated variables defined on this blueprint to work and is not\n\x09 * required just for the state machine to function on the network.\n\x09 *\n\x09 * The primary instance will always be replicated when the component replicates.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "If this specific instance should be replicated if it is referenced by another state machine. Requires a component\nand proper network setup. This allows RPCs and replicated variables defined on this blueprint to work and is not\nrequired just for the state machine to function on the network.\n\nThe primary instance will always be replicated when the component replicates." },
	};
#endif
	void Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference_SetBit(void* Obj)
	{
		((USMInstance*)Obj)->bCanReplicateAsReference = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference = { "bCanReplicateAsReference", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(USMInstance), &Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_ValueProp = { "PathGuidRedirectMap", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_Key_KeyProp = { "PathGuidRedirectMap_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_MetaData[] = {
		{ "BlueprintGetter", "GetGuidRedirectMap" },
		{ "BlueprintSetter", "SetGuidRedirectMap" },
		{ "Category", "State Machine Instance|Versioning" },
		{ "Comment", "/**\n\x09 * A map of PathGuids which should be redirected to other PathGuids. A PathGuid is the guid generated at run-time during initialization\n\x09 * which is unique per node based on the node's path in the state machine. The generated PathGuid is deterministic and has support for\n\x09 * references and parent graphs.\n\x09 *\n\x09 * Guid redirects aren't necessary unless you modify a node's path in the state machine and have to support loading data from a previous version\n\x09 * which may have used the old guids.\n\x09 */" },
		{ "DisplayName", "Guid Redirect Map" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "A map of PathGuids which should be redirected to other PathGuids. A PathGuid is the guid generated at run-time during initialization\nwhich is unique per node based on the node's path in the state machine. The generated PathGuid is deterministic and has support for\nreferences and parent graphs.\n\nGuid redirects aren't necessary unless you modify a node's path in the state machine and have to support loading data from a previous version\nwhich may have used the old guids." },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap = { "PathGuidRedirectMap", nullptr, (EPropertyFlags)0x0040000000010005, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, PathGuidRedirectMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_Inner_MetaData[] = {
		{ "Comment", "/*\n\x09 * Archetype objects used for instantiating references. Only valid from the CDO.\n\x09 * DuplicateTransient is used to prevent loading defaults in non nativized packages.\n\x09 * Cannot set Transient or CDO won't be created properly in BP Nativization. Instead\n\x09 * this value is manually cleaned on compile. \n\x09 */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "* Archetype objects used for instantiating references. Only valid from the CDO.\n* DuplicateTransient is used to prevent loading defaults in non nativized packages.\n* Cannot set Transient or CDO won't be created properly in BP Nativization. Instead\n* this value is manually cleaned on compile." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_Inner = { "ReferenceTemplates", nullptr, (EPropertyFlags)0x0002000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_Inner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_Inner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_MetaData[] = {
		{ "Comment", "/*\n\x09 * Archetype objects used for instantiating references. Only valid from the CDO.\n\x09 * DuplicateTransient is used to prevent loading defaults in non nativized packages.\n\x09 * Cannot set Transient or CDO won't be created properly in BP Nativization. Instead\n\x09 * this value is manually cleaned on compile. \n\x09 */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SMInstance.h" },
		{ "ToolTip", "* Archetype objects used for instantiating references. Only valid from the CDO.\n* DuplicateTransient is used to prevent loading defaults in non nativized packages.\n* Cannot set Transient or CDO won't be created properly in BP Nativization. Instead\n* this value is manually cleaned on compile." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates = { "ReferenceTemplates", nullptr, (EPropertyFlags)0x0010008000200008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMInstance, ReferenceTemplates), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ReplicatedReferences,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachineGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnPreStateMachineInitializedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineInitializedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStartedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineUpdatedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStoppedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineTransitionTakenEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateChangedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_OnStateMachineStateStartedEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ComponentOwner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_NetworkInterface,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_RootStateMachine,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_R_StateMachineContext,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceOwner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_StateMachineClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bAutoManageTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bStopOnEndState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bCanEverTick,
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickInEditor,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bCanTickWhenPaused,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bTickRegistered,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeInitialize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bTickBeforeBeginPlay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_TickInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_StateHistoryMaxCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bEnableLogging,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bLogStateChange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bLogTransitionTaken,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_bCanReplicateAsReference,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_PathGuidRedirectMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMInstance_Statics::NewProp_ReferenceTemplates,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USMInstance_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_USMStateMachineInterface_NoRegister, (int32)VTABLE_OFFSET(USMInstance, ISMStateMachineInterface), false },
			{ Z_Construct_UClass_USMInstanceInterface_NoRegister, (int32)VTABLE_OFFSET(USMInstance, ISMInstanceInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMInstance_Statics::ClassParams = {
		&USMInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USMInstance_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMInstance, 3236992337);
	template<> SMSYSTEM_API UClass* StaticClass<USMInstance>()
	{
		return USMInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMInstance(Z_Construct_UClass_USMInstance, &USMInstance::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMInstance"), false, nullptr, nullptr, nullptr);

	void USMInstance::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_ReplicatedReferences(TEXT("ReplicatedReferences"));
		static const FName Name_ComponentOwner(TEXT("ComponentOwner"));
		static const FName Name_R_StateMachineContext(TEXT("R_StateMachineContext"));
		static const FName Name_bAutoManageTime(TEXT("bAutoManageTime"));
		static const FName Name_bStopOnEndState(TEXT("bStopOnEndState"));
		static const FName Name_bCanEverTick(TEXT("bCanEverTick"));
		static const FName Name_bCanTickWhenPaused(TEXT("bCanTickWhenPaused"));
		static const FName Name_TickInterval(TEXT("TickInterval"));

		const bool bIsValid = true
			&& Name_ReplicatedReferences == ClassReps[(int32)ENetFields_Private::ReplicatedReferences].Property->GetFName()
			&& Name_ComponentOwner == ClassReps[(int32)ENetFields_Private::ComponentOwner].Property->GetFName()
			&& Name_R_StateMachineContext == ClassReps[(int32)ENetFields_Private::R_StateMachineContext].Property->GetFName()
			&& Name_bAutoManageTime == ClassReps[(int32)ENetFields_Private::bAutoManageTime].Property->GetFName()
			&& Name_bStopOnEndState == ClassReps[(int32)ENetFields_Private::bStopOnEndState].Property->GetFName()
			&& Name_bCanEverTick == ClassReps[(int32)ENetFields_Private::bCanEverTick].Property->GetFName()
			&& Name_bCanTickWhenPaused == ClassReps[(int32)ENetFields_Private::bCanTickWhenPaused].Property->GetFName()
			&& Name_TickInterval == ClassReps[(int32)ENetFields_Private::TickInterval].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in USMInstance"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
