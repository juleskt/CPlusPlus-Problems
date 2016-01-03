#include <iostream>
#include <math.h>

using namespace std;

bool compare(int x1, int y1, int x2, int y2, double area1, double area2);

int main() //Gathers info for square processing
{
	int x1, y1, x2, y2, area1, area2; //Note: x,y given are the CENTERS of squares
	int comparison;

	cout << "Enter the information for the first square" << endl << "x-coordinate: ";
	cin >> x1;
	cout << "y-coordinate: ";
	cin >> y1;
	cout << "area: ";
	cin >> area1;

	cout << "Enter the information for the second square" << endl << "x-coordinate: ";
	cin >> x2;
	cout << "y-coordinate: ";
	cin >> y2;
	cout << "area: ";
	cin >> area2;

	if (compare(x1, y1, x2, y2, area1, area2) == true)
	{
		cout << "THE SQUARES INTERSECT";
	}
	else
	{
		cout << "THE SQUARES DO NOT INTERSECT";
	}

	system("pause");

return 0;
}

bool compare(int x1, int y1, int x2, int y2, double area1, double area2)
//	TRUE INDICATES SQUARES INTERSECT
{
	double bound1 = sqrt(area1) / 2;
	double bound2 = sqrt(area2) / 2;


//THE FOLLOWING COMPARES THE DISTANCE OF THE SIDES OF THE SQUARES

	if (x1+bound1 > x2-bound2) // if upper x bound of a square intersects with the lower x bound with the other
	{
		return true;
	}
	else if (x1 - bound1 < x2 + bound2) // opposite of above
	{
		return false;
	}
	else
	{
		if (y1 + bound1 > y2 - bound2) //same as x
		{
			return true;
		}
		else if (y1 - bound1 < y2 + bound2) // same as x
		{
			return false;
		}
	}
}