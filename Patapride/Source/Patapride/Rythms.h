#pragma once
#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Math/Color.h" 

//button names are in Edit->Project Settings->Input
int nbMSecPerf = 400;
int nbMSecGood = 800;
double speedNotes = 100; //m/s
int percentageColored = 3; //1/x chances
int meh = 0;
TArray<FString> buttonsNames = { "Square", "Triangle", "Circle", "Cross" };
TArray<FColor> buttonFlagColor = { FColor::Blue, FColor::Purple, FColor::Yellow, FColor::White, FColor::Black };

struct Note {
	int min;
	int sec;
	int msec;
	FString button;
	int duration;
};

TArray<Note> testLevel = {
	{ 0, 2, 0, "Square", 0 },
	{ 0, 7, 0, "Cross", 800 }
};