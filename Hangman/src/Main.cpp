#include <SFML/Graphics.hpp>
#include "TitleScreen.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Hello SFML", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(false);

	//Prompt titleScreen, which starts the game
	TitleScreen titleScreen(window);

	return 0;
}