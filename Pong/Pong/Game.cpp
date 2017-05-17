#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"

using namespace std;

Game::Game(sf::RenderWindow& window) {
	player1.setPosition(sf::Vector2f(0, window.getSize().y / 2));
	//This insanely long line of code makes sure that the player2 pong board is in middle of the right hand side of the window
	player2.setPosition(sf::Vector2f(window.getSize().x - player2.getSprite().getGlobalBounds().width, window.getSize().y / 2));

	//Set the border in the middle of the screen
	border.setSize(sf::Vector2f(10, window.getSize().y));
	border.setOrigin(sf::Vector2f(border.getLocalBounds().width / 2, 0));
	border.setPosition(sf::Vector2f(window.getSize().x / 2, 0));

	playerScore1 = 0;
	playerScore2 = 0;

	if (!font.loadFromFile("Fonts/BlindSignature.ttf")) {
		cout << "Could not load font";
	}
	playerText1.setFont(font);
	playerText2.setFont(font);

	playerText1.setString("PLAYER 1" + playerScore1);
	playerText1.setCharacterSize(36);
	playerText1.setFillColor(sf::Color::White);
	playerText1.setOrigin(sf::Vector2f(0, 0));
	playerText1.setPosition(sf::Vector2f(0, 0));

	playerText2.setString("PLAYER 2" + playerScore1);
	playerText2.setCharacterSize(36);
	playerText2.setFillColor(sf::Color::White);
	playerText2.setOrigin(sf::Vector2f(playerText2.getLocalBounds().width, 0));
	playerText2.setPosition(sf::Vector2f(window.getSize().x, 0));
}

void Game::display(sf::RenderWindow& window) {
	window.clear();
	int SPRITE_SPEED = 2;

	//Flags for key pressing
	bool upFlag = false;
	bool downFlag = false;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//If a key is pressed
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						window.close();
					case sf::Keyboard::W:
						upFlag = true;
						break;
					case sf::Keyboard::S:
						downFlag = true;
						break;
					default:
						break;
				}
			}
			
			//If a key is released
			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
					case sf::Keyboard::W:
						upFlag = false;
						break;
					case sf::Keyboard::S:
						downFlag = false;
						break;
				}
			}
		}

		if (upFlag) {
			int x = player1.getPosition().x;
			int y = player1.getPosition().y;
			player1.setPosition(sf::Vector2f(x, y + SPRITE_SPEED));
		}
		else if (downFlag) {
			int x = player1.getPosition().x;
			int y = player1.getPosition().y;
			player1.setPosition(sf::Vector2f(x, y - SPRITE_SPEED));
		}

		window.clear();

		window.draw(player1.getSprite());
		window.draw(player2.getSprite());
		window.draw(border);
		window.draw(playerText1);
		window.draw(playerText2);

		window.display();
	}
	return;
}
