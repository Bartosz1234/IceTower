#pragma once
#include <SFML/Graphics.hpp>




class gwiazda
{
private:
	sf::Vector2f position;
	double xVel = 1;
	double yVel = 1;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	float x_in;
	float y_in;
	sf::Vector2f rozmiar_okna;

public:
	gwiazda(float x_in, float y_in, float szerokosc, float wysokosc)
	{
		position.x = x_in;
		position.y = y_in;
		rozmiar_okna.x = szerokosc;
		rozmiar_okna.y = wysokosc;
		tekstura.loadFromFile("pokeball.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
	}

	void przesun(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.x = x_in;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();
	}

	void sprawdzKolizjeSciany()
	{

		if (position.x <= 0)
			xVel = -xVel;
		if (position.x >= rozmiar_okna.x)
			xVel = -xVel;
		if (position.y <= 0)
			yVel = -yVel;
		if (position.y >= rozmiar_okna.y)
			yVel = -yVel;



	}
	void animuj()
	{
		sprawdzKolizjeSciany();
		przesun(xVel, yVel);
	}

	sf::Sprite getPokeball()
	{
		return pSprite;
	}

	double zmienPredkosc(double Vxnew, double Vynew)
	{
		xVel += Vxnew;
		yVel += Vynew;
		return xVel, yVel;
	}

	


};

