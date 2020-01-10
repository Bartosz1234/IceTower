#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Definitions.h"

namespace Sonar
{
	class Ground
	{
	public:
		Ground(GameDataRef data);


		void SpawnGround1();
		void SpawnGround2();
		void SpawnGround3();
		void SpawnInvisibleGround();
		void MoveGround(float dt);
		void DrawGround();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> GroundSprites;
	};



}