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
	int printResult(std::vector<Card>);
	int determineHand(std::vector<Card>);
	bool royalFlush(std::vector<Card>);
	bool flush(std::vector<Card>);
	bool straight(std::vector<Card>);
	bool fourOfAKind(std::vector<Card>);
	bool fullHouse(std::vector<Card>);
	bool threeOfAKind(std::vector<Card>);
	bool twoPair(std::vector<Card>);
	bool pair(std::vector<Card>);
	bool fold();
	bool playAgain();
	void erasePlayers(std::vector<Player>&, std::vector<int>);
};

#endif POKER_H