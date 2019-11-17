#include "nowa_gra.h"



nowa_gra::nowa_gra(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	for (int i = 0; i < ILOSC_POZYCJI_NOWA_GRA; i++)
	{

		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::Cyan);
		menu[i].setPosition(sf::Vector2f(width / 3, height / (ILOSC_POZYCJI_NOWA_GRA + 1) * (i + 1)));

	}
	int q = 0;
	menu[q++].setString("Stwórz gre");
	menu[q++].setString("Zmien postaæ");
	menu[q++].setString("Powrót");
	menu[0].setFillColor(sf::Color::Magenta);

}

void nowa_gra::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < ILOSC_POZYCJI_NOWA_GRA; i++)
	{
		window.draw(menu[i]);
	}
}


void nowa_gra::moveUp()
{
	if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_NOWA_GRA)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = ILOSC_POZYCJI_NOWA_GRA - 1;
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}


}

void nowa_gra::moveDown()
{
	if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_NOWA_GRA)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= ILOSC_POZYCJI_NOWA_GRA)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}

}