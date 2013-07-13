#include <iostream>
#include <string>
//#include <fstream>
#include <conio.h>

using std::cout; using std::endl; using std::cin;

void menu();
void encrypt(std::string&);
std::string decrypt(std::string);

int main(int argc, char * argv[])
{
	char selection;
	std::string theStr;

	while (true)
	{
		menu();
		cout << "Selection :  "; cin >> selection;

		if (selection == 'e' || selection == 'E')
		{
			cout << "Enter a String :  "; cin.ignore();
			std::getline(cin, theStr);
			cout << theStr << endl;
			encrypt(theStr);
			cout << theStr << endl << endl;
		}
		else if (selection == 'd' || selection == 'D')
		{
			cout << theStr << endl;
			cout << decrypt(theStr) << endl << endl;
		}
		else if (selection == 'q' || selection == 'Q')
		{
			break;
		}
		else
		{
			cout << "Please make a selection." << endl << endl;
		}
	}
	cout << "Happy Coding!";
	_getch();
	return 0;
}

void menu()
{
	cout << "(E)ncrypt String" << endl;
	cout << "(D)ecrypt String" << endl;
	cout << "(Q)uit" << endl << endl;
}

void encrypt(std::string& theStr)
{
	cout << "Begin Encryption." << endl;
	std::string retStr (theStr);
	for (unsigned i = 0; i < theStr.length(); ++i)
	{
		char tmpChar = theStr[i];
		unsigned int chInt = (unsigned int)tmpChar;
		chInt = ~chInt;
		chInt += 2;
		chInt = ~chInt;
		chInt -= 5;
		tmpChar = (char)chInt;
		retStr.insert(i, 1, tmpChar);
	}
	std::string encrypted(retStr, 0, theStr.length());
	cout << "End Encryption" << endl;
	theStr = encrypted;
}

std::string decrypt(std::string theStr)
{
	cout << "Begin Decryption." << endl;
	std::string retStr (theStr);
	for (unsigned i = 0; i < theStr.length(); ++i)
	{
		char tmpChar = theStr[i];
		unsigned int chInt = (unsigned int)tmpChar;
		chInt = ~chInt;
		chInt -= 2;
		chInt = ~chInt;
		chInt += 5;
		tmpChar = (char)chInt;
		retStr.insert(i, 1, tmpChar);
	}
	std::string decrypted(retStr, 0, theStr.length());
	cout << "End Decryption." << endl;
	return decrypted;
}	