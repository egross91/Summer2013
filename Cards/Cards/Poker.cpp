#include "Poker.h"

#include <iostream>
#include <string>

using namespace std;

Poker::Poker() : super() { }

void Poker::play()
{
	while (true)
	{
		// Unlike BlackJack, theDealer is only going to deal the cards when needed. He will not be a Player.
		Dealer * theDealer = new Dealer();
		vector<Player> players;
		// How many Players are there going to be?
		int nPlayers;
		cout << "How many Players will be playing? (2-7) :  "; cin >> nPlayers;
		if (nPlayers < 2)
		{
			cout << "There has to be a minimum of 2 Players.\nThere are 2 Players playing." << endl << endl;
			nPlayers = 2;
		}
		else if (nPlayers > 7)
		{
			cout << "There is a maximum of 7 Players.\nThere are 7 Players playing." << endl << endl;
			nPlayers = 7;
		}
		players.reserve(nPlayers);

		// Get every Player's name.
		cin.ignore();
		for (int i = 1; i <= nPlayers; ++i)
		{
			string name;
			cout << "Player " << i << "\'s Name :  ";
			getline(cin, name);
			Player pl_i(name);
			players.push_back(pl_i);
		}
		// Deal every Player their respective hand.
		for (unsigned int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < nPlayers; ++j)
				players[j].takeCard1(theDealer->dealCard());

		}
		cout << endl << endl << endl;
		// Each Player will now take their turn.
		// Erase these Players later. (fold()'s)
		vector<int> erase_player_indexes;
		for (unsigned int i = 0; i < players.size(); ++i)
		{
			cout << players[i].getName() << "\'s Turn!" << endl << endl;
			players[i].printHand1();
			char selection [10];
			// Begin turn.
			while (true)
			{
				cout << "Would you like to discard any cards? (y/n) :  "; cin >> selection;
				if (selection[0] == 'y' || selection[0] == 'Y')
				{
					int num;
					cout << "How many cards would you like to discard? :  "; cin >> num;
					if (num >= 4)
					{
						cout << "You can only discard 3 cards max." << endl;
						num = 3;
					}
					else if (num < 1)
					{
						cout << "You have to discard at least 1 card." << endl;
						num = 1;
					}
					// Store the indexes of the cards to erase.
					vector<int> erase_cards;
					int index;
					for (int j = 0; j < num; ++j)
					{
						while (true) 
						{
							cout << "Erase Card :  "; cin >> index;
							if (index > 0 && index < 6)
							{
								erase_cards.push_back(--index);
								break;
							}
							else
								cout << "Please choose between 1 and 5." << endl << endl;
						}
					}
					theDealer->swapCards(players[i], erase_cards);
					cout << players[i].getName() << " NEW Hand" << endl << endl;
					players[i].printHand1();
					if (fold())
						erase_player_indexes.push_back(i);
					cout << endl << endl << endl;
					break;
				}
				else if (selection[0] == 'n' || selection[0] == 'N')
				{
					cout << endl << endl; 
					break;
				}
				else
					cout << "Please choose Y or N." << endl << endl;
			}
		}
		if (erase_player_indexes.size() > 0)
			erasePlayers(players, erase_player_indexes);

		for (unsigned int i = 0; i < players.size(); ++i)
		{
			cout << players[i].getName() << " Hand" << endl << endl;
			players[i].printHand1();
		}

		if (!playAgain())
			break;
	}
}

bool Poker::fold()
{
	char selection [10];
	while (true)
	{
		cout << "Would you like to fold? (y/n):  "; cin >> selection;
		if (selection[0] == 'y' || selection[0] == 'Y')
			return true;
		else if (selection[0] == 'n' || selection[0] == 'N')
			return false;
		else
			cout << "Please choose Y or N." << endl << endl;
	}
}

bool Poker::playAgain()
{
	char selection [10];
	while (true)
	{
		cout << "Would you like to play again? (y/n) :  "; cin >> selection;
		if (selection[0] == 'y' || selection[0] == 'Y')
		{
			cout << endl << endl << endl << endl << endl;
			return true;
		}
		else if (selection[0] == 'n' || selection[0] == 'N')
		{
			cout << endl << endl << endl << endl << endl;
			return false;
		}
		else
			cout << "Please choose Y or N." << endl << endl;
	}
}

void Poker::erasePlayers(vector<Player>& players, vector<int> indexes)
{
	int offset = 0;
	vector<Player>::iterator itr;
	for (unsigned int i = 0; i < indexes.size(); ++i)
	{
		itr = players.begin();
		players.erase(itr + (indexes[i]-offset));
		++offset;
	}
}