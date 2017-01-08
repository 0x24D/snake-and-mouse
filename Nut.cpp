#include "Nut.h"
Nut::Nut() : MoveableGridItem(NUT, 8, 9){ collected_ = false; };

bool Nut::hasBeenCollected() const{
	return collected_;
}
void Nut::disappear(){
	collected_ = true;
}
void Nut::reset(){
	collected_ = false;
}