#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"
#include "DEFINITIONS.h"

int main()
{
	Sonar::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");

	return EXIT_SUCCESS;
}