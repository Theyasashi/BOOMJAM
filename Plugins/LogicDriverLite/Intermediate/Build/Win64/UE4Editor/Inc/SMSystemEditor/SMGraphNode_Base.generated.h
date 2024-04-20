// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SMSYSTEMEDITOR_SMGraphNode_Base_generated_h
#error "SMGraphNode_Base.generated.h already included, missing '#pragma once' in SMGraphNode_Base.h"
#endif
#define SMSYSTEMEDITOR_SMGraphNode_Base_generated_h

#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_25_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSMGraphNodeLog_Statics; \
	SMSYSTEMEDITOR_API static class UScriptStruct* StaticStruct();


template<> SMSYSTEMEDITOR_API UScriptStruct* StaticStruct<struct FSMGraphNodeLog>();

#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_SPARSE_DATA
#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_RPC_WRAPPERS
#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_RPC_WRAPPERS_NO_PURE_DECLS
#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSMGraphNode_Base(); \
	friend struct Z_Construct_UClass_USMGraphNode_Base_Statics; \
public: \
	DECLARE_CLASS(USMGraphNode_Base, UEdGraphNode, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SMSystemEditor"), NO_API) \
	DECLARE_SERIALIZER(USMGraphNode_Base) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_INCLASS \
private: \
	static void StaticRegisterNativesUSMGraphNode_Base(); \
	friend struct Z_Construct_UClass_USMGraphNode_Base_Statics; \
public: \
	DECLARE_CLASS(USMGraphNode_Base, UEdGraphNode, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SMSystemEditor"), NO_API) \
	DECLARE_SERIALIZER(USMGraphNode_Base) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMGraphNode_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMGraphNode_Base) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMGraphNode_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMGraphNode_Base); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMGraphNode_Base(USMGraphNode_Base&&); \
	NO_API USMGraphNode_Base(const USMGraphNode_Base&); \
public:


#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USMGraphNode_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USMGraphNode_Base(USMGraphNode_Base&&); \
	NO_API USMGraphNode_Base(const USMGraphNode_Base&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USMGraphNode_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USMGraphNode_Base); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USMGraphNode_Base)


#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollectedLogs() { return STRUCT_OFFSET(USMGraphNode_Base, CollectedLogs); } \
	FORCEINLINE static uint32 __PPO__BoundGraph() { return STRUCT_OFFSET(USMGraphNode_Base, BoundGraph); } \
	FORCEINLINE static uint32 __PPO__NodeInstanceTemplate() { return STRUCT_OFFSET(USMGraphNode_Base, NodeInstanceTemplate); } \
	FORCEINLINE static uint32 __PPO__CachedBrush() { return STRUCT_OFFSET(USMGraphNode_Base, CachedBrush); } \
	FORCEINLINE static uint32 __PPO__CachedTexture() { return STRUCT_OFFSET(USMGraphNode_Base, CachedTexture); } \
	FORCEINLINE static uint32 __PPO__CachedTextureSize() { return STRUCT_OFFSET(USMGraphNode_Base, CachedTextureSize); } \
	FORCEINLINE static uint32 __PPO__CachedNodeTintColor() { return STRUCT_OFFSET(USMGraphNode_Base, CachedNodeTintColor); } \
	FORCEINLINE static uint32 __PPO__LoadedVersion() { return STRUCT_OFFSET(USMGraphNode_Base, LoadedVersion); }


#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_51_PROLOG
#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_RPC_WRAPPERS \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_INCLASS \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_SPARSE_DATA \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h_54_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SMGraphNode_Base."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SMSYSTEMEDITOR_API UClass* StaticClass<class USMGraphNode_Base>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_SMSystem_Source_SMSystemEditor_Private_Graph_Nodes_SMGraphNode_Base_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
