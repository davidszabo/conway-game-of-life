#pragma once
#include "cell.h"
#include <iostream>

class HexagonCell :	public Cell
{
	friend class GridFactory;

private:
	HexagonCell* neNeighbour;
	HexagonCell* eNeighbour;
	HexagonCell* seNeighbour;
	HexagonCell* swNeighbour;
	HexagonCell* wNeighbour;
	HexagonCell* nwNeighbour;

public:
	HexagonCell();
	~HexagonCell();

	void checkStillAlive();
};

