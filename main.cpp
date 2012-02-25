using namespace std;

#include "GLOBALS.h"
#include "game.h"

int main (int argc, char * const argv[]) 
{
	cout << LINE << endl;
	Game game;
	while(!game.gameEnded)
	{
		game.update();
	}
	
	return 0;
}