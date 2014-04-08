#include "GridFactory.h"

GridFactory::GridFactory()
{
	this->cellCount = 1;
}

std::vector<Cell*>* GridFactory::createSquareGrid()
{
	std::vector<Cell*>* cells = new std::vector<Cell*>();
	for (int i = 0; i != gridWidth; ++i)
	{
		for (int j = 0; j != gridHeight; ++j)
		{
			SquareCell* newCell = new SquareCell();
			newCell->coordinate.x = i;
			newCell->coordinate.y = j;
			cells->push_back(newCell);
		}
	}

	for (auto i : *cells)
	{
		SquareCell* next = (SquareCell*)i;
		if (next->nNeighbour == nullptr)
		{
			next->nNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x, next->coordinate.y - 1);
		}
		if (next->neNeighbour == nullptr)
		{
			next->neNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x + 1, next->coordinate.y - 1);
		}
		if (next->eNeighbour == nullptr)
		{
			next->eNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x + 1, next->coordinate.y);
		}
		if (next->seNeighbour == nullptr)
		{
			next->seNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x + 1, next->coordinate.y + 1);
		}
		if (next->sNeighbour == nullptr)
		{
			next->sNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x, next->coordinate.y + 1);
		}
		if (next->swNeighbour == nullptr)
		{
			next->swNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x - 1, next->coordinate.y + 1);
		}
		if (next->wNeighbour == nullptr)
		{
			next->wNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x - 1, next->coordinate.y);
		}
		if (next->nwNeighbour == nullptr)
		{
			next->nwNeighbour = getNeighbour<SquareCell>(cells, next->coordinate.x - 1, next->coordinate.y - 1);
		}
	}

	return cells;
}

template <class T>
T* GridFactory::getNeighbour(std::vector<Cell*>* const cells, const int x, const int y)
{
	if (x < 0 || x >= gridWidth || y < 0 || y > gridHeight)
	{
		return nullptr;
	}
	for (auto i : *cells)
	{
		T* next = (T*)i;
		if (next->coordinate.x == x && next->coordinate.y == y)
		{
			return next;
		}
	}

	return nullptr;
}

std::vector<Cell*>* GridFactory::createHexagonGrid()
{
	std::vector<Cell*>* cells = new std::vector<Cell*>();
	for (int i = 0; i != gridWidth; ++i)
	{
		for (int j = 0; j != gridHeight; ++j)
		{
			HexagonCell* newCell = new HexagonCell();
			newCell->coordinate.x = i;
			newCell->coordinate.y = j;
			cells->push_back(newCell);
		}
	}

	for (auto i : *cells)
	{
		HexagonCell* next = (HexagonCell*)i;
		if (next->neNeighbour == nullptr)
		{
			next->neNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x + 1, next->coordinate.y - 1);
		}
		if (next->eNeighbour == nullptr)
		{
			next->eNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x + 1, next->coordinate.y);
		}
		if (next->seNeighbour == nullptr)
		{
			next->seNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x + 1, next->coordinate.y + 1);
		}
		if (next->swNeighbour == nullptr)
		{
			next->swNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x - 1, next->coordinate.y + 1);
		}
		if (next->wNeighbour == nullptr)
		{
			next->wNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x - 1, next->coordinate.y);
		}
		if (next->nwNeighbour == nullptr)
		{
			next->nwNeighbour = getNeighbour<HexagonCell>(cells, next->coordinate.x - 1, next->coordinate.y - 1);
		}
	}

	return cells;
}


GridFactory::~GridFactory()
{
}
