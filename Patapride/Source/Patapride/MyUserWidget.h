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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color1F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color2F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color3F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color4F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color5F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color6F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color7F;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
		FLinearColor Color8F;

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


	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor1() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor2() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor3() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor4() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor5() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor6() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor7() const;
	UFUNCTION(BlueprintPure, Category = "Widgets|Color")
		FLinearColor GetColor8() const;
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor1(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor2(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor3(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor4(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor5(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor6(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor7(const FLinearColor& gmt_NewColor);
	UFUNCTION(BlueprintCallable, Category = "Widgets|Color")
		void SetColor8(const FLinearColor& gmt_NewColor);
};
