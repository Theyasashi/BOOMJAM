// Copyright 2020 fpwong, Inc. All Rights Reserved.

#include "CreateVariableMenu.h"
#include "EditorStyleSet.h"
#include "Framework/Application/SlateApplication.h"

#include "Widgets/Layout/SBox.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Views/STableRow.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Widgets/Input/SButton.h"
#include "BlueprintAssistUtils.h"

#include "K2Node_Event.h"
#include "BlueprintEditor.h"
#include "BlueprintAssistGraphHandler.h"
#include "SPinTypeSelector.h"
#include "Kismet2/Kismet2NameValidators.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Layout/SSpacer.h"

void SCreateVariableMenu::Construct(
	const FArguments& InArgs,
	TSharedPtr<FBAGraphHandler> InGraphHandler)
{
	GraphHandler = InGraphHandler;

	UpdateMenuWidget();
}

void SCreateVariableMenu::UpdateMenuWidget()
{
	const UBASettings* BASettings = GetDefault<UBASettings>();

	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	FName UniqueVarName = FBlueprintEditorUtils::FindUniqueKismetName(GraphHandler->GetBlueprint(), BASettings->DefaultVariableName);
	VariableName = FText::FromName(UniqueVarName);
	VariableNameTextBox = MakeBoundEditableText(VariableName);

	CategoryText = BASettings->DefaultCategory;
	CategoryTextBox = MakeBoundEditableText(CategoryText);

	TooltipText = BASettings->DefaultTooltip;
	TooltipTextBox = MakeBoundEditableText(TooltipText);

	SimpleDefaultValue = FText::FromString(TEXT(""));
	SimpleDefaultValueTextBox = MakeBoundEditableText(SimpleDefaultValue);

	bInstanceEditable = BASettings->bDefaultInstanceEditable;
	InstanceEditableCheckBox = MakeBoundCheckBox(bInstanceEditable);

	bBlueprintReadOnly = BASettings->bDefaultBlueprintReadOnly;
	BlueprintReadOnlyCheckBox = MakeBoundCheckBox(bBlueprintReadOnly);

	bExposeOnSpawn = BASettings->bDefaultExposeOnSpawn;
	ExposeOnSpawnCheckBox = SNew(SCheckBox)
    .IsChecked(bExposeOnSpawn ? ECheckBoxState::Checked : ECheckBoxState::Unchecked)
    .OnCheckStateChanged(this, &SCreateVariableMenu::OnExposeOnSpawnChanged);

	bPrivate = BASettings->bDefaultPrivate;
	PrivateCheckBox = MakeBoundCheckBox(bPrivate);

	bExposeToCinematics = BASettings->bDefaultExposeToCinematics;
	ExposeToCinematicsCheckBox = MakeBoundCheckBox(bExposeToCinematics);

	// make the pin selector
	PinType.PinCategory = UEdGraphSchema_K2::PC_Boolean;

	TSharedRef<SPinTypeSelector> PinSelectorWidget = SNew(SPinTypeSelector, FGetPinTypeTree::CreateUObject(K2Schema, &UEdGraphSchema_K2::GetVariableTypeTree))
    .TargetPinType(this, &SCreateVariableMenu::OnGetPinType)
    .OnPinTypeChanged(this, &SCreateVariableMenu::OnPinTypeChanged)
    .Schema(K2Schema)
#if ENGINE_MINOR_VERSION >= 23
	.TypeTreeFilter(ETypeTreeFilter::None)
	.SelectorType(SPinTypeSelector::ESelectorType::Full);
#else
	.TypeTreeFilter(ETypeTreeFilter::None);
#endif

	FVector2D WidgetSize = GetWidgetSize();

	SBorder::Construct(
		SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(8)
		[
			SNew(SBox)
			.WidthOverride(WidgetSize.X)
			.HeightOverride(WidgetSize.Y)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().Padding(2, 2, 2, 5)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("Create variable")))
					.Font(FEditorStyle::GetFontStyle(FName("BlueprintEditor.ActionMenu.ContextDescriptionFont")))
					.WrapTextAt(280)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Variable Name", VariableNameTextBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Default Value", SimpleDefaultValueTextBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Pin Type", PinSelectorWidget)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Category", CategoryTextBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Instance Editable", InstanceEditableCheckBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Blueprint Read Only", BlueprintReadOnlyCheckBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Expose on Spawn", ExposeOnSpawnCheckBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Private", PrivateCheckBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Expose to Cinematics", ExposeToCinematicsCheckBox)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					MakeRow("Tooltip", TooltipTextBox)
				]
				+ SVerticalBox::Slot().FillHeight(1)
				[
					SNew(SSpacer)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					SNew(STextBlock)
                    .Justification(ETextJustify::Center)
                    .ColorAndOpacity(FLinearColor::Red)
                    .Text(this, &SCreateVariableMenu::GetErrorText)
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(4)
				[
					SNew(SButton)
                    .OnClicked(this, &SCreateVariableMenu::OnCreateButtonClicked)
                    .IsEnabled(this, &SCreateVariableMenu::IsValidInput)
					[
						SNew(STextBlock)
		                .Text(FText::FromString(TEXT("Create")))
		                .WrapTextAt(280)
					]
				]
			]
		]
	);
}


FReply SCreateVariableMenu::OnCreateButtonClicked()
{
	CreateVariable();

	return FReply::Handled();
}

void SCreateVariableMenu::CreateVariable()
{
	if (!IsValidInput())
	{
		return;
	}

	if (!GraphHandler.IsValid())
	{
		return;
	}

	UBlueprint* Blueprint = GraphHandler->GetBlueprint();
	if (!Blueprint)
	{
		return;
	}

	const FName VarName = FName(*VariableNameTextBox->GetText().ToString());

	const FString DefaultValue = DefaultValueString;
	FBlueprintEditorUtils::AddMemberVariable(Blueprint, VarName, PinType, DefaultValue);

	// this is stupid but seems to be the only way to get our newly created variable
	if (Blueprint->NewVariables.Num() > 0)
	{
		FBPVariableDescription& MyNewVar = Blueprint->NewVariables.Last();

		if (bInstanceEditable)
		{
			FBlueprintEditorUtils::SetBlueprintOnlyEditableFlag(Blueprint, VarName, false);
		}

		if (bBlueprintReadOnly)
		{
			FBlueprintEditorUtils::SetBlueprintPropertyReadOnlyFlag(Blueprint, VarName, true);
		}

		if (bExposeOnSpawn)
		{
			MyNewVar.MetaDataArray.Add(FBPVariableMetaDataEntry(FBlueprintMetadata::MD_ExposeOnSpawn, "true"));
		}

		// set private
		if (bPrivate)
		{
			FBlueprintEditorUtils::SetBlueprintVariableMetaData(Blueprint, VarName, nullptr, FBlueprintMetadata::MD_Private, TEXT("true"));
		}

		if (bExposeToCinematics)
		{
			FBlueprintEditorUtils::SetInterpFlag(Blueprint, VarName, true);
		}

		// set category
		MyNewVar.Category = CategoryText;

		// set tooltip
		FBlueprintEditorUtils::SetBlueprintVariableMetaData(Blueprint, VarName, nullptr, FBlueprintMetadata::MD_Tooltip, TooltipText.ToString());

		// TODO: add gui for this
		// set replication: 
		// MyNewVar.PropertyFlags |= CPF_Net;

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
	}

	FSlateApplication::Get().DismissMenuByWidget(SharedThis(this));
}

TSharedPtr<SWidget> SCreateVariableMenu::GetWidgetToFocus()
{
	return VariableNameTextBox;
}

FEdGraphPinType SCreateVariableMenu::OnGetPinType() const
{
	return PinType;
}

void SCreateVariableMenu::OnPinTypeChanged(const FEdGraphPinType& NewPinType)
{
	PinType = NewPinType;
}

TSharedRef<SSplitter> SCreateVariableMenu::MakeRow(FString PropertyName, TSharedPtr<SWidget> Widget)
{
	return SNew(SSplitter)
		.Orientation(EOrientation::Orient_Horizontal)
		+ SSplitter::Slot()
		.Value(0.4f)
		[
			SNew(STextBlock)
			.Text(FText::FromString(PropertyName))
		]
		+ SSplitter::Slot()
		.Value(0.6f)
		[
			Widget.ToSharedRef()
		];
}

TSharedRef<SCheckBox> SCreateVariableMenu::MakeBoundCheckBox(bool& VariableToBindTo)
{
	const auto SetVariableValue = [&VariableToBindTo](ECheckBoxState CheckBoxState)
	{
		VariableToBindTo = (CheckBoxState == ECheckBoxState::Checked);
	};

	return SNew(SCheckBox).IsChecked(VariableToBindTo ? ECheckBoxState::Checked : ECheckBoxState::Unchecked).OnCheckStateChanged_Lambda(SetVariableValue);
}

TSharedRef<SEditableTextBox> SCreateVariableMenu::MakeBoundEditableText(FText& TextToBindTo)
{
	const auto OnTextChanged = [&TextToBindTo](const FText& Text)
	{
		TextToBindTo = Text;
	};

	return SNew(SEditableTextBox)
    .Text(TextToBindTo)
    .OnTextChanged_Lambda(OnTextChanged)
    .OnTextCommitted(this, &SCreateVariableMenu::OnEditableTextCommitted);
}

void SCreateVariableMenu::OnEditableTextCommitted(const FText& Text, ETextCommit::Type CommitType)
{
	if (CommitType == ETextCommit::OnEnter)
	{
		CreateVariable();
	}
}

void SCreateVariableMenu::OnExposeOnSpawnChanged(ECheckBoxState CheckBoxState)
{
	bExposeOnSpawn = (CheckBoxState == ECheckBoxState::Checked);
	if (bExposeOnSpawn && !bInstanceEditable)
	{
		bInstanceEditable = true;
		InstanceEditableCheckBox->SetIsChecked(ECheckBoxState::Checked);
	}
}

bool SCreateVariableMenu::IsValidInput() const
{
	FKismetNameValidator NameValidator(GraphHandler->GetBlueprint());
	if (NameValidator.IsValid(VariableName.ToString()) == EValidatorResult::Ok)
	{
		return true;
	}

	return false;
}

FText SCreateVariableMenu::GetErrorText() const
{
	FKismetNameValidator NameValidator(GraphHandler->GetBlueprint());
	EValidatorResult Result = NameValidator.IsValid(VariableName.ToString());

	switch (Result)
	{
	case EValidatorResult::Ok:
	case EValidatorResult::ExistingName:
		break;
	default:
		return INameValidatorInterface::GetErrorText(VariableName.ToString(), Result);
	}

	return FText::FromString("");
}

FReply SCreateVariableMenu::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Enter)
	{
		CreateVariable();
		return FReply::Handled();
	}

	return FReply::Unhandled();
}
