#if !defined(FixedGridItemH)
#define FixedGridItemH 
#include "GridItem.h"
class FixedGridItem : public GridItem {
public:
	FixedGridItem(const char& symbol, const int& x, const int& y);
	int getX() const;
	int getY() const;
	bool isAtPosition(const int& x, const int& y) const;
private:
	const int x_, y_;
};
#endif