#include "BlackJack.h"
#include "Poker.h"
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
			cout << "Loading BlackJack..." << endl;
			BlackJack * game = new BlackJack();
			game->play();
			delete game;
		}
		else if (selection == 'p' || selection == 'P')
		{
			cout << "Loading Poker..." << endl;
			Poker * game = new Poker();
			game->play();
			delete game;
		}
		else if (selection == 't' || selection == 'T')
		{
			cout << "Under construction. . ." << endl << endl;
			_getch();
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
	cout << "(T)exas Holdem" << endl;
	cout << "(Q)uit" << endl << endl;
}

char getSelection()
{
	char selection [10];
	cout << "Selection :  "; cin >> selection;
	return selection[0];
}