#pragma once

#include "Point.h"
#include <vector>

class Turtle
{
public:
	Turtle(SDL_Renderer* renderer, int width, int height);

	void forward(int steps);
	void turn(double degrees);
	void draw();

private:
	static const int CIRCLE_DEGREES = 360;
	static const int DEGREES_TO_VERTICAL = 90;
	const double PI = 3.14159265359;

	SDL_Renderer* _renderer;
	Point _currentPosition;
	double _currentHeading;
	std::vector<Point> _toDraw;
};