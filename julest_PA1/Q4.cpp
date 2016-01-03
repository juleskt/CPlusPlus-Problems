#include <iostream>

using namespace std;

int main()
{
	char letter;
	int offset;
	int flip = 32;

	cout << "Enter character: ";
	cin >> letter;
	cout << "Offset (Enter 0 to convert case) ";
	cin >> offset;

	/*if (letter < 65)
	{
		cout << letter << " ";
		system("pause");
		return 0;
	}*/
	letter = letter * 1;

	if (letter + offset > 127)
	{
		cout << "An error has occured: Out of range.";
		return 0;
	}
	else if (letter + flip > 127)
	{
		flip = flip*-1;
	}

	if (offset == 0)
	{
		letter = letter + flip;
	}
	
	else
	{
		letter = letter + offset;
	}

	cout << "New Character: " << letter << " ";

	system("pause");
	return 0;
}