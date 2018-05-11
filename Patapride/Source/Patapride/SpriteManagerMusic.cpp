// Fill out your copyright notice in the Description page of Project Settings.

//#include "Engine\Intermediate\Build\Win64\Inc\Plugins\Paper2D\PaperSpriteComponent.h"
#include "SpriteManagerMusic.h"
//#include "Rythms.h" <- I HATE YOU

// Sets default values for this component's properties
USpriteManagerMusic::USpriteManagerMusic()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpriteManagerMusic::BeginPlay()
{

	
}


// Called every frame
void USpriteManagerMusic::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

