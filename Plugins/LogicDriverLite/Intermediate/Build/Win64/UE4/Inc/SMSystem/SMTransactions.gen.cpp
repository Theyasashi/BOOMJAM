// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/SMTransactions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMTransactions() {}
// Cross Module References
	SMSYSTEM_API UEnum* Z_Construct_UEnum_SMSystem_ESMTransactionType();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMFullSyncTransaction();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMTransaction_Base();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMFullSyncStateTransaction();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMActivateStateTransaction();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMTransitionTransaction();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMInitializeTransaction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	static UEnum* ESMTransactionType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SMSystem_ESMTransactionType, Z_Construct_UPackage__Script_SMSystem(), TEXT("ESMTransactionType"));
		}
		return Singleton;
	}
	template<> SMSYSTEM_API UEnum* StaticEnum<ESMTransactionType>()
	{
		return ESMTransactionType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESMTransactionType(ESMTransactionType_StaticEnum, TEXT("/Script/SMSystem"), TEXT("ESMTransactionType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SMSystem_ESMTransactionType_Hash() { return 3088780597U; }
	UEnum* Z_Construct_UEnum_SMSystem_ESMTransactionType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESMTransactionType"), 0, Get_Z_Construct_UEnum_SMSystem_ESMTransactionType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESMTransactionType::SM_Unknown", (int64)ESMTransactionType::SM_Unknown },
				{ "ESMTransactionType::SM_Transition", (int64)ESMTransactionType::SM_Transition },
				{ "ESMTransactionType::SM_State", (int64)ESMTransactionType::SM_State },
				{ "ESMTransactionType::SM_FullSync", (int64)ESMTransactionType::SM_FullSync },
				{ "ESMTransactionType::SM_Start", (int64)ESMTransactionType::SM_Start },
				{ "ESMTransactionType::SM_Stop", (int64)ESMTransactionType::SM_Stop },
				{ "ESMTransactionType::SM_Initialize", (int64)ESMTransactionType::SM_Initialize },
				{ "ESMTransactionType::SM_Shutdown", (int64)ESMTransactionType::SM_Shutdown },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/SMTransactions.h" },
				{ "SM_FullSync.Name", "ESMTransactionType::SM_FullSync" },
				{ "SM_Initialize.Name", "ESMTransactionType::SM_Initialize" },
				{ "SM_Shutdown.Name", "ESMTransactionType::SM_Shutdown" },
				{ "SM_Start.Name", "ESMTransactionType::SM_Start" },
				{ "SM_State.Name", "ESMTransactionType::SM_State" },
				{ "SM_Stop.Name", "ESMTransactionType::SM_Stop" },
				{ "SM_Transition.Name", "ESMTransactionType::SM_Transition" },
				{ "SM_Unknown.Name", "ESMTransactionType::SM_Unknown" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SMSystem,
				nullptr,
				"ESMTransactionType",
				"ESMTransactionType",
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

static_assert(std::is_polymorphic<FSMFullSyncTransaction>() == std::is_polymorphic<FSMTransaction_Base>(), "USTRUCT FSMFullSyncTransaction cannot be polymorphic unless super FSMTransaction_Base is polymorphic");

class UScriptStruct* FSMFullSyncTransaction::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncTransaction_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMFullSyncTransaction, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMFullSyncTransaction"), sizeof(FSMFullSyncTransaction), Get_Z_Construct_UScriptStruct_FSMFullSyncTransaction_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMFullSyncTransaction>()
{
	return FSMFullSyncTransaction::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMFullSyncTransaction(FSMFullSyncTransaction::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMFullSyncTransaction"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncTransaction
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncTransaction()
	{
		UScriptStruct::DeferCppStructOps<FSMFullSyncTransaction>(FName(TEXT("SMFullSyncTransaction")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncTransaction;
	struct Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActiveStates_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveStates_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActiveStates;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasStarted_MetaData[];
#endif
		static void NewProp_bHasStarted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasStarted;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bFromUserLoad_MetaData[];
#endif
		static void NewProp_bFromUserLoad_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromUserLoad;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Use for syncing the complete state of a state machine. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Use for syncing the complete state of a state machine." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMFullSyncTransaction>();
	}
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates_Inner = { "ActiveStates", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSMFullSyncStateTransaction, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates_MetaData[] = {
		{ "Comment", "/** All states which should be active. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "All states which should be active." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates = { "ActiveStates", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMFullSyncTransaction, ActiveStates), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted_MetaData[] = {
		{ "Comment", "/** Has the state machine started already. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Has the state machine started already." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted_SetBit(void* Obj)
	{
		((FSMFullSyncTransaction*)Obj)->bHasStarted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted = { "bHasStarted", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMFullSyncTransaction), &Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad_MetaData[] = {
		{ "Comment", "/**\n\x09 * User has specified to load these states by calling LoadFromState.\n\x09 * Consider removing and instead relying on a 'start' transaction with guids.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "User has specified to load these states by calling LoadFromState.\nConsider removing and instead relying on a 'start' transaction with guids." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad_SetBit(void* Obj)
	{
		((FSMFullSyncTransaction*)Obj)->bFromUserLoad = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad = { "bFromUserLoad", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMFullSyncTransaction), &Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_ActiveStates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bHasStarted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::NewProp_bFromUserLoad,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMTransaction_Base,
		&NewStructOps,
		"SMFullSyncTransaction",
		sizeof(FSMFullSyncTransaction),
		alignof(FSMFullSyncTransaction),
		Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMFullSyncTransaction()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncTransaction_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMFullSyncTransaction"), sizeof(FSMFullSyncTransaction), Get_Z_Construct_UScriptStruct_FSMFullSyncTransaction_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMFullSyncTransaction_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncTransaction_Hash() { return 907927426U; }

static_assert(std::is_polymorphic<FSMFullSyncStateTransaction>() == std::is_polymorphic<FSMTransaction_Base>(), "USTRUCT FSMFullSyncStateTransaction cannot be polymorphic unless super FSMTransaction_Base is polymorphic");

class UScriptStruct* FSMFullSyncStateTransaction::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMFullSyncStateTransaction"), sizeof(FSMFullSyncStateTransaction), Get_Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMFullSyncStateTransaction>()
{
	return FSMFullSyncStateTransaction::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMFullSyncStateTransaction(FSMFullSyncStateTransaction::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMFullSyncStateTransaction"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncStateTransaction
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncStateTransaction()
	{
		UScriptStruct::DeferCppStructOps<FSMFullSyncStateTransaction>(FName(TEXT("SMFullSyncStateTransaction")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMFullSyncStateTransaction;
	struct Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BaseGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeInState_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeInState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Use for syncing the complete state of a state machine. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Use for syncing the complete state of a state machine." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMFullSyncStateTransaction>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_BaseGuid_MetaData[] = {
		{ "Comment", "/** The node path guid. */" },
		{ "IgnoreForMemberInitializationTest", "" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "The node path guid." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_BaseGuid = { "BaseGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMFullSyncStateTransaction, BaseGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_BaseGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_BaseGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_TimeInState_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_TimeInState = { "TimeInState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMFullSyncStateTransaction, TimeInState), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_TimeInState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_TimeInState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_BaseGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::NewProp_TimeInState,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMTransaction_Base,
		&NewStructOps,
		"SMFullSyncStateTransaction",
		sizeof(FSMFullSyncStateTransaction),
		alignof(FSMFullSyncStateTransaction),
		Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMFullSyncStateTransaction()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMFullSyncStateTransaction"), sizeof(FSMFullSyncStateTransaction), Get_Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMFullSyncStateTransaction_Hash() { return 2591608223U; }

static_assert(std::is_polymorphic<FSMActivateStateTransaction>() == std::is_polymorphic<FSMTransaction_Base>(), "USTRUCT FSMActivateStateTransaction cannot be polymorphic unless super FSMTransaction_Base is polymorphic");

class UScriptStruct* FSMActivateStateTransaction::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMActivateStateTransaction_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMActivateStateTransaction, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMActivateStateTransaction"), sizeof(FSMActivateStateTransaction), Get_Z_Construct_UScriptStruct_FSMActivateStateTransaction_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMActivateStateTransaction>()
{
	return FSMActivateStateTransaction::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMActivateStateTransaction(FSMActivateStateTransaction::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMActivateStateTransaction"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMActivateStateTransaction
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMActivateStateTransaction()
	{
		UScriptStruct::DeferCppStructOps<FSMActivateStateTransaction>(FName(TEXT("SMActivateStateTransaction")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMActivateStateTransaction;
	struct Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BaseGuid;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeInState_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeInState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[];
#endif
		static void NewProp_bIsActive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSetAllParents_MetaData[];
#endif
		static void NewProp_bSetAllParents_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSetAllParents;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** States that need their active flag changed. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "States that need their active flag changed." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMActivateStateTransaction>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_BaseGuid_MetaData[] = {
		{ "Comment", "/** The node path guid. */" },
		{ "IgnoreForMemberInitializationTest", "" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "The node path guid." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_BaseGuid = { "BaseGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMActivateStateTransaction, BaseGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_BaseGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_BaseGuid_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_TimeInState_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_TimeInState = { "TimeInState", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMActivateStateTransaction, TimeInState), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_TimeInState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_TimeInState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive_SetBit(void* Obj)
	{
		((FSMActivateStateTransaction*)Obj)->bIsActive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMActivateStateTransaction), &Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents_SetBit(void* Obj)
	{
		((FSMActivateStateTransaction*)Obj)->bSetAllParents = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents = { "bSetAllParents", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMActivateStateTransaction), &Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_BaseGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_TimeInState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bIsActive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::NewProp_bSetAllParents,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMTransaction_Base,
		&NewStructOps,
		"SMActivateStateTransaction",
		sizeof(FSMActivateStateTransaction),
		alignof(FSMActivateStateTransaction),
		Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMActivateStateTransaction()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMActivateStateTransaction_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMActivateStateTransaction"), sizeof(FSMActivateStateTransaction), Get_Z_Construct_UScriptStruct_FSMActivateStateTransaction_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMActivateStateTransaction_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMActivateStateTransaction_Hash() { return 2007821893U; }

static_assert(std::is_polymorphic<FSMTransitionTransaction>() == std::is_polymorphic<FSMTransaction_Base>(), "USTRUCT FSMTransitionTransaction cannot be polymorphic unless super FSMTransaction_Base is polymorphic");

class UScriptStruct* FSMTransitionTransaction::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMTransitionTransaction_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMTransitionTransaction, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMTransitionTransaction"), sizeof(FSMTransitionTransaction), Get_Z_Construct_UScriptStruct_FSMTransitionTransaction_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMTransitionTransaction>()
{
	return FSMTransitionTransaction::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMTransitionTransaction(FSMTransitionTransaction::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMTransitionTransaction"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMTransitionTransaction
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMTransitionTransaction()
	{
		UScriptStruct::DeferCppStructOps<FSMTransitionTransaction>(FName(TEXT("SMTransitionTransaction")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMTransitionTransaction;
	struct Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BaseGuid;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AdditionalGuids_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AdditionalGuids_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AdditionalGuids;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Timestamp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ActiveTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Transition data to send across the network. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Transition data to send across the network." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMTransitionTransaction>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_BaseGuid_MetaData[] = {
		{ "Comment", "/** The node path guid. */" },
		{ "IgnoreForMemberInitializationTest", "" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "The node path guid." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_BaseGuid = { "BaseGuid", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMTransitionTransaction, BaseGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_BaseGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_BaseGuid_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids_Inner = { "AdditionalGuids", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids_MetaData[] = {
		{ "Comment", "/**\n\x09 * Additional guids for a transaction. For transitions this can be source and destination states.\n\x09 * When using conduits that information may be required and can't be calculated from a single transition.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Additional guids for a transaction. For transitions this can be source and destination states.\nWhen using conduits that information may be required and can't be calculated from a single transition." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids = { "AdditionalGuids", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMTransitionTransaction, AdditionalGuids), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Comment", "/** A UTC timestamp. Should be set manually. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "A UTC timestamp. Should be set manually." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMTransitionTransaction, Timestamp), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_Timestamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_Timestamp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_ActiveTime_MetaData[] = {
		{ "Comment", "/** Source state's time in state. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Source state's time in state." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_ActiveTime = { "ActiveTime", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMTransitionTransaction, ActiveTime), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_ActiveTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_ActiveTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_BaseGuid,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_AdditionalGuids,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_Timestamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::NewProp_ActiveTime,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMTransaction_Base,
		&NewStructOps,
		"SMTransitionTransaction",
		sizeof(FSMTransitionTransaction),
		alignof(FSMTransitionTransaction),
		Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMTransitionTransaction()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMTransitionTransaction_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMTransitionTransaction"), sizeof(FSMTransitionTransaction), Get_Z_Construct_UScriptStruct_FSMTransitionTransaction_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMTransitionTransaction_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMTransitionTransaction_Hash() { return 3934223639U; }

static_assert(std::is_polymorphic<FSMInitializeTransaction>() == std::is_polymorphic<FSMTransaction_Base>(), "USTRUCT FSMInitializeTransaction cannot be polymorphic unless super FSMTransaction_Base is polymorphic");

class UScriptStruct* FSMInitializeTransaction::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMInitializeTransaction_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMInitializeTransaction, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMInitializeTransaction"), sizeof(FSMInitializeTransaction), Get_Z_Construct_UScriptStruct_FSMInitializeTransaction_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMInitializeTransaction>()
{
	return FSMInitializeTransaction::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMInitializeTransaction(FSMInitializeTransaction::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMInitializeTransaction"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMInitializeTransaction
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMInitializeTransaction()
	{
		UScriptStruct::DeferCppStructOps<FSMInitializeTransaction>(FName(TEXT("SMInitializeTransaction")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMInitializeTransaction;
	struct Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Notify of initialization. */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "Notify of initialization." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMInitializeTransaction>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewProp_Context_MetaData[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMInitializeTransaction, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewProp_Context_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::NewProp_Context,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		Z_Construct_UScriptStruct_FSMTransaction_Base,
		&NewStructOps,
		"SMInitializeTransaction",
		sizeof(FSMInitializeTransaction),
		alignof(FSMInitializeTransaction),
		Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMInitializeTransaction()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMInitializeTransaction_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMInitializeTransaction"), sizeof(FSMInitializeTransaction), Get_Z_Construct_UScriptStruct_FSMInitializeTransaction_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMInitializeTransaction_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMInitializeTransaction_Hash() { return 4294824729U; }
class UScriptStruct* FSMTransaction_Base::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMTransaction_Base_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMTransaction_Base, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMTransaction_Base"), sizeof(FSMTransaction_Base), Get_Z_Construct_UScriptStruct_FSMTransaction_Base_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMTransaction_Base>()
{
	return FSMTransaction_Base::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMTransaction_Base(FSMTransaction_Base::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMTransaction_Base"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMTransaction_Base
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMTransaction_Base()
	{
		UScriptStruct::DeferCppStructOps<FSMTransaction_Base>(FName(TEXT("SMTransaction_Base")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMTransaction_Base;
	struct Z_Construct_UScriptStruct_FSMTransaction_Base_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_TransactionType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TransactionType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_TransactionType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bOriginatedFromServer_MetaData[];
#endif
		static void NewProp_bOriginatedFromServer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bOriginatedFromServer;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMTransaction_Base>();
	}
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType_MetaData[] = {
		{ "Comment", "/**\n\x09 * The type of transaction, set automatically if required.\n\x09 * It might be possible to always calculate this locally through RPC rather than send it.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "The type of transaction, set automatically if required.\nIt might be possible to always calculate this locally through RPC rather than send it." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType = { "TransactionType", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMTransaction_Base, TransactionType), Z_Construct_UEnum_SMSystem_ESMTransactionType, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer_MetaData[] = {
		{ "Comment", "/**\n\x09 * If the server made the decision to send this transaction. Used to distinguish multicast calls that can be\n\x09 * executed from both the owning client or the server.\n\x09 * TODO: If we switch to direct channel updates this could likely go away, or may need to be replaced by an ID.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SMTransactions.h" },
		{ "ToolTip", "If the server made the decision to send this transaction. Used to distinguish multicast calls that can be\nexecuted from both the owning client or the server.\nTODO: If we switch to direct channel updates this could likely go away, or may need to be replaced by an ID." },
	};
#endif
	void Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer_SetBit(void* Obj)
	{
		((FSMTransaction_Base*)Obj)->bOriginatedFromServer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer = { "bOriginatedFromServer", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FSMTransaction_Base), &Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_TransactionType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::NewProp_bOriginatedFromServer,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMTransaction_Base",
		sizeof(FSMTransaction_Base),
		alignof(FSMTransaction_Base),
		Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMTransaction_Base()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMTransaction_Base_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMTransaction_Base"), sizeof(FSMTransaction_Base), Get_Z_Construct_UScriptStruct_FSMTransaction_Base_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMTransaction_Base_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMTransaction_Base_Hash() { return 2231609012U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
