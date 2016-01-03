#include "myFunc.h"
#include <iostream>

using namespace std;

extern const int ENTRIES = 10;
int check = 0;

int main()
{
	double first;
	double last;
	double delta; 
	char code;

	do
	{
		cout << "Please enter the desired code" << endl;
		cin >> code;
		
		if (checkCode(code) == false)
		{
			continue;
		}

		if (code == 'Q' || code == 'q')
		{
			cout << "Quit confirmed, exiting..." << endl;
			system("pause");
			return 0;
		}

		cout << "Please enter the first value." << endl;;
		cin >> first;
		cout << "Please enter the last value" << endl;;
		cin >> last;
		
		if (first > last)
		{
			cout << "Invalid, please try again." << endl;
			break;
		}
		
		cout << "Please enter delta" << endl;
		cin >> delta;

		for (; first <= last; first + delta)
		{

		}

		check++;

		cout << check;

	} while (check < ENTRIES);

	return 0;
}