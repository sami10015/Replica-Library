#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
	private:
		Player player1;
		Player player2;

		sf::RectangleShape border;

		int playerScore1;
		int playerScore2;

		sf::Font font;
		sf::Text playerText1;
		sf::Text playerText2;
	public:
		Game::Game(sf::RenderWindow&);
		void display(sf::RenderWindow&);
};