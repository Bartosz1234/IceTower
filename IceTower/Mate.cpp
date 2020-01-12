#include "Mate.h"


namespace Sonar
{

	Mate::Mate(GameDataRef data) : _data(data)
	{
		



		_mateSprite.setTexture(_data->assets.GetTexture("Stoi"));

		_mateSprite.setPosition((_data->window.getSize().x / 9) + 150, 624);
		_mateState = MATE_STATE_STILL;
	}

	void Mate::Draw()
	{
		_data->window.draw(_mateSprite);

	}

	

	void Mate::Update(float dt)
	{

		
		if (MATE_STATE_FALLING == _mateState)
		{
			_mateSprite.move(0, GRAVITY * dt);
			
			
		}
		else if (MATE_STATE_JUMPING == _mateState)
		{
			_mateSprite.move(0, -JUMPING_SPEED * dt);
			
			
		}

		if (_movementClock.getElapsedTime().asSeconds() > JUMPING_DURATION)
		{
			_movementClock.restart();
			_mateState = MATE_STATE_FALLING;
			_mateSprite.setTexture(_data->assets.GetTexture("Stoi"));
		}
	}

	void Mate::move(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		_mateSprite.move(pos);
	}
	void Mate::Click()
	{
		_movementClock.restart();
		_mateState = MATE_STATE_JUMPING;
	}

	void Mate::Right()
	{
		_mateSprite.setTexture(_data->assets.GetTexture("Prawo"));
	}
	
	void Mate::Left()
	{
		_mateSprite.setTexture(_data->assets.GetTexture("Lewo"));
	}
	
	void Mate::Jump()
	{
		_mateSprite.setTexture(_data->assets.GetTexture("Skok"));
	}

	const sf::Sprite &Mate::GetSprite() const
	{
		return _mateSprite;
	}

}
