/*
 *  Game.h
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef GAME_H
#define GAME_H

#include <sstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <time.h>
using namespace std;

#include "player.h"

#define CLEAR string(50, '\n');

enum GameState {Main,CreateCharacter,NameCharacter,RollForStats,PurchaseEquipment,PurchaseArmor, PurchaseWeapon,ViewStats,Fight,Quit};

class Game;
class Menu;

class Menu
{
protected:
	Game* game;
	Menu* destination;
	virtual void showOptions(Game* game);
	virtual void handleInput(Game* game);
public:
	Menu();
	void Show(Game* game);
};

class Game
{
private:
	std::string playerName;
	std::string message;
	Player* player;
	Menu* currentMenu;
	GameState gameState;
	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;
public:
	Game();
	void newGame();
	bool gameEnded;
	GameState getState();
	void setState(GameState state);
	void update();
	void createPlayerName(std::string name);
	void createPlayer(int str, int dex, int con, int hitPoints);
	void erasePlayer();
	void registerMessage(string message);
	void transmitMessage();
	Player* getPlayer();
	std::vector<Weapon*> getWeapons();
	std::vector<Armor*> getArmors();
	string intToStr(int);
	int strToInt(std::string);
	int rollDice(int dices, int sides, int modifier);
	
};
#endif