#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Definitions.h"

namespace Bartux
{
	class Edge1
	{
	public:
		Edge1(GameDataRef data);

		void SpawnEdgeLeft();
		
		
		void SpawnEdgeRight();
		
		
		
		void DrawEdge();

		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> EdgeSprites;
	};

}