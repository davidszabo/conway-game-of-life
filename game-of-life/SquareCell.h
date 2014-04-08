#pragma once
#include "cell.h"
#include <iostream>

class SquareCell : public Cell 
{
	friend class GridFactory;

private:
	SquareCell* nNeighbour;
	SquareCell* neNeighbour;
	SquareCell* eNeighbour;
	SquareCell* seNeighbour;
	SquareCell* sNeighbour;
	SquareCell* swNeighbour;
	SquareCell* wNeighbour;
	SquareCell* nwNeighbour;

public:
	SquareCell();
	~SquareCell();

	void checkStillAlive();	
};

