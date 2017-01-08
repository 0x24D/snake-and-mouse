// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////
#include "Underground.h"
//////////////////////////////////////////////////////////////////////
Underground::Underground() : hole1_(4, 3), hole2_(15, 10), hole3_(7, 15) {}
bool Underground::findHoleAtPosition(const int& x, const int& y)  const {
	if ((hole1_.getX() == x && hole1_.getY() == y) || (hole2_.getX() == x && hole2_.getY() == y) || (hole3_.getX() == x && hole3_.getY() == y))
		return true;
	return false;
}
char Underground::getHoleSymbol() const{
	return hole1_.getSymbol();
}
void Underground::getExitHolePosition(const int& n, int& x, int& y) const {
	if (n == 1){
		x = hole1_.getX();
		y = hole1_.getY();
	}
	else if (n == 2){
		x = hole2_.getX();
		y = hole2_.getY();
	}
	else if (n == 3){
		x = hole3_.getX();
		y = hole3_.getY();
	}
}