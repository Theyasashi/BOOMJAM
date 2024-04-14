// Copyright 2020 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class SBlueprintContextTargetMenu;
class SWidget;

struct FBAHotkeyStruct
{
	FName CommandName;
	FText CommandChord;
	FText CommandDesc;
	
	FBAHotkeyStruct(TSharedPtr<FUICommandInfo> Command)
	{
		CommandName = Command->GetCommandName();
		CommandChord = Command->GetFirstValidChord()->GetInputText();

		if (CommandChord.IsEmptyOrWhitespace())
		{
			CommandChord = FText::FromString("Unbound");
		}
		
		CommandDesc = Command->GetDescription();
	};
};


class BLUEPRINTASSIST_API SBAHotkeyMenu final : public SBorder
{
	SLATE_BEGIN_ARGS(SBAHotkeyMenu)
	{
	}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

public:
	FVector2D WidgetSize;
protected:
	TArray<TSharedPtr<FBAHotkeyStruct>> BlueprintAssistHotkeys;

	TSharedRef<ITableRow> CreateItemWidget(
        TSharedPtr<FBAHotkeyStruct> Item,
        const TSharedRef<STableViewBase>& OwnerTable) const;
};
