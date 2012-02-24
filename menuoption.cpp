/*
 *  menuoption.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "menu.h"
#include "menuoption.h"

MenuOption::MenuOption(string choice, string description, Display* destination)
{
	MenuOption::choice = choice;
	MenuOption::description = description;
	MenuOption::destination = destination;
}

Display* MenuOption::Show()
{
	cout << choice << " " << description << endl;
	
	return NULL;
}

bool MenuOption::IsValid(string input)
{
	if(input == choice)
		return true;
	else
		return false;
}

Display* MenuOption::getDestination()
{
	return destination;
}
