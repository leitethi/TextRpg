/*
 *  untitled.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef ITEM_H
#define ITEM_H

#include "player.h"
#include "GameEntity.h"

class Item : public GameEntity
{
private:
	float worth;
protected:
	void virtual Use(Player * player);
public:
	Item(string, string, string, float);
	float getWorth();
	void setWorth(float value);
};
#endif