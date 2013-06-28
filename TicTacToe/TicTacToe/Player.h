#ifndef PLAYERS_H
#define PLAYERS_H

#include <string> 

class Player
{
private:
	int wins, draws, losses;
	std::string name;
public:
	Player();
	Player(std::string);
	const std::string & getName() { return name; }
	void setName(std::string);
	void setWins(int);
	void setDraws(int);
	void setLosses(int);
};

#endif PLAYERS_H