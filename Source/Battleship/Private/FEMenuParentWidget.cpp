

#include "Battleship.h"
#include "FEMenuParentWidget.h"

bool UFEMenuParentWidget::CheckKey(const TSet<FString> CheckKeys, const FString Key)
{
	if (CheckKeys.Contains(Key))
	{
		return true;
	}

	return false;
}

void UFEMenuParentWidget::PopulateLayout(UWidget* Widget, bool bVerticalLayout = false)
{
	if (NavigationLayout.Num())
	{
		NavigationLayout.Empty();
	}

	const UWorld* World = Widget->GetWorld();

	if (!World)
	{
		return;
	}

	TMap<UButton*, FVector2D> ButtonOrder;
	for (TObjectIterator<UButton> Itr; Itr; ++Itr)
	{
		UButton* NewButton = *Itr;

		if (NewButton->GetWorld() != World || !NewButton->IsChildOf(Widget))
		{
			continue;
		}

		UCanvasPanelSlot* NewSlot = Cast<UCanvasPanelSlot>(NewButton->Slot);
		
		if (NewSlot)
		{
			FVector2D NewPos = NewSlot->GetPosition();
			ButtonOrder.Add(NewButton, NewPos);
		}
	}

	ButtonOrder.ValueSort([](FVector2D LPos, FVector2D RPos) {
		return LPos.Y < RPos.Y;
	});

	UE_LOG(LogTemp, Warning, TEXT("%i"), ButtonOrder.Num());

	FNestedButtons NestButtons;
	for (const TPair<UButton*,FVector2D> ButtonEntry : ButtonOrder) {
		UButton* Button = ButtonEntry.Key;
		FVector2D Value = ButtonEntry.Value;

		if (!NestButtons.Buttons.Num() || bVerticalLayout)
		{
			NestButtons.Buttons.Add(Button);
		}
		else
		{
			UButton* FirstButton = NestButtons.Buttons[0];

			UCanvasPanelSlot* FirstSlot = Cast<UCanvasPanelSlot>(FirstButton->Slot);
			UCanvasPanelSlot* NewSlot = Cast<UCanvasPanelSlot>(Button->Slot);

			float Distance = FMath::Abs((FirstSlot->GetPosition().Y - (FirstSlot->GetSize().Y/2)) - (NewSlot->GetPosition().Y - (NewSlot->GetSize().Y/2)));

			UE_LOG(LogTemp, Warning, TEXT("%f"), Distance);

			if (Distance > 50.0f)
			{
				NavigationLayout.Add(NestButtons);
				NestButtons = FNestedButtons();
			}

			NestButtons.Buttons.Add(Button);
		}
	}
	NavigationLayout.Add(NestButtons);
	NestButtons = FNestedButtons();

	if (NavigationLayout.Num())
	{
		NestButtons = NavigationLayout[0];
		
		if (NestButtons.Buttons.Num())
		{
			UButton* Button = NestButtons.Buttons[0];
			Button->SetKeyboardFocus();
			UE_LOG(LogTemp, Warning, TEXT("Setting Focus: %s"), *Button->GetDisplayLabel());

			FButtonStyle Style = Button->WidgetStyle;
			FSlateBrush Normal = Style.Normal;

			Style.Normal = Style.Hovered;
			Style.Hovered = Normal;

			Button->SetStyle(Style);
		}
	}
}

UButton* UFEMenuParentWidget::NavigateUpDown(int32 Mod)
{
	if (NavigationLayout.Num() <= 1)
	{
		return nullptr;
	}

	CurrentButtonIndex = 0;
	CurrentRowIndex += Mod;

	if (CurrentRowIndex == NavigationLayout.Num())
	{
		CurrentRowIndex = 0;
	}

	if (CurrentRowIndex < 0)
	{
		CurrentRowIndex = NavigationLayout.Num() - 1;
	}

	if (NavigationLayout.IsValidIndex(CurrentRowIndex))
	{
		FNestedButtons ButtonSet = NavigationLayout[CurrentRowIndex];

		if (ButtonSet.Buttons.IsValidIndex(CurrentButtonIndex))
		{
			UButton* Button = ButtonSet.Buttons[CurrentButtonIndex];

			if (Button)
			{
				UE_LOG(LogTemp, Warning, TEXT("Setting Focus: %s"), *Button->GetDisplayLabel());
			}

			return Button;
		}
	}

	return nullptr;
}

UButton* UFEMenuParentWidget::NavigateLeftRight(int32 Mod)
{
	if (!NavigationLayout.IsValidIndex(CurrentRowIndex))
	{
		return nullptr;
	}

	FNestedButtons ButtonSet = NavigationLayout[CurrentRowIndex];

	if (ButtonSet.Buttons.Num() <= 1)
	{
		return nullptr;
	}

	CurrentButtonIndex += Mod;

	if (CurrentButtonIndex == ButtonSet.Buttons.Num())
	{
		CurrentButtonIndex = 0;
	}

	if (CurrentButtonIndex < 0)
	{
		CurrentButtonIndex = ButtonSet.Buttons.Num() - 1;
	}

	if (!ButtonSet.Buttons.IsValidIndex(CurrentButtonIndex))
	{
		return nullptr;
	}

	UButton* Button = ButtonSet.Buttons[CurrentButtonIndex];

	if (Button)
	{
		UE_LOG(LogTemp, Warning, TEXT("Setting Focus: %s"), *Button->GetDisplayLabel());
	}

	return Button;
}

UButton* UFEMenuParentWidget::GetCurrentButton()
{
	if (NavigationLayout.IsValidIndex(CurrentRowIndex))
	{
		FNestedButtons ButtonSet = NavigationLayout[CurrentRowIndex];

		if (ButtonSet.Buttons.IsValidIndex(CurrentButtonIndex))
		{
			return ButtonSet.Buttons[CurrentButtonIndex];
		}
	}

	return nullptr;
}
