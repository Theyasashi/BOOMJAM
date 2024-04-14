// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "ISMStateMachineInterface.h"
#include "SMLogging.h"

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"

#include "SMNodeInstance.generated.h"

class UWorld;
struct FSMNode_Base;

DECLARE_DWORD_ACCUMULATOR_STAT_EXTERN(TEXT("SMNodeInstances"), STAT_NodeInstances, STATGROUP_LogicDriver, SMSYSTEM_API);

/* Gets the value as defined on the struct. */
#define GET_NODE_STRUCT_VALUE(StructType, StructVariable) \
	if (StructType* StructOwner = GetOwningNodeAs<StructType>()) \
	{ \
		return StructOwner->StructVariable; \
	} \

/* Gets the node property value. */
#define GET_NODE_DEFAULT_VALUE_DIF_VAR(StructType, InstanceVariable, StructVariable) \
		GET_NODE_STRUCT_VALUE(StructType, StructVariable) \
		return InstanceVariable;

/* Gets the node property value. */
#define GET_NODE_DEFAULT_VALUE(StructType, Variable) \
		GET_NODE_DEFAULT_VALUE_DIF_VAR(StructType, Variable, Variable);


/* Sets both the node instance variable and the struct owner variable to the given value. */
#define SET_NODE_DEFAULT_VALUE_DIF_VAR(StructType, InstanceVariable, StructVariable, Value) \
		InstanceVariable = Value; \
		if (StructType* StructOwner = GetOwningNodeAs<StructType>()) \
		{ \
			StructOwner->StructVariable = Value; \
		}

/* Sets both the node instance variable and the struct owner variable to the given value. */
#define SET_NODE_DEFAULT_VALUE(StructType, Variable, Value) \
		SET_NODE_DEFAULT_VALUE_DIF_VAR(StructType, Variable, Variable, Value);

/**
 * This information will be viewable when selecting new nodes or hovering over nodes.
 */
USTRUCT()
struct SMSYSTEM_API FSMNodeDescription
{
	GENERATED_USTRUCT_BODY()

	/** The name of this node type. */
	UPROPERTY(EditDefaultsOnly, Category = "General", meta = (InstancedTemplate))
	FName Name;

	/** Which category this should fall under. */
	UPROPERTY(EditDefaultsOnly, Category = "General", meta = (InstancedTemplate))
	FText Category;

	/** The tooltip when selecting the action. */
	UPROPERTY(EditDefaultsOnly, Category = "General", meta = (InstancedTemplate, MultiLine = true))
	FText Description;
};

/**
 * The abstract base node instance class all state machine nodes derive from.
 */
UCLASS(Abstract, NotBlueprintable, BlueprintType, ClassGroup = LogicDriver, hideCategories = (SMNodeInstance), meta = (DisplayName = "State Machine Node Class Base"))
class SMSYSTEM_API USMNodeInstance : public UObject, public ISMInstanceInterface
{
	GENERATED_BODY()

public:
	USMNodeInstance();
	
	// UObject
	virtual UWorld* GetWorld() const override;
	virtual void BeginDestroy() override;
	// ~UObject

	// ISMInstanceInterface
	/** The object which this node is running for. Determined by the owning state machine. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	virtual UObject* GetContext() const override;
	// ~ISMInstanceInterface
	
	/**
	 * Retrieve an owning blueprint state machine.
	 * @param bTopMostInstance If the state machine is a reference return the top most instance.
	 * @return The state machine instance this node is running for.
	 */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	class USMInstance* GetStateMachineInstance(bool bTopMostInstance = false) const;

	/** Set during initialization of the state machine. */
	void SetOwningNode(FSMNode_Base* Node);
	
	/** Reference to the owning node within a state machine. */
	const FSMNode_Base* GetOwningNode() const { return OwningNode; }

	/** Reference the owning struct node as a given type. */
	template<typename T>
	T* GetOwningNodeAs() const { return static_cast<T*>(OwningNode); }
	
	/** Some nodes such as references may have special handling for returning a container node. */
	virtual const FSMNode_Base* GetOwningNodeContainer() const { return GetOwningNode(); }
	
	/** The instance of the direct state machine node this node is part of. Every node except the root state machine has an owning state machine node. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	class USMStateMachineInstance* GetOwningStateMachineNodeInstance() const;

	/** Return the server interface if there is one. This may be null. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance|Network")
	TScriptInterface<ISMStateMachineNetworkedInterface> GetNetworkInterface() const;
	
	/** The current time spent in the state. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	virtual float GetTimeInState() const;

	/** State Machine is in an end state or the state is an end state. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	virtual bool IsInEndState() const;

	/** State has updated at least once. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	virtual bool HasUpdated() const;
	
	/** If this node is active. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	bool IsActive() const;

	/** Retrieve the node name. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	const FString& GetNodeName() const;
	
	/** Unique identifier taking into account qualified path. Unique across blueprints if called after Instance initialization. */
	UFUNCTION(BlueprintCallable, Category = "Logic Driver|Node Instance")
	const FGuid& GetGuid() const;
	
	/** Retrieve the template guid. The template guid cannot be modified at runtime. */
	const FGuid& GetTemplateGuid() const { return TemplateGuid; }

private:
	/** The owning node in the state machine instance. */
	FSMNode_Base* OwningNode;

	/** Assigned from the editor and used in tracking specific templates. */
	UPROPERTY()
	FGuid TemplateGuid;
};