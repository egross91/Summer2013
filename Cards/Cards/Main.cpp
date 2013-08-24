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
		if (selection == 'b' || selection == 'B') // BlackJack
		{
			cout << "Loading BlackJack..." << endl;
			BlackJack * game = new BlackJack();
			game->play();
			delete game; game = NULL;
		}
		else if (selection == 'p' || selection == 'P') // Poker
		{
			cout << "Loading Poker..." << endl;
			Poker * game = new Poker();
			game->play();
			delete game; game = NULL;
		}
		else if (selection == 't' || selection == 'T') // Texas Holdem
		{
			cout << "Under construction. . ." << endl << endl;
			cin.get();
		}
		else if (selection == 'q' || selection == 'Q') // Quit
			break;
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