#include "Username.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

Username::Username() : theUsername("NULL"), firstname("FIRST"), lastname("LASST")
{

}
Username::Username(std::string user, std::string first, std::string last) : theUsername(user), firstname(first), lastname(last)
{

}
void Username::setTheUsername(std::string user)
{
	this->theUsername = user;
}
void Username::setFirstname(std::string first)
{
	this->firstname = first;
}
void Username::setLastname(std::string last)
{
	this->lastname = last;
}