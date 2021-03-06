#include "stdafx.h"
#include "Turtle.h"

#include <iostream>
using namespace std;

/**
* Uses the algorithm from http://codetrip.weebly.com/blog/year-3-semester-2-procedural-methods-catalogue-of-30-l-systems-drawable-with-turtle-graphics
*
* @param turtle the turtle being used to draw
* @param length the length of each side of teh squares making up the fractal
* @param depth the number of iterations of the fractal
*/
void recursiveDraw(Turtle &turtle, int length, int depth)
{
	const int scaling = 3; // scale the length down by this amount on every recursive step to prevent size from blowing up
	if (depth == 0)
	{
		turtle.forward(length);
	}
	else
	{
		recursiveDraw(turtle, length / scaling, depth - 1);
		turtle.turn(-90);
		recursiveDraw(turtle, length / scaling, depth - 1);
		turtle.turn(90);
		recursiveDraw(turtle, length / scaling, depth - 1);
		turtle.turn(90);
		recursiveDraw(turtle, length / scaling, depth - 1);
		turtle.turn(-90);
		recursiveDraw(turtle, length / scaling, depth - 1);
	}
}

/**
*
* @param turtle the turtle being used to draw
* @param depth the number of iterations of the fractal, 1<=depth<=5
*/
void drawVicsekFractal(Turtle &turtle, int depth)
{
	int fractalSideLength = 250;
	turtle.turn(180); // Build in upper-right corner
	for (int i = 0; i < 4; ++i) // for each side of the square
	{
		recursiveDraw(turtle, fractalSideLength, depth);
		turtle.turn(-90);
	}
	turtle.draw();
}

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("Vicsek Fractal",
							SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							512, 512, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderPresent(renderer);

	Turtle turtle = Turtle(renderer, 512, 512);

	cout << "Enter your desired depth for the vicsek fractal: ";
	int depth;
	cin >> depth;

	drawVicsekFractal(turtle, depth);
	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}
	if (window) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
    return 0;
}

