// Snake.h: interface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "RandomNumberGenerator.h"
#include "Mouse.h"
#include <vector>
#include "Tail.h"

class Snake : public MoveableGridItem {
	public:
		Snake();
		bool hasCaughtMouse()const;
		void spotMouse(Mouse* p_mouse);
		void chaseMouse();
		void setDirection( int& dx,  int& dy)const;
		RandomNumberGenerator getRNG() const;
		char getTailSymbol() const;
		void moveTail();
		bool getTailPosition(const int& x, const int& y)const;
		void reset();
	private:
		Mouse* p_mouse_;
		const static RandomNumberGenerator srng_;
		vector<Tail> tail;
		void positionAtRandom();
};      
#endif // !defined(SnakeH)
