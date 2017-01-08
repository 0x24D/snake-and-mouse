// Mouse.h: interface for the Mouse class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 29/11		Mark		int mouseDX_; and int mouseDY_; have are declared as local to scamper(), because they are only used there
//
//---------------------------------------------------------------------
#if !defined(MouseH)
#define MouseH
#include "Underground.h"
#include "Nut.h"
#include "MoveableGridItem.h"
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
	private:
		//data members
		bool alive_;
		bool escaped_;
		//supporting functions 
		void positionInMiddleOfGrid();
};
#endif // !defined(MouseH)