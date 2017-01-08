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
	void setUp();
	void run();
	string prepareGrid();
	bool isArrowKeyCode(const int& keycode)const;
	void applyRules();
	int findHoleNumberAtPosition(const int& x, const int& y)const;
	bool hasEnded(const char& key)const;
	string prepareEndMessage()const;
	int getKey() const;
	friend ofstream& operator <<(ofstream& fout, const string& game_);
	friend ifstream& operator >>(ifstream& fin, const string& game_);
	void reset();
private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	int key_;
	Nut nut_;
	string game_;
	RandomNumberGenerator rng_;
	Player player_;
	string prepareScorebar()const;
	vector<Tail> tail_;
};

#endif