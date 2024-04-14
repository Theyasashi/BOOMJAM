// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "SMNodeInstance.h"

#include "EdGraph/EdGraphNode.h"
#include "Styling/SlateBrush.h"

#include "SMGraphNode_Base.generated.h"

class USMEditorSettings;
class USMGraph;
class FSMKismetCompilerContext;
struct FSMNode_Base;

#define INDEX_PIN_INPUT 0
#define INDEX_PIN_OUTPUT 1

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnGraphNodeRefreshRequested, class USMGraphNode_Base* /* GraphNode */, bool /* bFullRefresh */);

USTRUCT()
struct FSMGraphNodeLog
{
	GENERATED_BODY()

	FSMGraphNodeLog(): LogType(0)
	{
	}

	FSMGraphNodeLog(int32 Type)
	{
		LogType = Type;
	}

	UPROPERTY()
	FString ConsoleMessage;

	UPROPERTY()
	FString NodeMessage;

	/** EMessageSeverity::Type */
	UPROPERTY()
	int32 LogType;

	/** Objects like nodes or pins to go to the log. */
	UPROPERTY()
	TArray<UObject*> ReferenceList;
};

UCLASS(abstract, config = EditorPerProjectUserSettings, PerObjectConfig)
class SMSYSTEMEDITOR_API USMGraphNode_Base : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()

public:
	bool bGenerateTemplateOnNodePlacement;
	
	// UEdGraphNode
	virtual void DestroyNode() override;
	virtual void PostPasteNode() override;
	virtual void PostEditUndo() override;
	virtual void PostPlacedNewNode() override;
	virtual void OnRenameNode(const FString& NewName) override;
	virtual UObject* GetJumpTargetForDoubleClick() const override;
	virtual bool CanJumpToDefinition() const override;
	virtual void JumpToDefinition() const override;
	virtual bool CanCreateUnderSpecifiedSchema(const UEdGraphSchema* Schema) const override;
	virtual void ReconstructNode() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const override;
	// ~UEdGraphNode
	
	/** Called during kismet pre-compile before the bound graph is copied to the consolidated event graph. */
	virtual void PreCompile(FSMKismetCompilerContext& CompilerContext);
	
	/** Called during kismet compile after this node has been cloned. */
	virtual void OnCompile(FSMKismetCompilerContext& CompilerContext);

	/** Resets the local and node debug state if valid. */
	virtual void ResetDebugState();
	
	/** Called from the slate node when it is constructed. */
	virtual void OnWidgetConstruct();
	
	/** So we can pass time ticks for specific node appearance behavior. */
	virtual void UpdateTime(float DeltaTime);

	/** Helper to set error messages that may happen before compile. */
	virtual void CheckSetErrorMessages() {}

	/** Resets collected logs. */
	virtual void ResetLogMessages();
	
	/** Calculate any error / info display. */
	void UpdateErrorMessageFromLogs();

	/** Adds a log message to the collected logs. */
	void AddNodeLogMessage(const FSMGraphNodeLog& Message);
	
	/** Combine all logs into a single message and retrieve the severity. Returns false if no messages exist. */
	bool TryGetNodeLogMessage(FString& OutMessage, int32& OutSeverity) const;
	
	/** Jump to the local graph. */
	virtual void GoToLocalGraph() const;

	/** If this node is allowed to go to it's local graph. */
	virtual bool CanGoToLocalGraph() const { return GetBoundGraph() != nullptr; }
	
	// Node class settings.
	/** Instantiate a template for use as an archetype. */
	virtual void InitTemplate();

	/** Transfer the template to the transient package. */
	virtual void DestroyTemplate();

	/** Place default nodes when a class is selected. */
	virtual void PlaceDefaultInstanceNodes();
	
	bool IsSafeToConditionallyCompile(EPropertyChangeType::Type ChangeType) const;

	/** Return the correct node class. This should be a TSubClass property in child nodes. */
	virtual UClass* GetNodeClass() const { return nullptr; }
	virtual void SetNodeClass(UClass* Class);
	UClass* GetDefaultNodeClass() const;
	
	/** Checks if the node template is user created or system supplied. System supplied templates don't get stored on the CDO. */
	bool IsUsingDefaultNodeClass() const { return GetNodeClass() == GetDefaultNodeClass(); }
	
	/** Checks if the node class is native only. */
	bool IsNodeClassNative() const;
	
	/** Checks if all execution points avoid blueprint graph calls. */
	virtual bool IsNodeFastPathEnabled() const;

private:
	mutable TOptional<bool> bFastPathEnabledCached;
	
public:
	USMNodeInstance* GetNodeTemplate() const { return NodeInstanceTemplate; }

	template<typename T>
	T* GetNodeTemplateAs(bool bCheck = false) const
	{
		return bCheck ? CastChecked<T>(NodeInstanceTemplate) : Cast<T>(NodeInstanceTemplate);
	}
	
	/** The state machine graph this node is placed in. */
	USMGraph* GetStateMachineGraph() const;
	/** The graph this node owns and represents. */
	UEdGraph* GetBoundGraph() const { return BoundGraph; }
	void ClearBoundGraph() { BoundGraph = nullptr; }

	/** If property graphs can be placed within this node. */
	virtual bool SupportsPropertyGraphs() const { return false; }
	
	virtual UEdGraphPin* GetInputPin() const;
	virtual UEdGraphPin* GetOutputPin() const;

	/** Returns the first output node. */
	UEdGraphNode* GetOutputNode() const;

	/** Returns all connected output nodes. */
	void GetAllOutputNodes(TArray<UEdGraphNode*>& OutNodes) const;

	template<typename T>
	void GetAllOutputNodesAs(TArray<T*>& OutNodes) const
	{
		TArray<UEdGraphNode*> Nodes;
		GetAllOutputNodes(Nodes);

		for (UEdGraphNode* Node : Nodes)
		{
			if (T* TNode = Cast<T>(Node))
			{
				OutNodes.Add(TNode);
			}
		}
	}

	/** The background color this node should be. Separate from slate so we can use one slate object
	 * to represent many different nodes. */
	virtual FLinearColor GetBackgroundColor() const;
	/** The background color to use when this node is being debugged. */
	virtual FLinearColor GetActiveBackgroundColor() const;
	/** The icon image to use. */
	virtual const FSlateBrush* GetNodeIcon();
	
	/** Helper to locate the runtime node this node represents. */
	FSMNode_Base* FindRuntimeNode() const;
	/** Locates the current debug node if one exists. */
	const FSMNode_Base* GetDebugNode() const;
	
	float GetDebugTime() const { return DebugTotalTime; }
	virtual float GetMaxDebugTime() const;
	bool IsDebugNodeActive() const { return bIsDebugActive; }
	bool WasDebugNodeActive() const { return bWasDebugActive; }

	virtual FName GetFriendlyNodeName() const { return "Node"; }

	/** Configure outdated versions. Currently called from the editor module on load and from pre-compile. */
	bool ConvertToCurrentVersion(bool bOnlyOnLoad = true);
	/** Sets the version field to the current version. No additional changes are made. */
	bool SetToCurrentVersion();
	/** FOR TESTING: Force set to a specific version. */
	void ForceSetVersion(int32 NewVersion);
	/** Brings in old values previously defined in the node and sets them on the template. */
	virtual void ImportDeprecatedProperties() {}

	/** If the node is being pasted in this frame. */
	bool IsBeingPasted() const { return bJustPasted; }

	/** If the node is pre compiling for this frame. */
	bool IsPreCompiling() const { return bIsPrecompiling; }
	
	/** If the node is performing an edit undo / redo. */
	bool IsEditUndo() const { return bIsEditUndo; }
	
	/**
	 * Request the corresponding slate widget refresh itself.
	 * @param bFullRefresh Completely redraw the widget.
	 */
	void RequestSlateRefresh(bool bFullRefresh = false);

	/** Reset any cached values saved. */
	virtual void ResetCachedValues();
	
private:
	friend class SGraphNode_BaseNode;
	FOnGraphNodeRefreshRequested OnGraphNodeRefreshRequestedEvent;
	
protected:
	virtual FLinearColor Internal_GetBackgroundColor() const;
	/** Return the custom color from a specific node instance.
	 *
	 * @param NodeInstance If null then the default NodeInstanceTemplate will be used.
	 */
	const FLinearColor* GetCustomBackgroundColor(const USMNodeInstance* NodeInstance = nullptr) const;

protected:
	UPROPERTY()
	TArray<FSMGraphNodeLog> CollectedLogs;

	UPROPERTY()
	UEdGraph* BoundGraph;

	/** The instanced template to use as an archetype. This node name is used in EditorCustomization directly! */
	UPROPERTY(VisibleDefaultsOnly, Instanced, Category = "Class", meta = (DisplayName=Template, DisplayThumbnail=true))
	USMNodeInstance* NodeInstanceTemplate;

	UPROPERTY(Transient)
	FSlateBrush CachedBrush;

	UPROPERTY(Transient)
	FString CachedTexture;

	UPROPERTY(Transient)
	FVector2D CachedTextureSize;

	UPROPERTY(Transient)
	FLinearColor CachedNodeTintColor;
	
	/** Resets on active change. */
	float DebugTotalTime;
	float MaxTimeToShowDebug;
	
	uint32 bIsDebugActive:	1;
	uint32 bWasDebugActive: 1;

	uint32 bIsPrecompiling: 1;
	uint32 bJustPasted:		1;
	uint32 bIsEditUndo:		1;

	/**
	 * Redirect caused a post edit change, such as a force delete.
	 * Only valid by default during PostEditChangeProperty of this class.
	 */
	uint32 bChangeFromRedirect: 1;
	
public:
	/** Member flag for forcing guid regeneration. */
	uint32 bRequiresGuidRegeneration:	1;
	
	/** True iff bRequiresGuidRegeneration and loaded version wrong. */
	uint32 bNeedsStateStackConversion:	1;

	/** Testing flag for forcing old guid generation WITHOUT template support. */
	uint32 bTEST_ForceNoTemplateGuid:	1;

	/** Property category expansion state for slate node. */
	UPROPERTY(config)
	TMap<FString, bool> PropertyCategoriesExpanded;

protected:
	int32 GetLoadedVersion() const { return LoadedVersion; }
	
private:
	// Graph node properties deprecated in favor of being stored on the node template.
#define TEMPLATE_PROPERTY_VERSION	1
#define STATESTACK_VERSION			2
#define CURRENT_VERSION STATESTACK_VERSION

	/** The current loaded version. Once saved it should be the highest version available. */
	UPROPERTY()
	int32 LoadedVersion = 0;
};
