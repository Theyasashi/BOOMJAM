// Copyright Recursoft LLC 2019-2022. All Rights Reserved.
#pragma once

#include "Editor/Kismet/Public/BlueprintEditorModes.h"

#define LOCTEXT_NAMESPACE "SMEditorModes"


// This is the list of IDs for SM Editor modes
struct FSMEditorModes
{
	// App Name
	static const FName SMEditorName;

	// Mode constants
	static const FName SMBlueprintMode;

	static FText GetLocalizedMode(const FName InMode)
	{
		static TMap< FName, FText > LocModes;

		if (LocModes.Num() == 0)
		{
			LocModes.Add(SMBlueprintMode, NSLOCTEXT("SMEditorModes", "SMBlueprintMode", "Graph"));
		}

		check(InMode != NAME_None);
		const FText* OutDesc = LocModes.Find(InMode);
		check(OutDesc);
		return *OutDesc;
	}
private:
	FSMEditorModes() {}
};

class FSMEditorBlueprintMode : public FBlueprintEditorApplicationMode
{
public:
	FSMEditorBlueprintMode(TSharedPtr<class FSMBlueprintEditor> EditorIn);
	~FSMEditorBlueprintMode();

	// FApplicationMode interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	// End of FApplicationMode interface
private:
	TWeakPtr<class FSMBlueprintEditor> Editor;

	FWorkflowAllowedTabSet EditorTabFactories;

};

#undef LOCTEXT_NAMESPACE