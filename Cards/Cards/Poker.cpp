#include "Poker.h"

#include <iostream>
#include <string>
#include <list>

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
		cout << "How many Players will be playing? (2-6) :  "; cin >> nPlayers;
		if (nPlayers < 2)
		{
			cout << "There has to be a minimum of 2 Players.\nThere are 2 Players playing." << endl << endl;
			nPlayers = 2;
		}
		else if (nPlayers > 6)
		{
			cout << "There is a maximum of 6 Players.\nThere are 6 Players playing." << endl << endl;
			nPlayers = 6;
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
		for (unsigned int i = 0; i < 5; ++i) // Number of Cards.
		{
			for (int j = 0; j < nPlayers; ++j) // For n number of Players.
				players[j].takeCard1(theDealer->dealCard());
		}
		cout << endl << endl << endl;
		// Each Player will now take their turn.
		// Erase these Players later. (fold()'s)
		vector<int> erase_player_indexes;
		for (unsigned int i = 0; i < players.size(); ++i)
		{
			// Print i-th Player's name and hand.
			cout << players[i].getName() << "\'s Turn!" << endl << endl;
			players[i].printHand();
			char selection [10];
			// Begin turn.
			while (true)
			{
				cout << "\n\n\n\nWould you like to discard any cards? (y/n) :  "; cin >> selection;
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
					// ** Used a list<> because it's easier to sort the indexes and then erase_cards.
					// ** Using unsorted indexes causes errors in erasing the erase_cards 
					list<int> erase_cards;
					int index;
					for (int j = 0; j < num; ++j)
					{
						while (true) 
						{
							// Ask which cards the Player would like to discard().
							cout << "Erase Card " << (j+1) << ":  "; cin >> index;
							if (index > 0 && index < 6)
							{
								// Get a good index, and store it properly.
								erase_cards.push_back(--index);
								break;
							}
							else
								cout << "Please choose between 1 and 5." << endl << endl;
						}
					}
					// Erase and discard() the desired cards.
					erase_cards.sort();
					theDealer->swapCards(players[i], erase_cards);
					cout << endl << endl << endl;
					// Print i-th Player's NEW hand.
					cout << players[i].getName() << "\'s NEW Hand" << endl << endl;
					players[i].printHand();
					// Does i-th Player want to fold() at the end of their turn?
					if (fold())
						erase_player_indexes.push_back(i);
					// End complete turn.
					cout << endl << endl << endl;
					break;
				}
				// End the Player's turn if they choose to keep the hand they were initially dealt.
				else if (selection[0] == 'n' || selection[0] == 'N')
				{
					cout << endl << endl; 
					break;
				}
				else
					cout << "Please choose Y or N." << endl << endl;
			}
		}
		// Erase whatever Players that fold()'d, if anyone did.
		if (erase_player_indexes.size() > 0)
			erasePlayers(players, erase_player_indexes);

		// Sort every Player's hand, figure out what they got, and print it.
		list<int> results;
		int max = -1, winner_index = 0, num;
		for (unsigned int i = 0; i < players.size(); ++i)
		{
			players[i].quickSortHand(0, 4);
			cout << players[i].getName() << "\'s Hand" << endl << endl;
			players[i].printHand();
			num = printResult(players[i].getHand1());
			if (max < num)
			{
				max = num;
				winner_index = i;
			}
		}
		cout << "THE WINNER IS " << players[winner_index].getName() << "!!!" << endl << endl << endl << endl << endl;

		if (!playAgain())
		{
			delete theDealer;
			break;
		}
		delete theDealer;
	}
}
// determineHand() of every Player and printResult() of the Hand.
int Poker::printResult(vector<Card> hand)
{
	int result = determineHand(hand);

	if (result == 0) // If the Player has nothing but a single high card.
	{
		int max = 0, index = 0;
		for (unsigned int i = 0; i < 5; ++i)
		{
			if (max < hand[i].getRank())
			{
				max = hand[i].getRank();
				index = i;
			}
		}
		cout << "** " << hand[index].toString() << " - High Card **" << endl << endl;
		return result;
	}
	else if (result == 1)
	{
		cout << "** One Pair **" << endl << endl;
		return result;
	}
	else if (result == 2)
	{
		cout << "** Two Pair **" << endl << endl;
		return result;
	}
	else if (result == 3)
	{
		cout << "** Three of a Kind **" << endl << endl;
		return result;
	}
	else if (result == 4)
	{
		cout << "** Straight **" << endl << endl;
		return result;
	}
	else if (result == 5)
	{
		cout << "** Flush **" << endl << endl;
		return result;
	}
	else if (result == 6)
	{
		cout << "** Full House **" << endl << endl;
		return result;
	}
	else if (result == 7)
	{
		cout << "** Four of a Kind **" << endl << endl;
		return result;
	}
	else if (result == 8)
	{
		cout << "** Straight Flush **" << endl << endl;
		return result;
	}
	else
	{
		cout << "*****	ROYAL FLUSH *****" << endl << endl;
		return result;
	}
}
// What kind of Hand does everyone have?
int Poker::determineHand(vector<Card> hand)
{
	if (royalFlush(hand)) // Royal Flush.
		return 9;
	else if (flush(hand) && straight(hand)) // Straight Flush.
		return 8;
	else if (fourOfAKind(hand)) // Four of a Kind.
		return 7;
	else if (fullHouse(hand)) // Full House.
		return 6;
	else if (flush(hand)) // Flush.
		return 5;
	else if (straight(hand)) // Straight.
		return 4;
	else if (threeOfAKind(hand)) // Three of a Kind
		return 3;
	else if (twoPair(hand)) // Two Pair
		return 2;
	else if (pair(hand)) // Pair
		return 1;
	return 0; // Nothing - High card.
}
// Check if there is a royalFlush().
bool Poker::royalFlush(vector<Card> hand)
{
	if (flush(hand) && 
		(hand[0].getRank() == 10 && hand[1].getRank() == 11 && hand[2].getRank() == 12 && hand[3].getRank() == 13 && hand[4].getRank() == 14))
		return true;
	return false;
}
// Check if there is a flush().
bool Poker::flush(vector<Card> hand)
{
	if (hand[0].getSuit() == hand[1].getSuit() && hand[1].getSuit() == hand[2].getSuit() && hand[2].getSuit() == hand[3].getSuit() && hand[3].getSuit() == hand[4].getSuit())
		return true;
	return false;
}
// Check if there is a straight().
bool Poker::straight(vector<Card> hand)
{
	if ((hand[4].getRank() - hand[3].getRank()) == 1 && (hand[3].getRank() - hand[2].getRank()) == 1 && (hand[2].getRank() - hand[1].getRank()) == 1 && (hand[1].getRank() - hand[0].getRank()) == 1)
		return true;
	return false;
}
// Check if there is a fourOfAKind().
bool Poker::fourOfAKind(vector<Card> hand)
{
	for (unsigned int i = 0; i < 2; ++i)
	{
		if (hand[i].getRank() == hand[i+1].getRank() && hand[i+1].getRank() == hand[i+2].getRank() && hand[i+2].getRank() == hand[i+3].getRank())
			return true;
	}
	return false;
}
// Check if there is a fullHouse().
bool Poker::fullHouse(vector<Card> hand)
{
	if ((hand[0].getRank() == hand[1].getRank() && hand[1].getRank() == hand[2].getRank() && hand[3].getRank() == hand[4].getRank()) ||
		(hand[0].getRank() == hand[1].getRank() && hand[2].getRank() == hand[3].getRank() && hand[3].getRank() == hand[4].getRank()))
		return true;
	return false;
}
// Check if there is a threeOfAKind().
bool Poker::threeOfAKind(vector<Card> hand)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		if (hand[i].getRank() == hand[i+1].getRank() && hand[i+1].getRank() == hand[i+2].getRank())
			return true;
	}
	return false;
}
// Check if there is a twoPair().
bool Poker::twoPair(vector<Card> hand)
{
	bool pair_one = false, pair_two = false;
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (hand[i].getRank() == hand[i+1].getRank() && !pair_one)
			pair_one = true;
		else if (hand[i].getRank() == hand[i+1].getRank() && pair_one)
			pair_two = true;
	}
	if (pair_two)
		return true;
	return false;
}
// Check if there is a pair().
bool Poker::pair(vector<Card> hand)
{
	if (hand[0].getRank() == hand[1].getRank() || 
		hand[1].getRank() == hand[2].getRank() || 
		hand[2].getRank() == hand[3].getRank() || 
		hand[3].getRank() == hand[4].getRank())
		return true;
	return false;
}
// Does the Player want to fold()?
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
// Does everyone, or someone wanna playAgain()?
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
// Erase losing Players.
void Poker::erasePlayers(vector<Player>& players, vector<int> indexes)
{
	int offset = 0;
	for (unsigned int i = 0; i < indexes.size(); ++i)
	{
		vector<Player>::iterator itr = players.begin();
		players.erase(itr + (indexes[i]-offset++));
	}
}