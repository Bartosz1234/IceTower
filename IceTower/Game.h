#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Menu_main.h"
#include "gwiazda.h"


class Game
{
public:
	gwiazda smierci;
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
		smierci.animuj();
	}

	void Draw() {
		window.clear();
		Glowne.Draw(window);
		
		//sf::Sprite nowa = smierci.getPokeball();
		//window.draw(nowa);
		
		window.draw(smierci.getPokeball());
		window.display();
	}
	
	Game():
		window(sf::VideoMode(640, 500), Producent),
		smierci(320,250,640, 500)
	{};
	~Game() {};
};