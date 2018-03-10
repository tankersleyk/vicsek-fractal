#pragma once
#include <iostream>
class Point
{
private:
	double _x;
	double _y;
public:
	Point(double x, double y);

	double x();
	double y();

	friend std::ostream& operator<<(std::ostream&, Point const&);
};