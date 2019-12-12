#include <string>
#include <iostream>
#include <list>
//#include <Windows.h>
#include <math.h>
#include "Player.h"
#include "Bullet.h"

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
	list<Bullet> bullets;
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
			if (bullets.size() < 5 && !isPressed) {
				bullets.push_front(player.shoot());
			}
			isPressed = true;
		}
		else {
			isPressed = false;
		}
		window.clear(sf::Color::Black);
		window.draw(fpsCount);
		window.draw(player);
		list<Bullet>::iterator bullet;
		for (bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
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
		}
		window.display();
	}
	return 0;
}