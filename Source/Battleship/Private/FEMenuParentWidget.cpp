

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

UButton* UFEMenuParentWidget::NavigateUpDown(int32 Mod)
{
	if (NavigationLayout.Num() <= 1)
	{
		return nullptr;
	}

	CurrentRowIndex += Mod;

	if (CurrentRowIndex == NavigationLayout.Num())
	{
		CurrentRowIndex = 0;
	}

	if (CurrentRowIndex < 0)
	{
		CurrentRowIndex = NavigationLayout.Num() - 1;
	}

	FNestedButtons ButtonSet = NavigationLayout[CurrentRowIndex];

	return ButtonSet.Buttons[0];
}

UButton* UFEMenuParentWidget::NavigateLeftRight(int32 Mod)
{
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

	return ButtonSet.Buttons[CurrentButtonIndex];
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
