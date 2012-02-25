/*
 *  Container.h
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/25/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CONTAINER_H
#define CONTAINER_H

#include "GLOBALS.h"
#include "GameEntity.h"

#include <vector>

class Container : public GameEntity
{
private:
	vector<GameEntity> items;
public:
	Container(string, string, string);
	vector<GameEntity> getItems();
};
#endif