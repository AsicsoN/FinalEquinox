#include "Battleship.h"
#include "AdvancedButton.h"

#pragma region >>> SAdvancedButton <<<
FReply SAdvancedButton::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) {
	if (!AdvancedHitTexture) return SButton::OnMouseMove(MyGeometry, MouseEvent);
	bool WhatToReturn = true;
	FVector2D LocalPosition = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	LocalPosition.X = floor(LocalPosition.X);
	LocalPosition.Y = floor(LocalPosition.Y);
	LocalPosition /= MyGeometry.GetLocalSize();
	int ImageWidth = AdvancedHitTexture->PlatformData->SizeX;
	LocalPosition.X *= ImageWidth;
	LocalPosition.Y *= AdvancedHitTexture->PlatformData->SizeY;
	int BufferPosition = (LocalPosition.Y * ImageWidth) + LocalPosition.X;
	FColor* ImageData = static_cast<FColor*>((AdvancedHitTexture->PlatformData->Mips[0]).BulkData.Lock(LOCK_READ_ONLY));
	if (!ImageData) { WhatToReturn = false; }
	else { if (ImageData[BufferPosition].A <= AdvancedHitAlpha) WhatToReturn = false; }
	AdvancedHitTexture->PlatformData->Mips[0].BulkData.Unlock();
	if (WhatToReturn != bIsHovered) {
		bIsHovered = WhatToReturn;
		if (bIsHovered) SButton::OnMouseEnter(MyGeometry, MouseEvent);
		else SButton::OnMouseLeave(MouseEvent);
	}
	return SButton::OnMouseMove(MyGeometry, MouseEvent);
}
FCursorReply SAdvancedButton::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const {
	if (!bIsHovered) return FCursorReply::Unhandled();
	TOptional<EMouseCursor::Type> TheCursor = Cursor.Get();
	return (TheCursor.IsSet()) ? FCursorReply::Cursor(TheCursor.GetValue()) : FCursorReply::Unhandled();
}
#pragma endregion

#pragma region >>> UAdvancedButton <<<
void UAdvancedButton::SynchronizeProperties() {
	Super::SynchronizeProperties();
	(static_cast<SAdvancedButton*>(MyButton.Get()))->SetAdvancedHitTexture(AdvancedHitTexture);
	(static_cast<SAdvancedButton*>(MyButton.Get()))->SetAdvancedHitAlpha(AdvancedHitAlpha);
}
TSharedRef<SWidget> UAdvancedButton::RebuildWidget() {
	TSharedPtr<SAdvancedButton> AdvancedButton = SNew(SAdvancedButton)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
		.OnHovered_UObject(this, &ThisClass::SlateHandleHovered)
		.OnUnhovered_UObject(this, &ThisClass::SlateHandleUnhovered)
		.ButtonStyle(&WidgetStyle)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.IsFocusable(IsFocusable)
		;

	AdvancedButton->SetAdvancedHitTexture(AdvancedHitTexture);
	AdvancedButton->SetAdvancedHitAlpha(AdvancedHitAlpha);

	MyButton = AdvancedButton;
	
	if (GetChildrenCount() > 0) Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());

	return MyButton.ToSharedRef();
}
