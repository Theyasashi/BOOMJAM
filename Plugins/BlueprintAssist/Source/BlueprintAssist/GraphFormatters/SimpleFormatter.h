// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FormatterInterface.h"
#include "BlueprintAssistGraphHandler.h"

class BLUEPRINTASSIST_API FSimpleFormatter
	: public FFormatterInterface
{
public:
	TSharedPtr<FBAGraphHandler> GraphHandler;
	FBAFormatterSettings FormatterSettings;
	float TrackSpacing;
	UEdGraphNode* RootNode;
	UEdGraphNode* GetRootNode() override { return RootNode; }
	TSet<UEdGraphNode*> FormattedNodes;
	TMap<UEdGraphNode*, TSharedPtr<FFormatXInfo>> FormatXInfoMap;

	EEdGraphPinDirection FormatterDirection;
	
	TSet<TSharedPtr<FFormatXInfo>> NodesToExpand;

	TArray<FPinLink> Path;

	FCommentHandler CommentHandler;

	FSimpleFormatter(TSharedPtr<FBAGraphHandler> InGraphHandler);

	~FSimpleFormatter()
	{
	}

	void FormatNode(UEdGraphNode* Node) override;

	void FormatX();
	int32 GetChildX(const FPinLink& Link);
	void ExpandPendingNodes();

	
	void FormatY();

	void FormatY_Recursive(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& NodesToCollisionCheck,
		TSet<FPinLink>& VisitedLinks,
		bool bSameRow,
		TSet<UEdGraphNode*>& Children);

	TSet<UEdGraphNode*> GetFormattedNodes() override;

	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking);
	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes);
	FSlateRect GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking);
	FSlateRect GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes);

	virtual FBAFormatterSettings GetFormatterSettings() = 0;
};
