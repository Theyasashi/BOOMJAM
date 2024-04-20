// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/States/SMConduitInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMConduitInstance() {}
// Cross Module References
	SMSYSTEM_API UClass* Z_Construct_UClass_USMConduitInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMConduitInstance();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateInstance_Base();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
// End Cross Module References
	DEFINE_FUNCTION(USMConduitInstance::execSetEvalWithTransitions)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEvalWithTransitions(Z_Param_bValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMConduitInstance::execGetEvalWithTransitions)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetEvalWithTransitions();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMConduitInstance::execGetCanEvaluate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetCanEvaluate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMConduitInstance::execSetCanEvaluate)
	{
		P_GET_UBOOL(Z_Param_bValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCanEvaluate(Z_Param_bValue);
		P_NATIVE_END;
	}
	void USMConduitInstance::StaticRegisterNativesUSMConduitInstance()
	{
		UClass* Class = USMConduitInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCanEvaluate", &USMConduitInstance::execGetCanEvaluate },
			{ "GetEvalWithTransitions", &USMConduitInstance::execGetEvalWithTransitions },
			{ "SetCanEvaluate", &USMConduitInstance::execSetCanEvaluate },
			{ "SetEvalWithTransitions", &USMConduitInstance::execSetEvalWithTransitions },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics
	{
		struct SMConduitInstance_eventGetCanEvaluate_Parms
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
	void Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMConduitInstance_eventGetCanEvaluate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMConduitInstance_eventGetCanEvaluate_Parms), &Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Check whether this node is allowed to evaluate. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "Check whether this node is allowed to evaluate." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMConduitInstance, nullptr, "GetCanEvaluate", nullptr, nullptr, sizeof(SMConduitInstance_eventGetCanEvaluate_Parms), Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics
	{
		struct SMConduitInstance_eventGetEvalWithTransitions_Parms
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
	void Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMConduitInstance_eventGetEvalWithTransitions_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMConduitInstance_eventGetEvalWithTransitions_Parms), &Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public getter for #bEvalWithTransitions. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "Public getter for #bEvalWithTransitions." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMConduitInstance, nullptr, "GetEvalWithTransitions", nullptr, nullptr, sizeof(SMConduitInstance_eventGetEvalWithTransitions_Parms), Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics
	{
		struct SMConduitInstance_eventSetCanEvaluate_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMConduitInstance_eventSetCanEvaluate_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMConduitInstance_eventSetCanEvaluate_Parms), &Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Sets whether this node is allowed to evaluate or not. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "Sets whether this node is allowed to evaluate or not." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMConduitInstance, nullptr, "SetCanEvaluate", nullptr, nullptr, sizeof(SMConduitInstance_eventSetCanEvaluate_Parms), Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics
	{
		struct SMConduitInstance_eventSetEvalWithTransitions_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue_SetBit(void* Obj)
	{
		((SMConduitInstance_eventSetEvalWithTransitions_Parms*)Obj)->bValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMConduitInstance_eventSetEvalWithTransitions_Parms), &Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::NewProp_bValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Defaults" },
		{ "Comment", "/** Public setter for #bEvalWithTransitions. */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "Public setter for #bEvalWithTransitions." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMConduitInstance, nullptr, "SetEvalWithTransitions", nullptr, nullptr, sizeof(SMConduitInstance_eventSetEvalWithTransitions_Parms), Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USMConduitInstance_NoRegister()
	{
		return USMConduitInstance::StaticClass();
	}
	struct Z_Construct_UClass_USMConduitInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEvalWithTransitions_MetaData[];
#endif
		static void NewProp_bEvalWithTransitions_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEvalWithTransitions;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCanEvaluate_MetaData[];
#endif
		static void NewProp_bCanEvaluate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCanEvaluate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMConduitInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USMStateInstance_Base,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USMConduitInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USMConduitInstance_GetCanEvaluate, "GetCanEvaluate" }, // 1688943973
		{ &Z_Construct_UFunction_USMConduitInstance_GetEvalWithTransitions, "GetEvalWithTransitions" }, // 2013624377
		{ &Z_Construct_UFunction_USMConduitInstance_SetCanEvaluate, "SetCanEvaluate" }, // 3084252674
		{ &Z_Construct_UFunction_USMConduitInstance_SetEvalWithTransitions, "SetEvalWithTransitions" }, // 943949839
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMConduitInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The base class for conduit nodes.\n */" },
		{ "DisplayName", "Conduit Class" },
		{ "HideCategories", "SMConduitInstance SMStateInstance_Base SMNodeInstance" },
		{ "IncludePath", "Nodes/States/SMConduitInstance.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "The base class for conduit nodes." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions_MetaData[] = {
		{ "Category", "Conduit" },
		{ "Comment", "/**\n\x09 * This conduit will be evaluated with inbound and outbound transitions.\n\x09 * If any transition fails the entire transition fails. In that case the\n\x09 * state leading to this conduit will not take this transition.\n\x09 *\n\x09 * This makes the behavior similar to AnimGraph conduits.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "This conduit will be evaluated with inbound and outbound transitions.\nIf any transition fails the entire transition fails. In that case the\nstate leading to this conduit will not take this transition.\n\nThis makes the behavior similar to AnimGraph conduits." },
	};
#endif
	void Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions_SetBit(void* Obj)
	{
		((USMConduitInstance*)Obj)->bEvalWithTransitions = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions = { "bEvalWithTransitions", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMConduitInstance), &Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate_MetaData[] = {
		{ "Category", "Conduit" },
		{ "Comment", "/**\n\x09 * If this conduit is allowed to evaluate.\n\x09 */" },
		{ "DisplayName", "Can Evaluate" },
		{ "ModuleRelativePath", "Public/Nodes/States/SMConduitInstance.h" },
		{ "ToolTip", "If this conduit is allowed to evaluate." },
	};
#endif
	void Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate_SetBit(void* Obj)
	{
		((USMConduitInstance*)Obj)->bCanEvaluate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate = { "bCanEvaluate", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USMConduitInstance), &Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMConduitInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bEvalWithTransitions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMConduitInstance_Statics::NewProp_bCanEvaluate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMConduitInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMConduitInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMConduitInstance_Statics::ClassParams = {
		&USMConduitInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USMConduitInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USMConduitInstance_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USMConduitInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMConduitInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMConduitInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMConduitInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMConduitInstance, 2296309643);
	template<> SMSYSTEM_API UClass* StaticClass<USMConduitInstance>()
	{
		return USMConduitInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMConduitInstance(Z_Construct_UClass_USMConduitInstance, &USMConduitInstance::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMConduitInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMConduitInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
