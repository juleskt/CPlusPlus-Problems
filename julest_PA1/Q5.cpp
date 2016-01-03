#include <iostream>
#include <random>

using namespace std;

int main()
{
	int comp = rand() % 3;
	int select;

	cout << "Choose Rock(0), Paper(1), Scissors(2): " << endl;
	cin >> select;
	cout << "Computer chooses: " << comp << endl;

	if (select > 2 || select < 0)
	{
		cout << "Invalid selection, try again";
	}
	if (comp == select)
	{
		cout << "You tie!";
	}
	else if (comp == 0 && select == 2)
	{
		cout << "You Lose!";
	}
	else if (comp == 0 && select == 1)
	{
		cout << "You Win!";
	}
	else if (comp == 1 && select == 0)
	{
		cout << "You Lose!";
	}
	else if (comp == 1 && select == 2)
	{
		cout << "You win!";
	}
	else if (comp == 2 && select == 1)
	{
		cout << "You lose!";
	}
	else if (comp == 2 && select == 0)
	{
		cout << "You win!";
	}

	system("pause");
	return 