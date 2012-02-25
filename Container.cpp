/*
 *  Container.cpp
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/25/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Container.h"

Container::Container(string id, string name, string description) 
: GameEntity(id, name, description)
{
}

vector<GameEntity> Container::getItems()
{
	return items;
}