#include "MyUserWidget.h"
#include "Engine.h"
#include "PataprideCharacter.h"

FText UMyUserWidget::GetStreakText() const {
	return StreakText;
}

void UMyUserWidget::SetStreakText(const FText& NewDisplayText) {
	StreakText = FText::FromString("Streak : " + NewDisplayText.ToString());
}

FText UMyUserWidget::GetProtestersText() const {
	return ProtestersText;
}

void UMyUserWidget::SetProtestersText(const FText& NewDisplayText) {
	ProtestersText = FText::FromString("Protesters : " + NewDisplayText.ToString());
}

UPaperSpriteComponent *UMyUserWidget::GetCurrentFlag() const {
	return CurrentFlag;
}

void UMyUserWidget::SetCurrentFlag(UPaperSpriteComponent *NewFlag) {
	CurrentFlag = NewFlag;
}

FLinearColor UMyUserWidget::GetColor1() const {
	return Color1F;
}
FLinearColor UMyUserWidget::GetColor2() const {
	return Color2F;
}
FLinearColor UMyUserWidget::GetColor3() const {
	return Color3F;
}
FLinearColor UMyUserWidget::GetColor4() const {
	return Color4F;
}
FLinearColor UMyUserWidget::GetColor5() const {
	return Color5F;
}
FLinearColor UMyUserWidget::GetColor6() const {
	return Color6F;
}
FLinearColor UMyUserWidget::GetColor7() const {
	return Color7F;
}
FLinearColor UMyUserWidget::GetColor8() const {
	return Color8F;
}

void UMyUserWidget::SetColor1(const FLinearColor& NewColor) {
	Color1F = NewColor;
}
void UMyUserWidget::SetColor2(const FLinearColor& NewColor) {
	Color2F = NewColor;
}
void UMyUserWidget::SetColor3(const FLinearColor& NewColor) {
	Color3F = NewColor;
}
void UMyUserWidget::SetColor4(const FLinearColor& NewColor) {
	Color4F = NewColor;
}
void UMyUserWidget::SetColor5(const FLinearColor& NewColor) {
	Color5F = NewColor;
}
void UMyUserWidget::SetColor6(const FLinearColor& NewColor) {
	Color6F = NewColor;
}
void UMyUserWidget::SetColor7(const FLinearColor& NewColor) {
	Color7F = NewColor;
}
void UMyUserWidget::SetColor8(const FLinearColor& NewColor) {
	Color8F = NewColor;
}
