#pragma once
#include "SplashState.h"
#include <sstream>
#include "SplashState.h"
#include "Definitions.h"

#include <iostream>



SplashState::SplashState(GameDataRef data)
{
}


SplashState::~SplashState()
{
}

void SplashState::Init() {
	sf::Texture texture;
	if (!texture.loadFromFile("splash state.jpg", sf::IntRect(10, 10, 32, 32)))
	{
		// error...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
}
void SplashState::HandleInput() {
	sf::Event event;
	while (_data->window.pollEvent (event))
}
	// window.draw(sprite);