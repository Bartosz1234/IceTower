#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

#define ILOSC_POZYCJI_MENU 4

namespace Sonar
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void moveUp();
		void moveDown();

		int getSelectedItem() { return selectedItem; }
	private:
		GameDataRef _data;
		
		sf::Sprite _background;
		sf::Sprite _playButton;
		sf::Text menu[ILOSC_POZYCJI_MENU];//maksymalna liczba poziomow
		int selectedItem = 0;
		sf::Font font;
	};
}


