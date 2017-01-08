#include "SnakeAndMouseGame.h"
void SnakeAndMouseGame::setUp(){
	//set up snake
	snake_.spotMouse(&mouse_);
}
void SnakeAndMouseGame::run(){
	do {
		Interface::drawGridOnScreen(prepareGrid());
		Interface::showResultsOnScreen(prepareScorebar());
		key_ = Interface::getKeyPressFromUser();
		while (!hasEnded(key_))
		{
			if (isArrowKeyCode(key_))
			{
				mouse_.scamper(key_);
				snake_.chaseMouse();
				Interface::drawGridOnScreen(prepareGrid());
				Interface::showResultsOnScreen(prepareScorebar());
				applyRules();
			}
			key_ = Interface::getKeyPressFromUser();
		}
		Interface::showResultsOnScreen(prepareEndMessage());
		reset();
	} while (Interface::getKeyPressFromUser() == 'Y');
}
string SnakeAndMouseGame::prepareGrid(){
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.getY()) && (col == snake_.getX()))
				os << snake_.getSymbol();	//show snake
			else
				if (snake_.getTailPosition(col, row))
					os << snake_.getTailSymbol();
				else
					if ((row == mouse_.getY()) && (col == mouse_.getX()))
						os << mouse_.getSymbol();	//show mouse
					else
						if (((row == nut_.getY()) && (col == nut_.getX())) && !nut_.hasBeenCollected())
							os << nut_.getSymbol(); //show nut
						else
							if (underground_.findHoleNumberAtPosition(col, row) != 0)
								os << underground_.getHoleSymbol();	//show hole
							else
								os << FREECELL;	//show free grid cell
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepareGrid
bool SnakeAndMouseGame::isArrowKeyCode(const int& keycode)const {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
void SnakeAndMouseGame::applyRules(){
	if (mouse_.canCollectNut(nut_))
		nut_.disappear();
	else
		if (snake_.hasCaughtMouse()){
			player_.updateScoreAmount(-1);
			mouse_.die();
		}
		else
			if (mouse_.hasReachedAHole(underground_) && (nut_.hasBeenCollected())){
				player_.updateScoreAmount(1);
				mouse_.escapeIntoHole();
			}
}
bool SnakeAndMouseGame::hasEnded(const char& key)const {
	return ((key == 'Q') || (!mouse_.isAlive()) || (mouse_.hasEscaped()));
}
string SnakeAndMouseGame::prepareEndMessage()const {
	ostringstream os;
	if (mouse_.hasEscaped())
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!\nDO YOU WANT TO PLAY AGAIN?";
	else
		if (!mouse_.isAlive())
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!\nDO YOU WANT TO PLAY AGAIN?";
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}
int SnakeAndMouseGame::getKey() const {
	return key_;
}
ofstream& operator <<(ofstream& fout, const string& game){
	fout.open("SnakeAndMouseGame.txt", ios::out);
	if (fout.fail())
		cout << "\nAn error has occurred when opening the file.";
	else
		fout << game;
	fout.close();
	return(fout);
}
ifstream& operator >>(ifstream& fin, const string& game){
	fin.open("SnakeAndMouseGame.txt", ios::in);
	if (fin.fail())
		cout << "\nAn error has occurred when opening the file.";
	else
		fin >> game;
	fin.close();
	return(fin);
}
void SnakeAndMouseGame::reset(){
	nut_.reset();
	mouse_.reset();
	snake_.reset();
	
}
string SnakeAndMouseGame::prepareScorebar()const{
	ostringstream os;
	os << "NAME: " << player_.getName() << "\tSCORE: " << player_.getScoreAmount();
	return os.str();
}