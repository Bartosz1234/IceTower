#include "Score.h"

#include <string>

namespace Sonar
{
	Score::Score(GameDataRef data) : _data(data)
	{
		_scoreText.setFont(this->_data->assets.GetFont("IceTower Font"));

		_scoreText.setString("0");

		_scoreText.setCharacterSize(128);

		_scoreText.setFillColor(sf::Color::Magenta);

		_scoreText.setOrigin(sf::Vector2f(100, 50));

		_scoreText.setPosition(sf::Vector2f(100, 50));
	}



	void Score::Draw()
	{
		_data->window.draw(_scoreText);
	}

	void Score::UpdateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	}
}