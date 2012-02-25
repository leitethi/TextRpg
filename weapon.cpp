/*
 *  weapon.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include "weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(string name, int damageMin, int damageMax, int criticalMin, int criticalMax, int multiplier, float worth)
{
	Init(name, damageMin, damageMax, criticalMin, criticalMax, multiplier, worth);
}

void Weapon::Init(string name, int damageMin, int damageMax, int criticalMin, int criticalMax, int multiplier, float worth)
{
	Weapon::name = name;
	Weapon::damageMin = damageMin;
	Weapon::damageMax = damageMax;
	Weapon::criticalMin = criticalMin;
	Weapon::criticalMax = criticalMax;
	Weapon::multiplier = multiplier;
	Weapon::worth = worth;
}
	
string Weapon::getName()
{
	return name;
}
	
int Weapon::getDamageMin()
{
	return damageMin;
}
	
int Weapon::getDamageMax()
{
	return damageMax;
}
	
int Weapon::getCriticalMin()
{
	return criticalMin;
}
	
int Weapon::getCriticalMax()
{
	return criticalMax;
}
	
int Weapon::getMultiplier()
{
	return multiplier;
}
	
float Weapon::getWorth()
{
	return worth;
}