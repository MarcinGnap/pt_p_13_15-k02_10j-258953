#include "mainWindow.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Starting..." << endl << endl;
	cout << "Press Enter to continue..." << endl;
	getchar();
	system("CLS");

	mainWindow noweOkno;	//Tworzenie obiektu obsługującego wzystkie struktury.

	noweOkno.mainMenu();	//Wywołanie metody głównego menu.

	return 0;
}