// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PataprideCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "PaperSprite.h"
#include "Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Blueprint/UserWidget.h"

UPaperSprite* GetTriangleAsset() {
	static ConstructorHelpers::FObjectFinder<UPaperSprite> Asset(TEXT("PaperSprite'/Game/TriangleSprite.TriangleSprite'"));
	return Asset.Object;
}

UPaperSprite* GetSquareAsset() {
	static ConstructorHelpers::FObjectFinder<UPaperSprite> Asset(TEXT("PaperSprite'/Game/SquareSprite.SquareSprite'"));
	return Asset.Object;
}

UPaperSprite* GetCircleAsset() {
	static ConstructorHelpers::FObjectFinder<UPaperSprite> Asset(TEXT("PaperSprite'/Game/CircleSprite.CircleSprite'"));
	return Asset.Object;
}

UPaperSprite* GetCrossAsset() {
	static ConstructorHelpers::FObjectFinder<UPaperSprite> Asset(TEXT("PaperSprite'/Game/CrossSprite.CrossSprite'"));
	return Asset.Object;
}

UPaperSprite* GetColorAsset() {
	static ConstructorHelpers::FObjectFinder<UPaperSprite> Asset(TEXT("PaperSprite'/Game/ButtonColor_Sprite_0.ButtonColor_Sprite_0'"));
	return Asset.Object;
}

UMaterialInstanceConstant *GetProudMaterial()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> ProudMat(TEXT("MaterialInstanceConstant'/Game/Mannequin/Character/Mesh/Protester1Mat.Protester1Mat'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> Proud1Mat(TEXT("MaterialInstanceConstant'/Game/Mannequin/Character/Mesh/Protester2Mat.Protester2Mat'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> Proud2Mat(TEXT("MaterialInstanceConstant'/Game/Mannequin/Character/Mesh/Protester3Mat.Protester3Mat'"));
	int r = FMath::RandRange(0, 2);
	if (r == 0)
		return ProudMat.Object;
	else if (r == 1)
		return Proud1Mat.Object;
	return Proud2Mat.Object;
}

UStaticMesh *GetProud()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Proud(TEXT("StaticMesh'/Game/Mannequin/Character/Mesh/proud.proud'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Proud1(TEXT("StaticMesh'/Game/Mannequin/Character/Mesh/Proud1.Proud1'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Proud2(TEXT("StaticMesh'/Game/Mannequin/Character/Mesh/Proud2.Proud2'"));
	int r = FMath::RandRange(0, 2);
	if (r == 0)
		return Proud.Object;
	else if (r == 1)
		return Proud1.Object;
	return Proud2.Object;
}

UStaticMesh *GetLMPT()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("StaticMesh'/Game/Mannequin/Character/Mesh/LMPT.LMPT'"));
	return Asset.Object;
}

UStaticMesh *GetACAB()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("StaticMesh'/Game/Mannequin/Character/Mesh/ACAB.ACAB'"));
	return Asset.Object;
}

UPaperSprite* GetAssetFromNote(FString const &button) {
	if (button == "Square") {
		return GetSquareAsset();
	} else if (button == "Triangle") {
		return GetTriangleAsset();
	} else if (button == "Circle") {
		return GetCircleAsset();
	} else {
		return GetCrossAsset();
	}
}

USoundWave *GetSoundFromNote(FString const &button) {
	static ConstructorHelpers::FObjectFinder<USoundWave> Circle(TEXT("SoundWave'/Game/sounds/Circle.Circle'"));
	static ConstructorHelpers::FObjectFinder<USoundWave> Cross(TEXT("SoundWave'/Game/sounds/Cross.Cross'"));
	static ConstructorHelpers::FObjectFinder<USoundWave> Square(TEXT("SoundWave'/Game/sounds/Square.Square'"));
	static ConstructorHelpers::FObjectFinder<USoundWave> Triangle(TEXT("SoundWave'/Game/sounds/Triangle.Triangle'"));
	if (button == "Square")
		return Square.Object;
	else if (button == "Triangle")
		return Triangle.Object;
	else if (button == "Circle")
		return Circle.Object;
	return Cross.Object;
}

APataprideCharacter::APataprideCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SpriteTriangle = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteTriangle"));
	SpriteTriangle->SetupAttachment(CameraBoom);
	SpriteTriangle->SetSprite(GetTriangleAsset());
	SpriteSquare = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteSquare"));
	SpriteSquare->SetupAttachment(CameraBoom);
	SpriteSquare->SetSprite(GetSquareAsset());
	SpriteCircle = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteCircle"));
	SpriteCircle->SetupAttachment(CameraBoom);
	SpriteCircle->SetSprite(GetCircleAsset());
	SpriteCross = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteCross"));
	SpriteCross->SetupAttachment(CameraBoom);
	SpriteCross->SetSprite(GetCrossAsset());
	TriangleEnd = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TriangleEnd"));
	TriangleEnd->SetupAttachment(CameraBoom);
	SquareEnd = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SquareEnd"));
	SquareEnd->SetupAttachment(CameraBoom);
	CrossEnd = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CrossEnd"));
	CrossEnd->SetupAttachment(CameraBoom);
	CircleEnd = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CircleEnd"));
	CircleEnd->SetupAttachment(CameraBoom);
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	GetColorAsset();
	GetProud();
	GetProudMaterial();
	GetACAB();
	GetLMPT();
	GetSoundFromNote("Square");
	PrimaryActorTick.bCanEverTick = true;
	audioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	audioComponent->bAutoActivate = false;
	audioComponent->SetupAttachment(RootComponent);
}

void APataprideCharacter::GenerateMusicNotes()
{
	TArray<FVector> directions = { (SpriteSquare->GetRelativeTransform().GetLocation() - SquareEnd->GetRelativeTransform().GetLocation()).GetSafeNormal(),
		(SpriteTriangle->GetRelativeTransform().GetLocation() - TriangleEnd->GetRelativeTransform().GetLocation()).GetSafeNormal(),
		(SpriteCircle->GetRelativeTransform().GetLocation() - CircleEnd->GetRelativeTransform().GetLocation()).GetSafeNormal(),
		(SpriteCross->GetRelativeTransform().GetLocation() - CrossEnd->GetRelativeTransform().GetLocation()).GetSafeNormal() };
	TArray<UPaperSpriteComponent*> sprites = { SquareEnd, TriangleEnd, CircleEnd, CrossEnd };
	TArray<UPaperSpriteComponent*> spritesDetect = { SpriteSquare, SpriteTriangle, SpriteCircle, SpriteCross };

	notes.Reserve(testLevel.Num());
	int i = 0;
	for (Note n : testLevel)
	{
		double timeNote = n.msec + n.sec * 1000.0 + n.min * 60000.0;
		i++;
		int indexButton = 0;
		buttonsNames.Find(n.button, indexButton);
		if (indexButton < 0 || indexButton > buttonsNames.Num() - 1)
			indexButton = 0;
		UPaperSpriteComponent *noteSprite = NewObject<UPaperSpriteComponent>(this);
		if (!noteSprite || !noteSprite->IsValidLowLevel())
			return;
		noteSprite->SetupAttachment(CameraBoom);
		noteSprite->SetSprite(GetAssetFromNote(n.button));
		noteSprite->SetRelativeTransform(spritesDetect[indexButton]->GetRelativeTransform());
		noteSprite->SetRelativeLocation(spritesDetect[indexButton]->GetRelativeTransform().GetLocation() - directions[indexButton] * speedNotes * timeNote / 1000);
		noteSprite->SetVisibility(true);
		notes.Add(noteSprite);
		if (FMath::RandRange(1, percentageColored) == 1)
		{
			UPaperSpriteComponent *colorSprite = NewObject<UPaperSpriteComponent>(this);
			if (!colorSprite || !colorSprite->IsValidLowLevel())
				return;
			colorSprite->SetupAttachment(noteSprite);
			colorSprite->SetSprite(GetColorAsset());
			colorSprite->SetRelativeLocation(FVector(1.0f, 1.0f, 0.0f));
			colorSprite->SetSpriteColor(buttonFlagColor[FMath::RandRange(0, buttonFlagColor.Num() - 1)]);
			colorSprite->SetVisibility(true);
			colorSprite->RegisterComponent();
		}
		noteSprite->RegisterComponent();
	}
}

void APataprideCharacter::AddPride()
{
	USceneComponent *root = CameraBoom->GetAttachmentRoot();
	USceneComponent *carac = root->GetChildComponent(root->GetNumChildrenComponents() - 1);
	Enemy e;
	e.isAcab = false;
	e.mesh = NewObject<UStaticMeshComponent>(this);
	if (!e.mesh || !e.mesh->IsValidLowLevel())
		return;
	e.mesh->SetupAttachment(carac);
	e.mesh->SetVisibility(true);
	e.mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	e.mesh->RegisterComponent();
	e.life = 20;
	e.strength = 3;
	e.mesh->SetStaticMesh(GetProud());
	//TODO material depending on flags
	e.mesh->SetRelativeLocation(FVector(500.0f * FMath::RandRange(1, 6), -500.0f * FMath::RandRange(1, 4), 0.0f)); //TODO proper please
	e.mesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
	allies.Add(e);
}

void APataprideCharacter::GenerateEnemies(int nbEnemies)
{
	USceneComponent *root = CameraBoom->GetAttachmentRoot();
	USceneComponent *carac = root->GetChildComponent(root->GetNumChildrenComponents() - 1);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, carac->GetFullName());
	enemies.Reserve(nbEnemies);
	for (int i = 0; i < nbEnemies; ++i)
	{
		Enemy e;
		e.isAcab = FMath::RandRange(0, 4) == 0 ? true : false;
		e.mesh = NewObject<UStaticMeshComponent>(this);
		if (!e.mesh || !e.mesh->IsValidLowLevel())
			return;
		e.mesh->SetupAttachment(carac);
		e.mesh->SetVisibility(true);
		e.mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		e.mesh->RegisterComponent();
		if (e.isAcab)
		{
			e.life = 20;
			e.strength = 3;
			e.mesh->SetStaticMesh(GetACAB());
		}
		else
		{
			e.life = 15;
			e.strength = 1;
			e.mesh->SetStaticMesh(GetLMPT());
		}
		e.mesh->SetRelativeLocation(FVector(500.0f * FMath::RandRange(1, 6), 500.0f * FMath::RandRange(1, 4) + 3000.0f, 0.0f)); //TODO proper please
		e.mesh->AddRelativeRotation(FRotator(0, 180, 0));
		e.mesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.2f));
		enemies.Add(e);
	}
}

void APataprideCharacter::DetectEnemies()
{
	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStaticMeshActor *Mesh = *ActorItr;
		if (!Mesh->GetName().Contains("ACAB") && !Mesh->GetName().Contains("LMPT"))
			continue;
		Enemy e;
		e.mesh = Mesh->GetStaticMeshComponent();
		e.isAcab = Mesh->GetName().Contains("ACAB") ? true : false;
		if (e.isAcab)
		{
			e.life = 20;
			e.strength = 3;
		}
		else
		{
			e.life = 15;
			e.strength = 1;
		}
		enemies.Add(e);
	}
	TArray<USceneComponent*> childs;
	GetRootComponent()->GetChildrenComponents(false, childs);
	for (USceneComponent *c : childs)
	{
		if (c->GetFullName().Contains("proud"))
		{
			Enemy e;
			e.mesh = (UStaticMeshComponent*)c;
			e.isAcab = false;
			e.life = 15;
			e.strength = 1;
			allies.Add(e);
		}
	}
}

void APataprideCharacter::BeginPlay() {
	Super::BeginPlay();
	GenerateMusicNotes();
	CheckPossibleFlags();
	DetectEnemies();
}

void APataprideCharacter::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	realtimeSeconds += deltaTime;
	timerLesbian -= deltaTime;
	timerTrans -= deltaTime;
	timerAce -= deltaTime;
	if (timerLesbian < 0.0)
		timerLesbian = 0.0;
	if (timerTrans < 0.0)
		timerTrans = 0.0;
	if (timerAce < 0.0)
		timerAce = 0.0;
	FTimespan currentTime = FTimespan::FromSeconds(realtimeSeconds);
	double currentTimeMs = currentTime.GetTotalMilliseconds();
	if (currentNote >= testLevel.Num())
		return;
	Note n = testLevel[currentNote];
	double timeNote = n.msec + n.sec * 1000.0 + n.min * 60000.0;
	if (timeNote + nbMSecGood < currentTimeMs)
	{
		notes[currentNote]->SetVisibility(false); //Fail
		if (!(timerLesbian > 0.00001) && !(timerTrans > 0.00001))
			ReceiveDamage();
		if (timerTrans > 0.0)
			GiveDamage();
		else
			currentStrike = 0;
		USceneComponent *color = notes[currentNote]->GetChildComponent(0);
		if (color && color->IsValidLowLevel())
			color->SetVisibility(false);
		currentNote++;
		if (audioComponent->IsValidLowLevelFast()) {
			audioComponent->SetSound(GetSoundFromNote(n.button));
			audioComponent->Play();
		}
	}
	UpdateNotesPositions(deltaTime);
	protestersNumber = allies.Num();
	if (protestersNumber == 0)
	{
		//TODO LOOSE
	}
}

void APataprideCharacter::UpdateNotesPositions(float deltaTime)
{
	FVector direction = (SpriteSquare->GetRelativeTransform().GetLocation() - SquareEnd->GetRelativeTransform().GetLocation()).GetSafeNormal();
	for (UPaperSpriteComponent *sprite : notes)
	{
		if (sprite && sprite->IsValidLowLevel())
			sprite->SetRelativeLocation(sprite->GetRelativeTransform().GetLocation() + direction * speedNotes * deltaTime);
	}
}

void APataprideCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAxis("MoveRight", this, &APataprideCharacter::MoveRight);
	for (FString name : buttonsNames)
	{
		FInputActionBinding PressedButton(*name, IE_Pressed);
		PressedButton.ActionDelegate.GetDelegateForManualSet().BindLambda(
			[this, name]() { checkNoteTiming(name); }
		);
		PlayerInputComponent->AddActionBinding(PressedButton);
		/*FInputActionBinding PressedButton("Up", IE_Released);
		PressedButton.ActionDelegate.GetDelegateForManualSet().BindLambda(
		[this]() { checkNoteTiming("Up"); }
		);
		PlayerInputComponent->AddActionBinding(PressedButton);*/
	}
	PlayerInputComponent->BindAction("UseFlag", IE_Pressed, this, &APataprideCharacter::UseFlag);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &APataprideCharacter::Right);
	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &APataprideCharacter::Left);
	//PlayerInputComponent->BindTouch(IE_Pressed, this, &APataprideCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &APataprideCharacter::TouchStopped);
}

void APataprideCharacter::SetNextSpriteColor(FLinearColor const &col)
{
	if (col1 == basicColor)
		col1 = col;
	else if (col1 == col)
		return;
	else if (col2 == basicColor)
		col2 = col;
	else if (col2 == col)
		return;
	else if (col3 == basicColor)
		col3 = col;
	else if (col3 == col)
		return;
	else if (col4 == basicColor)
		col4 = col;
	else if (col4 == col)
		return;
	else if (col5 == basicColor)
		col5 = col;
	else if (col5 == col)
		return;
}

void APataprideCharacter::CheckPossibleFlags()
{
	possibleFlags.Empty();
	int i = 0;
	for (TArray<FLinearColor> flagCol : colorsFlags)
	{
		bool missColor = false;
		for (FLinearColor col : flagCol)
		{
			bool findCol = false;
			for (FLinearColor *c : cols)
			{
				if (*c == col)
				{
					findCol = true;
					break;
				}
			}
			if (!findCol)
			{
				missColor = true;
				break;
			}
		}
		if (!missColor)
			possibleFlags.Add(i);
		++i;
	}
	if (currentFlag != 6 && currentFlag > possibleFlags.Num())
		currentFlag = possibleFlags.Num() - 1;
	if (currentFlag < 0)
		currentFlag = 6;
	if (possibleFlags.Num() > 0 && currentFlag == 6)
		currentFlag = 0;
}

void APataprideCharacter::GiveDamage(float multiplier)
{
	for (Enemy a : allies)
	{
		int r = FMath::RandRange(0, enemies.Num() - 1);
		if (enemies.Num() == 0)
			return;
		enemies[r].life -= a.strength * multiplier + bonusDegat / 2.0 * a.strength * multiplier;
		if (enemies[r].life <= 0.0f)
		{
			enemies[r].mesh->DestroyComponent();
			enemies.RemoveAt(r);
			AddPride();
		}
	}
}

void APataprideCharacter::ReceiveDamage()
{
	for (Enemy e : enemies)
	{
		int r = FMath::RandRange(0, allies.Num() - 1);
		if (allies.Num() == 0)
			return;
		allies[r].life -= e.strength;
		if (allies[r].life <= 0.0f)
		{
			allies[r].mesh->DestroyComponent();
			allies.RemoveAt(r);
			AddPride();
		}
	}
}

void APataprideCharacter::checkNoteTiming(FString const &noteName)
{
	//UE_LOG(LogTemp, Warning, TEXT("current note %d"), currentNote);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("current note %d"), currentNote);
	FTimespan currentTime = FTimespan::FromSeconds(realtimeSeconds);
	if (currentNote >= testLevel.Num())
		return;
	Note n = testLevel[currentNote];
	double timeNote = n.msec + n.sec * 1000.0 + n.min * 60000.0;
	double currentTimeMs = currentTime.GetTotalMilliseconds();
	if (timeNote - nbMSecPerf < currentTimeMs && timeNote + nbMSecPerf > currentTimeMs && n.button == noteName)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PERFECT");
		notes[currentNote]->SetVisibility(false);
		USceneComponent *color = notes[currentNote]->GetChildComponent(0);
		if (color && color->IsValidLowLevel())
		{
			SetNextSpriteColor(((UPaperSpriteComponent*)color)->GetSpriteColor());
			color->SetVisibility(false);
			CheckPossibleFlags();
		}
		GiveDamage(1.5f);
		currentNote++;
		currentStrike++;
		if (audioComponent->IsValidLowLevelFast()) {
			audioComponent->SetSound(GetSoundFromNote(n.button));
			audioComponent->Play();
		}
	}
	else if (timeNote - nbMSecGood < currentTimeMs && timeNote + nbMSecGood > currentTimeMs && n.button == noteName)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "GOOD");
		notes[currentNote]->SetVisibility(false);
		USceneComponent *color = notes[currentNote]->GetChildComponent(0);
		if (color && color->IsValidLowLevel())
		{
			SetNextSpriteColor(((UPaperSpriteComponent*)color)->GetSpriteColor());
			color->SetVisibility(false);
			CheckPossibleFlags();
		}
		GiveDamage();
		currentNote++;
		currentStrike++;
		if (audioComponent->IsValidLowLevelFast()) {
			audioComponent->SetSound(GetSoundFromNote(n.button));
			audioComponent->Play();
		}
	}
	/*else if (timeNote - nbMSecGood < currentTimeMs && timeNote + nbMSecGood > currentTimeMs && n.button != noteName)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Wrong button :/");
	else if (timeNote - nbMSecGood > currentTimeMs && n.button == noteName)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Too early :/");//*/
}


void APataprideCharacter::Left()
{
	if (currentFlag > 0 && currentFlag < possibleFlags.Num())
		currentFlag--;
	else if (currentFlag == 0)
		currentFlag = possibleFlags.Num() - 1;
}

void APataprideCharacter::Right()
{
	if (currentFlag < possibleFlags.Num() - 1)
		currentFlag++;
	else if (currentFlag == possibleFlags.Num() - 1)
		currentFlag = 0;
}

int APataprideCharacter::GetCurrentFlag()
{
	if (currentFlag < 0 || currentFlag >= possibleFlags.Num())
		return 6;
	return possibleFlags[currentFlag];
}

void APataprideCharacter::UseFlag()
{
	if (possibleFlags.Num() > 0 && currentFlag < possibleFlags.Num())
	{
		for (FLinearColor c : colorsFlags[currentFlag])
		{
			for (FLinearColor *col : cols)
			{
				if (*col == c)
				{
					*col = basicColor;
					break;
				}
			}
		}
		//TODO detect ennemies properly
		if (possibleFlags[currentFlag] == HOMO) //D�truit le cort�ge adverse
		{
			for (int i = 0; i < enemies.Num(); ++i)
			{
				if (!enemies[i].isAcab)
				{
					enemies[i].mesh->DestroyComponent();
					enemies.RemoveAt(i);
					--i;
				}
			}
		}
		else if (possibleFlags[currentFlag] == LESBIAN) //Cort�ge invuln�rable pendant 10s
			timerLesbian = 10.0;
		else if (possibleFlags[currentFlag] == BI) //Double degats
			++bonusDegat;
		else if (possibleFlags[currentFlag] == TRANS) //Toutes les notes jou�es infligent des d�g�ts pendant 15s (elles ne sont pas forc�ment justes = ne comptent pas pour la streak en cours)
			timerTrans = 15.0;
		else //Le cort�ge est invisible pendant 10s(il avance au travers du cort�ge ennemi); permet de passer un blocus
			timerAce = 10.0;
		CheckPossibleFlags();
	}
}

/*void APataprideCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void APataprideCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void APataprideCharacter::MoveRight(float Value)
{
// add movement in that direction
if (Value > .0f)
AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}*/

