#ifndef CARTVECTOR_H
#define CARTVECTOR_H

#include <iostream>

using namespace std;

class CartVector
{
public:

	//Public Variables

	double x;
	double y;

	CartVector(); //Default Constructor

	CartVector(double in_x, double in_y);

};

//Nonmember overloaded operators
CartVector operator*(CartVector v1, double d);
CartVector operator/(CartVector v1, double d);
ostream& operator<<(ostream& stream, CartVector v1);

#endif