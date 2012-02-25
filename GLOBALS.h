/*
 *  GLOBALS.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef GLOBALS_H
#define GLOBALS_H

#define LINE "==================================="

#include <iostream>
#include <time.h>

using namespace std;

static int rollDice(int dices, int sides, int modifier)
{
	int roll = 0;
	for( int i = 0; i < dices; i++ )
	{
		roll += (rand() % sides) + 1;
	}
	roll += modifier;
				
	return roll;
}

static void wait ( int seconds )
{
	clock_t endwait;
	endwait = clock () + seconds * CLOCKS_PER_SEC ;
	while (clock() < endwait) {}
}
#endif