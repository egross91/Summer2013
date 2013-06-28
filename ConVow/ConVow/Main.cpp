#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using std::cout; using std::cin; using std::endl;

std::vector<int> conVow(std::string lineText)
{
	int vowels = 0, consonants = 0;
	for (unsigned i = 0; i < lineText.length(); ++i)
	{
		if (lineText[i] == 'a' || lineText[i] == 'A' || lineText[i] == 'e' || lineText[i] == 'E' ||
			lineText[i] == 'i' || lineText[i] == 'I' || lineText[i] == 'o' || lineText[i] == 'O' ||
			lineText[i] == 'u' || lineText[i] == 'U')
		{
			++vowels;
		}
		else if ((lineText[i] > 64 && lineText[i] < 91) || (lineText[i] > 96 && lineText[i] < 123))
		{
			++consonants;
		}
		else if (lineText[i] == 32 || lineText[i] == 33 || lineText[i] == 44 || lineText[i] == 46 || lineText[i] == 63)
		{
			// Pass.
		}
		else
		{
			std::vector<int> nothing;
			return nothing;
		}
	}
	std::vector<int> counts;
	counts.push_back(vowels);
	counts.push_back(consonants);
	return counts;
}

int main(int argc, char * argv[])
{
	std::string str;
	cout << "Whatever String you enter, the program will check to see if there" << endl <<
		    "are any characters outside of the alphabet. Fortunately, this excludes" << endl <<
			"\".\" \",\" \"?\" and spaces." << endl << endl;
	cout << "Please enter a sentence :  ";
	std::getline(cin, str);
	std::vector<int> ret = conVow(str);
	if (ret.empty())
	{
		cout << "There were characters other than the alphabet in your sentence." << endl << endl;
	}
	else
	{
		cout << "There were " << ret[0] << " vowels and " << ret[1] << " consonants." << endl << endl;
	}
	cout << "Happy Coding!";
	_getch();
	return 0;
}