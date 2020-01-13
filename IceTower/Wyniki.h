#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Bartux
{

class Wyniki : public State
{

public:
	Wyniki(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	
private:
	GameDataRef _data;

	sf::Sprite Wynik_background;


	sf::Sprite Score_List;
	

	sf::Text _scoreText;
	sf::Text _bestScoreText;

	int _score;
	int _bestScore;
};

}
