#include <iostream>
#include <ctime>
#include <conio.h>

using std::cout; using std::cin; using std::endl;

void menu();
int randomNumber();

int main(int argc, char * argv[])
{
	char selection;

	while (true)
	{
		menu();
		cout << "Selection :  ";  cin >> selection;

		if (selection == 'p' || selection == 'P')
		{
			int num, ran = randomNumber();
			cout << ran;
			while (true)
			{	
				cout << "Pick a Number 0-100 :  "; 
				cin >> num;
				if (num == ran)
				{
					cout << "You Won!!! The winning number was " << ran << "!" << endl << endl;
					break;
				}
				else if (num < ran)
				{
					cout << "Too little." << endl;
				}
				else
				{
					cout << "Too much." << endl;
				}
			}
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
	cout << "******* Pick a Number *******" << endl;
	cout << "(P)lay" << endl;
	cout << "(Q)uit" << endl << endl;
}

int randomNumber()
{
	srand((unsigned int) time(NULL));
	return std::rand()%100;
}