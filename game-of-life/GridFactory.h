#pragma once
#include <vector>
#include "cell.h"
#include "SquareCell.h"
#include "HexagonCell.h"
#include <iostream>

class SquareCell;

class GridFactory
{
private:
	int cellCount;
	const int gridWidth = 20;
	const int gridHeight = 20;

	template <class T>
	T* getNeighbour(std::vector<Cell*>* const cells, const int x, const int y);
public:
	GridFactory();
	std::vector<Cell*>* createSquareGrid();
	std::vector<Cell*>* createHexagonGrid();
	~GridFactory();
};

