#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Definitions.h"

namespace Sonar
{
	class Edge1
	{
	public:
		Edge1(GameDataRef data);

		void SpawnEdgeLeft();
		void SpawnEdgeRight();
		

		void DrawEdge();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> EdgeSprites;
	};

}