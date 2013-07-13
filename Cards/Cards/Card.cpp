#include "Card.h"
#include <iostream>
#include <sstream>

Card::Card() : suit(), rank() { }
Card::Card(std::string s, std::string r) : suit(s), rank(r) { }
void Card::setRank(std::string r)
{
	this->rank = r;
}
void Card::setSuit(std::string s)
{
	this->suit = s;
}
std::string Card::toString()
{
	std::stringstream ss;
	ss << rank << " of " << suit << std::endl;
	return ss.str();
}