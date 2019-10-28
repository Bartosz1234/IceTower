#pragma once
#include <string>
#include <SFML/Graphics.hpp>


class Game
{
public:
	std::string Nazwa_gry = "Ice Tower";
	std::string Producent = "Ekskluzywny producent Kaszubek";

	void Start() {
		sf::RenderWindow window(sf::VideoMode(200, 200), Producent);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				
				
			}
			window.clear();
			window.display();
		}
	}
	Game();
	~Game();
};



Game::Game()
{
}


Game::~Game()
{
}
