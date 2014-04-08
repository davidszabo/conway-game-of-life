#pragma once

struct CellCoordinate
{
	int x, y;
};

class Cell 
{
protected:
	bool isAlive = false;
	CellCoordinate coordinate;

public:
	virtual const CellCoordinate getCellCoordinate();
	bool isCellAlive();
	void makeCellAlive();
	virtual void checkStillAlive() = 0;

	
};