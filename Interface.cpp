#include "Interface.h" 
int Interface::getKeyPressFromUser(){
//get key or command selected by user
	//read in the selected arrow key or command letter
	int keyPressed(_getch());
	//ignore symbol following cursor key
	while (keyPressed == 224) 
		keyPressed = _getch();
	//return the key in uppercase
	return(toupper(keyPressed));
}
void Interface::drawGridOnScreen(const string& gridData){
	system("cls"); //clear screen
	cout << gridData;
}
void Interface::showResultsOnScreen(const string& message){
	cout << message;
}
void Interface::holdWindow(){
	cout << "\n\n";
	system("pause");
}
string Interface::welcomeMessage(){
	string name;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo); //getting current colour
	wOldColorAttrs = csbiInfo.wAttributes;
	cout << "Hello there! \nWhat is your name? ";
	getline(cin, name);
	system("cls");
	cout << "Hello " << name << ", welcome to Snake and Mouse game! \n\nThe aim of the game is to evade a chasing snake and escape into a hole before \nyou are eaten.";
	_getch();
	cout << "\n\nBefore escaping you must also push a nut into one of the holes.";
	_getch();
	cout << "\n\nIf you try to escape into one of the holes before pushing the nut into one, you will reappear at a different hole. \nThe snake can get stuck on it's own tail if you reappear behind it and it turns around to chase you. ";
	_getch();
	cout << "\n\nIf you you are eaten by the snake before escaping into a hole, the game is over.";
	_getch();
	cout << "\n\nHere are the controls: ";
	SetConsoleTextAttribute(h, 14); //yellow
	cout << "\n\x18 \x19 \x1b \x1a"; //up down left and right arrows
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << " - control the mouse";
	SetConsoleTextAttribute(h, 14); //yellow
	cout << "\nS";
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << " - save the game";
	SetConsoleTextAttribute(h, 14); //yellow
	cout << "\nL";
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << " - load an already saved game";
	SetConsoleTextAttribute(h, 14); //yellow
	cout << "\nQ";
	SetConsoleTextAttribute(h, wOldColorAttrs);
	cout << " - quit the game at anytime";
	_getch();
	cout << "\n\n\n\nGood luck!";
	_getch();
	system("cls");
	SetConsoleTextAttribute(h, 8); // dark grey
	cout << "Psst... you can put the game in cheat mode and stop the snake from chasing you \nby pressing 'C'";
	SetConsoleTextAttribute(h, wOldColorAttrs);
	_getch();
	return name;
}