#include "Password.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Password::Password() : thePassword("password"), attempts(3)
{

}
Password::Password(std::string passw) : thePassword(passw), attempts(3)
{

}
void Password::setThePassword(std::string passw)
{
	this->thePassword = passw;
}