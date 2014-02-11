#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Window *mainWindow, SDL_Surface *windowSurface, std::string destinationOfImage)
{
	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	this->windowSurface = windowSurface;

	backgroundSurface = new Background(windowSurface, destinationOfImage);

	layerButton = layerManager::addLayer(1);
	startGameButton = new Sprite("red.bmp", 0, 100, 100, 100, 100);
	layerButton->addSprite(startGameButton);

}

void Menu::onMouseDown(int pointerX, int pointerY)
{
	layerManager::setRenderer(renderer, windowSurface);
	if (isPointInsideRectFromCorner(pointerX, pointerY, startGameButton->mainRect))
	{
		stateManager::changeState(STATE_GAME);
	}
}
