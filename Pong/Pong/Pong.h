#pragma once
#include <SFML/Graphics.hpp>

class Pong {
	private:
		sf::CircleShape pongBall;
	public:
		Pong::Pong(sf::Vector2f windowSize);
		sf::CircleShape getPongBall();
		void move(float offsetX, float offsetY);
};