/*
 *  Game.cpp
 *  cplusplus
 *
 *  Created by Thiago Nunes Leite on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "game.h"
#include "Battle.h"

class MainMenu : public Menu
{
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "====== Main Menu ======" << endl;
		std::cout << "a. Create Character" << endl;
		std::cout << "b. Purchase Equipment" << endl;
		std::cout << "c. View Stats" << endl;
		std::cout << "d. Fight!" << endl;
		std::cout << "q. Quit" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		char input;
		
		while(!isValid)
		{
			std::cin >> input;
			if(input == 'a')
			{
				game->setState(CreateCharacter);
				isValid = true;
			}
			else if(input == 'b')
			{
				game->setState(PurchaseEquipment);
				isValid = true;
			}
			else if(input == 'c')
			{
				game->setState(ViewStats);
				isValid = true;
			}
			else if(input == 'd')
			{
				game->setState(Fight);
				isValid = true;
			}
			else if(input == 'e')
			{
				game->setState(Quit);
				isValid = true;
				
				game->gameEnded = true;
			}
			else {
				std::cout << "Invalid option" << endl;
				isValid = false;
			}
		}
	}
};

// Purchase equipment menu
class PurchaseEquipmentMenu : public Menu
{
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "====== Purchase Equipment ======" << endl;
		std::cout << "a. Weapons" << endl;
		std::cout << "b. Armors" << endl;
		std::cout << "r. Return to previous menu" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		char input;
		
		if (game->getPlayer() == NULL)
		{
			cout << "You must have a character created before going to shop" << endl;
			game->setState(Main);
		}
		else {
			while(!isValid)
			{
				std::cin >> input;
				if(input == 'a')
				{
					game->setState(PurchaseWeapon);
					isValid = true;
				}
				else if(input == 'b')
				{
					game->setState(PurchaseArmor);
					isValid = true;
				}
				else 
				{
					std::cout << "Invalid option" << endl;
					isValid = false;
				}
			}
			
		}
	}
};

class PurchaseWeaponMenu : public Menu
{
private:
	std::vector<Weapon*> weapons;
	std::vector<Weapon*> list;
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "====== Purchase Weapon ======" << endl;
		std::cout << "Name\t\t\t\tDamage Min\t\tDamage Max\t\tCritical Min\t\tCriticalMax\t(X)\t\tPrice" << endl;
		list = game->getWeapons();
		
		for (int i = 0; i < list.size(); i++) 
		{
			std::cout << i << ". " 
			<< list[i]->getName() << " | " << list[i]->getDamageMin() << " | " 
			<< list[i]->getDamageMax() << " | " << list[i]->getCriticalMin() << " | " 
			<< list[i]->getCriticalMax() << " | "<< list[i]->getMultiplier() << " | " 
			<< list[i]->getWorth() << endl;
		}
		std::cout << "=============================" << endl;
		std::cout << "Enter the weapon number to buy it" << endl;
		std::cout << "You have " << game->getPlayer()->getGold() << "gold available" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		string input;
		
		while(!isValid)
		{
			std::cin >> input;
		
			for (int i = 0; i < list.size(); i++) 
			{
				if (input == game->intToStr(i))
				{
					if (game->getPlayer()->getGold() >= list[i]->getWorth()) 
					{
						game->getPlayer()->setWeapon(list[i]);
						game->getPlayer()->removeGold(list[i]->getWorth());
						
						game->setState(Main);
						Player* p = game->getPlayer();
						p->setWeapon(list[i]);
						isValid = true;
						
						game->setState(Main);
						
						cout << "You bought " << list[i]->getName() << " for " << list[i]->getWorth() << " gold" << endl;
						
						cout << "Press any key to continue" << endl;
						
						cin >> input;
					}
					else {
						cout << "You don't have enought funds to buy this weapon" << endl;
						isValid = false;
					}
				}
			}
			
			if(!isValid)
				cout << "Invalid option" << endl;
		}
	}
};

class PurchaseArmorMenu : public Menu
{
private:
	std::vector<Armor*> armor;
	std::vector<Armor*> list;
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "====== Purchase Armor ======" << endl;
		std::cout << "Name\t\t\t\tDef\t\tMax Dex\t\tPrice" << endl;
		list = game->getArmors();
		
		for (int i = 0; i < list.size(); i++) 
		{
			std::cout << i << ". " << list[i]->getName() << " | " 
			<< list[i]->getValue() << " | " << list[i]->getWorth() << endl;
		}
		std::cout << "=============================" << endl;
		std::cout << "Enter the weapon number to buy it" << endl;
		std::cout << "You have " << game->getPlayer()->getGold() << " gold available" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		string input;
		
		while(!isValid)
		{
			std::cin >> input;
			
			for (int i = 0; i < list.size(); i++) 
			{
				if (input == game->intToStr(i))
				{
					if (game->getPlayer()->getGold() >= list[i]->getWorth()) 
					{
						game->getPlayer()->setArmor(list[i]);
						game->getPlayer()->removeGold(list[i]->getWorth());
						
						Player* p = game->getPlayer();
						p->setArmor(list[i]);
						isValid = true;
						
						game->setState(Main);
						
						cout << "You bought " << list[i]->getName() << " for " << list[i]->getWorth() << " gold" << endl;
						
						cout << "Press any key to continue" << endl;
						
						cin >> input;
					}
					else {
						cout << "You don't have enought funds to buy this weapon" << endl;
						isValid = false;
					}
				}
			}
			
			if(!isValid)
				cout << "Invalid option" << endl;
		}
	}
};

class CreateCharacterMenu : public Menu
{
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "====== Create Character ======" << endl;
		std::cout << "a. Name Character" << endl;
		std::cout << "b. Roll for stats" << endl;
		std::cout << "r. Return to previous menu" << endl;
	}
	
	void handleInput(Game* game)
	{		
		bool isValid = false;
		char input;
		
		if (game->getPlayer() != NULL)
		{
			std::cout << CLEAR;
			std::cout << "You already created a player, you want to erase it? (y/n)";
			
			while (!isValid)
			{
				std::cin >> input;
				if (input == 'y') 
				{
					game->erasePlayer();
					game->setState(CreateCharacter);
					isValid = true;
				} 
				else if (input == 'n') 
				{
					game->setState(Main);
					isValid = true;
				} 
				else 
				{
					std::cout << "Invalid option";
					isValid = false;
				}
			}
		}
		else 
		{
			while(!isValid)
			{
				std::cin >> input;
				if(input == 'a')
				{
					game->setState(NameCharacter);
					isValid = true;
				}
				else if(input == 'b')
				{
					game->setState(RollForStats);
					isValid = true;
				}
				else if(input == 'r')
				{
					game->setState(Main);
					isValid = true;
				}
				else {
					std::cout << "Invalid option" << endl;
					isValid = false;
				}
			}
		}
	}
};

class NameCharacterMenu : public Menu 
{
protected:
	void showOptions(Game* game)
	{
		std::cout << string(50, '\n');
		std::cout << "What's your name?" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		std::string input;
		
		while(!isValid)
		{
			std::cin >> input;
			if(input.length() > 1)
			{
				game->createPlayerName(input);
				game->setState(RollForStats);
				isValid = true;
			}
			else {
				std::cout << "Invalid option" << endl;
				isValid = false;
			}
		}		
	}
};

// Main Menu > View Status Menu
class ViewStatsMenu : public Menu 
{
protected:
	void showOptions(Game* game)
	{
		Player* player = game->getPlayer();
		
		std::cout << string(50, '\n');
		std::cout << "===== PLAYER STATS =====" << endl;
		std::cout << "Name: " << player->getName() << endl;
		std::cout << "Str: " << player->getStr() << endl;
		std::cout << "Dex: " << player->getDex() << endl;
		std::cout << "Con: " << player->getCon() << endl;
		std::cout << "HitPoints: " << player->getMaxHitPoints() << endl;
		std::cout << "Experience: " << player->getExp() << endl;
		std::cout << "Gold: " << player->getGold() << endl;
		std::cout << "Weapon: " << player->getWeaponName() << endl;
		std::cout << "Armor: " << player->getArmorName() << endl;
		std::cout << "=========================" << endl;
		std::cout << "Press any key to return" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		char input;
		
		while(!isValid)
		{
			std::cin >> input;
			cin.ignore();
			game->setState(Main);
			isValid = true;
		}
	}
};

class RollForStatsMenu : public Menu 
{
private:
	int str;
	int dex;
	int con;
	int hitPoints;
	
protected:
	void showOptions(Game* game)
	{
		str = 8;
		dex = 8;
		con = 8;
		hitPoints = 10 + (con - 10) /2;
		
		std::cout << "Str: " << str << endl;
		std::cout << "Dex: " << dex << endl;
		std::cout << "Con: " << con << endl;
		std::cout << "HitPoints: " << hitPoints << endl;
		std::cout << "=======================================" << endl;
		std::cout << "Press 'c' to confirm your character or 'r' to roll the stats again" << endl;
	}

	void handleInput(Game* game)
	{
		bool isValid = false;
		char input;
		
		while(!isValid)
		{
			std::cin >> input;
			if(input == 'c')
			{
				game->createPlayer(str, dex, con, hitPoints);
				game->setState(Main);
				isValid = true;
			}
			else if(input == 'r')
			{
				game->setState(RollForStats);
				isValid = true;
			}
			else 
			{
				std::cout << "Invalid option" << endl;
				isValid = false;
			}
		}		
	}
};

class FightMenu : public Menu
{
private:
	Player* player1;
	Player* player2;
	bool ended;
	Armor* armor;
	Weapon* weapon;
	Battle* battle;
	
	void play(Game * game,int level)
	{
		switch (level) {
			case 1:
				player2 = new Player();
				player2->Init("Romildo", 1, 1, 1, 1, 1, 1, 1);
				armor = new Armor("Unarmored", 0, 0, 0);
				weapon = new Weapon("Unarmed Strike", 1, 3, 20, 20, 2, 0);
				player2->setWeapon(weapon);
				player2->setArmor(armor);
				player1->restoreLife();
				break;
			case 2:
				player2 = new Player();
				player2->Init("Romildo", 2, 2, 2, 2, 2, 2, 2);
				break;
			case 3:
				player2 = new Player();
				player2->Init("Romildo", 1, 1, 1, 1, 5, 5, 5);
				break;
			case 4:
				player2 = new Player();
				player2->Init("Romildo", 1, 1, 1, 1, 5, 5, 5);
				break;
			case 5:
				player2 = new Player();
				player2->Init("Romildo", 1, 1, 1, 1, 5, 5, 5);
				break;
			default:
				player2 = new Player();
				player2->Init("Romildo", 1, 1, 1, 1, 5, 5, 5);
				break;
		}
		
		battle = new Battle(player1, player2);
		battle->Start();
		
		delete battle;
	}
	
protected:
	void showOptions(Game* game)
	{
		player1 = game->getPlayer();
		
		std::cout << string(50, '\n');
		std::cout << "====== Level Menu ======" << endl;		
		for(int i = 1; i <= player1->getLevel(); i++)
		{
			cout << i << endl;
		}
		cout << "Enter the level of the opponent you would like to fight" << endl;
	}
	
	void handleInput(Game* game)
	{
		bool isValid = false;
		string input;
		
		int level = 1;
		while(!isValid)
		{
			std::cin >> input;
			for(int i = 1; i <= player1->getLevel(); i++)
			{
				level = game->strToInt(input);
				if(level == i)
				{
					isValid = true;
					break;
				}
			}
			
			if (!isValid) {
				cout << "Invalid option" << endl;
			}
		}
		
		play(game, level);
	
		game->setState(Main);

		cout << "Press any key to continue" << endl;
		
		string str;
		cin >> str;
	}
};

Game::Game()
{
	gameEnded = false;
	player = NULL;
	
	currentMenu = NULL;
	
	setState(Main);

	Weapon* weapon = new Weapon("Unarmed Strike", 1, 3, 20, 20, 2, 0);
	weapons.push_back(weapon);
	weapon = new Weapon("Brass Knuckles", 1, 4, 20, 20, 2, 2);
	weapons.push_back(weapon);
	weapon = new Weapon("Dagger", 1, 4, 19, 20, 2, 2);
	weapons.push_back(weapon);
	weapon = new Weapon("Mace", 1, 6, 20, 20, 2, 5);
	weapons.push_back(weapon);
	weapon = new Weapon("Handaxe", 1, 6, 20, 20, 3, 6);
	weapons.push_back(weapon);
	weapon = new Weapon("Shortsword", 1, 6, 19, 20, 2, 6.5);
	weapons.push_back(weapon);
	weapon = new Weapon("Scimitar", 1, 6, 18, 20, 2, 7);
	weapons.push_back(weapon);
	weapon = new Weapon("Morningstar", 1, 8, 20,20, 2, 8);
	weapons.push_back(weapon);
	weapon = new Weapon("Spear", 1, 8, 20, 20, 3, 9);
	weapons.push_back(weapon);
	weapon = new Weapon("Longsword", 1, 8, 19, 20, 2, 9.5);
	weapons.push_back(weapon);
	weapon = new Weapon("Greatclub", 1, 10, 20, 20, 2, 11);
	weapons.push_back(weapon);
	weapon = new Weapon("Halberd", 1, 10, 20, 20, 3, 12);
	weapons.push_back(weapon);
	weapon = new Weapon("Bastard Sword", 1, 10, 19, 20, 2, 12.5);
	weapons.push_back(weapon);
	weapon = new Weapon("Greataxe", 1, 12, 20, 20, 3, 16);
	weapons.push_back(weapon);
	weapon = new Weapon("Greatsword", 2, 6, 19, 20, 2, 20);
	weapons.push_back(weapon);
	
	Armor* armor = new Armor("Unarmored", 0, 0, 0);
	armors.push_back(armor);
	armor = new Armor("Padded Armor",1, 8, 5);
	armors.push_back(armor);
	armor = new Armor("Leather Armor", 2, 6, 10);
	armors.push_back(armor);
	armor = new Armor("Hide Armor", 3,4,15);
	armors.push_back(armor);
	armor = new Armor("Studded Leather",3,5,25);
	armors.push_back(armor);
	armor = new Armor("Scale Mail",4,3,50);
	armors.push_back(armor);
	armor = new Armor("Chain Shirt",4,4,100);
	armors.push_back(armor);
	armor = new Armor("Chainmail",5,2,150);
	armors.push_back(armor);
	armor = new Armor("Breastplate",5,3,200);
	armors.push_back(armor);
	armor = new Armor("Splint Mail",6,0,225);
	armors.push_back(armor);
	armor = new Armor("Banded Mail",6,1,250);
	armors.push_back(armor);
	armor = new Armor("Half-Plate",7,0,600);
	armors.push_back(armor);
	armor = new Armor("Full Plate",8,1,1000);
	armors.push_back(armor);
}

void Game::newGame()
{
	delete player;
}

GameState Game::getState()
{
	return gameState;
}

void Game::setState(GameState state)
{
	gameState = state;
	switch (gameState) {
		case Main:
			currentMenu = new MainMenu();
			break;
		case CreateCharacter:
			currentMenu = new CreateCharacterMenu();
			break;
		case NameCharacter:
			currentMenu=new NameCharacterMenu();
			break;
		case RollForStats:
			currentMenu= new RollForStatsMenu();
			break;
		case ViewStats:
			currentMenu = new ViewStatsMenu();
			break;
		case PurchaseEquipment:
			currentMenu = new PurchaseEquipmentMenu();
			break;
		case PurchaseWeapon:
			currentMenu = new PurchaseWeaponMenu();
			break;
		case PurchaseArmor:
			currentMenu = new PurchaseArmorMenu();
			break;
		case Fight:
			currentMenu = new FightMenu();
			break;
		default:
			break;
	}
}

void Game::update()
{
	currentMenu->Show(this);
}
	
void Game::createPlayerName(string name)
{
	playerName = name;
}

void Game::createPlayer(int str, int dex, int con, int hitPoints)
{
	Armor* armor = new Armor("Unarmored", 0, 0, 0);
	Weapon* weapon = new Weapon("Unarmed Strike", 1, 3, 20, 20, 2, 0);
	
	Game::player = new Player();
	player->Init(playerName, 1, str, dex, con, hitPoints, 0, 5);
	player->setWeapon(weapon);
	player->setArmor(armor);
}

void Game::erasePlayer()
{
	player = NULL;
}

Player* Game::getPlayer()
{
	return player;
}

std::vector<Weapon*> Game::getWeapons()
{
	return weapons;
}

std::vector<Armor*> Game::getArmors()
{
	return armors;
}

string Game::intToStr(int number)
{
	stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}

int Game::strToInt(string str)
{
	istringstream buffer(str);
	int value;
	buffer >> value;
	
	return value;
}

// Menu class
Menu::Menu()
{
}

void Menu::showOptions(Game* game)
{
}

void Menu::handleInput(Game* game)
{
}

void Menu::Show(Game* game)
{
	showOptions(game);
	
	handleInput(game);
}


