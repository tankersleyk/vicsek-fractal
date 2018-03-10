#include "stdafx.h"
#include "Turtle.h"
#include "math.h"
using namespace std;


/**
* Create a new turtle that draws to the given renderer
*
* @param renderer the SDL renderer to draw on
* @param width the width of the canvas the turtle is drawing on
* @param height the height of the canvas the turtle is drawing on
*/
Turtle::Turtle(SDL_Renderer* renderer, int width, int height) : _currentPosition(width/2, height/2)
{
	_currentHeading = 0;
	_renderer = renderer;
}

/**
* Move this turtle forward a given number of steps
*
* @param steps the nmber of steps to move in the current direction, must be >=0
*/
void Turtle::forward(int steps)
{
	double newX = _currentPosition.x() + cos((DEGREES_TO_VERTICAL - _currentHeading) * PI / 180) * steps;
	double newY = _currentPosition.y() + sin((DEGREES_TO_VERTICAL - _currentHeading) * PI / 180) * steps;

	_toDraw.push_back(_currentPosition);

	_currentPosition = Point(newX, newY);

	_toDraw.push_back(_currentPosition);
}

/**
* Turn this turtle a given number of degrees clockwise
*
* @param degrees amount of angles, in degrees, to turn
*/
void Turtle::turn(double degrees)
{
	_currentHeading = fmod(_currentHeading + degrees, CIRCLE_DEGREES);
}

/**
* Draw the image created by this turtle
*/
void Turtle::draw()
{
	for (auto it = _toDraw.begin(); it != _toDraw.end(); it += 2)
	{
		Point p1 = *it;
		Point p2 = *(it + 1);
		SDL_RenderDrawLine(_renderer, p1.x(), p1.y(), p2.x(), p2.y());
	}
}