#pragma once

struct Task {
	int StepCount;
	int ProcCount;
	int ID;
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