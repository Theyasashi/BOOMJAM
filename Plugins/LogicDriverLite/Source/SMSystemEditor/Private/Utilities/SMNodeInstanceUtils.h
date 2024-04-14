// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once
#include "Kismet2/BlueprintEditorUtils.h"


// Helpers for managing node instances and related objects.
class SMSYSTEMEDITOR_API FSMNodeInstanceUtils
{
public:
	enum class ENodeStackType : uint8
	{
		None,
		StateStack,
		TransitionStack
	};
	
	/** Recursively checks a child to see if it belongs to a parent. */
	static bool IsWidgetChildOf(TSharedPtr<SWidget> Parent, TSharedPtr<SWidget> PossibleChild);

};

