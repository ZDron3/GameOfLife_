#include "Cell.h"

Cell::Cell(bool _IsAlive)
{
	IsAlive = _IsAlive;
}


Cell::~Cell()
{
}

std::string Cell::ToString()
{
	return (IsAlive ? "X" : "-");
}
