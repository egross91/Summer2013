#include "BlackJack.h"
#include <iostream>
#include <conio.h>

using namespace std;

void menu();
char getSelection();

int main(int argc, char * argv[])
{
	char selection;
	while (true)
	{
		menu();
		selection = getSelection();
		if (selection == 'b' || selection == 'B')
		{
			BlackJack * game = new BlackJack();
			game->play();
			delete game;
		}
		else if (selection == 'p' || selection == 'P')
		{
			cout << "Under construction. . ." << endl << endl;
		}
		else if (selection == 'q' || selection == 'Q')
		{
			break;
		}
		else
			cout << "Please make a selection." << endl << endl;
	}
	cout << "Thanks for playing!" << endl;
	cout << "Happy Coding!" << endl;
	_getch();
	return 0;
}

void menu()
{
	cout << "***** Cards *****" << endl;
	cout << "(B)lackJack" << endl;
	cout << "(P)oker" << endl;
	cout << "(Q)uit" << endl << endl;
}

char getSelection()
{
	char selection [10];
	cout << "Selection :  "; cin >> selection;
	return selection[0];
}