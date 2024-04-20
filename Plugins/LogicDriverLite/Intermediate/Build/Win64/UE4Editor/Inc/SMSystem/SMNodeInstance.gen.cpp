// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SMSystem/Public/Nodes/SMNodeInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMNodeInstance() {}
// Cross Module References
	SMSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSMNodeDescription();
	UPackage* Z_Construct_UPackage__Script_SMSystem();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMNodeInstance();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMStateMachineInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstance_NoRegister();
	SMSYSTEM_API UClass* Z_Construct_UClass_USMInstanceInterface_NoRegister();
// End Cross Module References
class UScriptStruct* FSMNodeDescription::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SMSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSMNodeDescription_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSMNodeDescription, Z_Construct_UPackage__Script_SMSystem(), TEXT("SMNodeDescription"), sizeof(FSMNodeDescription), Get_Z_Construct_UScriptStruct_FSMNodeDescription_Hash());
	}
	return Singleton;
}
template<> SMSYSTEM_API UScriptStruct* StaticStruct<FSMNodeDescription>()
{
	return FSMNodeDescription::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSMNodeDescription(FSMNodeDescription::StaticStruct, TEXT("/Script/SMSystem"), TEXT("SMNodeDescription"), false, nullptr, nullptr);
static struct FScriptStruct_SMSystem_StaticRegisterNativesFSMNodeDescription
{
	FScriptStruct_SMSystem_StaticRegisterNativesFSMNodeDescription()
	{
		UScriptStruct::DeferCppStructOps<FSMNodeDescription>(FName(TEXT("SMNodeDescription")));
	}
} ScriptStruct_SMSystem_StaticRegisterNativesFSMNodeDescription;
	struct Z_Construct_UScriptStruct_FSMNodeDescription_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Category;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Description;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNodeDescription_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * This information will be viewable when selecting new nodes or hovering over nodes.\n */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "This information will be viewable when selecting new nodes or hovering over nodes." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSMNodeDescription>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** The name of this node type. */" },
		{ "InstancedTemplate", "" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "The name of this node type." },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNodeDescription, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Category_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** Which category this should fall under. */" },
		{ "InstancedTemplate", "" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Which category this should fall under." },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNodeDescription, Category), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Category_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Category_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** The tooltip when selecting the action. */" },
		{ "InstancedTemplate", "" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "MultiLine", "TRUE" },
		{ "ToolTip", "The tooltip when selecting the action." },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMNodeDescription, Description), METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Description_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSMNodeDescription_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Category,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSMNodeDescription_Statics::NewProp_Description,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSMNodeDescription_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
		nullptr,
		&NewStructOps,
		"SMNodeDescription",
		sizeof(FSMNodeDescription),
		alignof(FSMNodeDescription),
		Z_Construct_UScriptStruct_FSMNodeDescription_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSMNodeDescription_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSMNodeDescription()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSMNodeDescription_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SMSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SMNodeDescription"), sizeof(FSMNodeDescription), Get_Z_Construct_UScriptStruct_FSMNodeDescription_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSMNodeDescription_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSMNodeDescription_Hash() { return 2853034204U; }
	DEFINE_FUNCTION(USMNodeInstance::execGetGuid)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGuid*)Z_Param__Result=P_THIS->GetGuid();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetNodeName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNodeName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execIsActive)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsActive();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execHasUpdated)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasUpdated();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execIsInEndState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInEndState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetTimeInState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetTimeInState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetNetworkInterface)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TScriptInterface<ISMStateMachineNetworkedInterface>*)Z_Param__Result=P_THIS->GetNetworkInterface();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetOwningStateMachineNodeInstance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMStateMachineInstance**)Z_Param__Result=P_THIS->GetOwningStateMachineNodeInstance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetStateMachineInstance)
	{
		P_GET_UBOOL(Z_Param_bTopMostInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USMInstance**)Z_Param__Result=P_THIS->GetStateMachineInstance(Z_Param_bTopMostInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USMNodeInstance::execGetContext)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetContext();
		P_NATIVE_END;
	}
	void USMNodeInstance::StaticRegisterNativesUSMNodeInstance()
	{
		UClass* Class = USMNodeInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetContext", &USMNodeInstance::execGetContext },
			{ "GetGuid", &USMNodeInstance::execGetGuid },
			{ "GetNetworkInterface", &USMNodeInstance::execGetNetworkInterface },
			{ "GetNodeName", &USMNodeInstance::execGetNodeName },
			{ "GetOwningStateMachineNodeInstance", &USMNodeInstance::execGetOwningStateMachineNodeInstance },
			{ "GetStateMachineInstance", &USMNodeInstance::execGetStateMachineInstance },
			{ "GetTimeInState", &USMNodeInstance::execGetTimeInState },
			{ "HasUpdated", &USMNodeInstance::execHasUpdated },
			{ "IsActive", &USMNodeInstance::execIsActive },
			{ "IsInEndState", &USMNodeInstance::execIsInEndState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetContext_Statics
	{
		struct SMNodeInstance_eventGetContext_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetContext_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The object which this node is running for. Determined by the owning state machine. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "The object which this node is running for. Determined by the owning state machine." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetContext", nullptr, nullptr, sizeof(SMNodeInstance_eventGetContext_Parms), Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetContext()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetContext_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics
	{
		struct SMNodeInstance_eventGetGuid_Parms
		{
			FGuid ReturnValue;
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetGuid_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Unique identifier taking into account qualified path. Unique across blueprints if called after Instance initialization. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Unique identifier taking into account qualified path. Unique across blueprints if called after Instance initialization." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetGuid", nullptr, nullptr, sizeof(SMNodeInstance_eventGetGuid_Parms), Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetGuid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetGuid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics
	{
		struct SMNodeInstance_eventGetNetworkInterface_Parms
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
	const UE4CodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UE4CodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetNetworkInterface_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineNetworkedInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance|Network" },
		{ "Comment", "/** Return the server interface if there is one. This may be null. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Return the server interface if there is one. This may be null." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetNetworkInterface", nullptr, nullptr, sizeof(SMNodeInstance_eventGetNetworkInterface_Parms), Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics
	{
		struct SMNodeInstance_eventGetNodeName_Parms
		{
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetNodeName_Parms, ReturnValue), METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** Retrieve the node name. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Retrieve the node name." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetNodeName", nullptr, nullptr, sizeof(SMNodeInstance_eventGetNodeName_Parms), Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetNodeName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetNodeName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics
	{
		struct SMNodeInstance_eventGetOwningStateMachineNodeInstance_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetOwningStateMachineNodeInstance_Parms, ReturnValue), Z_Construct_UClass_USMStateMachineInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The instance of the direct state machine node this node is part of. Every node except the root state machine has an owning state machine node. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "The instance of the direct state machine node this node is part of. Every node except the root state machine has an owning state machine node." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetOwningStateMachineNodeInstance", nullptr, nullptr, sizeof(SMNodeInstance_eventGetOwningStateMachineNodeInstance_Parms), Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics
	{
		struct SMNodeInstance_eventGetStateMachineInstance_Parms
		{
			bool bTopMostInstance;
			USMInstance* ReturnValue;
		};
		static void NewProp_bTopMostInstance_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTopMostInstance;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_bTopMostInstance_SetBit(void* Obj)
	{
		((SMNodeInstance_eventGetStateMachineInstance_Parms*)Obj)->bTopMostInstance = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_bTopMostInstance = { "bTopMostInstance", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMNodeInstance_eventGetStateMachineInstance_Parms), &Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_bTopMostInstance_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetStateMachineInstance_Parms, ReturnValue), Z_Construct_UClass_USMInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_bTopMostInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/**\n\x09 * Retrieve an owning blueprint state machine.\n\x09 * @param bTopMostInstance If the state machine is a reference return the top most instance.\n\x09 * @return The state machine instance this node is running for.\n\x09 */" },
		{ "CPP_Default_bTopMostInstance", "false" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Retrieve an owning blueprint state machine.\n@param bTopMostInstance If the state machine is a reference return the top most instance.\n@return The state machine instance this node is running for." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetStateMachineInstance", nullptr, nullptr, sizeof(SMNodeInstance_eventGetStateMachineInstance_Parms), Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics
	{
		struct SMNodeInstance_eventGetTimeInState_Parms
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
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SMNodeInstance_eventGetTimeInState_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** The current time spent in the state. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "The current time spent in the state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "GetTimeInState", nullptr, nullptr, sizeof(SMNodeInstance_eventGetTimeInState_Parms), Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_GetTimeInState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_GetTimeInState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics
	{
		struct SMNodeInstance_eventHasUpdated_Parms
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
	void Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMNodeInstance_eventHasUpdated_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMNodeInstance_eventHasUpdated_Parms), &Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** State has updated at least once. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "State has updated at least once." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "HasUpdated", nullptr, nullptr, sizeof(SMNodeInstance_eventHasUpdated_Parms), Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_HasUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_HasUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_IsActive_Statics
	{
		struct SMNodeInstance_eventIsActive_Parms
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
	void Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMNodeInstance_eventIsActive_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMNodeInstance_eventIsActive_Parms), &Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** If this node is active. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "If this node is active." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "IsActive", nullptr, nullptr, sizeof(SMNodeInstance_eventIsActive_Parms), Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_IsActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_IsActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics
	{
		struct SMNodeInstance_eventIsInEndState_Parms
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
	void Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SMNodeInstance_eventIsInEndState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SMNodeInstance_eventIsInEndState_Parms), &Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Logic Driver|Node Instance" },
		{ "Comment", "/** State Machine is in an end state or the state is an end state. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "State Machine is in an end state or the state is an end state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USMNodeInstance, nullptr, "IsInEndState", nullptr, nullptr, sizeof(SMNodeInstance_eventIsInEndState_Parms), Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USMNodeInstance_IsInEndState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USMNodeInstance_IsInEndState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USMNodeInstance_NoRegister()
	{
		return USMNodeInstance::StaticClass();
	}
	struct Z_Construct_UClass_USMNodeInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TemplateGuid_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TemplateGuid;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USMNodeInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SMSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USMNodeInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USMNodeInstance_GetContext, "GetContext" }, // 1205428279
		{ &Z_Construct_UFunction_USMNodeInstance_GetGuid, "GetGuid" }, // 3904178713
		{ &Z_Construct_UFunction_USMNodeInstance_GetNetworkInterface, "GetNetworkInterface" }, // 1188887325
		{ &Z_Construct_UFunction_USMNodeInstance_GetNodeName, "GetNodeName" }, // 2523185169
		{ &Z_Construct_UFunction_USMNodeInstance_GetOwningStateMachineNodeInstance, "GetOwningStateMachineNodeInstance" }, // 1962110192
		{ &Z_Construct_UFunction_USMNodeInstance_GetStateMachineInstance, "GetStateMachineInstance" }, // 2786450446
		{ &Z_Construct_UFunction_USMNodeInstance_GetTimeInState, "GetTimeInState" }, // 2178473290
		{ &Z_Construct_UFunction_USMNodeInstance_HasUpdated, "HasUpdated" }, // 2322168383
		{ &Z_Construct_UFunction_USMNodeInstance_IsActive, "IsActive" }, // 696643648
		{ &Z_Construct_UFunction_USMNodeInstance_IsInEndState, "IsInEndState" }, // 4233274789
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMNodeInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "LogicDriver" },
		{ "Comment", "/**\n * The abstract base node instance class all state machine nodes derive from.\n */" },
		{ "DisplayName", "State Machine Node Class Base" },
		{ "HideCategories", "SMNodeInstance" },
		{ "IncludePath", "Nodes/SMNodeInstance.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "The abstract base node instance class all state machine nodes derive from." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USMNodeInstance_Statics::NewProp_TemplateGuid_MetaData[] = {
		{ "Comment", "/** Assigned from the editor and used in tracking specific templates. */" },
		{ "ModuleRelativePath", "Public/Nodes/SMNodeInstance.h" },
		{ "ToolTip", "Assigned from the editor and used in tracking specific templates." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USMNodeInstance_Statics::NewProp_TemplateGuid = { "TemplateGuid", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USMNodeInstance, TemplateGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_USMNodeInstance_Statics::NewProp_TemplateGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USMNodeInstance_Statics::NewProp_TemplateGuid_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USMNodeInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USMNodeInstance_Statics::NewProp_TemplateGuid,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USMNodeInstance_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_USMInstanceInterface_NoRegister, (int32)VTABLE_OFFSET(USMNodeInstance, ISMInstanceInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USMNodeInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USMNodeInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USMNodeInstance_Statics::ClassParams = {
		&USMNodeInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USMNodeInstance_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USMNodeInstance_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_USMNodeInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USMNodeInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USMNodeInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USMNodeInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USMNodeInstance, 3585043832);
	template<> SMSYSTEM_API UClass* StaticClass<USMNodeInstance>()
	{
		return USMNodeInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USMNodeInstance(Z_Construct_UClass_USMNodeInstance, &USMNodeInstance::StaticClass, TEXT("/Script/SMSystem"), TEXT("USMNodeInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USMNodeInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
