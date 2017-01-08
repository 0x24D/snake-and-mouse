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
string Interface::getUserName(){
	string name;
	cout << "Please enter your name: ";
	getline(cin,name);
	return name;
}