#pragma once
#include "CoreMinimal.h"
#include "Runtime/Core/Public/Containers/Array.h"

//button names are in Edit->Project Settings->Input
int nbMSecPerf = 800;
int nbMSecGood = 1200;
TArray<FString> buttonsNames = { "Square", "Triangle", "Circle", "Cross" };

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