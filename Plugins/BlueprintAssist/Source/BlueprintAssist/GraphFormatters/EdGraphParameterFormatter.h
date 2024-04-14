// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "FormatterInterface.h"
#include "BlueprintAssistSettings.h"
#include "GraphFormatterTypes.h"

class FEdGraphFormatter;
class FBAGraphHandler;
struct FNodeEdge;
struct FNodeArray;
class FSlateRect;
class UEdGraphNode;

class BLUEPRINTASSIST_API FEdGraphParameterFormatter final
	: public FFormatterInterface
{
	TSharedPtr<FBAGraphHandler> GraphHandler;
	UEdGraphNode* RootNode;
	UEdGraphNode* GetRootNode() override { return RootNode; }
	TSharedPtr<FEdGraphFormatter> GraphFormatter;
	TArray<UEdGraphNode*> IgnoredNodes;

public:
	TSet<UEdGraphNode*> FormattedInputNodes;
	TSet<UEdGraphNode*> FormattedOutputNodes;
	TSet<UEdGraphNode*> AllFormattedNodes;

	bool bInitialized = false;
	
	FEdGraphParameterFormatter(
		TSharedPtr<FBAGraphHandler> InGraphHandler,
		UEdGraphNode* InRootNode,
		TSharedPtr<FEdGraphFormatter> InGraphFormatter = nullptr,
		TArray<UEdGraphNode*> InIgnoredNodes = TArray<UEdGraphNode*>());

	virtual ~FEdGraphParameterFormatter()
	{
	}

	void FormatNode(UEdGraphNode* Node) override;

	TSet<UEdGraphNode*> GetFormattedNodes() override;

	void SetIgnoredNodes(TArray<UEdGraphNode*> InIgnoredNodes) { IgnoredNodes = InIgnoredNodes; }

	FSlateRect GetBounds();

	FSlateRect GetParameterBounds();

	void ExpandByHeight();

	void SaveRelativePositions();

private:
	bool bFormatWithHelixing;

	TMap<UEdGraphNode*, TSharedPtr<FNodeInfo>> NodeInfoMap;

	bool DoesHelixingApply();

	UEdGraphNode* NodeToKeepStill;

	FVector2D Padding;

	bool bGroupByComments = false;

	TMap<FPinLink, bool> SameRowMapping;

	TMap<UEdGraphNode*, FVector2D> NodeOffsets;

	void ProcessSameRowMapping(UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& VisitedNodes);

	void FormatX();

	void FormatY(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& VisitedNodes,
		bool bSameRow,
		TSet<UEdGraphNode*>& Children);

	int32 GetChildX(const FPinLink& Link,
		const EEdGraphPinDirection Direction) const;

	bool AnyLinkedImpureNodes() const;

	void MoveBelowBaseline(TSet<UEdGraphNode*> Nodes, float Baseline);

	void DebugPrintFormatted();

	void SimpleRelativeFormatting();
};
