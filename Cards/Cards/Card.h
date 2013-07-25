#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
protected:
	int rank, suit;
public:
	Card();
	Card(int, int);
	int getRank() { return rank; }
	int getSuit() { return suit; }
	void setRank(int);
	void setSuit(int);
	std::string toString();
};

#endif CARD_H