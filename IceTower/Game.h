#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Menu_main.h"
#include "Menu.h"
#include "Definitions.h"

// #include "nowa_gra.h"

struct GameData
{
	StateMachine machine;

	AssetManager assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Menu menu;
	// nowa_gra nowa_gra;
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
					// if (event.key.code == sf::Keyboard::Key::Enter)
						// menu.~Menu;
						// nowa_gra.draw(window);
						// Tutaj menu destruktor
						// Tutaj nowa_gra konstrukto/rysowanie

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