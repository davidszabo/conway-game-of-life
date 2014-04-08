#pragma once
#include <vector>
#include <iterator>
#include "cell.h"
#include "GridFactory.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

enum CellType { SQUARE, HEXAGON };

class Game
{
private:
	std::vector<Cell*>* cells;
	CellType cellType;

	bool gameStarted = false;
	float lastCycleTime;
	
	sf::Clock clock;
	sf::Texture* aliveTexture;
	sf::Sprite* aliveSprite;
	sf::Texture* deadTexture;
	sf::Sprite* deadSprite;

	void loadSprites(sf::String);

public:
	Game(const CellType cellType);

	void Update(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	~Game();
};