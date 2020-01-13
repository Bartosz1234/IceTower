#include "Edge1.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace Bartux
{
	Edge1::Edge1(GameDataRef data) : _data(data)
	{
		
	}


	void Edge1::SpawnEdgeLeft()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Edge"));

		sprite.setPosition(0, 0);

		EdgeSprites.push_back(sprite);
	}
	
	

	void Edge1::SpawnEdgeRight()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Edge"));

		sprite.setPosition(_data->window.getSize().x - sprite.getGlobalBounds().width, 0);

		EdgeSprites.push_back(sprite);
	}
	
	
	

	void Edge1::DrawEdge()
	{
		for (unsigned short int i = 0; i < EdgeSprites.size(); i++)
		{
			_data->window.draw(EdgeSprites.at(i));
		}
	}



	const std::vector<sf::Sprite> &Edge1::GetSprites() const
	{
		return EdgeSprites;
	}
}