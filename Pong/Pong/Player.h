#pragma once
#include <SFML/Graphics.hpp>

class Player {
	private:
		sf::Sprite playerSprite;
		sf::Vector2f playerPosition;
	public:
		sf::Vector2f getPosition();
		sf::Sprite getSprite();
		void setPosition(sf::Vector2f position);
};