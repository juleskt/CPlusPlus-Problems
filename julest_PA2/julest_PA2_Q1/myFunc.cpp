#include "myFunc.h"
#include <iostream>

using namespace std;

bool checkCode(char code)
{
	if (code != 'S'  && code != 's' && code != 'C' && code != 'c' && code != 'R' && code != 'r' && code != 'L' && code != 'l' && code != 'N' && code != 'n' && code != 'I' && code != 'i' && code != 'O' && code != 'o' && code != 'Q' && code != 'q')
	{
		cout << "Invalid code, please try again." << endl;
		return false;
	}
	else
	{
		return true;
	}
}