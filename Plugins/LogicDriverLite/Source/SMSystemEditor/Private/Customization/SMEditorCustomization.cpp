// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#include "SMEditorCustomization.h"
#include "Graph/Nodes/SMGraphNode_TransitionEdge.h"
#include "Graph/Nodes/SMGraphNode_ConduitNode.h"
#include "Graph/Nodes/SMGraphNode_AnyStateNode.h"
#include "Utilities/SMBlueprintEditorUtils.h"
#include "Utilities/SMNodeInstanceUtils.h"

#include "SMUtils.h"

#include "PropertyCustomizationHelpers.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailChildrenBuilder.h"
#include "Kismet2/KismetEditorUtilities.h"

#define LOCTEXT_NAMESPACE "SMEditorCustomization"


void FSMBaseCustomization::CustomizeDetails(const TSharedPtr<IDetailLayoutBuilder>& DetailBuilder)
{
	DetailBuilderPtr = DetailBuilder;
	CustomizeDetails(*DetailBuilder);
}

void FSMBaseCustomization::HideNestedCategoryHandles(const TSharedPtr<IPropertyHandle>& InHandle)
{
	if (InHandle.IsValid())
	{
		InHandle->MarkHiddenByCustomization();
		uint32 HandleNumChildren;
		InHandle->GetNumChildren(HandleNumChildren);

		for (uint32 CIdx = 0; CIdx < HandleNumChildren; ++CIdx)
		{
			TSharedPtr<IPropertyHandle> ChildProperty = InHandle->GetChildHandle(CIdx);
			HideNestedCategoryHandles(ChildProperty);
		}
	}
}

void FSMBaseCustomization::ForceUpdate()
{
	if (IDetailLayoutBuilder* DetailBuilder = DetailBuilderPtr.Pin().Get())
	{
		DetailBuilder->ForceRefreshDetails();
	}
}

void FSMNodeCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	SelectedGraphNode.Reset();
	USMGraphNode_Base* GraphNode = GetObjectBeingCustomized<USMGraphNode_Base>(DetailBuilder);
	if (!GraphNode)
	{
		return;
	}

	SelectedGraphNode = GraphNode;

	if (USMGraphNode_AnyStateNode* AnyState = Cast<USMGraphNode_AnyStateNode>(GraphNode))
	{
		IDetailCategoryBuilder& StateCategory = DetailBuilder.EditCategory(TEXT("State"));
		StateCategory.SetCategoryVisibility(false);

		IDetailCategoryBuilder& ClassCategory = DetailBuilder.EditCategory(TEXT("Class"));
		ClassCategory.SetCategoryVisibility(false);

		IDetailCategoryBuilder& DisplayCategory =  DetailBuilder.EditCategory(TEXT("Display"));
		DisplayCategory.SetCategoryVisibility(false);

		IDetailCategoryBuilder& AnyStateCategory = DetailBuilder.EditCategory(TEXT("Any State"));

		TArray<TSharedRef<IPropertyHandle>> AnyStateProperties;
		AnyStateCategory.GetDefaultProperties(AnyStateProperties);

		for (const TSharedRef<IPropertyHandle>& Handle : AnyStateProperties)
		{
			check(Handle->IsValidHandle() && Handle->GetProperty());
			if (Handle->GetProperty()->GetFName() == GET_MEMBER_NAME_CHECKED(USMGraphNode_AnyStateNode, AnyStateTags))
			{
				// Because AnyStateTags has special unreal customization we have to manually find the category property
				// and hide. DetailBuilder.GetProperty() will not work.
				DetailBuilder.HideProperty(Handle);
			}
		}
	}

	// Link to node guid.
	if (GraphNode->GetClass()->IsChildOf(USMGraphNode_StateNodeBase::StaticClass()))
	{
		if (const FSMNode_Base* RuntimeNode = FSMBlueprintEditorUtils::GetRuntimeNodeFromGraph(GraphNode->GetBoundGraph()))
		{
			FGuid& GuidStructure = const_cast<FGuid&>(RuntimeNode->GetNodeGuid());
			const TSharedPtr<FStructOnScope> StructToDisplay = MakeShareable(new FStructOnScope(TBaseStructure<FGuid>::Get(),
			                                                                                    reinterpret_cast<uint8*>(&GuidStructure)));

			IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("GraphNodeDetail", /* From BlueprintDetailsCustomization */
				LOCTEXT("GraphNodeDetailsCategory", "Graph Node"), ECategoryPriority::Important);
			IDetailPropertyRow* GuidRow = Category.AddExternalStructure(StructToDisplay, EPropertyLocation::Advanced);
			check(GuidRow);
			GuidRow->DisplayName(LOCTEXT("NodeGuidDisplayName", "Node Guid"));
			GuidRow->ToolTip(LOCTEXT("NodeGuidTooltip", "NodeGuid must always be unique. Do not duplicate the guid in any other node in any blueprint.\
\n\
\nThis is not the same guid that is used at run-time. At run-time all NodeGuids in a path to a node\
\nare hashed to form the PathGuid. This is done to account for multiple references and parent graph calls.\
\n\
\nIf you need to change the path of a node (such as collapse it to a nested state machine) and you need to maintain\
\nthe old guid for run-time saves to work, you should use the GuidRedirectMap on the primary state machine instance\
\nwhich accepts PathGuids."));

			GuidRow->GetPropertyHandle()->SetOnChildPropertyValuePreChange(FSimpleDelegate::CreateLambda([&]()
			{
				if (SelectedGraphNode.IsValid())
				{
					if (USMGraphK2Node_RuntimeNodeContainer* ContainerNode =
						FSMBlueprintEditorUtils::GetRuntimeContainerFromGraph(SelectedGraphNode->GetBoundGraph()))
					{
						ContainerNode->Modify();
					}
				}
			}));
			
			GuidRow->GetPropertyHandle()->SetOnChildPropertyValueChanged(FSimpleDelegate::CreateLambda([&]()
			{
				if (SelectedGraphNode.IsValid())
				{
					if (UBlueprint* Blueprint = FSMBlueprintEditorUtils::FindBlueprintFromObject(SelectedGraphNode.Get()))
					{
						FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
					}
				}
			}));
		}
	}
}

TSharedRef<IDetailCustomization> FSMNodeCustomization::MakeInstance()
{
	return MakeShareable(new FSMNodeCustomization);
}

void FSMNodeInstanceCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	SelectedGraphNode.Reset();
	USMNodeInstance* NodeInstance = GetObjectBeingCustomized<USMNodeInstance>(DetailBuilder);
	if (NodeInstance)
	{
		if (USMGraphNode_Base* GraphNode = Cast<USMGraphNode_Base>(NodeInstance->GetOuter()))
		{
			SelectedGraphNode = GraphNode;
		}
	}
	
	if (!SelectedGraphNode.IsValid())
	{
		// Should only be invalid when editing in the node class editor, in which case everything should be displayed.
		return;
	}
	
	TArray<TSharedRef<IPropertyHandle>> PropertyHandles;
	for (TFieldIterator<FProperty> PropIt(NodeInstance->GetClass(), EFieldIteratorFlags::IncludeSuper); PropIt; ++PropIt)
	{
		const FName PropertyName = PropIt->GetFName();
		TSharedRef<IPropertyHandle> PropertyHandle = DetailBuilder.GetProperty(PropertyName, PropIt->GetOwnerClass());
		if (PropertyHandle->IsValidHandle())
		{
			PropertyHandles.Add(PropertyHandle);
		}
	}

	ProcessNodeInstance(SelectedGraphNode, PropertyHandles, NodeInstance, DetailBuilder);

	// Don't enable alphabetical sorting yet, some categories should be first like GraphNode and Class.
	//DetailBuilder.SortCategories(SortCategories);
}

void FSMNodeInstanceCustomization::ProcessNodeInstance(TWeakObjectPtr<USMGraphNode_Base> GraphNode, const TArray<TSharedRef<IPropertyHandle>>& TemplateProperties,
	class USMNodeInstance* NodeInstance, IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TSharedRef<IPropertyHandle>> ContainerPropertyHandles;
	for (const TSharedRef<IPropertyHandle>& TemplatePropertyHandle : TemplateProperties)
	{
		if (const FProperty* Property = TemplatePropertyHandle->GetProperty())
		{
			// Check for and hide properties which are designed to be edited from class defaults only.
			if (Property->HasMetaData("InstancedTemplate") || (NodeInstance && NodeInstance->GetTemplateGuid().IsValid() && Property->HasMetaData("NodeBaseOnly")))
			{
				HideNestedCategoryHandles(TemplatePropertyHandle);
				continue;
			}
		}
	}
}

TSharedRef<IDetailCustomization> FSMNodeInstanceCustomization::MakeInstance()
{
	return MakeShareable(new FSMNodeInstanceCustomization);
}

USMGraphNode_Base* FSMStructCustomization::GetGraphNodeBeingCustomized(
	IPropertyTypeCustomizationUtils& StructCustomizationUtils, bool bCheckParent) const
{
	return GetObjectBeingCustomized<USMGraphNode_Base>(StructCustomizationUtils, bCheckParent);
}

#undef LOCTEXT_NAMESPACE
