#include <SFML/Graphics.hpp>
#include "TitleScreen.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Hello SFML", sf::Style::Fullscreen);

	//Create header file for title screen
	TitleScreen titleScreen(window);

	return 0;
}