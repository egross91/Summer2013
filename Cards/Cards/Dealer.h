#ifndef DEALER_H
#define DEALER_H

#include "Deck.h"
#include "Player.h"

class Dealer : public Deck, public Player
{
private:
	Deck dealerDeck;
	typedef Player super;
public:
	Dealer();
	Dealer(Deck);
	Card dealCard();
	Deck getDeck() { return dealerDeck; }
	void swapCards(Player&, std::list<int>);
	void setDeck(Deck);
};

#endif DEALER_H