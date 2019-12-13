/*****************************************************
FileName: Damageable.h
Description: Objects that can be destroyed in game should
inherent this class.
Author: Kyle Reddeman
Date Created 12/7/19
Class: CptS 122
******************************************************/
#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H
#pragma once

class Damageable {
private:
	int maxHealth;
	int health;
public:
	//sets maxHealth
	Damageable(int maxHealth) {
		Damageable::maxHealth = maxHealth;
		health = maxHealth;
	}
	Damageable() {
		maxHealth = 1;
		health = maxHealth;
	}
	//returns the remaining health
	int getHealth() {
		return health;
	}
	//decreases health by one
	void damage() {
		health -= 1;
	}
	//checks to see if object has any health left.
	bool isDestroyed() {
		return health <= 0;
	}
};
#endif