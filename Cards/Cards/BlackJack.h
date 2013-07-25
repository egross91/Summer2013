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
	int countHand(std::vector<Card>);
	bool bust(int);
	bool win(int);
	bool dealersTurn(Dealer*);
	bool playAgain();
	void erasePlayers(std::vector<Player>&, std::vector<int>);
};

#endif BLACKJACK_H