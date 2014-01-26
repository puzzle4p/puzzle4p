//Tylko dla testów
#include "Board.h"
#include <SDL.h>
#include <iostream>

const int FPS = 30;

int main(int argc, char** argv)
{
	int size = 12;
	bool isRunning = true;
	Board* board = new Board(size);
	
	
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Puzzle", 100, 100, 60 * size, 60 * size, 0);
	
	Uint32 startTicks;
	
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	SDL_Event e;
	if(window == NULL)
		return 1;
	
	while(isRunning)
	{
		startTicks = SDL_GetTicks();
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
		if(1000/FPS > SDL_GetTicks()-startTicks) 
		{
			SDL_Delay(1000/FPS-(SDL_GetTicks()-startTicks));
        }
	}
	delete board;
	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}