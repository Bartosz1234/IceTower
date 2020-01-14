#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Bartux
{
typedef struct {
	int score = 0;
	int time = 0;
} record;

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

	record rekordy[5];

	int _bestScore;
};
}
