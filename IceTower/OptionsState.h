#pragma once

#include <SFML/Graphics.hpp>	
#include "MainMenuState.h"
#include "Game.h"
#include "DEFINITIONS.h"
#include "State.h"


namespace Sonar {

	class OptionsState : public State
	{
	public:
		OptionsState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;


	};
}