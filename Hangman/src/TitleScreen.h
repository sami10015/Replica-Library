#pragma once
#include <SFML/Graphics.hpp>

class TitleScreen {
private:
	sf::Font font;
	sf::Text title;
	sf::Text playText;
	sf::Text exitText;
public:
	TitleScreen(sf::RenderWindow& window);
};