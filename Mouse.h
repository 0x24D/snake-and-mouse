// Mouse.h: interface for the Mouse class
//////////////////////////////////////////////////////////////////////

#if !defined(MouseH)
#define MouseH
#include "Underground.h"
#include "Nut.h"
#include "MoveableGridItem.h"
#include "RandomNumberGenerator.h"
class Mouse : public MoveableGridItem{
	public:
		//constructor
		Mouse();
		//assessors
		bool isAlive() const;
		bool hasEscaped() const;
		bool hasReachedAHole(const Underground& ug) const;
		bool canCollectNut(const Nut& n) const;
		//mutators
		void die();
		void escapeIntoHole();
		void scamper(const char& k);
		void reset();
		void setDirection(int& dx, int& dy) const;
		void pushNut();
		void spotNut(Nut* p_nut);
	private:
		//data members
		bool alive_;
		bool escaped_;
		//supporting functions 
		void positionInMiddleOfGrid();
		const static RandomNumberGenerator srng_;
		Nut* p_nut_;
};
#endif // !defined(MouseH)