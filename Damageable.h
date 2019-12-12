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
	int getHealth() {
		return health;
	}
	void damage() {
		health -= 1;
	}
	bool isDead() {
		return health <= 0;
	}
};
#endif