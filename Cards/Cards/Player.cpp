#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Player::Player(std::string n) : name(n), hand1(NULL) { } //hand2(NULL) 
Player::Player(std::string n, std::vector<Card> h) : name(n), hand1(h) { } // hand2(NULL) { }

// Ask the Player if they would like to Stay or Hit().
bool Player::hit()
{
	char selection [10];
	while (true)
	{
		std::cout << "Hit or Stay? (h/s) :  "; std::cin >> selection;
		if (selection[0] == 'h' || selection[0] == 'H')
			return true;
		else if (selection[0] == 's' || selection [0] == 'S')
			return false;
		else
			std::cout << "Please make a choice." << std::endl << std::endl;
	}
}
void Player::takeCard1(Card theCard)
{
	hand1.push_back(theCard);
}
/* void Player::takeCard2(Card theCard)
{
	hand2.push_back(theCard);
} */
void Player::discard1(std::list<int> indexes)
{
	std::vector<Card>::iterator c_itr;
	std::list<int>::iterator i_itr = indexes.begin();
	int offset = 0;
	for (unsigned int i = 0; i < indexes.size(); ++i)
	{
		c_itr = hand1.begin();
		hand1.erase(c_itr + (*i_itr++ - offset++));
	}
}
// Sort the Player's hand for easy analyzing.
void Player::quickSortHand(int left, int right)
{
	if (left < right)
	{
		int pivot = partition(left, right);

		quickSortHand(left, pivot-1);
		quickSortHand(pivot+1, right);
	}
}
int Player::partition(int left, int right)
{
	int pivot = hand1[left].getRank();
	if (pivot == 1) // An Ace
		pivot = 14;
	int offset = 0, end = 4;
	unsigned int j = left+1;
	int k = left+1;
	for (; k <= right; ++k)
	{
		if (hand1[k].getRank() <= pivot)
		{
			swap(hand1[k], hand1[j]);
			++j;
		}
	}
	swap(hand1[left], hand1[j-1]);
	return j-1;
}
void Player::setName(std::string n)
{
	this->name = n;
}
void Player::setHand1(std::vector<Card> h)
{
	this->hand1 = h;
}
/* void Player::setHand2(std::vector<Card> h)
{
	this->hand2 = h;
} */
// Print hand for Poker().
void Player::printHand() 
{
	for (unsigned int i = 0; i < hand1.size(); ++i)
		cout << hand1[i].toString() << "\t(" << (i+1) << ")" << endl;
	cout << endl;
}
// Print hand for BlackJack().
void Player::printHand1()
{
	for (unsigned int i = 0; i < hand1.size(); ++i)
		cout << hand1[i].toString() << endl;
	cout << endl;
}
/* void Player::printHand2()
{
	for (unsigned int i = 0; i < hand2.size(); ++i)
		std::cout << hand2[i].toString();
	std::cout << std::endl;
} */