// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "BlueprintEditor.h"

class USMBlueprint;
class FGGAssetEditorToolbar;

class SMSYSTEMEDITOR_API FSMBlueprintEditor : public FBlueprintEditor
{
public:
	FSMBlueprintEditor();
	virtual ~FSMBlueprintEditor() override;

	void InitSMBlueprintEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, USMBlueprint* Blueprint);

	//  IToolkit interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FString GetDocumentationLink() const override;
	// ~ IToolkit interface

	// FBlueprintEditor
	virtual void CreateDefaultCommands() override;
	virtual void RefreshEditors(ERefreshBlueprintEditorReason::Type Reason /** = ERefreshBlueprintEditorReason::UnknownReason */) override;
	// ~FBlueprintEditor

	/** Return the loaded blueprint as a USMBlueprint. */
	USMBlueprint* GetStateMachineBlueprint() const;

	void CloseInvalidTabs();

	/** Graph nodes selected by the user at the time of a paste operation. */
	const TSet<TWeakObjectPtr<class USMGraphNode_Base>>& GetSelectedGraphNodesDuringPaste() const { return SelectedGraphNodesOnPaste; }

	/** Set when right clicking on a node. */
	TWeakObjectPtr<UEdGraphNode> SelectedNodeForContext;
	
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCreateGraphEditorCommands, FSMBlueprintEditor*, TSharedPtr<FUICommandList>);
	/** Event fired when a graph in a state machine blueprint is renamed. */
	static FOnCreateGraphEditorCommands OnCreateGraphEditorCommandsEvent;
protected:

	// FEditorUndoClient
	virtual void PostUndo(bool bSuccess) override;
	// ~FEditorUndoClient

	/** Extend menu */
	void ExtendMenu();

	/** Extend toolbar */
	void ExtendToolbar();

	void BindCommands();

	/** When a debug object was set for the blueprint being edited. */
	void OnDebugObjectSet(UObject* Object);

	/** Find all nodes for the blueprint and reset their debug state. */
	void ResetBlueprintDebugStates();
	
	/** FBlueprintEditor interface */
	virtual void OnActiveTabChanged(TSharedPtr<SDockTab> PreviouslyActive, TSharedPtr<SDockTab> NewlyActivated) override;
	virtual void OnSelectedNodesChangedImpl(const TSet<UObject*>& NewSelection) override;
	virtual void OnCreateGraphEditorCommands(TSharedPtr<FUICommandList> GraphEditorCommandsList) override;
	virtual void PasteNodes() override;
	/** ~FBlueprintEditor interface */
	
	/** A self transition for the same state. */
	void CreateSingleNodeTransition();
	bool CanCreateSingleNodeTransition() const;

	void CollapseNodesToStateMachine();
	bool CanCollapseNodesToStateMachine() const;

	void ConvertStateMachineToReference();
	bool CanConvertStateMachineToReference() const;

	void ChangeStateMachineReference();
	bool CanChangeStateMachineReference() const;

	void JumpToStateMachineReference();
	bool CanJumpToStateMachineReference() const;

	void EnableIntermediateGraph();
	bool CanEnableIntermediateGraph() const;

	void DisableIntermediateGraph();
	bool CanDisableIntermediateGraph() const;

	void ReplaceWithStateMachine();
	bool CanReplaceWithStateMachine() const;

	void ReplaceWithStateMachineReference();
	bool CanReplaceWithStateMachineReference() const;

	void ReplaceWithStateMachineParent();
	bool CanReplaceWithStateMachineParent() const;
	
	void ReplaceWithState();
	bool CanReplaceWithState() const;

	void ReplaceWithConduit();
	bool CanReplaceWithConduit() const;

	void GoToGraph();
	bool CanGoToGraph() const;

	void GoToNodeBlueprint();
	bool CanGoToNodeBlueprint() const;

private:
	/** The extender to pass to the level editor to extend its window menu */
	TSharedPtr<FExtender> MenuExtender;

	/** Toolbar extender */
	TSharedPtr<FExtender> ToolbarExtender;

	/** The command list for this editor */
	TSharedPtr<FUICommandList> GraphEditorCommands;

	/** Selected state machine graph node */
	TWeakObjectPtr<class USMGraphK2Node_Base> SelectedStateMachineNode;

	/** The currently loaded blueprint. */
	TWeakObjectPtr<UBlueprint> LoadedBlueprint;

	/** When the user sets a debug object. */
	FDelegateHandle OnDebugObjectSetHandle;

	/** Graph nodes selected only at the time of a paste operation. */
	TSet<TWeakObjectPtr<class USMGraphNode_Base>> SelectedGraphNodesOnPaste;
};


class SMSYSTEMEDITOR_API FSMNodeBlueprintEditor : public FBlueprintEditor
{
public:
	FSMNodeBlueprintEditor();
	virtual ~FSMNodeBlueprintEditor();

	// IToolkit interface
	virtual void OnBlueprintChangedImpl(UBlueprint* InBlueprint, bool bIsJustBeingCompiled) override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetDocumentationLink() const override;
	// ~IToolkit interface
};