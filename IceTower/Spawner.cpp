#include "Spawner.h"

#include <iostream>

namespace Bartux
{
	Spawner::Spawner(GameDataRef data) : _data(data)
	{

	}


	void Spawner::Spawner1()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_1"));

		sprite.setPosition(_data->window.getSize().x / 9, 700);

		SpawnerSprites.push_back(sprite);
	}

	void Spawner::Spawner2()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_2"));

		sprite.setPosition((_data->window.getSize().x / 9) + 100, 700);

		SpawnerSprites.push_back(sprite);
	}

	void Spawner::Spawner3()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_3"));

		sprite.setPosition((_data->window.getSize().x / 9) + 199, 700);

		SpawnerSprites.push_back(sprite);
	}
	
	

	void Spawner::Update(float dt)
	{
		for (unsigned short int i = 0; i < SpawnerSprites.size(); i++)
		{
			
			if (SpawnerSprites.at(i).getPosition().y > 400)
			{
				SpawnerSprites.erase(SpawnerSprites.begin() + i);

			}
		}

	}
	

	void Spawner::DrawSpawner()
	{
		for (unsigned short int i = 0; i < SpawnerSprites.size(); i++)
		{
			_data->window.draw(SpawnerSprites.at(i));
			
		}
		
		
	}


}
