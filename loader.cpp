#include "SDL.h"
#include "Menu.h"
#include "Game.h"
#include "Background.h"
#include "Util.h"
#include "stateManager.h"
#include <iostream>
#include <string>
#include "Sprite.h"
#include "Layer.h"
#include "layerManager.h"


int main(int argc, char* args[])
{
	bool quit = false;
	int windowWidth = 640;
	int windowHeight = 480;
	std::string windowTitle = "puzzle4p";
	std::string destinationOfImage = "hello.bmp";

	SDL_Window *mainWindow = SDL_CreateWindow(windowTitle.c_str(), 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *windowSurface = SDL_GetWindowSurface(mainWindow);


	stateManager::addToMap(STATE_MENU, new Menu(mainWindow, destinationOfImage));
	stateManager::addToMap(STATE_GAME, new Game());
	stateManager::changeState(STATE_MENU);

	layerManager::setRenderer(renderer, windowSurface);
	layerManager::addLayerToVector(1);
	layerManager::layers[0]->addSprite(new Sprite("red.bmp", 0, 100, 0, 100, 100));
	layerManager::layers[0]->addSprite(new Sprite("red.bmp", 0, 200, 400, 100, 100));
	layerManager::addLayerToVector(0);
	layerManager::layers[1]->addSprite(new Sprite("hello.bmp", 0, 0, 0, 640, 480));
	layerManager::showLayers();

	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				int x = event.button.x;
				int y = event.button.y;
				std::cout << x << " " << y << "\n";
				stateManager::onMouseDown(x, y);
			}
			if (event.type == SDL_TEXTINPUT)
			{
				std::cout << event.text.text;
				stateManager::changeState(STATE_GAME);
			}
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;

	return 0;
}
