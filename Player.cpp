
#include "Player.h"
Player::Player(): name_(Interface::getUserName()){}
string Player::getName() const{
	return name_;
}
int Player::getScoreAmount() const{
	return score_.getAmount();
}
void Player::updateScoreAmount(const int& amount){
	score_.updateAmount(amount);
}