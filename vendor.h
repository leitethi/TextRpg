/*
 *  vendor.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>
#include <list>
#include <time.h>
using namespace std;

#include "player.h"

class Vendor
{
private:
	std::list<Weapon*> weapons;
	std::list<Armor*> armors;
public:
	void addWeapon(Weapon* weapon);
	void addArmor(Weapon* armor);
	std::list<Weapon*> getArmors();
	std::list<Weapon*> getWeapons();
	
	void sellWeapon(Weapon* weapon);
	void sellArmor(Armor* armor);
};
#endif