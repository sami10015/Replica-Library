#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//Constructor
Player::Player() {
	sf::Texture spriteTexture;
	if (!spriteTexture.loadFromFile("Pong.png", sf::IntRect(32, 103, 4, 14))) {
		cout << "Failed to load pong sprite sheet";
	}
	playerSprite.setTexture(spriteTexture);
}

sf::Sprite Player::getSprite() {
	return playerSprite;
}

void Player::setPosition(sf::Vector2f position) {
	playerPosition = position;
	playerSprite.setPosition(playerPosition);
}

sf::Vector2f Player::getPosition() {
	return playerPosition;
}