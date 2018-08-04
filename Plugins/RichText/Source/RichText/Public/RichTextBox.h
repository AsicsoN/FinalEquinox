#pragma once

#include "UObject/ObjectMacros.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateTypes.h"
#include "Widgets/SWidget.h"
#include "Components/TextWidgetTypes.h"

#include "RichTextBox.generated.h"

class SRichTextBlock;
class URichTextBlockDecorator;

/**
* The rich text block
*
* * Fancy Text
* * No Children
*/
UCLASS()
class RICHTEXT_API URichTextBox : public UTextLayoutWidget
{
    GENERATED_BODY()

public:
    URichTextBox(const FObjectInitializer& ObjectInitializer);

    virtual void SynchronizeProperties() override;

    virtual void ReleaseSlateResources(bool bReleaseChildren) override;

#if WITH_EDITOR
    virtual const FText GetPaletteCategory() override;
    virtual void OnCreationFromPalette() override;
#endif

protected:
    UPROPERTY(EditAnywhere, Category = Content, meta = (MultiLine = "true"))
    FText Text;

    UPROPERTY()
    FGetText TextDelegate;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
    FSlateFontInfo Font;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
    FLinearColor Color;

    UPROPERTY(EditAnywhere, Instanced, Category = Decorators)
    TArray<URichTextBlockDecorator*> Decorators;

protected:
    FTextBlockStyle DefaultStyle;
    TSharedPtr<SRichTextBlock> MyRichTextBlock;

    virtual TSharedRef<SWidget> RebuildWidget() override;

protected:
    PROPERTY_BINDING_IMPLEMENTATION(FText, Text);
};