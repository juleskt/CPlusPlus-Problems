#include "View.h"
#include <iostream>

using namespace std;

View::View()
{
	size = 11;
	scale = 2;
}
	
void View::clear()
{
	for(int x = 0; x < view_maxsize; x++)
	{
		for(int y = 0; y < view_maxsize; y++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}
		
void View::plot(GameObject* ptr)
{
	int x,y;

	if(get_subscripts(x,y,ptr->get_location()))
	{
		if(grid[x][y][0] != '.')
		{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
		else
		{
			ptr->drawself(grid[x][y]);
		}
	}
}

void View::draw()
{
	for (int y = size-1; y >= origin.y; y--)
		{
			if ((y % ((int)scale)) == 0)
			{
				if(scale*y > 10)
				{
					cout << scale*y; //Prints out scaled y axis on every even y line
				}
				else
				{
					cout << scale*y << " "; //If y is single digit, add a space at the end
				}
			}
			else
			{
				for(int spacing = 0; spacing < scale; spacing++)
				{
					cout << " "; //Adds as many spaces needed based on the scale
				}
			}

			for (int x = origin.x; x < size; x++)
			{
				cout << grid[x][y][0] << grid[x][y][1]; //Prints the actual grid
			}
			
			cout << endl; //New line
		}
		
		cout << "  ";
		
//Everything below here just prints the x axis scale
for(int x = 0; x < size; x++)
	{
		if ((x % ((int)scale)) == 0)
			{
				if(scale*x > 10)
				{
					cout << scale*x;
					
					for(int spacing = 0; spacing < scale; spacing++)
					{
						cout << " ";
					}
				
				}
				else
				{
					cout << scale*x << " ";

					for(int spacing = 0; spacing < scale; spacing++)
					{
						cout << " ";
					}
				}
			}
	}

	cout << endl;
}

bool View::get_subscripts(int& ix, int& iy,CartPoint location)
{	
	ix = ((location-origin)/scale).x;
	iy = ((location-origin)/scale).y;

	if(ix < 0 || iy < 0 || ix > size || iy > size)
	{
		cout << "An object is outside the display." << endl;
		return false;
	}
	else
	{
		return true;
	}
}