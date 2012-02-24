/*
 *  untitled.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "armor.h"

Armor::Armor()
{
}

Armor::Armor(string name, int value, int maxDex, float worth)
{
	Armor::name = name;
	Armor::value = value;
	Armor::maxDex = maxDex;
	Armor::worth = worth;
}

string Armor::getName()
{
	return name;
}

int Armor::getValue()
{
	return value;
}

float Armor::getWorth()
{
	return worth;
}
