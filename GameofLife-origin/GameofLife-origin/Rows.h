#pragma once
#include "Cell.h"
#include <iostream>
#include <list>
#include <vector>

class Rows
{
public:
	Rows();

	void AddCell(Cell* cell);

	void InsertCell(int position, Cell* cell, int colCount);

	~Rows();

public:
	std::vector<Cell*> cells;
	std::vector<Cell*>::iterator it;

};
