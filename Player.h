#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Damageable.h"
#include "Bullet.h"

#define PI 3.141592653

class Player: public Damageable, public sf::ConvexShape {
public:
	
	Player(int maxHealth): Damageable(maxHealth) {
		setPointCount(4);
		setPoint(0, sf::Vector2f(250.f, 0.f));
		setPoint(1, sf::Vector2f(270.f, 50.f));
		setPoint(2, sf::Vector2f(250.f, 30.f));
		setPoint(3, sf::Vector2f(230.f, 50.f));
		setFillColor(sf::Color::Green);
		setOrigin(sf::Vector2f(250.f, 25.f));
		setPosition(250.f, 250.f);
	}
	void move(float speed) {
		float angle = getRotation();
		sf::ConvexShape::move(sin(angle * PI / 180) * 1.f * speed , -cos(angle * PI / 180) * 1.f * speed);
	}

	Bullet shoot() {
		Bullet bullet(1);
		float angle = getRotation();
		bullet.setPosition(getPosition().x + sin(angle * PI / 180) * 50.f, getPosition().y + -cos(angle * PI / 180) * 50.f);
		return bullet;
	}
};
#endif
