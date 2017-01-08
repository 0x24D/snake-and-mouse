#if !defined(SnakeAndMouseGameH)
#define SnakeAndMouseGameH
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
#include <fstream>
#include "Interface.h"
#include "Snake.h"
#include "Player.h"
class SnakeAndMouseGame
{
public:
	SnakeAndMouseGame();
	void run();
	string prepareGrid();
	bool isArrowKeyCode(const int& keycode) const;
	void applyRules();
	bool hasEnded(const char& key) const;
	string prepareEndMessage() const;
	void reset();
	ostream& toStream(ostream& os) const;        //to support the definition of the <<operator
	istream& fromStream(istream& is);     //to support the definition of the >>operator
	void setPlayer(Player* p_player);
private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	Nut nut_;
	string game_;
	Player* p_player_;
	const static RandomNumberGenerator srng_;
	bool cheatMode_;
	bool fileExists_;
	string prepareScorebar() const;
	string prepareCheatMode() const;
	string prepareSaveStatus() const;
	string prepareLoadStatus() const;
	string prepareErrorMessage() const;
	bool cheatModeEnabled() const;
	void saveGame();
	void loadGame();
	
};
ostream& operator<<(ostream&, SnakeAndMouseGame&);
istream& operator>>(istream&, SnakeAndMouseGame&);
#endif