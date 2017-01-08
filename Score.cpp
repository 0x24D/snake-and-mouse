#include "Score.h"
Score::Score(): amount_(0) {}
int Score::getAmount() const
{
	return amount_;
}
void Score::updateAmount(const int& amount)
{
	amount_ += amount;
}