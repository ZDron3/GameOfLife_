#include <list>
#include <map>
#include "Grid.h"
#pragma once

using namespace std;

struct CoOrdinates
{
public: int X;
		int Y;
		CoOrdinates(int x, int y)
		{
			X = x;
			Y = y;
		}
};

enum CellTypeEnum
{
	TopLeftCorner,
	TopRightCorner,
	BottomLeftCorner,
	BottomRightCorner,
	TopSide,
	BottomSide,
	LeftSide,
	RightSide,
	Center,
	OuterTopSide,
	OuterRightSide,
	OuterBottomSide,
	OuterLeftSide,
	None
};

class ReachableCell
{
public:

	ReachableCell();

   ~ReachableCell();


	map<CellTypeEnum, list<CoOrdinates*>> *ReachableCells;


public:
	static CellTypeEnum GetCellType(Grid grid, CoOrdinates coOrdinates);

	void InitializeReachableCells();

	list<CoOrdinates*> GetReachable(CellTypeEnum celltype);

		
};
