/*
 *  player.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "player.h"

void Player::Init(string name, int level, int str, int dex, int con, int maxHitPoints, int experience, float gold)
{
	Player::name = name;
	Player::maxHitPoints = maxHitPoints;
	Player::strength = str;
	Player::dexterity = dex;
	Player::constitution = con;
	Player::experience = experience;
	Player::gold = gold;
	Player::level = level;
		
	alive = true;
	
	Player::currentHitPoints = Player::maxHitPoints = maxHitPoints;
}
	
string Player::getName()
{
	return name;
}
	
int Player::getLevel()
{
	return level;
}
	
int Player::getStr()
{
	return strength;
}
	
int Player::getDex()
{
	return dexterity;
}
	
int Player::getCon()
{
	return constitution;
}

int Player::getCurrentHitPoints()
{
	return currentHitPoints;
}

int Player::getMaxHitPoints()
{
	return maxHitPoints;
}
	
int Player::getExp()
{
	return experience;
}
	
float Player::getGold()
{
	return gold;
}
	
void Player::setWeapon(Weapon* weapon)
{
	Player::weapon = weapon;
}
	
string Player::getWeaponName()
{
	return weapon->getName();
}
	
void Player::setArmor(Armor* armor)
{
	Player::armor = armor;
}
	
string Player::getArmorName()
{
	return armor->getName();
}

int Player::getStrModifier()
{
	return (strength - 10) / 2;
}
	
int Player::getDexModifier()
{
	return (dexterity - 10) / 2;
}
	
int Player::getConModifier()
{
	return (constitution - 10) /2;
}

int Player::getArmor()
{
	return armor->getValue();
}
	
int Player::getWeaponDamageMin()
{
	return weapon->getDamageMin();
}
	
int Player::getWeaponDamageMax()
{
	return weapon->getDamageMax();
}
	
int Player::getWeaponCriticalMin()
{
	return weapon->getCriticalMin();
}
	
int Player::getWeaponCriticalMax()
{
	return weapon->getCriticalMax();
}
	
int Player::getWeaponMultiplier()
{
	return weapon->getMultiplier();
}
	
void Player::removeGold(float gold)
{
	Player::gold -= gold;
	if(Player::gold < 0)
		Player::gold = 0;
}
	
void Player::addGold(float gold)
{
	Player::gold += gold;
}
	
void Player::TakeDamage(int damage)
{
	currentHitPoints -= damage;
}
	
void Player::increaseLevel()
{
	level++;
}
	
void Player::increaseHitPoints(int hitPoints)
{
	Player::maxHitPoints += hitPoints;
}

void Player::restoreLife()
{
	Player::currentHitPoints = maxHitPoints;
}
	
bool Player::isAlive()
{
	if(currentHitPoints <= 0)
		return false;
		
	return true;
}
