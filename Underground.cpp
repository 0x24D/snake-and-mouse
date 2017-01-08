// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////
Underground::Underground() : hole1_(HOLE, 4, 3), hole2_(HOLE, 15, 10), hole3_(HOLE, 7, 15) {}
Hole Underground::getHoleNo(const int& no) const {
	assert(isValidHoleNumber(no));	//precondition: valid hole number
	switch (no) {
	case 1: return hole1_; break;
	case 2: return hole2_; break;
	case 3: return hole3_;
	}
}
bool Underground::isValidHoleNumber(const int& no) const {
	return (no >= 1) && (no <= 3); 
}
int Underground::findHoleNumberAtPosition(const int& x, const int& y)  const{
	for (int hNo(1); hNo <= 3; ++hNo)
		if (getHoleNo(hNo).isAtPosition(x, y))
			return hNo;		//number of the hole
	return 0;	
}
char Underground::getHoleSymbol() const{
	return HOLE;
}