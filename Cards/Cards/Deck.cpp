#include "Deck.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

// Build and shuffle a deck of cards.
Deck::Deck()
{
	for (int i = 1; i <= 4; ++i) // Suit
	{
		for (int j = 2; j <= 14; ++j) // Rank
		{
			Card tmpCard(i, j);
			theDeck.push_back(tmpCard);
		}
	}
	srand((unsigned int) time(0));
	int random = (rand()%100)+1;
	for (int i = 0; i < random; ++i)
		shuffle(theDeck);
}

// Shuffle the deck.
void Deck::shuffle(std::vector<Card>& deck)
{
	std::random_shuffle(deck.begin(), deck.end());
}

// Set the deck.
void Deck::setTheDeck(std::vector<Card> deck)
{
	this->theDeck = deck;
}

void Deck::printDeck()
{
	for (int i = 0; i < size(); ++i)
	{
		Card * tmpCard = new Card(theDeck[i]);
		std::cout << tmpCard->getRank() << " of " << tmpCard->getSuit() << std::endl;
		delete tmpCard;
	}
	std::cout << std::endl;
}