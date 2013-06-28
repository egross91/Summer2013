#include "Account.h"

//Account::Account() : myhashmap(std::unordered_map<Username, Password>()) { }
//Account::Account(std::unordered_map<Username, Password> unmap) : myhashmap(unmap) { }
//void Account::put(Username user_name, Password pass_word) { myhashmap.insert(std::make_pair(user_name, pass_word)); }
Account::Account() : user_name(Username()), pass_word(Password())
{

}
Account::Account(Username user, Password pass) : user_name(user), pass_word(pass)
{

}
void Account::setUsername(Username user)
{
	this->user_name = user;
}
void Account::setPassword(Password pass)
{
	this->pass_word = pass;
}
