#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>

class Password
{
private:
	std::string thePassword;
	int attempts;
public:
	Password();
	Password(std::string);
	const std::string & getThePassword() { return thePassword; }
	void setThePassword(std::string);
};

#endif PASSWORD_H