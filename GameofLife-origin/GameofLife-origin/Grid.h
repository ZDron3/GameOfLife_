#pragma once
#include"Rows.h"

class Grid
{
public:
	Grid(int rows, int colums);

	~Grid();

	int GetRowCount();

	void Setup(int rows,int columns);

	void ReInitialize();

	void ToggleCell(int x, int y);

	void InsertRow(int index, Rows* row);

	void AddRow(Rows* row);

	
public:
	std::vector<Rows*> GridObj;

	int ColumnCount=0;

	int RowCount = 0;
};

