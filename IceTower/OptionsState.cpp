#include "OptionsState.h"
#include <sstream>
#include "MainMenuState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>
#include "MainMenuState.h"
#include "OptionsState.h"

namespace Sonar {


	OptionsState::OptionsState(GameDataRef data) : _data(data)
	{

	}

	void OptionsState::Init()
	{
		this->_data->assets.LoadTexture("Options Background", OPTIONS_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Options Background"));
	}

	void OptionsState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (event.key.code == sf::Keyboard::Key::Escape)
			{
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			

		}
	}

	void OptionsState::Update(float dt)
	{

	}

	void OptionsState::Draw(float dt)
	{
		 this->_data->window.clear(sf::Color::Blue);

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}

}