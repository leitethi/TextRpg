/*
 *  mainmenu.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>

#include "game.h"

class MainMenu : public Menu
{
protected:
	void showOptions(Game* game);
	void handleInput(Game* game);
public:
	MainMenu();
};
#endif