/*
 *  Battle.h
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef BATTLE_H
#define BATTLE_H

#include "GLOBALS.h"
#include "player.h"

class Battle
{
private:
	Player* player1;
	Player* player2;
	Player* winner;
	int getAttackRole(Player*);
	int getArmorCheck(Player*);
	int getInitiative(Player*);
	void turn(Player*,Player*);
	void determineWinner(Player*);
	bool checkDeadPlayer();
public:
	Battle(Player*, Player*);
	void Start();
	Player* getWinner();
};
#endif