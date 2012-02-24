/*
 *  mainmenu.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "mainmenu.h"

MainMenu::MainMenu()
{
}

void MainMenu::showOptions(Game* game)
{
	std::cout << string(50, '\n');
	std::cout << "====== Main Menu ======" << endl;
	std::cout << "a. Create Character" << endl;
	std::cout << "b. Purchase Equipment" << endl;
	std::cout << "c. View Stats" << endl;
	std::cout << "d. Fight!" << endl;
	std::cout << "q. Quit" << endl;
}
	
void MainMenu::handleInput(Game* game)
{
	bool isValid = false;
	string input;
	
	while(!isValid)
	{
		std::cin >> input;
		if(input == "a")
		{
			//destination = new CreateCharacterMenu();
			//destination->Show();
		}
		if(input == "b")
			break; //destination = new PurchaseEquipmentMenu();
		if(input=="c")
			break;
		if(input=="d")
			break;
		if(input=="q")
			break;
		else {
			std::cout << "Invalid option" << endl;
			isValid = false;
		}
	}
}