#include <iostream>

using namespace std;

void PrintRhombus(int);

int globalNum;
int globalTrack = 0;
int topNum = 1;

int main()
{
	int num;

	do
	{
		cout << "Enter a number [1-9]: ";
		cin >> num;

		globalNum = num;

		if (num < 0 || num > 9)
		{
			cout << "Wrong input, please enter a single digit number between 1 and 9." << endl;
			continue;
		}
		else
		{
			PrintRhombus(num);
			break;
		}

	} while (true);

	cout << endl;
	//system("pause"); //DONT FORGET TO COMMENT!!#############################
	return 0;
}

void PrintRhombus(int num)
{
	int bottomDiff = globalNum - num; // The difference between the highest num in the row and the highest num overall for the bottom
	int difference = 2; //used in bottom half
	int diff = 2; // used in top half
	int topDiff = globalNum - topNum; //The difference between the highest num in the row and the highest num overall for the top

	//cout << "(" << num << ")";
	//THIS ENTIRE IF BLOCK CAN BE IGNORED, RECURSION IS HARD.
	if (globalTrack == 1)
	{
	
		if (num == 0)
		{
			//cout << "hit";
			//wtf++;
			//cout << "num is: " << num;
			return;

		}

		else if (bottomDiff > 0)
		{ 
			for (int x = 0; x < bottomDiff; x++)
			{
				cout << " " << " "; //Prints spaces on the left side of the bottom half before the first number in the row
			}
		}


		for (int x = 1; x < num * 2; x++)
		{
			if (x <= num) //if the iterator x is less than the halfway point
			{
				cout << x << " "; //Prints numbers on the left side of the bottom half
			}
			else//if the iterator is past the halfway point
			{
				cout << x - difference << " "; //prints numbers on the right side of the bottom half
				difference += 2; //Since x increments by 1 each loop and there is a space between each number, difference is incremented by two
			}
		}
		cout << endl;
		num--;
		//cout << "this sucks";
		PrintRhombus(num);
		//cout << "after (" << num <<")";
	}
		
	else
	{
		if (topNum == globalNum)
		{
			globalTrack++;
			PrintRhombus(globalNum);
			return;
		}

		if (topNum == 1)
		{
			for (int x = 0; x <= topDiff; x++) //loop for the first row, so hard-codey...
			{
				if (x == topDiff)
				{
					cout << topNum; //Once in the middle, print 1
				}
				else
				{
					cout << " " << " "; //Prints spaces on the left side of the top half
				}
			}
		}
		else
		{
			for (int x = 0; x < topDiff; x++)
			{
				cout << " " << " "; //Prints spaces on the left side of the top half
			}

			for (int x = 1; x < topNum * 2; x++)
			{
				if (x <= topNum)
				{
					cout << x << " "; //Prints numbers on the left side of the top half
				}
				else
				{
					cout << x - diff << " "; //prints numbers on the right side of the top half
					diff+= 2;
				}
			}
		}
		
		cout << endl;
		topNum++;
		PrintRhombus(topNum); 
	}	
}