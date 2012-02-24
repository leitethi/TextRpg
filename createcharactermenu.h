/*
 *  createcharactermenu.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CREATECHARACTERMENU_H
#define CREATECHARACTERMENU_H

#include <iostream>

#include "game.h"

class CreateCharacterMenu : public Menu
{
protected:
	void showOptions(Game* game);
	void handleInput(Game* game);
	
public:
	CreateCharacterMenu();
};
#endif