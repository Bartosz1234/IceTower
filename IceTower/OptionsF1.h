#pragma once

#include <SFML/Graphics.hpp>	
#include "Game.h"
#include "DEFINITIONS.h"
#include "State.h"



namespace Sonar {

	class OptionsF1 : public State
	{
	public:
		OptionsF1(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;


	};
}