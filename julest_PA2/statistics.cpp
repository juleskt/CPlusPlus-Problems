#include "statistics.h"
#include <math.h>

using namespace std;


float getMean(int myArray[], int size)
{
	float mean = 0;

	for (int x = 0; x < size; x++)
	{
		mean += myArray[x];
	}
	
	mean = mean / size;

	return mean;
}

float getStdDev(int myArray[], int size)
{
	float mean = 0;
	float stdev = 0;

	for (int x = 0; x < size; x++)
	{
		mean += myArray[x];
	}

	mean = mean / size;

	for (int x = 0; x < size; x++)
	{
		stdev += pow(myArray[x] - mean, 2);
	}

	stdev = sqrt(stdev/size);

	return stdev;
}