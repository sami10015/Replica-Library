#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
	private:
		Player player1;
		Player player2;
		int playerScore1;
		int playerScore2;
	public:
		Game::Game(sf::RenderWindow&);
		void display(sf::RenderWindow&);
};