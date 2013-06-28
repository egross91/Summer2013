#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include "Player.h"
#include <ctime>
#include <vector>

class ComputerAI : public Player
{
private:
	typedef Player super;
public:
	ComputerAI();
	ComputerAI(std::string);
	bool check(char[], int);
	int makeMove(char[], std::vector<int>);
};

#endif COMPUTERAI_H