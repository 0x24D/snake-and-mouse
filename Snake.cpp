// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
#include "Snake.h"
Snake::Snake() : MoveableGridItem(SNAKEHEAD, srng_.getRandomValue(SIZE), srng_.getRandomValue(SIZE)) {
	p_mouse_ = nullptr;
	for (int i = 0; i < 3; i++){
		tail.push_back(Tail(getX(), getY()));
	}
}
bool Snake::hasCaughtMouse()const {
	assert(p_mouse_ != 0);  //Pre-condition: The snake needs to know where the mouse is 
	return isAtPosition(p_mouse_->getX(), p_mouse_->getY());
}
void Snake::spotMouse(Mouse* p_mouse)
{
	p_mouse_ = p_mouse;
}
void Snake::chaseMouse(){	 
	int snakeDX, snakeDY;
	//identify direction of travel
	setDirection(snakeDX, snakeDY);
	//go in that direction
	moveTail();
	updatePosition(snakeDX, snakeDY);
	
}
void Snake::setDirection(int& dx, int& dy) const
{
	assert(p_mouse_ != 0);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (getX() < p_mouse_->getX())             //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (getX() > p_mouse_->getX())         //if snake on left of mouse
			dx = -1;                     //snake should move left
	if (getY() < p_mouse_->getY())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (getY() > p_mouse_->getY())         //if snake is below mouse
			dy = -1;                     //snake should move up
}
void Snake::moveTail()
{
	for (unsigned int i = tail.size() - 1; i > 0; i--)
	{
		tail[i].resetPosition(tail[i - 1].getX(), tail[i - 1].getY());
	}
	tail[0].resetPosition(getX(), getY());
}
char Snake::getTailSymbol() const
{
	for (unsigned int i = 0; i < tail.size(); i++)
	{
		return tail[i].getSymbol();
	}
}
bool Snake::getTailPosition(const int& x, const int& y) const{
	for (unsigned int i = 0; i < tail.size(); i++)
	{
		if ((tail[i].getX() == x) && (tail[i].getY() == y))
			return true;
	}
	return false;
}
const RandomNumberGenerator Snake::srng_;
RandomNumberGenerator Snake::getRNG() const{return srng_;}
void Snake::reset(){
	resetPosition(srng_.getRandomValue(SIZE), srng_.getRandomValue(SIZE));
	for (int i = 0; i < tail.size(); i++)
		tail[i].resetPosition(getX(), getY());
}