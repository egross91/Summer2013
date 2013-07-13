#include "BlackJack.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

BlackJack::BlackJack() : super() { }

void BlackJack::play()
{
	while (true)
	{
		// Create the Dealer, vector of Players, and ask how many Players there will be.
		Dealer * theDealer = new Dealer();
		vector<Player> player_vec;
		int nPlayers;
		cout << "How many players would you like to have? :  "; cin >> nPlayers;
		if (nPlayers > 25)
		{
			cout << "Only 25 Players allowed.\nThe new number of Players is 25." << endl;
			nPlayers = 25;
		}
		else if (nPlayers < 1)
		{
			cout << "You need at least 1 other Player.\nThe new number of Players is 1." << endl;
			nPlayers = 1;
		}
		player_vec.reserve(nPlayers+1);

		// Create n amount of Players, and make sure the Dealer is last in the vector.
		cout << endl;
		cin.ignore();
		for (int i = 1; i <= nPlayers; ++i)
		{
			string name;
			cout << "Player " << i << "\'s Name :  ";
			getline(cin, name);
			Player pl_i(name);
			player_vec.push_back(pl_i);
		}
		player_vec.push_back(*theDealer);

		// Give each Player a Card in sequential order or turn.
		for (int i = 0; i < 2; ++i)
		{
			for (unsigned int j = 0; j < player_vec.size(); ++j)
			{
				player_vec[j].takeCard(theDealer->dealCard());
			}
		}
	
		// Allow each player to take their respective turn.
		vector<int> ePlayers;
		for (unsigned int i = 0; i < player_vec.size(); ++i)
		{
			cout << endl << endl;
			cout << player_vec[i].getName() << "\'s Turn" << endl;
			player_vec[i].printHand();
			vector<Player>::iterator itr = player_vec.begin();
			while (true)
			{
				if (win(player_vec[i].getHand()))
				{
					cout << player_vec[i].getName() << "\'s WON!!!" << endl;
					break;
				}
				if (player_vec[i].hit())
				{
					Card tmpCard = theDealer->dealCard();
					player_vec[i].takeCard(tmpCard);
					cout << tmpCard.toString() << endl << endl; 
				}
				else
					break;
				
				if (win(player_vec[i].getHand()))
				{
					cout << player_vec[i].getName() << "\'s WON!!!" << endl;
					break;
				}
				if (bust(player_vec[i].getHand()))
				{
					cout << player_vec[i].getName() << " Bust!" << endl << endl;
					ePlayers.push_back(i);
					_getch();
					break;
				}
			}
		}

		// Get rid of the Player's that already lost, if there are any.
		if (ePlayers.size() > 0)
		{
			erasePlayers(player_vec, ePlayers);
		}

		// Print each Player's hand at the end of the game, and announce who won.
		for (unsigned int i = 0; i < player_vec.size(); ++i)
		{
			cout << "***** " << player_vec[i].getName() << "\'s Hand *****" << endl << endl;
			player_vec[i].printHand();
		}		
		// End game and get rid of the dealer.
		delete theDealer;
		if (!playAgain())
		{
			cout << endl << endl << endl << endl << endl;
			break;
		}
	} 
}

bool BlackJack::bust(vector<Card> hand)
{
	int sum = 0, size = hand.size();
	bool ace11 = false;
	for (int i = 0; i < size; ++i)
	{
		if (hand[i].getRank() == "Two")
			sum += 2;
		else if (hand[i].getRank() == "Three")
			sum += 3;
		else if	(hand[i].getRank() == "Four")
			sum += 4;
		else if (hand[i].getRank() == "Five")
			sum += 5;
		else if (hand[i].getRank() == "Six")
			sum += 6;
		else if (hand[i].getRank() == "Seven")
			sum += 7;
		else if (hand[i].getRank() == "Eight")
			sum += 8;
		else if (hand[i].getRank() == "Nine")
			sum += 9;
		else if (hand[i].getRank() == "Ten" || hand[i].getRank() == "Jack" || hand[i].getRank() == "Queen" || hand[i].getRank() == "King")
			sum += 10;
		else if (hand[i].getRank() == "Ace")
		{
			if (sum > 10)
				sum += 1;
			else
			{
				sum += 11;
				ace11 = true;
			}
		}
	}
	if (ace11 && sum > 21)
		sum -= 10;
	if (sum > 21)
		return true;

	return false;
}

bool BlackJack::win(vector<Card> hand)
{
	int sum = 0, size = hand.size();
	bool ace11 = false;
	for (int i = 0; i < size; ++i)
	{
		if (hand[i].getRank() == "Two")
			sum += 2;
		else if (hand[i].getRank() == "Three")
			sum += 3;
		else if	(hand[i].getRank() == "Four")
			sum += 4;
		else if (hand[i].getRank() == "Five")
			sum += 5;
		else if (hand[i].getRank() == "Six")
			sum += 6;
		else if (hand[i].getRank() == "Seven")
			sum += 7;
		else if (hand[i].getRank() == "Eight")
			sum += 8;
		else if (hand[i].getRank() == "Nine")
			sum += 9;
		else if (hand[i].getRank() == "Ten" || hand[i].getRank() == "Jack" || hand[i].getRank() == "Queen" || hand[i].getRank() == "King")
			sum += 10;
		else if (hand[i].getRank() == "Ace")
		{
			if (sum > 10)
				sum += 1;
			else
			{
				sum += 11;
				ace11 = true;
			}
		}
	}
	if (ace11 && sum > 21)
	{
		sum -= 10;
	}
	if (sum == 21)
		return true;

	return false;
}

bool BlackJack::playAgain()
{
	char selection [10];
	while (true)
	{	
		cout << "Would you like to play again? (y/n) :  "; cin >> selection;
		if (selection[0] == 'y' || selection[0] == 'Y')
			return true;
		else if (selection[0] == 'n' || selection[0] == 'N')
			return false;
		else
			cout << "Please choose Y or N." << endl << endl;
	} 
}
void BlackJack::erasePlayers(vector<Player>& players, vector<int> indexes)
{
	unsigned int offset = 0;
	vector<Player>::iterator itr;
	for (unsigned int i = 0; i < indexes.size(); ++i)
	{
		itr = players.begin();
		players.erase(itr + (indexes[i] - offset));
		++offset;
	}
}