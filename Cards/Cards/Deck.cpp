#include "Deck.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

// Build and shuffle a deck of cards.
Deck::Deck()
{
	std::string suit;
	std::string rank;
	for (int i = 1; i <= 4; ++i) // Suit
	{
		if (i == 1) 
			suit = "Hearts";
		else if (i == 2)
			suit = "Diamonds";
		else if (i == 3)
			suit = "Clubs";
		else if (i == 4)
			suit = "Spades";
		for (int j = 1; j <= 13; ++j) // Rank
		{
			if (j == 1) 
				rank = "Ace";
			else if (j == 2)
				rank = "Two";
			else if (j == 3)
				rank = "Three";
			else if (j == 4)
				rank = "Four";
			else if (j == 5)
				rank = "Five";
			else if (j == 6)
				rank = "Six";
			else if (j == 7)
				rank = "Seven";
			else if (j == 8)
				rank = "Eight";
			else if (j == 9)
				rank = "Nine";
			else if (j == 10)
				rank = "Ten";
			else if (j == 11)
				rank = "Jack";
			else if (j == 12)
				rank = "Queen";
			else if (j == 13)
				rank = "King";
			Card * tmpCard = new Card(suit, rank);
			theDeck.push_back(*tmpCard);
			delete tmpCard;
		}
	}
	srand((unsigned int) time(0));
	int random = rand()%1000;
	for (int i = 0; i < random; ++i)
	{
		shuffle(theDeck);
	}
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