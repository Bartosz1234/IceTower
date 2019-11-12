#pragma once
#include <SFML/Graphics.hpp>

#define ILOSC_POZYCJI_NOWA_GRA 4
class nowa_gra
{
private:
	sf::Font font;
	sf::Text menu[ILOSC_POZYCJI_NOWA_GRA];
	int selectedItem = 0;

public:
	nowa_gra(float width, float height);
	~nowa_gra() {};
	void moveUp();
	void moveDown();
	void draw(sf::RenderWindow &window); //  W innym oknie? Tym nastepnym
	int getSelectedItem() { return selectedItem; }
};

