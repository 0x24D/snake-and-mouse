// RandomNumberGenerator.h: interface for the RandomNumberGenerator class
#if !defined(RandomNumberGeneratorH)
#define RandomNumberGeneratorH

#include <stdlib.h>	//for srand and rand routines
#include <cassert>	//for assert
#include <ctime>	//for time used in RandomNumberGenerator::seed routines
using namespace std;

class RandomNumberGenerator
{
	public:
		//constructors
		RandomNumberGenerator();
		//assessors
		int getRandomValue(const int& max) const;
	private:
		//supporting functions
		void seed();
};
#endif // !defined(RandomNumberGeneratorH)
