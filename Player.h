#if !defined(playerH)
#define playerH
#include <iostream>		//for output and input
#include <string>		//for string
#include "Score.h"
#include "Interface.h"
using namespace std;
class Player{
public:
	Player();
	string getName() const;
	int getScoreAmount() const;
	void updateScoreAmount(const int& amount);
private:
	const string name_;
	Score score_;
};
#endif