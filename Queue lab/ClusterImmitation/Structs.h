#pragma once

struct Task {
	int StepCount;
	int ProcCount;
	int ID;
	int Color;
};

struct Processor {
	bool free;
	int ActiveTaskID;
	int CurrentStepCount;
	int MaxStepCount;
	int InactiveTactsCount;
	int id;
	int X;
	int Y;
};