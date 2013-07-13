#include "Player.h"
#include <iostream>

Player::Player(std::string n) : name(n), hand(NULL) { }
Player::Player(std::string n, std::vector<Card> h) : name(n), hand(h) { }

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
void Player::takeCard(Card theCard)
{
	hand.push_back(theCard);
}
void Player::setName(std::string n)
{
	this->name = n;
}
void Player::setHand(std::vector<Card> h)
{
	this->hand = h;
}
void Player::printHand()
{
	for (unsigned int i = 0; i < hand.size(); ++i)
	{
		std::cout << hand[i].toString();
	}
	std::cout << std::endl;
}
