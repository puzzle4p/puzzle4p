//Tylko dla testów
#include <SDL.h>
#include <iostream>
#include "Game.h"


int main(int argc, char** argv)
{
	int size = 12;

	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Puzzle", 100, 100, 60 * size, 60 * size, 0);

	Game* game = new Game(window, size);
	game -> start();

	SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}
