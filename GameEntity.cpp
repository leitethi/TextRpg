/*
 *  GameEntity.cpp
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "GameEntity.h"

GameEntity::GameEntity(string id, string name, string description)
{
	GameEntity::id = id;
	GameEntity::name = name;
	GameEntity::description = description;
}

void GameEntity::Render()
{
}

string GameEntity::getId()
{
	return id;
}

string GameEntity::getName()
{
	return name;
}

std::string GameEntity::getDescription()
{
	return description;
}