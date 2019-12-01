#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "Gamestate.h"
#include <iostream>

namespace Sonar
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

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
			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			
			}
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

		this->_data->window.display();
	}
}