#include "Dealer.h"
#include <iostream>
#include <string>

Dealer::Dealer() : dealerDeck(Deck()), super(std::string("Dealer")) { }
Dealer::Dealer(Deck d) : dealerDeck(d), super(std::string("Dealer")) { }

// Used for when a players discards a card from their hand and needs another. (Poker related).
// Can also be used for when a player wants to hit().
Card Dealer::dealCard()
{
	Card retCard(theDeck.front());
	std::vector<Card>::iterator itr = theDeck.begin();
	theDeck.erase(itr);
	return retCard;
}

void Dealer::setDeck(Deck d)
{
	this->dealerDeck = d;
}