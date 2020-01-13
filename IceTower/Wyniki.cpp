#include "Wyniki.h"
#include "MainMenuState.h"
#include <fstream>
#include "DEFINITIONS.h"
#include <iostream>

namespace Sonar
{

	Wyniki::Wyniki(GameDataRef data) : _data(data)
	{

	}


	void Wyniki::Init()
	{
		std::ifstream readFile;
		readFile.open("Wyniczki.txt");


		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _bestScore;
				readFile >> _score;
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

			writeFile << _bestScore;
		}

		writeFile.close();

		this->_data->assets.LoadFont("IceTower Font", ICETWOER_FONT);

		this->_data->assets.LoadTexture("Wyniki_background", WYNIKI_BACKGROUND_FIEPATH);
		Wynik_background.setTexture(this->_data->assets.GetTexture("Wyniki_background"));



		_scoreText.setFont(this->_data->assets.GetFont("IceTower Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(100);
		_scoreText.setFillColor(sf::Color::Magenta);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(sf::Vector2f((_data->window.getSize().x / 10 * 7.25) - 650, (_data->window.getSize().y / 2.15) - 140));

		_bestScoreText.setFont(this->_data->assets.GetFont("IceTower Font"));
		_bestScoreText.setString(std::to_string(_bestScore));
		_bestScoreText.setCharacterSize(100);
		_bestScoreText.setFillColor(sf::Color::Black);
		_bestScoreText.setOrigin(sf::Vector2f(_bestScoreText.getGlobalBounds().width / 2, _bestScoreText.getGlobalBounds().height / 2));
		_bestScoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, (_data->window.getSize().y / 1.78) - 200));

	}

	void Wyniki::HandleInput()
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
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
			}

			
		}
	}


	void Wyniki::Update(float dt)
	{

	}

	void Wyniki::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->Wynik_background);

		_data->window.draw(_scoreText);
		_data->window.draw(_bestScoreText);

		this->_data->window.display();
	}

}
