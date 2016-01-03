#include <iostream>
#include <fstream>
#include <random>
#include <string.h>

using namespace std;

int DataToFile(const char *filename, int N, int M)
{
	ofstream *filename;

	*filename.open("numbers.txt");

	for (int x = 0; x < N; x++)
	{
		*filename << rand() % M + 1 << endl;
	}
	
	*filename.close(); 
	
	return 0;
}