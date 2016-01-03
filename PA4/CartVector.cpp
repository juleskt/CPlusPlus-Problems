#include "CartVector.h"
#include <cmath>

using namespace std;

//Default constructor sets x and y to 0.0
CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

//Constructor sets x and y to specified values
CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

CartVector operator*(CartVector v1, double d)
{
	CartVector vec(v1.x * d, v1.y * d); //Creates CartVector object with parameters
	return vec;
}

CartVector operator/(CartVector v1, double d)
{
	CartVector vec(v1.x / d, v1.y / d); //Creates CartVector object with parameters
	return vec;
}

ostream& operator<<(ostream& stream, CartVector v1)
{
	stream << "<" << v1.x << ", " << v1.y << ">"; //Formats output
	return stream;
}
