/*
 *  createcharactermenu.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "createcharactermenu.h"

CreateCharacterMenu::CreateCharacterMenu()
{
}

void CreateCharacterMenu::showOptions(Game* game)
{
	std::cout << string(50, '\n');
	std::cout << "====== Create Character ======" << endl;
	std::cout << "a. Name Character" << endl;
	std::cout << "b. Roll for stats" << endl;
	std::cout << "r. Return to previous menu" << endl;
}
	
void CreateCharacterMenu::handleInput(Game* game)
{
	bool isValid = false;
	string input;
	
	while(!isValid)
	{
		std::cin >> input;
		if(input == "a")
		{
			game->setState(NameCharacter);
		}
		if(input == "b")
		{
			game->setState(RollForStats);
		}
		if(input == "r")
		{
			game->setState(Main);
		}
		else {
			std::cout << "Invalid option" << endl;
			isValid = false;
		}
	}
}
