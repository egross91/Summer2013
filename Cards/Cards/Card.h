#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
protected:
	std::string rank, suit;
public:
	Card();
	Card(std::string, std::string);
	std::string getRank() { return rank; }
	std::string getSuit() { return suit; }
	void setRank(std::string);
	void setSuit(std::string);
	std::string toString();
};

#endif CARD_H