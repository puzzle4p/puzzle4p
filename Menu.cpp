#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Window *mainWindow, SDL_Surface *windowSurface, SDL_Renderer *passedRenderer, std::string destinationOfImage)
{
	state = STATE_MENU;
	renderer = passedRenderer;
	backgroundSurface = new Background(windowSurface, renderer, destinationOfImage, state);

	layerButton = layerManager::addLayer(1);
	startGameButton = new Sprite(renderer, "red.bmp", 0, 100, 100, 100, 100, state);
	layerButton->addSprite(startGameButton);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
	if (isPointInsideRectFromCorner(pointerX, pointerY, startGameButton->mainRect))
	{
		std::cout << "state game\n";
		stateManager::changeState(STATE_GAME);
	}
}
