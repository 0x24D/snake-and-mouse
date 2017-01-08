// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////
#include "Mouse.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Mouse::Mouse() : MoveableGridItem(MOUSE, srng_.getRandomValue(GRIDSIZE), srng_.getRandomValue(GRIDSIZE)), alive_(true), escaped_(false), p_nut_(nullptr){}
//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////
bool Mouse::isAlive() const {
	return alive_;
}
void Mouse::reset(){
	alive_ = true;
	escaped_ = false;
	positionInMiddleOfGrid();
}
bool Mouse::hasEscaped() const {
	return escaped_;
}
bool Mouse::hasReachedAHole(const Underground& ug) const {
	if (ug.findHoleAtPosition(getX(), getY()))
		return true;
	else
		return false;
}
bool Mouse::canCollectNut(const Nut& n) const {
	if (!(n.hasBeenCollected()))
		return true;
	else
		return false;
}
void Mouse::die()
{
	alive_ = false;
}
void Mouse::escapeIntoHole()
{
	escaped_ = true;
}
void Mouse::scamper(const char& k) { //move mouse in required direction
	//pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	int mouseDX, mouseDY, nutDX, nutDY;;
	switch (k)               //...depending on the selected key...
	{
	case LEFT:           //when LEFT arrow pressed...
		mouseDX = -1;    //decrease the X coordinate
		mouseDY = 0;
		break;
	case RIGHT:          //when RIGHT arrow pressed...
		mouseDX = +1;    //increase the X coordinate
		mouseDY = 0;
		break;
	case UP:             //when UP arrow pressed...
		mouseDX = 0;
		mouseDY = -1;    //decrease the Y coordinate
		break;
	case DOWN:           //when DOWN arrow pressed...
		mouseDX = 0;
		mouseDY = +1;    //increase the Y coordinate
		break;
	}
	nutDX = mouseDX;
	nutDY = mouseDY;
	//update mouse coordinates if move is possible
	if (((getX() + mouseDX) >= 1) && ((getX() + mouseDX) <= GRIDSIZE) &&
		((getY() + mouseDY) >= 1) && ((getY() + mouseDY) <= GRIDSIZE))
	{
		if (((p_nut_->getX() + mouseDX) > 1) && ((p_nut_->getX() + mouseDX) < GRIDSIZE) &&
			((p_nut_->getY() + mouseDY) > 1) && ((p_nut_->getY() + mouseDY) < GRIDSIZE)){
			if (k == UP && p_nut_->getX() == getX() && p_nut_->getY() == (getY() - 1))
				p_nut_->updatePosition(nutDX, nutDY);		//go in that direction
			else if (k == DOWN && p_nut_->getX() == getX() && p_nut_->getY() == (getY() + 1))
				p_nut_->updatePosition(nutDX, nutDY);		//go in that direction
			else if (k == LEFT && p_nut_->getX() == (getX() - 1) && p_nut_->getY() == getY())
				p_nut_->updatePosition(nutDX, nutDY);		//go in that direction
			else if (k == RIGHT && p_nut_->getX() == (getX() + 1) && p_nut_->getY() == getY())
				p_nut_->updatePosition(nutDX, nutDY);		//go in that direction
		}
		if ((k == UP && p_nut_->getX() == getX() && p_nut_->getY() == 2 && getY() == 3) ||
			(k == DOWN && p_nut_->getX() == getX() && p_nut_->getY() == (GRIDSIZE - 1) && getY() == (GRIDSIZE - 2)) ||
			(k == LEFT && p_nut_->getY() == getY() && p_nut_->getX() == 2 && getX() == 3) ||
			(k == RIGHT && p_nut_->getY() == getY() && p_nut_->getX() == (GRIDSIZE - 1) && getX() == (GRIDSIZE - 2)))
			updatePosition(0, 0);		//do not move
		else
			updatePosition(mouseDX, mouseDY);		//go in that direction
	}
}
void Mouse::spotNut(Nut* p_nut)
{
	p_nut_ = p_nut;
}
//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////
void Mouse::positionInMiddleOfGrid(){
	resetPosition(srng_.getRandomValue(GRIDSIZE), srng_.getRandomValue(GRIDSIZE));
}

const RandomNumberGenerator Mouse::srng_;