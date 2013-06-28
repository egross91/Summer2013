#include "ComputerAI.h"

ComputerAI::ComputerAI(std::string name) : super(name)
{

}

/********************************************************************
//  Algorighthm for the AI to decide on what play to put on the board.
// This function just checks to make sure the spot is empty and playable. 
// The AI is designed to play very defensive, and allows for chances to win by making a non-win or lose
// situation a random placement. The key to winning is playing a heavy offense.
**********************************************************************/
bool ComputerAI::check(char board[], int index)
{
	if (board[index] == 1)
	{
		return true;
	}
	return false;
}
int ComputerAI::makeMove(char board[], std::vector<int> pMoves)
{
	/****************************************************************
	// Check to make sure the board is fresh and only played once.
	// If so, just pick a random number and pick play it.
	// If the spot is taken, then pick a new random play until one is suitable. 
	// Helps to do the catch here, rather than in the Main to save lines.
	*****************************************************************/
	srand((unsigned int)time(NULL)); // Cast once.
	int ran = 0;
	if (pMoves.size() == 1)
	{
		while (true)
		{
			ran = (rand()%10 - 1); // 0-9
			if (board[ran] == 1)
			{
				return ran;
			}
		}
	}
	// ********************* START DEFENSE ************************************
	// ************ If the first block is played by the Player. (0) **************
	if (board[0] == 'X')
	{
		if (board[1] == 'X') // Next to.
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
		if (board[2] == 'X')
		{
			if (check(board, 1))
			{
				return 1;
			}
		}
		if (board[3] == 'X') // Below.
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
		if (board[4] == 'X') // Right and down of.
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'X') // All the way diagonal of. 
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[6] == 'X') // Very below of.
		{
			if (check(board, 3)) // Make sure it hasn't already been played.
			{
				return 3;
			}
		}
	}

	// *********** If the 2 block is taken by the opponent. (1) ****************
	if (board[1] == 'X')
	{
		if (board[2] == 'X')
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
		if (board[4] == 'X') // Below.
		{
			if (check(board, 7))
			{
				return 7;
			}
		}
		if (board[7] == 'X') // All the way below.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
	}

	// *********** If the 3 block is taken by the opponent. (1) *****************
	if (board[2] == 'X')
	{
		if (board[4] == 'X') // Left 1 and down 1.
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
		if (board[5] == 'X') // Below.
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'X') // All the way below.
		{
			if (check(board, 5))
			{
				return 5;
			}
		}
		if (board[6] == 'X') // / Diagonal of.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
	}
	
	// ********* If the 4 block is taken by the opponent. (3) ************
	if (board[3] == 'X')
	{
		if (board[4] == 'X') // Next to.
		{
			if (check(board, 5))
			{
				return 5;
			}
		}
	    if (board[5] == 'X') // Other side of.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[6] == 'X') // Below.
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
	}
	// ************ If the 5 block is taken by the opponent. (4) ******************
	if (board[4] == 'X')
	{
		if (board[5] == 'X')
		{
			if (check(board, 3))
			{
				return 3;
			}
		}
		if (board[6] == 'X')
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
		if (board[7] == 'X')
		{
			if (check(board, 1))
			{
				return 1;
			}
		}
		if (board[8] == 'X')
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
	}
	// ********** If the 6 block was taken by the opponent. (5) *************
	if (board[5] == 'X')
	{
		if (board[8] == 'X')
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
	}
	// ********** If the 7 block is taken by the opponent. (6) ************
	if (board[6] == 'X')
	{
		if (board[7] == 'X')
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'X')
		{
			if (check(board, 7))
			{
				return 7;
			}
		}
	}
	// ************ If the 8 block is taken by the opponent. (7) *************
	if (board[7] == 'X')
	{
		if (board[8] == 'X')
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
	}
	if (board[8] == 'X')
	{
		if (board[0] == 'X')
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[4] == 'X')
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
	}
	// ***************************************************************
	// ******************* BEGIN OFFENSE *****************************
	if (board[0] == 'O')
	{
		if (board[1] == 'O') // Next to.
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
		if (board[2] == 'O')
		{
			if (check(board, 1))
			{
				return 1;
			}
		}
		if (board[3] == 'O') // Below.
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
		if (board[4] == 'O') // Right and down of.
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'O') // All the way diagonal of. 
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[6] == 'O') // Very below of.
		{
			if (check(board, 3)) // Make sure it hasn't already been played.
			{
				return 3;
			}
		}
	}

	// *********** If the 2 block is taken by the ComputerAI. (1) ****************
	if (board[1] == 'O')
	{
		if (board[2] == 'O')
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
		if (board[4] == 'O') // Below.
		{
			if (check(board, 7))
			{
				return 7;
			}
		}
		if (board[7] == 'O') // All the way below.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[6] == 'O') // All the way below and left 1.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[8] == 'O') // All the way below and right 1.
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
	}

	// *********** If the 3 block is taken by the ComputerAI. (1) *****************
	if (board[2] == 'O')
	{
		if (board[4] == 'O') // Left 1 and down 1.
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
		if (board[5] == 'O') // Below.
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'O') // All the way below.
		{
			if (check(board, 5))
			{
				return 5;
			}
		}
		if (board[6] == 'O') // / Diagonal of.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
	}
	
	// ********* If the 4 block is taken by the ComputerAI. (3) ************
	if (board[3] == 'O')
	{
		if (board[4] == 'O') // Next to.
		{
			if (check(board, 5))
			{
				return 5;
			}
		}
	    if (board[5] == 'O') // Other side of.
		{
			if (check(board, 4))
			{
				return 4;
			}
		}
		if (board[6] == 'O') // Below.
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
	}
	// ************ If the 5 block is taken by the ComputerAI. (4) ******************
	if (board[4] == 'O')
	{
		if (board[5] == 'O')
		{
			if (check(board, 3))
			{
				return 3;
			}
		}
		if (board[6] == 'O')
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
		if (board[7] == 'O')
		{
			if (check(board, 1))
			{
				return 1;
			}
		}
		if (board[8] == 'O')
		{
			if (check(board, 0))
			{
				return 0;
			}
		}
	}
	// ********** If the 6 block was taken by the ComputerAI. (5) *************
	if (board[5] == 'O')
	{
		if (board[8] == 'O')
		{
			if (check(board, 2))
			{
				return 2;
			}
		}
	}
	// ********** If the 7 block is taken by the ComputerAI. (6) ************
	if (board[6] == 'O')
	{
		if (board[7] == 'O')
		{
			if (check(board, 8))
			{
				return 8;
			}
		}
		if (board[8] == 'O')
		{
			if (check(board, 7))
			{
				return 7;
			}
		}
	}
	// ************ If the 8 block is taken by the ComputerAI. (7) *************
	if (board[7] == 'O')
	{
		if (board[8] == 'O')
		{
			if (check(board, 6))
			{
				return 6;
			}
		}
	}
	// If no move for an Offensive or Defensive move, just throw out a random square like a normal player.
	while (true)
	{
		ran = (rand()%10-1);
		if (check(board, ran))
		{
			return ran;
		}
	}
}
