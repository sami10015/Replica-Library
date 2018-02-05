#include "TitleScreen.h"

TitleScreen::TitleScreen(sf::RenderWindow & window){
	font.loadFromFile("Fonts/Pacifico.ttf");
	title.setFont(font);
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
	title.setPosition(window.getSize().x * .4 , window.getSize().y * .4);
	title.setCharacterSize(60);
	title.setString("Hangman");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
				//Window closed
				case sf::Event::Closed:
					window.close();
					break;
				//Key pressed
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Down) {
						//TODO: Indicate which option is selected
					}
					else if (event.key.code == sf::Keyboard::Up) {
						//TODO: Indicate which option is selected
					}
					else if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
				default:
					break;
			}
		}
		window.clear();
		window.draw(title);
		window.display();
	}
}
