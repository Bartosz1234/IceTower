#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Definitions.h"

namespace Sonar
{
	class Ending
	{
	public:
		Ending(GameDataRef data);

		
		void End();

		void DrawEnding();
	
		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;
		
		std::vector<sf::Sprite> endingSprites;
	};

}