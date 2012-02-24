/*
 *  player.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

#include "weapon.h"
#include "armor.h"

class Player 
{
private:
	Weapon* weapon;
	Armor* armor;	
	string name; 		// Name of the Character
	bool alive;
	int level;	// Level of the Character (1-20)
	int strength;	// Strength of the Character (8-20)
	int dexterity;	// Dexterity of the Character (8-20)
	int constitution;	// Constitution of the Character (8-20)
	int maxHitPoints;	// The hit points of the character
	int currentHitPoints;
	int experience;	// How many experience points the character has earned
	float gold;	// The amount of gold the character has earned through victorious battles
	bool critical;
	int rollDice( int numDice, int numSides, int modifier);
public:
	void Init(string name, int level, int str, int dex, int con, int maxHitPoints, int experience, float gold);
	string getName();
	int getLevel();
	int getStr();
	int getDex();
	int getCon();
	int getExp();
	float getGold();
	void setWeapon(Weapon* weapon);
	string getWeaponName();
	void setArmor(Armor* armor);
	string getArmorName();
	int getInitiative();
	int getStrModifier();
	int getDexModifier();
	int getConModifier();
	int getMaxHitPoints();
	int getCurrentHitPoints();
	int getArmorCheck();
	int getAttackRole();
	int getWeaponDamageMin();
	int getWeaponDamageMax();
	int getWeaponCriticalMin();
	int getWeaponCriticalMax();
	int getWeaponMultiplier();
	void removeGold(float gold);
	void addGold(float gold);
	void TakeDamage(int damage);
	void increaseLevel();
	void increaseHitPoints(int hitPoints);
	void restoreLife();
	bool isAlive();
};
#endif