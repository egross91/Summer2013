#ifndef POKER_H
#define POKER_H

#include "Dealer.h"

class Poker : public Dealer
{
private:
	typedef Dealer super;
public:
	Poker();
	void play();
	void determineHand(std::vector<Card>);
	bool fold();
	bool playAgain();
	void erasePlayers(std::vector<Player>&, std::vector<int>);
};

#endif POKER_H