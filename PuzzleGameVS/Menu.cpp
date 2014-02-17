#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Window *mainWindow, SDL_Renderer *passed_renderer, SDL_Surface *windowSurface, std::string destinationOfImage)
{
	renderer = passed_renderer;
	state = STATE_MENU;
	backgroundSurface = new Background(windowSurface, passed_renderer, destinationOfImage, state);

	layerButton = layerManager::addLayer(1);
	startGameButton = new Sprite(renderer, "Images/red_button.bmp", 0, 100, 100, 100, 100, state);
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
void Menu::update()
{

}

Menu::~Menu()
{
	delete layerButton;
	delete backgroundSurface;
	delete startGameButton;
}