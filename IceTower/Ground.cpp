#include "Ground.h"

#include <iostream>

namespace Sonar
{
	Ground::Ground(GameDataRef data) : _data(data)
	{

	}


	
	
	void Ground::SpawnGround1()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_1"));

		sprite.setPosition(_data->window.getSize().x / 2, 0);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnGround2()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_2"));

		sprite.setPosition((_data->window.getSize().x / 2) + 100, 0);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnGround3()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_3"));

		sprite.setPosition((_data->window.getSize().x / 2) + 199, 0);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnInvisibleGround()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_1"));

		sprite.setPosition(_data->window.getSize().x + 100, 50);

		sprite.setColor(sf::Color(0, 0, 0, 0));

		GroundSprites.push_back(sprite);

	}


	void Ground::MoveGround(float dt)
	{
		for (unsigned short int i = 0; i < GroundSprites.size(); i++)
		{
			sf::Vector2f position = GroundSprites.at(i).getPosition();
			float movement = GROUND_MOVEMENT_SPEED * dt;

			GroundSprites.at(i).move(0, movement);
		}

	}


	void Ground::DrawGround()
	{
		for (unsigned short int i = 0; i < GroundSprites.size(); i++)
		{
			_data->window.draw(GroundSprites.at(i));
		}
	}


}
