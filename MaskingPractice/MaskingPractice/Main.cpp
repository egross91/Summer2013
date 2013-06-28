/********************************************************************
 * This is project allows the user to create Accounts by creating a 
 * Username and Password object to store in the Account as properties.
 * You are able to print the current state of the vector containing all 
 * the Accounts created. The only thing I've noticed about this project
 * that I never did anything with was the login attempts. I mean, I could 
 * after realizing I didn't do it, but I figured it wasn't worth the effort.
 * Other than that, I'm pretty sure all the checks here all handled,
 * and there are no bugs besides the lack of using the attempts
 * property for the Password object. 
 *
 * I incorporated a lot of new stuff I learned around this time.
 * That includes password masking and saving & loading. For shiggles, 
 * you can load the save file that's found in the project folder.
 * There is no sensitive information in the save file for obvious reasons haha.
 * But they are there for testing purposes.
 *
 * All memory management is handled with no leaks (i.e. all pointers are
 * later deleted). I'm still not too sure on when and when not to use them, though.
 * From my knowledge, it's recommended to use them for dynamic allocation
 * when you aren't sure how much data you will be storing within that
 * variable or object. I also have the same thoughts and concerns for
 * `const.` All I know about const is that whatever is const is immutable.
 ********************************************************************/
#include "Account.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>

using std::cout; using std::cin; using std::endl;

//-----------------------  MENU  ------------------------------------
void menu()
{
	cout << "(C)reate Account" << endl;
	cout << "(P)rint Array of Accounts" << endl;
	cout << "(E)dit User Profile" << endl;
	cout << "(D)elete User Profile" << endl;
	cout << "(L)oad Previous Users" << endl;
	cout << "(Q)uit Without Saving" << endl;
	cout << "(S)ave & Quit" << endl << endl;
}
//--------------------  GETSELECTION  ----------------------------------
char getSelection()
{
	char s;
	cout << "Selection :  "; cin >> s;
	return s;
}
// ----------------  GETMASKEDPASSWORD  ------------------------------------
std::string getMaskedPassword(std::string thePwd)
{
	STARTPASS:
	char tmpPass [32];
	char tmpChar = ' ';
	int index = 0;

	while (tmpChar != 13)
	{
		tmpChar = _getch();
		if ((tmpChar > 27 && tmpChar < 127) && index < 32)
		{
			cout << "*";
			tmpPass[index] = tmpChar;
			++index;
		}
		else if (tmpChar == '\b' && index >= 1)
		{
			cout << "\b \b";
			--index;
		}
		else if (tmpChar == '\r')
		{
			tmpPass[index] = '\0';
			break;
		}
	}
	cout << endl;
	if (index < 6)
	{
		cout << "Password must be at least 6 character." << endl << endl;
		cout << "Password :  ";
		goto STARTPASS;
	}
	for (int i = 0; i < index; i++)
	{
		thePwd += tmpPass[i];
	}
	cout << endl << endl;
	return thePwd;
}
//------------------  PRINTACCOUNTS  -------------------------------------
void printAccounts(std::vector<Account> accs) // Print the accounts only based on the actual number of accounts, not by the size of the array.
{
	for (unsigned i = 0; i < accs.size(); i++)
	{
		Username * the_user = new Username(accs[i].getTheUser());
		Password * the_password = new Password(accs[i].getThePass());
		cout << "Account " << (i+1) << " - " << the_user->getFirstname() << " " << the_user->getLastname() << endl;
		cout << "----------------------------------" << endl;
		cout << "Username :  " << the_user->getTheUsername() << endl;
		cout << "Password :  " << the_password->getThePassword() << endl;
		cout << endl;
		delete the_user;
		delete the_password;
	}
}
//------------------  SAVEACCOUNTS  -------------------------------------
void saveAccounts(std::vector<Account> accs)
{
	std::ofstream savefile("savedata.sav", std::ofstream::binary); // By re-initializing the file, the old contents are destroyed and the new data is written.
	for (unsigned i = 0; i < accs.size(); i++)
	{
		Username * pUser = new Username(accs[i].getTheUser());
		Password * pPass = new Password(accs[i].getThePass());
		savefile << pUser->getFirstname() << endl;
		savefile << pUser->getLastname() << endl;
		savefile << pUser->getTheUsername() << endl;
		savefile << pPass->getThePassword() << endl;
		delete pUser;
		delete pPass;
	}
	savefile << "\0" << endl;
	savefile.close();
}
//-------------------  LOADACCOUNTS  ------------------------------------
std::vector<Account> loadAccounts() // Load the data from the file to later print to make sure it works correctly.
{
	cout << "LOADING ACCOUNTS!" << endl;
	std::ifstream loadfile("savedata.sav", std::ifstream::binary);
	std::vector<Account> acc_mem;
	acc_mem.reserve(20);
	if (loadfile.is_open() && loadfile.good())
	{
		for (unsigned i = 0; i < acc_mem.capacity() && loadfile.good(); i++)
		{
			std::string first;
			std::getline(loadfile, first);
			if (first == "\0")
			{
				break;
			}
			std::string last;
			std::getline(loadfile, last);
			std::string user_name;
			std::getline(loadfile, user_name);
			std::string pass_word;
			std::getline(loadfile, pass_word);
			Username * user = new Username(user_name, first, last);
			Password * pass = new Password(pass_word);
			Account * acc = new Account(*user, *pass);
			acc_mem.push_back(*acc);
			delete user;
			delete pass;
			delete acc;
		}
		const Username endUser = Username();
		const Password endPass = Password();
		const Account endAcc(endUser, endPass);
		acc_mem.push_back(endAcc);
		loadfile.close();
		cout << "ACCOUNTS LOADED SUCCESSFUL!" << endl;
		return acc_mem;
	}
	else
	{
		cout << "ACCOUNTS FAILED TO LOAD!" << endl;
		loadfile.close();
		return acc_mem;
	}
}
//----------------  ADDSPACE  ---------------------------------------
std::vector<Account> addSpace(std::vector<Account> accs)
{
	std::vector<Account> bigger_arr;
	if (accs.size() == 10)
	{
		cout << "Making Vector of size 15." << endl;
		bigger_arr.reserve(15);
	}
	if (accs.size() == 15)
	{
		cout << "Making Vector of size 20. This is max capacity." << endl;
		cout << "You will need to edit members or delete, if you wish." << endl;
		bigger_arr.reserve(20);
	}
	for (unsigned i = 0; i < accs.size(); i++)
	{
		bigger_arr.push_back(accs[i]);
	}
	return bigger_arr;
}
//-----------------  EDITACCOUNT  --------------------------------------
std::vector<Account> editAccount(std::vector<Account> accs)
{
	std::string user;
	cout << "Username :  "; cin.ignore();
	std::getline(cin, user);

	std::string pwd = "";
	cout << "Password :  ";
	pwd = std::string(getMaskedPassword(pwd));
	cout << endl;
	for (unsigned i = 0; i < accs.size(); i++)
	{
		Username * user_name = new Username(accs[i].getTheUser());
		// If the usernames match.
		if (user_name->getTheUsername() == user)
		{
			cout << "Username found!" << endl;
			Password * pass = new Password(accs[i].getThePass());
			// If the Passwords match.
			if (pass->getThePassword() == pwd)
			{
				cout << "Password correct!" << endl << endl;
				cout << "Enter to leave the same." << endl;
				cout << "Username must be at least 6 characters, but at most 18." << endl;
				cout << "New Username :  ";
				std::getline(cin, user);
				std::string first;
				cout << "New Firstname :  "; 
				std::getline(cin, first);
				std::string last;
				cout << "New Lastname :  ";
				std::getline(cin, last);
				cout << endl;
				cout << "Enter your current password to keep it." << endl;
				cout << "New Password :  ";
				pwd = "";
				pwd = std::string(getMaskedPassword(pwd));	

				// Checks to make sure there were any changes to the editable properties.
				if (user != "\0" && user.length() > 5 && user.length() < 19)
				{
					user_name->setTheUsername(user);
					cout << "Username changed!" << endl;
				}
				if (first != "\0")
				{
					user_name->setFirstname(first);
					cout << "Firstname changed!"  << endl;
				}
				if (last != "\0")
				{
					user_name->setLastname(last);
					cout << "Lastname changed!" << endl;
				}
				if (pwd != pass->getThePassword())
				{
					pass->setThePassword(pwd);
					cout << "Password changed!" << endl;
				}

				Account * tmpAcc = new Account(*user_name, *pass);
				accs[i] = *tmpAcc;
				delete user_name;
				delete pass;
				delete tmpAcc;
				cout << "Edit successful!" << endl << endl;
				return accs;
			}
			// If the passwords do not match.
			else
			{
				cout << "Password NOT correct!" << endl << endl;
				delete user_name;
				delete pass;
				return accs;
			}
		}
		delete user_name;
	}
	cout << "Username NOT found!" << endl << endl;
	return accs;
}
//-----------------  DELETEACCOUNT  --------------------------------------
std::vector<Account> deleteAccount(std::vector<Account> accs)
{
	std::string user;
	cout << "Username :  "; cin.ignore();
	std::getline(cin, user);

	std::string pwd = "";
	cout << "Password :  ";
	pwd = std::string(getMaskedPassword(pwd));
	cout << endl;
	for (unsigned i = 0; i < accs.size(); i++)
	{
		Username * user_name = new Username(accs[i].getTheUser());
		if (user_name->getTheUsername() == user)
		{
			Password * pass_word = new Password(accs[i].getThePass());
			if (pass_word->getThePassword() == pwd)
			{
				std::vector<Account>::iterator itr = accs.begin();
				accs.erase(itr+i);
				delete user_name;
				delete pass_word;
				cout << "User \"" << user << "\" was deleted successfully!" << endl << endl;
				return accs;
			}
			else
			{
				cout << "Password incorrect!" << endl << endl;
				delete user_name;
				delete pass_word;
				return accs;
			}
		}
		delete user_name;
	}
	cout << "Username \"" << user << "\" not found!" << endl << endl;
	return accs;
}
//----------------------  MAIN  --------------------------------------
int main(int argc, char * argv[])
{
	//Globals.
	char selection;
	std::vector<Account> acc_arr;
	acc_arr.reserve(10);

	while(true)
	{
		//Condensed menu.
		STARTMENU:
		menu();
		selection = getSelection();
		cout << endl << endl;
		// ******************* CREATE USER ******************
		if (selection == 'c' || selection == 'C') 
		{
			if (acc_arr.size() == 10 || acc_arr.size() == 15)
			{
				acc_arr = addSpace(acc_arr);
			}
			if (acc_arr.size() == 20)
			{
				cout << "Maximum of 20 users allowed. Please delete a user before continuing." << endl;
				goto STARTMENU;
			}
			std::string firstname, lastname;
			cout << "Firstname : "; cin.ignore();
			std::getline(cin, firstname);
			cout << "Lastname :  ";
			std::getline(cin, lastname);			
			STARTUSER: // If the length of the username is not long enough or too big, go back to here. 
			std::string user_name;
			cout << "Username :  ";
			std::getline(cin, user_name);

			if (user_name.length() < 6)
			{
				cout << "Username must be at least 6 characters." << endl << endl;
				goto STARTUSER;
			}
			if (user_name.length() > 18)
			{
				cout << "Username must be less than 18 characters." << endl << endl;
				goto STARTUSER;
			}
			std::string pass_word = "";
			cout << "Password :  ";
			pass_word = std::string(getMaskedPassword(pass_word));

			Username pUser(user_name, firstname, lastname);
			Password pPass(pass_word);
			Account pAcc(pUser, pPass);
			acc_arr.push_back(pAcc);
		}
		// ******************* PRINT USER *********************
		else if (selection == 'p' || selection == 'P') 
		{
			//Print the accounts to the user, including the passwords. They will be readible and not masked.
			printAccounts(acc_arr);
		}
		// ****************** EDIT USER ***********************
		else if (selection == 'e' || selection == 'E')
		{
			acc_arr = std::vector<Account>(editAccount(acc_arr));
		}
		// **************** DELETE USER ***********************
		else if (selection == 'd' || selection == 'D')
		{
			acc_arr = std::vector<Account>(deleteAccount(acc_arr));
		}
		// ****************** LOAD USER ***********************
		else if (selection == 'l' || selection == 'L')
		{
			std::vector<Account> tmp_acc_arr = loadAccounts();
			acc_arr = std::vector<Account>();
			if (tmp_acc_arr.size() == 0)
			{
				cout << endl;
			}
			else
			{
				if (tmp_acc_arr.size() >= 10 && tmp_acc_arr.size() < 15)
				{
					acc_arr.reserve(15);
				}
				if (tmp_acc_arr.size() >= 15)
				{
					acc_arr.reserve(20);
				}
				//Store the loaded Accounts into the main array (acc_arr).
				for (unsigned i = 0; i < tmp_acc_arr.size(); i++)
				{
					Username tmp_user(tmp_acc_arr[i].getTheUser());
					if (tmp_user.getTheUsername() == "NULL")
					{
						break;
					}
					acc_arr.push_back(tmp_acc_arr[i]);
				}
				cout << endl;
			}
		}
		// ********** QUIT WITHOUT SAVING ******************
		else if (selection == 'q' || selection == 'Q')
		{
			break;
		}
		// ************** QUIT AND SAVE ********************
		else if (selection == 's' || selection == 'S')
		{
			saveAccounts(acc_arr); // Save the session.
			break;
		}
		// *********** INVALID SELECTION ********************
		else
		{
			cout << "Please make a selection." << endl << endl;
		}
	}
	cout << "Happy Coding!";
	_getch();
	return 0;
}