#ifndef ASTEROIDMANAGER_H
#define ASTEROIDMANAGER_H

#include <SFML/Graphics.hpp>
//#include "Bullet.h"
#include "AsteroidList.h"
#include <time.h>
#include <stdlib.h>

using namespace std;



class AsteroidManager {
private:
	AsteroidList* asteroids;
	sf::RenderWindow& window;

public:
	AsteroidManager(sf::RenderWindow& w): window(w) {
		asteroids = new AsteroidList(window);
		srand(time(0));
	}

	void draw() {
		asteroids->draw();
	}

	void move(float speed) {
		asteroids->move(speed);
	}

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
};





#endif
