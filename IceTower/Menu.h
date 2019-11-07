#pragma once
#include <SFML/Graphics.hpp>

#define ILOSC_POZYCJI_MENU 4


class Menu
{

private:
	sf::Font font;
	sf::Text menu[ILOSC_POZYCJI_MENU];//maksymalna liczba poziomow
	int selectedItem = 0;


public:
	Menu(float width, float height);
	~Menu() {};
	void moveUp();//przesun do gory
	void moveDown();//przesun w dol
	void draw(sf::RenderWindow &window);//rysuj menu w oknie
	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
};

