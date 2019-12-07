#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Gamestate.h"
#include <iostream>
#include "DEFINITIONS.h"

namespace Sonar
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
		if (!font.loadFromFile("arial.ttf"))
		{
			return;
		}

		for (int i = 0; i < ILOSC_POZYCJI_MENU; i++)
		{

			menu[i].setFont(font);
			menu[i].setFillColor(sf::Color::White);
			menu[i].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / (ILOSC_POZYCJI_MENU + 1) * (i + 1)));

		}
		int q = 0;
		menu[q++].setString("Nowa gra");
		menu[q++].setString("Wyniki");
		menu[q++].setString("Opcje");
		menu[q++].setString("Wyjscie");
		menu[0].setFillColor(sf::Color::Magenta);
	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		//this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		/*_background.setTexture(this->_data->assets.GetTexture("Play Button"));

		_playButton.setPosition( (SCREEN_WIDTH / 2) - ( _playButton.
			getGlobalBounds( ).width / 2), (SCREEN_HEIGHT / 2) - (_playButton.
				getGlobalBounds().height / 2));*/
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			/*if (event.type == sf::Event::KeyPressed) {*/
				/*if (event.key.code == sf::Keyboard::Key::W)
					menu.moveUp();
				if (event.key.code == sf::Keyboard::Key::S)
					menu.moveDown();*/
				if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
				{
					this->_data->machine.AddState(StateRef(new GameState(_data)), true);

				}

			/*}*/
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_playButton);
		
		for (int i = 0; i < ILOSC_POZYCJI_MENU; i++)
		{
			this->_data->window.draw(this->menu[i]);
		}
		this->_data->window.display();

	}

	void MainMenuState::moveUp()
	{
		if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_MENU)
		{
			menu[selectedItem].setFillColor(sf::Color::White);
			menu[selectedItem].setStyle(sf::Text::Regular);
			selectedItem--;
			if (selectedItem < 0)
				selectedItem = ILOSC_POZYCJI_MENU - 1;
			menu[selectedItem].setFillColor(sf::Color::Magenta);
			menu[selectedItem].setStyle(sf::Text::Bold);
		}


	}

	void MainMenuState::moveDown()
	{
		if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_MENU)
		{
			menu[selectedItem].setFillColor(sf::Color::White);
			menu[selectedItem].setStyle(sf::Text::Regular);
			selectedItem++;
			if (selectedItem >= ILOSC_POZYCJI_MENU)
				selectedItem = 0;
			menu[selectedItem].setFillColor(sf::Color::Magenta);
			menu[selectedItem].setStyle(sf::Text::Bold);
		}

	}

}