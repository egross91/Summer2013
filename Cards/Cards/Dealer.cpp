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

void Dealer::swapCards(Player& turn, std::list<int> indexes)
{
	// Erase the old Cards, in the appropriate indexes.
	turn.discard1(indexes);

	// Replace the erased Cards.
	for (unsigned int i = 0; i < indexes.size(); i++)
		turn.takeCard1(dealCard());
}

void Dealer::setDeck(Deck d)
{
	this->dealerDeck = d;
}