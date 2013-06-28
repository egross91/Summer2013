#include "Player.h"

Player::Player() : wins(0), draws(0), losses(0), name(std::string("Default")) 
{ 

}
Player::Player(std::string n) : wins(0), draws(0), losses(0), name(n) 
{

}
void Player::setName(std::string n)
{
	this->name = n;
}
void Player::setWins(int w)
{
	this->wins = w;
}
void Player::setDraws(int d)
{
	this->draws = d;
}
void Player::setLosses(int l)
{
	this->losses = l;
}