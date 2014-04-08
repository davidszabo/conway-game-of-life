#include "Game.h"


Game::Game(const CellType cellType)
{
	this->cellType = cellType;

	GridFactory gridFactory;
	if (this->cellType == CellType::SQUARE)
	{
		this->cells = gridFactory.createSquareGrid();
		loadSprites("../assets/square/");
	}
	if (this->cellType == CellType::HEXAGON)
	{
		this->cells = gridFactory.createHexagonGrid();
		loadSprites("../assets/hexagon/");
	}
	clock = sf::Clock();
}

void Game::loadSprites(const sf::String folder)
{
	aliveTexture = new sf::Texture();
	deadTexture = new sf::Texture();

	aliveSprite = new sf::Sprite();
	deadSprite = new sf::Sprite();
	
	this->aliveTexture->loadFromFile(folder + "alive.png");
	this->aliveSprite->setTexture(*aliveTexture);

	
	this->deadTexture->loadFromFile(folder + "dead.png");
	this->deadSprite->setTexture(*deadTexture);
}

void Game::Update(sf::RenderWindow& window)
{
	if (this->gameStarted)
	{
		float currentTime = clock.getElapsedTime().asSeconds();
		if (currentTime - this->lastCycleTime > 2)
		{
			for (auto i : *cells)
			{
				SquareCell* next = (SquareCell*)i;
				next->checkStillAlive();
			}
			this->lastCycleTime = clock.getElapsedTime().asSeconds();
		}
	}
	else
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			int rowHeight = (this->cellType == CellType::HEXAGON) ? 24 : 32;
			sf::Vector2i gridPosition = sf::Vector2i((int)ceil(localPosition.x / 32), (int)ceil(localPosition.y / rowHeight));
			for (auto i : *cells)
			{
				SquareCell* next = (SquareCell*)i;
				if (next->getCellCoordinate().x == gridPosition.x && next->getCellCoordinate().y == gridPosition.y)
				{
					next->makeCellAlive();
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			gameStarted = true;
			this->lastCycleTime = clock.getElapsedTime().asSeconds();
		}
	}
}

void Game::Draw(sf::RenderWindow& window)
{
	if (this->cellType == CellType::SQUARE)
	{
		for (auto i : *cells)
		{
			SquareCell* next = (SquareCell*)i;
			CellCoordinate coordinate = next->getCellCoordinate();
			if (next->isCellAlive())
			{
				aliveSprite->setPosition((float)coordinate.x * 32, (float)coordinate.y * 32);
				window.draw(*aliveSprite);
			} 
			else
			{
				deadSprite->setPosition((float)coordinate.x * 32, (float)coordinate.y * 32);
				window.draw(*deadSprite);
			}
		}
	}
	if (this->cellType == CellType::HEXAGON)
	{
		for (auto i : *cells)
		{
			SquareCell* next = (SquareCell*)i;
			CellCoordinate coordinate = next->getCellCoordinate();
			int hexagonOffset = 0;
			if (coordinate.y % 2)
			{
				hexagonOffset = 16;
			}
			else
			{
				hexagonOffset = 0;
			}
			if (next->isCellAlive())
			{
				aliveSprite->setPosition((float)coordinate.x * 32 + hexagonOffset, (float)coordinate.y * 24);
				window.draw(*aliveSprite);
			} else
			{
				deadSprite->setPosition((float)coordinate.x * 32 + hexagonOffset, (float)coordinate.y * 24);
				window.draw(*deadSprite);
			}
		}
	}
}

Game::~Game()
{
	cells->clear();
	cells = NULL;
	delete cells;
	aliveTexture = NULL;
	delete aliveTexture;
	aliveSprite = NULL;
	delete aliveSprite;
	deadTexture = NULL;
	delete deadTexture;
	deadSprite = NULL;
	delete deadSprite;
}
