// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h" 
#include "Rythms.h"
#include "PataprideCharacter.generated.h"

static FLinearColor basicColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
UCLASS(config=Game)
class APataprideCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;
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

	int currentNote = 0;
	TArray<UPaperSpriteComponent*> notes;
	double realtimeSeconds = 0;

	TArray<TArray<FLinearColor>> colorsFlags = { { FColor::Purple, FColor::Blue, FColor::Green, FColor::Yellow, FColor::Red }, //HOMO
	{ FColor::Purple, FColor::White, PINK }, //LESBIAN
	{ FColor::Blue, FColor::Purple, PINK }, //BI
	{ FColor::Blue, FColor::White, PINK }, //TRANS
	{ FColor::Purple, FColor::White, FColor::Silver } }; //ASEXUAL
	TArray<int> possibleFlags;
	int currentFlag = 6;
	typedef struct {
		bool isAcab;
		int strength;
		int life;
		UStaticMeshComponent *mesh;
	} Enemy;
	TArray<Enemy> enemies;
protected:
	//void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);
	//void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);
	//void MoveRight(float Val);

	void Right();
	void Left();
	void UseFlag();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	virtual void Tick(float deltaTime) override;
	virtual void BeginPlay() override;

	void GenerateMusicNotes();
	void GenerateEnemies(int nbEnemies);
	void UpdateNotesPositions(float deltaTime);
	void checkNoteTiming(FString const &noteName);
	void SetNextSpriteColor(FLinearColor const &col);
	void CheckPossibleFlags();
public:
	APataprideCharacter();
	typedef enum { HOMO, LESBIAN, BI, TRANS, ASEXUAL } E_Flag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int currentStrike = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int protestersNumber = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col1 = FColor::Purple;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col2 = FColor::Blue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col3 = FColor::Green;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col4 = FColor::Yellow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col5 = FColor::Red;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col6 = PINK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col7 = FColor::White;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FLinearColor col8 = FColor::Silver;
	UFUNCTION(BlueprintCallable, Category = "Widgets")
		int GetCurrentFlag();
	TArray<FLinearColor*> cols = { &col1, &col2, &col3, &col4, &col5, &col6, &col7, &col8 };
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
