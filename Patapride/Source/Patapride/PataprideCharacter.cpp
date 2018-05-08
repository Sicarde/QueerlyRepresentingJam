// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PataprideCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Rythms.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine.h"

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
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}
void APataprideCharacter::Tick(float deltaTime) {
	float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	FTimespan currentTime = FTimespan::FromSeconds(realtimeSeconds);
	double currentTimeMs = currentTime.GetTotalMilliseconds();
	if (currentNote >= testLevel.Num())
		return;
	Note n = testLevel[currentNote];
	double timeNote = n.msec + n.sec * 1000.0 + n.min * 60000.0;
	if (timeNote + nbMSecGood < currentTimeMs)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Too late :/");
		currentNote++;
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void APataprideCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &APataprideCharacter::MoveRight);
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

	PlayerInputComponent->BindTouch(IE_Pressed, this, &APataprideCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &APataprideCharacter::TouchStopped);
}

void APataprideCharacter::checkNoteTiming(FString const &noteName)
{
	UE_LOG(LogTemp, Warning, TEXT("current note %d"), currentNote);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("current note %d"), currentNote);
	float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	FTimespan currentTime = FTimespan::FromSeconds(realtimeSeconds);
	if (currentNote >= testLevel.Num())
		return;
	Note n = testLevel[currentNote];
	double timeNote = n.msec + n.sec * 1000.0 + n.min * 60000.0;
	double currentTimeMs = currentTime.GetTotalMilliseconds();
	if (timeNote - nbMSecPerf < currentTimeMs && timeNote + nbMSecPerf > currentTimeMs && n.button == noteName)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PERFECT");
		currentNote++;
	}
	else if (timeNote - nbMSecGood < currentTimeMs && timeNote + nbMSecGood > currentTimeMs && n.button == noteName)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "GOOD");
		currentNote++;
	}
	else if (timeNote - nbMSecGood < currentTimeMs && timeNote + nbMSecGood > currentTimeMs && n.button != noteName)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Wrong button :/");
	else if (timeNote - nbMSecGood > currentTimeMs && n.button == noteName)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, "Too early :/");
}

void APataprideCharacter::UpButton()
{
	checkNoteTiming("Up");
}

void APataprideCharacter::MoveRight(float Value)
{
	// add movement in that direction
	if (Value > .0f)
		AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void APataprideCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void APataprideCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

