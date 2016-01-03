#ifndef CARTPOINT_H
#define CARTPOINT_H

#include "CartVector.h"
#include <iostream>

using namespace std;

class CartPoint
{
public:

	//Public Variables
	double x;
	double y;

	CartPoint(); //Default constructor

	CartPoint(double in_x, double in_y); //Constructor with coords
};

double cart_distance(CartPoint p1, CartPoint p2); //Nonmember Function

//Nonmember overloaded operators
ostream& operator<<(ostream& stream, CartPoint p2);
CartPoint operator+(CartPoint p1, CartVector v1);
CartVector operator-(CartPoint p1, CartPoint p2);

#endif
