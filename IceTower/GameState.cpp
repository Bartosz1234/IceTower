#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "Collisions.h"

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

		this->_data->assets.LoadTexture("Koniec", END_FILEPATH);

		this->_data->assets.LoadTexture("Stoi", MATE_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Skok", JUMP_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Prawo", RIGHT_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Lewo", LEFT_FRAME_FILEPATH);

		ground = new Ground(_data);
		spawner = new Spawner(_data);
		ending = new Ending(_data);

		edge = new Edge1(_data);
		mate = new Mate(_data);


		_gameState = GameStates::eReady;
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
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					if (event.key.code == sf::Keyboard::Key::Space)
					{
						mate->Click();
						mate->Jump();
					}
					if (event.key.code == sf::Keyboard::Key::Right)
					{
						mate->move(30, 0);
						mate->Right();
					}
					if (event.key.code == sf::Keyboard::Key::Left)
					{
						mate->move(-30, 0);
						mate->Left();
					}

				}

			}
		}
	}


	void GameState::Update(float dt)
	{
		

		spawner->Spawner1();
		spawner->Spawner2();
		spawner->Spawner3();
		ending->End();

		edge->SpawnEdgeLeft();

		edge->SpawnEdgeRight();
		if (GameStates::ePlaying == _gameState)
		{
			ground->MoveGround(dt);

			if (clock.getElapsedTime().asSeconds() > GROUND_SPAWN_FREQUENCY)
			{
				ground->RandomiseGroundOffset();

				ground->SpawnInvisibleGround();
				ground->SpawnGround1();
				ground->SpawnGround2();
				ground->SpawnGround3();

				clock.restart();
			}


			mate->Update(dt);

			std::vector<sf::Sprite> endingSprites = ending->GetSprites();

			for (int i = 0; i < endingSprites.size(); i++)
			{
				if (collisions.CheckSpriteCollision(mate->GetSprite(), endingSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;
				}
			}
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		ground->DrawGround();

		spawner->DrawSpawner();
		ending->DrawEnding();

		edge->DrawEdge();

		mate->Draw();

		this->_data->window.display();
	}
	
	
}