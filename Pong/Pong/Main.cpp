#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include <iostream>

using namespace std;

int main(){
	//Create Window
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes().front(), "Pong", sf::Style::Fullscreen);

	//Render Title Text with Font in the middle of the screen
	sf::Font font;
	if (!font.loadFromFile("Fonts/BlindSignature.ttf")) {
		cout << "Failed to load font";
	}
	sf::Text titleText;
	titleText.setFont(font);
	titleText.setString("PONG");
	titleText.setCharacterSize(72);
	titleText.setFillColor(sf::Color::White);
	titleText.setOrigin(sf::Vector2f(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2));
	titleText.setPosition(sf::Vector2f(window.getSize().x*.5, window.getSize().y * .25));

	//Render the rest of the text below the title
	sf::Text playText;
	playText.setFont(font);
	playText.setString("PLAY");
	playText.setCharacterSize(36);
	playText.setFillColor(sf::Color::White);
	playText.setOrigin(sf::Vector2f(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2));
	playText.setPosition(sf::Vector2f(window.getSize().x*.5, window.getSize().y * .7));
	playText.setStyle(sf::Text::Underlined);
	sf::Text quitText;
	quitText.setFont(font);
	quitText.setString("QUIT");
	quitText.setCharacterSize(36);
	quitText.setFillColor(sf::Color::White);
	quitText.setOrigin(sf::Vector2f(quitText.getLocalBounds().width / 2, quitText.getLocalBounds().height / 2));
	quitText.setPosition(sf::Vector2f(window.getSize().x*.5, window.getSize().y * .85));

	//Load background music
	sf::Music backgroundMusic;
	if (!backgroundMusic.openFromFile("Sounds/Background.ogg")) {
		cout << "Failed to load background music";
	}
	backgroundMusic.setVolume(10);
	backgroundMusic.play();
	backgroundMusic.setLoop(true);

	//Load selection sound and soundbuffer combo
	sf::Sound selectSound;
	sf::SoundBuffer selectSoundBuffer;
	if (!selectSoundBuffer.loadFromFile("Sounds/Select.wav")) {
		cout << "Failed to load selection sound";
	}
	selectSound.setBuffer(selectSoundBuffer);
	selectSound.setVolume(30);

	//Variable to check which option is selected on the keyboard
	bool playSelected = true;

	//Variable to check if the user selected play or not
	bool startGame = false;

	Player player1;
	player1.setPosition(sf::Vector2f(0, window.getSize().y / 2));

	//Title Screen Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
				//Closes the window if the x button is clicked
				case sf::Event::Closed:
					window.close();
					break;
				//Checks which keys are pressed on the keyboards and acts accordingly
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Up && playSelected == false) {
						playText.setStyle(sf::Text::Underlined);
						quitText.setStyle(sf::Text::Regular);
						selectSound.play();
						playSelected = true;
					}
					if (event.key.code == sf::Keyboard::Down && playSelected == true) {
						playText.setStyle(sf::Text::Regular);
						quitText.setStyle(sf::Text::Underlined);
						selectSound.play();
						playSelected = false;
					}
					if (event.key.code == sf::Keyboard::Return) {
						if (playSelected) {
							selectSound.play();
							startGame = true;
							break;
						}
						else {
							selectSound.play();
							window.close();
							break;
						}
					}
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
						break;
					}
				//Mouse click functionality
				case sf::Event::MouseButtonPressed:
					if (event.key.code == sf::Mouse::Left) {
						//User clicking quit
						if (quitText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
							selectSound.play();
							window.close();
						} 
						//User clicking play
						else if (playText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
							selectSound.play();
							startGame = true;
							break;
						}
					}
				default:
					break;
			}
		}
		window.clear();

		window.draw(player1.getSprite());
		window.draw(titleText);
		window.draw(playText);
		window.draw(quitText);

		window.display();
	}

	if (startGame == true) {
		//Send window to game object
		return 0;
	}
	else {
		return 0;
	}
}