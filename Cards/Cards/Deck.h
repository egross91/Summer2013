#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <string>
#include <vector>

class Deck : public Card
{
protected:
	std::vector<Card> theDeck;
public:
	Deck();
	void shuffle(std::vector<Card>&);
	std::vector<Card> deal5();
	std::vector<Card> deal2();
	int size() { return theDeck.size(); }
	std::vector<Card> getTheDeck() { return theDeck; }
	Card getCard() { return theDeck.front(); }
	void setTheDeck(std::vector<Card>);
	void printDeck();
};

#endif DECK_H