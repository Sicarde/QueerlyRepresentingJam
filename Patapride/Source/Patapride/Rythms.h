#pragma once
#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"

//button names are in Edit->Project Settings->Input
int nbMSecPerf = 800;
int nbMSecGood = 1200;
TArray<FString> buttonsNames = { "Up", "Down", "Left", "Right", "Square", "Triangle", "Circle", "Cross" };

struct Note {
	int min;
	int sec;
	int msec;
	FString button;
};

TArray<Note> testLevel = {
	{ 0, 2, 0, "Up" },
	{ 0, 7, 0, "Down" }
};