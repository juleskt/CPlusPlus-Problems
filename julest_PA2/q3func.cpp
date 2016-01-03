#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "q3func.h"
#include <time.h>

using namespace std;

int DataToFile(const char *filename, int N, int M)
{
	ofstream file(filename);
	srand(time(0));
	 
	if (file.is_open())
	{
		for (int x = 0; x < N; x++)
		{
			if (x < N - 1)
			{
				file << rand() % M << endl;

			}
			else
			{
				file << rand() % M;
			}
		}
		
		file.close();
		return 0;
	}
	else
	{
		file.close();
		return 1;
	}
}

int DataFromFile(const char *filename, int myArray[], int& size)
{
	ifstream file(filename);
	string line;

	int x = 0;
	int num = 0;
	
	while (getline(file,line))
	{
	  istringstream stream(line);

	    while(stream >> num)
	      {
		myArray[x] = num;
		x++;
		size++;
	      }
	}
	file.close();
	return 0;
}
