#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"




namespace Bartux
{
	class Score
	{
	public:
		Score(GameDataRef data);
		

		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;

		

		sf::Text _scoreText;

	};
}

