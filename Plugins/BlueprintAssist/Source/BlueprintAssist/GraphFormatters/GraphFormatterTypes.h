// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "SGraphPin.h"

class UEdGraphNode_Comment;
class FBAGraphHandler;
class UEdGraphPin;
class UEdGraphNode;
class FEdGraphFormatter;
class FSlateRect;
class UK2Node_Knot;

struct BLUEPRINTASSIST_API FNodeInfo
	: public TSharedFromThis<FNodeInfo>
{
	UEdGraphNode* Node = nullptr;
	UEdGraphPin* Pin = nullptr;
	TSharedPtr<FNodeInfo> Parent = nullptr;
	EEdGraphPinDirection Direction = EGPD_MAX;
	TArray<TSharedPtr<FNodeInfo>> Children;

	FNodeInfo(
		UEdGraphNode* InNode,
		UEdGraphPin* InPin,
		TSharedPtr<FNodeInfo> InParent,
		UEdGraphPin* InParentPin,
		EEdGraphPinDirection InDirection);

	FNodeInfo()
	{
	}

	void SetParent(TSharedPtr<FNodeInfo> NewParent, UEdGraphPin* MyPin);

	int32 GetChildX(
		UEdGraphNode* Child,
		TSharedPtr<FBAGraphHandler> GraphHandler,
		const FVector2D& Padding,
		EEdGraphPinDirection ChildDirection) const;

	bool DetectCycle(TSharedPtr<FNodeInfo> OtherInfo);

	void MoveChildren(
		TSharedPtr<FNodeInfo> Info,
		TSharedPtr<FBAGraphHandler> GraphHandler,
		const FVector2D& Padding,
		TSet<UEdGraphNode*>& TempVisited) const;

	TSharedPtr<FNodeInfo> GetParent() const { return Parent; }
	UEdGraphNode* GetParentNode() const { return !Parent.IsValid() ? nullptr : Parent->Node; }

	FString ToString() const;

	TArray<UEdGraphNode*> GetChildNodes();
};

struct BLUEPRINTASSIST_API FPinLink
{
	UEdGraphPin* From;
	UEdGraphPin* To;
	UEdGraphNode* FallbackNode;

	FGraphPinHandle FromHandle;
	FGraphPinHandle ToHandle;

	UEdGraph* Graph;

	FPinLink()
		: From(nullptr)
		, To(nullptr)
		, FallbackNode(nullptr)
		, FromHandle(nullptr)
		, ToHandle(nullptr)
		, Graph(nullptr)
	{
	}

	FPinLink(UEdGraphPin* InFrom, UEdGraphPin* InTo, UEdGraphNode* InFallbackNode = nullptr)
		: From(InFrom)
		, To(InTo)
		, FallbackNode(InFallbackNode)
		, FromHandle(InFrom)
		, ToHandle(InTo)
	{
		// FromHandle = FGraphPinHandle(InFrom);
		// ToHandle = FGraphPinHandle(InTo);

		if (InFrom != nullptr)
		{
			Graph = InFrom->GetOwningNodeUnchecked()->GetGraph();
		}
		else if (InTo != nullptr)
		{
			Graph = InTo->GetOwningNodeUnchecked()->GetGraph();
		}
		else
		{
			Graph = nullptr;
		}
	}

	bool operator==(const FPinLink& Other) const
	{
		return FromHandle == Other.FromHandle && ToHandle == Other.ToHandle;
	}

	bool operator!=(const FPinLink& Other) const
	{
		return !(*this == Other);
	}

	friend uint32 GetTypeHash(const FPinLink& Link)
	{
		return HashCombine(GetTypeHash(Link.FromHandle), GetTypeHash(Link.ToHandle));
	}

	UEdGraphPin* GetFromPin() const;
	UEdGraphPin* GetToPin() const;
	
	UEdGraphNode* GetFromNode() const;
	UEdGraphNode* GetToNode() const;
	
	UEdGraphNode* GetNode() const;

	UEdGraphPin* GetFromPinUnsafe() const { return From; }
	UEdGraphPin* GetToPinUnsafe() const { return To; }
	UEdGraphNode* GetFromNodeUnsafe() const { return (From == nullptr) ? nullptr : From->GetOwningNodeUnchecked(); }
	UEdGraphNode* GetToNodeUnsafe() const { return (To == nullptr) ? nullptr : To->GetOwningNodeUnchecked(); }

	EEdGraphPinDirection GetDirection() const;

	FString ToString() const;
};

struct BLUEPRINTASSIST_API FKnotNodeCreation
	: public TSharedFromThis<FKnotNodeCreation>
{
	TSharedPtr<struct FKnotNodeTrack> OwningKnotTrack;
	
	bool bMakeLinkForPrevious = false;

	FVector2D KnotPos;
	TSharedPtr<FKnotNodeCreation> KnotToConnectTo = nullptr;
	UK2Node_Knot* CreatedKnot = nullptr;

	FGraphPinHandle PinToConnectToHandle;
	TSet<FGraphPinHandle> PinHandlesToConnectTo;

	int CreationIndex = -1;

	FKnotNodeCreation() : PinToConnectToHandle(nullptr)
	{
	}

	FKnotNodeCreation(
		const FVector2D InKnotPos,
		TSharedPtr<FKnotNodeCreation> InKnotToConnectTo,
		UEdGraphPin* InPinToConnectTo)
		: KnotPos(InKnotPos)
		, KnotToConnectTo(InKnotToConnectTo)
		, PinToConnectToHandle(InPinToConnectTo)
	{
		if (InPinToConnectTo != nullptr)
			PinHandlesToConnectTo.Add(PinToConnectToHandle);
	}

	UK2Node_Knot* CreateKnotNode(FVector2D InKnotPos, UEdGraphPin* PreviousPin, UK2Node_Knot* KnotNodeToReuse, UEdGraph* Graph);

	bool HasHeightDifference() const;
};

struct BLUEPRINTASSIST_API FKnotNodeTrack
	: public TSharedFromThis<FKnotNodeTrack>
{
	TSharedPtr<FBAGraphHandler> GraphHandler;
	UEdGraphPin* ParentPin;
	TArray<UEdGraphPin*> LinkedTo;

private:
	float TrackHeight;

public:
	float GetTrackHeight() const;

	bool bTrackExpandsUpwards;
	FGraphPinHandle PinToAlignTo;
	float PinAlignedX;

	FVector2D ParentPinPos;

	TArray<TSharedPtr<FKnotNodeCreation>> KnotCreations;
	bool bIsLoopingTrack = false;

	FKnotNodeTrack(
		TSharedPtr<FEdGraphFormatter> Formatter,
		TSharedPtr<FBAGraphHandler> InGraphHandler,
		UEdGraphPin* InParentPin,
		TArray<UEdGraphPin*> InLinkedTo,
		float InTrackY,
		bool bInTrackExpandsUpwards);

	UEdGraphPin* GetParentPin() const;
	
	UEdGraphPin* GetLastPin() const;

	UEdGraphPin* GetPinToAlignTo() const;

	FSlateRect GetTrackBounds() const;

	TArray<FGraphPinHandle> GetLinkedToSafe();

	void SetTrackHeight(TSharedPtr<FEdGraphFormatter> Formatter);

	bool IsFloatingTrack() const;

	void UpdateTrackHeight(float NewTrackY);

	TSet<UEdGraphNode*> GetNodes(UEdGraph* Graph);

	bool DoesTrackOverlapNode(UEdGraphNode* Node) const;

	void AddKnotNodeForPin(UEdGraphPin* Pin, const FVector2D& NodePadding);

	bool HasPinToAlignTo() const;

	FString ToString();
};

struct BLUEPRINTASSIST_API FFormatXInfo
	: public TSharedFromThis<FFormatXInfo>
{
	FPinLink Link;
	TSharedPtr<FFormatXInfo> Parent;
	TArray<TSharedPtr<FFormatXInfo>> Children;

	FFormatXInfo(const FPinLink& InLink, TSharedPtr<FFormatXInfo> InParent);

	UEdGraphNode* GetNode() const;

	TArray<UEdGraphNode*> GetChildren(EEdGraphPinDirection Direction = EGPD_MAX, bool bInitialDirectionOnly = true) const;

	TArray<UEdGraphNode*> GetImmediateChildren() const;
	
	TArray<FPinLink> GetChildrenAsLinks(EEdGraphPinDirection Direction = EGPD_MAX) const;

	void SetParent(TSharedPtr<FFormatXInfo> NewParent);

	TSharedPtr<FFormatXInfo> GetRootParent();
};

struct BLUEPRINTASSIST_API FCommentHandler
	: public TSharedFromThis<FCommentHandler>
{
	TSharedPtr<FBAGraphHandler> GraphHandler;
	TMap<UEdGraphNode*, TArray<UEdGraphNode_Comment*>> ParentComments;
	TMap<UEdGraphNode_Comment*, TArray<UEdGraphNode*>> CommentNodesContains;

	FCommentHandler(TSharedPtr<FBAGraphHandler> InGraphHandler = nullptr);

	void Init(TSharedPtr<FBAGraphHandler> InGraphHandler);
	
	FSlateRect GetCommentBounds(
		UEdGraphNode_Comment* CommentNode,
		UEdGraphNode* NodeAsking);

	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking);
	FSlateRect GetRelativeNodeBounds(UEdGraphNode* Node, UEdGraphNode* NodeAsking, TSet<UEdGraphNode*>& OutRelativeNodes);
};
