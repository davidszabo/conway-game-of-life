#include <SFML/Graphics.hpp>
#include "Game.h"

int main() 
{
	Game game = Game(CellType::SQUARE);
	sf::RenderWindow window(sf::VideoMode(640, 640), "Game of Life");
	window.setFramerateLimit(30);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		game.Update(window);

		window.clear();
		game.Draw(window);
		window.display();
	}

	return 0;
}