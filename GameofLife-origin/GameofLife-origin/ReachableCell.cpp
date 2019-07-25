#include "ReachableCell.h"
//#include "ReachableCell.h"
//#include "ReachableCell.h"
//
//
//
ReachableCell::ReachableCell()
{
	ReachableCells = new map<CellTypeEnum, list<CoOrdinates *>>();
}


ReachableCell::~ReachableCell()
{
}


void ReachableCell::InitializeReachableCells()
{
	CellTypeEnum innerCell;
	// push_back Reachable adjacent cell co-ordinates for Top Left corner cell into std::map with TopLeftCorner CellTypeEnum as key
	innerCell = CellTypeEnum::TopLeftCorner;
	list<CoOrdinates*> TopLeftCoOrdinateList;
	TopLeftCoOrdinateList.push_back(new CoOrdinates(0, 1));
	TopLeftCoOrdinateList.push_back(new CoOrdinates(1, 1));
	TopLeftCoOrdinateList.push_back(new CoOrdinates(1, 0));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, TopLeftCoOrdinateList));

	// push_back Reachable adjacent cell co-ordinates for Top right corner cell into std::map with TopRightCorner CellTypeEnum as key
	innerCell = CellTypeEnum::TopRightCorner;
	std::list<CoOrdinates*> TopRightCoOrdinateList;
	TopRightCoOrdinateList.push_back(new CoOrdinates(1, 0));
	TopRightCoOrdinateList.push_back(new CoOrdinates(1, -1));
	TopRightCoOrdinateList.push_back(new CoOrdinates(0, -1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, TopRightCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for bottom left corner cell into std::map with BottomLeftCorner CellTypeEnum as key
	innerCell = CellTypeEnum::BottomLeftCorner;
	std::list<CoOrdinates*> BottomLeftCoOrdinateList;
	BottomLeftCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	BottomLeftCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	BottomLeftCoOrdinateList.push_back(new CoOrdinates(0, 1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, BottomLeftCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for bottom right corner cell into std::map with BottomRightCorner CellTypeEnum as key
	innerCell = CellTypeEnum::BottomRightCorner;
	std::list<CoOrdinates*> BottomRightCoOrdinateList;
	BottomRightCoOrdinateList.push_back(new CoOrdinates(0, -1));
	BottomRightCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	BottomRightCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, BottomRightCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for top side cell into std::map with BottomRightCorner TopSide as key
	innerCell = CellTypeEnum::TopSide;
	std::list<CoOrdinates*> TopSideCoOrdinateList;
	TopSideCoOrdinateList.push_back(new CoOrdinates(0, 1));
	TopSideCoOrdinateList.push_back(new CoOrdinates(1, 1));
	TopSideCoOrdinateList.push_back(new CoOrdinates(1, 0));
	TopSideCoOrdinateList.push_back(new CoOrdinates(1, -1));
	TopSideCoOrdinateList.push_back(new CoOrdinates(0, -1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, TopSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for bottom side cell into std::map with BottomRightCorner BottomSide as key
	innerCell = CellTypeEnum::BottomSide;
	std::list<CoOrdinates*> BottomSideCoOrdinateList;
	BottomSideCoOrdinateList.push_back(new CoOrdinates(0, -1));
	BottomSideCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	BottomSideCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	BottomSideCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	BottomSideCoOrdinateList.push_back(new CoOrdinates(0, 1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, BottomSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for left side cell into std::map with BottomRightCorner LeftSide as key
	innerCell = CellTypeEnum::LeftSide;
	std::list<CoOrdinates*> LeftSideCoOrdinateList;
	LeftSideCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	LeftSideCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	LeftSideCoOrdinateList.push_back(new CoOrdinates(0, 1));
	LeftSideCoOrdinateList.push_back(new CoOrdinates(1, 1));
	LeftSideCoOrdinateList.push_back(new CoOrdinates(1, 0));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, LeftSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for right side cell into std::map with BottomRightCorner RightSide as key
	innerCell = CellTypeEnum::RightSide;
	std::list<CoOrdinates*> RightSideCoOrdinateList;
	RightSideCoOrdinateList.push_back(new CoOrdinates(1, 0));
	RightSideCoOrdinateList.push_back(new CoOrdinates(1, -1));
	RightSideCoOrdinateList.push_back(new CoOrdinates(0, -1));
	RightSideCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	RightSideCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, RightSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for Center cell into std::map with BottomRightCorner Center as key
	innerCell = CellTypeEnum::Center;
	std::list<CoOrdinates*> CenterCoOrdinateList;
	CenterCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	CenterCoOrdinateList.push_back(new CoOrdinates(0, 1));
	CenterCoOrdinateList.push_back(new CoOrdinates(1, 1));
	CenterCoOrdinateList.push_back(new CoOrdinates(1, 0));
	CenterCoOrdinateList.push_back(new CoOrdinates(1, -1));
	CenterCoOrdinateList.push_back(new CoOrdinates(0, -1));
	CenterCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, CenterCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for outer top side cell into std::map with BottomRightCorner OuterTopSide as key
	innerCell = CellTypeEnum::OuterTopSide;
	std::list<CoOrdinates*> OuterTopSideCoOrdinateList;
	OuterTopSideCoOrdinateList.push_back(new CoOrdinates(1, -1));
	OuterTopSideCoOrdinateList.push_back(new CoOrdinates(1, 0));
	OuterTopSideCoOrdinateList.push_back(new CoOrdinates(1, 1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, OuterTopSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for outer right side cell into std::map with BottomRightCorner OuterRightSide as key
	innerCell = CellTypeEnum::OuterRightSide;
	std::list<CoOrdinates*> OuterRightSideCoOrdinateList;
	OuterRightSideCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	OuterRightSideCoOrdinateList.push_back(new CoOrdinates(0, -1));
	OuterRightSideCoOrdinateList.push_back(new CoOrdinates(1, -1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, OuterRightSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for outer bottom side cell into std::map with BottomRightCorner OuterBottomSide as key
	innerCell = CellTypeEnum::OuterBottomSide;
	std::list<CoOrdinates*> OuterBottomSideCoOrdinateList;
	OuterBottomSideCoOrdinateList.push_back(new CoOrdinates(-1, -1));
	OuterBottomSideCoOrdinateList.push_back(new CoOrdinates(-1, 0));
	OuterBottomSideCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, OuterBottomSideCoOrdinateList));

		// push_back Reachable adjacent cell co-ordinates for outer left side cell into std::map with BottomRightCorner OuterLeftSide as key
	innerCell = CellTypeEnum::OuterLeftSide;
	std::list<CoOrdinates*> OuterLeftSideCoOrdinateList;
	OuterLeftSideCoOrdinateList.push_back(new CoOrdinates(-1, 1));
	OuterLeftSideCoOrdinateList.push_back(new CoOrdinates(0, 1));
	OuterLeftSideCoOrdinateList.push_back(new CoOrdinates(1, 1));
	ReachableCells->insert(std::pair<CellTypeEnum, list<CoOrdinates*>>(innerCell, OuterLeftSideCoOrdinateList));
}

CellTypeEnum ReachableCell::GetCellType(Grid grid, CoOrdinates coOrdinates)
{
	if ((coOrdinates.X < -1 || coOrdinates.X > grid.RowCount) || (coOrdinates.Y < -1 || coOrdinates.Y > grid.ColumnCount))
	{
		//no on
	}
	CellTypeEnum enumCellType = CellTypeEnum::None;
	if (coOrdinates.X == 0 && coOrdinates.Y == 0)
		enumCellType = CellTypeEnum::TopLeftCorner;
	else if (coOrdinates.X == 0 && coOrdinates.Y == grid.ColumnCount - 1)
		enumCellType = CellTypeEnum::TopRightCorner;
	else if (coOrdinates.X == grid.RowCount - 1 && coOrdinates.Y == 0)
		enumCellType = CellTypeEnum::BottomLeftCorner;
	else if (coOrdinates.X == grid.RowCount - 1 && coOrdinates.Y == grid.ColumnCount - 1)
		enumCellType = CellTypeEnum::BottomRightCorner;
	else if (coOrdinates.X == 0 && (coOrdinates.Y > 0 && coOrdinates.Y < grid.ColumnCount - 1))
		enumCellType = CellTypeEnum::TopSide;
	else if (coOrdinates.X == grid.RowCount - 1 && (coOrdinates.Y > 0 && coOrdinates.Y < grid.ColumnCount - 1))
		enumCellType = CellTypeEnum::BottomSide;
	else if ((coOrdinates.X > 0 && coOrdinates.X < grid.RowCount - 1) && coOrdinates.Y == 0)
		enumCellType = CellTypeEnum::LeftSide;
	else if ((coOrdinates.X > 0 && coOrdinates.X < grid.RowCount - 1) && coOrdinates.Y == grid.ColumnCount - 1)
		enumCellType = CellTypeEnum::RightSide;
	else if ((coOrdinates.X > 0 && coOrdinates.X < grid.RowCount - 1) && (coOrdinates.Y > 0 && coOrdinates.Y < grid.ColumnCount - 1))
		enumCellType = CellTypeEnum::Center;
	else if (coOrdinates.X == -1 && (coOrdinates.Y > 0 && coOrdinates.Y < grid.ColumnCount - 1))
		enumCellType = CellTypeEnum::OuterTopSide;
	else if ((coOrdinates.X > 0 && coOrdinates.X < grid.RowCount - 1) && coOrdinates.Y == grid.ColumnCount)
		enumCellType = CellTypeEnum::OuterRightSide;
	else if (coOrdinates.X == grid.RowCount && (coOrdinates.Y > 0 && coOrdinates.Y < grid.ColumnCount - 1))
		enumCellType = CellTypeEnum::OuterBottomSide;
	else if ((coOrdinates.X > 0 && coOrdinates.X < grid.RowCount - 1) && coOrdinates.Y == -1)
		enumCellType = CellTypeEnum::OuterLeftSide;
	return enumCellType;
}

list<CoOrdinates*> ReachableCell::GetReachable(CellTypeEnum celltype)
{
	return ReachableCells->find(celltype)->second;
}
