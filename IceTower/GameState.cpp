#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "Collisions.h"
#include "GameOverState.h"

#include <iostream>

namespace Bartux
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

		// this->_data->assets.LoadTexture("Options background", OPTIONS_BACKGROUND_FILEPATH);
		// _backgroundOptions.setTexture(this->_data->assets.GetTexture("Game Background"));

		// this->_data->assets.LoadTexture("Options F1 background", OPTIONS_F1_BACKGROUND_FILEPATH);

		this->_data->assets.LoadFont("IceTower Font", ICETWOER_FONT);

		this->_data->assets.LoadTexture("Quitting", ESC_WINDOW_FILEPATH);
		_EscWindow.setTexture(this->_data->assets.GetTexture("Quitting"));

		this->_data->assets.LoadTexture("YesButton", YES_BUTTON_FILEPATH);
		_YesButton.setTexture(this->_data->assets.GetTexture("YesButton"));

		this->_data->assets.LoadTexture("NoButton", NO_BUTTON_FILEPATH);
		_NoButton.setTexture(this->_data->assets.GetTexture("NoButton"));

		_EscWindow.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_EscWindow.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_EscWindow.getGlobalBounds().height / 2)));

		_YesButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_YesButton.getGlobalBounds().width / 2),  (_data->window.getSize().y / 2) + 35));

		_NoButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_NoButton.getGlobalBounds().width / 2) + 80, (_data->window.getSize().y / 2) + 35));


		this->_data->assets.LoadTexture("Options F1 Window", OPTIONS_F1_BACKGROUND_FILEPATH);
		_OptionsWindow.setTexture(this->_data->assets.GetTexture("Options F1 Window"));

		_OptionsWindow.setPosition(sf::Vector2f(0, 0));



		ground = new Ground(_data);
		spawner = new Spawner(_data);
		ending = new Ending(_data);

		edge = new Edge1(_data);
		mate = new Mate(_data);

		// optionsstate = new OptionsState(_data);

		// optionsF1 = new OptionsF1(_data);

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
						
					}
					
					if (event.key.code == sf::Keyboard::Key::F2)
					{
						_gameState = GameStates::ePlaying;

					}
					if (event.key.code == sf::Keyboard::Key::Escape)
					{
						_gameState = GameStates::ePauseEsc;

					}

				}

			}
			if (this->_data->input.IsSpriteClicked(this->_YesButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
			
			if (this->_data->input.IsSpriteClicked(this->_NoButton, sf::Mouse::Left, this->_data->window))
			{
				
				_gameState = GameStates::eReadyEsc;
				
				if (_gameState == GameStates::eReadyEsc)
				{
					EscClock.restart();

					if (EscClock.getElapsedTime().asSeconds() > 1.0f)
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

		if (SpawnerClock.getElapsedTime().asSeconds() > 3)
		{
			spawner->Update(dt);
			spawner->Update(dt);
			spawner->Update(dt);
		}
		
		std::vector<sf::Sprite> GroundSprites = ground->GetSprites();

		for (int i = 0; i < GroundSprites.size(); i++)
		{
			if (collisions.CheckSpriteCollision(mate->GetSprite(), 0.750f, GroundSprites.at(i) , 1.1f))
			{
				_gameState = GameStates::eGameOver;

				// clock.restart();
			}
		}
		
		std::vector<sf::Sprite> EdgeSprites = edge->GetSprites();

		for (int i = 0; i < EdgeSprites.size(); i++)
		{
			if (collisions.CheckSpriteCollision(mate->GetSprite(),  EdgeSprites.at(i) ))
			{
				_gameState = GameStates::eGameOver;

				// clock.restart();
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

		if (GameStates::ePause == _gameState)
		{
			_data->window.draw(_OptionsWindow);
			
		}

		if (GameStates::ePauseEsc == _gameState)
		{
			_data->window.draw(_EscWindow);
			_data->window.draw(_YesButton);
			_data->window.draw(_NoButton);
		}



		flash->Draw();

		score->Draw();

		this->_data->window.display();
	}


}