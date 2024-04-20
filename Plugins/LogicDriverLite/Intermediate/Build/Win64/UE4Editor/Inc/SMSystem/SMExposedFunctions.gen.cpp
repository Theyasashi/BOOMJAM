// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/SMExposedFunctions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMExposedFunctions() {}
// Cross Module References
	SMSYSTEM_API UEnum* Z_Construct_UEnum_SMSystem_ESMConditionalEvaluationType();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UEnum* Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMExposedFunctionHandler();
	COREUOBJECT_API UClass* Z_Construct_UClass_UFunction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	static UEnum* ESMConditionalEvaluationType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SMSystem_ESMConditionalEvaluationType, Z_Construct_UPackage__Script_SMSystem(), TEXT("ESMConditionalEvaluationType"));
		}
		return Singleton;
	}
	template<> SMSYSTEM_API UEnum* StaticEnum<ESMConditionalEvaluationType>()
	{
		return ESMConditionalEvaluationType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESMConditionalEvaluationType(ESMConditionalEvaluationType_StaticEnum, TEXT("/Script/SMSystem"), TEXT("ESMConditionalEvaluationType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SMSystem_ESMConditionalEvaluationType_Hash() { return 108653176U; }
	UEnum* Z_Construct_UEnum_SMSystem_ESMConditionalEvaluationType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESMConditionalEvaluationType"), 0, Get_Z_Construct_UEnum_SMSystem_ESMConditionalEvaluationType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESMConditionalEvaluationType::SM_Graph", (int64)ESMConditionalEvaluationType::SM_Graph },
				{ "ESMConditionalEvaluationType::SM_NodeInstance", (int64)ESMConditionalEvaluationType::SM_NodeInstance },
				{ "ESMConditionalEvaluationType::SM_AlwaysFalse", (int64)ESMConditionalEvaluationType::SM_AlwaysFalse },
				{ "ESMConditionalEvaluationType::SM_AlwaysTrue", (int64)ESMConditionalEvaluationType::SM_AlwaysTrue },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
				{ "SM_AlwaysFalse.Comment", "// Node instance only \n" },
				{ "SM_AlwaysFalse.Name", "ESMConditionalEvaluationType::SM_AlwaysFalse" },
				{ "SM_AlwaysFalse.ToolTip", "Node instance only" },
				{ "SM_AlwaysTrue.Comment", "// Never eval graph and never take conditionally\n" },
				{ "SM_AlwaysTrue.Name", "ESMConditionalEvaluationType::SM_AlwaysTrue" },
				{ "SM_AlwaysTrue.ToolTip", "Never eval graph and never take conditionally" },
				{ "SM_Graph.Name", "ESMConditionalEvaluationType::SM_Graph" },
				{ "SM_NodeInstance.Comment", "// BP Graph eval required\n" },
				{ "SM_NodeInstance.Name", "ESMConditionalEvaluationType::SM_NodeInstance" },
				{ "SM_NodeInstance.ToolTip", "BP Graph eval required" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SMSystem,
				nullptr,
				"ESMConditionalEvaluationType",
				"ESMConditionalEvaluationType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ESMExposedFunctionExecutionType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType, Z_Construct_UPackage__Script_SMSystem(), TEXT("ESMExposedFunctionExecutionType"));
		}
		return Singleton;
	}
	template<> SMSYSTEM_API UEnum* StaticEnum<ESMExposedFunctionExecutionType>()
	{
		return ESMExposedFunctionExecutionType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESMExposedFunctionExecutionType(ESMExposedFunctionExecutionType_StaticEnum, TEXT("/Script/SMSystem"), TEXT("ESMExposedFunctionExecutionType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType_Hash() { return 980155091U; }
	UEnum* Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESMExposedFunctionExecutionType"), 0, Get_Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESMExposedFunctionExecutionType::SM_Graph", (int64)ESMExposedFunctionExecutionType::SM_Graph },
				{ "ESMExposedFunctionExecutionType::SM_NodeInstance", (int64)ESMExposedFunctionExecutionType::SM_NodeInstance },
				{ "ESMExposedFunctionExecutionType::SM_None", (int64)ESMExposedFunctionExecutionType::SM_None },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
				{ "SM_Graph.Name", "ESMExposedFunctionExecutionType::SM_Graph" },
				{ "SM_NodeInstance.Comment", "// BP Graph eval required\n" },
				{ "SM_NodeInstance.Name", "ESMExposedFunctionExecutionType::SM_NodeInstance" },
				{ "SM_NodeInstance.ToolTip", "BP Graph eval required" },
				{ "SM_None.Comment", "// Node instance only\n" },
				{ "SM_None.Name", "ESMExposedFunctionExecutionType::SM_None" },
				{ "SM_None.ToolTip", "Node instance only" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SMSystem,
				nullptr,
				"ESMExposedFunctionExecutionType",
				"ESMExposedFunctionExecutionType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FSMExposedFunctionHandler::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMExposedFunctionHandler, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMExposedFunctionHandler"), sizeof(FSMExposedFunctionHandler), Get_Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMExposedFunctionHandler>()
{
	return FSMExposedFunctionHandler::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMExposedFunctionHandler(FSMExposedFunctionHandler::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMExposedFunctionHandler"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMExposedFunctionHandler
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMExposedFunctionHandler()
	{
		UScriptStruct::DeferCppStructOps<FSMExposedFunctionHandler>(FName(TEXT("SMExposedFunctionHandler")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMExposedFunctionHandler;
	struct Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoundFunction_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BoundFunction;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ExecutionType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExecutionType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ExecutionType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Function;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnerObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwnerObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Handles execution of functions exposed in blueprint graphs.\n * This is often wrapped in a TArray to reduce struct memory offsets\n * for garbage collection.\n */" },
		{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
		{ "ToolTip", "Handles execution of functions exposed in blueprint graphs.\nThis is often wrapped in a TArray to reduce struct memory offsets\nfor garbage collection." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMExposedFunctionHandler>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_BoundFunction_MetaData[] = {
		{ "Comment", "/** Name of the graph function we will be evaluating. */" },
		{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
		{ "ToolTip", "Name of the graph function we will be evaluating." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_BoundFunction = { "BoundFunction", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMExposedFunctionHandler, BoundFunction), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_BoundFunction_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_BoundFunction_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType_MetaData[] = {
		{ "Comment", "/** The type of execution for this function. */" },
		{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
		{ "ToolTip", "The type of execution for this function." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType = { "ExecutionType", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMExposedFunctionHandler, ExecutionType), Z_Construct_UEnum_SMSystem_ESMExposedFunctionExecutionType, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_Function_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMExposedFunctionHandler, Function), Z_Construct_UClass_UFunction, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_Function_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_Function_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_OwnerObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMExposedFunctions.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_OwnerObject = { "OwnerObject", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMExposedFunctionHandler, OwnerObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_OwnerObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_OwnerObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_BoundFunction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_ExecutionType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_Function,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::NewProp_OwnerObject,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMExposedFunctionHandler",
		sizeof(FSMExposedFunctionHandler),
		alignof(FSMExposedFunctionHandler),
		Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMExposedFunctionHandler()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMExposedFunctionHandler"), sizeof(FSMExposedFunctionHandler), Get_Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMExposedFunctionHandler_Hash() { return 3899784723U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
