/*****************************************************
FileName: Player.h
Description: Controlls the main player.
Author: Kyle Reddeman
Date Created 12/7/19
Class: CptS 122
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Damageable.h"
#include "Bullet.h"

#define PI 3.141592653

class Player: public Damageable, public sf::ConvexShape {
public:
	//creates a player with the given amount of max health.
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
	//moves the player at the given speed.
	//if player moves out of bounds they will transport to opposite side.
	void move(float speed) {
		float angle = getRotation();
		sf::ConvexShape::move(sin(angle * PI / 180) * 1.f * speed , -cos(angle * PI / 180) * 1.f * speed);
		int xPos =getPosition().x;
		int yPos = getPosition().y;
		if (xPos > 815) {
			setPosition(0, yPos);
		}
		if (xPos < -15) {
			setPosition(800, yPos);
		}
		if (yPos > 815) {
			setPosition(xPos, 0);
		}
		if (yPos < -15) {
			setPosition(xPos, 800);
		}
	}

	//creates and shoots a bullet.
	Bullet* shoot() {
		Bullet* bullet = new Bullet(.25, sf::Color::Red);
		float angle = getRotation() - 6;
		bullet->setPosition(getPosition().x + sin(angle * PI / 180) * 44.f, getPosition().y + -cos(angle * PI / 180) * 44.f);
		bullet->setRotation(getRotation());
		return bullet;
	}
};
#endif
