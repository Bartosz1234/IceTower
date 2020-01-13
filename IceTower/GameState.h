#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Ground.h"
#include "Spawner.h"
#include "Edge1.h"
#include "DEFINITIONS.h"
#include "Mate.h"
#include "Ending.h"
#include "Collisions.h"

#include "Flash.h"

#include "Score.h"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void moveUp();
		void moveDown();

	private:
		GameDataRef _data;
		
		sf::Sprite _background;
		
		sf::Sprite _EscWindow;
		sf::Sprite _NoButton;
		sf::Sprite _YesButton;

		sf::Sprite _OptionsWindow;

		// sf::Sprite _backgroundOptions;

		Ground *ground;

		Spawner *spawner;

		
		Edge1 *edge;

		Mate *mate;

		Ending *ending;

		Collisions collisions;

		Flash *flash;

		

		

		Score *score;

		sf::Clock clock;
		sf::Clock LevelClock;

		sf::Clock EscClock;

		sf::Clock SpawnerClock;
		
		int _gameState;

		int _score;
	};
}
