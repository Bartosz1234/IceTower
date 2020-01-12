#include "Ending.h"
#include "DEFINITIONS.h"

#include <iostream>

#include <vector>


namespace Sonar
{
	Ending::Ending(GameDataRef data) : _data(data)
	{

	}


	

	void Ending::End()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Koniec"));

		sprite.setPosition(0, 877);

		endingSprites.push_back(sprite);
	}




	void Ending::DrawEnding()
	{
		
		for (unsigned short int i = 0; i < endingSprites.size(); i++)
		{
			_data->window.draw(endingSprites.at(i));

		}
	}

	const std::vector<sf::Sprite> &Ending::GetSprites() const
	{
		return endingSprites;
	}
}