#include "OptionsF1.h"

#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>


namespace Sonar {


	OptionsF1::OptionsF1(GameDataRef data) : _data(data)
	{

	}

	void OptionsF1::Init()
	{
		this->_data->assets.LoadTexture("Options F1 Background", OPTIONS_F1_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Options F1 Background"));
	}

	void OptionsF1::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (event.key.code == sf::Keyboard::Key::F1)
			{
				// this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			if (event.key.code == sf::Keyboard::Key::Enter)
			{
				 this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}


		}
	}

	void OptionsF1::Update(float dt)
	{

	}

	void OptionsF1::Draw(float dt)
	{
		_data->window.draw(this->_background);

		this->_data->window.display();
	}
}
