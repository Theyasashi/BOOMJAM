// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGuid;
class ISMStateMachineNetworkedInterface;
class USMStateMachineInstance;
class USMInstance;
class UObject;
#ifdef SMSYSTEM_SMNodeInstance_generated_h
#error "SMNodeInstance.generated.h already included, missing '#pragma once' in SMNodeInstance.h"
#endif
#define SMSYSTEM_SMNodeInstance_generated_h

#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_53_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSMNodeDescription_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SMSYSTEM_API UScriptStruct* StaticStruct<struct FSMNodeDescription>();

#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_SPARSE_DATA
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetGuid); \
	DECLARE_FUNCTION(execGetNodeName); \
	DECLARE_FUNCTION(execIsActive); \
	DECLARE_FUNCTION(execHasUpdated); \
	DECLARE_FUNCTION(execIsInEndState); \
	DECLARE_FUNCTION(execGetTimeInState); \
	DECLARE_FUNCTION(execGetNetworkInterface); \
	DECLARE_FUNCTION(execGetOwningStateMachineNodeInstance); \
	DECLARE_FUNCTION(execGetStateMachineInstance); \
	DECLARE_FUNCTION(execGetContext);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGuid); \
	DECLARE_FUNCTION(execGetNodeName); \
	DECLARE_FUNCTION(execIsActive); \
	DECLARE_FUNCTION(execHasUpdated); \
	DECLARE_FUNCTION(execIsInEndState); \
	DECLARE_FUNCTION(execGetTimeInState); \
	DECLARE_FUNCTION(execGetNetworkInterface); \
	DECLARE_FUNCTION(execGetOwningStateMachineNodeInstance); \
	DECLARE_FUNCTION(execGetStateMachineInstance); \
	DECLARE_FUNCTION(execGetContext);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSMNodeInstance(); \
	friend struct Z_Construct_UClass_USMNodeInstance_Statics; \
public: \
	DECLARE_CLASS(USMNodeInstance, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMNodeInstance) \
	virtual UObject* _getUObject() const override { return const_cast<USMNodeInstance*>(this); }


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_INCLASS \
private: \
	static void StaticRegisterNativesUSMNodeInstance(); \
	friend struct Z_Construct_UClass_USMNodeInstance_Statics; \
public: \
	DECLARE_CLASS(USMNodeInstance, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMNodeInstance) \
	virtual UObject* _getUObject() const override { return const_cast<USMNodeInstance*>(this); }


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMNodeInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMNodeInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMNodeInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMNodeInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMNodeInstance(USMNodeInstance&&); \
	NO_API USMNodeInstance(const USMNodeInstance&); \
public:


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMNodeInstance(USMNodeInstance&&); \
	NO_API USMNodeInstance(const USMNodeInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMNodeInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMNodeInstance); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(USMNodeInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TemplateGuid() { return STRUCT_OFFSET(USMNodeInstance, TemplateGuid); }


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_71_PROLOG
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_RPC_WRAPPERS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_INCLASS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h_74_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SMSYSTEM_API UClass* StaticClass<class USMNodeInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_SMNodeInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
