// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h" 
#include "PataprideCharacter.generated.h"

static FLinearColor basicColor = FLinearColor(FColor::Red);
UCLASS(config=Game)
class APataprideCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UPaperSpriteComponent* SpriteTriangle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* SpriteSquare;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* SpriteCircle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* SpriteCross;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* TriangleEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* CircleEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* CrossEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UPaperSpriteComponent* SquareEnd;

	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;
	int currentNote = 0;
	TArray<UPaperSpriteComponent*> notes;
	double realtimeSeconds = 0;
protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	virtual void Tick(float deltaTime) override;
	virtual void BeginPlay() override;
	void GenerateMusicNotes();
	void UpdateNotesPositions(float deltaTime);
	void checkNoteTiming(FString const &noteName);
	void SetNextSpriteColor(FLinearColor const &col);
public:
	APataprideCharacter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> HUD;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int currentStrike = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int protestersNumber = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int currentFlag = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor col1 = basicColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor col2 = basicColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor col3 = basicColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor col4 = basicColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FLinearColor col5 = basicColor;

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
