#include "myFunc.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

extern const int ENTRIES = 10;

int main()
{
	double first;
	double last;
	double delta; 
	char code;

	initialize();

	do
	{	
		int check = 1;
		
		cout << "Please enter command code: ";
		cin >> code;
		
		if (checkCode(code) == false) //Checking the Code
		{
			cout << endl;
			continue;
		}

		if (code == 'Q' || code == 'q') //If quit, then exit
		{
			cout << "Bye bye!" << endl;
			//system("pause"); //DO NOT FORGET TO COMMENT THIS OUT!!!@@@@@@@@@@@@@@@@@@@@@@@@@
			return 0;
		}

		if (code == 'I' || code == 'i')
		{
			char input[100];
			const char * filename = input;
			cout << "Please enter input filename: ";
			cin >> input;
			readDataFromFile(filename);
			continue;
		}
		else if (code == 'O' || code == 'o')
		{
			char input[100];
			const char * filename = new char;
			cout << "Please enter output filename: ";
			cin >> input;
			filename = input;
			writeDataToFile(filename); //NEED TO CHECK IF ITS ALWAYS CALLED MYOUTPUT
			cout << "File has been written." << endl;
			cout << endl;
			continue;
		}

		cout << "Please enter command parameters: "; //gather data
		cin >> first >> last >> delta;
		
		if (first > last) //Totally illegal, do the loop again
		{
			cout << "No computation needed" << endl << endl;
			continue;
		}

		if (delta <= 0)
		{
			cout << "No computation needed" << endl << endl;
			continue;
		}

		//INCOMING COMPUTATIONS
		for (; first <= last; first = first + delta)
		{
			cout << fixed;
			if (check > ENTRIES)
			{
				break;
			}
			
			if (code == 'S' || code == 's')
			{
				cout << "Area of square with side length " <<setprecision(2) << first << " = " << setprecision(5) << findSquareAreaValue(first) << endl;
			}
			else if (code == 'C' || code == 'c')
			{
				cout << "Circumference of circle with radius " << setprecision(2) << first << setprecision(5) << " = " << findCircumValue(first) << endl;
			}
			else if (code == 'R' || code == 'r')
			{
				cout << "Square root of " << setprecision(2) << first << " = " << setprecision(5) << findSqrtValue(first) << endl; 
			}
			else if (code == 'E' || code == 'e')
			{
				cout << "Next even number for " << setprecision(2) << first << " = " << findNextEvenValue(first) << endl;
			}
			else if (code == 'L' || code == 'l')
			{
				cout << "Lucky number of " << setprecision(2) << first << " = " << setprecision(5) << findLuckyNumValue(first) << endl;
			}
			else if (code == 'N' || code == 'n')
			{
				cout << "nyanCat(" << setprecision(2) << first << ") = " << setprecision(5) << findNyanCatValue(first) << endl;;
			}
			
			check++;
		}

		cout << endl;

	} while (true);

	//system("pause"); //DON'T FORGET TO COMMENT THIS OUT!!! @@@@@@@@@@@@@@@@@@@@@@@@@
	return 0;
}