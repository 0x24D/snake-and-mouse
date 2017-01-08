// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
#include "Snake.h"
Snake::Snake() : MoveableGridItem(SNAKEHEAD, GRIDSIZE/2, GRIDSIZE/2), p_mouse_(nullptr), stuck_(false) {
	for (int i = 0; i < 3; i++){
		tail_.push_back(Tail(getX(), getY()));
	}
}
bool Snake::hasCaughtMouse() const{
	assert(p_mouse_ != 0);  //Pre-condition: The snake needs to know where the mouse is 
	return isAtPosition(p_mouse_->getX(), p_mouse_->getY());
}
void Snake::spotMouse(Mouse* p_mouse){
	p_mouse_ = p_mouse;
}
void Snake::chaseMouse(){	 
	int snakeDX, snakeDY;
	//identify direction of travel
	setDirection(snakeDX, snakeDY);
	//go in that direction
	moveTail();
	updatePosition(snakeDX, snakeDY);
	if (getTailPosition(getX(), getY()))
		stuck_ = true;
}
void Snake::setDirection(int& dx, int& dy) const{
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
void Snake::moveTail(){
	for (unsigned int i = tail_.size() - 1; i > 0; i--)
	{
		tail_[i].resetPosition(tail_[i - 1].getX(), tail_[i - 1].getY());
	}
	tail_[0].resetPosition(getX(), getY());
}
char Snake::getTailSymbol() const{
	for (unsigned int i = 0; i < tail_.size(); i++)
	{
		return tail_[i].getSymbol();
	}
}
bool Snake::getTailPosition(const int& x, const int& y) const{
	for (unsigned int i = 0; i < tail_.size(); i++)
	{
		if ((tail_[i].getX() == x) && (tail_[i].getY() == y))
			return true;
	}
	return false;
}
void Snake::saveTailPosition(const int& n, int& x, int& y) const{
	x = tail_[n].getX();
	y = tail_[n].getY();
}
void Snake::loadTailPosition(const int& n, int& x, int& y) const{
	x = tail_[n].getX();
	y = tail_[n].getY();
}
void Snake::reset(){
	stuck_ = false;
	resetPosition(GRIDSIZE/2, GRIDSIZE/2);
	for (unsigned int i = 0; i < tail_.size(); i++){
		tail_[i].resetPosition(getX(), getY());
	}
}
bool Snake::isStuck() const{
	if (stuck_)
		return true;
	else
		return false;
}