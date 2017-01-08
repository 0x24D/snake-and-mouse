// Snake.h: interface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(TailH)
#define TailH
#include "constants.h"
#include "MoveableGridItem.h"
class Tail : public MoveableGridItem{
public:
	Tail(const int& x, const int& y);
};
#endif // !defined(TailH)