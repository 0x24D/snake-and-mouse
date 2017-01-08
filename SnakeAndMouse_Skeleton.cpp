//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
using namespace std;
//include class modules
#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Interface.h"
#include "SnakeAndMouseGame.h"
//using OO approach
//---------------------------------
int main()
{
	SnakeAndMouseGame game;
	game.setUp();
	game.run();
	Interface::holdWindow();
	return 0;
}