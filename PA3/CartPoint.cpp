#include "CartPoint.h"
#include "CartVector.h"
#include <cmath>

using namespace std;

//Default Constructor, intializes y and x to 0.0
CartPoint::CartPoint()
{
	x = 0.0;
	y = 0.0;
}

//Constructor that sets coordinates to the ones specified
CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

//Nonmember function that returns the cartesian distance between two CartPoint Objects
double cart_distance(CartPoint p1, CartPoint p2)
{
	double x_dist = abs(p1.x - p2.x);
	double y_dist = abs(p1.y - p2.y);
	double distance = sqrt((pow(x_dist, 2)) + (pow(y_dist, 2)));

	return distance;
}

ostream& operator<<(ostream& stream, CartPoint p1)
{
	stream << "(" << p1.x << ", " << p1.y << ")";
	return stream;
}

CartPoint operator+(CartPoint p1, CartVector v1)
{
	CartPoint p2(p1.x + v1.x, p1.y + v1.y);
	return p2;
}

CartVector operator-(CartPoint p1, CartPoint p2)
{
	CartVector vec(p1.x - p2.x, p1.y - p2.y);
	return vec;
}
