// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UEdGraphNode;

struct BLUEPRINTASSIST_API FFormatterInterface
	: public TSharedFromThis<FFormatterInterface>
{
	virtual ~FFormatterInterface() = default;
	virtual void FormatNode(UEdGraphNode* Node) = 0;
	virtual TSet<UEdGraphNode*> GetFormattedNodes() = 0;
	virtual UEdGraphNode* GetRootNode() = 0;
};
