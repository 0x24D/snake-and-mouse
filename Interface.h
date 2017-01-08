// Interface.h: interface for the Interface class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------
#if !defined(InterfaceH)
#define InterfaceH
//include standard libraries
#include <iostream>		//for output and input: cout << and cin >>
#include <string>		//for string
#include <conio.h>		//for _getch() -- moved from .cpp file
using namespace std;
class Interface{
	public:
		static int getKeyPressFromUser();
		static void drawGridOnScreen(const string& gridData);
		static void showResultsOnScreen(const string& message);
		static void holdWindow();
		static string getUserName();
};
#endif // !defined(InterfaceH)