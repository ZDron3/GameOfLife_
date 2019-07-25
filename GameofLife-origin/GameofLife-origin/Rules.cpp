#include "Rules.h"

Rules::Rules()
{
	cell = new ReachableCell();
}


Rules::~Rules()
{
}


 void Rules::ChangeCellsState(Grid inputGrid, Grid outputGrid, CoOrdinates*  coOrdinates)
{
	int liveNeighbourCount = CountAliveNeighbours(inputGrid, coOrdinates);

	if (IsAliveInNextState(inputGrid.GridObj[coOrdinates->X]->cells[coOrdinates->Y], liveNeighbourCount))
	{
		//set output grid's cell to live only if it is in alive status in next generation
		outputGrid.GridObj[coOrdinates->X]->cells[coOrdinates->Y]->IsAlive = true;
	}
}

 int Rules::CountAliveNeighbours(Grid grid, CoOrdinates* coOrdinates)
{
	int liveNeighbours = 0;
	// Get the Cell type of current cell
	CellTypeEnum enumInnerCell = ReachableCell::GetCellType(grid, *coOrdinates);
	std::list<CoOrdinates*> reachableCells;
	// populate reachable cells from current cell for easier traversing
	reachableCells = cell->GetReachable(enumInnerCell);
	if (reachableCells.size() == 0) {}
	else {
		for (CoOrdinates* coOrds : reachableCells)
		{
			liveNeighbours += IsAliveNeighbour(grid, *coOrdinates, *coOrds);
		}
	}
	return liveNeighbours;
}

 int Rules::IsAliveNeighbour(Grid grid, CoOrdinates baseCoOrdinates, CoOrdinates offSetCoOrdinates)
{
	int live = 0; // set default as 0
	int x = baseCoOrdinates.X + offSetCoOrdinates.X; // get x axis of neighbour
	int y = baseCoOrdinates.Y + offSetCoOrdinates.Y; // get y axis of neighbour
	// check the computed bound is within range of grid, if it is not within bounds live is 0 as default
	if ((x >= 0 && x < grid.RowCount) && y >= 0 && y < grid.ColumnCount)
	{
		// if reachable neighbour cell is alive then set live to 1 otherwise 0
		live = grid.GridObj[x]->cells[y]->IsAlive ? 1 : 0;
	}

	return live;
}

 bool Rules::IsAliveInNextState(Cell cell, int liveNeighbourCount)
{
	bool alive = false;
	if (cell.IsAlive)
	{
		// if cell is alive and 2 or 3 ajacent cells are alive then set it to alive in next generation
		if (liveNeighbourCount == 2 || liveNeighbourCount == 3)
		{
			alive = true;
		}
	}
	// if cell is dead and 3 adjacent cells are alive then set it to alive in next generation
	else if (liveNeighbourCount == 3)
	{
		alive = true;
	}
	return alive;
}

 void Rules::ChangeGridState(Grid inputGrid, Grid outputGrid)
{
	CheckRowGrowth(inputGrid, outputGrid, -1);
	CheckRowGrowth(inputGrid, outputGrid, inputGrid.RowCount);
	CheckColumnGrowth(inputGrid, outputGrid, -1);
	CheckColumnGrowth(inputGrid, outputGrid, inputGrid.ColumnCount);
}

 void Rules::CheckColumnGrowth(Grid inputGrid, Grid outputGrid, int colId)
{
	//Create a whole new column in the beginning or end if rule is satified for any of the cell
	bool columnCreatedFlag = false;
	//Boolean IsPreviousCellsFilled = false;
	// start with the index 1  until 1 less than last index as index 0 and last index cannot have 3 live adjacent cell in any case
	// This index 0 and last index must be included if rule is changed in future; dead can alive with 2 live adjacent cells
	for (int i = 1; i < inputGrid.RowCount - 1; i++)
	{
		if (CountAliveNeighbours(inputGrid, new CoOrdinates(i, colId)) == 3)
		{
			if (columnCreatedFlag == false)
			{
				//if (IsPreviousCellsFilled == false)
				//{
				for (int k = 0; k < outputGrid.RowCount; k++)
				{
					// Fill all cells with false
					Cell* newDeadCell = new Cell(false);
					if (colId == -1)
					{
						outputGrid.GridObj[k]->InsertCell(0, newDeadCell, outputGrid.ColumnCount);
					}
					else
					{
						outputGrid.GridObj[k]->AddCell(newDeadCell);
					}
				}
				//    IsPreviousCellsFilled = true;
				//}
				// increment column count to 1
				outputGrid.ColumnCount += 1;
				columnCreatedFlag = true;
			}
			int yAxis = (colId == -1) ? 0 : outputGrid.ColumnCount - 1;
			outputGrid.GridObj[i]->cells[yAxis]->IsAlive = true;
		}
	}
}

 void Rules::CheckRowGrowth(Grid inputGrid, Grid outputGrid, int rowId)
{
	//Create a whole new row in the beginning or end if rule is satified for any of the cell
	bool rowCreatedFlag = false;
	//Boolean IsPreviousCellsFilled = false;
	// start with the index 1  until 1 less than last index as index 0 and last index cannot have 3 live adjacent cell in any case
	// This index 0 and last index must be included if rule is changed in future; dead can alive with 2 live adjacent cells
	for (int j = 1; j < inputGrid.ColumnCount - 1; j++)
	{
		if (CountAliveNeighbours(inputGrid, new CoOrdinates(rowId, j)) == 3)
		{
			if (rowCreatedFlag == false)
			{
				Rows *newRow = new Rows();
				//if (IsPreviousCellsFilled == false)
				//{
				for (int k = 0; k < outputGrid.ColumnCount; k++)
				{
					// Fill all cells with false
					Cell* newDeadCell = new Cell(false);
					newRow->AddCell(newDeadCell);
				}
				//IsPreviousCellsFilled = true;
				//}
				if (rowId == -1)
				{
					outputGrid.InsertRow(0, newRow);
				}
				else
				{
					outputGrid.AddRow(newRow);
				}
				rowCreatedFlag = true;
			}
			int XAxis = (rowId == -1) ? 0 : outputGrid.RowCount - 1;
			outputGrid.GridObj[XAxis]->cells[j]->IsAlive = true;
		}
	}
}