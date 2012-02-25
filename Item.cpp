/*
 *  untitled.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "item.h"

void Item::Use(Player * player)
{
}

Item::Item(string id, string name, string description, float worth) : GameEntity(id, name, description)
{
	Item::worth = worth;
}