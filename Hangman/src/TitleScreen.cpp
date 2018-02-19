#include "TitleScreen.h"
#include <iostream>

TitleScreen::TitleScreen(sf::RenderWindow & window){
	if (!buffer.loadFromFile("Sounds/Background.ogg")) {
		std::cout << "Something went wrong" << std::endl;
	}
	backgroundMusic.setBuffer(buffer);
	backgroundMusic.play();

	font.loadFromFile("Fonts/Pacifico.ttf");
	//Title text set up
	title.setFont(font);
	title.setCharacterSize(60);
	title.setString("Hangman");
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
	title.setPosition(window.getSize().x * .5, window.getSize().y * .4);

	//Play text set up
	playText.setFont(font);
	playText.setCharacterSize(50);
	playText.setString("Play");
	playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
	playText.setPosition(window.getSize().x * .5, window.getSize().y * .75);

	//Play text alpha set up
	int playAlpha = 255;
	playText.setFillColor(sf::Color(255, 255, 255, playAlpha));

	//Exit text set up
	exitText.setFont(font);
	exitText.setCharacterSize(50);
	exitText.setString("Exit");
	exitText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
	exitText.setPosition(window.getSize().x * .5, window.getSize().y * .85);
	
	//Exit text alpha set up
	int exitAlpha = 255;
	exitText.setFillColor(sf::Color(255, 255, 255, exitAlpha));

	//Integer indicated which field is selected
	int playerSelection = 0;
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
						if (playerSelection == 0) {
							playerSelection = 1;
							playAlpha = 255;
							playText.setFillColor(sf::Color(255, 255, 255, playAlpha));
						}
					} else if (event.key.code == sf::Keyboard::Up) {
						if (playerSelection == 1) {
							playerSelection = 0;
							exitAlpha = 255;
							exitText.setFillColor(sf::Color(255, 255, 255, exitAlpha));
						}
					} else if (event.key.code == sf::Keyboard::Return) {
						if (playerSelection == 0) {
							//TODO: Start Game
						} else {
							window.close();
						}
					} else if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
				default:
					break;
			}
		}

		//Fade in and out play text
		if (playerSelection == 0) {
			if (playAlpha < 0) {
				playAlpha = 255;
			}
			playText.setFillColor(sf::Color(255, 255, 255, playAlpha));
			playAlpha -= 8;
		} else if(playerSelection == 1){ //Fade in and out exit text
			if (exitAlpha < 0) {
				exitAlpha = 255;
			}
			exitText.setFillColor(sf::Color(255, 255, 255, exitAlpha));
			exitAlpha -= 8;
		}
		window.clear();
		window.draw(title);
		window.draw(playText);
		window.draw(exitText);
		window.display();
	}
}
