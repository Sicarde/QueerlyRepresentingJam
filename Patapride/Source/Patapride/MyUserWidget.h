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

	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
		FText GetProtestersText() const;

	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
		void SetProtestersText(const FText& gmt_NewDisplayText);

	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
		FText GetStreakText() const;

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
	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
		void SetStreakText(const FText& gmt_NewDisplayText);
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
};
