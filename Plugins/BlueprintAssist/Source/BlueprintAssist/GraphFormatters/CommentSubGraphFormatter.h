// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "FormatterInterface.h"
#include "GraphFormatterTypes.h"
#include "BlueprintAssistSettings.h"
#include "EdGraphParameterFormatter.h"

class FBAGraphHandler;
struct FNodeInfo;
class FSlateRect;
class UEdGraphNode_Comment;

struct FCommentSubGraphFormatterParameters
{
	TSharedPtr<EBAParameterFormattingStyle> OverrideFormattingStyle;
	TArray<UEdGraphNode*> NodesToFormat;
	EBAAutoFormatting FormattingMethod;
	bool bIsCommentFormatter;

	FCommentSubGraphFormatterParameters()
	{
		Reset();
	}

	void Reset()
	{
		bIsCommentFormatter = false;
		FormattingMethod = BAAutoFormat_FormatAllConnected;
		OverrideFormattingStyle = nullptr;
		NodesToFormat.Reset();
	}
};

class FCommentSubGraphFormatter final
	: public FFormatterInterface
{
	TSharedPtr<FBAGraphHandler> GraphHandler;
	UEdGraphNode* RootNode;
	UEdGraphNode* GetRootNode() override { return RootNode; }
	FCommentSubGraphFormatterParameters FormatterParameters;

public:
	bool bHasBeenFormatted;
	
	TMap<UEdGraphNode*, TArray<UEdGraphNode_Comment*>> ParentComments;
	
	FCommentSubGraphFormatter(
		TSharedPtr<FBAGraphHandler> InGraphHandler,
		FCommentSubGraphFormatterParameters InFormatterParameters,
		TSharedPtr<FEdGraphFormatter> InParentFormatter);

	virtual ~FCommentSubGraphFormatter()
	{
	}

	void FormatNode(UEdGraphNode* Node) override;

	TSet<UEdGraphNode*> GetFormattedNodes() override;

	TArray<UEdGraphNode*> GetNodePool() const { return NodePool; }

	UEdGraphNode* GetRootNode() const { return RootNode; }

	TSet<UEdGraphNode*> GetFormattedGraphNodes();

	void RefreshParameters(UEdGraphNode* Node);

	const FCommentSubGraphFormatterParameters& GetFormatterParameters() const { return FormatterParameters; }

private:
	FVector2D PinPadding;
	FVector2D NodePadding;
	float TrackSpacing;
	
	TArray<UEdGraphNode*> NodePool;
	TArray<UEdGraphNode*> NodeTree;
	TMap<UEdGraphNode_Comment*, TArray<UEdGraphNode*>> CommentNodesContains;

	TMap<UEdGraphNode*, TSharedPtr<FEdGraphParameterFormatter>> ParameterFormatterMap;

	TMap<UEdGraphNode*, TSharedPtr<FFormatXInfo>> FormatXInfoMap;

	TArray<FPinLink> Path;

	TSharedPtr<FEdGraphParameterFormatter> MainParameterFormatter;

	TMap<FPinLink, bool> SameRowMapping;

	TMap<UEdGraphNode*, TSharedPtr<FEdGraphParameterFormatter>> ParameterParentMap;

	TArray<TSharedPtr<FFormatXInfo>> NodesToExpand;

	TMap<UEdGraphNode*, TSharedPtr<FCommentSubGraphFormatter>> SubGraphFormatters;

	TSharedPtr<FEdGraphFormatter> ParentFormatter;

	bool bAccountForComments = false;

	void ExpandPendingNodes(bool bUseParameter);

	TArray<UEdGraphNode*> GetNodeTree(UEdGraphNode* InitialNode) const;

	bool IsInitialNodeValid(UEdGraphNode* Node) const;

	void InitNodePool();

	void ExpandBasedOnHeight();

	void InitCommentNodeInfo();
	
	void FormatX(bool bUseParameter);

	void FormatY_Recursive(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& NodesToCollisionCheck,
		TSet<FPinLink>& VisitedLinks,
		bool bSameRow,
		TSet<UEdGraphNode*>& Children);

	void FormatY();

	bool AnyCollisionBetweenPins(UEdGraphPin* Pin, UEdGraphPin* OtherPin);

	bool NodeCollisionBetweenLocation(FVector2D Start, FVector2D End, TSet<UEdGraphNode*> IgnoredNodes);

	void ResetRelativeToNodeToKeepStill(const FSlateRect& SavedBounds);

	void FormatComments();

	FSlateRect GetClusterBoundsForNodes(const TArray<UEdGraphNode*>& Nodes);

	static bool IsExecOrDelegatePin(UEdGraphPin* Pin);

	void GetPinsOfSameHeight();
	void GetPinsOfSameHeight_Recursive(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& NodesToCollisionCheck,
		TSet<FPinLink>& VisitedLinks);

protected:
	TSharedPtr<FEdGraphParameterFormatter> GetParameterFormatter(UEdGraphNode* Node);
};
