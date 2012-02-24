/*
 *  menuoption.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once

#include <iostream>
using namespace std;

#include "display.h"
#include "menu.h"

class MenuOption : public Display
{
private:
	string choice;
	string description;
	Display* destination;
public:
	MenuOption(string choice, string description, Display* display);
	Display* Show();
	virtual bool IsValid(string input);
	Display* getDestination();
};