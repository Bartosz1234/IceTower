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

		this->_data->assets.LoadTexture("Edge", GAME_EDGE_FILEPATH);

		ground = new Ground(_data);
		spawner = new Spawner(_data);
		edge = new Edge1(_data);
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
		

		spawner->Spawner1();
		spawner->Spawner2();
		spawner->Spawner3();
		
		edge->SpawnEdgeLeft();
		
		edge->SpawnEdgeRight();
		

		if (clock.getElapsedTime().asSeconds() > GROUND_SPAWN_FREQUENCY)
		{
			ground->RandomiseGroundOffset();

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
		
		spawner->DrawSpawner();

		edge->DrawEdge();

		this->_data->window.display();
	}
}