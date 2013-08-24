/********************************************************************
 ** This is a simple console application. You may play with a friend 
 ** or play against the Computer. As you notice, I put my funtions at the 
 ** top above my Main, but I did comment throughout the code to follow along. 
 ** I have the game in a turn based style using a while (true) loop. The game is built
 ** to perform checks after each move. I was told the 'goto' shouldn't be used,
 ** but you'll notice I used to a fair amount. They are labeled fairly well 
 ** (but I'm biased haha). If you have idea for cleaning up the code and making it
 ** run more efficient, that would be much appreciated. I will say this is one of
 ** my more favorite projects next to the MaskingPractice one. I'm really trying to 
 ** compile a really difficult algorithm going for the ComputerAI player. So far
 ** it's programmed to find every lose-situation before it checks for a 
 ** win-situation.
*********************************************************************/
#include "ComputerAI.h"
#include "Board.h"
#include <iostream>
#include <conio.h>

using std::cout; using std::cin; using std::endl;

// ----------- MENU ------------- Print the Menu.
void menu()
{
	cout << "******* TIC-TAC-TOE ********" << endl;
	cout << "(P)lay w/ Friend" << endl;
	cout << "(C)omputer Challenge" << endl;
	cout << "(Q)uit" << endl << endl;
}

// ------------ WIN ---------------- Checks to see if anyone won a game.
bool win(char pieces[])
{ 
	if (((pieces[0] == pieces[1] && pieces[1] == pieces[2]) && pieces[0] != 1) || // First Row
		((pieces[3] == pieces[4] && pieces[4] == pieces[5]) && pieces[3] != 1) || // Second Row
		((pieces[6] == pieces[7] && pieces[7] == pieces[8]) && pieces[6] != 1) || // Third Row
		((pieces[0] == pieces[3] && pieces[3] == pieces[6]) && pieces[0] != 1) || // First Col
		((pieces[1] == pieces[4] && pieces[4] == pieces[7]) && pieces[1] != 1) || // Second Col
		((pieces[2] == pieces[5] && pieces[5] == pieces[8]) && pieces[2] != 1) || // Third Col
		((pieces[0] == pieces[4] && pieces[4] == pieces[8]) && pieces[0] != 1) || // \ diagonal
		((pieces[2] == pieces[4] && pieces[4] == pieces[6]) && pieces[2] != 1))   // / diagonal
	{
		return true;
	}
	else
		return false;
}

// ---------- FULL -------------- Checks to see if the board is full.
bool full(char pieces[9])
{
	int empties = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (pieces[i] == 1)
			return false;	
	}
	return true;
}

// ----------- PLAYAGAIN ---------- Ask the players if they would like to play again.
bool playAgain()
{
	while (true)
	{
		char s;
		cout << "Would you like to play again? (Y/N):  "; cin >> s;
		if (s == 'y' || s == 'Y')
			return true;
	
		else if (s == 'n' || s == 'N')
			return false;
	
		else
			cout << "Please choose Y or N." << endl << endl;
	}
}

// ---------- PLAYWITHFRIEND --------- Play against your friend.
void playWithFriend()
{
	// Create Player's Name.
	std::string name1, name2;
	cout << "Player's 1 Name (X) :  "; cin.ignore();
	std::getline(cin, name1);
	cout << "Player's 2 Name (O) :  ";
	std::getline(cin, name2);
		
	// Create the Boards.
	Board * gameBoard = new Board();
	Player pl1(name1);
	Player pl2(name2);

	// If the Players decide to play again, empty the board.
	GAME:
	// Board Pieces.
	char playPieces [9];
	// Fill the board with empty spaces.
	for (int i = 0; i < 9; ++i)
			playPieces[i] = 1;
	
	cout << endl;
	while (true)
	{
		// Player's 1 Turn. Goto here.
		PLAYER1:
		// Where the play with put their piece.
		int block;
		cout << "***** " << pl1.getName() << "'s Move *****" << endl;
		cout << "Block :  "; cin >> block;
		--block;
	
		// Check to see if the block is playable and within bounds.
		if (playPieces[block] == 1 && (block < 9 && block >= 0))
			playPieces[block] = 'X';
		
		// Make them choose again if not.
		else
		{
			cout << "Please make another selection." << endl << endl;
			goto PLAYER1;
		}
		// Print the board after block selection.
		gameBoard->printBoard(playPieces);
		if (win(playPieces))
		{
			cout << pl1.getName() << " WINS!!!" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
		else if (!win(playPieces) && full(playPieces))
		{
			cout << "AHHHHH!!! Cat's game! :(" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
		// Player 2's Turn.
		PLAYER2:
		// So they can't just hit enter with a left over value of block.
		block = -1;
		cout << "***** " << pl2.getName() << "'s Move *****" << endl;
		cout << "Block :  "; cin >> block;
		--block;
		// Play if it's a valid spot.
		if (playPieces[block] == 1 && (block < 9 && block >= 0))
			playPieces[block] = 'O';
		
		// Make them re-try if not.
		else
		{
			cout << "Please make another selection." << endl << endl;
			goto PLAYER2;
		}
		// Print game.
		gameBoard->printBoard(playPieces);
		// Check for win, and ask to play again.
		if (win(playPieces))
		{
			cout << pl2.getName() << " WINS!!!" << endl << endl;
			// If they want to play again, then go back to the beginning of the game with an "empty" board.
			if (playAgain())
				goto GAME;
			
			// Break to Menu if they do not want to play again.
			break;
		}
		// If there is not a win and the board is full, it's a cat's game.
		else if (!win(playPieces) && full(playPieces))
		{
			cout << "AHHHHH!!! Cat's game! :(" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
	}
	// End game.
	delete gameBoard;
}

// ---------- PLAYCOMPUTER -------- Play against the AI.
void playComputer()
{
	// Create Player's Name.
	std::string name1, name2;
	cout << "Player's Name (X) :  "; cin.ignore();
	std::getline(cin, name1);
	cout << "Computer's Name (O) :  ";
	std::getline(cin, name2);
		
	// Create the Boards.
	Board * gameBoard = new Board();
	Player pl1(name1);
	ComputerAI compAI(name2);

	// If the Players decide to play again, empty the board.
	// Fill the board with empty spaces.
	GAME:
	// Board Pieces.
	char playPieces [9];
	for (int i = 0; i < 9; ++i)
	{
		playPieces[i] = 1;
	}
	cout << endl;
	while (true)
	{
		// Player's 1 Turn.
		PLAYER1:
		// Where the play with put their piece.
		int block;
		cout << "***** Player's Move *****" << endl;
		cout << "Block :  "; cin >> block;
		--block;
		if (playPieces[block] == 1 && (block < 9 && block >= 0))
			playPieces[block] = 'X';
		else
		{
			cout << "Please make another selection." << endl << endl;
			goto PLAYER1;
		}
		gameBoard->printBoard(playPieces);
		if (win(playPieces))
		{
			cout << pl1.getName() << " WINS!!!" << endl << endl;
			if (playAgain())
				goto GAME;

			break;
		}
		else if (!win(playPieces) && full(playPieces))
		{
			cout << "AHHHHH!!! Cat's game! :(" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
		cout << "Enter to Continue." << endl << endl;
		_getch();
		// Computer's Turn.
		cout << "***** Computer's Move *****" << endl;
		// Call the function for the ComputerAI to make it's selection.
		block = compAI.makeMove(playPieces, std::vector<int>(NULL));
		// Create it's game piece.
		playPieces[block] = 'O';
		// Print the current game.
		gameBoard->printBoard(playPieces);
		// Checks for wins and losses and play agains.
		if (win(playPieces))
		{
			cout << compAI.getName() << " WINS!!!" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
		else if (!win(playPieces) && full(playPieces))
		{
			cout << "AHHHHH!!! Cat's game! :(" << endl << endl;
			if (playAgain())
				goto GAME;
			
			break;
		}
	}
	// End game.
	delete gameBoard;
}

// ---------- MAIN ----------- Do stoof and run the game.
int main(int argc, char * argv[])
{
	while (true)
	{
		char selection;
		menu();
		cout << "Selection :  "; cin >> selection;
		cout << endl;

		if (selection == 'p' || selection == 'P')
		{
			playWithFriend();
		}
		else if (selection == 'c' || selection == 'C')
		{
			playComputer();
		}
		else if (selection == 'q' || selection == 'Q')
		{
			break;
		}	
		else
		{
			cout << "You can only play or quit." << endl << endl;
		}
	}
	cout << "Thanks for playing, and happy coding!";
	_getch();
	return 0;
}