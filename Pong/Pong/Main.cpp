#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

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

	//Title Screen Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(titleText);
		window.draw(playText);
		window.draw(quitText);

		window.display();
	}

	return 0;
}