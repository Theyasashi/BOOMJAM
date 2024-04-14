// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FormatterInterface.h"
#include "BlueprintAssistSettings.h"

class FBAGraphHandler;

class BLUEPRINTASSIST_API FBehaviorTreeGraphFormatter final
	: public FFormatterInterface
{
public:
	TSharedPtr<FBAGraphHandler> GraphHandler;
	FBAFormatterSettings FormatterSettings;
	
	TSet<UEdGraphNode*> FormattedNodes;
	TSet<UEdGraphNode*> GetFormattedNodes() override { return FormattedNodes; }

	UEdGraphNode* RootNode;
	UEdGraphNode* GetRootNode() override { return RootNode; }

	FBehaviorTreeGraphFormatter(TSharedPtr<FBAGraphHandler> InGraphHandler);

	~FBehaviorTreeGraphFormatter()
	{
	}

	void FormatNode(UEdGraphNode* Node) override;

private:
	void FormatNodes(UEdGraphNode* Node, TSet<UEdGraphNode*>& VisitedNodes) const;
};
