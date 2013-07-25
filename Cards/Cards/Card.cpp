#include "Card.h"
#include <iostream>
#include <sstream>

Card::Card() : suit(), rank() { }
Card::Card(int s, int r) : suit(s), rank(r) { }
void Card::setRank(int r)
{
	this->rank = r;
}
void Card::setSuit(int s)
{
	this->suit = s;
}
std::string Card::toString()
{
	std::stringstream ss;
	if (this->rank == 2)
		ss << "Two ";
	else if (this->rank == 3)
		ss << "Three ";
	else if (this->rank == 4)
		ss << "Four ";
	else if (this->rank == 5)
		ss << "Five ";
	else if (this->rank == 6)
		ss << "Six ";
	else if (this->rank == 7)
		ss << "Seven ";
	else if (this->rank == 8)
		ss << "Eight ";
	else if (this->rank == 9)
		ss << "Nine ";
	else if (this->rank == 10)
		ss << "Ten ";
	else if (this->rank == 11)
		ss << "Jack ";
	else if (this->rank == 12 )
		ss << "Queen ";
	else if (this->rank == 13)
		ss << "King ";
	else
		ss << "Ace ";

	if (this->suit == 1)
		ss << "of Hearts";
	else if (this->suit == 2)
		ss << "of Diamonds";
	else if (this->suit == 3)
		ss << "of Clubs";
	else if (this->suit == 4)
		ss << "of Spades";

	return ss.str();
}