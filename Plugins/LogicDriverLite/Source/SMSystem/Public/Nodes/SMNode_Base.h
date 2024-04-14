// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SMExposedFunctions.h"

#include "SMNode_Base.generated.h"

class USMInstance;
class USMNodeInstance;

/**
 * Base struct for all state machine nodes. The Guid MUST be manually initialized right after construction.
 */
USTRUCT(BlueprintInternalUseOnly)
struct SMSYSTEM_API FSMNode_Base
{
	GENERATED_USTRUCT_BODY()

public:
	/** Entry point to when a transition is first initialized. */
	UPROPERTY()
	TArray<FSMExposedFunctionHandler> TransitionInitializedGraphEvaluators;

	/** Entry point to when a transition is shutdown. */
	UPROPERTY()
	TArray<FSMExposedFunctionHandler> TransitionShutdownGraphEvaluators;

	/** When the owning blueprint's root state machine starts. */
	UPROPERTY()
	TArray<FSMExposedFunctionHandler> OnRootStateMachineStartedGraphEvaluator;

	/** When the owning blueprint's root state machine stops. */
	UPROPERTY()
	TArray<FSMExposedFunctionHandler> OnRootStateMachineStoppedGraphEvaluator;
	
	/** The current time spent in the state. */
	UPROPERTY(BlueprintReadWrite, Category = "State Machines")
	float TimeInState;

	/** State Machine is in end state or the state is an end state. */
	UPROPERTY(BlueprintReadWrite, Category = "State Machines")
	bool bIsInEndState;

	/** State has updated at least once. */
	UPROPERTY(BlueprintReadWrite, Category = "State Machines")
	bool bHasUpdated;

	/** Special indicator in case this node is a duplicate within the same blueprint. If this isn't 0 then the NodeGuid will have been adjusted. */
	UPROPERTY()
	int32 DuplicateId;

public:
	virtual void UpdateReadStates() {}

public:
	FSMNode_Base();
	virtual ~FSMNode_Base() = default;
	FSMNode_Base(const FSMNode_Base& Node) = default;

	/** Initialize specific properties and node instances. */
	virtual void Initialize(UObject* Instance);

	/** Initialize all graph evaluator functions. Must be called from GameThread! */
	virtual void InitializeGraphFunctions();

	/** Resets persistent data. */
	virtual void Reset();
	
	/** Called when the blueprint owning this node is started. */
	virtual void OnStartedByInstance(USMInstance* Instance);

	/** Called when the blueprint owning this node has stopped. */
	virtual void OnStoppedByInstance(USMInstance* Instance);
	
	/** If all graph function initialization has taken place once. */
	bool HaveGraphFunctionsInitialized() const { return bHaveGraphFunctionsInitialized; }

	/** If the node is currently initialized for this run. */
	bool IsInitializedForRun() const { return bIsInitializedForRun; }

	/** Unique identifier used in constructing nodes from a graph. May not be unique if this is from a parent graph or a reference. */
	const FGuid& GetNodeGuid() const;
	void GenerateNewNodeGuid();
	
	/** Unique identifier taking into account qualified path. Unique across blueprints if called after Instance initialization. */
	const FGuid& GetGuid() const;
	/** Calculate the value returned from GetGuid(). Gets all owner nodes and builds a path to this node. Hashes the path and sets PathGuid. */
	virtual void CalculatePathGuid(TMap<FString, int32>& InOutMappedPaths);
	/** Unhashed string format of the guid path. MappedPaths are used to adjust for collisions. */
	FString GetGuidPath(TMap<FString, int32>& InOutMappedPaths) const;
	/** Calculate the path guid but do not set the guid. */
	FGuid CalculatePathGuidConst() const;
	
	/** Only generate a new guid if the current guid is invalid. This needs to be called
	 * on new nodes. */
	void GenerateNewNodeGuidIfNotSet();
	void SetNodeGuid(const FGuid& NewGuid);

	/** The state machine's NodeGuid owning this node. */
	void SetOwnerNodeGuid(const FGuid& NewGuid);
	/** Unique identifier to help determine which state machine this node belongs to. */
	const FGuid& GetOwnerNodeGuid() const { return OwnerGuid; }

	/** Property name of the NodeGuid. */
	static FName GetNodeGuidPropertyName() { return GET_MEMBER_NAME_CHECKED(FSMNode_Base, Guid); }
	
	/** The node directly owning this node. Should be a StateMachine. */
	void SetOwnerNode(FSMNode_Base* Owner);
	/** The node directly owning this node. Should be a StateMachine. */
	virtual FSMNode_Base* GetOwnerNode() const { return OwnerNode; }
	
	/** The state machine instance owning this node. */
	USMInstance* GetOwningInstance() const { return OwningInstance; }

	/** Create the node instance if a node instance class is set. */
	void CreateNodeInstance();

	/** Calls CheckNodeInstanceCompatible. */
	void SetNodeInstanceClass(UClass* NewNodeInstanceClass);
	
	/** Derived nodes should overload and check for the correct type. */
	virtual bool IsNodeInstanceClassCompatible(UClass* NewNodeInstanceClass) const;
	
	/** Return the current node instance. Only valid after initialization and may be nullptr. */
	virtual USMNodeInstance* GetNodeInstance() const { return NodeInstance; }

	/** Create a node instance on demand if needed. Only required for default node classes. Initialization should be completed before calling. */
	virtual USMNodeInstance* GetOrCreateNodeInstance();

	/** If the node can at some point create a node instance. */
	virtual bool CanEverCreateNodeInstance() const { return true; }
	
	/** The default node instance class. Each derived node class needs to implement. */
	virtual UClass* GetDefaultNodeInstanceClass() const { return nullptr; }

	/** The current in use node class. */
	UClass* GetNodeInstanceClass() const { return NodeInstanceClass; }

	/** Is the default node class assigned. */
	bool IsUsingDefaultNodeClass() const { return GetDefaultNodeInstanceClass() == GetNodeInstanceClass(); }

	void SetNodeName(const FString& Name);
	const FString& GetNodeName() const { return NodeName; }
	
	void SetTemplateName(const FName& Name);
	const FName& GetTemplateName() const { return TemplateName; }

	/** If this node is active. */
	virtual bool IsActive() const { return bIsActive; }

	virtual void ExecuteInitializeNodes();
	virtual void ExecuteShutdownNodes();

	/** Set the time in state as recorded from the server. */
	virtual void SetServerTimeInState(float InTime);

	/** The time in state as recorded by the server. Kept in the base node as transitions can utilize it. */
	float GetServerTimeInState() const { return ServerTimeInState; }
	
#if WITH_EDITORONLY_DATA
	virtual bool IsDebugActive() const { return bIsActive; }
	virtual bool WasDebugActive() const { return bWasActive; }
	
	/** Debug helper in case a state switches to inactive in one frame. */
	mutable bool bWasActive = false;
#endif
protected:
	/** Execute the graph. */
	virtual void PrepareGraphExecution();
	virtual void SetActive(bool bValue);
protected:
	/*
	 * NodeGuid must always be unique. Do not duplicate the guid in any other node in any blueprint.
	 *
	 * This is not the same guid that is used at run-time. At run-time all NodeGuids in a path to a node
	 * are hashed to form the PathGuid. This is done to account for multiple references and parent graph calls.
	 *
	 * If you need to change the path of a node (such as collapse it to a nested state machine) and you need to maintain
	 * the old guid for run-time saves to work, you should use the GuidRedirectMap on the primary state machine instance
	 * which accepts PathGuids.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Graph Node")
	FGuid Guid;

	/** The state machine's NodeGuid owning this node. */
	UPROPERTY()
	FGuid OwnerGuid;

	/*
	 * Unique identifier calculated from this node's place in an instance.
	 * Calculated by taking the MD5 hash of the full path of all owner NodeGuids and
	 * this NodeGuid.
	 * This is what is returned from GetGuid().
	 * 
	 * ReadWrite so it can be easily read from custom graph nodes.
	 */
	UPROPERTY(BlueprintReadWrite, Category = "Graph Node")
	FGuid PathGuid;
	
	/** The node directly owning this node. Should be a StateMachine. */
	FSMNode_Base* OwnerNode;

	UPROPERTY()
	FString NodeName;

	/** The name of a template archetype to use when constructing an instance. This allows default values be passed into the instance. */
	UPROPERTY()
	FName TemplateName;

	/** The state machine instance owning this node. */
	UPROPERTY()
	USMInstance* OwningInstance;

	/** The node instance for this node if it exists. */
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Node Class")
	USMNodeInstance* NodeInstance;
	
	/** The class to use to construct the node instance if one exists. */
	UPROPERTY(BlueprintReadWrite, Category = "Node Class")
	UClass* NodeInstanceClass;
	
private:
	/** Last recorded active time in state from the server. */
	float ServerTimeInState;
	
	uint8 bHaveGraphFunctionsInitialized: 1;
	uint8 bIsInitializedForRun: 1;
	uint8 bIsActive: 1;
};