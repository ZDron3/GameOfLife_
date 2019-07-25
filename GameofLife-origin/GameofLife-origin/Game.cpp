#include "Game.h"

Game::Game(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) {}
	else
	{
		_inputGrid = new Grid(rows, columns);
		_outputGrid = new Grid(rows, columns);
		ReachableCell *reachablecell = new ReachableCell();
		rules = new Rules();
		reachablecell->InitializeReachableCells();
		MaxGenerations = 1;

	}
}


Game::~Game()
{
}

void Game:: ToggleGridCell(int x, int y)
{
	if (_inputGrid->RowCount <= x || _inputGrid->ColumnCount <= y) {}
	else
	{
		_inputGrid->ToggleCell(x, y);

	}
}

/// <summary>
/// Initialize the Game of lide
/// </summary>
void Game::Init()
{
	Start();
}
/// <summary>
/// Start Game of Life
/// </summary>
void Game::Start()
{
	int currentGeneration = 0;
	GridHelper::Display(_inputGrid);
	do
	{
		currentGeneration++;
		// Process current generation for next generation
		ProcessGeneration();
	// Display the input grid
		GridHelper::Display(_inputGrid);
		// increment generation count                
	} while (currentGeneration < MaxGenerations);
}
/// <summary>
/// Process current generation for next generation
/// </summary>
void Game::ProcessGeneration()
{
	SetNextGeneration();
	Tick();
	FlipGridState();
}

/// <summary>
/// Handles tasks for setting next generation
/// </summary>
void Game::SetNextGeneration()
{
	// Generate next state of the Grid if last generate state process is completed
	if ((EvaluateCellTask == false) || (EvaluateCellTask != false && IsCompleted))
	{
		EvaluateCellTask = ChangeCellsState();
	}
	if ((EvaluateGridGrowthTask == false) || (EvaluateGridGrowthTask != false && IsCompleted))
	{
		EvaluateGridGrowthTask = ChangeGridState();
	}
}
/// <summary>
/// Tick ensures that previous generation taks are completed
/// </summary>
void Game::Tick()
{
	if (EvaluateGridGrowthTask != false)
	{
		//EvaluateGridGrowthTask.Wait();
	}
}

/// <summary>
/// Set output grid to input grid by Deep Copy output grid into input grid
/// </summary>
void Game::FlipGridState()
{
	GridHelper::Copy(*_outputGrid, *_inputGrid);
	_outputGrid->ReInitialize();
}

bool Game::ChangeCellsState()
{
	for (int i = 0; i < _inputGrid->GetRowCount(); i++)
	{
		for (int j = 0; j < _inputGrid->ColumnCount; j++)
		{
			rules->ChangeCellsState(*_inputGrid, *_outputGrid, new CoOrdinates(i, j));
		}
	}
	return true;
}

bool Game::ChangeGridState()
{
	rules->ChangeGridState(*_inputGrid, *_outputGrid);

	return true;
}

