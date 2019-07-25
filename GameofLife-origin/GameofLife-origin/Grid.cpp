#include "Grid.h"



Grid::Grid(int rows,int colums)
{
	Setup(rows, colums);
	RowCount = rows;
}


Grid::~Grid()
{
}

void Grid::ReInitialize()
{
	Setup(GetRowCount(), ColumnCount);
}

void Grid::Setup(int rows, int columns)
{
	if (rows <= 0 || columns <= 0) {}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			Rows *row = new Rows();
			for (int j = 0; j < columns; j++)
			{
				Cell *cell = new Cell(false);
				row->AddCell(cell);
			}
			GridObj.push_back(row);
		}
		ColumnCount = columns;
	}
}

	void Grid::ToggleCell(int x, int y)
	{
		if (GetRowCount() <= x || ColumnCount <= y) {}
		else {
			GridObj[x]->cells[y]->IsAlive = !GridObj[x]->cells[y]->IsAlive;
		}
	}

	void Grid::InsertRow(int index, Rows* row)
	{
		if (index < 0 || index >= GetRowCount())
		{
		}
		else {
		
			GridObj.insert(GridObj.begin()+index,row);
		}
	}


void Grid::AddRow(Rows* row)
{
	GridObj.push_back(row);
}

int Grid::GetRowCount()
{
	return GridObj.size();
}
