#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Bartux
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		//sf::Sprite _background;

		
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

		sf::Text _scoreText;
		sf::Text _bestScoreText;

		int _score;
		int _bestScore;
	};
}