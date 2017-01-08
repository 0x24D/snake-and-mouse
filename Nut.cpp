#include "Nut.h"
Nut::Nut(int x, int y) : MoveableGridItem(NUT, x, y), collected_(false) {}
bool Nut::hasBeenCollected() const{
	return collected_;
}
void Nut::disappear(){
	collected_ = true;
}
void Nut::reset(){
	collected_ = false;
}
