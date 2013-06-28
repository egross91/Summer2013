#ifndef USERNAME_H
#define USERNAME_H

#include <string>

class Username
{
private:
	std::string theUsername, firstname, lastname;
public:
	Username();
	Username(std::string, std::string, std::string);
	const std::string & getTheUsername() { return theUsername; }
	const std::string & getFirstname() { return firstname; }
	const std::string & getLastname() { return lastname; }
	void setTheUsername(std::string);
	void setFirstname(std::string);
	void setLastname(std::string);
};

#endif USERNAME_H