#pragma once
#include "Grid.h"
#include "Rules.h"
#include "GridHelper.h"
#include <iostream>
#include <sstream>
#include <future>
#include "ReachableCell.h"

#include <thread>

class Game
{
public:
	Game(int rows,int columns);

	~Game();

	void ToggleGridCell(int x, int y);

	void Init();

	void Start();

	void ProcessGeneration();

	void SetNextGeneration();

	void Tick();

	void FlipGridState();

	bool ChangeCellsState();

	bool ChangeGridState();


public :
	 Grid *_inputGrid, *_outputGrid;

	 Rules *rules;
	 
	 int MaxGenerations;
	 
	 int RowCount = 0;

	 int ColumnCount = 0;

	 bool EvaluateGridGrowthTask, IsCompleted;

	 bool EvaluateCellTask;

};
