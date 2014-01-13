#include "Board.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char** argv)
{
	std::cout<<"Test\n";
	bool isRunning = true;
	Board* board = new Board();
	std::cout<<"Test\n";
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	std::cout<<"Test\n";
	window = SDL_CreateWindow("Puzzle", 100, 100, 480, 480, 0);
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	SDL_Event e;
	std::cout<<"Test\n";
	if(window == NULL)
		return 1;
	
	while(isRunning)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				std::cout<<"Click";
				board -> onMouseDown(e);
			}
			else if(e.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
		
		board -> draw(screen);
		SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}