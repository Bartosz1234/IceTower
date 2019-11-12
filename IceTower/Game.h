#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Menu_main.h"
#include "Menu.h"
#include "nowa_gra.h"

class Game
{
public:
	Menu menu;
	// gwiazda smierci;
	//Menu_main Glowne;
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
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Key::W)
						menu.moveUp();
					if (event.key.code == sf::Keyboard::Key::S)
						menu.moveDown();



				}
			}
			Update();
			Draw();
		}
	}

	void Update() {
		// smierci.animuj();
	}

	void Draw() {
		window.clear();
		//Glowne.Draw(window);
		menu.draw(window);
		//sf::Sprite nowa = smierci.getPokeball();
		//window.draw(nowa);
		
		// window.draw(smierci.getPokeball());
		window.display();
	}
	
	Game():
		window(sf::VideoMode(1420, 800), Producent, sf::Style::Titlebar | sf::Style::Close) ,
		// smierci(320,250,640, 500)
		menu(1420,800)
	{};
	~Game() {};
};