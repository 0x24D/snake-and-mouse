#include "FixedGridItem.h"
FixedGridItem::FixedGridItem(const char& symbol, const int& x, const int& y) : GridItem(symbol), x_(x), y_(y) {}
int FixedGridItem::getX() const {
	return x_;
}
int FixedGridItem::getY() const {
	return y_;
}
bool FixedGridItem::isAtPosition(const int& x, const int& y) const {
	return (x_ == x) && (y_ == y);
}