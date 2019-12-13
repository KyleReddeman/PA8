/*****************************************************
FileName: AsteroidManager.h
Description: Used to manage the asteroids. Probably could have 
gotten rid of this class and just used AsteroidList.
Author: Kyle Reddeman
Date Created 12/7/19
Class: CptS 122
******************************************************/
#ifndef ASTEROIDMANAGER_H
#define ASTEROIDMANAGER_H

#include <SFML/Graphics.hpp>
#include "AsteroidList.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

class AsteroidManager {
private:
	AsteroidList* asteroids;
	sf::RenderWindow& window;

public:
	//sets the reference to window, and sets the random seed
	AsteroidManager(sf::RenderWindow& w): window(w) {
		asteroids = new AsteroidList(window);
		srand(time(0));
	}

	//draws the asteroids.
	void draw() {
		asteroids->draw();
	}

	//moves all of the asteroids.
	void move(float speed) {
		asteroids->move(speed);
	}

	//creates and adds an asteroid to the asteroid list.
	//gives random location size, and rotation to the asteroid.
	//spawns on edges of screen to avoid spawn killing the player.
	void addAsteroid() {
		int size = rand() % 4 + 1;
		int angle = rand() % 360;
		int xPos = rand() % 800;
		int yPos = rand() % 800;
		int side = rand() % 4;
		Bullet* asteroid = new Bullet(size, sf::Color::White);
		asteroid->setOrigin(size * 20.f, size * 20.f);
		asteroid->setRotation(angle);
		if (side == 0) {
			asteroid->setPosition(xPos, 0);
		}
		else if (side == 1) {
			asteroid->setPosition(0, yPos);
		}
		else if (side == 2) {
			asteroid->setPosition(xPos, 800);
		}
		else {
			asteroid->setPosition(800, yPos);
		}
		
		asteroids->add(asteroid);
	}

	//returns the amount of asteroids in play.
	int asteroidCount() {
		return asteroids->getSize();
	}
};





#endif
