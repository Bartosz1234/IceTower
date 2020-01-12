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

		sf::Clock clock;
		int _gameState;
		
	};
}
