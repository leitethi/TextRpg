/*
 *  GameEntity.h
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "GLOBALS.h"

class GameEntity
{
private:
	string id;
	string name;
	string description;
	bool active;
public:
	GameEntity(string, string, string);
	virtual void Render();
	string getId();
	string getName();
	string getDescription();
};
#endif