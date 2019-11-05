#pragma once
#include <SFML/Graphics.hpp>

#define MAX_LICZBA_POZIOMOW 4


class Menu
{

private:
	sf::Font font;
	sf::Text menu[MAX_LICZBA_POZIOMOW];//maksymalna liczba poziomow
	int selectedItem = 0;


public:
	Menu(float width, float height);
	~Menu() {};
	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	void draw(sf::RenderWindow &window);//rysuj menu w oknie
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
};

