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

		void SpawnScoringGround();

		void MoveGround(float dt);
		void DrawGround();
		void RandomiseGroundOffset();

		std::vector<sf::Sprite> &GetScoringSprite();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> GroundSprites;
		std::vector<sf::Sprite> ScoringGround;

		int _EdgeWidth;
		int _groundSpawnXOffset;
		sf::Clock _clock;
		sf::Clock _LevelClock;
	};



}