// Underground.h: interface for the Underground class 
//////////////////////////////////////////////////////////////////////

#if !defined(UndergroundH)
#define UndergroundH
#include <cassert>
#include "Hole.h"
class Underground {
public:
	Underground::Underground();
	bool findHoleAtPosition(const int& x, const int& y) const;
	char getHoleSymbol() const;
	void getExitHolePosition(const int& n, int& x, int& y) const;
private: 
	const Hole hole1_, hole2_, hole3_;
};
#endif // !defined(UndergroundH) 