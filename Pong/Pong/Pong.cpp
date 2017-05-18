#include "Pong.h"

Pong::Pong(sf::Vector2f windowSize) {
	pongBall.setRadius(8);
	pongBall.setFillColor(sf::Color::White);
	pongBall.setOrigin(4, 4);
	pongBall.setPosition(windowSize.x / 2, windowSize.y / 2);
}

sf::CircleShape Pong::getPongBall(){
	return pongBall;
}

void Pong::move(float offsetX, float offsetY) {

}
