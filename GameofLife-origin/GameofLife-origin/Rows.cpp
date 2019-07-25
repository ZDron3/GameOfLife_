#include "Rows.h"



Rows::Rows()
{
	it = cells.begin();
}


Rows::~Rows()
{
}

void Rows::AddCell(Cell* cell)
{
	cells.push_back(cell);
}
/// <summary>
/// Insert a cell into specified index position
/// </summary>
/// <param name="index"></param>
/// <param name="cell"></param>
/// <param name="ColumnCount"></param>
void Rows::InsertCell(int index, Cell* cell, int ColumnCount)
{
	if (index < 0 || index >= ColumnCount)
	{

	}
	else
	{
		cells.insert(it, index, cell);
	}
}
