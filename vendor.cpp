/*
 *  vendor.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "vendor.h"

std::list<Weapon*> getArmors()
{
	return armors;
}

std::list<Weapon*> getWeapons()
{
	return weapons;
}

void addWeapon(Weapon* weapon)
{
	weapons->push_back(weapon);
}

void addArmor(Weapon* armor)
{
	armors->push_back(armor);
}

void sellWeapon(Weapon* weapon)
{
	weapons->remove(weapon);
}

void sellArmor(Armor* armor)
{
	armors->remove(armor);
}