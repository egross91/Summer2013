#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>

class Player : public Card
{
protected:
	std::string name;
	std::vector<Card> hand1;
	std::vector<Card> hand2;
public:
	Player();
	Player(std::string);
	Player(std::string, std::vector<Card>);
	bool hit();
	std::string getName() { return name; }
	std::vector<Card> getHand1() { return hand1; }
	std::vector<Card> getHand2() { return hand2; }
	void setName(std::string);
	void takeCard1(Card);
	void takeCard2(Card);
	void discard1(std::vector<int>);
	void setHand1(std::vector<Card>);
	void setHand2(std::vector<Card>);
	void printHand1();
	void printHand2();
};

#endif	PLAYER_H