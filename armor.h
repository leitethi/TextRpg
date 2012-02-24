/*
 *  untitled.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
using namespace std;

class Armor
{
private:
	string name;
	int value;
	int maxDex;
	float worth;
	int id;
public:
	Armor();
	Armor(string name, int value, int maxDex, float worth);
	string getName();
	int getValue();
	int getMaxDex(); 
	float getWorth();
};
#endif