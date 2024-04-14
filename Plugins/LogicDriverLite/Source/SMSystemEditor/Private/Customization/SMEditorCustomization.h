// Copyright Recursoft LLC 2019-2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "Blueprints/SMBlueprintGeneratedClass.h"
#include "IPropertyUtilities.h"
#include "Modules/ModuleManager.h"

template<typename T>
static T* GetObjectBeingCustomized(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> Objects;
	DetailBuilder.GetObjectsBeingCustomized(Objects);
	for (TWeakObjectPtr<UObject> Object : Objects)
	{
		if (T* CastedObject = Cast<T>(Object.Get()))
		{
			return CastedObject;
		}
	}

	return nullptr;
}

static EVisibility VisibilityConverter(bool bValue)
{
	return bValue ? EVisibility::Visible : EVisibility::Collapsed;
}

class FSMBaseCustomization : public IDetailCustomization
{
public:
	// IDetailCustomization
	virtual void CustomizeDetails(const TSharedPtr<IDetailLayoutBuilder>& DetailBuilder) override;
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override {}
	// ~IDetailCustomization

	/** Recursively hide all handles. */
	static void HideNestedCategoryHandles(const TSharedPtr<IPropertyHandle>& InHandle);
protected:
	void ForceUpdate();
	
	TWeakPtr<IDetailLayoutBuilder> DetailBuilderPtr;
};

class FSMNodeCustomization : public FSMBaseCustomization
{
public:
	// IDetailCustomization
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	// ~IDetailCustomization

	static TSharedRef<IDetailCustomization> MakeInstance();

protected:
	TWeakObjectPtr<class USMGraphNode_Base> SelectedGraphNode;
};

class FSMNodeInstanceCustomization : public FSMBaseCustomization {
public:
	// IDetailCustomization
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	// ~IDetailCustomization

	/**
	 * Handle the details panel for exposed graph properties for all node instances.
	 *
	 * @param GraphNode					The selected graph node.
	 * @param TemplateProperties		All template properties to check.
	 * @param NodeInstance				The node instance template containing the properties.
	 * @param DetailBuilder				The detail builder to use.
	 * 
	 */
	static void ProcessNodeInstance(TWeakObjectPtr<USMGraphNode_Base> GraphNode, const TArray<TSharedRef<IPropertyHandle>>& TemplateProperties,
		class USMNodeInstance* NodeInstance, IDetailLayoutBuilder& DetailBuilder);

	/**
	 * Display a single exposed property widget in the details panel. Can be called from either state base or state stack.
	 *
	 * @param GraphNode					The selected graph node.
	 * @param PropertyHandle			The specific template property.
	 * @param NodeInstance				The node instance template containing the properties.
	 * @param DetailBuilder				The detail builder to use if ChildrenBuilder is not supplied.
	 * @param ChildrenBuilder			A child builder if being called from struct customization, such as for the state stack.
	 */
	static void DisplayExposedPropertyWidget(TWeakObjectPtr<USMGraphNode_Base> GraphNode, const TSharedRef<IPropertyHandle>& PropertyHandle, class USMNodeInstance* NodeInstance,
		IDetailLayoutBuilder* DetailBuilder = nullptr, IDetailChildrenBuilder* ChildrenBuilder = nullptr);
	
	static TSharedRef<IDetailCustomization> MakeInstance();

protected:
	TWeakObjectPtr<USMGraphNode_Base> SelectedGraphNode;
};

class FSMStructCustomization : public IPropertyTypeCustomization
{
public:
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> InPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override
	{
		PropertyHandle = InPropertyHandle;
		check(PropertyHandle.IsValid());
	}
	
	class USMGraphNode_Base* GetGraphNodeBeingCustomized(IPropertyTypeCustomizationUtils& StructCustomizationUtils, bool bCheckParent = false) const;

	/** Register the given struct with the Property Editor. */
	template<typename T>
	static void RegisterNewStruct(const FName& Name)
	{
		if (RegisteredStructs.Contains(Name))
		{
			return;
		}
		RegisteredStructs.Add(Name);
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.RegisterCustomPropertyTypeLayout(Name, FOnGetPropertyTypeCustomizationInstance::CreateStatic(&T::MakeInstance));
	}

	/** Unregister all previously registered structs from the Property Editor. */
	static void UnregisterAllStructs()
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		for (const FName& Name : RegisteredStructs)
		{
			PropertyModule.UnregisterCustomPropertyTypeLayout(Name);
		}
	}
	
	template<typename T>
	T* GetObjectBeingCustomized(IPropertyTypeCustomizationUtils& StructCustomizationUtils,
	                            bool bCheckParent = false) const
	{
		const TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized = StructCustomizationUtils
			.GetPropertyUtilities()->GetSelectedObjects();

		if (ObjectsBeingCustomized.Num() != 1)
		{
			return nullptr;
		}

		if (T* GraphNode = Cast<T>(ObjectsBeingCustomized[0]))
		{
			return GraphNode;
		}

		if (bCheckParent)
		{
			return Cast<T>(ObjectsBeingCustomized[0]->GetOuter());
		}

		return nullptr;
	}

protected:
	TSharedPtr<IPropertyHandle> PropertyHandle;

private:
	static TSet<FName> RegisteredStructs;
};
