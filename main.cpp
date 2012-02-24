#include <iostream>
#include <time.h>
#include <list>
using namespace std;

#include "game.h"

int main (int argc, char * const argv[]) 
{
	Game game;
	while(!game.gameEnded)
	{
		cout << game.getState() << endl;
		game.update();
	}
	
	return 0;
}