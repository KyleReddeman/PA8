#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H
#pragma once

class Damageable {
private:
	int maxHealth;
	int health;
public:
	Damageable(int maxHealth) {
		Damageable::maxHealth = maxHealth;
		health = maxHealth;
	}
	Damageable() {
		maxHealth = 1;
		health = maxHealth;
	}
	int getHealth() {
		return health;
	}
	void damage() {
		health -= 1;
	}
	bool isDestroyed() {
		return health <= 0;
	}
};
#endif