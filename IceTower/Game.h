#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Menu_main.h"
#include "gwiazda.h"

class Game
{
public:
	Menu_main Glowne;
	std::string Nazwa_gry = "Ice Tower";
	std::string Producent = "Ekskluzywny producent Kaszubek";
	sf::RenderWindow window;
	void Start() {
		while (window.isOpen())
		{	
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				
				
			}
			Update();
			Draw();
		}
	}

	void Update() {

	}

	void Draw() {
		window.clear();
		Glowne.Draw(window);
		window.display();
	}
	Game():
		window(sf::VideoMode(500, 800), Producent)
	{};
	~Game() {};
};