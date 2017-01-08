#if !defined(HoleH)
#define HoleH
#include "FixedGridItem.h"
class Hole : public FixedGridItem{
public:
	//constructors
	Hole(const char& symbol, const int& x, const int& y);
};
#endif