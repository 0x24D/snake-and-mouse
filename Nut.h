#if !defined(NutH)
#define NutH
#include "constants.h"
#include "MoveableGridItem.h"
class Nut : public MoveableGridItem {
public:
	//constructor
	Nut(int x, int y);
	//assessors
	bool hasBeenCollected() const;
	void disappear();
	void reset();
private:
	bool collected_;
};

#endif