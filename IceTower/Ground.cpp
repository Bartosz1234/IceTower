#include "Ground.h"

#include <iostream>

namespace Bartux
{
	Ground::Ground(GameDataRef data) : _data(data)
	{
		_EdgeWidth = 810;
		_groundSpawnXOffset = 0;
	}

	void Ground::RandomiseGroundOffset()
	{
		_groundSpawnXOffset = rand() % (_EdgeWidth + 1);
	}



	void Ground::SpawnGround1()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_1"));

		sprite.setPosition(_data->window.getSize().x - 450 - _groundSpawnXOffset, -100);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnGround2()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_2"));

		sprite.setPosition(_data->window.getSize().x - 350 - _groundSpawnXOffset, -100);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnGround3()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_3"));

		sprite.setPosition(_data->window.getSize().x - 251 - _groundSpawnXOffset, -100);

		GroundSprites.push_back(sprite);
	}


	void Ground::SpawnInvisibleGround()
	{
		sf::Sprite sprite(_data->assets.GetTexture("level_one_1"));

		sprite.setPosition(_data->window.getSize().x + 100, 50);

		sprite.setColor(sf::Color(0, 0, 0, 0));

		GroundSprites.push_back(sprite);

	}
	
	void Ground::SpawnScoringGround()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Koniec"));

		sprite.setPosition(_data->window.getSize().x - 1250 , -100);

		// 160, _data->window.getSize().y

		ScoringGround.push_back(sprite);

	}


	void Ground::MoveGround(float dt)
	{
		for (unsigned short int i = 0; i < GroundSprites.size(); i++)
		{
			if (GroundSprites.at(i).getPosition().y > 800 + GroundSprites.at(i).getGlobalBounds().height)
			{
				GroundSprites.erase(GroundSprites.begin() + i);

			}

			else if (_LevelClock.getElapsedTime().asSeconds() > 10.0f)
			{
				float movement = (GROUND_MOVEMENT_SPEED + 300.0f) * dt;
				

				GroundSprites.at(i).move(0.0f, movement);
			}
			else
			{
				// sf::Vector2f position = GroundSprites.at(i).getPosition();

				float movement = GROUND_MOVEMENT_SPEED * dt;

				GroundSprites.at(i).move(0.0f, movement);
			}
		}


		for (unsigned short int i = 0; i < ScoringGround.size(); i++)
		{
			if (ScoringGround.at(i).getPosition().y > 800 + ScoringGround.at(i).getGlobalBounds().height)
			{
				ScoringGround.erase(ScoringGround.begin() + i);

			}

			else if (_LevelClock.getElapsedTime().asSeconds() > 10.0f)
			{
				float movement = (GROUND_MOVEMENT_SPEED + 300.0f) * dt;


				ScoringGround.at(i).move(0.0f, movement);
			}
			else
			{
				// sf::Vector2f position = GroundSprites.at(i).getPosition();

				float movement = GROUND_MOVEMENT_SPEED * dt;

				ScoringGround.at(i).move(0.0f, movement);
			}
		}

	}


	void Ground::DrawGround()
	{
		for (unsigned short int i = 0; i < GroundSprites.size(); i++)
		{
			_data->window.draw(GroundSprites.at(i));
		}
	}

	std::vector<sf::Sprite> &Ground::GetScoringSprite()
	{
		return ScoringGround;
	}

	const std::vector<sf::Sprite> &Ground::GetSprites() const
	{
		
		return GroundSprites;

	}


}
