#include "Board.h"
#include <iostream>

using namespace std;

void Board::printBoard(char piece[9])
{
	cout << endl;
	cout << "        |          |              " << endl;
	cout << "  " << piece[0] << "     |     " << piece[1] << "    |    " << piece[2] << "        " << endl;
	cout << "        |          |              " << endl;
	cout << "----------------------------" << endl;
	cout << "        |          |              " << endl;
	cout << "  " << piece[3] << "     |     " << piece[4] << "    |    " << piece[5] << "        " << endl;
	cout << "        |          |              " << endl;
	cout << "----------------------------" << endl;
	cout << "        |          |              " << endl;
	cout << "  " << piece[6] << "     |     " << piece[7] << "    |    " << piece[8] << "        " << endl;
	cout << "        |          |              " << endl;
}