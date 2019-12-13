/*****************************************************
FileName: Bullet.h
Description: Projectile would have been a better name.
Used as asteroids, and players projectile.
Author: Kyle Reddeman
Date Created 12/7/19
Class: CptS 122
******************************************************/
#ifndef BULLET_H
#define BULLET_H

#include "Damageable.h"
#include <SFML/Graphics.hpp>

class Bullet : public Damageable, public sf::CircleShape {
public:
	//default constructor creates a bullet that would be shot by the player
	Bullet() {
		Damageable(1);
		Bullet(.25f, sf::Color::Red);
	}
	//creates a bullet with a radius with a factor of size, and sets the color to the specified color.
	Bullet(float size, sf::Color color) {
		setRadius(20.f * size);
		setFillColor(color);
	}
};
#endif
