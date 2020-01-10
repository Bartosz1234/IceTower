#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"


#include <iostream>

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	
		this->_data->assets.LoadTexture("level_one_1", GROUND_1_FILEPATH);
		//_background.setTexture(this->_data->assets.GetTexture("level_one_1"));

		this->_data->assets.LoadTexture("level_one_2", GROUND_2_FILEPATH);
		//_background.setTexture(this->_data->assets.GetTexture("level_one_2"));

		this->_data->assets.LoadTexture("level_one_3", GROUND_3_FILEPATH);
		//_background.setTexture(this->_data->assets.GetTexture("level_one_3"));

		ground = new Ground(_data);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Key::Space)
				{
				
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		ground->MoveGround(dt);

		if (clock.getElapsedTime().asSeconds() > GROUND_SPAWN_FREQUENCY)
		{
			ground->SpawnInvisibleGround();
			ground->SpawnGround1();
			ground->SpawnGround2();
			ground->SpawnGround3();

			clock.restart();
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		ground->DrawGround();
		this->_data->window.display();
	}
}