#include <sfml/Graphics.hpp>
#include "Bullet.h"
class AsteroidList {
private:
	sf::RenderWindow& window;
	struct Node {
		Bullet* asteroid;
		Node* next;
		Node* prev;
	};
	Node* top;
public:
	AsteroidList(sf::RenderWindow& w) : window(w) {

	}


	void add(Bullet* a) {
		Node* newNode = new Node();
		newNode->asteroid = a;
		Node* temp = top;
		top = newNode;
		newNode->next = temp;
		if (temp != NULL) {
			temp->prev = newNode;
		}
	}

	void removeDestroyed() {
		Node* temp = top;

		while (temp != NULL) {
			if (temp->asteroid->isDestroyed()) {
				if (temp == top) {
					top = temp->next;
				}
				temp->prev = temp->next;
				delete temp;

			}
		}
	}

	void move(float speed) {
		Node* temp = top;
		while (temp != NULL) {
			float angle = temp->asteroid->getRotation();
			temp->asteroid->move(sin(angle * PI / 180) * 1.f * speed, -cos(angle * PI / 180) * 1.f * speed);
			int xPos = temp->asteroid->getPosition().x;
			int yPos = temp->asteroid->getPosition().y;
			if (xPos > 815) {
				temp->asteroid->setPosition(0, yPos);
			}
			if (xPos < -15) {
				temp->asteroid->setPosition(800, yPos);
			}
			if (yPos > 815) {
				temp->asteroid->setPosition(xPos, 0);
			}
			if (yPos < -15) {
				temp->asteroid->setPosition(xPos, 800);
			}
			temp = temp->next;
		}
	}

	void draw() {
		Node* temp = top;
		while (temp != NULL) {
			window.draw(*(temp->asteroid));
			temp = temp->next;
		}
	}
};