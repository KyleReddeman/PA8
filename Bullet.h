#ifndef BULLET_H
#define BULLET_H

#include "Damageable.h"
#include <SFML/Graphics.hpp>

class Bullet : public Damageable, public sf::CircleShape {
public:
	Bullet(int maxHealth): Damageable(maxHealth) {
		setRadius(5.f);
		setFillColor(sf::Color::Red);
	}
};
#endif
