#include "Player.h"
#include <iostream>

Player::Player(std::string n) : name(n), hand1(NULL), hand2(NULL) { }
Player::Player(std::string n, std::vector<Card> h) : name(n), hand1(h), hand2(NULL) { }

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
void Player::takeCard2(Card theCard)
{
	hand2.push_back(theCard);
}
void Player::setName(std::string n)
{
	this->name = n;
}
void Player::setHand1(std::vector<Card> h)
{
	this->hand1 = h;
}
void Player::setHand2(std::vector<Card> h)
{
	this->hand2 = h;
}
void Player::printHand1()
{
	for (unsigned int i = 0; i < hand1.size(); ++i)
		std::cout << hand1[i].toString();
	std::cout << std::endl;
}
void Player::printHand2()
{
	for (unsigned int i = 0; i < hand2.size(); ++i)
		std::cout << hand2[i].toString();
	std::cout << std::endl;
}