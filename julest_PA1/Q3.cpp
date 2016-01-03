#include <iostream>
#include <vector>

using namespace std;

int conversion(int x, vector <int> &x_vec);
int ham(vector<int> x_vec, vector<int> y_vec);

int main()
{
	vector<int> x_vec, y_vec;
	int x;
	int y;

	//Gets user input
	cout << "Enter two numbers between 0-100: ";
	cin >> x;
	cin >> y;

	//Checks for invalids
	if (x > 100 || y > 100 || x < 0 || y < 0)
	{
		cout << "Invalid numbers!";
		//system("pause");
		return 0;
	}

	//Calls conversion
	conversion(x, x_vec);
	conversion(y, y_vec);

	cout << "Hamming distance between " << x << " and " << y << " when numbers are in ternary format is: " << ham(x_vec, y_vec);

	//system("pause");

	return 0;
}

int conversion(int x, vector<int> &x_vec)
{
	/*Turns into base 3 and writes each place value into an
	element in a vector
	*/
	if (x == 0)
	{
		x_vec.push_back(3);
	}

	while (x > 0)
	{
		int subsZero = x % 3;

		if (subsZero == 0)
		{
			subsZero = 3;
		}

		x_vec.push_back(subsZero);
		x = x / 3;
	}


	for (int x = 0; x < x_vec.size(); x++)
	{
		cout << x_vec[x];
	}
	
	cout << " ";
	return 0;
}

int ham(vector<int> x_vec, vector<int> y_vec)
{
	int xSize = x_vec.size() - 1;
	int ySize = y_vec.size() - 1;
	int distance = 0;

	/*Compares the sizes of the arrays and increments the hamming distance
	Then, compares the elements of each vector. The code iterates through both
	vectors a number of times to accmodate every element in the smaller vector to be
	accounted for. The extra digits (elements) are accounted for in the size
	comparisons.
	*/
	
	if (xSize > ySize)
	{
		for (int diff = xSize - ySize; diff > 0; diff--)
		{;
			y_vec.push_back(3);
			ySize++;
		}
	}
	
	else if (ySize > xSize)
	{
		for (int diff = ySize - xSize; diff > 0; diff--)
		{
			x_vec.push_back(3);
			xSize++;
		}
	}

	for (int x = xSize; x >= 0; x--)
		{
			if (x_vec[x] != y_vec[x])
				{
					distance++;
				}
		}

	return distance;
}