// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "BlueprintAssistInputProcessor.h"
#include "CoreMinimal.h"
#include "EdGraph/EdGraphPin.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Views/SListView.h"

class SEditableTextBox;
class FBAGraphHandler;

class BLUEPRINTASSIST_API SCreateVariableMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SCreateVariableMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FBAGraphHandler> InGraphHandler);

	FReply OnCreateButtonClicked();
	
	void CreateVariable();

	TSharedPtr<SWidget> GetWidgetToFocus();
	FVector2D GetWidgetSize() const { return FVector2D(300, 350); }
	
public:
	FEdGraphPinType PinType;
	FText VariableName;
	FText SimpleDefaultValue;
	
	bool bInstanceEditable;
	bool bBlueprintReadOnly;
    bool bExposeOnSpawn;
    bool bPrivate;
    bool bExposeToCinematics;
	
	FText TooltipText;
    FText CategoryText;

private:
	FSlateFontInfo FontInfo;
	
	TSharedPtr<SEditableTextBox> VariableNameTextBox;

	TSharedPtr<SEditableTextBox> CategoryTextBox;
	
	TSharedPtr<SEditableTextBox> TooltipTextBox;
	
	TSharedPtr<SEditableTextBox> SimpleDefaultValueTextBox;

	TSharedPtr<SCheckBox> InstanceEditableCheckBox;
	TSharedPtr<SCheckBox> BlueprintReadOnlyCheckBox;
	TSharedPtr<SCheckBox> ExposeOnSpawnCheckBox;
	TSharedPtr<SCheckBox> PrivateCheckBox;
	TSharedPtr<SCheckBox> ExposeToCinematicsCheckBox;
	
	TSharedPtr<FBAGraphHandler> GraphHandler;
	
	FString DefaultValueString;

	void UpdateMenuWidget();
	
	FEdGraphPinType OnGetPinType() const;

	void OnPinTypeChanged(const FEdGraphPinType& NewPinType);

	TSharedRef<SSplitter> MakeRow(FString PropertyName, TSharedPtr<SWidget> Widget);

	TSharedRef<SCheckBox> MakeBoundCheckBox(bool& VariableToBindTo);
	
	TSharedRef<SEditableTextBox> MakeBoundEditableText(FText& TextToBindTo);

	void OnEditableTextCommitted(const FText&, ETextCommit::Type);
	
	void OnExposeOnSpawnChanged(ECheckBoxState CheckBoxState);

	bool IsValidInput() const;

	FText GetErrorText() const;

public:
	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
};
