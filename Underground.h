// Underground.h: interface for the Underground class 
//////////////////////////////////////////////////////////////////////

#if !defined(UndergroundH)
#define UndergroundH
#include <cassert>
#include "constants.h"
#include "Hole.h"
class Underground {
public:
	Underground::Underground();
	Hole getHoleNo(const int& no) const;
	void setHoleNoAtPosition(const int& no, const int& x, const int& y) const;
	bool isValidHoleNumber(const int& n) const;
	int findHoleNumberAtPosition(const int& x, const int& y)const;
	char getHoleSymbol()const;
private: 
	const Hole hole1_, hole2_, hole3_;
};
#endif // !defined(UndergroundH) 