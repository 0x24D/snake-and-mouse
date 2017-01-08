#include "MoveableGridItem.h"
MoveableGridItem::MoveableGridItem(const char& symbol, const int& x, const int& y) : GridItem(symbol), x_(x), y_(y) {}
int MoveableGridItem::getX() const {
	return x_;
}
int MoveableGridItem::getY() const {
	return y_;
}
bool MoveableGridItem::isAtPosition(const int& x, const int& y) const {
	return (x_ == x) && (y_ == y);
}
void MoveableGridItem::resetPosition(const int& x, const int& y){
	x_ = x;
	y_ = y;
}
void MoveableGridItem::updatePosition(const int& dx, const int& dy){
	x_ += dx;
	y_ += dy;
}