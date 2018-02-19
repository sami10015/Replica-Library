#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameScreen {
private:
	sf::Font font;
	sf::Text pressLetterText;
	sf::SoundBuffer buffer;
	sf::Sound backgroundMusic;
public:
	GameScreen(sf::RenderWindow& window);
};