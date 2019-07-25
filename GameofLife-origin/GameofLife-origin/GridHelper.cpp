#include "GridHelper.h"



GridHelper::GridHelper()
{
}


GridHelper::~GridHelper()
{
}

void GridHelper::Display(Grid* grid)
{
   for(Rows* row : grid->GridObj)
	{
		for(Cell* cell : row->cells)
		{
			std::cout<< cell->ToString();
		}
	}
}

void GridHelper::Copy(Grid sourceGrid, Grid targetGrid)
{
	MatchScheme(sourceGrid, targetGrid);
	targetGrid.ReInitialize();
	AssignCellValues(sourceGrid, targetGrid);
}

void GridHelper::MatchScheme(Grid sourceGrid, Grid targetGrid)
{
	while (targetGrid.GetRowCount() < sourceGrid.GetRowCount())
	{
		Rows *newRow = new Rows();
		for (int k = 0; k < targetGrid.ColumnCount; k++)
		{
			Cell* newCell = new Cell(false);
			newRow->AddCell(newCell);
		}
		targetGrid.AddRow(newRow);
	}
	while (targetGrid.ColumnCount < sourceGrid.ColumnCount)
	{
		Cell* cell = new Cell(false);
		for (int k = 0; k <targetGrid.GetRowCount(); k++)
		{
			targetGrid.GridObj[k]->AddCell(cell);
		}
		targetGrid.ColumnCount += 1;
	}

}

void GridHelper::AssignCellValues(Grid sourceGrid, Grid targetGrid)
{
	for (int i = 0; i < sourceGrid.GetRowCount(); i++)
	{
		for (int j = 0; j < sourceGrid.ColumnCount; j++)
		{
			targetGrid.GridObj[i]->cells[j]->IsAlive = sourceGrid.GridObj[i]->cells[j]->IsAlive;
		}
	}
}

