// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMEditorCommands.h"

#define LOCTEXT_NAMESPACE "SMEditorCommands"

void FSMEditorCommands::RegisterCommands()
{
	UI_COMMAND(GoToGraph, "Go to Local Graph", "Open the graph this node contains within this blueprint", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(GoToNodeBlueprint, "Open Node Blueprint [Pro Only]", "Edit the blueprint for this node if one is set", EUserInterfaceActionType::Button, FInputChord());
	
	UI_COMMAND(CreateSelfTransition, "Link to Self", "Creates a transition within the same state", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(CollapseToStateMachine, "Collapse to State Machine", "Creates a nested state machine from existing nodes", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ConvertToStateMachineReference, "Convert to State Machine Reference", "Save the selected state machine to disk and reference it", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ChangeStateMachineReference, "Change State Machine Reference", "Change the reference to another state machine", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(JumpToStateMachineReference, "Open State Machine Reference", "Open the state machine reference", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(EnableIntermediateGraph, "Enable Intermediate Graph", "Use a graph to manage the state machine entry points", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(DisableIntermediateGraph, "Disable Intermediate Graph", "Let the system manage the entry points", EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(ReplaceWithStateMachine, "State Machine", "Destructively replace the selected node with an empty state machine", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ReplaceWithStateMachineReference, "State Machine Reference", "Destructively replace the selected node with an invalid state machine reference\nSet the reference after using 'Change State Machine Reference'",
		EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ReplaceWithState, "State", "Destructively replace the selected node with an empty state", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ReplaceWithConduit, "Conduit", "Destructively replace the selected node with a conduit", EUserInterfaceActionType::Button, FInputChord());
}

const FSMEditorCommands& FSMEditorCommands::Get()
{
	return TCommands<FSMEditorCommands>::Get();
}

#undef LOCTEXT_NAMESPACE
