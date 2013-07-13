#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>

class Player : public Card
{
private:
	std::string name;
	std::vector<Card> hand;
public:
	Player();
	Player(std::string);
	Player(std::string, std::vector<Card>);
	bool hit();
	std::string getName() { return name; }
	std::vector<Card> getHand() { return hand; }
	void takeCard(Card);
	void setName(std::string);
	void setHand(std::vector<Card>);
	void printHand();
};

#endif	PLAYER_H