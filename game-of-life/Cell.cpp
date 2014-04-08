#include "cell.h"

const CellCoordinate Cell::getCellCoordinate()
{
	return this->coordinate;
}

bool Cell::isCellAlive() 
{
	return this->isAlive;
}

void Cell::makeCellAlive()
{
	this->isAlive = true;
}