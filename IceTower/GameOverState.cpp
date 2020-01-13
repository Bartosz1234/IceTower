#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "GameOverState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include <fstream>

#include <iostream>

namespace Bartux
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data) , _score(score)
	{

	}

	void GameOverState::Init()
	{
		std::ifstream readFile;
		readFile.open("Wyniczki.txt");


		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _bestScore;
			}
		}

		std::cout << _bestScore << std::endl;

		readFile.close();

		std::ofstream writeFile("Wyniczki.txt");

		if (writeFile.is_open())
		{
			if (_score > _bestScore)
			{
				_bestScore = _score;
			}

			writeFile << _bestScore << std::endl;
			writeFile << _score << std::endl;
		}

		writeFile.close();


		//this->_data->assets.LoadTexture("game_background", GAME_BACKGROUND_FILEPATH);
		
		this->_data->assets.LoadTexture("GameOver", GAME_OVER_WINDOW);

		this->_data->assets.LoadTexture("Play Again Button", PLAY_AGAIN_BUTTON);

		//_background.setTexture(this->_data->assets.GetTexture("game_background"));
	
		_gameOverContainer.setTexture(this->_data->assets.GetTexture("GameOver"));
		
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Again Button"));

		_gameOverContainer.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2)));
		
		_retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height - _retryButton.getGlobalBounds().height * 1.2 ));
	
		_scoreText.setFont(this->_data->assets.GetFont("IceTower Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(100);
		_scoreText.setFillColor(sf::Color::Magenta);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(sf::Vector2f((_data->window.getSize().x / 10 * 7.25) - 330, _data->window.getSize().y / 2.15));

		_bestScoreText.setFont(this->_data->assets.GetFont("IceTower Font"));
		_bestScoreText.setString(std::to_string(_bestScore));
		_bestScoreText.setCharacterSize(60);
		_bestScoreText.setFillColor(sf::Color::White);
		
			
	
	}

	void GameOverState::HandleInput()
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
				if (event.key.code == sf::Keyboard::Key::Escape)
				{
					this->_data->window.close();
				}
			
				if (event.key.code == sf::Keyboard::Key::Enter)
				{
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
			}
			
			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		//this->_data->window.clear(sf::Color::Red);

		//this->_data->window.draw(this->_background);

		
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);

		
		this->_data->window.display();
	}
}