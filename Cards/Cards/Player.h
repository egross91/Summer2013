#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>
#include <list>

// Meant for the double down in BlackJack() //
class Player : public Card
{
protected:
	std::string name;
	std::vector<Card> hand1;
	//std::vector<Card> hand2;
public:
	Player();
	Player(std::string);
	Player(std::string, std::vector<Card>);
	bool hit();
	const std::string& getName() { return name; }
	std::vector<Card> getHand1() { return hand1; }
	//std::vector<Card> getHand2() { return hand2; }
	void setName(std::string);
	void takeCard1(Card);
	//void takeCard2(Card);
	void discard1(std::list<int>);
	void quickSortHand(int, int);
	int partition(int, int);
	void setHand1(std::vector<Card>);
	//void setHand2(std::vector<Card>);
	void printHand(); // Print hand for Poker().
	void printHand1();
	//void printHand2();
};

#endif	PLAYER_H