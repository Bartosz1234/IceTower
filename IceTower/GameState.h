#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Ground.h"
#include "DEFINITIONS.h"

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
	};
}
