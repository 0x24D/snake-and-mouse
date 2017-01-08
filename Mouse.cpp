// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////
#include "Mouse.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Mouse::Mouse() : MoveableGridItem(MOUSE, (SIZE/2), (SIZE/2)), alive_(true), escaped_(false){}
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
	for (int i(1); i <= 3; ++i)
	{
		if (ug.findHoleNumberAtPosition(getX(), getY()))
			return true;
	}
	return false;
}
bool Mouse::canCollectNut(const Nut& n) const {
	if (!(n.hasBeenCollected()) && (isAtPosition(n.getX(), n.getY())))
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
	int mouseDX;
	int mouseDY;
	switch(k)               //...depending on the selected key...
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
	//update mouse coordinates if move is possible
	if (((getX() + mouseDX) >= 1) && ((getX() + mouseDX) <= SIZE) &&
		 ((getY() + mouseDY) >= 1) && ((getY() + mouseDY) <= SIZE) )
	{
		updatePosition(mouseDX, mouseDY);		//go in that direction
	}
}
//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////
void Mouse::positionInMiddleOfGrid(){
	resetPosition((SIZE / 2), (SIZE / 2));
}
