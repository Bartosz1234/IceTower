#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>


namespace Bartux
{


	class Mate
	{
	public:
		Mate(GameDataRef data);
		
		void Draw();


		void Update(float dt);

		void Click();
		void move(float a, float b);

		void Right();
		void Left();
		void Jump();

		const sf::Sprite &GetSprite() const;
	private:
		GameDataRef _data;

		sf::Sprite _mateSprite;
		
		

		sf::Clock _clock;

		sf::Clock _movementClock;

		int _mateState;
	};

}
