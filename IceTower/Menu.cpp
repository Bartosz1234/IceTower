#include "Menu.h"

Menu::Menu(float width, float height)
{	//laduj czcionke
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	
	

	//rysowanie elementow menu
	
	for (int i = 0; i < ILOSC_POZYCJI_MENU; i++)
	{
	
	menu[i].setFont(font);
	menu[i].setFillColor(sf::Color::White);
	menu[i].setPosition(sf::Vector2f(width / 2, height / (ILOSC_POZYCJI_MENU + 1) * (i+1)));
	
	}
	int q = 0;
	menu[q++].setString("Nowa gra");
	menu[q++].setString("Wyniki");
	menu[q++].setString("Opcje");
	menu[q++].setString("Wyjscie");
	menu[0].setFillColor(sf::Color::Magenta);
}



//rysowanie menu w biezacym oknie
void Menu::draw(sf::RenderWindow &window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("Ice Tower grafika.jpg", sf::IntRect(0, 0, 1420, 800)))
	{
		// error...
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.draw(sprite);
	for (int i = 0; i < ILOSC_POZYCJI_MENU; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::moveUp()
{
	if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_MENU)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = ILOSC_POZYCJI_MENU - 1;
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}


}

void Menu::moveDown()
{
	if (selectedItem >= 0 && selectedItem < ILOSC_POZYCJI_MENU)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= ILOSC_POZYCJI_MENU)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}

}


