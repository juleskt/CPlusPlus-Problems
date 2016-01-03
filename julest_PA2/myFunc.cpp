#include "myFunc.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void initialize()
{
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2014" << endl;
	cout << "Programming Assignment 2" << endl;
	cout << "Maximum computation is: 10" << endl << endl << endl;
}

bool checkCode(char code)
{
	if (code != 'S'  && code != 's' && code != 'C' && code != 'c' && code != 'R' && code != 'r' && code != 'L' && code != 'l' && code != 'N' && code != 'n' && code != 'I' && code != 'i' && code != 'O' && code != 'o' && code != 'Q' && code != 'q' && code != 'E' && code != 'e')
	{
		cout << "Invalid code, please try again." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

void writeDataToFile(const char *filename)
{
	int first = rand() % 11;
	int last = rand() % 31 + 20;
	int delta = rand() % 11 + 5;

	ofstream myfile;
	myfile.open(filename);

	for (; first <= last; first = first + delta)
	{
		myfile << fixed;
		myfile << "nyanCat(" << setprecision(2) << first << ") = " << setprecision(5) << findNyanCatValue(first) << endl;
	}

	myfile.close();
}

void readDataFromFile(const char *filename)
{	
	double first;
	double last;
	double delta;
	
	ifstream myInFile;
	myInFile.open(filename);
	myInFile >> first >> last >> delta;
	myInFile.close();
	cout << fixed;
	cout << "Successfully read data from file: ";
	cout << "Start " << setprecision(5) << first << " " << "Finish " << last << " " << "Step " << delta << "." << endl;
	cout << endl;
}

double findNyanCatValue(double input)
{
	input = pow((2 * input),input);
	return input;
}

double findSquareAreaValue(double input)
{
	return input * input;
}

double findCircumValue(double input)
{
	input = 6.28*input;
	return input;
}

double findSqrtValue(double input)
{
	return sqrt(input);
}

double findLuckyNumValue(double input)
{
	srand(input);
	return rand();
}

int findNextEvenValue(double input)
{
	int x = static_cast<int>(input);
	if (x % 2 != 0)
	{
		x++;
		return x;
	}
	else
	{
		return x+2;
	}
}