#pragma once
#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Math/Color.h" 

//button names are in Edit->Project Settings->Input
static int nbMSecPerf = 400;
static int nbMSecGood = 800;
static double speedNotes = 100; //m/s
static int percentageColored = 3; //1/x chances
static TArray<FString> buttonsNames = { "Square", "Triangle", "Circle", "Cross" };
#define PINK FLinearColor(0.973958f, 0.314507f, 0.876652f, 1.0f)
static TArray<FLinearColor> buttonFlagColor = { FColor::Blue, FColor::Purple, FColor::Yellow, FColor::White, FColor::Silver, FColor::Red, FColor::Green, PINK };

struct Note {
	int min;
	int sec;
	int msec;
	FString button;
	int duration;
};

static TArray<Note> testLevel = {
	{ 0, 2, 0, "Square", 0 },
	{ 0, 7, 0, "Cross", 800 }
};