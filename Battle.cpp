/*
 *  Battle.cpp
 *  TextRpg
 *
 *  Created by Thiago Nunes Leite on 2/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Battle.h"

// Battle System 1x1
Battle::Battle(Player* player1, Player* player2)
{
	Battle::player1 = player1;
	Battle::player2 = player2;
}

int Battle::getAttackRole(Player* player)
{
	return rollDice(1, 20, 0) + player->getLevel() + player->getStrModifier();
}

int Battle::getArmorCheck(Player* player)
{
	return player->getArmor() + 10 + player->getDexModifier();
}

int Battle::getInitiative(Player* player)
{
	return rollDice(1, 10, 0) + player->getDexModifier();
}

void Battle::turn(Player* attacker, Player* defender)
{
	bool critical = false;
	
	if(getAttackRole(attacker) >= getArmorCheck(defender))
	{			
		int row = 0;
		for(int i = 1; i <= attacker->getWeaponDamageMin(); i++)
		{
			row += rollDice(1, attacker->getWeaponDamageMax(), 1);
			if (row >= attacker->getWeaponCriticalMin() && row <= attacker->getWeaponCriticalMax())
			{
				row *= attacker->getWeaponMultiplier();
				critical = true;
			}
		}
		
		int damage = row + attacker->getStrModifier();
		if(critical)
			cout << attacker->getName() << " swings his " << attacker->getWeaponName()  << " at his opponent %s and critically hits him for " << damage << " damage!" << endl;
		else {
			cout << attacker->getName() << " swings his " << attacker->getWeaponName() << " at " << defender->getName() << " and hits him for " << damage << " damage!" << endl;
		}
		
		defender->TakeDamage(damage);
	} 
	else {
		cout << attacker->getName() << " swings his " << attacker->getWeaponName() << " at his opponent and misses." << endl;
	}
}

bool Battle::checkDeadPlayer()
{
	if (!player1->isAlive()) 
	{
		cout << "You died!" << endl;
		determineWinner(player2);
		
		return true;
		
	} 
	else if (!player2->isAlive()) 
	{
		cout << player2->getName() << "level " << player2->getLevel() << " died!" << endl;
		
		determineWinner(player1);
		
		return true;
	}
	
	return false;
}

void Battle::determineWinner(Player* player)
{
	if(player == player1)
		winner = player1;
	else
		winner = player2;

	winner->restoreLife();
	
	int expRequired = (winner->getExp() + winner->getLevel()) * winner->getExp();
	if (winner->getExp() == expRequired)
	{
		winner->increaseLevel();
		
		int hitPointsReceived = rollDice(1, 10, 0) + winner->getConModifier();
		
		winner->increaseHitPoints(hitPointsReceived);
	}
	
	cout << winner->getName() << " receives 10 gold" << endl;
}

void Battle::Start()
{
	if(getInitiative(player1) >= getInitiative(player2))
	{
		cout << player1->getName() << " starts the fight and attacks " << player2->getName() << endl;
		
		while(player1->isAlive() && player2->isAlive())
		{
			turn(player1, player2);
			if(checkDeadPlayer())
				break;
			
			wait(5);
			
			turn(player2, player1);
			if(checkDeadPlayer())
				break;
		}
	}
	else 
	{
		cout << player2->getName() << " starts the fight and attacks " << player1->getName() << endl;
		
		while(player1->isAlive() && player2->isAlive())
		{
			turn(player2, player1);
			if(checkDeadPlayer())
				break;
			
			wait(5);
			
			turn(player1, player2);
			if(checkDeadPlayer())
				break;
		}
	}
}

Player* Battle::getWinner()
{
	return winner;
}