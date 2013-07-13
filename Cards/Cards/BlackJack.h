#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Dealer.h"

class BlackJack : public Dealer
{
private:
	typedef Dealer super;
public:
	BlackJack();
	void play();
	bool bust(std::vector<Card>);
	bool win(std::vector<Card>);
	bool playAgain();
	void erasePlayers(std::vector<Player>&, std::vector<int>);
};

#endif BLACKJACK_H