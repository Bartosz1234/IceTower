#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
class Menu_main
{
public:
	sf::Font font;
	void Draw(sf::RenderWindow &window) {
		sf::Text text;

		// select the font
		text.setFont(font); // font is a sf::Font

		// set the string to display
		text.setString("Nowa gra111");

		// set the character size
		text.setCharacterSize(24); // in pixels, not points!

		// set the color
		text.setFillColor(sf::Color::Red);

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		// inside the main loop, between window.clear() and window.display()
		window.draw(text);
	}
	Menu_main();
	~Menu_main();
	
};



Menu_main::Menu_main()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
		std::cout << "blad cionki";
	}

}


Menu_main::~Menu_main()
{
}
