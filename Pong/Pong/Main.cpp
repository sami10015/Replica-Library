#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong works!");

	//Render Text with Font
	sf::Font font;
	if (!font.loadFromFile("Fonts/BlindSignature.ttf")) {
		cout << "Failed to load font";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("PONG");
	text.setCharacterSize(72);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Underlined);
	text.setPosition(sf::Vector2f(window.getSize().x*.5, window.getSize().y * .25));


	// Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(text);

		window.display();
	}

	return 0;
}