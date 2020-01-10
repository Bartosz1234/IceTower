#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Definitions.h"

namespace Sonar
{
	class Spawner
	{
	public:
		Spawner(GameDataRef data);

		void Spawner1();
		void Spawner2();
		void Spawner3();

		
		void DrawSpawner();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> SpawnerSprites;
	};

}