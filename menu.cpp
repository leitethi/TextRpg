/*
 *  menu.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"

Menu::Menu()
{
}

Menu::Menu(Game * game)
{
	Menu::game = game;
}

void Menu::showOptions()
{
}

void Menu::Show()
{
	showOptions();
	
	handleInput();
}

void Menu::handleInput()
{
}

