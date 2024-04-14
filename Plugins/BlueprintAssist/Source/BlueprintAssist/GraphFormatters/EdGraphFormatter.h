// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "FormatterInterface.h"
#include "GraphFormatterTypes.h"
#include "BlueprintAssistSettings.h"
#include "EdGraphParameterFormatter.h"
#include "CommentSubGraphFormatter.h"

class FBAGraphHandler;
struct FKnotNodeTrack;
struct FNodeInfo;
class FSlateRect;
class UEdGraphNode_Comment;

struct FEdGraphFormatterParameters
{
	TSharedPtr<EBAParameterFormattingStyle> OverrideFormattingStyle;
	TArray<UEdGraphNode*> NodesToFormat;
	EBAAutoFormatting FormattingMethod;

	FEdGraphFormatterParameters()
	{
		Reset();
	}

	void Reset()
	{
		FormattingMethod = BAAutoFormat_FormatAllConnected;
		OverrideFormattingStyle = nullptr;
		NodesToFormat.Reset();
	}
};

struct FNodeChangeInfo
{
	bool bIsNodeToKeepStill;
	UEdGraphNode* Node;
	TArray<FPinLink> Links;
	int32 NodeX;
	int32 NodeY;

	int32 NodeOffsetX;
	int32 NodeOffsetY;

	FNodeChangeInfo(UEdGraphNode* Node, UEdGraphNode* NodeToKeepStill);

	void UpdateValues(UEdGraphNode* NodeToKeepStill);

	bool HasChanged(UEdGraphNode* NodeToKeepStill);
};

struct ChildBranch
{
	UEdGraphPin* Pin;
	UEdGraphPin* ParentPin;
	TSet<UEdGraphNode*> BranchNodes;
			
	ChildBranch(UEdGraphPin* InPin, UEdGraphPin* InParentPin, TSet<UEdGraphNode*>& InBranchNodes)
        : Pin(InPin)
        , ParentPin(InParentPin)
        , BranchNodes(InBranchNodes)
	{
	}

	bool operator==(const ChildBranch& Other) const
	{
		return FPinLink(Pin, ParentPin) == FPinLink(Other.Pin, Other.ParentPin);
	}
};

class FEdGraphFormatter final
	: public FFormatterInterface
	// , public TSharedFromThis<FEdGraphFormatter>
	
{
	TSharedPtr<FBAGraphHandler> GraphHandler;
	UEdGraphNode* RootNode;
	UEdGraphNode* GetRootNode() override { return RootNode; }
	FEdGraphFormatterParameters FormatterParameters;

public:
	TMap<UEdGraphNode*, TArray<UEdGraphNode_Comment*>> ParentComments;
	
	FEdGraphFormatter(
		TSharedPtr<FBAGraphHandler> InGraphHandler,
		FEdGraphFormatterParameters InFormatterParameters);

	virtual ~FEdGraphFormatter()
	{
	}

	void FormatNode(UEdGraphNode* Node) override;

	TSet<UEdGraphNode*> GetFormattedNodes() override;

	TArray<UEdGraphNode*> GetNodePool() const { return NodePool; }

	UEdGraphNode* GetRootNode() const { return RootNode; }

	TSet<UEdGraphNode*> GetFormattedGraphNodes();

	void RefreshParameters(UEdGraphNode* Node);

	const FEdGraphFormatterParameters& GetFormatterParameters() const { return FormatterParameters; }

	TSharedPtr<FEdGraphParameterFormatter> GetParameterFormatter(UEdGraphNode* Node);

private:
	FVector2D PinPadding;
	FVector2D NodePadding;
	float TrackSpacing;
	float VerticalPinSpacing;
	bool bCenterBranches;
	int NumRequiredBranches;

	TArray<UEdGraphNode*> NodePool;
	TArray<UEdGraphNode*> NodeTree;
	TMap<UEdGraphNode_Comment*, TArray<UEdGraphNode*>> CommentNodesContains;

	TMap<UEdGraphNode*, TSharedPtr<FEdGraphParameterFormatter>> ParameterFormatterMap;

	TSet<UEdGraphNode*> KnotNodesSet;
	TArray<TSharedPtr<FKnotNodeTrack>> KnotTracks;

	UEdGraphNode* NodeToKeepStill = nullptr;
	int32 LastFormattedX;
	int32 LastFormattedY;

	TMap<UEdGraphNode*, FVector2D> LastNodePositions;

	TMap<UEdGraphNode*, FNodeChangeInfo> NodeChangeInfos;

	TMap<UEdGraphNode*, TSharedPtr<FFormatXInfo>> FormatXInfoMap;

	TArray<FPinLink> Path;

	TArray<UK2Node_Knot*> KnotNodePool;

	TSharedPtr<FEdGraphParameterFormatter> MainParameterFormatter;

	TMap<FPinLink, bool> SameRowMapping;

	TMap<UEdGraphNode*, TSharedPtr<FEdGraphParameterFormatter>> ParameterParentMap;

	TArray<TSharedPtr<FFormatXInfo>> NodesToExpand;

	TMap<UEdGraphNode*, TSharedPtr<FCommentSubGraphFormatter>> SubGraphFormatters;

	TMap<UK2Node_Knot*, UEdGraphNode*> KnotNodeOwners;

	TMap<UEdGraphNode*, int> NodeHeightLevels;

	void ExpandPendingNodes(bool bUseParameter);

	void SimpleRelativeFormatting();

	bool IsFormattingRequired(const TArray<UEdGraphNode*>& NewNodeTree);

	void SaveFormattingEndInfo();

	TArray<UEdGraphNode*> GetNodeTree(UEdGraphNode* InitialNode) const;

	bool IsInitialNodeValid(UEdGraphNode* Node) const;

	void InitNodePool();

	void ExpandByHeight();

	void InitCommentNodeInfo();
	
	void FormatX(bool bUseParameter);

	bool bAccountForComments = false;
	void FormatY_Recursive(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& NodesToCollisionCheck,
		TSet<FPinLink>& VisitedLinks,
		bool bSameRow,
		TSet<UEdGraphNode*>& Children);

	void FormatY();

	void CenterBranches(UEdGraphNode* CurrentNode, TArray<ChildBranch>& ChildBranches, TSet<UEdGraphNode*>& NodesToCollisionCheck);

	void FormatKnotNodes();

	void MakeKnotTrack();

	void MakeKnotTracksForLinkedExecPins(UEdGraphPin* ParentPin, TArray<UEdGraphPin*> LinkedPins, bool& bPreviousHasTrack);

	void MakeKnotTracksForParameterPins(UEdGraphPin* ParentPin, TArray<UEdGraphPin*> LinkedPins, bool& bPreviousHasTrack);

	void MergeNearbyKnotTracks();

	void ExpandKnotTracks();

	void CreateKnotTracks();

	bool TryAlignTrackToEndPins(TSharedPtr<FKnotNodeTrack> Track, const TArray<UEdGraphNode*>& AllNodes);

	bool DoesPinNeedTrack(UEdGraphPin* Pin, const TArray<UEdGraphPin*>& LinkedTo);

	bool AnyCollisionBetweenPins(UEdGraphPin* Pin, UEdGraphPin* OtherPin);

	bool NodeCollisionBetweenLocation(FVector2D Start, FVector2D End, TSet<UEdGraphNode*> IgnoredNodes);

	void FormatParameterNodes();

	void ResetRelativeToNodeToKeepStill(const FVector2D& SavedLocation);
	
	void FormatComments();

	void RemoveKnotNodes();

	static bool IsExecOrDelegatePin(UEdGraphPin* Pin);

	void ModifyCommentNodes();

	UK2Node_Knot* CreateKnotNode(FKnotNodeCreation* Creation, const FVector2D& Position, UEdGraphPin* ParentPin);

	void GetPinsOfSameHeight();
	void GetPinsOfSameHeight_Recursive(
		UEdGraphNode* CurrentNode,
		UEdGraphPin* CurrentPin,
		UEdGraphPin* ParentPin,
		TSet<UEdGraphNode*>& NodesToCollisionCheck,
		TSet<FPinLink>& VisitedLinks);

	void AddKnotNodesToComments();

	UEdGraphNode* GetHighestLevelParentNode(UEdGraphNode* Node);

	void WrapNodes();

protected:
	int32 GetChildX(const FPinLink& Link, bool bUseClusterNodes);

	FSlateRect GetClusterBounds(UEdGraphNode* Node);
	FSlateRect GetClusterBoundsForNodes(const TArray<UEdGraphNode*>& Nodes);

	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes, bool bUseClusterBounds);
	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, bool bUseClusterBounds);

	FSlateRect GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, bool bUseClusterBounds);
	FSlateRect GetRelativeBoundsForNodes(const TArray<UEdGraphNode*>& Nodes, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& RelativeNodes, bool bUseClusterBounds);

	FSlateRect GetRelativeClusterBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking);
	
	FSlateRect GetCommentNodeBounds(UEdGraphNode_Comment* CommentNode, const FSlateRect& InBounds, FMargin& PostPadding);
	FSlateRect GetCommentBounds(UEdGraphNode_Comment* CommentNode, UEdGraphNode* NodeAsking);

	void ApplyCommentPadding(FSlateRect& Bounds, UEdGraphNode* Node, EEdGraphPinDirection Direction);

	friend class FEdGraphParameterFormatter;
	friend class FCommentSubGraphFormatter;
	friend struct FNodeInfo;
	friend struct FKnotNodeTrack;
};
