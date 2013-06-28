#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Username.h"
#include "Password.h"
#include <unordered_map>

class Account : public Username, public Password
{
private:
	// Use a hash_map as the private property and use it as an arg for the initializing constructor.
	// Add a "put()" function and figure a way to access the Usernames and Passwords within the hash_map.
	// *** LEFT OFF HERE ***
	//std::unordered_map<Username, Password> myhashmap;
	Username user_name;
	Password pass_word;
public:
	Account();
	//Account(std::unordered_map<Username, Password>);
	Account(Username user, Password pass);
	const Username & getTheUser() { return user_name; }
	const Password & getThePass() { return pass_word; }
	//void put(Username, Password);
	void setUsername(Username user);
	void setPassword(Password pass);
};


#endif ACCOUNT_H