#include "SnakeAndMouseGame.h"
SnakeAndMouseGame::SnakeAndMouseGame() : nut_(srng_.getRandomValue(GRIDSIZE), srng_.getRandomValue(GRIDSIZE)), p_player_(nullptr) { snake_.spotMouse(&mouse_); mouse_.spotNut(&nut_); }
void SnakeAndMouseGame::run(){
	while (mouse_.isAtPosition(nut_.getX(), nut_.getY()) || underground_.findHoleAtPosition(mouse_.getX(), mouse_.getY()) ||
		mouse_.isAtPosition(snake_.getX(), snake_.getY()) || snake_.getTailPosition(mouse_.getX(), mouse_.getY()))
	{
		mouse_.resetPosition(srng_.getRandomValue(GRIDSIZE), srng_.getRandomValue(GRIDSIZE));
	}
	while (underground_.findHoleAtPosition(nut_.getX(), nut_.getY()) || nut_.isAtPosition(snake_.getX(), snake_.getY()) || snake_.getTailPosition(nut_.getX(), nut_.getY()) ||
		((nut_.getX() == 1) || (nut_.getX() == GRIDSIZE)) || ((nut_.getY() == 1) || (nut_.getY() == GRIDSIZE)))
	{
		nut_.resetPosition(srng_.getRandomValue(GRIDSIZE), srng_.getRandomValue(GRIDSIZE));
	}
	cheatMode_ = false;
	do {
		Interface::drawGridOnScreen(prepareGrid());
		Interface::showResultsOnScreen(prepareScorebar());
		int key_ = Interface::getKeyPressFromUser();
		while (!hasEnded(key_))
		{
			if (key_ == 'S'){
				saveGame();
				Interface::showResultsOnScreen(prepareSaveStatus());
			}
			if (key_ == 'L'){
				loadGame();
				if (fileExists_)
					Interface::showResultsOnScreen(prepareLoadStatus());
				else
					Interface::showResultsOnScreen(prepareErrorMessage());
				Interface::drawGridOnScreen(prepareGrid());
				Interface::showResultsOnScreen(prepareScorebar());
			}
			if (key_ == 'C'){
				if (!cheatMode_){
					cheatMode_ = true;
					Interface::showResultsOnScreen(prepareCheatMode());
				}
				else
					cheatMode_ = false;
			}
			if (isArrowKeyCode(key_))
			{
				mouse_.scamper(key_);
				if ((!cheatMode_) && (!snake_.isStuck()))
					snake_.chaseMouse();
				Interface::drawGridOnScreen(prepareGrid());
				Interface::showResultsOnScreen(prepareScorebar());
				if (cheatMode_)
					Interface::showResultsOnScreen(prepareCheatMode());
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
	for (int row(1); row <= GRIDSIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= GRIDSIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.getY()) && (col == snake_.getX()))
				os << snake_.getSymbol();	//show snake
			else
				if (snake_.getTailPosition(col, row))
					os << snake_.getTailSymbol();
				else
					if (underground_.findHoleAtPosition(col, row) != 0)
						os << underground_.getHoleSymbol();	//show hole
					else
						if ((row == mouse_.getY()) && (col == mouse_.getX()))
							os << mouse_.getSymbol();	//show mouse
						else
							if (((row == nut_.getY()) && (col == nut_.getX())) && !nut_.hasBeenCollected())
								os << nut_.getSymbol(); //show nut
							else
								os << FREECELL;	//show free grid cell
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepareGrid
bool SnakeAndMouseGame::isArrowKeyCode(const int& keycode) const {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
void SnakeAndMouseGame::applyRules(){
	if (mouse_.canCollectNut(nut_) && underground_.findHoleAtPosition(nut_.getX(), nut_.getY()))
		nut_.disappear();
	else {
		if (snake_.hasCaughtMouse()){
			p_player_->updateScoreAmount(-1);
			mouse_.die();
		}
		else {
			if (mouse_.hasReachedAHole(underground_)){
				if (nut_.hasBeenCollected()){
					p_player_->updateScoreAmount(1);
					mouse_.escapeIntoHole();
				}
				else{
					int exitX, exitY;
					do
					{
						underground_.getExitHolePosition(srng_.getRandomValue(3), exitX, exitY);
					} while (exitX == mouse_.getX() && exitY == mouse_.getY());
					mouse_.resetPosition(exitX, exitY);
				}
			}
		}
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
ostream& SnakeAndMouseGame::toStream(ostream& os) const {
	os << mouse_.getX() << " " << mouse_.getY() << "\n"; //send mouse’s position to stream
	os << snake_.getX() << " " << snake_.getY() << "\n"; //send snake’s position to stream
	for (unsigned int i = 0; i < 3; i++) //send tail’s position to stream
	{
		int x, y;
		snake_.saveTailPosition(i, x, y);
		os << x << " " << y << "\n";
	}
	os << nut_.getX() << " " << nut_.getY() << "\n"; //send nut's position to stream
	os << nut_.hasBeenCollected() << "\n"; //send nut collected value to stream
	os << cheatModeEnabled() << "\n"; //send cheat mode value to stream
	os << p_player_->getScoreAmount() << "\n"; //send player score to stream
	return os;
}
istream& SnakeAndMouseGame::fromStream(istream& is) {
	int x, y;
	is >> x >> y;                   //read mouse’s position from stream
	mouse_.resetPosition(x, y);             //update mouse’s position
	is >> x >> y;                   //read snake’s position from stream
	snake_.resetPosition(x, y);             //update snake’s position
	for (unsigned int i = 0; i < 3; i++){
		is >> x >> y;
		snake_.loadTailPosition(i, x, y);
	}
	is >> x >> y;
	nut_.resetPosition(x, y);
	is >> x;
	(x == 1) ? nut_.disappear() : nut_.reset();
	is >> x;
	(x == 1) ? cheatMode_ = true : cheatMode_ = false;
	is >> x;
	p_player_->updateScoreAmount(x);
	return is;
}
ostream& operator<<(ostream& os, const SnakeAndMouseGame& rhs) {
	return (rhs.toStream(os));     //call support function to serialise game data in stream
}
istream& operator>>(istream& is, SnakeAndMouseGame& rhs) {
	return (rhs.fromStream(is));   //call support function to recover game data from stream
}
void SnakeAndMouseGame::reset(){
	nut_.reset();
	mouse_.reset();
	snake_.reset();
	cheatMode_ = false;
}
string SnakeAndMouseGame::prepareSaveStatus() const{
	ostringstream os;
	os << "\n GAME SAVED!";
	return os.str();
}
string SnakeAndMouseGame::prepareLoadStatus() const{
	ostringstream os;
	os << "\n GAME LOADED!";
	return os.str();
}
string SnakeAndMouseGame::prepareScorebar() const{
	ostringstream os;
	os << "NAME: " << p_player_->getName() << "\tSCORE: " << p_player_->getScoreAmount();
	return os.str();
}
string SnakeAndMouseGame::prepareCheatMode() const{
	ostringstream os;
	os << "\nCHEAT MODE ACTIVATED!";
	return os.str();
}
string SnakeAndMouseGame::prepareErrorMessage() const{
	ostringstream os;
	os << "\n ERROR: NO FILE FOUND!";
	return os.str();
}
bool SnakeAndMouseGame::cheatModeEnabled() const{
	return cheatMode_;
}
void SnakeAndMouseGame::saveGame(){
	ofstream file(p_player_->getName() + ".txt");
	if (file.is_open())
	{
		toStream(file);
		file.close();
	}
}
void SnakeAndMouseGame::loadGame(){
	ifstream file(p_player_->getName() + ".txt");
	if (file.is_open())
	{
		fromStream(file);
		file.close();
		fileExists_ = true;
	}
	else{
		fileExists_ = false;
	}
}
void SnakeAndMouseGame::setPlayer(Player* p_player){
	p_player_ = p_player;
}
const RandomNumberGenerator SnakeAndMouseGame::srng_;