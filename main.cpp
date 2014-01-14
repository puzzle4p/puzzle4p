#include "Board.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	bool isRunning = true;
	Board* board = new Board();
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Puzzle", 100, 100, 480, 480, 0);
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	SDL_Event e;
	if(window == NULL)
		return 1;
	
	while(isRunning)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				board -> onMouseDown(e);
			}
			else if(e.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
		board -> update();
		board -> draw(screen);
		SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}