#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"
#include "DEFINITIONS.h"

int main()
{
	Bartux::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Kaszubek Tower");

	return EXIT_SUCCESS;
}