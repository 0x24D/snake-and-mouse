#if !defined(MoveableGridItemH)
#define MoveableGridItemH 
#include "GridItem.h"
class MoveableGridItem : public GridItem {
public:
	MoveableGridItem(const char& symbol, const int& x, const int& y);
	int getX() const;
	int getY() const;
	bool isAtPosition(const int& x, const int& y) const;
	void resetPosition(const int& x, const int& y);
	void updatePosition(const int& dx, const int& dy);
private:
	int x_, y_;
};
#endif