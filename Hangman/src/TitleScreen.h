#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TitleScreen {
private:
	sf::Font font;
	sf::Text title;
	sf::Text playText;
	sf::Text exitText;
	sf::SoundBuffer buffer;
	sf::Sound backgroundMusic;
public:
	TitleScreen(sf::RenderWindow& window);
};