/*
 *  menu.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <list>
using namespace std;

#include "game.h"

class Game;

class Menu
{
protected:
	Game* game;
	Menu* destination;
	virtual void showOptions();
	virtual void handleInput();
public:
	Menu();
	Menu(Game* game);
	void Show();
};
#endif