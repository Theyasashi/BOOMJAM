// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USMInstance;
class USMStateInstance_Base;
#ifdef SMSYSTEM_SMStateMachineInstance_generated_h
#error "SMStateMachineInstance.generated.h already included, missing '#pragma once' in SMStateMachineInstance.h"
#endif
#define SMSYSTEM_SMStateMachineInstance_generated_h

#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_SPARSE_DATA
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetReuseIfNotEndState); \
	DECLARE_FUNCTION(execGetReuseIfNotEndState); \
	DECLARE_FUNCTION(execSetReuseCurrentState); \
	DECLARE_FUNCTION(execGetReuseCurrentState); \
	DECLARE_FUNCTION(execSetWaitForEndState); \
	DECLARE_FUNCTION(execGetWaitForEndState); \
	DECLARE_FUNCTION(execGetStateMachineReference); \
	DECLARE_FUNCTION(execGetActiveStates); \
	DECLARE_FUNCTION(execGetEntryStates); \
	DECLARE_FUNCTION(execGetContainedStateByName); \
	DECLARE_FUNCTION(execGetAllStateInstances);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetReuseIfNotEndState); \
	DECLARE_FUNCTION(execGetReuseIfNotEndState); \
	DECLARE_FUNCTION(execSetReuseCurrentState); \
	DECLARE_FUNCTION(execGetReuseCurrentState); \
	DECLARE_FUNCTION(execSetWaitForEndState); \
	DECLARE_FUNCTION(execGetWaitForEndState); \
	DECLARE_FUNCTION(execGetStateMachineReference); \
	DECLARE_FUNCTION(execGetActiveStates); \
	DECLARE_FUNCTION(execGetEntryStates); \
	DECLARE_FUNCTION(execGetContainedStateByName); \
	DECLARE_FUNCTION(execGetAllStateInstances);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSMStateMachineInstance(); \
	friend struct Z_Construct_UClass_USMStateMachineInstance_Statics; \
public: \
	DECLARE_CLASS(USMStateMachineInstance, USMStateInstance_Base, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateMachineInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUSMStateMachineInstance(); \
	friend struct Z_Construct_UClass_USMStateMachineInstance_Statics; \
public: \
	DECLARE_CLASS(USMStateMachineInstance, USMStateInstance_Base, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateMachineInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMStateMachineInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMStateMachineInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateMachineInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateMachineInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateMachineInstance(USMStateMachineInstance&&); \
	NO_API USMStateMachineInstance(const USMStateMachineInstance&); \
public:


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateMachineInstance(USMStateMachineInstance&&); \
	NO_API USMStateMachineInstance(const USMStateMachineInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateMachineInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateMachineInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USMStateMachineInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bWaitForEndState() { return STRUCT_OFFSET(USMStateMachineInstance, bWaitForEndState); } \
	FORCEINLINE static uint32 __PPO__bReuseCurrentState() { return STRUCT_OFFSET(USMStateMachineInstance, bReuseCurrentState); } \
	FORCEINLINE static uint32 __PPO__bReuseIfNotEndState() { return STRUCT_OFFSET(USMStateMachineInstance, bReuseIfNotEndState); }


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_15_PROLOG
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_RPC_WRAPPERS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_INCLASS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SMSYSTEM_API UClass* StaticClass<class USMStateMachineInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateMachineInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
