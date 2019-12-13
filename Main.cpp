#include <string>
#include <iostream>
#include <list>
#include <array>
//#include <Windows.h>
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
	sf::Text fpsCount;
	fpsCount.setFont(font);
	fpsCount.setCharacterSize(14);
	sf::Clock clock;

	Player player(3);
	//list<Bullet> bullets;
	//array<Bullet, 5> bullets;
	Bullet* bullets[5];
	AsteroidManager* asteroidManager = new AsteroidManager(window);

	for (int i = 0; i < 5; i++) {
		bullets[i] = NULL;
	}
	bool isPressed = false;

	clock.restart();
	while (window.isOpen()) {
		
		sf::Time deltaT = clock.getElapsedTime();
		clock.restart();//set fps counter.
		fpsCount.setString("FPS:" + to_string((int)(1 / deltaT.asSeconds())));
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		//Sleep(16.6);
		float angle = 0.f;
		float speed = 240.f;
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
				asteroidManager->addAsteroid();
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
		list<Bullet>::iterator bullet;
		/*for (bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
			float angle = (*bullet).getRotation();
			(*bullet).move(sin(angle * PI / 180) * 1.f * speed * deltaT.asSeconds(), -cos(angle * PI / 180) * 1.f * speed * deltaT.asSeconds());
			if ((*bullet).getPosition().x > 810 || (*bullet).getPosition().y > 810 || (*bullet).getPosition().x < -10 || (*bullet).getPosition().y < -10) {
 				(*bullet).damage();
			}
			window.draw(*bullet);
			if ((*bullet).isDead()) {
				//bullet = bullets.erase(bullet);
				//bullets.erase(bullet);
//				bullet--;
				//bullets.remove(*bullet);
				cout << "dead";
			}
		}*/
		for (int i = 0; i < 5; i++) {
			if (bullets[i] != NULL) {
				float angle = bullets[i]->getRotation();
				bullets[i]->move(sin(angle * PI / 180) * 1.f * speed * deltaT.asSeconds(), -cos(angle * PI / 180) * 1.f * speed * deltaT.asSeconds());
				if (bullets[i]->getPosition().x > 810 || bullets[i]->getPosition().y > 810 || bullets[i]->getPosition().x < -10 || bullets[i]->getPosition().y < -10) {
					bullets[i]->damage();
				}
				window.draw(*bullets[i]);
				if (bullets[i]->isDestroyed()) {
					bullets[i]->~Bullet();
					bullets[i] = NULL;
				}
			}
			
		}
		window.display();
	}
	return 0;
}