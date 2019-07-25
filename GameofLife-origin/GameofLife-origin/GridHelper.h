#pragma once
#include"Grid.h"

class GridHelper
{
public:
	GridHelper();
	
	~GridHelper();

static void Display(Grid* grid);

static void Copy(Grid sourceGrid, Grid targetGrid);

static	void MatchScheme(Grid sourceGrid,Grid targetGrid);

static	void AssignCellValues(Grid sourceGrid, Grid targetGrid);
};
