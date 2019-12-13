#ifndef BULLET_H
#define BULLET_H

#include "Damageable.h"
#include <SFML/Graphics.hpp>

class Bullet : public Damageable, public sf::CircleShape {
public:
	Bullet() {
		Damageable(1);
		Bullet(.25f, sf::Color::Red);
	}
	Bullet(float size, sf::Color color) {
		setRadius(20.f * size);
		setFillColor(color);
	}
	~Bullet() {

	}

};
#endif
