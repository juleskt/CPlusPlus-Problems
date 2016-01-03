#include <iostream>
#include <iomanip>

using namespace std;

int calculation(double bill, double taxrate, double tiprate, int destiny);

int main()
{
	double bill;
	double taxrate;
	double tiprate;
	int destiny;
	int tip_level;

	cout << "Enter the original bill amount: ";
	cin >> bill;
	cout << "Enter the tax rate: ";
	cin >> taxrate;
	cout << "Enter tip level: (1 = 15%, 2 = 20%, 3 = 25%)";
	cin >> tip_level;
	cout << "Tip on post tax amount? (1 = yes, 2 = no)";
	cin >> destiny;

	if (tip_level == 1)
	{
		tiprate = .15;
	}
	else if (tip_level == 2)
	{
		tiprate = .20;
	}
	else if (tip_level == 3)
	{
		tiprate = .25;
	}

	calculation(bill, taxrate, tiprate, destiny);

	system("pause");

	return 0;
}

int calculation(double bill, double taxrate, double tiprate, int destiny)
{
	double tip1;
	double tip2;
	taxrate = taxrate / 100;

	// Tip on post-tax amount? (1=yes, 2=no)
	if (destiny == 2)
	{
		tip1 = bill*tiprate;
		bill = (bill*taxrate) + bill;
		cout << "The bill pre-tip is: " << setprecision(2) << fixed << bill << endl;
		cout << "The total tip is: " << setprecision(2) << fixed << tip1 << endl;
		cout << "The bill post tip is: " << setprecision(2) << fixed << bill + tip1 << endl;
	}

	// Tip on post-tax amount? (1=yes, 2=no)
	if (destiny == 1)
	{
		bill = (bill*taxrate) + bill;
		tip2 = bill*tiprate;
		cout << "The bill pre-tip is: " << bill << endl;
		cout << "The total tip is: " << tip1 << endl;
		cout << "The bill post tip is: " << bill + tip1 << endl;
	}

	return 0;
}