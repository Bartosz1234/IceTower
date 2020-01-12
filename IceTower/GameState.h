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
#include "OptionsState.h"
#include "Flash.h"
#include "OptionsF1.h"

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
		

		Ground *ground;

		Spawner *spawner;

		
		Edge1 *edge;

		Mate *mate;

		Ending *ending;

		Collisions collisions;

		Flash *flash;

		OptionsState *optionsstate;

		OptionsF1 *optionsF1;

		sf::Clock clock;
		sf::Clock LevelClock;
		
		int _gameState;
	};
}
