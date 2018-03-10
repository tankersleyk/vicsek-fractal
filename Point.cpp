#include "stdafx.h"
#include "Point.h"


/**
* Create a new point at the given coordinates
*
* @param x x-coordinate
* @param y y-coordinate
*/
Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}

/**
* @return the x-coordinate of the point
*/
double Point::x()
{
	return _x;
}

/**
* @return the y-coordinate of the point
*/
double Point::y()
{
	return _y;
}

std::ostream &operator<<(std::ostream &os, Point const &m)
{
	return os << m._x << "," << m._y;
}