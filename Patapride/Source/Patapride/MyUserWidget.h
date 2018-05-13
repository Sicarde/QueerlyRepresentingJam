// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class PATAPRIDE_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
		FText StreakText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
		FText ProtestersText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprite")
		UPaperSpriteComponent *CurrentFlag;

	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
		FText GetProtestersText() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
		FText GetStreakText() const;

	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
		void SetProtestersText(const FText& gmt_NewDisplayText);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
		void SetStreakText(const FText& gmt_NewDisplayText);

	UFUNCTION(BlueprintPure, Category = "Widgets|Sprite")
		UPaperSpriteComponent *GetCurrentFlag() const;
	UFUNCTION(BlueprintCallable, Category = "Widgets|Sprite")
		void SetCurrentFlag(UPaperSpriteComponent *gmt_flag);
};
