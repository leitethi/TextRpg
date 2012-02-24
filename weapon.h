/*
 *  weapon.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
using namespace std;

class Weapon
{
private:
	string name;
	int damageMin;
	int damageMax;
	int criticalMin;
	int criticalMax;
	int multiplier;
	float worth;
public:
	Weapon();
	Weapon(string name, int damageMin, int damageMax, int criticalMin, int criticalMax, int multiplier, float worth);
	void Init(string name, int damageMin, int damageMax, int criticalMin, int criticalMax, int multiplier, float worth);
	string getName();
	int getDamageMin();
	int getDamageMax();
	int getCriticalMin();
	int getCriticalMax();
	int getMultiplier();
	float getWorth();
};
#endif