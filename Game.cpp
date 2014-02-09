#include "Game.h"

Game::Game(SDL_Surface *windowSurface, std::string destinationOfImage)
{
	backgroundSurface = new Background(windowSurface, destinationOfImage);
}
void Game::onMouseDown(int pointerX, int pointerY)
{
    
}
