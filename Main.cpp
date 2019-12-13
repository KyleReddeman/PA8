/*****************************************************
FileName: Main.cpp
Description: The .cpp file with the int main() function.
Author: Kyle Reddeman
Date Created 12/7/19
Class: CptS 122
******************************************************/
#include <string>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "AsteroidManager.h"

using namespace std;
#define PI 3.141592653

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Asteroids!", sf::Style::Default, settings);
	sf::Font font;
	if (!font.loadFromFile("calibri.ttf")) {
		cout << "Error loading font\n";
	}
	//set up fps counter
	sf::Text fpsCount;
	fpsCount.setFont(font);
	fpsCount.setCharacterSize(14);
	sf::Clock clock;

	//drawable things
	Player player(3);
	Bullet* bullets[5];
	AsteroidManager* asteroidManager = new AsteroidManager(window);
	sf::Clock spawnTimer;

	for (int i = 0; i < 5; i++) {
		bullets[i] = NULL;
	}
	bool isPressed = false;

	clock.restart();
	spawnTimer.restart();
	
	while (window.isOpen()) {
		//spawn asteroids
		if (spawnTimer.getElapsedTime().asSeconds() > 1 && asteroidManager->asteroidCount() < 15) {
			asteroidManager->addAsteroid();
			spawnTimer.restart();
		}
		sf::Time deltaT = clock.getElapsedTime();
		clock.restart();//set fps counter.
		fpsCount.setString("FPS:" + to_string((int)(1 / deltaT.asSeconds())));
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//float angle = 0.f;
		float speed = 240.f;
		//move foward
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player.move(speed * deltaT.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.rotate(-speed * .8f * deltaT.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player.rotate(speed * .8f * deltaT.asSeconds());
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (!isPressed) {
				for (int i = 0; i < 5; i++) {
					if (bullets[i] == NULL) {
 						bullets[i] = player.shoot();
						break;
					}
				}
			}
			isPressed = true;
		}
		else {
			isPressed = false;
		}



		window.clear(sf::Color::Black);
		window.draw(fpsCount);
		window.draw(player);
		asteroidManager->move(.75f * speed * deltaT.asSeconds());
		asteroidManager->draw();
		//draw/move bullets. Asteroids used better solution
		for (int i = 0; i < 5; i++) {
			if (bullets[i] != NULL) {
				float angle = bullets[i]->getRotation();
				bullets[i]->move(sin(angle * PI / 180) * 1.f * speed * deltaT.asSeconds(), -cos(angle * PI / 180) * 1.f * speed * deltaT.asSeconds());
				if (bullets[i]->getPosition().x > 810 || bullets[i]->getPosition().y > 810 || bullets[i]->getPosition().x < -10 || bullets[i]->getPosition().y < -10) {
					bullets[i]->damage();
				}
				window.draw(*bullets[i]);
				//if bullet is destroyed stop drawing it
				if (bullets[i]->isDestroyed()) {
					bullets[i] = NULL;
				}
			}
		}
		window.display();
	}
	return 0;
}