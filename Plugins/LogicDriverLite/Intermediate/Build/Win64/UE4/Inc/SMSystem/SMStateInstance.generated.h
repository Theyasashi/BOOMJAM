// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USMStateInstance_Base;
struct FDateTime;
class USMTransitionInstance;
struct FSMStateInfo;
#ifdef SMSYSTEM_SMStateInstance_generated_h
#error "SMStateInstance.generated.h already included, missing '#pragma once' in SMStateInstance.h"
#endif
#define SMSYSTEM_SMStateInstance_generated_h

#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_14_DELEGATE \
struct _Script_SMSystem_eventOnStateEndSignature_Parms \
{ \
	USMStateInstance_Base* StateInstance; \
}; \
static inline void FOnStateEndSignature_DelegateWrapper(const FMulticastScriptDelegate& OnStateEndSignature, USMStateInstance_Base* StateInstance) \
{ \
	_Script_SMSystem_eventOnStateEndSignature_Parms Parms; \
	Parms.StateInstance=StateInstance; \
	OnStateEndSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_13_DELEGATE \
struct _Script_SMSystem_eventOnStateUpdateSignature_Parms \
{ \
	USMStateInstance_Base* StateInstance; \
	float DeltaSeconds; \
}; \
static inline void FOnStateUpdateSignature_DelegateWrapper(const FMulticastScriptDelegate& OnStateUpdateSignature, USMStateInstance_Base* StateInstance, float DeltaSeconds) \
{ \
	_Script_SMSystem_eventOnStateUpdateSignature_Parms Parms; \
	Parms.StateInstance=StateInstance; \
	Parms.DeltaSeconds=DeltaSeconds; \
	OnStateUpdateSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_12_DELEGATE \
struct _Script_SMSystem_eventOnStateBeginSignature_Parms \
{ \
	USMStateInstance_Base* StateInstance; \
}; \
static inline void FOnStateBeginSignature_DelegateWrapper(const FMulticastScriptDelegate& OnStateBeginSignature, USMStateInstance_Base* StateInstance) \
{ \
	_Script_SMSystem_eventOnStateBeginSignature_Parms Parms; \
	Parms.StateInstance=StateInstance; \
	OnStateBeginSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_SPARSE_DATA
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetExcludeFromAnyState); \
	DECLARE_FUNCTION(execGetExcludeFromAnyState); \
	DECLARE_FUNCTION(execSetEvalTransitionsOnStart); \
	DECLARE_FUNCTION(execGetEvalTransitionsOnStart); \
	DECLARE_FUNCTION(execSetDisableTickTransitionEvaluation); \
	DECLARE_FUNCTION(execGetDisableTickTransitionEvaluation); \
	DECLARE_FUNCTION(execSetAlwaysUpdate); \
	DECLARE_FUNCTION(execGetAlwaysUpdate); \
	DECLARE_FUNCTION(execGetServerTimeInState); \
	DECLARE_FUNCTION(execGetStartTime); \
	DECLARE_FUNCTION(execAreAllIncomingTransitionsFromAnAnyState); \
	DECLARE_FUNCTION(execAreAllOutgoingTransitionsFromAnAnyState); \
	DECLARE_FUNCTION(execGetPreviousActiveTransition); \
	DECLARE_FUNCTION(execGetPreviousActiveState); \
	DECLARE_FUNCTION(execGetPreviousStateByName); \
	DECLARE_FUNCTION(execGetNextStateByName); \
	DECLARE_FUNCTION(execGetNextStateByTransitionIndex); \
	DECLARE_FUNCTION(execGetTransitionByIndex); \
	DECLARE_FUNCTION(execSwitchToLinkedStateByTransition); \
	DECLARE_FUNCTION(execSwitchToLinkedStateByName); \
	DECLARE_FUNCTION(execSwitchToLinkedState); \
	DECLARE_FUNCTION(execGetTransitionToTake); \
	DECLARE_FUNCTION(execGetIncomingTransitions); \
	DECLARE_FUNCTION(execGetOutgoingTransitions); \
	DECLARE_FUNCTION(execEvaluateTransitions); \
	DECLARE_FUNCTION(execSetActive); \
	DECLARE_FUNCTION(execIsEntryState); \
	DECLARE_FUNCTION(execIsStateMachine); \
	DECLARE_FUNCTION(execGetStateInfo);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetExcludeFromAnyState); \
	DECLARE_FUNCTION(execGetExcludeFromAnyState); \
	DECLARE_FUNCTION(execSetEvalTransitionsOnStart); \
	DECLARE_FUNCTION(execGetEvalTransitionsOnStart); \
	DECLARE_FUNCTION(execSetDisableTickTransitionEvaluation); \
	DECLARE_FUNCTION(execGetDisableTickTransitionEvaluation); \
	DECLARE_FUNCTION(execSetAlwaysUpdate); \
	DECLARE_FUNCTION(execGetAlwaysUpdate); \
	DECLARE_FUNCTION(execGetServerTimeInState); \
	DECLARE_FUNCTION(execGetStartTime); \
	DECLARE_FUNCTION(execAreAllIncomingTransitionsFromAnAnyState); \
	DECLARE_FUNCTION(execAreAllOutgoingTransitionsFromAnAnyState); \
	DECLARE_FUNCTION(execGetPreviousActiveTransition); \
	DECLARE_FUNCTION(execGetPreviousActiveState); \
	DECLARE_FUNCTION(execGetPreviousStateByName); \
	DECLARE_FUNCTION(execGetNextStateByName); \
	DECLARE_FUNCTION(execGetNextStateByTransitionIndex); \
	DECLARE_FUNCTION(execGetTransitionByIndex); \
	DECLARE_FUNCTION(execSwitchToLinkedStateByTransition); \
	DECLARE_FUNCTION(execSwitchToLinkedStateByName); \
	DECLARE_FUNCTION(execSwitchToLinkedState); \
	DECLARE_FUNCTION(execGetTransitionToTake); \
	DECLARE_FUNCTION(execGetIncomingTransitions); \
	DECLARE_FUNCTION(execGetOutgoingTransitions); \
	DECLARE_FUNCTION(execEvaluateTransitions); \
	DECLARE_FUNCTION(execSetActive); \
	DECLARE_FUNCTION(execIsEntryState); \
	DECLARE_FUNCTION(execIsStateMachine); \
	DECLARE_FUNCTION(execGetStateInfo);


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSMStateInstance_Base(); \
	friend struct Z_Construct_UClass_USMStateInstance_Base_Statics; \
public: \
	DECLARE_CLASS(USMStateInstance_Base, USMNodeInstance, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateInstance_Base)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUSMStateInstance_Base(); \
	friend struct Z_Construct_UClass_USMStateInstance_Base_Statics; \
public: \
	DECLARE_CLASS(USMStateInstance_Base, USMNodeInstance, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateInstance_Base)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMStateInstance_Base(const FObjectInitializer& ObjectInitializer); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMStateInstance_Base) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateInstance_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateInstance_Base); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateInstance_Base(USMStateInstance_Base&&); \
	NO_API USMStateInstance_Base(const USMStateInstance_Base&); \
public:


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateInstance_Base(USMStateInstance_Base&&); \
	NO_API USMStateInstance_Base(const USMStateInstance_Base&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateInstance_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateInstance_Base); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(USMStateInstance_Base)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bAlwaysUpdate() { return STRUCT_OFFSET(USMStateInstance_Base, bAlwaysUpdate); } \
	FORCEINLINE static uint32 __PPO__bDisableTickTransitionEvaluation() { return STRUCT_OFFSET(USMStateInstance_Base, bDisableTickTransitionEvaluation); } \
	FORCEINLINE static uint32 __PPO__bEvalTransitionsOnStart() { return STRUCT_OFFSET(USMStateInstance_Base, bEvalTransitionsOnStart); }


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_19_PROLOG
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_RPC_WRAPPERS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_INCLASS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SMSYSTEM_API UClass* StaticClass<class USMStateInstance_Base>();

#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_SPARSE_DATA
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_RPC_WRAPPERS
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSMStateInstance(); \
	friend struct Z_Construct_UClass_USMStateInstance_Statics; \
public: \
	DECLARE_CLASS(USMStateInstance, USMStateInstance_Base, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_INCLASS \
private: \
	static void StaticRegisterNativesUSMStateInstance(); \
	friend struct Z_Construct_UClass_USMStateInstance_Statics; \
public: \
	DECLARE_CLASS(USMStateInstance, USMStateInstance_Base, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SMSystem"), NO_API) \
	DECLARE_SERIALIZER(USMStateInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMStateInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMStateInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateInstance(USMStateInstance&&); \
	NO_API USMStateInstance(const USMStateInstance&); \
public:


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMStateInstance(USMStateInstance&&); \
	NO_API USMStateInstance(const USMStateInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMStateInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMStateInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USMStateInstance)


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_360_PROLOG
#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_RPC_WRAPPERS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_INCLASS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h_363_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SMSYSTEM_API UClass* StaticClass<class USMStateInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_SMSystem_Source_SMSystem_Public_Nodes_States_SMStateInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
