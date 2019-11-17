#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"
#include "State.h"

namespace Sonar
{
class SplashState:public State
{
public:
	SplashState(GameDataRef data);	
	~SplashState();

	void Init();
	
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	GameDataRef _data;

	sf::Clock _clock;
	sf::Texture _backgroundTExture;
	sf::Sprite _background;
};
}


