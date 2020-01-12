#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "Collisions.h"
#include "GameOverState.h"

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

		// this->_data->assets.LoadTexture("Scoring Ground", SCORING_GROUND_FILEPATH);

		this->_data->assets.LoadTexture("Stoi", MATE_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Skok", JUMP_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Prawo", RIGHT_FRAME_FILEPATH);
		this->_data->assets.LoadTexture("Lewo", LEFT_FRAME_FILEPATH);

		this->_data->assets.LoadTexture("Options background", OPTIONS_BACKGROUND_FILEPATH);
		// _backgroundOptions.setTexture(this->_data->assets.GetTexture("Game Background"));

		this->_data->assets.LoadTexture("Options F1 background", OPTIONS_F1_BACKGROUND_FILEPATH);

		this->_data->assets.LoadFont("IceTower Font", ICETWOER_FONT);


		ground = new Ground(_data);
		spawner = new Spawner(_data);
		ending = new Ending(_data);

		edge = new Edge1(_data);
		mate = new Mate(_data);

		// optionsstate = new OptionsState(_data);

		optionsF1 = new OptionsF1(_data);

		flash = new Flash(_data);

		score = new Score(_data);

		_score = 0;
		score->UpdateScore(_score);

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
					if (event.key.code == sf::Keyboard::Key::F1)
					{
						_gameState = GameStates::ePause;
						this->_data->machine.AddState(StateRef(new OptionsState(_data)), true);
					}
					if (event.key.code == sf::Keyboard::Key::F2)
					{
						_gameState = GameStates::ePlaying;

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

			if (LevelClock.getElapsedTime().asSeconds() > 20.0f)
			{
				float B = GROUND_SPAWN_FREQUENCY - 1.0f;

				if (clock.getElapsedTime().asSeconds() > B)
				{
					ground->RandomiseGroundOffset();

					ground->SpawnInvisibleGround();
					ground->SpawnGround1();
					ground->SpawnGround2();
					ground->SpawnGround3();

					ground->SpawnScoringGround();
					clock.restart();
				}
			}
			else
			{
				if (clock.getElapsedTime().asSeconds() > GROUND_SPAWN_FREQUENCY)
				{
					ground->RandomiseGroundOffset();

					ground->SpawnInvisibleGround();
					ground->SpawnGround1();
					ground->SpawnGround2();
					ground->SpawnGround3();

					ground->SpawnScoringGround();
					clock.restart();
				}
			}

			mate->Update(dt);

			std::vector<sf::Sprite> endingSprites = ending->GetSprites();

			for (int i = 0; i < endingSprites.size(); i++)
			{
				if (collisions.CheckSpriteCollision(mate->GetSprite(), endingSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
				}
			}

			if (GameStates::ePlaying == _gameState)
			{

				std::vector<sf::Sprite> &ScoringSprite = ground->GetScoringSprite();

				for (int i = 0; i < ScoringSprite.size(); i++)
				{

					if (collisions.CheckSpriteCollision(mate->GetSprite(), ScoringSprite.at(i)))
					{
						_score++;

						score->UpdateScore(_score);

						ScoringSprite.erase(ScoringSprite.begin() + i);
					}
				}
			}
		}
		if (GameStates::eGameOver == _gameState)
		{
			flash->Show(dt);
			
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_YOU_DIE)
			{
				_data->machine.AddState(StateRef(new GameOverState( _data, _score) ), true);
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

		//if (_gameState == GameStates::ePause)
		//{
		//	// this->_data->window.draw(this->_backgroundOptions);
		//	//optionsstate->Draw(dt);
		//	optionsF1->Draw(dt);
		//}

		flash->Draw();

		score->Draw();

		this->_data->window.display();
	}


}