/*
 *  untitled.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "player.h"

class Item
{
private:
	float worth;
	std::string name;
protected:
	void virtual Use(Player * player);
public:
	std::string getName();
	float getWorth();
	void setWorth(float value);
};