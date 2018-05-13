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
