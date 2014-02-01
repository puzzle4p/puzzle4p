#include "SDL.h"
#include "Menu.h"
#include "Game.h"
#include "stateManager.h"
#include "layerManager.h"
#include <string>


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

	layerManager::setRenderer(renderer, windowSurface);
	layerManager::addLayerToVector(0);
	layerManager::addLayerToVector(1);

	stateManager::addToMap(STATE_MENU, new Menu(windowSurface, destinationOfImage));
	stateManager::addToMap(STATE_GAME, new Game());
	stateManager::changeState(STATE_MENU);

	
	layerManager::showLayers();

	SDL_Event event;

	while (!quit)
	{
		Uint32 now = SDL_GetTicks();
		
		int delay = 1000 / 60 - (SDL_GetTicks() - now);
		if (delay > 0) SDL_Delay(delay);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				int x = event.button.x;
				int y = event.button.y;
				
				stateManager::onMouseDown(x, y);
			}
			if (event.type == SDL_TEXTINPUT)
			{
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
