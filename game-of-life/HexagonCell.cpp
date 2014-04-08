#include "HexagonCell.h"


HexagonCell::HexagonCell()
{
}

void HexagonCell::checkStillAlive()
{
	int countOfAliveNeighbours = 0;

	if (this->neNeighbour != nullptr && this->neNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}
	if (this->eNeighbour != nullptr && this->eNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}
	if (this->seNeighbour != nullptr && this->seNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}
	if (this->swNeighbour != nullptr && this->swNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}
	if (this->wNeighbour != nullptr && this->wNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}
	if (this->nwNeighbour != nullptr && this->nwNeighbour->isAlive)
	{
		countOfAliveNeighbours++;
	}


	if (this->isAlive)
	{
		if (countOfAliveNeighbours < 2 || countOfAliveNeighbours > 3)
		{
			this->isAlive = false;
			return;
		}
		return;
	}


	if (countOfAliveNeighbours == 3)
	{
		this->isAlive = true;
		return;
	}
}


HexagonCell::~HexagonCell()
{
	neNeighbour = NULL;
	delete neNeighbour;
	eNeighbour = NULL;
	delete eNeighbour;
	seNeighbour = NULL;
	delete seNeighbour;
	swNeighbour = NULL;
	delete swNeighbour;
	wNeighbour = NULL;
	delete wNeighbour;
	nwNeighbour = NULL;
	delete nwNeighbour;
}
