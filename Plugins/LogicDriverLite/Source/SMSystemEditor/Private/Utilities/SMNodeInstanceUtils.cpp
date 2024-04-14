// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "Utilities/SMNodeInstanceUtils.h"
#include "Layout/Children.h"
#include "SMBlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "SMNodeInstanceUtils"


bool FSMNodeInstanceUtils::IsWidgetChildOf(TSharedPtr<SWidget> Parent, TSharedPtr<SWidget> PossibleChild)
{
	FChildren* Children = Parent->GetChildren();
	for (int32 i = 0; i < Children->Num(); ++i)
	{
		TSharedRef<SWidget> Child = Children->GetChildAt(i);
		if (Child == PossibleChild)
		{
			return true;
		}
		return IsWidgetChildOf(Child, PossibleChild);
	}

	return false;
}

#undef LOCTEXT_NAMESPACE
