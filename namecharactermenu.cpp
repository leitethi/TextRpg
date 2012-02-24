/*
 *  namecharactermenu.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "namecharactermenu.h"

NameCharacterMenu::NameCharacterMenu()
{
}

void NameCharacterMenu::showOptions(Game* game)
{
	std::cout << string(50, '\n');
	std::cout << "What's your name" << endl;
}
	
void NameCharacterMenu::handleInput(Game* game)
{
	bool isValid = false;
	std::string input;
		
	while(!isValid)
	{
		std::cin >> input;
		if(input.length() > 1)
		{
			game->setState(NameCharacter); //destination = new NameCharacterMenu();
		}
		if(input == "b")
		{
			break; //destination = new RollForStatsMenu();
		}
		if(input == "r")
			break;//destination = new MainMenu();
		else {
			std::cout << "Invalid option" << endl;
			isValid = false;
		}
	}
}