#include <iostream>
#include <string>
#include "q3func.h"
#include "statistics.h"
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
  	int numRand = 10;
  	int mRange = 10;
	int *Array = new int[1001];
	int arraySize = 0;
	int largest = 0;
	int smallest = numeric_limits<int>::max();


	//DataToFile("numbers.txt", numRand, mRange);
	DataFromFile("numbers.txt", Array, arraySize);

	cout << "Array size is: " << arraySize << endl;
	cout << "Mean is: " << getMean(Array, arraySize) << endl;
	cout << "StdDev is: "<< fixed <<setprecision(4) << getStdDev(Array, arraySize) << endl;

	cout << "Array values forward are: ";
	for (int x = 0; x < arraySize; x++)
	{
		if (x < arraySize - 1)
		{
			cout << Array[x] << ", ";
		}
		else
		{
			cout << Array[x];
		}
	}
	cout << endl;

	cout << "Array values backward are: ";
	for (int x = arraySize-1; x > -1; x--)
	{
		if (x > 0)
		{
			cout << Array[x] << ", ";
		}
		else
		{
			cout << Array[x];
		}
	}
	cout << endl;

	cout << "The largest array value is: ";
		for (int x = 0; x < arraySize; x++)
		{
		  if(Array[x] > largest)
		    {
		      largest = Array[x];
		    }
		}
	cout << largest << endl;

	cout << "The smallest array value is: ";
		for (int x = 0; x < arraySize; x++)
		{
		  if(Array[x] < smallest)
		    {
		      smallest = Array[x];
		    }
		}
		cout << smallest << endl;

	//system("pause"); //REMEMBER TO UNCOMMENT@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	return 0; 
}
