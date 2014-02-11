#include "Game.h"

Game::Game(SDL_Window *mainWindow, SDL_Surface *windowSurface, std::string destinationOfImage)
{
	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	layerManager::setRenderer(renderer, windowSurface);

	backgroundSurface = new Background(windowSurface, destinationOfImage);
	
}
void Game::onMouseDown(int pointerX, int pointerY)
{
	
}
