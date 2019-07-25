#include "Grid.h"
#include "Rows.h"
#include <Windows.h>
#include "ReachableCell.h"
#pragma once

class Rules
{
public:

	ReachableCell *cell;

	Rules();

    ~Rules();

	void ChangeCellsState(Grid inputGrid, Grid outputGrid, CoOrdinates * coOrdinates);

	int CountAliveNeighbours(Grid grid, CoOrdinates * coOrdinates);

	int IsAliveNeighbour(Grid grid, CoOrdinates baseCoOrdinates, CoOrdinates offSetCoOrdinates);

	bool IsAliveInNextState(Cell cell, int liveNeighbourCount);

	void ChangeGridState(Grid inputGrid, Grid outputGrid);

	void CheckColumnGrowth(Grid inputGrid, Grid outputGrid, int colId);

	void CheckRowGrowth(Grid inputGrid, Grid outputGrid, int rowId);

};
