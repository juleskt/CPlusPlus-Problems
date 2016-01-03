#include <iostream>

using namespace std;

int	*DoubleAndReverse(int *, int);

int main()
{
	int numSize = 0;

	cout << "Enter the number of entries: ";
	cin >> numSize;

	int * Array = new int[numSize];
	int * temp;

	for (int x = 0; x < numSize; x++)
	{
		cout << "Entry " << x << " is: ";
		cin >> Array[x];
	}

	cout << "*****" << endl;

	cout << "Original array is: ";
	for (int x = 0; x < numSize; x++)
	{
		cout << Array[x] << " "; 
	}
	cout << "and the address of the zero element is: " << &(*Array) << endl; //OR &Array[0]

	temp = DoubleAndReverse(Array, numSize);

	cout << "Final array is: ";
	for (int x = 0; x < 2 * numSize; x++)
	{
		cout << temp[x] << " ";
	}
	cout << "and the address of the zero element is: " << &(*temp); 

	//system("pause"); //DON'T FORGET TO COMMENT!!!!!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	delete[] Array;
	delete[] temp;
	
	return 0;
}

int *DoubleAndReverse(int *list, int size)
{
	int difference = 1;
	int *clone = new int[size*2];
	//list[size*2];
	
	for (int x = 0; x < (size); x++)
	{
		clone[x] = list[x];
		clone[x + size] = list[(size - 1) - x]; 
	}
		
	return clone;
}