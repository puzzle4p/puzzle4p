#include "Menu.h"
#include <iostream>

Menu::Menu(SDL_Window *mainWindow, SDL_Renderer *passed_renderer, SDL_Surface *windowSurface, std::string destinationOfImage)
{
	renderer = passed_renderer;
	state = STATE_MENU;
	backgroundSurface = new Background(windowSurface, passed_renderer, destinationOfImage, state);

	layerButton = layerManager::addLayer(1);
	title = new Sprite(renderer, "Images//MAIN_MENU_TITLE.png", 0, 275, 100, 729, 175, state);
	startGameButton = new Sprite(renderer, "Images//PLAY_BUTTON.png", 0, 400, 400, 306, 121, state);
	quitButton = new Sprite(renderer, "Images//QUIT_BUTTON.png", 0, 500, 550, 306, 121, state);
	layerButton->addSprite(title);
	layerButton->addSprite(startGameButton);
	layerButton->addSprite(quitButton);
}

void Menu::onMouseDown(int pointerX, int pointerY)
{
	if (isPointInsideRectFromCorner(pointerX, pointerY, startGameButton->mainRect))
	{
		std::cout << "state game\n";
		stateManager::changeState(STATE_GAME);
	}
	if (isPointInsideRectFromCorner(pointerX, pointerY, quitButton->mainRect))
	{
		std::cout << "state quit\n";
		stateManager::changeState(STATE_QUIT);
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